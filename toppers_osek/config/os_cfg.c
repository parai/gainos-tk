#include "os_cfg.h"
#include "osek_kernel.h"
/* ============================= TASK =================================================== */
/*
 *  os_cfg.c, static configured information for tasks
 */
const UINT8	tnum_task = cfgOSEK_TASK_NUM;
const UINT8	tnum_exttask = cfgOSEK_TASK_NUM;
	
const Priority	tinib_inipri[] =
{
    7, /* vTaskInit */
    4, /* vTaskSender */ 
    5, /* vTaskReceiver */ 
    6, /* vTaskMainFunction */ 
    0  /* vTaskIdle */ 
};
const Priority	tinib_exepri[] = 
{
    7, /* vTaskInit */
    4, /* vTaskSender */ 
    5, /* vTaskReceiver */ 
    6, /* vTaskMainFunction */ 
    0  /* vTaskIdle */ 
};
const UINT8		tinib_maxact[]=
{
    3, /* vTaskInit */
    3, /* vTaskSender */ 
    3, /* vTaskReceiver */ 
    3, /* vTaskMainFunction */ 
    3  /* vTaskIdle */ 
};
const AppModeType tinib_autoact[]=
{
    OSDEFAULTAPPMODE, /* vTaskInit */
    OSDEFAULTAPPMODE+1, /* vTaskSender */ 
    OSDEFAULTAPPMODE+1, /* vTaskReceiver */ 
    OSDEFAULTAPPMODE+1, /* vTaskMainFunction */ 
    OSDEFAULTAPPMODE    /* vTaskIdle */ 
};
const FP			tinib_task[]=
{
    TASKNAME(vTaskInit),
    TASKNAME(vTaskSender),
    TASKNAME(vTaskReceiver),
    TASKNAME(vTaskMainFunction),
    TASKNAME(vTaskIdle)
};

static UINT8  vTaskInit_stk[512];
static UINT8  vTaskSender_stk[512];
static UINT8  vTaskReceiver_stk[512];
static UINT8  vTaskMainFunction_stk[512];
static UINT8  vTaskIdle_stk[512];
const VP			tinib_stk[]=
{
    vTaskInit_stk,
    vTaskSender_stk,
    vTaskReceiver_stk,
    vTaskMainFunction_stk,
    vTaskIdle_stk
};

const UINT16		tinib_stksz[]=
{
    512,
    512,
    512,
    512,
    512
};
const IPL		ipl_maxisr2 = 1;
/*
 *  os_cfg.c
 *
 *  used to manage tasks < tasks queue, state, proority, activate count >
 */
TaskType	    tcb_next[cfgOSEK_TASK_NUM];			/* task linker,indicate the next task in the queue */
UINT8			tcb_tstat[cfgOSEK_TASK_NUM];		/* task state */
Priority		tcb_curpri[cfgOSEK_TASK_NUM];		/* task current priority */
UINT8			tcb_actcnt[cfgOSEK_TASK_NUM];		/* task current activate count */
EventMaskType	tcb_curevt[cfgOSEK_TASK_NUM];		/* task current event has been set */
EventMaskType	tcb_waievt[cfgOSEK_TASK_NUM];		/* task wait event */
ResourceType	tcb_lastres[cfgOSEK_TASK_NUM];		/* task acquired resource recently */

/* ================================= ALARM COUNTER ======================================= */
/*
 *  number of ALARM and Counter
 */
const UINT8		tnum_counter = cfgOSEK_COUNTER_NUM;		/* Counter number configured */
const UINT8		tnum_alarm = cfgOSEK_ALARM_NUM;			/* Alarm number configured */

/*
 *  configured information for counter
 */
const TickType	cntinib_maxval[cfgOSEK_COUNTER_NUM] =
{
    65535
};
const TickType	cntinib_maxval2[cfgOSEK_COUNTER_NUM] =
{
    65535*2+1
};
const TickType	cntinib_tickbase[cfgOSEK_COUNTER_NUM] =
{
    1
};
const TickType	cntinib_mincyc[cfgOSEK_COUNTER_NUM] = 
{
    50
};

/*
 *  counter control block
 */
TickType			cntcb_curval[cfgOSEK_COUNTER_NUM];		/* counter current value*/
AlarmType		    cntcb_almque[cfgOSEK_COUNTER_NUM];		/* counter queue */

/*
 *  configured information for alarm
 */
const CounterType alminib_cntid[cfgOSEK_ALARM_NUM] =
{
    ID_vCounter0,   /* vAlarmSender */ 
    ID_vCounter0,   /* vAlarmReceiver */
    ID_vCounter0    /* vAlarmMainFunction */
};
const FP			 alminib_cback[cfgOSEK_ALARM_NUM] =
{
    ALARMCALLBACKNAME(vAlarmSender),
    ALARMCALLBACKNAME(vAlarmReceiver),
    ALARMCALLBACKNAME(vAlarmMainFunction),
    
};	/* alarm call back routine */
const AppModeType alminib_autosta[cfgOSEK_ALARM_NUM] =
{
    OSDEFAULTAPPMODE+1, /* vAlarmSender */ 
    OSDEFAULTAPPMODE+1, /* vAlarmReceiver */ 
    OSDEFAULTAPPMODE+1  /* vAlarmMainFunction */
};	/* alarm autostart mode */

const TickType	 alminib_almval[cfgOSEK_ALARM_NUM] =
{
    503, /* vAlarmSender */ 
    1007, /* vAlarmReceiver */ 
    1508  /* vAlarmMainFunction */
};
const TickType	 alminib_cycle[cfgOSEK_ALARM_NUM] = 
{
    500, /* vAlarmSender */ 
    500, /* vAlarmReceiver */ 
    500  /* vAlarmMainFunction */
};

/*
 *  alarm control block
 *
 *  アラームがアラームキューに挿入されていない場合，almcb_nextには
 *  そのアラームのIDが入っている（nextが自分を指している）．
 */
AlarmType		almcb_next[cfgOSEK_ALARM_NUM];		/* next alarm in queue */
AlarmType		almcb_prev[cfgOSEK_ALARM_NUM];		/* previous alarm in queue */
TickType		almcb_almval[cfgOSEK_ALARM_NUM];		/* expire time */
TickType		almcb_cycle[cfgOSEK_ALARM_NUM];		/* alarm cycle time */

/* ======================= RESOURCE =========================================== */
const UINT8		tnum_resource = cfgOSEK_RESOURCE_NUM;

const Priority	resinib_ceilpri[cfgOSEK_RESOURCE_NUM] =
{
    14,
    8
};	

/*
 *  resource control block
 *
 */
Priority			rescb_prevpri[cfgOSEK_RESOURCE_NUM];	/* previous priority of task which has acquired this res */
ResourceType		rescb_prevres[cfgOSEK_RESOURCE_NUM];

/* ============= ISR resource ============= */
const UINT8		tnum_isr2 = 0;


const Priority	isrinib_intpri[] =
{
    0
};

ResourceType		isrcb_lastres[1];


extern void	task_initialize(void);
extern void alarm_initialize(void);
extern void resource_initialize(void);
void object_initialize(void)
{
    task_initialize();
    alarm_initialize();
    resource_initialize();
}