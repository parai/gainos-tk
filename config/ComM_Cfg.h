#ifndef COMM_CFG_H_H_H
#define COMM_CFG_H_H_H

//#include "ComM_ConfigTypes.h"

#define COMM_VERSION_INFO_API STD_ON
#define COMM_DEV_ERROR_DETECT STD_ON
#define COMM_NO_COM STD_ON
#define COMM_MODE_LIMITATION_ENABLED STD_ON

#define COMM_T_MIN_FULL_COM_MODE_DURATION 100

#define COMM_CHANNEL_COUNT 1

#define COMM_CHANNEL0 0

typedef enum
{
    COMM_USER0 = 0,
    COMM_USER_COUNT
}ComM_UserHandleType;

extern const ComM_ConfigType ComM_Cfg;
#endif /* COMM_CFG_H_H_H */


