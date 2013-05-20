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
 *  SuspendAllInterrupts nest count
 *
 *  disable_int() will be called when sus_all_cnt is ZERO
 */
UINT8		sus_all_cnt;

/*
 *  SuspendOSInterrupts nest
 *
 *  will call set_ipl(ipl_maxisr2) to block all the ISR2 if sus_os_cnt
 *  is ZERO. 
 */
static UINT8	sus_os_cnt;

/*
 *  SuspendOSInterrupts call time ipl
 *
 *  when call set_ipl(ipl_maxisr2) to block all the OS ISR2 if
 *  sus_os_cnt is ZERO, saved_ipl will used to store the current 
 *  CPU IPL(interrupt processing level).
 *  And then when ResumeOSInterrupts called and sus_os_cnt is One,
 *  then CPU IPL will be restored by saved_ipl.
 */
static IPL	saved_ipl;

/*
 *  SuspendAllInterrupts/SuspendOSInterrupts call level saved
 *
 *  when disable_int or set_ipl(ipl_maxisr2), should save the current
 *  OS calling level if sus_os_cnt is ZERO for disable_int or if
 *  sus_all_cnt is ZERO for set_ipl(ipl_maxisr2).
 *  when ResumeAllInterrupts/ResumeOSInterrupts is called and if
 *  sus_all_cnt or sus_os_cnt is One, should restore OS calling level.
 */
static UINT8	saved_callevel;

/*
 *  interrupt initialize
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
 *  Disable all interrupts
 */
void
DisableAllInterrupts(void)
{
	LOG_DISINT_ENTER();
	disable_int();
	LOG_DISINT_LEAVE();
}

/*
 *  Enable all interrupts
 */
void
EnableAllInterrupts(void)
{
	LOG_ENAINT_ENTER();
	enable_int();
	LOG_ENAINT_LEAVE();
}

/*
 *  Suspend all interrupts
 */
void
SuspendAllInterrupts(void)
{
	LOG_SUSALL_ENTER();
	if (sus_all_cnt == UINT8_INVALID) {
		/*
		 *  SuspendAllInterrupts has reached its max nest count
		 *  So do nothing. May a ResumeAllInterrupts call has been forgot.
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
 *  Resume all interrupts
 */
void
ResumeAllInterrupts(void)
{
	LOG_RSMALL_ENTER();
	if (sus_all_cnt == 0) {
		/*
		 *  SuspendAllInterrupts hasn't been called before ResumeAllInterrupts
		 *  It's an error, so just do nothig.
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
 *  Suspend OS interrupts
 */
void
SuspendOSInterrupts(void)
{
	IPL	ipl;

	LOG_SUSOSI_ENTER();
	if (sus_os_cnt == UINT8_INVALID) {
		/*
		 *  SuspendOSInterrupts has reached its max nest count
		 *  do nothing.
		 */
	}
	else if (sus_os_cnt == 0) {
		ipl = current_ipl();

		/*
		 *  to block all the OS ISR2s, should set the IPL to the max IPL of all the OS ISR2
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
 *  Resume OS Interrupts
 */
void
ResumeOSInterrupts(void)
{
	LOG_RSMOSI_ENTER();
	if (sus_os_cnt == 0) {
		/*
		 *  SuspendOSInterrupts hasn't been called before ResumeOSInterrupts
		 *  do nothing as it is an error
		 */
	}
	else if (sus_os_cnt == 1) {
		if (sus_all_cnt == 0) {
			callevel = saved_callevel;
		}
		sus_os_cnt--;

		/*
		 *  to resume the OS ISR2 acknowledge, restore the IPL to the saved_ipl
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
