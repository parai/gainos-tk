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
    printf("vTask1 is running.\r\n");
    (void)TerminateTask();
}

TASK(vTask2)
{
    printf("vTask2 is running.\r\n");
    (void)ActivateTask(ID_vTask1);
    (void)TerminateTask();
    //(void)ChainTask(ID_vTask1);
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