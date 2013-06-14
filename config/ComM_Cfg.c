#include "ComM.h"
#include "Nm.h"

const ComM_ChannelType ComM_Channels[] = 
{
    {
        /* BusType = */  COMM_BUS_TYPE_CAN,
        /* BusSMNetworkHandle = */ 0,//?
        /* NmChannelHandle = */  NM_CHANNEL0,
        /* NmVariant = */ COMM_NM_VARIANT_FULL,
        /* MainFunctionPeriod = */ 10,
        /* LightTimeout = */ 10,
        /* Number = */ 0, //?? 
    }
};
const ComM_ChannelType* ComM_User0_ChannleList[] = 
{
    &ComM_Channels[0]
}; 
const ComM_UserType ComM_Users[] = 
{
    {   //User0
        /* ChannelList = */ ComM_User0_ChannleList,
        /* ChannelCount = */ 1
    } 
};
const ComM_ConfigType ComM_Cfg = 
{
    /* Channels = */ ComM_Channels,
    /* Users = */ ComM_Users
};