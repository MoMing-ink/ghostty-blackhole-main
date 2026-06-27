# Debug State — Blackhole v10: 配置器 + 渲染器 进程分离

## 当前状态
### 编译 ✓ - 零警告零错误 (2026-06-27)

## 架构：双进程分离

`
blackhole.exe             → 配置页面 + 空闲监控（Monitor）
blackhole.exe --render    → 黑洞渲染（Renderer）
`

### 流程
`
用户打开 blackhole.exe
    ↓
配置页面 (ImGui)
    ↓ 点击"启动"
保存配置 → 启动 blackhole.exe --render → 进入监控循环
    ↓                                    ↓
每5秒检测空闲                          读取配置渲染黑洞
    ↓                                    ↓
空闲 → 启动渲染器                       ESC → 退出
活跃 → 关闭渲染器                       被监控关闭 → 退出
`

### 关键点
- 渲染器永不处理空闲逻辑（由监控器管理）
- 监控器不开 OpenGL 窗口（纯后台进程）
- 进程级隔离：无 DWM/opacity/show-hide 问题
- 活跃时渲染器进程不存在 → 零 GPU/CPU 负载

## 修改文件
- src/main.cpp — 进程拆分 + 监控循环
