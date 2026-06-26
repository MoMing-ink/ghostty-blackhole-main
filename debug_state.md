# Debug State — Blackhole v4: WGC + PBO 架构迁移

## 实施结果

### 编译 ✅
- 零警告零错误通过
- 3 源文件链接: main.cpp + capture_wgc.cpp + gl_texture.cpp
- 依赖库: glfw + opengl32 + d3d11 + dxgi + gdi32 + runtimeobject

### 架构变更

**旧架构 (v3) — 已删除：**
```
DXGI Desktop Duplication (screen_capture)
    → AcquireNextFrame / ReleaseFrame
    → CopyResource → shared D3D11 texture
    → WGL_NV_DX_interop2 (NVIDIA only) → OpenGL texture
    → blackhole.glsl → 窗口
```
- `src/screen_capture.h` / `.cpp` — 已删除
- `src/gl_interop.h` / `.cpp` — 已删除
- SPIR-V 编译路径 — 已删除，只保留 GLSL

**新架构 (v4) — 跨 GPU：**
```
Windows Graphics Capture (capture_wgc)
    → TryGetNextFrame → ID3D11Texture2D
    → CopyResource → staging texture (D3D11_USAGE_STAGING)
    → Map → memcpy → PBO → glTexSubImage2D
    → OpenGL texture → blackhole.glsl → 窗口
```
- `src/capture_wgc.h` / `.cpp` — 新建：WGC 捕获模块
- `src/gl_texture.h` / `.cpp` — 新建：PBO 异步上传模块

### 关键改进

| 问题 (v3) | 解决 (v4) |
|-----------|----------|
| WGL_NV_DX_interop2 仅 NVIDIA | PBO 上传，跨所有 GPU（NVIDIA/AMD/Intel） |
| DXGI Duplication ACCESS_LOST | WGC 无此问题 |
| 无 WS_EX_LAYERED | WS_EX_LAYERED + LWA_COLORKEY 真透明叠加 |
| SPIR-V 编译永远失败 | 删除 SPIR-V 路径，仅 GLSL |
| 无 resize 处理 | resize 检测 + 自动重建纹理 |
| 反馈循环风险 | WDA_EXCLUDEFROMCAPTURE 保护 |

### 新增功能

- **resize 检测**：每帧检查 WGC 帧尺寸，变化时自动重建 staging/纹理/PBO
- **WS_EX_LAYERED**：窗口使用 LWA_COLORKEY 实现真透明叠加
- **double-buffered PBO**：glBufferData orphan + 双缓冲，GPU DMA 与 CPU 写入并行

### 性能特征
- 每帧一次 GPU CopyResource（WGC frame → staging，~0.1ms）
- 每帧一次 CPU memcpy（staging → PBO，8MB @ 1080p，~1ms）
- PBO 上传异步（glTexSubImage2D 使用 DMA，不阻塞 CPU）
- 总体：~1-2ms per frame，60fps 下 12% 时间预算

### 待验证
- ⚠️ 需要实际运行验证 WGC 正常工作
- ⚠️ 需要验证 PBO 上传在全分辨率下性能
- ⚠️ 需要验证 WS_EX_LAYERED 透明叠加效果
- ⚠️ 需要验证 resize 处理（外接显示器场景）

## 修改文件汇总

| 文件 | 操作 | 说明 |
|------|------|------|
| `src/capture_wgc.h` | 新建 | WGC 捕获接口 |
| `src/capture_wgc.cpp` | 新建 | WGC + D3D11 staging 实现 |
| `src/gl_texture.h` | 新建 | PBO 纹理上传接口 |
| `src/gl_texture.cpp` | 新建 | Double-buffered PBO 实现 |
| `src/main.cpp` | 重写 | 集成 WGC+PBO，删除 DXGI/WGL/SPIR-V |
| `CMakeLists.txt` | 修改 | 新源文件 + runtimeobject 库 |
| `src/screen_capture.h` | 删除 | 旧 DXGI 捕获 |
| `src/screen_capture.cpp` | 删除 | 旧 DXGI 捕获 |
| `src/gl_interop.h` | 删除 | 旧 WGL interop (NVIDIA only) |
| `src/gl_interop.cpp` | 删除 | 旧 WGL interop (NVIDIA only) |

## 未修改文件
- `blackhole.glsl` — 保留完整物理模拟
- `shaders/vert.glsl` — 不变
- `shaders/frag_desktop_header.glsl` — 不变
- `shaders/frag_simple.glsl` — 不变
- `shaders/frag_header.glsl` — 不变

## 修改函数

| 函数 | 文件 | 操作 |
|------|------|------|
| `WGC_Init()` | capture_wgc.cpp | 新增 — D3D11 + WGC 会话初始化 |
| `WGC_GetFrame()` | capture_wgc.cpp | 新增 — TryGetNextFrame 获取捕获帧 |
| `WGC_CopyToStaging()` | capture_wgc.cpp | 新增 — CopyResource + Map 到 CPU |
| `WGC_UnmapStaging()` | capture_wgc.cpp | 新增 — Unmap staging |
| `WGC_Release()` | capture_wgc.cpp | 新增 — 释放所有 WGC/D3D11 资源 |
| `GLTex_Init()` | gl_texture.cpp | 新增 — GL 纹理 + 双 PBO 初始化 |
| `GLTex_Upload()` | gl_texture.cpp | 新增 — PBO orphan+map+copy+上传 |
| `GLTex_Resize()` | gl_texture.cpp | 新增 — 重建纹理/PBO（resize 场景） |
| `GLTex_Shutdown()` | gl_texture.cpp | 新增 — 释放 GL 资源 |
| `main()` | main.cpp | 重写 — 新管线集成 |

## 风险验证

| 风险 | 状态 |
|------|------|
| WGC TryGetNextFrame 可用性 | ⚠️ 需运行时验证 |
| CreateDirect3D11DeviceFromDXGIDevice dll 加载 | ⚠️ 需运行时验证 |
| PBO 双缓冲上传性能 | ⚠️ 需运行时验证 |
| WS_EX_LAYERED 透明效果 | ⚠️ 需运行时验证 |
| resize 自动重建 | ⚠️ 需运行时验证 |
| 内存泄漏 | ✅ 每个 Release/Shutdown 配对检查 |