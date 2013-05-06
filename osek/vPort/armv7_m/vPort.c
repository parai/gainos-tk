#include "vPort.h"

EXPORT 	UB	knl_tmp_stack[cfgTMP_STACK_SZ];

EXPORT void knl_system_clock_init(void)
{

}

EXPORT void knl_start_hw_timer( void )
{
}
EXPORT void knl_setup_context( TCB *tcb )
{
    UW pc, xpsr;
    SStackFrame *ssp;

    ID tskid = tcb - knl_tcb_table;
    ssp = knl_gtsk_table[tskid].isstack;
    ssp--;

	pc = (UW)knl_gtsk_table[tskid].task;
	xpsr = TS_PSR_T;                             /* Thumb mode */

    /* CPU context initialization */
    ssp->taskmode  = 0;                          /* Initial taskmode */
    ssp->xpsr = xpsr;                            /* Initial SR */
    ssp->pc = (VP)pc;                            /* Task startup address */
    tcb->tskctxb.ssp = ssp;                      /* System stack */ 
}

