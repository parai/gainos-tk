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

#ifndef _ALARM_H_
#define _ALARM_H_

/*
 *  invalid alarm ID
 */
#define ALMID_NULL		((AlarmType) UINT8_INVALID)

/*
 *  number of ALARM and Counter
 */
extern const UINT8		tnum_counter;		/* Counter number configured */
extern const UINT8		tnum_alarm;			/* Alarm number configured */

/*
 *  configured information for counter
 */
extern const TickType	cntinib_maxval[];	/* maxed allowed value for alarm */
extern const TickType	cntinib_maxval2[];	/* cntinib_maxval2+1 */
extern const TickType	cntinib_tickbase[];	/* counter tick base */
extern const TickType	cntinib_mincyc[];	/* alarm min cycle */

/*
 *  counter control block
 */
extern TickType			cntcb_curval[];		/* counter current value*/
extern AlarmType		cntcb_almque[];		/* counter queue */

/*
 *  configured information for alarm
 */
extern const CounterType alminib_cntid[];	/* alarm owner< Counter ID> */
extern const FP			 alminib_cback[];	/* alarm call back routine */
extern const AppModeType alminib_autosta[];	/* alarm autostart mode */
extern const TickType	 alminib_almval[];	/* alarm init expire time at autostart*/
extern const TickType	 alminib_cycle[];	/* alarm init cycle time at autostart*/

/*
 *  alarm control block
 */
extern AlarmType		almcb_next[];		/* next alarm in queue */
extern AlarmType		almcb_prev[];		/* previous alarm in queue */
extern TickType			almcb_almval[];		/* expire time */
extern TickType			almcb_cycle[];		/* alarm cycle time */

/*
 *  initialize alarm
 */
extern void	alarm_initialize(void);

#endif /* _ALARM_H_ */
