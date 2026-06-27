# Debug State — Blackhole v10: 视频检测修复

## 当前状态
编译 ✅ 零警告零错误 (2026-06-27)

## 已修复的问题

### 1. GetProcessName 终止符缺失 → 浏览器匹配失败
### 2. 中文字符串编译编码不匹配 → 中文进程名匹配失败  
### 3. 多进程应用 PID 匹配失败 → B站客户端匹配失败
### 4. NVIDIA Overlay + UWP 媒体播放器未识别

## 本轮修改 (v4)

### `src/main.cpp`
| 修改 | 说明 |
|------|------|
| isVideo 新增 `nvidia` | NVIDIA 录播回放界面 |
| UWP 窗口标题检测 | `applicationframehost.exe` 通过窗口标题识别媒体播放器 |
| UWP 音频检测 | 不按进程名过滤，匹配所有音频会话 |

### UWP 窗口标题关键词
电影/电视/媒体/播放/视频/Movies/Media/Player/Video/TV/影视/Films

## 修改文件
- `src/main.cpp` — isWatchingVideo() 逻辑增强
- `CMakeLists.txt` — -fexec-charset=UTF-8

## 修改函数
- `GetProcessName()` — Unicode API + UTF-8 + 终止符修复
- `isWatchingVideo()` — 扩充匹配 + UWP 检测 + 统一进程名匹配

## 风险分析
- UWP 检测匹配所有音频会话，若系统有其他音频播放可能误判
