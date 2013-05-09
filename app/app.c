#include "Os.h"
#include <stdio.h>

TASK(vTask1)
{
    static int i = 0;
    if(0 == i)
    {
        i++;
        //(void)SetRelAlarm(ID_vAlarm1,500,1000);
        //(void)SetAbsAlarm(ID_vAlarm2,103,1000);
    }
    (void)printf("vTask1 is running.\r\n");
    //(void)WaitEvent(0x00000001u);
    //(void)ClearEvent(0x00000001u);
#if 1
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
    //(void)GetResource(ID_vResource1);
    //void)SetEvent(ID_vTask1,0x00000001u);
    //(void)ReleaseResource(ID_vResource1);
    for(;;)
    {
        WakeUpTask(ID_vTask1);
        SleepTask(1000);
        printf("vTask2 is running.\r\n");
    }
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