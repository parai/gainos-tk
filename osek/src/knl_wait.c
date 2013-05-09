#include "knl_wait.h"
#include "knl_task.h"
#include "knl_queue.h"

EXPORT WSPEC    knl_wspec_slp = { TTW_SLP,NULL,NULL};
/*
 * Change the active task state to wait state and connect to the
 * timer event queue.
 *	Normally, 'knl_ctxtsk' is in the RUN state, but when an interrupt
 *	occurs during executing system call, 'knl_ctxtsk' may become the
 *	other state by system call called in the interrupt handler.
 *	However, it does not be in WAIT state.
 *
 *	"include/tk/typedef.h"
 *	typedef	W		TMO;
 *	typedef UW		RELTIM;
 *	#define TMO_FEVR	(-1)
 */
EXPORT void knl_make_wait( TickType tmout)
{
	switch ( knl_ctxtsk->state ) {
	  case TS_READY:
		knl_make_non_ready(knl_ctxtsk);
		knl_ctxtsk->state = TS_WAIT;
		break;
	  case TS_SUSPEND:
		knl_ctxtsk->state = TS_WAITSUS;
		break;
	}
	knl_timer_insert(&knl_ctxtsk->wtmeb, tmout,(CBACK)knl_wait_release_tmout, knl_ctxtsk);
}

EXPORT void knl_wait_release( TCB *tcb )
{
	knl_timer_delete(&tcb->wtmeb);
	QueRemove(&tcb->tskque);
	knl_make_non_wait(tcb);
}

EXPORT void knl_wait_release_ok( TCB *tcb )
{
	knl_wait_release(tcb);
	*tcb->wercd = E_OK;
}

EXPORT void knl_wait_release_tmout( TCB *tcb )
{
	QueRemove(&tcb->tskque);
	knl_make_non_wait(tcb);
    if ( tcb->wspec->rel_wai_hook != NULL ) {
		(*tcb->wspec->rel_wai_hook)(tcb);
	}
}

/*
 * Update the task state to release wait. When it becomes ready state,
 * connect to the ready queue.
 * Call when the task is in the wait state (including double wait).
 */
EXPORT void knl_make_non_wait( TCB *tcb )
{
	if ( tcb->state == TS_WAIT ) {
		knl_make_ready(tcb);
	} else {
		tcb->state = TS_SUSPEND;
	}
}
