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

/* ######################## Hardware dependent MACORs and TYPEs #################### */
// bits in CANxCTL0:
#define BM_INITRQ	0x01
#define BM_SLPRQ	0x02
#define BM_WUPE 	0x04

// bits in CANxCTL1:
#define BM_INITAK	0x01
#define BM_SLPAK	0x02
#define BM_WUPM 	0x04
#define BM_LISTEN	0x10
#define BM_LOOPB	0x20
#define BM_CLKSRC	0x40
#define BM_CANE		0x80

// bits in CANxRFLG:
// bits in CANxRIER:
#define BM_WUPI		0x80
#define BM_CSCI		0x40
#define BM_RSTAT1	0x20
#define BM_RSTAT0	0x10
#define BM_TSTAT1	0x08
#define BM_TSTAT0	0x04
#define BM_OVRI 	0x02
#define BM_RXF		0x01

// bits in CANxTFLG:
// bits in CANxTBSEL:
#define BM_TX2		0x04
#define BM_TX1		0x02
#define BM_TX0		0x01

#if(CAN_USE_HW_BUFFER == STD_ON)
#define BM_TXY      (BM_TX2|BM_TX1|BM_TX0)
/* This is a really special control data defined for 
 * use of Tx BUFFERs of MSCAN,add by parai. */
LOCAL  uint8 Can_TxPrio[NUM_OF_HTHS];
#endif

typedef struct{
	volatile uint8   idr0; // Identifier Register 0
	volatile uint8   idr1;
	volatile uint8   idr2;
	volatile uint8   idr3;
	volatile uint8   ds0; // Data Segment Register 0
	volatile uint8   ds1;
	volatile uint8   ds2;
	volatile uint8   ds3;
	volatile uint8   ds4;
	volatile uint8   ds5;
	volatile uint8   ds6;
	volatile uint8   ds7;
	volatile uint8   dlr;  // Data Length Register
	volatile uint8   tbpr; // Transmit Buffer Priority Register
	volatile uint8   tsr_hb; // Time Stamp Register (High Byte)
	volatile uint8   tsr_lb; // Time Stamp Register (Low Byte)
} RxTxBuf_t;

/*
  IDR0 : ID28 ID27 ID26 ID25 ID24 ID23 ID22 ID21
  IDR1 : ID20 ID19 ID18 SRR  IDE  ID17 ID16 ID15
  IDR2 : ID14 ID13 ID12 ID11 ID10 ID9  ID8  ID7
  IDR3 : ID6  ID5  ID4  ID3  ID2  ID1  ID0  RTR
*/
typedef union {
	volatile uint8 R[4];
    struct {
		volatile uint8 id28to21;
		volatile uint8 id20to18:3;
		volatile uint8 SRR:1;
		volatile uint8 IDE:1;
		volatile uint8 id17to15:3;
		volatile uint8 id14to7;
		volatile uint8 id6to0:7;
		volatile uint8 RTR:1;
    } Bit;
} IdrType;


typedef struct{
	volatile uint8   CTL0; /*   control register 0 */
	volatile uint8   CTL1; /*   control register 1 */
	volatile uint8   BTR0; /*   bus timing register 0 */
	volatile uint8   BTR1; /*   bus timing register 1 */
	volatile uint8   RFLG; /*   receiver flag register */
	volatile uint8   RIER; /*   receiver interrupt reg */
	volatile uint8   TFLG; /*   transmitter flag reg */
	volatile uint8   TIER; /*   transmitter control reg */
	volatile uint8   TARQ; /*   transmitter abort request */
	volatile uint8   TAAK; /*   transmitter abort acknowledge */
	volatile uint8   TBSEL; /*   transmit buffer selection */
	volatile uint8   IDAC; /*   identifier acceptance */
	volatile uint8   NOTUSED1;
	volatile uint8   NOTUSED2;
	volatile uint8   RXERR; /*   receive error counter */
	volatile uint8   TXERR; /*   transmit error counter */
	volatile uint8   IDAR0; /*   id acceptance reg 0 */
	volatile uint8   IDAR1; /*   id acceptance reg 1 */
	volatile uint8   IDAR2; /*   id acceptance reg 2 */
	volatile uint8   IDAR3; /*   id acceptance reg 3 */
	volatile uint8   IDMR0; /*   id mask register 0 */
	volatile uint8   IDMR1; /*   id mask register 1 */
	volatile uint8   IDMR2; /*   id mask register 2 */
	volatile uint8   IDMR3; /*   id mask register 3 */
	volatile uint8   IDAR4; /*   id acceptance reg 4 */
	volatile uint8   IDAR5; /*   id acceptance reg 5 */
	volatile uint8   IDAR6; /*   id acceptance reg 6 */
	volatile uint8   IDAR7; /*   id acceptance reg 7 */
	volatile uint8   IDMR4; /*   id mask register 4 */
	volatile uint8   IDMR5; /*   id mask register 5 */
	volatile uint8   IDMR6; /*   id mask register 6 */
	volatile uint8   IDMR7; /*   id mask register 7 */
	volatile RxTxBuf_t   RXFG; /*   receive buffer */
	volatile RxTxBuf_t   TXFG; /*   transmit buffer */
} CAN_HW_t;
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
// Uses 25.4.5.1 Transmission Abort Mechanism
LOCAL void Can_Hw_AbortTx( CAN_HW_t *canHw, Can_UnitType *canUnit ) 
{
	uint8 mask = 0;
	// Wait for mb's being emptied
	int i=0;

	// Disable Transmit irq
	canHw->TIER = 0;

	// check if mb's empty
	if((canHw->TFLG & BM_TX0) == 0){mask |= BM_TX0;}
	if((canHw->TFLG & BM_TX1) == 0){mask |= BM_TX1;}
	if((canHw->TFLG & BM_TX2) == 0){mask |= BM_TX2;}

	canHw->TARQ = mask; // Abort all pending mb's

	while(canHw->TFLG != (BM_TX0 | BM_TX1 | BM_TX2))
	{
		i++;
		if(i > 100)
		{
			break;
		}
	}
}
#define IO_BASE 0
LOCAL CAN_HW_t * Can_Hw_GetController(int unit)
{
	CAN_HW_t *res = 0;
    switch(unit)
    {
        case  CAN_CTRL_0:
            res = (CAN_HW_t *)(IO_BASE+0x140);
            break;
        case  CAN_CTRL_1:
            res = (CAN_HW_t *)(IO_BASE+0x180);
            break; 
        case  CAN_CTRL_2:
            res = (CAN_HW_t *)(IO_BASE+0x1c0);
            break;
        case  CAN_CTRL_3:
            res = (CAN_HW_t *)(IO_BASE+0x200);
            break;
        case  CAN_CTRL_4:
            res = (CAN_HW_t *)(IO_BASE+0x280);
            break;                                               
    }
	return res;
}
//-------------------------------------------------------------------
/**
 * Function that finds the Hoh( HardwareObjectHandle ) from a Hth
 * A HTH may connect to one or several HOH's. Just find the first one.
 *
 * @param hth The transmit handle
 * @returns Ptr to the Hoh
 */
LOCAL const Can_HardwareObjectType * Can_FindHoh( Can_Arc_HTHType hth , uint32* controller)
{
    const Can_HardwareObjectType *hohObj;
    const Can_ObjectHOHMapType *map;
    const Can_ControllerConfigType *canHwConfig;

    map = &Can_Global.CanHTHMap[hth];
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    // Verify that this is the correct map
    if (map->CanHOHRef->CanObjectId != hth)
    {
        Det_ReportError(MODULE_ID_CAN, 0, CAN_WRITE_SERVICE_ID, CAN_E_PARAM_HANDLE);
    }
#endif
    canHwConfig= CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[map->CanControllerRef]);

    hohObj = map->CanHOHRef;

    // Verify that this is the correct Hoh type
    if ( hohObj->CanObjectType == CAN_OBJECT_TYPE_TRANSMIT)
    {
        *controller = map->CanControllerRef;
        return hohObj;
    }
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(MODULE_ID_CAN, 0, CAN_WRITE_SERVICE_ID, CAN_E_PARAM_HANDLE);
#endif
    return NULL;
}
LOCAL IdrType Can_Hw_ConstructIdBytes(Can_IdType id, Can_IdTypeType idType)
{
    IdrType idr;

    idr.R[3] = idr.R[2] = idr.R[1] = idr.R[0] = 0;

    if(idType == CAN_ID_TYPE_EXTENDED) {
        idr.Bit.SRR = 1;
        idr.Bit.RTR = 0;
        idr.Bit.IDE = 1;
        idr.Bit.id28to21 = id>>21;
        idr.Bit.id20to18 = id>>18 & 0x07;
        idr.Bit.id17to15 = id>>15 & 0x07;
        idr.Bit.id14to7  = id>>7;
        idr.Bit.id6to0   = id & 0x7F;
    } else if (idType == CAN_ID_TYPE_STANDARD) {
        idr.R[0] = id>>3;
        idr.R[1] = id<<5 & 0xE0;
    } else {
        // No support for mixed in this processor
        //assert(0);
        for(;;);
    }

    return idr;
}

LOCAL uint32 McuE_GetSystemClock(void)
{
	return CPU_FREQUENCY;	/* CPU_FREQUENCY = 32MHZ */
}

/* ####################### FUNCTIONs ########################### */
EXPORT void Can_Hw_Init(const Can_ConfigType* Config)
{
	/*For MSCAN nothing to do. */
	return;
}

EXPORT Std_ReturnType Can_Hw_InitController(uint8 Controller,const Can_ControllerConfigType* Config)
{
	CAN_HW_t *canHw;
	uint8 tq;
	uint8 tqSync;
	uint8 tq1;
	uint8 tq2;
	uint32 clock;
	Can_UnitType *canUnit;
	const Can_ControllerConfigType *canHwConfig;
	const Can_HardwareObjectType *hohObj;
	canHw = Can_Hw_GetController(Controller);
	canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[Controller]);

	// Start this baby up
	canHw->CTL0 = BM_INITRQ;				// request Init Mode
	while((canHw->CTL1 & BM_INITAK) == 0) ;   // wait until Init Mode is established

	// set CAN enable bit, deactivate listen-only mode,
	// use Bus Clock as clock source and select loop back mode on/off
	canHw->CTL1 = BM_CANE | BM_CLKSRC | (Config->Can_Loopback ? BM_LOOPB : 0x00);
    
	// acceptance filters
	hohObj = canHwConfig->Can_Hoh;
	--hohObj;
	do {
	    ++hohObj;
		if (hohObj->CanObjectType == CAN_OBJECT_TYPE_RECEIVE)
		{
			canHw->IDAC = hohObj->CanFilterMaskRef->idam;
			canHw->IDAR0 = hohObj->CanFilterMaskRef->idar[0];
			canHw->IDAR1 = hohObj->CanFilterMaskRef->idar[1];
			canHw->IDAR2 = hohObj->CanFilterMaskRef->idar[2];
			canHw->IDAR3 = hohObj->CanFilterMaskRef->idar[3];
			canHw->IDAR4 = hohObj->CanFilterMaskRef->idar[4];
			canHw->IDAR5 = hohObj->CanFilterMaskRef->idar[5];
			canHw->IDAR6 = hohObj->CanFilterMaskRef->idar[6];
			canHw->IDAR7 = hohObj->CanFilterMaskRef->idar[7];
			canHw->IDMR0 = hohObj->CanFilterMaskRef->idmr[0];
			canHw->IDMR1 = hohObj->CanFilterMaskRef->idmr[1];
			canHw->IDMR2 = hohObj->CanFilterMaskRef->idmr[2];
			canHw->IDMR3 = hohObj->CanFilterMaskRef->idmr[3];
			canHw->IDMR4 = hohObj->CanFilterMaskRef->idmr[4];
			canHw->IDMR5 = hohObj->CanFilterMaskRef->idmr[5];
			canHw->IDMR6 = hohObj->CanFilterMaskRef->idmr[6];
			canHw->IDMR7 = hohObj->CanFilterMaskRef->idmr[7];
		}	
	}while( !hohObj->Can_EOL );

    // Clock calucation
    // -------------------------------------------------------------------
    //
    // * 1 TQ = Sclk period( also called SCK )
    // * Ftq = Fcanclk / ( PRESDIV + 1 ) = Sclk
    //   ( Fcanclk can come from crystal or from the peripheral dividers )
    //
    // -->
    // TQ = 1/Ftq = (PRESDIV+1)/Fcanclk --> PRESDIV = (TQ * Fcanclk - 1 )
    // TQ is between 8 and 25
    clock = McuE_GetSystemClock()/2;
    
    tqSync = Config->CanControllerPropSeg + 1;
    tq1 = Config->CanControllerSeg1 + 1;
    tq2 = Config->CanControllerSeg2 + 1;
    tq = tqSync + tq1 + tq2;

    // Check TQ limitations..
    VALIDATE_DEM_NO_RV(( (tq1>=1) && (tq1<=16)), CAN_E_TIMEOUT );
    VALIDATE_DEM_NO_RV(( (tq2>=1) && (tq2<=8)), CAN_E_TIMEOUT );
    VALIDATE_DEM_NO_RV(( (tq>=3) && (tq<25 )), CAN_E_TIMEOUT );

    canHw->BTR0 = (Config->CanControllerPropSeg << 6) | (uint8)(clock/(Config->CanControllerBaudRate*1000*tq) - 1); // Prescaler
    canHw->BTR1 = (Config->CanControllerSeg2 << 4) | Config->CanControllerSeg1;

    canHw->CTL0 &= ~BM_INITRQ;				// exit Init Mode
    while((canHw->CTL1 & BM_INITAK) != 0) ;// wait until Normal Mode is established

    canHw->TBSEL = BM_TX0;					// use (only) TX buffer 0
}

EXPORT Can_ReturnType Can_Hw_SetControllerMode(uint8 Controller,Can_StateTransitionType Transition)
{
	CAN_HW_t *canHw;
	Can_UnitType *canUnit;
	UB imask;
	Can_ReturnType rv = CAN_OK;

	canUnit = CAN_GET_PRIVATE_DATA(Controller);
	canHw = Can_Hw_GetController(Controller);

	switch(Transition )
	{
		case CAN_T_START:
			canUnit->state = CANIF_CS_STARTED;
			DI(imask);
			if (canUnit->lock_cnt == 0){   // REQ CAN196
                Can_EnableControllerInterrupts(Controller);
			}
			EI(imask);
            break;
		case CAN_T_WAKEUP:
			VALIDATE(canUnit->state == CANIF_CS_SLEEP, CAN_SETCONTROLLERMODE_SERVICE_ID, CAN_E_TRANSITION);
			canHw->CTL0 &= ~BM_SLPRQ; // Clear Sleep request
			canHw->CTL0 &= ~BM_WUPE; // Clear Wake up enable
			canUnit->state = CANIF_CS_STOPPED;
            break;
		case CAN_T_SLEEP:  //CAN258, CAN290
			// Should be reported to DEM but DET is the next best
			VALIDATE(canUnit->state == CANIF_CS_STOPPED, CAN_SETCONTROLLERMODE_SERVICE_ID, CAN_E_TRANSITION);
			canHw->CTL0 |= BM_WUPE; // Set wake up enable
			canHw->CTL0 |= BM_SLPRQ; // Set sleep request
			canHw->RIER |= BM_WUPI; // Enable wake up irq
			canUnit->state = CANIF_CS_SLEEP;
            break;
		case CAN_T_STOP:
			// Stop
			canUnit->state = CANIF_CS_STOPPED;
			Can_Hw_AbortTx( canHw, canUnit ); // CANIF282
            break;
		default:
			// Should be reported to DEM but DET is the next best
			VALIDATE(canUnit->state == CANIF_CS_STOPPED, CAN_SETCONTROLLERMODE_SERVICE_ID, CAN_E_TRANSITION);
            break;
	}

	return rv;
}
EXPORT void Can_Hw_DisableControllerInterrupts(uint8 Controller)
{
	UB imask;
	Can_UnitType *canUnit;
	CAN_HW_t *canHw;

	canUnit = CAN_GET_PRIVATE_DATA(Controller);

	VALIDATE_NO_RV( (canUnit->state!=CANIF_CS_UNINIT), CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_UNINIT );

	DI(imask);
	if(canUnit->lock_cnt > 0 )
	{
		// Interrupts already disabled
		canUnit->lock_cnt++;
		EI(imask);
		return;
	}
	canUnit->lock_cnt++;
	EI(imask);

	/* Don't try to be intelligent, turn everything off */
	canHw = Can_Hw_GetController(Controller);

	/* Turn off the tx interrupt mailboxes */
	canHw->TIER = 0;

	/* Turn off the bus off/tx warning/rx warning and error and rx  */
	canHw->RIER = 0;
}

EXPORT void Can_Hw_EnableControllerInterrupts( uint8 Controller )
{
	UB imask;
	Can_UnitType *canUnit;
	CAN_HW_t *canHw;
	const Can_ControllerConfigType *canHwConfig;

	canUnit = CAN_GET_PRIVATE_DATA(Controller);

	VALIDATE_NO_RV( (canUnit->state!=CANIF_CS_UNINIT), CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID, CAN_E_UNINIT );

	DI(imask);
	if( canUnit->lock_cnt > 1 )
	{
		// IRQ should still be disabled so just decrement counter
		canUnit->lock_cnt--;
		EI(imask);
		return;
	} else if (canUnit->lock_cnt == 1)
	{
		canUnit->lock_cnt = 0;
	}
	EI(imask);

	canHw = Can_Hw_GetController(Controller);

	canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[Controller]);

	if( canHwConfig->CanRxProcessing == CAN_PROCESS_TYPE_INTERRUPT )
	{
		/* Turn on the rx interrupt */
		canHw->RIER |= BM_RXF;
	}

	// BusOff here represents all errors and warnings
	if( canHwConfig->CanBusOffProcessing == CAN_PROCESS_TYPE_INTERRUPT )
	{
		/* Turn off the bus off/tx warning/rx warning and error and rx  */
		canHw->RIER |= BM_WUPI | BM_CSCI | BM_OVRI | BM_RXF | BM_RSTAT0 | BM_TSTAT0;
	}
}

EXPORT Can_ReturnType Can_Hw_Write( Can_HwHandleType/* Can_HTHType */ hth, Can_PduType *pduInfo ) {
    Can_ReturnType rv = CAN_OK;
#if(CAN_USE_HW_BUFFER == STD_ON)
    LOCAL uint8 canTxBufferMap[8]=
    {       /* Get The lowest index */
        /* 0=0b000 */ 0,
        /* 1=0b001 */ BM_TX0,
        /* 2=0b010 */ BM_TX1,
        /* 3=0b011 */ BM_TX0,
        /* 4=0b100 */ BM_TX2,
        /* 5=0b101 */ BM_TX0,
        /* 6=0b110 */ BM_TX1,
        /* 7=0b111 */ BM_TX0
    };
    uint8 fb; /* free Tx buffer mask */
#endif
    CAN_HW_t *canHw;
    const Can_HardwareObjectType *hohObj;
    const Can_ControllerConfigType *canHwConfig;
    uint32 controller;
    UB imask;

    IdrType idr;
    Can_UnitType *canUnit;

    hohObj = Can_FindHoh(hth, &controller);
    if (hohObj == NULL)
        return CAN_NOT_OK;

  
    canUnit = CAN_GET_PRIVATE_DATA(controller);
    canHw = Can_Hw_GetController(controller);
    DI(imask);
#if(CAN_USE_HW_BUFFER == STD_ON)
    /* should be in critical section */
    if(canUnit->swPduHandle!=INVALID_PDU_ID)
    {
    	if(canUnit->swPduHandle!=pduInfo->swPduHandle)
    	{
    		return CAN_BUSY;
    	}
    }
#endif
#if(CAN_USE_HW_BUFFER == STD_ON)
    // check for any free box
    fb = (canHw->TFLG & BM_TXY);
    if(BM_TXY == fb )
    {
       Can_TxPrio[hth]=0; /* reset it when all is free */
    }
    else
    {
        if(0xFF == Can_TxPrio[hth]) /* already reach the max value allowed */
        {
            /* wait untill all is free to sync*/
            EI(imask);
        	return CAN_BUSY;
        }
    }
    fb = canTxBufferMap[fb];
    
    if(0 != fb) {
        canHw->TBSEL = fb; // Select mb0

        idr = Can_Hw_ConstructIdBytes(pduInfo->id, hohObj->CanIdType);

        canHw->TXFG.idr0 = idr.R[0];
        canHw->TXFG.idr1 = idr.R[1];
        canHw->TXFG.idr2 = idr.R[2];
        canHw->TXFG.idr3 = idr.R[3];

        memcpy((uint8 *)&canHw->TXFG.ds0, pduInfo->sdu, pduInfo->length);
        canHw->TXFG.dlr = pduInfo->length;
        canHw->TXFG.tbpr = Can_TxPrio[hth]; 
        /* 这都是为了能够使用所有硬件上的Tx Buffer */
        Can_TxPrio[hth]++;

        // Send
        canHw->TFLG = fb;

        canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[controller]);

        if( canHwConfig->CanTxProcessing == CAN_PROCESS_TYPE_INTERRUPT ) {
            /* Turn on the tx interrupt mailboxes */
            canHw->TIER |= fb; 
        }

        // Increment statistics
        canUnit->stats.txSuccessCnt++;

        // Store pdu handle in unit to be used by TxConfirmation
        canUnit->swPduHandle = pduInfo->swPduHandle;
    } else {
        rv = CAN_BUSY;
    }
#else /* CAN_USE_HW_BUFFER */
    // check for any free box
    if((canHw->TFLG & BM_TX0) == BM_TX0) {
      canHw->TBSEL = BM_TX0; // Select mb0

      idr = Can_Hw_ConstructIdBytes(pduInfo->id, hohObj->CanIdType);

      canHw->TXFG.idr0 = idr.R[0];
      canHw->TXFG.idr1 = idr.R[1];
      canHw->TXFG.idr2 = idr.R[2];
      canHw->TXFG.idr3 = idr.R[3];

      memcpy((uint8 *)&canHw->TXFG.ds0, pduInfo->sdu, pduInfo->length);
      canHw->TXFG.dlr = pduInfo->length;
      canHw->TXFG.tbpr = 0; // Highest prio

      // Send
      canHw->TFLG = BM_TX0;

      canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[controller]);

      if( canHwConfig->CanTxProcessing == CAN_PROCESS_TYPE_INTERRUPT ) {
    	  /* Turn on the tx interrupt mailboxes */
        canHw->TIER |= BM_TX0; // We only use TX0
      }

      // Increment statistics
      canUnit->stats.txSuccessCnt++;

      // Store pdu handle in unit to be used by TxConfirmation
      canUnit->swPduHandle = pduInfo->swPduHandle;
    } else {
      rv = CAN_BUSY;
    }
#endif /* CAN_USE_HW_BUFFER */
    EI(imask);

    return rv;
}
/* ######################### ISR HANDLERs ######################### */

/**
 * Hardware wake ISR for CAN
 *
 * @param unit CAN controller number( from 0 )
 */
LOCAL void Can_Hw_WakeIsr( int unit ) {
	//CanIf_ControllerWakeup(unit);
	// 269,270,271
	Can_SetControllerMode(unit, CAN_T_STOP);

	// TODO EcuM_CheckWakeup();
}

/**
 * Hardware error ISR for CAN
 *
 * @param unit CAN controller number( from 0 )
 */
LOCAL void Can_Hw_ErrIsr( int unit ) {
    Can_Arc_ErrorType err;
    CAN_HW_t *canHw = Can_Hw_GetController(unit);
    Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(unit);
    
    uint8 rflg = canHw->RFLG;
    err.R = 0;

    if((rflg & BM_OVRI) == BM_OVRI)
    {
        err.B.FRMERR = 1;

        // Clear ERRINT
        canHw->RFLG = BM_OVRI;
    }

    if((rflg & BM_CSCI) == BM_CSCI)
    {
        if( ((rflg & (BM_RSTAT0 | BM_RSTAT0)) == (BM_RSTAT0 | BM_RSTAT1)) ||
            ((rflg & (BM_TSTAT0 | BM_TSTAT0)) == (BM_TSTAT0 | BM_TSTAT1)) )
        {
            canUnit->stats.boffCnt++;
            CanIf_ControllerBusOff(unit);
            Can_SetControllerMode(unit, CAN_T_STOP); // CANIF272

            Can_Hw_AbortTx( canHw, canUnit ); // CANIF273
        }

        // Clear ERRINT
        canHw->RFLG = BM_CSCI;
    }

    if (err.R != 0)
    {
        CanIf_Arc_Error( unit, err );
    }
}

//-------------------------------------------------------------------

/**
 * ISR for CAN. Normal Rx/operation
 *
 * @param unit CAN controller number( from 0 )
 */
LOCAL void Can_Hw_RxIsr(int unit) {

    CAN_HW_t *canHw= Can_Hw_GetController(unit);
    const Can_ControllerConfigType *canHwConfig= CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[unit]);
    Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(unit);
    const Can_HardwareObjectType *hohObj;

    // Loop over all the Hoh's
    hohObj= canHwConfig->Can_Hoh;
    --hohObj;
    do {
        ++hohObj;
        if (hohObj->CanObjectType == CAN_OBJECT_TYPE_RECEIVE)
        {
            Can_IdType id=0;
            IdrType *idr;
            idr = (IdrType *)&canHw->RXFG.idr0;

            // According to autosar MSB shuould be set if extended
            if (idr->Bit.IDE == 1) {
                id = ((uint32)idr->Bit.id28to21 << 21) | ((uint32)idr->Bit.id20to18 << 18) | ((uint32)idr->Bit.id17to15 << 15) |
                    ((uint32)idr->Bit.id14to7 << 7) | idr->Bit.id6to0;
                id |= 0x80000000;
            } else {
                //id = ((uint32)idr->Bit.id28to21 << 3) | (uint32)idr->Bit.id20to18;
                id = ((uint32)idr->R[0] << 3) | (uint32)(idr->R[1]>>5);
            }

            CanIf_RxIndication(hohObj->CanObjectId,
                               id,
                               canHw->RXFG.dlr,
                               (uint8 *)&canHw->RXFG.ds0 ); // Next layer will copy
            // Increment statistics
            canUnit->stats.rxSuccessCnt++;

            // Clear interrupt
            canHw->RFLG = BM_RXF;					// clear RX flag
        }
        
    } while ( !hohObj->Can_EOL);
}

/**
 * ISR for CAN. Normal Tx operation
 *
 * @param unit CAN controller number( from 0 )
 */
LOCAL void Can_Hw_TxIsr(int unit) {
    CAN_HW_t *canHw= Can_Hw_GetController(unit);
    const Can_ControllerConfigType *canHwConfig= CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[unit]);
    Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(unit);
    const Can_HardwareObjectType *hohObj;

    // Loop over all the Hoh's
    hohObj= canHwConfig->Can_Hoh;
    --hohObj;
    do {
        ++hohObj;
        if (hohObj->CanObjectType == CAN_OBJECT_TYPE_TRANSMIT)
        {
            CanIf_TxConfirmation(canUnit->swPduHandle);
#if(CAN_USE_HW_BUFFER == STD_ON)
            if((canHw->TFLG & BM_TXY)==BM_TXY)
            {
            	canUnit->swPduHandle = INVALID_PDU_ID;
            	// Disable Tx interrupt when all has been transfered.
            	canHw->TIER = 0;
            }
#else
            // Disable Tx interrupt
            canHw->TIER = 0;
#endif

        }       
    } while ( !hohObj->Can_EOL);
}

/* ######################### ISRs #############################*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED
#define ISR_Vcan4tx            55
#define ISR_Vcan4rx            54
#define ISR_Vcan4err           53
#define ISR_Vcan4wkup          52
#define ISR_Vcan3tx            51
#define ISR_Vcan3rx            50
#define ISR_Vcan3err           49
#define ISR_Vcan3wkup          48
#define ISR_Vcan2tx            47
#define ISR_Vcan2rx            46
#define ISR_Vcan2err           45
#define ISR_Vcan2wkup          44
#define ISR_Vcan1tx            43
#define ISR_Vcan1rx            42
#define ISR_Vcan1err           41
#define ISR_Vcan1wkup          40
#define ISR_Vcan0tx            39
#define ISR_Vcan0rx            38
#define ISR_Vcan0err           37
#define ISR_Vcan0wkup          36

interrupt ISR_Vcan0rx void Can_0_RxIsr( void  ) {	Can_Hw_RxIsr(CAN_CTRL_0); }
interrupt ISR_Vcan1rx void Can_1_RxIsr( void  ) {	Can_Hw_RxIsr(CAN_CTRL_1); }
interrupt ISR_Vcan2rx void Can_2_RxIsr( void  ) {	Can_Hw_RxIsr(CAN_CTRL_2); }
interrupt ISR_Vcan3rx void Can_3_RxIsr( void  ) {	Can_Hw_RxIsr(CAN_CTRL_3); }
interrupt ISR_Vcan4rx void Can_4_RxIsr( void  ) {	Can_Hw_RxIsr(CAN_CTRL_4); }

interrupt ISR_Vcan0tx void Can_0_TxIsr( void  ) {	Can_Hw_TxIsr(CAN_CTRL_0); }
interrupt ISR_Vcan1tx void Can_1_TxIsr( void  ) {	Can_Hw_TxIsr(CAN_CTRL_1); }
interrupt ISR_Vcan2tx void Can_2_TxIsr( void  ) {	Can_Hw_TxIsr(CAN_CTRL_2); }
interrupt ISR_Vcan3tx void Can_3_TxIsr( void  ) {	Can_Hw_TxIsr(CAN_CTRL_3); }
interrupt ISR_Vcan4tx void Can_4_TxIsr( void  ) {	Can_Hw_TxIsr(CAN_CTRL_4); }

interrupt ISR_Vcan0err void Can_0_ErrIsr( void  ) {	Can_Hw_ErrIsr(CAN_CTRL_0); }
interrupt ISR_Vcan1err void Can_1_ErrIsr( void  ) {	Can_Hw_ErrIsr(CAN_CTRL_1); }
interrupt ISR_Vcan2err void Can_2_ErrIsr( void  ) {	Can_Hw_ErrIsr(CAN_CTRL_2); }
interrupt ISR_Vcan3err void Can_3_ErrIsr( void  ) {	Can_Hw_ErrIsr(CAN_CTRL_3); }
interrupt ISR_Vcan4err void Can_4_ErrIsr( void  ) {	Can_Hw_ErrIsr(CAN_CTRL_4); }

interrupt ISR_Vcan0wkup void Can_0_WakeIsr( void  ) {	Can_Hw_WakeIsr(CAN_CTRL_0); }
interrupt ISR_Vcan1wkup void Can_1_WakeIsr( void  ) {	Can_Hw_WakeIsr(CAN_CTRL_1); }
interrupt ISR_Vcan2wkup void Can_2_WakeIsr( void  ) {	Can_Hw_WakeIsr(CAN_CTRL_2); }
interrupt ISR_Vcan3wkup void Can_3_WakeIsr( void  ) {	Can_Hw_WakeIsr(CAN_CTRL_3); }
interrupt ISR_Vcan4wkup void Can_4_WakeIsr( void  ) {	Can_Hw_WakeIsr(CAN_CTRL_4); }

#pragma CODE_SEG DEFAULT
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

