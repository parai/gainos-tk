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
#ifndef _CAN_H_H
#define _CAN_H_H
#define CAN_VENDOR_ID			    1
#define CAN_MODULE_ID			    MODULE_ID_CAN
#define CAN_AR_MAJOR_VERSION  2
#define CAN_AR_MINOR_VERSION 	2
#define CAN_AR_PATCH_VERSION	2

#define CAN_SW_MAJOR_VERSION	1
#define CAN_SW_MINOR_VERSION 	0
#define CAN_SW_PATCH_VERSION	0
/* ##############################  INCLUDEs  ############################## */
#include "ComStack_Types.h"
#include "Can_Types.h"
#include "CanIf_Types.h"
#include "Can_Hw.h"
#include "Can_Cfg.h"
/* ##############################  TYPEs  ############################## */
/* Type for holding information about each controller */
typedef struct {
  CanIf_ControllerModeType state;
  UINT		lock_cnt;

  /* Statistics */
  Can_StatisticsType stats;

  /* Data stored for Txconfirmation callbacks to CanIf */
  PduIdType swPduHandle;
} Can_UnitType;

// Mapping between HRH and Controller//HOH
typedef struct Can_ObjectHOHMapStruct
{
  Can_ControllerIdType CanControllerRef;    // Reference to controller
  const Can_HardwareObjectType* CanHOHRef;       // Reference to HOH.
} Can_ObjectHOHMapType;

typedef struct{
	Can_DriverStateType driverState;
	const Can_ConfigType* config;
	Can_UnitType canUnit[CAN_CONTROLLER_CNT];
	/* One bit for each channel that is configured.
	Used to determine if validity of a channel
	1 - configured
	0 - NOT configured*/
	UINT  configured;
	/* Maps the channel id to a configured channel id */
	uint8   channelMap[CAN_CONTROLLER_CNT];

	/* This is a map that maps the HTHs with the controller and Hoh. It is built
	during Can_Init and is used to make things faster during a transmit. */
	Can_ObjectHOHMapType CanHTHMap[NUM_OF_HTHS];
}Can_GlobalType;


/* ##############################  MACROs  ############################## */
#define CAN_E_PARAM_POINTER     0x01
#define CAN_E_PARAM_HANDLE      0x02
#define CAN_E_PARAM_DLC     	0x03
#define CAN_E_PARAM_CONTROLLER  0x04
/* API service used without initialization */
#define CAN_E_UNINIT            0x05
/* Init transition for current mode */
#define CAN_E_TRANSITION        0x06

#define CAN_E_DATALOST          0x07     /** @req 4.0/CAN395 */

/** name Service id's */
#define CAN_INIT_SERVICE_ID                         0x00
#define CAN_MAINFUNCTION_WRITE_SERVICE_ID           0x01
#define CAN_INITCONTROLLER_SERVICE_ID               0x02
#define CAN_SETCONTROLLERMODE_SERVICE_ID            0x03
#define CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID  0x04
#define CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID   0x05
#define CAN_WRITE_SERVICE_ID                        0x06
#define CAN_GETVERSIONINFO_SERVICE_ID               0x07
#define CAN_MAINFUNCTION_READ_SERVICE_ID            0x08
#define CAN_MAINFUNCTION_BUSOFF_SERVICE_ID          0x09
#define CAN_MAINFUNCTION_WAKEUP_SERVICE_ID          0x0a
#define CAN_CBK_CHECKWAKEUP_SERVICE_ID              0x0b
#define CAN_MAINFUNCTION_MODE_SERVICE_ID            0x0c
/* #################### MACROs ############################# */
#define CAN_GET_CONTROLLER_CONFIG(_controller)	\
        					&Can_Global.config->CanConfigSet->CanController[(_controller)]

#define CAN_GET_PRIVATE_DATA(_controller) \
									&Can_Global.canUnit[_controller]
/* ##############################  FUNCTIONs  ############################## */
IMPORT void Can_Init(const Can_ConfigType* Config);
IMPORT void Can_DeInit();
IMPORT void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);
IMPORT void Can_InitController(uint8 Controller,const Can_ControllerConfigType* Config);
IMPORT Can_ReturnType Can_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition);
IMPORT void Can_EnableControllerInterrupts(uint8 Controller);
IMPORT void Can_DisableControllerInterrupts(uint8 Controller);
IMPORT Can_ReturnType Can_CheckWakeup(uint8 Controller);
IMPORT Can_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo);
#endif /* _CAN_H_H */
