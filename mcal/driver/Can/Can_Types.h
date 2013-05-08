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
