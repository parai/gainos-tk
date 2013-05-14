
#ifndef DCM_CFG_H_
#define DCM_CFG_H_
/*
 * DCM General
 */
#define DCM_VERSION_INFO_API    		STD_ON		// Activate/Deactivate ver info API.
#define DCM_DEV_ERROR_DETECT			STD_ON		// Activate/Deactivate Dev Error Detection and Notification.
#define DCM_REQUEST_INDICATION_ENABLED	STD_ON		// Activate/Deactivate indication request mechanism.
#define DCM_RESPOND_ALL_REQUEST			STD_ON		// Activate/Deactivate response on SID 0x40-0x7f and 0xc0-0xff.
#define DCM_TASK_TIME					TBD			// Time for periodic task (in ms).
#define DCM_PAGEDBUFFER_ENABLED			STD_OFF		// Enable/disable page buffer mechanism (currently only disabled supported)

#define DCM_DSL_RX_PDU_ID_LIST_LENGTH 1
#define DCM_DSL_TX_PDU_ID_LIST_LENGTH 1

#define DCM_MAIN_FUNCTION_PERIOD_TIME_MS 4 /* ms */
#endif /*DCM_CFG_H_*/
