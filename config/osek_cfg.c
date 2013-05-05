#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"
#include "knl_alarm.h"

GenTaskStack(vTask1,512);
GenTaskStack(vTask2,512);
EXPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM]=
{
     GenTaskInfo(vTask1,0,512,BCC1|AUTOSTART),
     GenTaskInfo(vTask2,1,512,BCC1|AUTOSTART)
};

EXPORT const T_GALM knl_galm_table[cfgOSEK_ALARM_NUM]=
{
    GenAlarmInfo(vAlarm1,vCounter1),
    GenAlarmInfo(vAlarm2,vCounter1)
};

TASK(vTask1)
{
    (void)TerminateTask();
}

TASK(vTask2)
{
    (void)ChainTask(ID_vTask1);
}

ALARM(vAlarm1)
{
}

ALARM(vAlarm2)
{
}