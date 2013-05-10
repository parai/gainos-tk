#ifndef VPORT_MACRO_H_H
#define VPORT_MACRO_H_H

#define cfgTMP_STACK_SZ 1024

#define PMK_D		(1UL << 15UL)      	/* EE Interrupt disable */
#define PMK_E		(0x00UL)     	    /* Interrupt enable */
/*
 * CPU interrupt control
 *	'intsts' is the value of PRIMASK in CPU
 *	disint()  Set PRIMASK = 1 and return the original PRIMASK
 *		  to the return value.
 *	enaint()  Set PRIMASK = intsts, Do not change except
 *		  for PRIMASK
 *		  Return the original PRIMASK to the return value.
 */
#define DI(intsts)	    ( (intsts) = disint() )
#define EI(intsts)	    ( (void)enaint(intsts) )
#define isDI(intsts)	( ((intsts) & PMK_D) == 0 )

/*
 * Start/End critical section
 */
#define BEGIN_CRITICAL_SECTION	{ imask_t _primask_ = disint()
#define END_CRITICAL_SECTION	if ( !isDI(_primask_)			\
				  && (knl_ctxtsk != knl_schedtsk)		        \
				  && !knl_isTaskIndependent()	            	\
				  && !knl_dispatch_disabled ) {		            \
					knl_dispatch();		                    	\
				}				                            	\
				enaint(_primask_); }

/*
 * Start/End interrupt disable section
 */
#define BEGIN_DISABLE_INTERRUPT	{ imask_t _primask_ = disint()
#define END_DISABLE_INTERRUPT	enaint(_primask_); }


/*
 * Interrupt enable/disable
 */
#define ENABLE_INTERRUPT	{ asm("wrteei 1"); }
#define DISABLE_INTERRUPT	{ asm("wrteei 0"); }

/*
 * Enable interrupt nesting
 *	Enable the interrupt that has a higher priority than 'level.'
 */
#define ENABLE_INTERRUPT_UPTO(level)	/* do nothing */

#define  knl_EnterTaskIndependent()	knl_taskindp++
#define  knl_LeaveTaskIndependent() knl_taskindp--
/*
 * Move to/Restore task independent part
 */
#define ENTER_TASK_INDEPENDENT	{ knl_EnterTaskIndependent(); }
#define LEAVE_TASK_INDEPENDENT	{ knl_LeaveTaskIndependent(); }

/* ----------------------------------------------------------------------- */
/*
 *	Check system state
 */
#define knl_isTaskIndependent() (( knl_taskindp > 0 )?TRUE:FALSE)
/*
 * When a system call is called from the task independent part, TRUE
 */
#define in_indp()	( knl_isTaskIndependent() || knl_ctxtsk == NULL )

/*
 * When a system call is called during dispatch disable, TRUE
 * Also include the task independent part as during dispatch disable.
 */
#define in_ddsp()	( knl_dispatch_disabled	\
			|| in_indp()		\
			|| isDI(knl_getPRIMASK()) )

/*
 * When a system call is called during CPU lock (interrupt disable), TRUE
 * Also include the task independent part as during CPU lock.
 */
#define in_loc()	( isDI(knl_getPRIMASK())		\
			|| in_indp() )

/*
 * When a system call is called during executing the quasi task part, TRUE
 * Valid only when in_indp() == FALSE because it is not discriminated from
 * the task independent part.
 */
#define in_qtsk()	( knl_ctxtsk->sysmode > knl_ctxtsk->isysmode )

/* ----------------------------------------------------------------------- */
/*
 *	Task dispatcher startup routine
 */

/*
 * Request for task dispatcher startup
 *	Do nothing at this point because there is no delayed
 *	interrupt function in ARM.
 *	Perform dispatcher startup with END_CRITICAL_SECTION.
 */
#define knl_dispatch_request()	/* */
#endif