echo off
REM
REM --------------------------------------------------------------------------------------
REM   Utility 
REM
REM   Copyright (C) 2008-2013 by Dalian uLoong Co.,Ltd. All rights reserved.
REM
REM   This program is open source software; developer can redistribute it and/or
REM   modify it under the terms of the U-License as published by the T-Engine China
REM   Open Source Society; either version 1 of the License, or (at developer option)
REM   any later Version.
REM
REM   This program is distributed in the hope that it will be useful,but WITHOUT ANY
REM   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
REM   A PARTICULAR PURPOSE.  See the U-License for more details.
REM
REM   Developer should have received a copy of the U-License along with this program;
REM   if not, download from www.tecoss.org(the web page of the T-Engine China Open
REM   Source Society).
REM
REM   CPU:        X86
REM   OS:         Window XP
REM   Version:    1.5.00
REM   Released by T-Engine China Open Source Society
REM               (http://www.tecoss.org).
REM
REM  File Name  	: tk_clrrub.bat
REM  Create Date	: 2013/3/18-2013/4/28
REM  Author		    : WangShb-Zhangzl
REM  Usage          : tk_clr
REM  Description	: Clear all rubbish files,for example .o,.d,.crf,.lib,. dep.ini etc
REM  Parameter      : none.
REM --------------------------------------------------------------------------------------
REM

echo Now clearing rubbish files...

del /s /q *.a
del /s /q *.axf
del /s /q *.bak
del /s /q *.cspy.bat
del /s /q *.crf
del /s /q *.cout
del /s /q *.d
del /s /q *.dbgdt
del /s /q *.dep
del /s /q *.dni
del /s /q *.hex
del /s /q *.i
del /s /q *.iex
del /s /q *.ini
del /s /q *.lib
del /s /q *.lnp
del /s /q *.lst
del /s /q *.map
del /s /q *.o
del /s /q *.out
del /s /q *.pbi
del /s /q *.plg
del /s /q *.sfr
del /s /q *.sim
del /s /q *.tra
del /s /q *.uvgui.*
del /s /q JLinkLog.txt
del /s /q *.pbd
del /s /q *.pbd.*
del /s /q *.__i
REM delete CW rubbish
del /s /q *.abs
del /s /q *.xpr
del /s /q *.s19
del /s /q *.pyc
del /s /q *.phy
del /s /q *.stg
del /s /q *.mot
del /s /q *.tdt
REM delete Tasking rubbish
del /s /q *.obj
del /s /q *.log
del /s /q *.mk
del /s /q *.mapxml
del /s /q *.mdf
del /s /q *.elf
del /s /q *.src
REM delete CW cmd file
del /s /q *.cmd

rm -f ./app/test.c ./app/test.h
echo Cleared successfully
echo on
pause
