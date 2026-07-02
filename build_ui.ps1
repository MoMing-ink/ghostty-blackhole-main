$env:PATH = "C:\msys64\ucrt64\bin;C:\msys64\ucrt64\share\qt6\bin;C:\msys64\usr\bin;$env:PATH"
$ws = "d:\Projects\ghostty-blackhole-main-main"

Write-Host "=== Building Qt QML UI (BlackHole.exe) ==="

$buildDir = "$ws\build_qt"
if (Test-Path $buildDir) { Remove-Item $buildDir -Recurse -Force }
New-Item -ItemType Directory -Path $buildDir | Out-Null

Push-Location $buildDir

& cmake -G Ninja `
    -DCMAKE_BUILD_TYPE=Release `
    -DCMAKE_PREFIX_PATH="C:/msys64/ucrt64/lib/cmake/Qt6" `
    "$ws/Blakhole_UI" 2>&1 | Out-String

if ($LASTEXITCODE -ne 0) {
    Write-Host "CMAKE CONFIGURE FAILED"
    Pop-Location
    exit 1
}

& cmake --build . --config Release 2>&1 | Out-String

if ($LASTEXITCODE -ne 0) {
    Write-Host "BUILD FAILED"
    Pop-Location
    exit 1
}

Pop-Location

# 复制到 build 目录
$srcExe = "$buildDir\BlackHole.exe"
$dstExe = "$ws\build\BlackHole.exe"

if (Test-Path $srcExe) {
    Copy-Item $srcExe $dstExe -Force
    Write-Host "BlackHole.exe BUILD SUCCESS"
    Get-Item $dstExe | Select-Object Length, LastWriteTime

    # 部署 Qt DLL（windeployqt 需要 qmlimportscanner 在 PATH 中）
    Write-Host "Running windeployqt..."
    & "C:\msys64\ucrt64\bin\windeployqt.exe" --release --no-translations --no-system-d3d-compiler --no-opengl-sw `
        --qmldir "$ws\Blakhole_UI" --qmldir "$ws\Blakhole_UI\pages" --qmldir "$ws\Blakhole_UI\components" `
        "$dstExe" 2>&1 | Select-String -Pattern "Error|fail|Cannot" -CaseSensitive:$false | Select-Object -First 5

    # windeployqt 不会复制 MinGW runtime DLL 和 Qt6 的间接依赖 (libmd4c/libharfbuzz/libicu 等)
    # 这些 DLL 是 Qt6Gui.dll / Qt6Core.dll 等间接依赖的, 缺失会报「由于找不到 xxx.dll」系统错误
    Write-Host "Copying MinGW runtime + Qt6 indirect dependencies..."
    $indirectDeps = @(
        # MinGW runtime
        "libgcc_s_seh-1.dll", "libstdc++-6.dll", "libwinpthread-1.dll", "libgomp-1.dll",
        # Qt6Core 依赖
        "libb2-1.dll", "libdouble-conversion.dll",
        "libicuin78.dll", "libicuuc78.dll", "libicudt78.dll",
        "libpcre2-16-0.dll", "libpcre2-8-0.dll",
        "zlib1.dll", "libzstd.dll",
        # Qt6Gui 依赖 (字体/Markdown/图像)
        "libmd4c.dll", "libmd4c-html.dll",
        "libfreetype-6.dll", "libharfbuzz-0.dll", "libpng16-16.dll",
        "libbz2-1.dll", "libgraphite2.dll",
        "libglib-2.0-0.dll", "libffi-8.dll", "libintl-8.dll", "libiconv-2.dll",
        # Qt6Network 依赖 (brotli)
        "libbrotlidec.dll", "libbrotlicommon.dll", "libbrotlienc.dll"
    )
    foreach ($dll in $indirectDeps) {
        $srcDll = "C:\msys64\ucrt64\bin\$dll"
        if (Test-Path $srcDll) {
            Copy-Item $srcDll "$ws\build\" -Force
        }
    }

    # 复制 shader 文件到 build 目录 (QML 预览渲染器需要)
    # resolveShaderPath() 找: build/shaders/vert.glsl, build/shaders/frag_preview_header.glsl, build/blackhole_preview.glsl
    Write-Host "Copying shaders for QML preview..."
    if (-not (Test-Path "$ws\build\shaders")) { New-Item -ItemType Directory -Path "$ws\build\shaders" | Out-Null }
    Copy-Item "$ws\shaders\vert.glsl" "$ws\build\shaders\" -Force
    Copy-Item "$ws\shaders\frag_preview_header.glsl" "$ws\build\shaders\" -Force
    Copy-Item "$ws\shaders\blackhole_preview.glsl" "$ws\build\shaders\" -Force
    # blackhole_preview.glsl 必须在 build 根目录 (resolveShaderPath 找的是 build/blackhole_preview.glsl)
    Copy-Item "$ws\shaders\blackhole_preview.glsl" "$ws\build\blackhole_preview.glsl" -Force
    # blackhole.glsl 给 blackhole.exe 渲染器用
    Copy-Item "$ws\blackhole.glsl" "$ws\build\blackhole.glsl" -Force

    Write-Host "Deployment complete. build/ contents:"
    Get-ChildItem "$ws\build" -File | Where-Object { $_.Length -gt 1MB } | Select-Object Name, @{N='SizeMB';E={[math]::Round($_.Length/1MB,2)}}, LastWriteTime | Format-Table -AutoSize
} else {
    Write-Host "BlackHole.exe not found"
    exit 1
}
