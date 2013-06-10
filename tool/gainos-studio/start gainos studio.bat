@echo off
REM Author:parai
REM Start the gainos-tk studio with the default "gainoscfg.arxml" 
echo ============================================================
echo =             gainos-studio                                =
echo =  Copyright 2012, Fan Wang(Parai). All rights reserved.   =
echo =  Email:parai@foxmail.com                                 =
echo =  URL:   https://github.com/parai/gainos-tk               =
echo =         http://hi.baidu.com/parai                        =  
echo ============================================================
if exist ../../config/gainoscfg.arxml (python main.py --arxml ../../config/gainoscfg.arxml) else (python main.py)
pause
