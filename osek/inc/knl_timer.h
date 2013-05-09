#ifndef KNL_TIMER_H_H
#define KNL_TIMER_H_H

#include "knl_task.h"

IMPORT WSPEC    knl_wspec_slp;
IMPORT LSYSTIM  knl_current_time;
IMPORT QUEUE	knl_timer_queue;

IMPORT void knl_wait_release_tmout( TCB *tcb );
IMPORT void knl_timer_insert( TMEB *evt, TickType tmout, CBACK cback, VP arg );
IMPORT void knl_timer_handler( void );


#endif /* KNL_TIMER_H_H */