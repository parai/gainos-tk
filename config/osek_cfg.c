#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"
#include "knl_alarm.h"
#include <stdio.h>
GenTaskStack(vTask1,512);
GenTaskStack(vTask2,512);
GenTaskStack(vTaskIdle,512);
EXPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM]=
{
     GenTaskInfo(vTask1,0,512,BCC1|AUTOSTART),
     GenTaskInfo(vTask2,1,512,BCC1|AUTOSTART),
     GenTaskInfo(vTaskIdle,2,512,BCC1|AUTOSTART)
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