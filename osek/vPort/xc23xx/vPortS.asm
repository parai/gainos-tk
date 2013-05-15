	.extern _knl_dispatch_disabled
	.extern _knl_taskmode
	.extern _knl_ctxtsk
	.extern _knl_schedtsk

	cfgTMP_STACK_SZ .set  1024

	near_TaskStackvTaskInit	.section	near, clear, cluster 'knl_tmp_stack', new
_knl_tmp_stack	.label	nearword
	.ds	cfgTMP_STACK_SZ

;; void knl_force_dispatch(void)
code_knl_force_dispatch	.section	code, cluster 'knl_force_dispatch', new
	.global	_knl_force_dispatch
_knl_force_dispatch .proc far
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

;; void knl_dispatch_entry(void)
code_knl_dispatch_entry	.section	code, cluster 'knl_dispatch_entry', new
	.global	_knl_dispatch_entry
_knl_dispatch_entry	.proc	intno knl_dispatch_entry_trap = 1
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
	movw [r0+#0x04],r1

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
	movw r15,[r14+#4]
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


