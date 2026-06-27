# Black Hole Watchdog
# 空闲时启动blackhole.exe，活跃时关闭

Add-Type @"
using System;
using System.Runtime.InteropServices;
public class IdleCheck {
    [StructLayout(LayoutKind.Sequential)]
    struct LASTINPUTINFO { public uint cbSize; public uint dwTime; }
    [DllImport("user32.dll")]
    static extern bool GetLastInputInfo(ref LASTINPUTINFO plii);
    public static uint GetIdleMs() {
        LASTINPUTINFO lii = new LASTINPUTINFO();
        lii.cbSize = (uint)Marshal.SizeOf(typeof(LASTINPUTINFO));
        GetLastInputInfo(ref lii);
        return (uint)Environment.TickCount - lii.dwTime;
    }
}
"@

$idleSec = 300
$checkInterval = 5
$exePath = Join-Path (Split-Path -Parent $MyInvocation.MyCommand.Path) "build\blackhole.exe"

Write-Host "Black Hole Watchdog (idle=$idleSec`s)" -ForegroundColor Cyan

while ($true) {
    $idleActual = [IdleCheck]::GetIdleMs() / 1000
    $proc = Get-Process -Name "blackhole" -ErrorAction SilentlyContinue
    if ($idleActual -ge $idleSec -and !$proc) {
        Start-Process -FilePath $exePath -WorkingDirectory (Split-Path $exePath -Parent) -WindowStyle Hidden
    }
    if ($idleActual -lt $idleSec -and $proc) {
        $proc | Stop-Process -Force
    }
    Start-Sleep -Seconds $checkInterval
}
