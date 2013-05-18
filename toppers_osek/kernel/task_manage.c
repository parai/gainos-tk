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
 *	タスク管理機能
 */

#include "osek_kernel.h"
#include "check.h"
#include "task.h"
#include "resource.h"

/*
 *  タスクの起動
 */
StatusType
ActivateTask(TaskType tskid)
{
	StatusType	ercd = E_OK;

	LOG_ACTTSK_ENTER(tskid);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_TSKID(tskid);

	lock_cpu();
	if (tcb_tstat[tskid] == TS_DORMANT) {
		if ((make_active(tskid)) && (callevel == TCL_TASK)) {
			dispatch();
		}
	}
	else if (tcb_actcnt[tskid] < tinib_maxact[tskid]) {
		tcb_actcnt[tskid] += 1;
	}
	else {
		ercd = E_OS_LIMIT;
		goto d_error_exit;
	}
  exit:
	unlock_cpu();
	LOG_ACTTSK_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.tskid = tskid;
	call_errorhook(ercd, OSServiceId_ActivateTask);
	goto exit;
}

/*
 *  自タスクの終了
 */
StatusType
TerminateTask(void)
{
	StatusType	ercd = E_OK;

	LOG_TERTSK_ENTER();
	CHECK_CALLEVEL(TCL_TASK);
	CHECK_RESOURCE(tcb_lastres[runtsk] == RESID_NULL);

	lock_cpu();
	/*
	 *  内部リソースの解放は優先度を下げるだけなので，ここでは
	 *  何もしなくてよい．
	 */
	tcb_tstat[runtsk] = TS_DORMANT;
	search_schedtsk();
	if (tcb_actcnt[runtsk] > 0) {
		tcb_actcnt[runtsk] -= 1;
		(void)make_active(runtsk);
	}
	exit_and_dispatch();
	/* ここには戻ってこない */

  error_exit:
	lock_cpu();
	call_errorhook(ercd, OSServiceId_TerminateTask);
	unlock_cpu();
	LOG_TERTSK_LEAVE(ercd);
	return(ercd);
}

/*
 *  自タスクの終了とタスクの起動
 */
StatusType
ChainTask(TaskType tskid)
{
	/*
	 *  ここでの ercd の初期化は本来は不要であるが，コンパイラの警
	 *  告メッセージを避けるために初期化している．
	 */
	StatusType	ercd = E_OK;

	LOG_CHNTSK_ENTER(tskid);
	CHECK_CALLEVEL(TCL_TASK);
	CHECK_RESOURCE(tcb_lastres[runtsk] == RESID_NULL);
	CHECK_TSKID(tskid);

	lock_cpu();
	if (tskid == runtsk) {
		// tcb_tstat[runtsk] = TS_DORMANT;
		search_schedtsk();
		(void)make_active(runtsk);
	}
	else {
		/*
		 *  エラー時に副作用が残らないように，エラーチェックは
		 *  タスク終了処理の前に行う必要がある．
		 */
		if ((tcb_tstat[tskid] != TS_DORMANT)
			&& (tcb_actcnt[tskid] >= tinib_maxact[tskid])) {
			ercd = E_OS_LIMIT;
			goto d_error_exit;
		}
		tcb_tstat[runtsk] = TS_DORMANT;
		search_schedtsk();
		if (tcb_actcnt[runtsk] > 0) {
			tcb_actcnt[runtsk] -= 1;
			(void)make_active(runtsk);
		}
		if (tcb_tstat[tskid] == TS_DORMANT) {
			(void)make_active(tskid);
		}
		else {
			tcb_actcnt[tskid] += 1;
		}
	}
	exit_and_dispatch();
	/* ここには戻ってこない */

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.tskid = tskid;
	call_errorhook(ercd, OSServiceId_ChainTask);
	unlock_cpu();
	LOG_CHNTSK_LEAVE(ercd);
	return(ercd);
}

/*
 *  スケジューラの呼び出し
 */
StatusType
Schedule(void)
{
	/*
	 *  ここでの ercd の初期化は本来は不要であるが，コンパイラの警
	 *  告メッセージを避けるために初期化している．
	 */
	StatusType	ercd = E_OK;

	LOG_SCHED_ENTER();
	CHECK_CALLEVEL(TCL_TASK);
	CHECK_RESOURCE(tcb_lastres[runtsk] == RESID_NULL);

	lock_cpu();
	if (tinib_inipri[runtsk] < nextpri) {
		tcb_curpri[runtsk] = tinib_inipri[runtsk];
		preempt();
		dispatch();
		tcb_curpri[runtsk] = tinib_exepri[runtsk];
	}
  exit:
	unlock_cpu();
	LOG_SCHED_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	call_errorhook(ercd, OSServiceId_Schedule);
	goto exit;
}

/*
 *  実行状態のタスクIDの参照
 */
StatusType
GetTaskID(TaskRefType p_tskid)
{
	StatusType	ercd = E_OK;

	LOG_GETTID_ENTER(p_tskid);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);

	lock_cpu();
	*p_tskid = runtsk;
	/*
	 *  本来は runtsk ではなく以下の式になるべきだが，TSKID_NULL 
	 *  と INVALID_TASK は等しいので，単に runtsk でよい．
	 *      (runtsk == TSKID_NULL) ? INVALID_TASK : runtsk
	 */
  exit:
	unlock_cpu();
	LOG_GETTID_LEAVE(ercd, *p_tskid);
	return(ercd);

  error_exit:
	lock_cpu();
	call_errorhook(ercd, OSServiceId_GetTaskID);
	goto exit;

}

/*
 *  タスク状態の参照
 */
StatusType
GetTaskState(TaskType tskid, TaskStateRefType p_state)
{
	StatusType	ercd = E_OK;

	LOG_GETTST_ENTER(tskid, p_state);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);
	CHECK_TSKID(tskid);

	lock_cpu();
	*p_state = (tskid == runtsk) ? RUNNING : tcb_tstat[tskid];
  exit:
	unlock_cpu();
	LOG_GETTST_LEAVE(ercd, *p_state);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.tskid = tskid;
	_errorhook_par2.p_state = p_state;
	call_errorhook(ercd, OSServiceId_GetTaskState);
	goto exit;
}
