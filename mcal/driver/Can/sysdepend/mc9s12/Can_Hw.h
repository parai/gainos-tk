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
	CAN_CTRL_0 = 0,
	CAN_CTRL_1 = 1,
	CAN_CTRL_2 = 2,
	CAN_CTRL_3 = 3,
	CAN_CTRL_4 = 4,
	CAN_CONTROLLER_CNT = 5
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
	Can_FilterMaskType *CanFilterMaskRef;

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

/* ####################### MSCAN Control Registers ###################### */
#define CAN_REG_BASE	0x0140
#define CAN_REG_OFFSET  64
#define CAN_CTL0        0  /*   control register 0 */
#define CAN_CTL1        1  /*   control register 1 */
#define CAN_BTR0        2  /*   bus timing register 0 */
#define CAN_BTR1        3  /*   bus timing register 1 */
#define CAN_RFLG        4  /*   receiver flag register */
#define CAN_RIER        5  /*   receiver interrupt reg */
#define CAN_TFLG        6  /*   transmitter flag reg */
#define CAN_TIER        7  /*   transmitter control reg */
#define CAN_TARQ        8  /*   transmitter abort request */
#define CAN_TAAK        9  /*   transmitter abort acknowledge */
#define CAN_TBSEL       10 /*   transmit buffer selection */
#define CAN_IDAC        11 /*   identifier acceptance */
#define CAN_RESERVED1	12
#define CAN_RESERVED2	13
#define CAN_RXERR       14 /*   receive error counter */
#define CAN_TXERR       15 /*   transmit error counter */
#define CAN_IDAR0       16 /*   id acceptance reg 0 */
#define CAN_IDAR1       17 /*   id acceptance reg 1 */
#define CAN_IDAR2       18 /*   id acceptance reg 2 */
#define CAN_IDAR3       19 /*   id acceptance reg 3 */
#define CAN_IDMR0       20 /*   id mask register 0 */
#define CAN_IDMR1       21 /*   id mask register 1 */
#define CAN_IDMR2       22 /*   id mask register 2 */
#define CAN_IDMR3       23 /*   id mask register 3 */
#define CAN_IDAR4       24 /*   id acceptance reg 4 */
#define CAN_IDAR5       25 /*   id acceptance reg 5 */
#define CAN_IDAR6       26 /*   id acceptance reg 6 */
#define CAN_IDAR7       27 /*   id acceptance reg 7 */
#define CAN_IDMR4       28 /*   id mask register 4 */
#define CAN_IDMR5       28 /*   id mask register 5 */
#define CAN_IDMR6       30 /*   id mask register 6 */
#define CAN_IDMR7       31 /*   id mask register 7 */
#define CAN_RXFG        32 /*   receive buffer structure offset(16 bytes) */

#define CAN_TXFG        48 /*   transmit buffer structure offset(16 bytes) */

/* CAN Transmit/Receive buffer structure */
#define CAN_IDR0		0	/* Identifier Register 0 */
#define CAN_IDR1		1	/* Identifier Register 1 */
#define CAN_IDR2		2	/* Identifier Register 2 */
#define CAN_IDR3		3	/* Identifier Register 3 */
#define CAN_DSR0		4	/* Data Segment Register 0 */
#define CAN_DSR1		5	/* Data Segment Register 1 */
#define CAN_DSR2		6	/* Data Segment Register 2 */
#define CAN_DSR3		7	/* Data Segment Register 3 */
#define CAN_DSR4		8	/* Data Segment Register 4 */
#define CAN_DSR5		9	/* Data Segment Register 5 */
#define CAN_DSR6		10	/* Data Segment Register 6 */
#define CAN_DSR7		11	/* Data Segment Register 7 */
#define CAN_DLCR		12	/* Data Length Register */
#define CAN_TBPR		13	/* Transmit Buffer Priority Register */
#define CAN_TSRH        14	/* Time Stamp Register (High Byte) */
#define CAN_TSRL        15	/* Time Stamp Register (Low Byte) */
/* io access <tk/syslib.h:>
 * out_w(port,data)
 * out_h(port,data )
 * out_b(port,data )
 * in_w(port)
 * in_h(port)
 * in_b(port)
 * */
#endif /* CAN_HW_H_ */
