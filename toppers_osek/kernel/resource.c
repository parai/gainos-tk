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
 *	リソース管理機能
 */

#include "osek_kernel.h"
#include "check.h"
#include "task.h"
#include "interrupt.h"
#include "resource.h"

/*
 *  リソース管理機能の初期化
 */
void
resource_initialize(void)
{
	ResourceType	resid;

	for (resid = 0; resid < tnum_resource; resid++) {
		rescb_prevpri[resid] = TPRI_NULL;
	}
}

/*
 *  リソースの獲得
 */
StatusType
GetResource(ResourceType resid)
{
	StatusType	ercd = E_OK;
	Priority	ceilpri, curpri;

	LOG_GETRES_ENTER(resid);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_RESID(resid);

	ceilpri = resinib_ceilpri[resid];
	if (callevel == TCL_TASK) {
		CHECK_ACCESS(tinib_inipri[runtsk] <= ceilpri);

		lock_cpu();
		D_CHECK_ACCESS(rescb_prevpri[resid] == TPRI_NULL);
		curpri = tcb_curpri[runtsk];
		rescb_prevpri[resid] = curpri;
		rescb_prevres[resid] = tcb_lastres[runtsk];
		tcb_lastres[runtsk] = resid;
		if (ceilpri > curpri) {
			tcb_curpri[runtsk] = ceilpri;
			if (ceilpri >= TPRI_MINISR) {
				set_ipl(ceilpri - TPRI_MINISR);
			}
		}
	}
	else {
		CHECK_ACCESS(isrinib_intpri[runisr] <= ceilpri);

		lock_cpu();
		D_CHECK_ACCESS(rescb_prevpri[resid] == TPRI_NULL);
		curpri = current_ipl() + TPRI_MINISR;
		rescb_prevpri[resid] = curpri;
		rescb_prevres[resid] = isrcb_lastres[runisr];
		isrcb_lastres[runisr] = resid;
		if (ceilpri > curpri) {
			set_ipl(ceilpri - TPRI_MINISR);
		}
	}
  exit:
	unlock_cpu();
	LOG_GETRES_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.resid = resid;
	call_errorhook(ercd, OSServiceId_GetResource);
	goto exit;
}

/*
 *  リソースの返却
 */
StatusType
ReleaseResource(ResourceType resid)
{
	StatusType	ercd = E_OK;

	LOG_RELRES_ENTER(resid);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_RESID(resid);

	if (callevel == TCL_TASK) {
		CHECK_ACCESS(tinib_inipri[runtsk] <= resinib_ceilpri[resid]);
		CHECK_NOFUNC(tcb_lastres[runtsk] == resid);

		lock_cpu();
		if (rescb_prevpri[resid] >= TPRI_MINISR) {
			set_ipl(rescb_prevpri[resid] - TPRI_MINISR);
		}
		else{
			if (tcb_curpri[runtsk] >= TPRI_MINISR) {
				set_ipl(IPL_ENA_ALL);
			}
		}
		tcb_curpri[runtsk] = rescb_prevpri[resid];
		tcb_lastres[runtsk] = rescb_prevres[resid];
		rescb_prevpri[resid] = TPRI_NULL;
		if (tcb_curpri[runtsk] < nextpri) {
			preempt();
			dispatch();
		}
	}
	else {
		CHECK_ACCESS(isrinib_intpri[runisr] <= resinib_ceilpri[resid]);
		CHECK_NOFUNC(isrcb_lastres[runisr] == resid);

		lock_cpu();
		set_ipl(rescb_prevpri[resid] - TPRI_MINISR);
		isrcb_lastres[runisr] = rescb_prevres[resid];
		rescb_prevpri[resid] = TPRI_NULL;
	}
  exit:
	unlock_cpu();
	LOG_RELRES_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.resid = resid;
	call_errorhook(ercd, OSServiceId_ReleaseResource);
	goto exit;
}
