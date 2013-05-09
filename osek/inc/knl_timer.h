#ifndef KNL_TIMER_H_H
#define KNL_TIMER_H_H

#include "osek_os.h"

IMPORT LSYSTIM  knl_current_time;
IMPORT QUEUE	knl_timer_queue;


IMPORT void knl_timer_insert( TMEB *evt, TickType tmout, CBACK cback, VP arg );
IMPORT void knl_timer_handler( void );
IMPORT void knl_timer_init(void);


#endif /* KNL_TIMER_H_H */