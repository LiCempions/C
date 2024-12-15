@echo off
if "%*"==[] goto :tutorial

set directory=%1
if %directory:~0,1% neq \ set files=%* && goto :processFiles

:folderFound
cd %CD%%directory%
@REM Strip folder name
for /f "tokens=1*" %%i in ("%*") do ( set files=%%j )

:processFiles
echo Will compile the following files in %CD% to dll: %files%
echo Initializing environment for compiler...
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" arm64 >nul

echo Deleting existing library files...
for %%f in ( %files% ) do if exist "%%f.dll" del "%%f.dll"

echo Compiling...
for %%f in ( %files% ) do cl /LD ".\%%f.*"

echo Cleaning up...
for %%f in ( %files% ) do if exist "%%f.obj" del "%%f.obj"
goto :eof

:tutorial
echo:
echo ---- DLLCOMPILE (mini) GUIDE ----
echo:
echo Syntax: dllcompile.bat [\relativePath] file1 file2 ...
echo:
echo relativePath: (optional) path to the folder containing the files. Must contain a leading backslash. If omitted the current directory will be used.
echo fileN: file names to compile to .dll files
echo: