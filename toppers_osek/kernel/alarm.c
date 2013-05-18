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
 *	Includes
 */

#include "osek_kernel.h"
#include "check.h"
#include "alarm.h"

/*
 *  Local Alarm APIs
 */
Inline TickType	add_tick(TickType almval, TickType incr, TickType maxval2);
Inline TickType	diff_tick(TickType val1, TickType val2, TickType maxval2);
static void	enqueue_alarm(AlarmType almid, CounterType cntid);
static void	dequeue_alarm(AlarmType almid, CounterType cntid);

/*
 *  to calculate the next alarm expiry value or counter current value
 *
 *  almval + incr: alarm curreent value + alarm increment(cycle value)
 *  maxval2 is the max allowed value for alarm and counter
 */
Inline TickType
add_tick(TickType almval, TickType incr, TickType maxval2)
{
	/*
	 *  if almval + incr <= maxval2 then no overflow
	 *  so next expiry value is (almval + incr)
	 */
	if (incr <= (maxval2 - almval)) {
		return(almval + incr);
	}
	else {
		/*
		 *  if almval + incr > maxval2, overflow 
		 *  so should roll back from zero
		 */
		return(almval + incr - (maxval2 + 1));
	}
}

/*
 *  diff_tick between alarm and counter
 *
 *  val1: the counter current value; val2: the alarm next expiry value
 *  calculate the diff between val1 and val2
 */
Inline TickType
diff_tick(TickType val1, TickType val2, TickType maxval2)
{
	if (val1 >= val2) {
		return(val1 - val2);
	}
	else {
		/*
		 *  as val1 < val2,that's counter current value < alarm next erpiry value
		 *  So It's not the time to process this alarm.
		 *  As maxval2 is always the 2 times of maxval,so |val2 - val1| < maxval.
		 *  SO,the return value always bigger than maxval.
		 */
		return(val1 - val2 + (maxval2 + 1));
	}
}

/*
 *  put the alarm to counter queue
 *
 * in the time value order from min to max,the almid was linked to cntid's queue
 * but shoul note that the absolut max value dosen't mean the the last in the queue,
 * if the almid is an overflowed one,it should skip all the non-overflowed one.
 */
static void
enqueue_alarm(AlarmType almid, CounterType cntid)
{
	TickType	enqval, curval;
	AlarmType	next, prev;

	enqval = almcb_almval[almid];
	curval = cntcb_curval[cntid];

	/*
	 *  get counter queue head
	 */
	next = cntcb_almque[cntid];
	prev = ALMID_NULL;
	if (curval < enqval) {
		/*
		 *  enqval > curval , so it's an non-overflowed one
		 *  skip all the alarm in the queue whose almval < enqval 
		 *  untill find the right positon where almval >enqval or 
		 *  find an overflowed alarm.
		 */
		while ((next != ALMID_NULL) && ((curval <= almcb_almval[next])
					&& (almcb_almval[next] <= enqval))) {
			prev = next;
			next = almcb_next[prev];
		}
	}
	else {
		/*
		 *  this is an overflowed alarm,so should first skip all the 
		 *  non-overflowed one( whose value > curval),
		 *  and then in the overflowed parts find the alarm whose value > enqval
		 */
		while ((next != ALMID_NULL) && ((curval <= almcb_almval[next])
					|| (almcb_almval[next] <= enqval))) {
			prev = next;
			next = almcb_next[prev];
		}
	}

	/*
	 *  insert the almid between prev and next
	 */
	almcb_next[almid] = next;
	almcb_prev[almid] = prev;
	if (prev != ALMID_NULL) {
		almcb_next[prev] = almid;
	}
	else {
		cntcb_almque[cntid] = almid;
	}
	if (next != ALMID_NULL) {
		almcb_prev[next] = almid;
	}
}

/*
 *  remove the almid from the queue of cntid
 */
static void
dequeue_alarm(AlarmType almid, CounterType cntid)
{
	AlarmType	next, prev;

	next = almcb_next[almid];
	prev = almcb_prev[almid];
	if (prev != ALMID_NULL) {
		almcb_next[prev] = next;
	}
	else {
		cntcb_almque[cntid] = next;
	}
	if (next != ALMID_NULL) {
		almcb_prev[next] = prev;
	}
	almcb_next[almid] = almid;
}

/*
 *  initialize the alarm and counter
 */
void
alarm_initialize(void)
{
	CounterType	cntid;
	AlarmType	almid;

	for (cntid = 0; cntid < tnum_counter; cntid++) {
		cntcb_curval[cntid] = 0u;
		cntcb_almque[cntid] = ALMID_NULL;
	}
	for (almid = 0; almid < tnum_alarm; almid++) {
		almcb_next[almid] = almid;
		if ((alminib_autosta[almid] & appmode) != APPMODE_NONE) {
			almcb_almval[almid] = alminib_almval[almid];
			almcb_cycle[almid] = alminib_cycle[almid];
			enqueue_alarm(almid, alminib_cntid[almid]);
		}
	}
}

/*
 *  Get the alarm base information
 */
StatusType
GetAlarmBase(AlarmType almid, AlarmBaseRefType p_info)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;

	LOG_GETALB_ENTER(almid, p_info);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);
	CHECK_ALMID(almid);

	cntid = alminib_cntid[almid];
	p_info->maxallowedvalue = cntinib_maxval[cntid];
	p_info->ticksperbase = cntinib_tickbase[cntid];
	p_info->mincycle = cntinib_mincyc[cntid];
  exit:
	LOG_GETALB_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.almid = almid;
	_errorhook_par2.p_info = p_info;
	call_errorhook(ercd, OSServiceId_GetAlarmBase);
	unlock_cpu();
	goto exit;
}

/*
 *  get the alarm next expiry value in ticks
 */
StatusType
GetAlarm(AlarmType almid, TickRefType p_tick)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;
	TickType	curval;

	LOG_GETALM_ENTER(almid, p_tick);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);
	CHECK_ALMID(almid);

	lock_cpu();
	if (almcb_next[almid] == almid) {
		ercd = E_OS_NOFUNC;
		goto d_error_exit;
	}
	cntid = alminib_cntid[almid];
	curval = cntcb_curval[cntid];
	if (curval < almcb_almval[almid]) {
		*p_tick = almcb_almval[almid] - curval;
	}
	else {
		*p_tick = (cntinib_maxval2[cntid] - curval) + 1
					+ almcb_almval[almid];
	}
  exit:
	unlock_cpu();
	LOG_GETALM_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	_errorhook_par2.p_tick = p_tick;
	call_errorhook(ercd, OSServiceId_GetAlarm);
	goto exit;
}

/*
 *  start a alarm,set its next expiry value relate to counter curval
 */
StatusType
SetRelAlarm(AlarmType almid, TickType incr, TickType cycle)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;
	TickType	maxval;

	LOG_SETREL_ENTER(almid, incr, cycle);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_ALMID(almid);

	cntid = alminib_cntid[almid];
	maxval = cntinib_maxval[cntid];
	CHECK_VALUE((0u < incr) && (incr <= maxval));
	CHECK_VALUE((cycle == 0u)
		|| ((cntinib_mincyc[cntid] <= cycle) && (cycle <= maxval)));

	lock_cpu();
	if (almcb_next[almid] != almid) {
		ercd = E_OS_STATE;
		goto d_error_exit;
	}
	almcb_almval[almid] = add_tick(cntcb_curval[cntid], incr,
										cntinib_maxval2[cntid]);
	almcb_cycle[almid] = cycle;
	enqueue_alarm(almid, cntid);
  exit:
	unlock_cpu();
	LOG_SETREL_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	_errorhook_par2.incr = incr;
	_errorhook_par3.cycle = cycle;
	call_errorhook(ercd, OSServiceId_SetRelAlarm);
	goto exit;
}

/*
 *  start a alarm,set its next expiry value absolute to counter curval
 */
StatusType
SetAbsAlarm(AlarmType almid, TickType start, TickType cycle)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;
	TickType	maxval, start2;

	LOG_SETABS_ENTER(almid, start, cycle);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_ALMID(almid);

	cntid = alminib_cntid[almid];
	maxval = cntinib_maxval[cntid];
	CHECK_VALUE(start <= maxval);
	CHECK_VALUE((cycle == 0u)
		|| ((cntinib_mincyc[cntid] <= cycle) && (cycle <= maxval)));

	lock_cpu();
	if (almcb_next[almid] != almid) {
		ercd = E_OS_STATE;
		goto d_error_exit;
	}

	start2 = start + maxval + 1;
	if (cntcb_curval[cntid] <= maxval) {
		if (start <= cntcb_curval[cntid]) {
			almcb_almval[almid] = start2;
		}
		else {
			almcb_almval[almid] = start;
		}
	}
	else {
		if (start2 <= cntcb_curval[cntid]) {
			almcb_almval[almid] = start;
		}
		else {
			almcb_almval[almid] = start2;
		}
	}
	almcb_cycle[almid] = cycle;
	enqueue_alarm(almid, cntid);
  exit:
	unlock_cpu();
	LOG_SETABS_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	_errorhook_par2.start = start;
	_errorhook_par3.cycle = cycle;
	call_errorhook(ercd, OSServiceId_SetAbsAlarm);
	goto exit;
}

/*
 *  cancle the alarm
 *
 */
StatusType
CancelAlarm(AlarmType almid)
{
	StatusType	ercd = E_OK;

	LOG_CANALM_ENTER(almid);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_ALMID(almid);

	lock_cpu();
	if (almcb_next[almid] == almid) {
		ercd = E_OS_NOFUNC;
		goto d_error_exit;
	}
	dequeue_alarm(almid, alminib_cntid[almid]);

	/*
	 *  アラームコールバックの中から，自アラームを SetRelAlarm/
	 *  SetAbsAlarm した後に CancelAlarm した状況（OSEK仕様では許
	 *  されていないが，TOPPERS/OSEKカーネルでは許している）で，自
	 *  アラームがアラームキューに再挿入されるのを防ぐために，
	 *  almcb_cycle[almid] を 0 にしておく．
	 */
	almcb_cycle[almid] = 0u;
  exit:
	unlock_cpu();
	LOG_CANALM_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	call_errorhook(ercd, OSServiceId_CancelAlarm);
	goto exit;
}

/*
 *  signal the counter that it should increment
 */
StatusType
SignalCounter(CounterType cntid)
{
	StatusType	ercd = E_OK;
	TickType	newval;
	AlarmType	almid, next;

	LOG_SIGCNT_ENTER(cntid);
	CHECK_CALLEVEL(TCL_ISR2);
	CHECK_CNTID(cntid);

	lock_cpu();

	/*
	 *  calculate the counter next value
	 */
	newval = add_tick(cntcb_curval[cntid], cntinib_tickbase[cntid],
												cntinib_maxval2[cntid]);

	/*
	 *  store the counter current value
	 */
	cntcb_curval[cntid] = newval;

	/*
	 *  process the already expiried one
	 */
	while (((almid = cntcb_almque[cntid]) != ALMID_NULL)
			&& diff_tick(newval, almcb_almval[almid], cntinib_maxval2[cntid])
												<= cntinib_maxval[cntid]) {
		/*
		 *  find one,first remove it from the counter queue
		 */
		next = almcb_next[almid];
		cntcb_almque[cntid] = next;
		if (next != ALMID_NULL) {
			almcb_prev[next] = ALMID_NULL;
		}
		almcb_next[almid] = almid;

		/*
		 *  process it,call its callback routine
		 */
		unlock_cpu();
		(*alminib_cback[almid])();
		lock_cpu();

		/*
		 *  if this alarm is cyclic alarm,put it to the counter queue again
		 */
		if ((almcb_next[almid] == almid) && (almcb_cycle[almid] > 0u)) {
			almcb_almval[almid] = add_tick(almcb_almval[almid], 
								almcb_cycle[almid], cntinib_maxval2[cntid]);
			enqueue_alarm(almid, cntid);
		}
	}
  exit:
	unlock_cpu();
	LOG_SIGCNT_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.cntid = cntid;
	call_errorhook(ercd, OSServiceId_SignalCounter);
	goto exit;
}
