@echo off
cd /d C:\xampp\htdocs\cs\CalculateFloatSkins

echo A compilar calculateBestFloat.cpp...
g++ -std=c++17 -o calculateBestFloat calculateBestFloat.cpp
if %errorlevel% neq 0 (
    echo.
    echo ❌ Erro na compilação.
    pause
    exit /b %errorlevel%
)

echo.
echo ✅ Compilação bem-sucedida. A executar o programa...
echo.
calculateBestFloat.exe
pause