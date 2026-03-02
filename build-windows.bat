@echo off
REM LunaLite API GUI - Build Script for Windows (MSVC)
REM This script automates the build process for the desktop application

setlocal enabledelayedexpansion

REM Configuration
set PROJECT_NAME=LunaLiteAPIGUI
set BUILD_TYPE=Release
set CMAKE_VERSION=3.16

REM Colors for output
set RED=[91m
set GREEN=[92m
set YELLOW=[93m
set BLUE=[94m
set RESET=[0m

echo.
echo ==========================================================
echo   LunaLite API GUI - Desktop Application Build
echo ==========================================================
echo.

REM Check for required tools
echo [*] Checking for required tools...

where cmake >nul 2>nul
if !errorlevel! neq 0 (
    echo [!] CMake not found. Please install CMake and add to PATH.
    exit /b 1
)
echo [+] CMake found

where cl.exe >nul 2>nul
if !errorlevel! neq 0 (
    echo [!] Visual Studio compiler not found.
    echo     Please run this from Visual Studio Developer Command Prompt.
    exit /b 1
)
echo [+] MSVC found

REM Get Qt path from user or environment
if not defined QT_PATH (
    echo.
    echo [?] Qt path not set in QT_PATH environment variable.
    echo     Please enter Qt installation path (e.g., C:\Qt\5.15.2\msvc2019_64):
    set /p QT_PATH=
)

if not exist "%QT_PATH%" (
    echo [!] Qt path not found: %QT_PATH%
    exit /b 1
)
echo [+] Qt found at: %QT_PATH%

REM Create build directory
echo.
echo [*] Setting up build environment...
if not exist "build" (
    mkdir build
    echo [+] Created build directory
)

cd build

REM Configure with CMake
echo.
echo [*] Configuring project with CMake...
cmake -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH="%QT_PATH%" ..
if !errorlevel! neq 0 (
    echo [!] CMake configuration failed.
    exit /b 1
)
echo [+] Configuration complete

REM Build project
echo.
echo [*] Building project (this may take a few minutes)...
cmake --build . --config %BUILD_TYPE%
if !errorlevel! neq 0 (
    echo [!] Build failed.
    exit /b 1
)
echo [+] Build successful

REM Run application
echo.
echo [*] Build complete!
echo [+] Executable: %BUILD_TYPE%\%PROJECT_NAME%.exe
echo.
echo [?] Do you want to run the application now? (Y/N)
set /p RUN_APP=

if /i "%RUN_APP%"=="Y" (
    echo [*] Starting application...
    start %BUILD_TYPE%\%PROJECT_NAME%.exe
) else (
    echo [*] To run the application manually, execute:
    echo     %BUILD_TYPE%\%PROJECT_NAME%.exe
)

cd ..
echo.
echo [+] Build script completed successfully!
echo.
