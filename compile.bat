echo off
set folder=%1
set filename=%2
if %filename%=="" (
    set filename="*"
)
echo Will compile %folder%\%filename%.c
cd .\%folder%

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" arm64
cl "%filename%.c"

if %3==pause (
    PAUSE
)