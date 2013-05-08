#include "osek_os.h"

#define INVALID_EVENT UINT_MAX
#define NO_EVENT     0u

/*
 * Event flag control block
 */
typedef struct event_control_block {
	EventMaskType	            flgptn;		    /* Event flag current pattern */
    EventMaskType               waipth;         /* Event flag wait pattern */
} FLGCB;

IMPORT FLGCB knl_flgcb_table[];

IMPORT void knl_entflg_init(void);