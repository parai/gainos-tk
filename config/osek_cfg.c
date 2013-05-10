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
#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"
#include "knl_alarm.h"
#include "knl_event.h"
#include <stdio.h>
GenTaskStack(vTask1,1024);
GenTaskStack(vTask2,1024);
GenTaskStack(vTaskIdle,1024);
EXPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM]=
{
     GenTaskInfo(vTask1,5,1024,ECC1|AUTOSTART,ID_vTask1Event),
     GenTaskInfo(vTask2,6,1024,BCC1|AUTOSTART,INVALID_EVENT),
     GenTaskInfo(vTaskIdle,cfgOSEK_MAX_PRIO,1024,BCC1|AUTOSTART,INVALID_EVENT)
};

EXPORT const AlarmBaseType knl_almbase_table[cfgOSEK_COUNTER_NUM]=
{
    GenAlarmBaseInfo(UINT_MAX/2,1,100)
};

EXPORT const T_GALM knl_galm_table[cfgOSEK_ALARM_NUM]=
{
    GenAlarmInfo(vAlarm1,vCounter1),
    GenAlarmInfo(vAlarm2,vCounter1)
};

EXPORT const PRI knl_gres_table[cfgOSEK_RESOURCE_NUM]=
{
      /* ceilpri */ 0,  /* vResource1*/
};