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
#include "CanIf_Cbk.h"
#if(CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/* ######################## Hardware dependent GLOBALs #################### */
EXPORT Can_GlobalType Can_Global =
{
	CAN_UNINIT, 	/* driverState */
	NULL,			/* config */
	{				/* canUint */
		{CANIF_CS_UNINIT,0,{0,},INVALID_PDU_ID},
		{CANIF_CS_UNINIT,0,{0,},INVALID_PDU_ID},
		{CANIF_CS_UNINIT,0,{0,},INVALID_PDU_ID},
		{CANIF_CS_UNINIT,0,{0,},INVALID_PDU_ID},
		{CANIF_CS_UNINIT,0,{0,},INVALID_PDU_ID}
	},
	0u,	/* configured */
};

/* ####################### MACROs ########################### */
#if defined(USE_DEM)
#define VALIDATE_DEM_NO_RV(_exp,_err )                          \
    if( !(_exp) ) {                                             \
        Dem_ReportErrorStatus(_err, DEM_EVENT_STATUS_FAILED);   \
        return;                                                 \
    }
#else
#define VALIDATE_DEM_NO_RV(_exp,_err )
#endif

#if ( CAN_DEV_ERROR_DETECT == STD_ON )
#define VALIDATE(_exp,_api,_err )                   \
    if( !(_exp) ) {                                 \
        Det_ReportError(MODULE_ID_CAN,0,_api,_err); \
        return CAN_NOT_OK;                          \
    }
#define VALIDATE_NO_RV(_exp,_api,_err )             \
    if( !(_exp) ) {                                 \
        Det_ReportError(MODULE_ID_CAN,0,_api,_err); \
        return;                                     \
    }
#else
#define VALIDATE(_exp,_api,_err )
#define VALIDATE_NO_RV(_exp,_api,_err )
#endif
/* ####################### LOCAL FUNCTIONs ########################### */
EXPORT void Can_Hw_Init(const Can_ConfigType* Config)
{
	/*For MSCAN nothing to do. */
	return;
}
EXPORT Std_ReturnType Can_Hw_InitController(uint8 Controller,const Can_ControllerConfigType* Config)
{
}

EXPORT Can_ReturnType Can_Hw_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition)
{

}
EXPORT void Can_Hw_DisableControllerInterrupts(uint8 Controller)
{

}

EXPORT void Can_Hw_EnableControllerInterrupts( uint8 Controller )
{

}

EXPORT Can_ReturnType Can_Hw_Write( Can_HwHandleType/* Can_HTHType */ hth, Can_PduType *pduInfo ) {

}

//-------------------------------------------------------------------

/**
 * ISR for CAN. Normal Rx/operation
 *
 * @param unit CAN controller number( from 0 )
 */
LOCAL void Can_Hw_RxIsr(int unit) {

}

/**
 * ISR for CAN. Normal Tx operation
 *
 * @param unit CAN controller number( from 0 )
 */
LOCAL void Can_Hw_TxIsr(int unit) {

}

/* ######################### ISRs #############################*/

#if 0
#include <tm/tmonitor.h>
#include <tm/tm_printf.h>
void CanIf_TxConfirmation( PduIdType canTxPduId )
{

}
void CanIf_RxIndication( uint8 Hrh, Can_IdType CanId, uint8 CanDlc, const uint8 *CanSduPtr )
{
    tm_printf("Hrh = %d,CanId = %d:\r\n",(int)Hrh,(int)CanId);
    while(CanDlc > 0)
    {
        tm_putchar(*CanSduPtr++);
        CanDlc--;
    } 
    tm_putstring("\r\n");    
}

void CanIf_ControllerBusOff( uint8 Controller )
{
}

/* ArcCore extensions */
void CanIf_Arc_Error( uint8 Controller, Can_Arc_ErrorType Error )
{
}
#endif

