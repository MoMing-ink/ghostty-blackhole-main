# Debug State — Blackhole v8: 播放模式 + 粘贴改进 + 无终端

## 当前状态
### 编译 ✓ - 零警告零错误

## 新增功能 (2026-06-27)

### 粘贴自动新增
- 粘贴按钮现在创建新预设（而非覆盖当前）
- 上限 16 个，到达上限时按钮无效

### 三种播放模式
- **顺序播放 (默认)**: 从第1个播到最后一个，然后停留在最后一个
- **循环播放**: 播完最后一个回到第一个，无限循环
- **随机播放**: 每个时段随机抽取预设（基于时间哈希，确保同一时段显示同一预设）
- 左侧面板新增下拉选择器 + 模式说明文字

### 不弹出终端
- main() 开头调用 `ShowWindow(GetConsoleWindow(), SW_HIDE)` 隐藏控制台窗口
- CMakeLists.txt 已有 `-mwindows` 编译标志（Windows GUI 子系统）

### 修改文件
- `src/gui_config.h` — 新增 `int playMode = 0;`
- `src/gui_config.cpp` — 粘贴改为新增 + 播放模式选择器
- `shaders/frag_desktop_header.glsl` — 新增 `uniform int uPlayMode = 0;`
- `src/main.cpp` — shader注入播放模式逻辑 + `loc_uPM` 上传 + 隐藏终端
