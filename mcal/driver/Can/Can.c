/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.                                           
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

/* Modified && Ported by parai to integrated with GaInOS,which is an open source 
 * AUTOSAR OS based on uTenux(tkernel). 
 * And re-construct a GUI tool named gainos-studio,which is based on python and Qt4.8,
 * for the whole Com Architecture of ArCore.
 * URL:      https://github.com/parai
 * Email:    parai@foxmail.com
 * Name:     parai(Wang Fan)
 * from Date:2013-04-08 to $Date: 2013-04-13 13:51:22 $
 * $Revision: 1.1 $
 */
#include "Can.h"
#include "EcuM_Cbk.h"
#include "osek_os.h"
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include <string.h>


/* #################### IMPORTs ############################# */
IMPORT Can_GlobalType Can_Global;
IMPORT void Can_Hw_Init(const Can_ConfigType* Config);;
IMPORT Can_ReturnType Can_Hw_Write( Can_HwHandleType/* Can_HTHType */ hth, const Can_PduType *pduInfo );
IMPORT Std_ReturnType Can_Hw_InitController(uint8 Controller,const Can_ControllerConfigType* Config);
IMPORT Can_ReturnType Can_Hw_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition);
IMPORT void Can_Hw_DisableControllerInterrupts(uint8 Controller);
IMPORT void Can_Hw_EnableControllerInterrupts( uint8 Controller );

/* ####################### FUNCTIONs ########################### */
EXPORT void Can_Init(const Can_ConfigType* Config)
{
	  Can_UnitType *canUnit;
	  const Can_ControllerConfigType *canHwConfig;
	  const Can_HardwareObjectType* hoh;
	  uint8 ctlrId;
	  int configId;
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT != Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INIT_SERVICE_ID,CAN_E_TRANSITION);
		return;
	}
	if(NULL == Config)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INIT_SERVICE_ID,CAN_E_PARAM_POINTER);
		return;
	}
#endif
	/* save config */
	Can_Global.config = Config;
	Can_Global.driverState = CAN_READY;

	Can_Hw_Init(Config);

	for (configId=0; configId < CAN_CTRL_CONFIG_CNT; configId++)
	{
		canHwConfig = CAN_GET_CONTROLLER_CONFIG(configId);
		ctlrId = canHwConfig->CanControllerId;

		// Assign the configuration channel used later..
		Can_Global.channelMap[ctlrId] = configId;
		Can_Global.configured |= (1<<ctlrId);

		canUnit = CAN_GET_PRIVATE_DATA(ctlrId);
		canUnit->state = CANIF_CS_STOPPED;

		canUnit->lock_cnt = 0;

		// Clear stats
		memset(&canUnit->stats, 0, sizeof(Can_StatisticsType));
		//This can be done by CanIf
	    //Can_InitController(ctlrId, canHwConfig);

	    // Loop through all Hohs and map them into the HTHMap
	    hoh = canHwConfig->Can_Hoh;
	    hoh--;
		do
		{
		    hoh++;
			if (hoh->CanObjectType == CAN_OBJECT_TYPE_TRANSMIT)
			{
				Can_Global.CanHTHMap[hoh->CanObjectId].CanControllerRef = canHwConfig->CanControllerId;
				Can_Global.CanHTHMap[hoh->CanObjectId].CanHOHRef = hoh;
			}
		} while (!hoh->Can_EOL);
	}
}

// Unitialize the module
EXPORT void Can_DeInit()
{
  Can_UnitType *canUnit;
  int configId;
  const Can_ControllerConfigType *canHwConfig;
  uint32 ctlrId;

  for (configId=0; configId < CAN_CTRL_CONFIG_CNT; configId++) {
    canHwConfig = CAN_GET_CONTROLLER_CONFIG(configId);
    ctlrId = canHwConfig->CanControllerId;

    canUnit = CAN_GET_PRIVATE_DATA(ctlrId);
    canUnit->state = CANIF_CS_UNINIT;

    Can_DisableControllerInterrupts(ctlrId);

    canUnit->lock_cnt = 0;

    // Clear stats
    memset(&canUnit->stats, 0, sizeof(Can_StatisticsType));
  }

  Can_Global.config = NULL;
  Can_Global.driverState = CAN_UNINIT;

  return;
}


#if(CAN_VERSION_INFO_API == STD_ON )
EXPORT void Can_GetVersionInfo(Std_VersionInfoType* versioninfo )
{
	STD_GET_VERSION_INFO(versioninfo,CAN);
}
#endif

EXPORT void Can_InitController(uint8 Controller,const Can_ControllerConfigType* Config)
{
	Can_UnitType *canUnit;
	StatusType ercd;
	canUnit = CAN_GET_PRIVATE_DATA(Controller);
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INITCONTROLLER_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
	if(NULL == Config)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INITCONTROLLER_SERVICE_ID,CAN_E_PARAM_POINTER);
		return;
	}
	if(Controller >= CAN_CONTROLLER_CNT)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INITCONTROLLER_SERVICE_ID,CAN_E_PARAM_CONTROLLER);
		return;
	}
	if(canUnit->state!=CANIF_CS_STOPPED)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_INITCONTROLLER_SERVICE_ID,CAN_E_TRANSITION);
		return;
	}
#endif
	ercd = Can_Hw_InitController(Controller,Config);
	if(ercd != E_OK)
	{
		return;
	}
	canUnit->state = CANIF_CS_STOPPED;
	Can_EnableControllerInterrupts(Controller);
}

EXPORT Can_ReturnType Can_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_SETCONTROLLERMODE_SERVICE_ID,CAN_E_UNINIT);
		return CAN_NOT_OK;
	}
	if(Controller >= CAN_CONTROLLER_CNT)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_SETCONTROLLERMODE_SERVICE_ID,CAN_E_PARAM_CONTROLLER);
		return CAN_NOT_OK;
	}
#endif
	return Can_Hw_SetControllerMode(Controller,Transition);
}
EXPORT void Can_DisableControllerInterrupts(uint8 Controller)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
	if(Controller >= CAN_CONTROLLER_CNT)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID,CAN_E_PARAM_CONTROLLER);
		return;
	}
#endif
	Can_Hw_DisableControllerInterrupts(Controller);
}

EXPORT void Can_EnableControllerInterrupts(uint8 Controller)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
	Can_Hw_EnableControllerInterrupts(Controller);
}

EXPORT Can_ReturnType Can_CheckWakeup(uint8 Controller)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_CBK_CHECKWAKEUP_SERVICE_ID,CAN_E_UNINIT);
		return CAN_NOT_OK;
	}
#endif
    /* not supported */
    return CAN_NOT_OK;
}

EXPORT Can_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_WRITE_SERVICE_ID,CAN_E_UNINIT);
		return CAN_NOT_OK;
	}
	if(NULL == PduInfo)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_WRITE_SERVICE_ID,CAN_E_PARAM_POINTER);
		return CAN_NOT_OK;
	}	  
  	if(PduInfo->length > 8)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_WRITE_SERVICE_ID,CAN_E_PARAM_DLC);
		return CAN_NOT_OK;
	}
    if(Hth >= NUM_OF_HTHS)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_WRITE_SERVICE_ID,CAN_E_PARAM_HANDLE);
		return CAN_NOT_OK;
	}
#endif
    return Can_Hw_Write(Hth,PduInfo);
}

EXPORT void Can_MainFunction_Write(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_WRITE_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_Read(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_READ_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_BusOff(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_BUSOFF_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_WakeUp(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_WAKEUP_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}
EXPORT void Can_MainFunction_Mode(void)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
	if(CAN_UNINIT == Can_Global.driverState)
	{
		Det_ReportError(MODULE_ID_CAN,0,CAN_MAINFUNCTION_MODE_SERVICE_ID,CAN_E_UNINIT);
		return;
	}
#endif
}

