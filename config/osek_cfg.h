#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
/* =====================  MISC  ========================== */
#define cfgOS_STATUS_LEVEL OS_STATUS_EXTEND
#define cfgTMP_STACK_SZ  512
#define CPU_FREQUENCY        32000000 /* HZ */
#define OSC_FREQUENCY         8000000 /* HZ */

/* =====================  TASK  ========================== */
#define cfgOSEK_MAX_PRIO  32
#define cfgOSEK_TASK_NUM  2
#define ID_vTask1  0
#define ID_vTask2  1
IMPORT TASK(vTask1);
IMPORT TASK(vTask2);

/* =====================  EVENT ========================== */
#define cfgOSEK_EVENTFLAG_NUM 0

/* =====================  ALARM ========================== */
#define cfgOSEK_COUNTER_NUM 1
#define ID_vCounter1  0
#define cfgOSEK_ALARM_NUM 2
#define ID_vAlarm1 0
#define ID_vAlarm2 1
IMPORT ALARM(vAlarm1);
IMPORT ALARM(vAlarm2);

/*  ====================  RESOURCE ======================= */
#define cfgOSEK_RESOURCE_NUM 1

/*  ====================  HOOKs    ======================= */
#define cfgOS_SHUT_DOWN_HOOK 0
#define cfgOS_START_UP_HOOK  0
#endif /* _OSEK_CFG_H_ */

