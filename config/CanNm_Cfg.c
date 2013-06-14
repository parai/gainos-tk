#include "CanNm.h"
#include "CanIf.h"
#include "Nm.h"

const CanNm_ChannelType  CanNm_Channels[] = {
    {  
        /* Active = */ TRUE,
        /* NmNetworkHandle = */ NM_CHANNEL0,
        /* NodeId= */ 0, // ?
        /* MainFunctionPeriod = */ 4,//eyi mi ga yi la?
        /* TimeoutTime = */ 1000,//ms
        /* RepeatMessageTime = */ 1000,
        /* WaitBusSleepTime = */ 1000,
        /* MessageCycleTime = */ 1000,
        /* MessageCycleOffsetTime = */ 100,
        /* CanIfPduId = */ CANIF_TX_vEcuC_Pdu_1,//?
        /* PduLength = */ 8,//?
        /* NidPosition = */ CANNM_PDU_BYTE_0,//?
        /* CbvPosition = */ CANNM_PDU_BYTE_1,//?
    },
};

const CanNm_ConfigType CanNm_Config = {
    /* CanNm_ChannelType* = */ CanNm_Channels
};    