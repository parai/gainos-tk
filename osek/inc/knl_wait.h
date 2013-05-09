#ifndef KNL_WAIT_H_H
#define KNL_WAIT_H_H
#include "osek_os.h"

IMPORT WSPEC    knl_wspec_slp;

IMPORT void knl_make_non_wait( TCB *tcb );
IMPORT void knl_make_wait( TickType tmout);
IMPORT void knl_wait_release_ok( TCB *tcb );
IMPORT void knl_wait_release_tmout( TCB *tcb );
IMPORT void knl_wait_release_tmout( TCB *tcb );

#endif /* KNL_WAIT_H_H */