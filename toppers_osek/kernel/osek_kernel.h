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

#ifndef _OSEK_KERNEL_H_
#define _OSEK_KERNEL_H_

/*
 *  includes
 */
#include "kernel.h"

/*
 *  type defines for kernel
 */
#ifndef _MACRO_ONLY
typedef void		*VP;			/* void pointer */
typedef void		(*FP)(void);	/* function pointer */
typedef UINT8		Priority;		/* priority for task/resource/ISR */
typedef	UINT8		IPL;			/* interrupt processing level */
#endif /* _MACRO_ONLY */

#include "portable.h"
/*
 *  number of prioritys
 */
#define TNUM_PRIORITY	((Priority) 16)

/*
 *  NULL
 */
#define	NULL			((void *) 0)		/* NULL */

/*
 *  Macros for priority
 */
#define TPRI_MINTASK	((Priority) 0)		/* minimum priority */
#define TPRI_MAXTASK	((Priority)(TNUM_PRIORITY - 1))
											/* maximum priority */
#define TPRI_SCHEDULER	((Priority) 127)	/* priority of the scheduler */
#define TPRI_MINISR		((Priority) 128)	/* the minimum priority of ISRs */
#define TPRI_NULL		((Priority) UINT8_INVALID)
											/* invalid priprity */

/*
 *  Event Macros
 */
#define EVTMASK_NONE	((EventMaskType) 0)	/* No event */

/*
 *  Application mode
 */
#define APPMODE_NONE	((AppModeType) 0)	/* void application mode */

/*
 *  IPL
 */
#define IPL_ENA_ALL	((IPL) 0)		/* IPL default mode,all interrupt is abled to get to be processed by cpu if enabled */

/*
 *  kernel call level
 */
#define TCL_NULL		((UINT8) 0x00)	/* invalid kernel call level */
#define TCL_TASK		((UINT8) 0x01)	/* task level */
#define TCL_ISR2		((UINT8) 0x02)	/* interrupt type 2 ISR */
#define TCL_ERROR		((UINT8) 0x04)	/* ErrorHook */
#define TCL_PREPOST		((UINT8) 0x08)	/* PreTaskHook & PostTaskHook */
#define TCL_STARTUP		((UINT8) 0x10)	/* StartupHook */
#define TCL_SHUTDOWN	((UINT8) 0x20)	/* ShutdownHook */


#ifndef _MACRO_ONLY
/*
 *  help the OS to remember os kernel status,see osctl.c
 */
extern UINT8		callevel;	/* help to remember os calling level */
extern AppModeType	appmode;	/* help to remember os application mode */

/*
 *  OS lock/unlock API
 */
Inline void	lock_cpu(void);		/* lock the cpu,that no interrupts will be acknowledged */
Inline void	unlock_cpu(void);	/* unlock the cpu,that interruprs can be acknowledged */

Inline void
lock_cpu(void)
{
	disable_int();
}

Inline void
unlock_cpu(void)
{
	enable_int();
}

/*
 *  called when os error encountered
 */
extern void	call_errorhook(StatusType ercd, OSServiceIdType svcid);

/*
 *  called when task enter or leave running state
 */
extern void	call_posttaskhook(void);
extern void	call_pretaskhook(void);

/*
 *  os_cfg.c
 */
extern void	object_initialize(void);

#endif /* _MACRO_ONLY */

/*
 *  if BASIC_STATUS undefined, the EXTEND_STATUS will be the default
 */
#ifndef BASIC_STATUS
#define EXTENDED_STATUS
#endif /* BASIC_STATUS */

#endif /* _OSEK_KERNEL_H_ */
