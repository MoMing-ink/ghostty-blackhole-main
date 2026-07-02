# 同步工作区 build 产物到本机使用目录
# 仅同步必要文件，跳过 Qt/QML 运行时（首次部署后不变）
$src = "d:\Projects\ghostty-blackhole-main-main\build"
$dst = "D:\Software\ghostty-blackhole-main\build"

# 停止运行中的进程
Get-Process BlackHole, blackhole_render -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Milliseconds 300

# 仅同步发生变化的可执行文件 + shader
$filesToSync = @(
    "BlackHole.exe",
    "blackhole_render.exe",
    "blackhole.glsl",
    "blackhole_preview.glsl",
    "shaders\vert.glsl",
    "shaders\frag_preview_header.glsl",
    "shaders\blackhole_preview.glsl"
)

foreach ($file in $filesToSync) {
    $srcPath = Join-Path $src $file
    $dstPath = Join-Path $dst $file
    if (Test-Path $srcPath) {
        $dstDir = Split-Path $dstPath -Parent
        if (-not (Test-Path $dstDir)) { New-Item -ItemType Directory -Path $dstDir -Force | Out-Null }
        Copy-Item $srcPath $dstPath -Force
        Write-Host ("  synced: " + $file) -ForegroundColor Green
    } else {
        Write-Host ("  skip (not found): " + $file) -ForegroundColor Yellow
    }
}

Write-Host "`nDone." -ForegroundColor Cyan
