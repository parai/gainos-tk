/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine China
 * Open Source Society; either version 1 of the License, or (at developer option)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the U-License for more details.
 * Developer should have received a copy of the U-Licensealong with this program;
 * if not, download from www.tecoss.org(the web page of the T-Engine China Open
 * Source Society).
 *
 * GaInOS-TK is a static configured RTOS, which conformed to OSEK OS 2.2.3 Specification
 * and it is based on uTenux(http://www.uloong.cc).
 *
 * Email: parai@foxmail.com
 * Sourrce Open At: https://github.com/parai/gainos-tk/
 */
#include "Os.h"
#include <stdio.h>

TASK(vTask1)
{
    static int i = 0;
    if(0 == i)
    {
        i++;
        (void)SetRelAlarm(ID_vAlarm1,500,1000);
        (void)SetAbsAlarm(ID_vAlarm2,103,1000);
    }
    (void)printf("vTask1 is running.\r\n");
    (void)WaitEvent(0x00000001u);
    (void)ClearEvent(0x00000001u);
#if 0
    for(;;)
    {
        SleepTask(5000);
        printf("vTask1 sleep 5000 Ticks.\r\n");
    }
#endif    
    (void)TerminateTask();
}

TASK(vTask2)
{
    ActivateTask(ID_vTask1);
    (void)printf("vTask2 is running.\r\n");
    (void)GetResource(ID_vResource1);
    (void)SetEvent(ID_vTask1,0x00000001u);
    (void)ReleaseResource(ID_vResource1);
    #if 0
    for(;;)
    {
        WakeUpTask(ID_vTask1);
        SleepTask(1000);
        printf("vTask2 is running.\r\n");
    }
    #endif
    (void)TerminateTask();
}

TASK(vTaskIdle)
{
    for(;;);
}

ALARM(vAlarm1)
{
    (void)ActivateTask(ID_vTask1);
}

ALARM(vAlarm2)
{
    (void)ActivateTask(ID_vTask2);
}