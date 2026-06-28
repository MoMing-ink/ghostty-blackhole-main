# Debug State — Blackhole: GLFW → Win32+WGL 迁移 完成

## 当前状态
编译 ✅ 零警告零错误 (2026-06-28)

## 本次修改总结

### 架构变更
```
修改前: GLFW(窗口+OpenGL上下文) + WGC(捕获) + OpenGL(渲染)
修改后: Win32+WGL(窗口+OpenGL上下文) + WGC(捕获) + OpenGL(渲染)
```

### 新增文件
| 文件 | 说明 |
|------|------|
| src/win32_gl.h | Win32窗口+WGL OpenGL上下文模块头文件 |
| src/win32_gl.cpp | 实现：窗口类注册、WGL上下文创建、DWM属性控制、消息循环 |

### 修改文件
| 文件 | 修改内容 |
|------|----------|
| src/main.cpp | 渲染器路径：GLFW → Win32GL；glfwInit移到配置面板分支 |
| CMakeLists.txt | 添加 win32_gl.cpp 到编译源列表 |

### 核心变更点
1. **窗口创建**: 直接使用 CreateWindowExW，从创建开始就设置 WS_EX_NOACTIVATE / TOOLWINDOW / TRANSPARENT / NOREDIRECTIONBITMAP
2. **OpenGL上下文**: WGL两步法创建（临时上下文→wglCreateContextAttribsARB→3.3兼容上下文）
3. **消息循环**: PeekMessage / DispatchMessage 替代 glfwPollEvents
4. **帧缓冲交换**: SwapBuffers(hdc) 替代 glfwSwapBuffers
5. **计时器**: QueryPerformanceCounter 替代 glfwGetTime
6. **GL函数加载**: Win32GL_GetProcAddress(wglGetProcAddress + opengl32.dll回退) 替代 glfwGetProcAddress

### 未修改模块
- 配置面板（ImGui + GLFW）：保持不变
- 空闲检测（isWatchingVideo, isIdle）
- 监视器/托盘图标（MonitorSpawn, MonitorKill）
- WGC捕获（capture_wgc）
- Shader编译和渲染逻辑
- GLTexture模块

### 下一步
- 第二/三阶段：Renderer 常驻化（永久进程，通过 IPC 通信）
- 考虑 D3D11 渲染层替代 OpenGL
