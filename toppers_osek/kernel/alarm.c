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
 *	アラーム機能
 */

#include "osek_kernel.h"
#include "check.h"
#include "alarm.h"

/*
 *  スタティック関数のプロトタイプ宣言
 */
Inline TickType	add_tick(TickType almval, TickType incr, TickType maxval2);
Inline TickType	diff_tick(TickType val1, TickType val2, TickType maxval2);
static void	enqueue_alarm(AlarmType almid, CounterType cntid);
static void	dequeue_alarm(AlarmType almid, CounterType cntid);

/*
 *  ティック値の加算
 *
 *  almval に incr を加算したティック値を返す．加算したティック値が，
 *  maxval2 を超える場合には，(maxval2 + 1) を引いた値を返す．
 */
Inline TickType
add_tick(TickType almval, TickType incr, TickType maxval2)
{
	/*
	 *  素直な条件式は almval + incr <= maxval2 であるが，この条件式で
	 *  は，almval + incr が TickType で表せる範囲を超える場合に正しく
	 *  判定できなくなるため，次の条件式としている．
	 */
	if (incr <= (maxval2 - almval)) {
		return(almval + incr);
	}
	else {
		/*
		 *  下の計算式で，almval + incr と maxval2 + 1 が TickType で表
		 *  せる範囲を超える場合があるが，オーバフローしても求まる値は
		 *  正しいため差し支えない．
		 */
		return(almval + incr - (maxval2 + 1));
	}
}

/*
 *  ティック値の差
 *
 *  val1 と val2 の差（val1 から val2 を引いた値）を返す．差が負の値に
 *  なる場合には，(maxval2 + 1) を加えた値を返す．
 */
Inline TickType
diff_tick(TickType val1, TickType val2, TickType maxval2)
{
	if (val1 >= val2) {
		return(val1 - val2);
	}
	else {
		/*
		 *  下の計算式で，val1 - val2 と maxval2 + 1 が TickType で表せ
		 *  る範囲を超える場合があるが，オーバフローしても求まる値は正
		 *  しいため差し支えない．
		 */
		return(val1 - val2 + (maxval2 + 1));
	}
}

/*
 *  アラームキューへの挿入
 *
 *  almid で指定されるアラームを，cntid で指定されるカウンタのアラーム
 *  キューに挿入する．また，アラームキューに同じ時刻のアラームがある場
 *  合には，その末尾に挿入する（先頭でも差し支えないと思われる）．
 */
static void
enqueue_alarm(AlarmType almid, CounterType cntid)
{
	TickType	enqval, curval;
	AlarmType	next, prev;

	enqval = almcb_almval[almid];
	curval = cntcb_curval[cntid];

	/*
	 *  挿入場所のサーチ
	 */
	next = cntcb_almque[cntid];
	prev = ALMID_NULL;
	if (curval < enqval) {
		/*
		 *  enqval が curval よりも大きい時．言い換えると，現在
		 *  ティックからアラームの指定ティックまでの間に，カウ
		 *  ンタのオーバフロー（最大値を超えて，0 に戻ること）
		 *  が起こらない場合．
		 */
		while ((next != ALMID_NULL) && ((curval <= almcb_almval[next])
					&& (almcb_almval[next] <= enqval))) {
			prev = next;
			next = almcb_next[prev];
		}
	}
	else {
		/*
		 *  それ以外の時．言い換えると，現在ティックからアラー
		 *  ムの指定ティックまでの間に，カウンタのオーバフロー
		 *  が起こる場合．
		 */
		while ((next != ALMID_NULL) && ((curval <= almcb_almval[next])
					|| (almcb_almval[next] <= enqval))) {
			prev = next;
			next = almcb_next[prev];
		}
	}

	/*
	 *  キューのつなぎ換え処理
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
 *  アラームキューからの削除
 *
 *  almid で指定されるアラームを，cntid で指定されるカウンタのアラー
 *  ムキューから削除する．
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
 *  アラーム機能の初期化
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
 *  アラームベースの参照
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
 *  アラームの状態参照
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
 *  アラームの設定（相対値）
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
 *  アラームの設定（絶対値）
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
 *  アラームのキャンセル
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
 *  カウンタを進める
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
	 *  更新後のカウンタ値を求める
	 */
	newval = add_tick(cntcb_curval[cntid], cntinib_tickbase[cntid],
												cntinib_maxval2[cntid]);

	/*
	 *  カウンタの現在値の更新
	 */
	cntcb_curval[cntid] = newval;

	/*
	 *  アラームの expire 処理
	 */
	while (((almid = cntcb_almque[cntid]) != ALMID_NULL)
			&& diff_tick(newval, almcb_almval[almid], cntinib_maxval2[cntid])
												<= cntinib_maxval[cntid]) {
		/*
		 *  アラームキューの先頭のアラームを，キューから外す．
		 */
		next = almcb_next[almid];
		cntcb_almque[cntid] = next;
		if (next != ALMID_NULL) {
			almcb_prev[next] = ALMID_NULL;
		}
		almcb_next[almid] = almid;

		/*
		 *  アラームコールバックの呼び出し
		 */
		unlock_cpu();
		(*alminib_cback[almid])();
		lock_cpu();

		/*
		 *  アラームキューへの再挿入（周期アラームの場合）
		 *
		 *  アラームコールバックの中で自アラームを SetRelAlarm/
		 *  SetAbsAlarm した状況（OSEK仕様では許されていないが，
		 *  TOPPERS/OSEKカーネルでは許している）で，アラームキュー
		 *  への再挿入を防ぐために，almcb_next[almid] == almid
		 *  の場合のみ再挿入する．
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
