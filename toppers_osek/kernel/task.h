/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
 * 
 *  Copyright (C) 2013 by Fan Wang(parai), China
 * 
 * The above copyright holders grant permission gratis to use,
 * duplicate, modify, or redistribute (hereafter called use) this
 * software (including the one made by modifying this software),
 * provided that the following four conditions (1) through (4) are
 * satisfied.
 * 
 * (1) When this software is used in the form of source code, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be retained in the source code without modification.
 *
 * (2) When this software is redistributed in the forms usable for the
 *    development of other software, such as in library form, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be shown without modification in the document provided
 *    with the redistributed software, such as the user manual.
 *
 * (3) When this software is redistributed in the forms unusable for the
 *    development of other software, such as the case when the software
 *    is embedded in a piece of equipment, either of the following two
 *    conditions must be satisfied:
 *
 *  (a) The above copyright notice, this use conditions, and the
 *      disclaimer shown below must be shown without modification in
 *      the document provided with the redistributed software, such as
 *      the user manual.
 *
 *  (b) How the software is to be redistributed must be reported to the
 *      TOPPERS Project according to the procedure described
 *      separately.
 *
 * (4) The above copyright holders and the TOPPERS Project are exempt
 *    from responsibility for any type of damage directly or indirectly
 *    caused from the use of this software and are indemnified by any
 *    users or end users of this software from any and all causes of
 *    action whatsoever.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 * THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 * TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 * INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

/*
 *	Task
 */

#ifndef _TASK_H_
#define _TASK_H_

/*
 *  Task ID macro
 */
#define TSKID_NULL		((TaskType) UINT8_INVALID)	/* invalid ID */

/*
 *  task state, tcb_tstat
 */
#define TS_RUNNABLE		READY				/* ready state */
#define TS_DORMANT		SUSPENDED			/* suspended state */
#define TS_WAITING		WAITING				/* waiting state */

/*
 *  os_cfg.c, static configured information for tasks
 */
extern const UINT8	tnum_task;		/* number of the (basic & extend) task has been configured */
extern const UINT8	tnum_exttask;		/* number of the extend task has been configured */
extern const Priority	tinib_inipri[];		/* task init priority */
extern const Priority	tinib_exepri[];		/* task priority when start to execute */
extern const UINT8		tinib_maxact[];		/* task max activate count */
extern const AppModeType tinib_autoact[];	/* task autostart mode */
extern const FP			tinib_task[];		/* task entery */
extern const VP			tinib_stk[];		/* task stack buffer entry */
extern const UINT16		tinib_stksz[];		/* task stack buffer size */

/*
 *  os_cfg.c
 *
 *  used to manage tasks < tasks queue, state, proority, activate count >
 */
extern TaskType			tcb_next[];			/* task linker,indicate the next task in the queue */
extern UINT8			tcb_tstat[];		/* task state */
extern Priority			tcb_curpri[];		/* task current priority */
extern UINT8			tcb_actcnt[];		/* task current activate count */
extern EventMaskType	tcb_curevt[];		/* task current event has been set */
extern EventMaskType	tcb_waievt[];		/* task wait event */
extern ResourceType		tcb_lastres[];		/* task acquired resource recently */

/*
 *  help the scheduler to remember the current task in running state
 *
 *  when it is TKSID_NULL, no task is in ready state
 */
extern TaskType			runtsk;

/*
 *  help the scheduler to remember the next highest ready task  
 */
extern TaskType			schedtsk;

/*
 *  help the scheduler to remember the next high priority
 */
extern Priority			nextpri;

/*
 *  initialize tasks
 */
extern void	task_initialize(void);

/*
 *  activate a task
 *  activate the task tskid,set its pre-running enviroment.
 *  and if the tskid has the highest priority, this API will
 *  return ture, so a dispatch should be done, else return false
 */
extern BOOL	make_active(TaskType tskid);

/*
 *  help to make the tskid runnable
 *
 *  this API will put the tskid on tskid's priority queue if the tskid
 *  has a priority lower than schedtsk's, and if the tskid has higher 
 *  priority than nextpri, the nextpri's value will be replaced by tskid's
 *  priority.
 *  Else,if the schedtsk is NULL or has lower priority than tskid,then
 *  the schedtsk will be put to the its ready queue and update nextpri,
 *  and the tskid will be the next schedtsk, the API then return TRUE to
 *  indicate that a dispatch should be done.
 */
extern BOOL	make_runnable(TaskType tskid);

/*
 *  search a schedtsk
 *
 *  this API will search the the schedtsk by get the first task on the
 *  queue of nextpri if the ready_primap is not NULL(all is ZERO),and then
 *  will update the nextpri by means of bitmap_search if the queue of 
 *  nextpri becomes empty.
 *  if when this API was called and ready_primap is arleady 0,then TSKID_NULL
 *  will just be returned.
 */
extern void	search_schedtsk(void);

/*
 *  preempt current running task
 *
 *  When called,the runtsk which also must be the schedtsk  will be put at 
 *  the head of its ready queue and set its bitmap priority.
 *  And followed preempt() should be a dispatch().
 */
extern void	preempt(void);

#endif /* _TASK_H_ */
