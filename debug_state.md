# Debug State — Blackhole v5: ImGui Config Panel

## 当前状态

### 编译 ◆
- 零警告零错误
- 源文件: main.cpp + capture_wgc.cpp + capture_dxgi.cpp + gl_texture.cpp + gui_config.cpp + imgui/*
- 依赖: glfw + opengl32 + d3d11 + dxgi + runtimeobject + dwmapi + comctl32

### 启动流程
```
双击 blackhole.exe
  → ImGui 配置面板 (520x420)
    → 选择模式: Always On / Idle Detection
    → 设置空闲超时 (仅 Idle 模式)
    → 点击 START
  → 全屏黑洞 overlay 启动
  → ESC 退出
```

### 默认模式: WGC
- `blackhole.exe` → 配置面板 → WGC 黑洞

### GPU 管线
```
Capture(GetFrame) → CopyResource → Map → glTexSubImage2D → blackhole.glsl → 渲染
```
无 fence、无 Flush、无 PBO、无 SPIR-V。纯顺序同步。

### 窗口设置
- WS_EX_TRANSPARENT — 点击穿透
- WS_EX_TOOLWINDOW — 隐藏任务栏
- WS_EX_NOACTIVATE — 禁止激活
- WDA_EXCLUDEFROMCAPTURE — 防反馈循环
- WM_NCACTIVATE→FALSE — 防黄框
- DWMWA_NCRENDERING_POLICY=DISABLED — 禁用非客户区

## 文件结构
| 文件 | 说明 |
|------|------|
| src/main.cpp | 主程序：配置面板 + 渲染循环 |
| src/gui_config.h/cpp | ImGui 配置面板 |
| src/capture_wgc.h/cpp | WGC 捕获 |
| src/capture_dxgi.h/cpp | DXGI 捕获(备选) |
| src/gl_texture.h/cpp | GL 纹理上传 |
| src/imgui/* | ImGui 库文件 |