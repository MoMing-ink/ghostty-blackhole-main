$env:PATH = "C:\msys64\ucrt64\bin;C:\msys64\usr\bin;$env:PATH"
$ws = "d:\Projects\ghostty-blackhole-main-main"

# 编译资源文件（包含图标）- 使用 coff 格式
Write-Host "Compiling resource file..."
& windres --output-format=coff --input-format=rc -o "$ws\build\resource.o" "$ws\resource.rc" 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "windres failed, continuing without icon..."
}

# 编译 blackhole_render.exe (渲染器) — 不再依赖 ImGui/GLFW
Write-Host "Compiling blackhole_render.exe (renderer)..."
$resourceFile = if (Test-Path "$ws\build\resource.o") { "$ws\build\resource.o" } else { "" }

& g++ -std=c++17 -O2 -o "$ws\build\blackhole_render.exe" `
    "$ws\src\main.cpp" `
    "$ws\src\capture_wgc.cpp" `
    "$ws\src\capture_dxgi.cpp" `
    "$ws\src\gl_texture.cpp" `
    "$ws\src\gui_config.cpp" `
    "$ws\src\win32_gl.cpp" `
    $resourceFile `
    -I"C:\msys64\ucrt64\include" `
    -L"C:\msys64\ucrt64\lib" `
    -lopengl32 -lgdi32 -ld3d11 -ldxgi -lruntimeobject -ldwmapi -lcomctl32 -lole32 `
    -mwindows 2>&1

if ($LASTEXITCODE -ne 0) {
    Write-Host "BUILD FAILED (exit $LASTEXITCODE)"
    Remove-Item "$ws\build\resource.o" -Force -ErrorAction SilentlyContinue
    exit 1
}

Write-Host "blackhole_render.exe BUILD SUCCESS"
Get-Item "$ws\build\blackhole_render.exe" | Select-Object Length, LastWriteTime

# 复制着色器到 build 目录
if (-not (Test-Path "$ws\build\shaders")) { New-Item -ItemType Directory -Path "$ws\build\shaders" | Out-Null }
Copy-Item "$ws\shaders\*" "$ws\build\shaders\" -Force
Copy-Item "$ws\blackhole.glsl" "$ws\build\blackhole.glsl" -Force

# 同步原版新增的 preview shader
if (Test-Path "D:\Projects\_upstream_new\ghostty-blackhole-main-main\shaders\blackhole_preview.glsl") {
    Copy-Item "D:\Projects\_upstream_new\ghostty-blackhole-main-main\shaders\blackhole_preview.glsl" "$ws\shaders\" -Force
    Copy-Item "D:\Projects\_upstream_new\ghostty-blackhole-main-main\shaders\blackhole_preview.glsl" "$ws\build\shaders\" -Force
}
if (Test-Path "D:\Projects\_upstream_new\ghostty-blackhole-main-main\shaders\frag_preview_header.glsl") {
    Copy-Item "D:\Projects\_upstream_new\ghostty-blackhole-main-main\shaders\frag_preview_header.glsl" "$ws\shaders\" -Force
    Copy-Item "D:\Projects\_upstream_new\ghostty-blackhole-main-main\shaders\frag_preview_header.glsl" "$ws\build\shaders\" -Force
}

# 同步 MinGW runtime DLL 到 build 目录 (避免版本不匹配导致 STATUS_ENTRYPOINT_NOT_FOUND)
Write-Host "Syncing MinGW runtime DLLs..."
$runtimeDlls = @("libgcc_s_seh-1.dll", "libstdc++-6.dll", "libwinpthread-1.dll", "libgomp-1.dll")
foreach ($dll in $runtimeDlls) {
    $src = "C:\msys64\ucrt64\bin\$dll"
    if (Test-Path $src) {
        Copy-Item $src "$ws\build\" -Force
    }
}

# 清理临时文件
Remove-Item "$ws\build\resource.o" -Force -ErrorAction SilentlyContinue
