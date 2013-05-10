
#ifndef PDUR_PB_CFG_H_H
#define PDUR_PB_CFG_H_H
#if !(((PDUR_SW_MAJOR_VERSION == 2) && (PDUR_SW_MINOR_VERSION == 0)) )
#error PduR: Configuration file expected BSW module version to be 2.0.*
#endif


#if defined(USE_DCM)
#include "Dcm.h"
#endif
#if defined(USE_COM)
#include "Com.h"
#endif
#if defined(USE_CANIF)
#include "CanIf.h"
#endif
#if defined(USE_CANTP)
#include "CanTp.h"
#endif

extern const PduR_PBConfigType PduR_Config;
//  PduR Polite Defines.
/* PduR Rx NSdu Id */
#define PDUR_RX_vEcuC_Pdu1 0
#define vPduR_SrcPath_0 0
#define PDUR_RX_vEcuC_Pdu2 2
#define vPduR_SrcPath_2 2
/* PduR Tx NSdu Id */
#define PDUR_TX_vEcuC_Pdu1 1
#define vPduR_SrcPath_1 1
#define PDUR_TX_vEcuC_Pdu2 3
#define vPduR_SrcPath_3 3
#endif /* PDUR_PB_CFG_H_H */

