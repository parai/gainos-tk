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
 *	イベント制御機能
 */

#include "osek_kernel.h"
#include "check.h"
#include "task.h"
#include "resource.h"

/*
 *  イベントのセット
 */
StatusType
SetEvent(TaskType tskid, EventMaskType mask)
{
	StatusType	ercd = E_OK;

	LOG_SETEVT_ENTER(tskid, mask);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_TSKID(tskid);
	CHECK_ACCESS(tskid < tnum_exttask);

	lock_cpu();
	D_CHECK_STATE(tcb_tstat[tskid] != TS_DORMANT);

	tcb_curevt[tskid] |= mask;
	if ((tcb_curevt[tskid] & tcb_waievt[tskid]) != EVTMASK_NONE) {
		tcb_waievt[tskid] = EVTMASK_NONE;
		if ((make_runnable(tskid)) && (callevel == TCL_TASK)) {
			dispatch();
		}
	}
  exit:
	unlock_cpu();
	LOG_SETEVT_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.tskid = tskid;
	_errorhook_par2.mask = mask;
	call_errorhook(ercd, OSServiceId_SetEvent);
	goto exit;
}

/*
 *  イベントのクリア
 */
StatusType
ClearEvent(EventMaskType mask)
{
	StatusType	ercd = E_OK;

	LOG_CLREVT_ENTER(mask);
	CHECK_CALLEVEL(TCL_TASK);
	CHECK_ACCESS(runtsk < tnum_exttask);

	lock_cpu();
	tcb_curevt[runtsk] &= ~mask;
  exit:
	unlock_cpu();
	LOG_CLREVT_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.mask = mask;
	call_errorhook(ercd, OSServiceId_ClearEvent);
	goto exit;
}

/*
 *  イベントの状態参照
 */
StatusType
GetEvent(TaskType tskid, EventMaskRefType p_mask)
{
	StatusType	ercd = E_OK;

	LOG_GETEVT_ENTER(tskid, p_mask);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);
	CHECK_TSKID(tskid);
	CHECK_ACCESS(tskid < tnum_exttask);

	lock_cpu();
	D_CHECK_STATE(tcb_tstat[tskid] != TS_DORMANT);
	*p_mask = tcb_curevt[tskid];
  exit:
	unlock_cpu();
	LOG_GETEVT_LEAVE(ercd, *p_mask);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.tskid = tskid;
	_errorhook_par2.p_mask = p_mask;
	call_errorhook(ercd, OSServiceId_GetEvent);
	goto exit;
}

/*
 *  イベント待ち
 */
StatusType
WaitEvent(EventMaskType mask)
{
	StatusType	ercd = E_OK;

	LOG_WAIEVT_ENTER(mask);
	CHECK_CALLEVEL(TCL_TASK);
	CHECK_ACCESS(runtsk < tnum_exttask);
	CHECK_RESOURCE(tcb_lastres[runtsk] == RESID_NULL);

	lock_cpu();
	if ((tcb_curevt[runtsk] & mask) == EVTMASK_NONE) {
		tcb_curpri[runtsk] = tinib_inipri[runtsk];
		tcb_tstat[runtsk] = TS_WAITING;
		tcb_waievt[runtsk] = mask;
		search_schedtsk();
		dispatch();
		tcb_curpri[runtsk] = tinib_exepri[runtsk];
	}
  exit:
	unlock_cpu();
	LOG_WAIEVT_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.mask = mask;
	call_errorhook(ercd, OSServiceId_WaitEvent);
	goto exit;
}
