@echo off
REM paths to Qt and MinGW64
SET QT_BIN_DIR=C:\Dev\Qt\5.12.2\mingw73_64\bin

REM release or debug
SET MODE=release
SET SOURCE_DIR=%~dp0..\build\cmake-build-%MODE%-mingw-64\CenterDot.exe

REM @echo on

echo ===== Setting up deploy directory =====
echo Deploy directory is %SOURCE_DIR%

echo ===== Copying executables and files =====
REM TODO copy executables
REM TODO copy icons
REM TODO copy assets

echo ===== Copying MinGW DLLs =====
REM TODO copy libgcc_s_dw2-1.dll from %MINGW_BIN_DIR%
REM TODO copy libwinpthread-1.dll from %MINGW_BIN_DIR%
REM TODO copy libstdc++-6.dll from %MINGW_BIN_DIR%

@echo on
echo ===== Deploy for Windows =====
echo Mode: %MODE%
"%QT_BIN_DIR%\windeployqt.exe" --%MODE% "%SOURCE_DIR%"

@echo off
echo ===== Cleaning up unused libraries =====
REM TODO delete D3Dcompiler_43.dll
REM TODO delete opengl32sw.dll
REM TODO delete libGLESV2.dll

REM TODO create InnoSetup install script

@echo on