# Black Hole — Windows 桌面黑洞屏保

![demo](demo.gif)

基于 Eric Bruneton 黑洞着色器的 Windows 桌面黑洞可视化程序。捕获桌面画面，实时渲染史瓦西黑洞的引力透镜、吸积盘、光子环等相对论效应。

## 快速开始

1. 双击 `build\blackhole.exe`
2. 配置参数 → 点击 **"启动"**
3. 黑洞在**空闲时自动显示**，动鼠标/键盘即消失
4. 右下角托盘图标 → 右键可调出配置或退出

## 开机自启

配置面板勾选 **"开机自启"** 并保存后，程序注册到 Windows 启动项，开机时以 `--monitor` 模式**无感启动**：直接读取上次保存的配置进入托盘监控，**不弹配置面板**。

## 运行模式

| 模式 | 行为 |
|------|------|
| **始终显示** | 黑洞常驻桌面 |
| **空闲检测** | 空闲 N 秒后显示，活跃时自动隐藏 |

空闲时间在配置页面设置（默认 300 秒 / 5 分钟）。

## 双进程架构

```
blackhole.exe             配置器 + 空闲监控器（托盘图标）
blackhole.exe --monitor   无感启动：跳过配置面板，直接进托盘监控
blackhole.exe --config    托盘"配置"菜单调出：保存后重启 monitor
blackhole.exe --render    黑洞渲染器（由监控器自动启停）
```

### 为什么这样设计？

Windows 11 的 DWM 会对全屏透明窗口施加**强调色边框**（黄边框），且 show/hide 窗口会触发 DWM 重建缓存。经过多轮迭代，发现以下方案均存在缺陷：

| 尝试方案 | 问题 |
|----------|------|
| opacity=0 隐藏 | 破坏 swap chain，导致黑屏 |
| ShowWindow 隐藏 | 触发 DWM 黄色 accent 边框 |
| 缩成 1×1 像素 | 仍有 DWM 合成开销 |
| WM hook 拦截 | 无法阻止 DWM 的缓存 accent layer |

**最终方案：进程级隔离**
- 渲染器启动即创建窗口（带 DWM 防护：DWMWA_BORDER_COLOR=0 + DWMNCRP_DISABLED + DwmFlush）
- 活跃时**直接终止渲染器进程**（优雅 WM_CLOSE 退出）
- 空闲时**重新启动渲染器进程**（全新 GL 上下文 + 全新 DWM 状态）
- 每次启动使用**唯一窗口标题**防止 DWM 缓存匹配

## 空闲检测原理

程序使用**三层检测机制**判断用户是否在观看视频：

### 检测流程

```
每 1 秒执行一次
├── Method 1: D3D 独占全屏检测
│   └── SHQueryUserNotificationState → 检测游戏/全屏独占应用
├── Method 1b: 无边框全屏窗口检测
│   ├── 前景窗口尺寸 ≥ 屏幕分辨率 → 全屏播放
│   ├── 排除最大化窗口（WS_MAXIMIZE）避免误判编辑器/浏览器
│   └── 排除桌面窗口（Progman/WorkerW）避免误判桌面本身
└── Method 3: 音频会话检测
    ├── 获取前景窗口进程名
    ├── 匹配已知视频应用列表（中/英文进程名）
    ├── 对 UWP 应用（电影和电视等）检测窗口标题
    └── 枚举 Windows 音频会话，比对进程名 + 音频峰值
```

### 匹配策略

- **进程名匹配**：所有视频应用统一使用进程名比对（而非 PID），兼容浏览器、Electron 等多进程架构
- **UWP 特殊处理**：`ApplicationFrameHost.exe` 是 UWP 应用的外壳进程，程序会读取窗口标题识别媒体播放器，并检测**所有**音频会话
- **黑洞自身排除**：通过窗口类名 `BlackHoleWGL` 和 `WS_EX_NOACTIVATE | WS_EX_TOPMOST | WS_EX_TRANSPARENT` 扩展样式组合排除黑洞自己的渲染窗口，防止误判死循环
- **桌面窗口排除**：`Progman`（桌面）和 `WorkerW`（桌面图标层）天然铺满全屏但不是游戏，已加入排除列表
- **编码兼容**：进程名使用 UTF-8 统一编码，支持中英文混用场景

### 支持的应用

| 类别 | 应用 |
|------|------|
| **浏览器** | Chrome, Edge, Firefox, Opera, Brave |
| **国内视频平台** | 哔哩哔哩, 爱奇艺, 优酷, 芒果TV, 抖音, 快手, 腾讯视频 |
| **本地播放器** | VLC, MPV, PotPlayer, MPC, Windows Media Player, NVIDIA Overlay |
| **UWP 播放器** | 电影和电视, 媒体播放器（窗口标题关键词检测） |

### 桌面壁纸音频

壁纸引擎（如 Wallpaper Engine）播放的音频**不会阻止黑洞触发**——程序通过窗口/进程名过滤，仅前景视频应用才计入活跃状态。

## 配置参数

### 黑洞预设

- **16 个内置预设**（Inferno、Gargantua、M87* Donut、Quasar、Blazar、Crimson Vortex、Azure Spiral 等）
- 14 个可调参数（色温、倾角、旋转、半径、不透明度、多普勒、光束指数、亮度增益、条纹对比度、缠绕紧度、旋转速度、曝光度、星空亮度、透镜率）
- 全部使用**滑块调节**
- 支持**复制/粘贴**预设、**上移/下移**排序
- 每次启动**随机化初始位置、轨迹相位、风格预设偏移**（相同预设每次出现位置不同）

### 播放模式

- **顺序播放**：从第 1 个预设播到最后一个
- **循环播放**：播完回到第一个，无限循环
- **随机播放**：每个时段随机抽取预设

预设之间使用 **crossfade 平滑过渡**（DEMO_XFADE = 0.65，约 65% 槽位时长用于淡入淡出）。

## 窗口层级保护

黑洞作为桌面覆盖层，窗口 Z 序分层采用了最终稳定方案：

```cpp
// win32_gl.cpp — 窗口创建
DWORD exStyle = WS_EX_NOACTIVATE | WS_EX_TOPMOST | WS_EX_TOOLWINDOW |
                WS_EX_TRANSPARENT | WS_EX_LAYERED;
```

- **WS_EX_TOPMOST** — 创建时即声明为 DWM 合成层最高优先级，不会被其他置顶窗口覆盖
- **WS_EX_NOACTIVATE** — 永不抢焦点，不打断用户当前操作
- **WS_EX_TRANSPARENT + WS_EX_LAYERED** — Layered Window 鼠标穿透（配合 `WM_NCHITTEST → HTTRANSPARENT`）
- **WS_EX_TOOLWINDOW** — 不在任务栏和 Alt+Tab 中出现

### DWM 防护层

- DWMWA_BORDER_COLOR = 0 — accent 边框透明
- DWMNCRP_DISABLED — 禁用非客户区渲染
- DwmEnableBlurBehindWindow(FALSE) — 禁用模糊背景
- DwmFlush() — 清除合成器缓存
- WM_NCCALCSIZE return 0 — 移除整个非客户区
- WDA_EXCLUDEFROMCAPTURE — 排除自身被 WGC 捕获（防止黑洞纹理自反馈）

### 光标处理

程序**不隐藏系统光标**。WGC 捕获时通过 `IsCursorCaptureEnabled = false` 禁用光标捕获，避免全局 `SetSystemCursor` 带来的退出后光标异常问题。

## 文件结构

```
ghostty-blackhole-main/
├── blackhole.exe              # 主程序（构建输出）
├── blackhole.glsl             # 黑洞着色器（GLSL）
├── blackhole_presets.txt      # 预设配置文件（v4 格式）
├── blackhole.ico              # 程序图标
├── resource.rc                # Windows 资源文件（图标）
├── build_blackhole.ps1        # 构建脚本（windres + g++ -O2）
├── LICENSE                    # MIT 许可证
├── README.md                  # 本文件
├── CHANGES.md                 # 改动记录（相比原版）
│
├── src/                       # 源代码
│   ├── main.cpp               # 入口（OpenGL 路径，双进程管理）
│   ├── capture_wgc.cpp/h      # WGC 桌面捕获
│   ├── capture_dxgi.cpp/h     # DXGI Duplication 备用捕获
│   ├── gl_texture.cpp/h       # OpenGL 纹理管理
│   ├── win32_gl.cpp/h         # Win32 + WGL 窗口
│   ├── gui_config.cpp/h       # ImGui 配置面板（16 预设）
│   └── imgui/                 # ImGui 库
│
├── shaders/                   # 着色器
│   ├── vert.glsl              # OpenGL 顶点着色器
│   ├── frag_desktop_header.glsl  # 桌面片段着色器头（含 uniform 覆盖）
│   ├── frag_header.glsl       # OpenGL 公共头
│   └── frag_simple.glsl       # OpenGL 简单片段着色器
│
└── build/                     # 构建输出 + 运行时依赖
    ├── blackhole.exe          # 主程序（带图标，-O2 优化，约 1.77MB）
    ├── blackhole.glsl         # 着色器副本
    ├── shaders/               # 着色器副本
    ├── glfw3.dll              # GLFW 运行时
    ├── libgcc_s_seh-1.dll     # MinGW 运行时
    ├── libstdc++-6.dll        # MinGW C++ 运行时
    └── libwinpthread-1.dll    # MinGW 线程运行时
```

## 构建

### 依赖

- **MinGW-w64 (ucrt64)** — `C:\msys64\ucrt64\bin`
- **GLFW3** — `C:\msys64\ucrt64\include` / `lib`
- **windres** — 编译资源文件（嵌入图标）

### 编译

```powershell
powershell -ExecutionPolicy Bypass -File build_blackhole.ps1
```

脚本会：
1. 设置 PATH 包含 ucrt64
2. `windres` 编译 `resource.rc` → `resource.o`（嵌入图标）
3. `g++ -std=c++17 -O2` 编译所有源码并链接 `resource.o`
4. 输出 `build\blackhole.exe`（约 1.77MB，带图标）
5. 复制 shader 到 build 目录
6. 清理临时 `resource.o`

### 运行时依赖

`build\` 目录下必须包含：
- `blackhole.glsl` + `shaders\` 目录
- `glfw3.dll`, `libgcc_s_seh-1.dll`, `libstdc++-6.dll`, `libwinpthread-1.dll`

## 桌面捕获：WGC

项目使用 **Windows Graphics Capture (WGC)** 作为桌面捕获方案：

| 维度 | WGC |
|------|-----|
| 帧来源 | DWM 合成快照 |
| 帧完整性 | 大画面变动时可能拿到半帧 |
| 帧稳定性 | 持续输出，不卡死 |
| 光标 | 默认捕获（已通过 `IsCursorCaptureEnabled = false` 禁用） |
| 多 GPU | 支持 |
| DRM 内容 | 可捕获 |
| 全屏独占程序 | 可捕获 |
| 延迟 | 有 DWM 合成延迟 |
| API 复杂度 | WinRT（高） |
| 恢复机制 | 自动 |

### WGC 黄边框抑制

Win11 会对屏幕捕获绘制黄色强调色边框。通过 `IGraphicsCaptureSession3::put_IsBorderRequired(false)` 通知 DWM 不要绘制边框（Win11 22H2+）。

> ⚠️ 非官方关闭开关，Windows 在某些场景下仍可能显示边框。

## 已知问题

| 问题 | 状态 | 说明 |
|------|------|------|
| Win11 黄边框 | 已抑制 | `IsBorderRequired(false)` 降低概率，非 100% 消除 |
| 游戏启动器误判 | 已修复 | 移除游戏启动器列表，真正的全屏游戏仍会被 Method 1/1b 捕获 |
| 桌面误判 | 已修复 | 排除 Progman/WorkerW 桌面窗口 |
| 黑洞自身误判 | 已修复 | 排除 BlackHoleWGL 窗口类和特定扩展样式组合 |
| 旧进程冲突 | 已修复 | 启动时枚举进程杀旧实例（`--config`/`--render` 除外） |

## 技术栈

- **OpenGL 3.3** — 渲染
- **Win32 + WGL** — 原生窗口 + OpenGL 上下文（替代 GLFW 获得完整桌面特效控制）
- **ImGui** — 配置界面
- **Windows Graphics Capture (WGC)** — 桌面捕获
- **MinGW-w64 (ucrt64)** — 编译工具链
- **windres** — 资源编译（图标嵌入）

## 灵感来源

[Eric Bruneton's black hole shader](https://github.com/ebruneton/black_hole_shader) (BSD-3-Clause)

## License

MIT — 见 [LICENSE](LICENSE)
