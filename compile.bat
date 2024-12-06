echo off
set folder=%1
set filename=%2
if %filename%=="" (
    set filename="*"
)
if exist %folder%\%filename%.c (
    echo Will compile %folder%\%filename%.c
) else (
    echo "%folder%\%filename%.c" not found
    goto end
)

cd .\%folder%

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" arm64
cl "%filename%.c"

del %filename%.obj

:end
if %3==pause ( PAUSE )