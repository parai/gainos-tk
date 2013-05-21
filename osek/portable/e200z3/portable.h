/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine China
 * Open Source Society; either version 1 of the License, or (at developer option)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the U-License for more details.
 * Developer should have received a copy of the U-Licensealong with this program;
 * if not, download from www.tecoss.org(the web page of the T-Engine China Open
 * Source Society).
 *
 * GaInOS-TK is a static configured RTOS, which conformed to OSEK OS 2.2.3 Specification
 * and it is based on uTenux(http://www.uloong.cc).
 *
 * Email: parai@foxmail.com
 * Sourrce Open At: https://github.com/parai/gainos-tk/
 */
#ifndef  VPORT_H_H
#define  VPORT_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h"
#include "portmacro.h"
#include "knl_task.h"
/* ============================ MACROs ============================================= */
#define configRTI  0
#define configDEC  1
#define configTickSrc configDEC

#define SP_OFFSET 8 /* sizeof(QUEUE) */

/* ============================ TYPEs ============================================= */
/*
 * System stack configuration at task startup
 */
typedef struct {
    VW r[32];  /* R0 ~ R31 */
    VW taskmode;
    VW srr0;
    VW srr1;
    VW usprg;
    VW ctr;
    VW xer;
    VW cr;
    VW lr;
    VW spefscr;
    VW pad2;
    VW pad3;
    VW msr;
} SStackFrame;

/* ============================ FUNCTIONs ========================================= */
/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
IMPORT void knl_force_dispatch(void); 
/*
 * Start task dispatcher
 */
#define knl_dispatch() {asm("sc");}

/*
 * Start task dispatcher during ISR
 */
#define knl_isr_dispatch() {asm("sc");}

IMPORT imask_t disint( void );
IMPORT void enaint( imask_t intsts );
IMPORT void knl_start_hw_timer( void );
/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
IMPORT void knl_setup_context( TCB *tcb );
IMPORT ISR(SystemTick);
IMPORT void knl_dispatch_entry(void);
IMPORT void knl_activate_r(void);
IMPORT void knl_dispatch_r(void);


/***************************************************************************************************
		Regeister Map
***************************************************************************************************/
#define XR0     0
#define XR1     XR0+4
#define XR2     XR1+4  /* untouch it because of _SDA2_BASE_ */
#define XR3     XR2+4    
#define XR4     XR3+4
#define XR5     XR4+4
#define XR6     XR5+4
#define XR7     XR6+4
#define XR8     XR7+4
#define XR9     XR8+4
#define XR10    XR9+4
#define XR11    XR10+4
#define XR12    XR11+4
#define XR13    XR12+4	/* untouch it because of _SDA_BASE_ */
#define XR14    XR13+4
#define XR15    XR14+4
#define XR16    XR15+4
#define XR17    XR16+4
#define XR18    XR17+4
#define XR19    XR18+4
#define XR20    XR19+4
#define XR21    XR20+4
#define XR22    XR21+4
#define XR23    XR22+4
#define XR24    XR23+4
#define XR25    XR24+4
#define XR26    XR25+4
#define XR27    XR26+4
#define XR28    XR27+4
#define XR29    XR28+4
#define XR30    XR29+4
#define XR31    XR30+4 
#define XTMODE  XR31+4
#define XSRR0   XTMODE+4
#define XSRR1   XSRR0+4
#define XUSPRG  XSRR1+4 
#define XCTR    XUSPRG+4    
#define XXER    XCTR+4
#define XCR     XXER+4
#define XLR     XCR+4
#define XSPEFSCR XLR+4
#define XPAD2   XSPEFSCR+4
#define XPAD3   XPAD2+4
#define XMSR    XPAD3+4

#define STACK_FRAME_SIZE   XMSR+4
		
#define OS_SAVE_R2_TO_R31()  stmw  r2,XR2(r1)
#define OS_SAVE_R4_TO_R31()  stmw  r4,XR4(r1)	

#define OS_SAVE_SPFRS()                         \
	/*Store XMSR ang SPEFSCR  */                \
	mfmsr   r0;                                 \
	stw     r0,  XMSR(r1);                      \
	mfspr   r0,  SPEFSCR;                       \
	stw     r0,  XSPEFSCR(r1);                  \
	/*Store LR(SRR0)*/                          \
	mfspr   r0,  SRR0;                          \
	stw     r0,  XSRR0(r1);                     \
	/*Store MSR(SRR1)*/                         \
	mfspr   r0,  SRR1;                          \
	stw     r0,  XSRR1(r1);                     \
	/*Store USPRG0*/                            \
	mfspr   r0,  USPRG0;                        \
	stw     r0,  XUSPRG(r1);                    \
	/*Store LR*/                                \
	mflr    r0;                                 \
	stw     r0,  XLR(r1);                       \
	/*Store CTR*/                               \
	mfctr   r0;                                 \
	stw     r0,  XCTR(r1);                      \
	/*Store XER*/                               \
	mfxer   r0;                                 \
	stw     r0,  XXER(r1);                      \
	/*Store CR*/                                \
	mfcr    r0;                                 \
	stw     r0,  XCR(r1)
	
#define OS_RESTORE_R2_TO_R31()  lmw  r2,XR2(r1)

#define OS_RESTORE_R3_TO_R31()  lmw  r3,XR3(r1)

#define OS_RESTORE_SPFRS()                                              \
	/*restore CR*/                                                      \
    lwz     r0,  XCR(r1);                                               \
    mtcrf   0xff,r0;                                                    \
	/*restore XER*/                                                     \
	lwz     r0,  XXER(r1);                                              \
	mtxer   r0;                                                         \
	/*restore CTR*/                                                     \
	lwz     r0,  XCTR(r1);                                              \
	mtctr   r0;                                                         \
	/*restore LR¡êo?a????¡ä??¡Â¡À?D?¡À¡ê¡ä?¡ê?¨°??¡ã?¨°¡ä¨ª?¨®¦Ì?¨¨??a?¨¦¨°?2?¨®?*/        \
	lwz     r0,  XLR(r1);                                               \
	mtlr    r0;                                                         \
	/*restore SRR1*/                                                    \
	lwz     r0,  XSRR1(r1);                                             \
	mtspr   SRR1,r0;                                                    \
	/*restore SRR0*/                                                    \
	lwz     r0,  XSRR0(r1);                                             \
	mtspr   SRR0,r0;                                                    \
	/*restore USPRG*/                                                   \
	lwz     r0,  XUSPRG(r1);                                            \
	mtspr   USPRG0,r0;                                                  \
	/*restore SPEFSCR :¡¤t??¨®¨²??¦Ì?????¡ê??¨¦¨°?2?¨®?¡À¡ê¡ä?¡ê¡§¨¨?1?2?¨º1¨®???¦Ì?¡ê?*/ \
	lwz     r0,  XSPEFSCR(r1);                                          \
	mtspr   SPEFSCR,r0

#endif/* VPORT_H_H */
