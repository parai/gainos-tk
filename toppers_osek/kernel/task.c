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
 *	includes
 */

#include "osek_kernel.h"
#include "check.h"
#include "task.h"
#include "resource.h"

/*
 *  task ready queue management APIs
 */
Inline void	ready_insert_first(Priority pri, TaskType tskid);
Inline void	ready_insert_last(Priority pri, TaskType tskid);
Inline TaskType	ready_delete_first(Priority pri);
Inline Priority	bitmap_search(UINT16 bitmap);

/*
 *  task ready queue list
 *
 *  each priority can have multiply tasks in ready state( note that runtsk 
 *  is noot on the queue as it is in running state, also the schedtsk is not 
 *  on the ready queue).
 *  ready_queue_first[pri] help to remember the first/head task on the queue 
 *  of pri,and the ready_queue_last[pri] help to remember the last/tail task
 *  on the queue of pri.Note that when ready_queue_first[pri] = TSKID_NULL, 
 *  it means that no task is in ready state with priority <pri>.
 */
static TaskType ready_queue_first[TNUM_PRIORITY];
static TaskType ready_queue_last[TNUM_PRIORITY];

/*
 *  insert the task tskid at the head of the ready queue of pri
 */
Inline void
ready_insert_first(Priority pri, TaskType tskid)
{
	TaskType	first;

	assert(pri <= TPRI_MAXTASK);
	first = ready_queue_first[pri];
	ready_queue_first[pri] = tskid;
	tcb_next[tskid] = first;
	if (first == TSKID_NULL) {
		ready_queue_last[pri] = tskid;
	}
}

/*
 *  insert the tskid at the tail of the ready queue of pri
 */
Inline void
ready_insert_last(Priority pri, TaskType tskid)
{
	assert(pri <= TPRI_MAXTASK);
	if (ready_queue_first[pri] == TSKID_NULL) {
		ready_queue_first[pri] = tskid;
	}
	else {
		tcb_next[ready_queue_last[pri]] = tskid;
	}
	ready_queue_last[pri] = tskid;
	tcb_next[tskid] = TSKID_NULL;
}

/*
 *  remove the head tsk from the ready queue of pri,and return it.
 */
Inline TaskType
ready_delete_first(Priority pri)
{
	TaskType	first;

	first = ready_queue_first[pri];
	assert(first != TSKID_NULL);
	ready_queue_first[pri] = tcb_next[first];
	return(first);
}

/*
 *  task ready priority map
 *
 *  each bit of bitmap corresponds to a special priority <pri>. if at least
 *  one task with pri is in ready state, the <pri> bit in bitmap should be set.
 *  Only when no any task with <pri> is in ready state, the <pri> bit in bitmap
 *  should be cleared, which means no tasks is in the ready state on the queue
 *  of <pri>.
 *  For toppers_osek,this bit map is 16 bit long,so only 16 prioritys was allowed
 *  from 0 to 15.
 *  by default toppers_osek assume that the host cpu is big endianness mode.
 *  Also the default PRIMAP implement is ok for little endianness mode cpu,as it 
 *  just has 16 bit.
 *  if you want to make it more rigth,you can change the define as belows if the 
 *  host cpu is in little endianness mode by the way add the define in your compiler
 *  pre-processor.
 *	#define PRIMAP_BIT(pri)	(0x8000u >> (pri))
 *	#define	bitmap_search(bitmap) (16 - ffs(bitmap))
 *  And also you can re-implement the bitmap mechanism to make better osek os.
 *  Such as use the ucOS ready map
 */
#ifndef PRIMAP_BIT
#define	PRIMAP_BIT(pri)		(1u << (pri))
#endif /* PRIMAP_BIT */

#ifndef CPU_BITMAP_SEARCH

Inline Priority
bitmap_search(UINT16 bitmap)
{
	static const UINT8 search_table[] = { 0, 1, 1, 2, 2, 2, 2,
						3, 3, 3, 3, 3, 3, 3, 3 };
	Priority	pri = 0;

	assert((bitmap & ((UINT16) 0xffffu)) != 0);
	if ((bitmap & ((UINT16) 0xff00u)) != 0) {
		bitmap >>= 8;
		pri += 8;
	}
	if ((bitmap & ((UINT16) 0xf0)) != 0) {
		bitmap >>= 4;
		pri += 4;
	}
	return(pri + (search_table[(bitmap & ((UINT16) 0x0f)) - 1]));
}

#endif /* CPU_BITMAP_SEARCH */

/*
 * current running task 
 */
TaskType	runtsk;

/*
 * the next should be scheduled task which has higher or equal priority 
 */
TaskType	schedtsk;

/*
 *  the next should be scheduled task's priority,may lower than schedtsk's pri
 */
Priority	nextpri;

/*
 *  ready priority map
 *
 *  each bit of it correspond to a priority which has task(s) in runnable state
 */
static UINT16	ready_primap;

/*
 *  initialize task related 
 */
void
task_initialize(void)
{
	Priority	pri;
	TaskType	tskid;

	runtsk = TSKID_NULL;
	schedtsk = TSKID_NULL;
	for (pri = 0; pri < TNUM_PRIORITY; pri++) {
		ready_queue_first[pri] = TSKID_NULL;
	}
	nextpri = TPRI_MINTASK;
	ready_primap = 0u;

	for (tskid = 0; tskid < tnum_task; tskid++) {
		tcb_actcnt[tskid] = 0;
		if ((tinib_autoact[tskid] & appmode) != APPMODE_NONE) {
			(void)make_active(tskid);
			tcb_tstat[tskid] = TS_RUNNABLE;
		}
		else {
			tcb_tstat[tskid] = TS_DORMANT;
		}
	}
}

/*
 *  make a task active, prepare to run
 *
 *  TerminateTask and ChainTask may call make_active only when task actcnt is not zero
 *  set up task's pre-running enviroment
 */
BOOL
make_active(TaskType tskid)
{
	tcb_curpri[tskid] = tinib_inipri[tskid];
	if (tskid < tnum_exttask) {
		tcb_curevt[tskid] = EVTMASK_NONE;
		tcb_waievt[tskid] = EVTMASK_NONE;
	}
	tcb_lastres[tskid] = RESID_NULL;
	activate_context(tskid);
	return(make_runnable(tskid));
}

/*
 *  make the task runnable
 */
BOOL
make_runnable(TaskType tskid)
{
	Priority	pri, schedpri;

	tcb_tstat[tskid] = TS_RUNNABLE;
	if (schedtsk != TSKID_NULL) {
		pri = tcb_curpri[tskid];
		schedpri = tcb_curpri[schedtsk];
		if (pri <= schedpri) {
			/*
			 *  schedtsk has higher priority than tskid, so just 
			 *  put the tskid at the tail of the ready queue of pri
			 */
			ready_insert_last(pri, tskid);
			ready_primap |= PRIMAP_BIT(pri);
			if (pri > nextpri) {
				nextpri = pri;
			}
			return(FALSE);
		}
		/*
		 *  tskid has higher priority than schedtsk, so put 
		 *  the schedtsk at the head of the ready queue of schedpri
         *  because the schedtsk will be preempted by tskid
		 */
		ready_insert_first(schedpri, schedtsk);
		ready_primap |= PRIMAP_BIT(schedpri);
		nextpri = schedpri;
	}
	schedtsk = tskid;
	return(TRUE);
}

/*
 *  search task should be scheduled next
 */
void
search_schedtsk(void)
{
	if (ready_primap == ((UINT16) 0)) {
		schedtsk = TSKID_NULL;
	}
	else {
		schedtsk = ready_delete_first(nextpri);
		if (ready_queue_first[nextpri] == TSKID_NULL) {
			ready_primap &= ~PRIMAP_BIT(nextpri);
			nextpri = (ready_primap == ((UINT16) 0)) ?
						TPRI_MINTASK : bitmap_search(ready_primap);
		}
	}
}

/*
 *  preempt current running task<runtsk> which is also the schedtsk
 */
void
preempt(void)
{
	assert(runtsk == schedtsk);
	ready_insert_first(tcb_curpri[schedtsk], schedtsk);
	ready_primap |= PRIMAP_BIT(tcb_curpri[schedtsk]);
	search_schedtsk();
}
