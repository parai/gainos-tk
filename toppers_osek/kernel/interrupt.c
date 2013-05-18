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
#include "interrupt.h"

/*
 *  help the kernel to remember current ISR ID
 */
IsrType		runisr;

/*
 *  割込み管理機能内部で使用する変数の定義
 */

/*
 *  SuspendAllInterrupts のネスト回数
 *
 *  この変数は，disable_int() した状態でのみ変更してよい．
 */
UINT8		sus_all_cnt;

/*
 *  SuspendOSInterrupts のネスト回数
 *
 *  この変数は，set_ipl(ipl_maxisr2) した状態でのみ変更してよい．
 *  set_ipl(ipl_maxisr2) しても，カテゴリ1 の ISR は入ってくるが，元の
 *  値に戻してからリターンすれば問題はない．
 */
static UINT8	sus_os_cnt;

/*
 *  SuspendOSInterrupts する前の割込み優先レベル
 *
 *  この変数は，set_ipl(ipl_maxisr2) した状態でのみ変更してよい．また，
 *  この変数を使用している間は，sus_os_cnt を非ゼロにしておく．
 *  set_ipl(ipl_maxisr2) してもカテゴリ1 の ISR は入ってくるが，
 *  sus_os_cnt を非ゼロにしておくことで，カテゴリ1 の ISR でこの変数が
 *  変更されることはない．
 */
static IPL	saved_ipl;

/*
 *  SuspendAllInterrupts/SuspendOSInterrupts する前の実行コンテキスト
 *
 *  この変数は，disable_int または set_ipl(ipl_maxisr2) した状態でのみ
 *  変更してよい．また，この変数を使用している間は，sus_all_cnt か 
 *  sus_os_cnt を非ゼロにしておく．set_ipl(ipl_maxisr2) してもカテゴリ1
 *  の ISR は入ってくるが，sus_os_cnt を非ゼロにしておくことで，カテゴ
 *  リ1 の ISR でこの変数が変更されることはない．
 */
static UINT8	saved_callevel;

/*
 *  割込み管理機能の初期化
 */
void
interrupt_initialize(void)
{
	IsrType		isrid;

	isrid = ISRID_NULL;
	sus_all_cnt = 0u;
	sus_os_cnt = 0u;
	for (isrid = 0; isrid < tnum_isr2; isrid++) {
		isrcb_lastres[isrid] = 0u;
	}
}

/*
 *  すべての割込みの禁止（高速簡易版）
 */
void
DisableAllInterrupts(void)
{
	LOG_DISINT_ENTER();
	disable_int();
	LOG_DISINT_LEAVE();
}

/*
 *  すべての割込みの許可（高速簡易版）
 */
void
EnableAllInterrupts(void)
{
	LOG_ENAINT_ENTER();
	enable_int();
	LOG_ENAINT_LEAVE();
}

/*
 *  すべての割込みの禁止
 */
void
SuspendAllInterrupts(void)
{
	LOG_SUSALL_ENTER();
	if (sus_all_cnt == UINT8_INVALID) {
		/*
		 *  SuspendAllInterrupts を繰り返し呼んだ場合の対策
		 *  （何もせずに抜ける）
		 */
	}
	else if (sus_all_cnt == 0) {
		disable_int();
		sus_all_cnt++;
		if (sus_os_cnt == 0) {
			saved_callevel = callevel;
			callevel = TCL_NULL;
		}
	}
	else {
		sus_all_cnt++;
	}
	LOG_SUSALL_LEAVE();
}

/*
 *  すべての割込みの許可
 */
void
ResumeAllInterrupts(void)
{
	LOG_RSMALL_ENTER();
	if (sus_all_cnt == 0) {
		/*
		 *  SuspendAllInterrupts を呼ばずに，ResumeAllInterrupts
		 *  を呼んだ場合の対策（何もせずに抜ける）
		 */
	}
	else if (sus_all_cnt == 1) {
		if (sus_os_cnt == 0) {
			callevel = saved_callevel;
		}
		sus_all_cnt--;
		enable_int();
	}
	else {
		sus_all_cnt--;
	}
	LOG_RSMALL_LEAVE();
}

/*
 *  カテゴリ2の割込みの禁止
 */
void
SuspendOSInterrupts(void)
{
	IPL	ipl;

	LOG_SUSOSI_ENTER();
	if (sus_os_cnt == UINT8_INVALID) {
		/*
		 *  SuspendOSInterrupts を繰り返し呼んだ場合の対策
		 *  （何もせずに抜ける）
		 */
	}
	else if (sus_os_cnt == 0) {
		ipl = current_ipl();

		/*
		 *  すでに ISR2 が禁止されている時は何もしない．
		 */
		if (ipl < ipl_maxisr2) {
			set_ipl(ipl_maxisr2);
		}
		sus_os_cnt++;
		saved_ipl = ipl;
		if (sus_all_cnt == 0) {
			saved_callevel = callevel;
			callevel = TCL_NULL;
		}
	}
	else {
		sus_os_cnt++;
	}
	LOG_SUSOSI_LEAVE();
}

/*
 *  カテゴリ2の割込みの許可
 */
void
ResumeOSInterrupts(void)
{
	LOG_RSMOSI_ENTER();
	if (sus_os_cnt == 0) {
		/*
		 *  SuspendOSInterrupts を呼ばずに，ResumeOSInterrupts
		 *  を呼んだ場合の対策（何もせずに抜ける）
		 */
	}
	else if (sus_os_cnt == 1) {
		if (sus_all_cnt == 0) {
			callevel = saved_callevel;
		}
		sus_os_cnt--;

		/*
		 *  もともと ISR2 が禁止されていた時は何もしない．
		 */
		if (saved_ipl < ipl_maxisr2) {
			set_ipl(saved_ipl);
		}
	}
	else {
		sus_os_cnt--;
	}
	LOG_RSMOSI_LEAVE();
}
