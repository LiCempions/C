@echo off
set folder=%1
set filename=%2
if [%filename%]==[] (
    set filename="*"
)
if exist %folder%\%filename%.* (
    echo Will compile %folder%\%filename%
) else (
    echo %folder%\%filename% not found
    goto :end
)

cd .\%folder%

call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" arm64 >nul
if exist "%filename%.exe" (
    echo This will delete the old .exe file, rename it if you want to keep it
    PAUSE
    echo Deleting old executable...
    del "%filename%.exe"
)
cl "%filename%.*"

del %filename%.obj

:end
if [%2]==[pause] PAUSE
if [%3]==[pause] PAUSE