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
	.extern _knl_dispatch_disabled
	.extern _knl_taskmode
	.extern _knl_ctxtsk
	.extern _knl_schedtsk

	cfgTMP_STACK_SZ .set  1024
	SP_OFFSET .set 4 ;sizeof(QUEUE)

	near_TaskStackvTaskInit	.section	near, clear, cluster 'knl_tmp_stack', new
_knl_tmp_stack	.label	nearword
	.ds	cfgTMP_STACK_SZ

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
	;/* Set temporal stack */
	movw r15,#_knl_tmp_stack+cfgTMP_STACK_SZ
	movw SP,r15

	movw r14,#1
	movw r15,#_knl_dispatch_disabled
	movw [r15],r14	;/* Dispatch disable */

	movw r15,_knl_ctxtsk
	movw [r15],ZEROS	; knl_ctxtsk = NULL

	BCLR PSW_IEN	; Disable Interrupt
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

	movw r14,#1
	movw r15,#_knl_dispatch_disabled
	movw [r15],r14	;/* Dispatch disable */

	push r13
	push r12
	push r11
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
	movw [r0+#SP_OFFSET],r1

l_dispatch0:
	movw r15,#_knl_schedtsk

l_dispatch1:
	BCLR PSW_IEN	; Disable Interrupt
	movw r14,[r15]
	cmpw r14,#0
	jmp cc_nz,l_dispatch2	;knl_schedtsk == NULL
	BSET PSW_IEN	; Enable Interrupt
	nop
	nop
	nop
	jmp l_dispatch1

l_dispatch2:
	movw r13,#_knl_ctxtsk
	movw [r13],r14		;knl_ctxtsk=knl_schedtsk
	; restore SP
	movw r15,[r14+#SP_OFFSET]
	movw SP,r15

	; restore context
	pop  r14
	movw r15,#_knl_taskmode
	movw [r15],r14

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

	movw r15,#_knl_dispatch_disabled
	movw [r15],ZEROS

	pop r15
	pop MDH
	pop MDL
	reti
;}


