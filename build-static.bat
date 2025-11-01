@echo off
REM 
REM 

echo Building statically linked executable...
echo.

REM 
where g++ >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: g++ not found! Please install MinGW or MSYS2.
    echo.
    pause
    exit /b 1
)

REM 
REM 
REM 
REM 
REM 
g++ -std=c++17 -Wall -Wextra -pedantic -O3 -static -static-libgcc -static-libstdc++ -o number-guessing-game-static.exe main.cpp

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo Build successful!
    echo ========================================
    echo.
    echo Created: number-guessing-game-static.exe
    echo.
    echo This executable is fully portable and can be run on any Windows machine
    echo without requiring any additional DLLs or runtime libraries.
    echo.
) else (
    echo.
    echo ========================================
    echo Build failed!
    echo ========================================
    echo.
)

pause

