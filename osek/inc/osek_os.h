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
#ifndef _OSEK_OS_H_
#define _OSEK_OS_H_
/* ============================ INCLUDEs ========================================== */
#include "Std_Types.h"
#include "Os.h"

/* ============================ MACROs   ========================================== */
#define BITMAPSZ	( sizeof(UINT) * 8 )
#define NUM_BITMAP	( ((cfgOSEK_MAX_PRIO+1) + BITMAPSZ - 1) / BITMAPSZ )
#define NUM_PRI     (cfgOSEK_MAX_PRIO+1)
//tkernel priority mechanism adapter to osek os priority
//the 0 is the lowest priority
#define PRIORITY(__priority) (cfgOSEK_MAX_PRIO - (__priority) )

/* Wait factor tskwait */
#define TTW_SLP		    0x00000001UL             /* Wait caused by wakeup wait */
#define TTW_DLY		    0x00000002UL             /* Wait caused by task delay */
#define TTW_SEM		    0x00000004UL             /* Semaphore wait */
#define TTW_FLG		    0x00000008UL             /* Event flag wait */
#define TTW_MBX		    0x00000040UL             /* Mail box wait */
#define TTW_MTX		    0x00000080UL             /* Mutex wait */
#define TTW_SMBF	    0x00000100UL             /* Message buffer send wait */
#define TTW_RMBF	    0x00000200UL             /* Message buffer receive wait */
#define TTW_CAL		    0x00000400UL             /* Rendezvous call wait */
#define TTW_ACP		    0x00000800UL             /* Rendezvous accept wait */
#define TTW_RDV		    0x00001000UL             /* Rendezvous end wait */
#define TTW_MPF		    0x00002000UL             /* Fixed size memory pool wait */
#define TTW_MPL		    0x00004000UL             /* Variable size memory pool wait */

#define DeclareTask(TaskName)  TaskType TaskName
#if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF)
#define GenTaskStack(TaskName)  static uint32 TaskStack##TaskName[TaskName##StkSz/4]
/* Task Generate information */
//here runpri is special, it's the priority when task start to run
//so by change the value of runpri, it's easy to support the internal resourse
//but now not supported by gainos-studio,so sorry
//-- do it by hand
//for example:Internal resource 1<vInRes1> is shared by task 1,2,3
//and task 1,2,3 each has initial priority 15, 9 ,7
//so you can config vInRes1 ceiling priority to 6, and change each of task 1,2,3's
//runpri from initial priority to 6.
//So that task 1,2,3 now can share vInRes1 safely.
//and also it's easy to change runprio to OS_HIGHEST_PRIORITY to make a task
//non-preemtable.
//by default,runprio is equal to task initial priority<itskpri> 
#define GenTaskInfo(TaskName,Attribute,flgid,runpri) \
    {                                                                   \
        /* tskatr */   Attribute,                                       \
            /* task */     TaskMain##TaskName,                          \
            /* itskpri */  TaskName##Pri,                               \
            /* sstksz */   TaskName##StkSz,                             \
            /* isstack */  &TaskStack##TaskName[TaskName##StkSz/4-1],   \
            /* flgid */  flgid,                                         \
            /* maxact */  TaskName##MaxAct,                             \
            /* runpri */ runpri                                         \
            }
#else
#define GenTaskStack(TaskName)
 /* Task Generate information */
#define GenTaskInfo(TaskName,Attribute,flgid,runpri) \
    {                                                                   \
        /* tskatr */   Attribute,                                       \
            /* task */     TaskMain##TaskName,                          \
            /* itskpri */  TaskName##Pri,                               \
            /* sstksz */   TaskName##StkSz,                             \
            /* isstack */  NULL,                                        \
            /* flgid */  flgid,                                         \
            /* maxact */  TaskName##MaxAct,                             \
            /* runpri */ runpri                                         \
            }
#endif  /* cfgOS_SHARE_SYSTEM_STACK */
#define GenAlarmInfo(AlarmName,Owner)           \
    {                                           \
        /* owner */ Owner,                 \
        /* almhdr */ AlarmMain##AlarmName,   \
        /* time */ AlarmName##_AutoStartTime,   \
        /* cycle */ AlarmName##_AutoCycleTime,   \
        /* mode */ AlarmName##Mode   \
    }

#define GenAlarmBaseInfo(MaxAllowedValue,TicksPerBase,MinCycle) \
    {                                                           \
        MaxAllowedValue,                                        \
            TicksPerBase,                                       \
            MinCycle                                            \
            }

/* ============================ TYPEs FOR QUEUE   ========================================== */
/*
 * Double-link queue (ring)
 */
typedef struct queue {
	struct queue	*next;
	struct queue	*prev;
} QUEUE;

/* ============================ TYPEs FOR TASK ========================================= */
/*
 * Internal expression of task state
 *	Can check with 'state & TS_WAIT' whether the task is in the wait state.
 *	Can check with 'state & TS_SUSPEND' whether the task is in the forced
 *	wait state.
 */
typedef enum {
	TS_NONEXIST	= 0,	/* Unregistered state */
	TS_READY	= 1,	/* RUN or READY state */
	TS_WAIT		= 2,	/* WAIT state */
	TS_SUSPEND	= 4,	/* SUSPEND state */
	TS_WAITSUS	= 6,	/* Both WAIT and SUSPEND state */
	TS_DORMANT	= 8	    /* DORMANT state */
} TSTAT;

/*
 * Definition of wait specification structure
 */
typedef struct wait_spec_block {
	UW	                tskwait;                 /* Wait factor */
    void	(*chg_pri_hook)(/* TCB* */ VP, INT);	/* Process at task priority
                   change */
    void	(*rel_wai_hook)(/* TCB* */ VP);		/* Process at task wait
                   release */
}WSPEC;

/*
 * Definition of timer event block
 */
typedef struct timer_event_block {
	QUEUE	            queue;		             /* Timer event queue */
	LSYSTIM	            time;		             /* Event time */
	CBACK	            callback;	             /* Callback function */
	VP	                arg;		             /* Argument to be sent to callback func*/
} TMEB;

/*
 * Task gerneration information
 */
typedef struct t_gtsk {
	ATR 	tskatr;		/* Task attribute */
	FP      task;		/* Task startup address */
	PRI	    itskpri;	/* Priority at task startup */
	UINT	stksz;		/* User stack size (byte) */
	VP	    isstack;	/* User stack top pointer */
    ID      flgid;      /* Event Id occupied by task */
    UINT    maxact;     /* Task maxium activate count */
    PRI     runpri;     /* Task priority When it Start To Running */
} T_GTSK;

typedef struct task_control_block{
    QUEUE	    tskque;		/* Task queue */
    CTXB     	tskctxb;	/* Task context block */
    //{{    Yes, the 6 var help the os run fast by a more usage of RAM
    TaskType    tskid;      /* Task ID */
    FP          task;       /* Task Entry */
    #if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF)
    VP          isstack;    /* Init Task Stack Top Pointer*/
    UINT		stksz;		/* User stack size (byte) */
    #endif
    ATR 	    tskatr;		/* Task attribute */
    PRI         runpri;     /* Task priority When it Start To Running */
    //}}
    UINT        actcnt;     /* Task Activate Count */
	PRI	        priority;	/* Current priority */
//	BOOL	    klockwait:1;	/* TRUE at wait kernel lock */
//	BOOL     	klocked:1;	    /* TRUE at hold kernel lock */
	UB /*TSTAT*/	state;  	/* Task state (Int. expression) */
#if(cfgOS_TK_EXTEND == STD_ON)
	WSPEC *	        wspec;	  /* Wait specification */
	StatusType *    wercd;    /* Wait error code set area */
	ID	            wid;	  /* Wait object ID */
	UINT	        wupcnt;   /* Number of wakeup requests queuing */
	TMEB	        wtmeb;	  /* Wait timer event block */
#endif
	QUEUE resque;	/* queue to hold resources */
}TCB;

/*
 * Definition of ready queue structure
 *	In the ready queue, the task queue 'tskque' is provided per priority.
 *	The task TCB is registered onto queue with the applicable priority.
 *	For effective ready queue search, the bitmap area 'bitmap' is provided
 *	to indicate whether there are tasks in task queue per priority.
 *
 *	Also, to search a task at the highest priority in the ready queue
 *    	effectively, put the highest task priority in the 'top_priority' field.
 *	If the ready queue is empty, set the value in this field to NUM_PRI.
 *	In this case, to return '0' with refering 'tskque[top_priority]',
 *      there is 'null' field which is always '0'.
 *
 *	Multiple READY tasks with kernel lock do not exist at the same time.
 */
typedef	struct ready_queue {
	PRI	top_priority;		/* Highest priority in ready queue */
	QUEUE	tskque[NUM_PRI];	/* Task queue per priority */
	TCB	*   null;			/* When the ready queue is empty, */
	UINT	bitmap[NUM_BITMAP];	/* Bitmap area per priority */
//	TCB	*klocktsk;	/* READY task with kernel lock */
} RDYQUE;

/* ============================ TYPEs FOR ALARM   =============================== */
typedef struct counter_control_block
{
    QUEUE       almque;
    TickType    curvalue; /* current value of the Counter */
}CCB;

typedef struct alarm_generate_info
{
    CounterType owner; /* Alarm Owner -> Counter */
    FP          almhdr;  /* Alarm handler */
    TickType    time;
    TickType    cycle;
    AppModeType mode;
}T_GALM;

/* Alarm Control Block */
typedef struct AlmCtrlBlk
{
    QUEUE           almque;
    AlarmType       almid;
    TickType        time; /* The Time It will expire */
    TickType        cycle;
}ALMCB;

/* ============================ TYPEs FOR RESOURCE    ========================================== */
/*
 * Resource control block
 */
typedef struct resource_control_block {
	QUEUE	resque;	        /* Resource queue in task list*/
	PRI tskpri;     /* old priority of the task occupied this resource */
}RESCB;
/* ============================ TYPEs FOR EVENT    ========================================== */
/*
 * Event flag control block
 */
typedef struct event_control_block {
	EventMaskType	            flgptn;		    /* Event flag current pattern */
    EventMaskType               waipth;         /* Event flag wait pattern */
} FLGCB;
#endif /* _OSEK_OS_H_ */

