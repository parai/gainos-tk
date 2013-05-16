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
	.extern knl_dispatch_disabled
	.extern knl_taskmode
	.extern knl_ctxtsk
	.extern knl_schedtsk

	cfgTMP_STACK_SZ .set  	1024	;system stack
	cfgTMP_USTK_SZ  .set  	128		;user stack
	SP_OFFSET 		.set 	4 		;sizeof(QUEUE)


;/*
; *    Function Name : disint
; *    Description   : Disable external interrupt,CPSR interrupt flag is in  disabled status.
; */

;EXPORT imask_t disint()
;{

;}

;/*
; *    Function Name : enaint
; *    Description   : Enable external interrupt (restore to original state),
; *                    Updates CPSR interrupt disabled flag with the intsts interrupt flag.
; */

;EXPORT void enaint(imask_t mask)
;{

;}


;EXPORT imask_t knl_getPRIMASK ( void )
;{

;}

; EXPORT void knl_force_dispatch(void)
;{

;}


; EXPORT void knl_dispatch_entry(void)
;{


l_dispatch0:

l_dispatch1:


l_dispatch2:

;}


