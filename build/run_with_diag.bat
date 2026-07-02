@echo off
chcp 65001 >nul
cd /d "%~dp0"

echo ============================================
echo  appBlakholeUI.exe 诊断启动
echo  Working directory: %CD%
echo ============================================
echo.

REM 把 build 目录加到 PATH，确保 Qt6 / MinGW DLL 都能找到
set "PATH=%CD%;%PATH%"

echo [1/3] 检查关键 DLL 是否存在...
echo.

for %%f in (Qt6Core.dll Qt6Gui.dll Qt6Quick.dll Qt6Qml.dll Qt6Widgets.dll Qt6OpenGL.dll Qt6QuickControls2.dll Qt6QuickLayouts.dll Qt6QuickEffects.dll Qt6Network.dll Qt6Svg.dll Qt6QmlModels.dll libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll) do (
    if exist "%%f" (
        echo   [OK]  %%f
    ) else (
        echo   [MISSING]  %%f
    )
)

echo.
echo [2/3] 检查 qml 子目录...
if exist "qml\QtQuick\Controls\qmldir" (
    echo   [OK]  qml\QtQuick\Controls
) else (
    echo   [MISSING]  qml\QtQuick\Controls
)
if exist "qml\QtQuick\Layouts\qmldir" (
    echo   [OK]  qml\QtQuick\Layouts
) else (
    echo   [MISSING]  qml\QtQuick\Layouts
)
if exist "qml\QtQuick\Effects\qmldir" (
    echo   [OK]  qml\QtQuick\Effects
) else (
    echo   [MISSING]  qml\QtQuick\Effects
)
if exist "platforms\qwindows.dll" (
    echo   [OK]  platforms\qwindows.dll
) else (
    echo   [MISSING]  platforms\qwindows.dll
)
if exist "styles\qmodernwindowsstyle.dll" (
    echo   [OK]  styles\qmodernwindowsstyle.dll
) else (
    echo   [MISSING]  styles\qmodernwindowsstyle.dll
)

echo.
echo [3/3] 启动 appBlakholeUI.exe...
echo   如果弹出"找不到 dll"对话框, 请记录具体的 dll 文件名
echo   如果程序正常启动, 关闭后此窗口会自动退出
echo.

start "appBlakholeUI" /wait appBlakholeUI.exe

echo.
echo ============================================
echo  程序已退出, ExitCode=%ERRORLEVEL%
echo  如果上面有 [MISSING] 项, 就是问题所在
echo ============================================
pause
