@echo off

SETLOCAL ENABLEEXTENSIONS
SETLOCAL ENABLEDELAYEDEXPANSION

rem ****************************************************************************
rem * MAKESUPPORT_DIR has to be set to MakeSupport root directory
rem * There MUSTNOT be any blanks between the '=' sign and the path string
rem * Example:
rem *     set MAKESUPPORT_DIR=..\70_Tools\41_MakeSupportDelta\bin
rem ****************************************************************************
IF "%USERNAME%" EQU "DEHAPHU$" GOTO SETTING_PHUHA
IF "%USERNAME%" EQU "DESOEAP06$" GOTO SETTING_CI_SERVER
IF "%USERNAME%" EQU "deenstr" GOTO SETTING_DEENSTR
IF "%USERNAME%" EQU "detheit" GOTO SETTING_DETHEIT
IF "%USERNAME%" EQU "DECHRIA" GOTO SETTING_DECHRIA
IF "%USERNAME%" EQU "Nagashree.Kashyap" GOTO SETTING_NAGASHREE_KASHYAP
IF "%USERNAME%" EQU "DESHETS" GOTO SETTING_DESHETS
IF "%USERNAME%" EQU "Jagadish.Selokar" GOTO SETTING_PHUHA
IF "%USERNAME%" EQU "DEKRAFM" GOTO SETTING_DESHETS
IF "%USERNAME%" EQU "dekrafm" GOTO SETTING_DESHETS
IF "%USERNAME%" EQU "Saurabh.K" GOTO SETTING_SK
IF "%USERNAME%" EQU "Keshavan.A" GOTO SETTING_KESHAVAN
IF "%USERNAME%" EQU "Bhavin.PV" GOTO SETTING_BHAVIN

:SETTING_PHUHA
echo Username: %USERNAME%
echo Used settings: SETTING_PHUHA
set INSTALLED_COMPILER_DIR=C:\HIGHTEC_RNA\toolchains\tricore\v4.6.6.1
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=C:\DEV\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=C:\DEV\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING

:SETTING_KESHAVAN
echo Username: %USERNAME%
echo Used settings: SETTING_KESHAVAN
set INSTALLED_COMPILER_DIR=C:\HIGHTEC\toolchains\tricore\v4.6.6.1
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=C:\DEV\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=C:\DEV\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING

:SETTING_BHAVIN
echo Username: %USERNAME%
echo Used settings: SETTING_BHAVIN
set INSTALLED_COMPILER_DIR=C:\HIGHTEC\toolchains\tricore\v4.6.6.1
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=C:\DEV\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=C:\DEV\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING


:SETTING_DESHETS
echo Username: %USERNAME%
echo Used settings: SETTING_DESHETS
set INSTALLED_COMPILER_DIR=D:\NoBackup\Dev\HighTec\toolchains\tricore\v4.6.3.0
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=C:\DEV\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=C:\DEV\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING

:SETTING_CI_SERVER
echo Username: %USERNAME%
echo Used settings: SETTING_CI_SERVER
set INSTALLED_COMPILER_DIR=D:\DEV\HIGHTEC\toolchains\tricore\v4.6.3.0
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=D:\NoBackup\DEV\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=D:\NoBackup\DEV\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING

:SETTING_NAGASHREE_KASHYAP
echo Username: %USERNAME%
echo Used settings: SETTING_NAGASHREE_KASHYAP
set INSTALLED_COMPILER_DIR=D:\NoBackup\DEV\HIGHTEC\toolchains\tricore\v4.6.3.0
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=D:\NoBackup\DEV\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=D:\NoBackup\DEV\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING

:SETTING_SK
echo Username: %USERNAME%
echo Used settings: SETTING_SK
set INSTALLED_COMPILER_DIR=D:\NoBackup\Dev\HIGHTEC\toolchains\tricore\v4.6.3.0
set RLM_LICENSE=ES-DESO-SR010.delta.corp@5053
set ROOT_DIR=..
set UNDERSTAND_C_PATH_32_WIN=D:\NoBackup\Dev\SciTools\bin\pc-win32
set UNDERSTAND_C_PATH_64_WIN=D:\NoBackup\Dev\SciTools\bin\pc-win64
set PCLINT_DIR=V:\
GOTO END_USER_SETTING

:END_USER_SETTING

rem ****************************************************************************
rem * DO NOT EDIT ANYTHING BELOW THIS
rem ****************************************************************************
set MAKESUPPORT_DIR=%ROOT_DIR%\70_Tools\50_MakeSupport\UnixTools
set COMPILER_DIR=%ROOT_DIR%\70_Tools\41_Compiler
set UNDERSTAND_C_DIR=%ROOT_DIR%\70_Tools\42_Understand_C

if "%MAKESUPPORT_DIR% "==" "   goto ErrorNotSet
if not exist "%MAKESUPPORT_DIR%" goto ErrorWrongPath

if "%INSTALLED_COMPILER_DIR% "==" "   goto ErrorNotSet
if not exist "%INSTALLED_COMPILER_DIR%" goto ErrorWrongPath

if exist "%COMPILER_DIR%" (
  rmdir /q %COMPILER_DIR%
)
mklink /J %COMPILER_DIR% %INSTALLED_COMPILER_DIR%


if exist "%UNDERSTAND_C_PATH_32_WIN%" (
  set INSTALLED_UNDERSTAND_C_DIR=%UNDERSTAND_C_PATH_32_WIN%
  goto link_Understand_C
) else (
  if exist "%UNDERSTAND_C_PATH_64_WIN%" (
    set INSTALLED_UNDERSTAND_C_DIR=%UNDERSTAND_C_PATH_64_WIN%
    goto link_Understand_C
  ) else (
    echo Create dummy folder!
    if not exist "%UNDERSTAND_C_DIR%" MKDIR %UNDERSTAND_C_DIR%
    goto end_Understand_C
  )
)

:link_Understand_C
if exist "%UNDERSTAND_C_DIR%" goto end_Understand_C
mklink /J %UNDERSTAND_C_DIR% %INSTALLED_UNDERSTAND_C_DIR%
:end_Understand_C

if "%1" == "understand_c" (
  if not "S:\20_Make"=="%CD%" (
    echo.
    echo Excecute the understand_c target only from S drive!
    goto End
  )
)

set str1=%1
set lint_output=
if not x%str1:.c.lint=%==x%str1% (
  FOR /F "tokens=*" %%A IN ('echo %1 ^| %MAKESUPPORT_DIR%\sed "s/\(.*\)\.c\.lint/\1\.lint/g"') DO SET Variable=%%A
  set lint_output=%MAKESUPPORT_DIR%\cat pclint\!Variable!
) else if not x%str1:.c.o=%==x%str1% (
  FOR /F "tokens=*" %%A IN ('echo %1 ^| %MAKESUPPORT_DIR%\sed "s/\(.*\)\.c\.o/\1\.o/g"') DO SET Variable=%%A
) else (
  set Variable=%1
)
goto SetPath

:NoArgument
set Variable=

:SetPath
set PATH_OLD=%PATH%
set PATH=%MAKESUPPORT_DIR%;%PATH%

set CYGWIN=nodosfilewarning

if exist "bin\Renault5DH_LvCtrl.elf" (
 del bin\Renault5DH_LvCtrl.elf
)

if exist "bin\Renault5DH_LvCtrl.hex" (
 del bin\Renault5DH_LvCtrl.hex
)

if exist "bin\Renault5DH_LvCtrl.map" (
 del bin\Renault5DH_LvCtrl.map
)

%MAKESUPPORT_DIR%\make --jobs=8 !Variable! %2 %3 %4 %5 %6 %7
!lint_output!


set PATH=%PATH_OLD%
set PATH_OLD=

goto End

:ErrorNotSet
echo ***************************************************************************
echo Error: Variable is not set!
echo        Please correct setting in this batch file and try again!
echo ***************************************************************************
goto End

:ErrorWrongPath
echo ***************************************************************************
echo Error: Path does not exist
echo        Please correct setting in this batch file and try again!
echo ***************************************************************************
goto End

:End
set MAKESUPPORT_DIR=
