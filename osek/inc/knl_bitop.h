#ifndef	KNL_BITOP_H_H
#define KNL_BITOP_H_H

#include "Std_Types.h"

extern void knl_tstdlib_bitclr( VP base, INT offset );
extern void knl_tstdlib_bitset( VP base, INT offset );

extern INT  knl_tstdlib_bitsearch1( VP base, INT offset, INT width );                      

#endif  /* KNL_BITOP_H_H */
