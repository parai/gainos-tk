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