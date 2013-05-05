#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"

GenTaskStack(vTask1,512);
GenTaskStack(vTask2,512);
EXPORT TCB	knl_tcb_table[cfgOSEK_TASK_NUM]=
{
     GenTaskCreInfo(vTask1,0,512,BCC1|AUTOSTART),
     GenTaskCreInfo(vTask2,1,512,BCC1|AUTOSTART)
};

TASK(vTask1)
{
    TerminateTask();
}

TASK(vTask2)
{
    ChainTask(ID_vTask1);
}

ALARM(vAlarm1)
{
}

ALARM(vAlarm2)
{
}