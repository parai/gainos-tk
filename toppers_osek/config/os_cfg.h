#ifndef OS_CONFIG_H_H
#define OS_CONFIG_H_H

#include "kernel.h"

#define cfgOSEK_TASK_NUM  5
#define ID_vTaskInit 0
#define ID_vTaskSender 1
#define ID_vTaskReceiver 2
#define ID_vTaskMainFunction 3
#define ID_vTaskIdle 4

extern TASK(vTaskInit);
extern TASK(vTaskSender);
extern TASK(vTaskReceiver);
extern TASK(vTaskMainFunction);
extern TASK(vTaskIdle);

#define cfgOSEK_ALARM_NUM   3
#define cfgOSEK_COUNTER_NUM 1

#define ID_vCounter0  0

#define ID_vAlarmSender       0
#define ID_vAlarmReceiver     1
#define ID_vAlarmMainFunction 2

extern ALARMCALLBACK(vAlarmSender);
extern ALARMCALLBACK(vAlarmReceiver);
extern ALARMCALLBACK(vAlarmMainFunction);


#define cfgOSEK_RESOURCE_NUM 2
//#define RES_SCHEDULER 0   //see kernel.h
#define ID_vResourceCAN  1

//#define BASIC_STATUS

/* OSEK OS Debugh elper */
#define assert(__true)
#define LOG_STAOS_ENTER(mode) 
#define LOG_STAOS_LEAVE()
#define LOG_TERTSK_ENTER()
#define LOG_TERTSK_LEAVE(ercd)
#define LOG_STUTOS_ENTER(ercd)
#define LOG_STUTOS_LEAVE()
#define LOG_ACTTSK_ENTER(tskid)
#define LOG_ACTTSK_LEAVE(ercd)
#define LOG_SIGCNT_ENTER(cntid)
#define LOG_SIGCNT_LEAVE(ercd)
#define LOG_SETREL_ENTER(almid, incr, cycle)
#define LOG_SETREL_LEAVE(ercd)
#define LOG_SETABS_ENTER(almid, incr, cycle)
#define LOG_SETABS_LEAVE(ercd)
#define LOG_SETEVT_ENTER(tskid, mask)
#define LOG_SETEVT_LEAVE(ercd)
#define LOG_CLREVT_ENTER(mask)
#define LOG_CLREVT_LEAVE(ercd)
#define LOG_GETEVT_ENTER(tskid, p_mask)
#define LOG_GETEVT_LEAVE(ercd, mask)
#define LOG_WAIEVT_ENTER(mask)
#define LOG_WAIEVT_LEAVE(ercd)
#define LOG_GETRES_ENTER(resid)
#define LOG_GETRES_LEAVE(ercd)
#define LOG_RELRES_ENTER(resid)
#define LOG_RELRES_LEAVE(ercd)

#endif  /* OS_CONFIG_H_H */