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
#ifndef CAN_TYPES_H_
#define CAN_TYPES_H_
#include "Std_Types.h"
/* ####################### Autosar CAN Standard TYPEs  ###################### */
/* @req 4.0/CAN103,CAN246,CAN245 */
typedef enum
{
    CAN_UNINIT = 0,
    CAN_READY
} Can_DriverStateType;

/*
Represents the Identifier of an L-PDU. For extended IDs the most significant bit is set.
 */
typedef uint32 Can_IdType;
/*
Range:
	Standard  0..0x0FF
	Extended  0..0xFFFF
Represents the hardware object handles of a CAN hardware unit. For CAN
hardware units with more than 255 HW objects use extended range.
 */
typedef uint16 Can_HwHandleType;

typedef struct Can_PduType_s {
	/* the CAN ID, 29 or 11-bit  */
	Can_IdType 	id;
	/* Length, max 8 bytes  */
	uint8		length;
	/* data ptr  */
	uint8 		*sdu;
	/* private data for CanIf,just save and use for callback */
	PduIdType   swPduHandle;
} Can_PduType;

typedef enum {
	CAN_T_START,
	CAN_T_STOP,
	CAN_T_SLEEP,
	CAN_T_WAKEUP
} Can_StateTransitionType;

typedef struct {
	uint32 txSuccessCnt;
	uint32 rxSuccessCnt;
	uint32 txErrorCnt;
	uint32 rxErrorCnt;
	uint32 boffCnt;
	uint32 fifoOverflow;
	uint32 fifoWarning;
} Can_StatisticsType;

typedef enum {
	CAN_OK,
	CAN_NOT_OK,
	CAN_BUSY
} Can_ReturnType;

typedef enum
{
	CAN_PROCESS_TYPE_INTERRUPT,
	CAN_PROCESS_TYPE_POLLING
}Can_ProcessType;

typedef enum 
{
  CAN_ARC_HANDLE_TYPE_BASIC,
  CAN_ARC_HANDLE_TYPE_FULL
} Can_Arc_HohType;

typedef enum
{
	/** All the CANIDs are of type extended only (29 bit).*/
	CAN_ID_TYPE_EXTENDED = 0x1,
	/** All the CANIDs are of type standard only (11bit). */
	CAN_ID_TYPE_STANDARD = 0x2,
	/** The type of CANIDs can be both Standard or Extended.*/
	CAN_ID_TYPE_MIXED    = 0x3
}Can_IdTypeType;

typedef enum {
	CAN_OBJECT_TYPE_RECEIVE,
	CAN_OBJECT_TYPE_TRANSMIT
} Can_ObjectTypeType;
/* Error from  CAN controller */
typedef union {
     volatile uint32 R;
     struct {
    	 volatile uint32:24;
         volatile uint32 BIT1ERR:1;
         volatile uint32 BIT0ERR:1;
         volatile uint32 ACKERR:1;
         volatile uint32 CRCERR:1;
         volatile uint32 FRMERR:1;
         volatile uint32 STFERR:1;
         volatile uint32 TXWRN:1;
         volatile uint32 RXWRN:1;
     } B;
 } Can_Arc_ErrorType;
#endif /* CAN_TYPES_H_ */
