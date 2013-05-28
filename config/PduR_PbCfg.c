#include "PduR.h"

#if PDUR_CANIF_SUPPORT == STD_ON
#include "CanIf.h"
#endif
#if PDUR_CANTP_SUPPORT == STD_ON
#include "CanTp.h"
#endif
#if PDUR_LINIF_SUPPORT == STD_ON
#include "LinIf.h"
#endif
#if PDUR_COM_SUPPORT == STD_ON
#include "Com.h"
#endif
#if PDUR_DCM_SUPPORT == STD_ON
#include "Dcm.h"
#endif
#if PDUR_J1939TP_SUPPORT == STD_ON
#include "J1939Tp.h"
#endif
//Tp Buffers,not understand by parai
const PduRDestPdu_type vPduR_SrcPath0_PduRDestination[] = {
	{
		/* .DataProvision = */ PDUR_NO_PROVISION,
		/* .DestPduId = */ CANIF_TX_vEcuC_Pdu_1,
		/* .TxBufferRef = */ NULL,
		/* .DestModule = */ ARC_PDUR_CANIF
	},
};
const PduRDestPdu_type * const vPduR_SrcPath0_PduRDestinations[] = {
	&vPduR_SrcPath0_PduRDestination[0],/* vPduR_DestPath0 */
	NULL
};

const PduRDestPdu_type vPduR_SrcPath1_PduRDestination[] = {
	{
		/* .DataProvision = */ PDUR_NO_PROVISION,
		/* .DestPduId = */ COM_RX_vEcuC_Pdu_1,
		/* .TxBufferRef = */ NULL,
		/* .DestModule = */ ARC_PDUR_COM
	},
};
const PduRDestPdu_type * const vPduR_SrcPath1_PduRDestinations[] = {
	&vPduR_SrcPath1_PduRDestination[0],/* vPduR_DestPath0 */
	NULL
};

const PduRDestPdu_type vPduR_SrcPath2_PduRDestination[] = {
	{
		/* .DataProvision = */ PDUR_NO_PROVISION,
		/* .DestPduId = */ CANIF_TX_vEcuC_Pdu_0,
		/* .TxBufferRef = */ NULL,
		/* .DestModule = */ ARC_PDUR_CANIF
	},
};
const PduRDestPdu_type * const vPduR_SrcPath2_PduRDestinations[] = {
	&vPduR_SrcPath2_PduRDestination[0],/* vPduR_DestPath0 */
	NULL
};

const PduRDestPdu_type vPduR_SrcPath3_PduRDestination[] = {
	{
		/* .DataProvision = */ PDUR_NO_PROVISION,
		/* .DestPduId = */ COM_RX_vEcuC_Pdu_0,
		/* .TxBufferRef = */ NULL,
		/* .DestModule = */ ARC_PDUR_COM
	},
};
const PduRDestPdu_type * const vPduR_SrcPath3_PduRDestinations[] = {
	&vPduR_SrcPath3_PduRDestination[0],/* vPduR_DestPath0 */
	NULL
};

const PduRRoutingPath_type vPduR_SrcPath0_PduRRoutingPath = {
	/* .SduLength = */ 8,
	/* .TpChunkSize = */0xDEAD,
	/* .PduRDefaultValue = */{0xDB,NULL},
	/* .SrcPduId = */ COM_TX_vEcuC_Pdu_1,
	/* .SrcModule =  */ARC_PDUR_COM,
	/* .PduRDestPdus = */ vPduR_SrcPath0_PduRDestinations
};
const PduRRoutingPath_type vPduR_SrcPath1_PduRRoutingPath = {
	/* .SduLength = */ 8,
	/* .TpChunkSize = */0xDEAD,
	/* .PduRDefaultValue = */{0xDB,NULL},
	/* .SrcPduId = */ CANIF_RX_vEcuC_Pdu_1,
	/* .SrcModule =  */ARC_PDUR_CANIF,
	/* .PduRDestPdus = */ vPduR_SrcPath1_PduRDestinations
};
const PduRRoutingPath_type vPduR_SrcPath2_PduRRoutingPath = {
	/* .SduLength = */ 8,
	/* .TpChunkSize = */0xDEAD,
	/* .PduRDefaultValue = */{0xDB,NULL},
	/* .SrcPduId = */ COM_TX_vEcuC_Pdu_0,
	/* .SrcModule =  */ARC_PDUR_COM,
	/* .PduRDestPdus = */ vPduR_SrcPath2_PduRDestinations
};
const PduRRoutingPath_type vPduR_SrcPath3_PduRRoutingPath = {
	/* .SduLength = */ 8,
	/* .TpChunkSize = */0xDEAD,
	/* .PduRDefaultValue = */{0xDB,NULL},
	/* .SrcPduId = */ CANIF_RX_vEcuC_Pdu_0,
	/* .SrcModule =  */ARC_PDUR_CANIF,
	/* .PduRDestPdus = */ vPduR_SrcPath3_PduRDestinations
};
const PduRRoutingPath_type * const PduRRoutingPaths[] = { 
	&vPduR_SrcPath0_PduRRoutingPath,
	&vPduR_SrcPath1_PduRRoutingPath,
	&vPduR_SrcPath2_PduRRoutingPath,
	&vPduR_SrcPath3_PduRRoutingPath,
	NULL
};

const PduR_PBConfigType PduR_Config = {
	/* .PduRConfigurationId = */ 0,
	/* .NRoutingPaths = */ 4,
	/* .RoutingPaths = */ PduRRoutingPaths,
	/* .TpBuffers = */ NULL,
	/* .TpRouteBuffers = */ NULL
};

