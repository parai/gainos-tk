#include "Nm.h"
#include "CanNm.h"
#include "ComM.h"

const Nm_ChannelType Nm_Channels[] = 
{
    {
        /* BusType = */ NM_BUSNM_CANNM,
	    /* BusNmNetworkHandle = */ vCanNm_Channel_0,
	    /* ComMNetworkHandle = */  COMM_CHANNEL0
    }  
};

const Nm_ConfigType Nm_Config = 
{
    /* Channels = */ Nm_Channels
};