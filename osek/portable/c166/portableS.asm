;/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
; *
; * This program is open source software; developer can redistribute it and/or
; * modify it under the terms of the U-License as published by the T-Engine China
; * Open Source Society; either version 1 of the License, or (at developer option)
; * any later Version.
; *
; * This program is distributed in the hope that it will be useful,but WITHOUT ANY
; * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
; * A PARTICULAR PURPOSE. See the U-License for more details.
; * Developer should have received a copy of the U-Licensealong with this program;
; * if not, download from www.tecoss.org(the web page of the T-Engine China Open
; * Source Society).
; *
; * GaInOS-TK is a static configured RTOS, which conformed to OSEK OS 2.2.3 Specification
; * and it is based on uTenux(http://www.uloong.cc).
; *
; * Email: parai@foxmail.com
; * Sourrce Open At: https://github.com/parai/gainos-tk/
; */

;/*
; * This vPort is For TASKING VX-toolset C166.
; * Run OK on XC2300 family chip.
; */
	.extern _knl_dispatch_disabled
	.extern _knl_taskmode
	.extern _knl_ctxtsk
	.extern _knl_schedtsk
	.extern	__icall : far
	.extern _knl_activate_rr

	cfgTMP_STACK_SZ .set  	1024	;system stack
	cfgTMP_USTK_SZ  .set  	128		;user stack
	SSP_OFFSET 		.set 	4 		;sizeof(QUEUE)               ->  ssp
	USP_OFFSET 		.set 	6		;sizeof(QUEUE) +sizeof(VP)   ->  usp
	DSP_OFFSET 		.set 	8		;sizeof(QUEUE) +sizeof(VP)*2 ->  dispatcher
	TSK_OFFSET      .set    12		;  -> tcb->task

	near_knl_tmp_stack	.section	near, clear, cluster 'knl_tmp_stack', new
_knl_tmp_stack	.label	nearword
	.ds	cfgTMP_STACK_SZ
	near_knl_tmp_ustk	.section	near, clear, cluster 'knl_tmp_ustk', new
_knl_tmp_ustk	.label	nearword
	.ds	cfgTMP_USTK_SZ

;/*
; *    Function Name : disint
; *    Description   : Disable external interrupt,CPSR interrupt flag is in  disabled status.
; */
code_disint	.section	code, cluster 'disint', new
	.global	_disint
_disint .proc far
;EXPORT imask_t disint()
;{
	movw r2,PSW
	BCLR PSW_IEN
	ret
;}

;/*
; *    Function Name : enaint
; *    Description   : Enable external interrupt (restore to original state),
; *                    Updates CPSR interrupt disabled flag with the intsts interrupt flag.
; */
code_enaint	.section	code, cluster 'enaint', new
	.global	_enaint
_enaint .proc far
;EXPORT void enaint(imask_t mask)
;{
	movw PSW,r2
	ret
;}

code_knl_getPRIMASK	.section	code, cluster 'knl_getPRIMASK', new
	.global	_knl_getPRIMASK
_knl_getPRIMASK .proc far
;EXPORT imask_t knl_getPRIMASK ( void )
;{
	movw r2,PSW
	ret
;}


code_knl_force_dispatch	.section	code, cluster 'knl_force_dispatch', new
	.global	_knl_force_dispatch
; EXPORT void knl_force_dispatch(void)
_knl_force_dispatch .proc far
;{
	BCLR PSW_IEN	; Disable Interrupt
	;/* Set temporal System stack */
	movw r14,#_knl_tmp_stack+cfgTMP_STACK_SZ
	movw SP,r14

	;/* Set temporal User stack */
	movw r15,#_knl_tmp_ustk+cfgTMP_USTK_SZ


	movw r11,#1
	movw r12,#_knl_dispatch_disabled
	movw [r12],r11	;/* Dispatch disable */

	movw r11,#_knl_ctxtsk
	movw [r11],ZEROS	; knl_ctxtsk = NULL

	jmp l_dispatch0
;}

code_knl_dispatch_entry	.section	code, cluster 'knl_dispatch_entry', new
	.global	_knl_dispatch_entry
; EXPORT void knl_dispatch_entry(void)
_knl_dispatch_entry	.proc	intno knl_dispatch_entry_trap = 1
;{
	push MDL
	push MDH

	push r15
	push r14
	push r13
	push r12
	push r11

	movw r11,#1
	movw r12,#_knl_dispatch_disabled
	movw [r12],r11	;/* Dispatch disable */

	push r10
	push r9
	push r8
	push r7
	push r6
	push r5
	push r4
	push r3
	push r2
	push r1
	push r0
	; /* save knl_taskmode */
	movw r0,_knl_taskmode
	push r0

	; /* save SP */
	movw r0,_knl_ctxtsk
	movw r1,SP
	movw [r0+#SSP_OFFSET],r1

	; knl_ctxtsk->tskctxb.dispatcher = 0;
	movw	r1,ZEROS
	movw	[r0+#DSP_OFFSET],r1

	movw r11,#_knl_ctxtsk
	movw [r11],ZEROS	; knl_ctxtsk = NULL

l_dispatch0:

l_dispatch1:
	BCLR PSW_IEN	; Disable Interrupt
	movw r11,_knl_schedtsk
	cmpw r11,#0
	jmp cc_nz,l_dispatch2	;knl_schedtsk == NULL
	BSET PSW_IEN	; Enable Interrupt
	nop
	nop
	nop
	jmp l_dispatch1

l_dispatch2:
	movw r12,#_knl_ctxtsk
	movw [r12],r11		;knl_ctxtsk=knl_schedtsk
	; restore SP
	movw r12,[r11+#SSP_OFFSET]
	movw SP,r12

	movw r12,#_knl_dispatch_disabled
	movw [r12],ZEROS	;/* Dispatch enable */

	movw r12,[r11+#DSP_OFFSET]   ;r12 = knl_ctxtsk->dispatcher

	cmpw r12,#1
; if(knl_ctxtsk->dispatcher = 1)
;{
	jmp cc_nz,knl_dispatch_r
knl_activate_r:
	; restore user sp
	movw r15,[r11+#USP_OFFSET]
	jmp _knl_activate_rr
;}else
;{
knl_dispatch_r:
	; restore context
	pop  r11
	movw r12,#_knl_taskmode
	movw [r12],r11
	pop r0
	pop r1
	pop r2
	pop r3
	pop r4
	pop r5
	pop r6
	pop r7
	pop r8
	pop r9
	pop r10
	pop r11
	pop r12
	pop r13
	pop r14
	pop r15
	pop MDH
	pop MDL
	reti
;}

;}


