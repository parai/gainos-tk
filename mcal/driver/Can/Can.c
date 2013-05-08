/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface.
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 *
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#include "Can.h"
#include "EcuM_Cbk.h"
#include "osek_os.h"
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(MICRO_TENUX_VERSION == 140)
#  include <libstr.h>
#else if(MICRO_TENUX_VERSION == 150)
#  include <string.h>
#endif

/* #################### IMPORTs ############################# */
IMPORT Can_GlobalType Can_Global;
IMPORT void Can_Hw_Init(const Can_ConfigType* Config);
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

