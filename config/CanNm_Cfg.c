#include "CanNm.h"
#include "CanIf.h"
#include "Nm.h"

const CanNm_ChannelType  CanNm_Channels[] = {
    {  
        /* Active = */ TRUE,
        /* NmNetworkHandle = */ NM_CHANNEL0,
        /* NodeId= */ 0, // ?
        /* MainFunctionPeriod = */ 10,//eyi mi ga yi la?
        /* TimeoutTime = */ 10,//ms
        /* RepeatMessageTime = */ 10,
        /* WaitBusSleepTime = */ 10,
        /* MessageCycleTime = */ 10,
        /* MessageCycleOffsetTime = */ 10,
        /* CanIfPduId = */ CANIF_TX_vEcuC_Pdu_1,//?
        /* PduLength = */ 8,//?
        /* NidPosition = */ CANNM_PDU_BYTE_0,//?
        /* CbvPosition = */ CANNM_PDU_BYTE_1,//?
    },
};

const CanNm_ConfigType CanNm_Config = {
    /* CanNm_ChannelType* = */ CanNm_Channels
};    