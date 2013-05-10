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
#ifndef CAN_HW_H_
#define CAN_HW_H_
#include "Can_Types.h"
/* Use Hardware buffers or not,not fully implemented. be carefully.
 * A Hth has three hardware Tx buffers.But I don't know how to use the 3 Tx buffers
 * among different PduId handler.So the rule below was used to simply implement it:
 * When a PduId AAA send a frame though Hth0 and not finished, then PduId BBB also want to
 * send a frame through Hth0,then it's not allowed.but if any of the 3 Tx buffers of Hth0
 * is empty,then PduId AAA can use Hth0,So PduId AAA can send messages consecutively.
 * PduId BBB can start to use Hth0 only when all of the 3 Tx buffers is empty.*/
#define CAN_USE_HW_BUFFER STD_ON
typedef enum {
	CAN_CTRL_1 = 0,
	CAN_CTRL_2 = 1,
	CAN_CONTROLLER_CNT = 2
}Can_ControllerIdType;
/** Start mc9s12 unique */
typedef enum {
  CAN_IDAM_2_32BIT = 0,
  CAN_IDAM_4_16BIT = 1,
  CAN_IDAM_8_8BIT  = 2,
  CAN_IDAM_FILTER_CLOSED = 3,
} Can_IDAMType;

typedef struct
{
	uint8 idmr[8]; /* Identifier Mask Register, 1 = ignore corresponding acceptance code register bit*/
	uint8 idar[8]; /* Identifier Acceptance Register*/
	Can_IDAMType idam;
} Can_FilterMaskType;

typedef struct Can_HardwareObjectStruct {
	/** Specifies the type (Full-CAN or Basic-CAN) of a hardware object.*/
	Can_Arc_HohType CanHandleType;

	/** Specifies whether the IdValue is of type - standard identifier - extended
	identifier - mixed mode ImplementationType: Can_IdType*/
	Can_IdTypeType CanIdType;

	/**	Specifies (together with the filter mask) the identifiers range that passes
	the hardware filter.*/
	uint32 CanIdValue;

	/**	Holds the handle ID of HRH or HTH. The value of this parameter is unique
	in a given CAN Driver, and it should start with 0 and continue without any
	gaps. The HRH and HTH Ids are defined under two different name-spaces.
	Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3.*/
	uint16 CanObjectId;

	/** Specifies if the HardwareObject is used as Transmit or as Receive object*/
	Can_ObjectTypeType CanObjectType;

	/** Reference to the filter mask that is used for hardware filtering togerther
	with the CAN_ID_VALUE*/
	const Can_FilterMaskType *CanFilterMaskRef;

	/** A "1" in this mask tells the driver that that HW Message Box should be
	occupied by this Hoh. A "1" in bit 31(ppc) occupies Mb 0 in HW.*/
	uint32 Can_MbMask;

	/** End Of List. Set to TRUE is this is the last object in the list.*/
	boolean Can_EOL;
} Can_HardwareObjectType;

typedef struct
{
	/** Enables / disables API Can_MainFunction_BusOff() for
	handling busoff events in polling mode. */
	//Can_ProcessType CanBusoffProcessing;
	/** Defines if a CAN controller is used in the configuration. */
	//boolean         CanControllerActivation;
	/** This parameter provides the controller ID which is unique in a
	given CAN Driver. The value for this parameter starts with 0 and
	continue without any gaps. */
	Can_ControllerIdType  CanControllerId;
	/** Enables / disables API Can_MainFunction_Read() for
	handling PDU reception events in polling mode. */
	Can_ProcessType CanRxProcessing;
	/** Enables / disables API Can_MainFunction_Write() for
	handling PDU transmission events in polling mode.  */
	Can_ProcessType CanTxProcessing;
	/** Enables / disables API Can_MainFunction_Wakeup() for
	handling wakeup events in polling mode. */
	Can_ProcessType CanWakeupProcessing;
	Can_ProcessType CanBusOffProcessing;
	/** CAN driver support for wakeup over CAN Bus. */
	//boolean         CanWakeupSupport;
	/**	Reference to the CPU clock configuration, which is set in the MCU driver
	configuration.*/
	//uint32 CanCpuClockRef;
	/** This parameter contains a reference to the Wakeup Source for this
	ontroller as defined in the ECU State Manager. Implementation Type:
	reference to EcuM_WakeupSourceType.*/
	//uint32/* ref to EcuMWakeupSource */ CanWakeupSourceRef;
	/** Specifies the baudrate of the controller in kbps. */
	uint16          CanControllerBaudRate;
	/** Specifies propagation delay in time quantas(1..8).*/
	uint16          CanControllerPropSeg;
	/** Specifies phase segment 1 in time quantas(1..16).*/
	uint16          CanControllerSeg1;
	/** Specifies phase segment 2 in time quantas(1..8).*/
	uint16          CanControllerSeg2;
	/**	Specifies the synchronization jump width(1..4) for the controller in
	time quantas.*/
	//uint16          CanControllerSyncJumpWidth;
	/** List of Hoh id's that belong to this controller */
	const Can_HardwareObjectType  *Can_Hoh;
	boolean Can_Loopback;
}Can_ControllerConfigType;

typedef struct {
	const Can_ControllerConfigType *CanController;
} Can_ConfigSetType;

/*
	This is  the type of the external data structure containing the overall initialization
	data for the CAN driver and SFR settings affecting all controllers. Furthermore it
	contains pointers to controller configuration structures. The contents of the
	initialization data structure are CAN hardware specific.
*/
typedef struct
{
	/** This is the multiple configuration set container for CAN Driver
	 Multiplicity 1..*  */
	const Can_ConfigSetType	 *CanConfigSet;
}Can_ConfigType;
#endif /* CAN_HW_H_ */
