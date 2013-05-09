#ifndef KNL_EVENT_H_H
#define KNL_EVENT_H_H
#include "osek_os.h"

#define INVALID_EVENT UINT_MAX
#define NO_EVENT     0u

IMPORT FLGCB knl_flgcb_table[];

IMPORT void knl_entflg_init(void);

#endif /* KNL_EVENT_H_H*/
