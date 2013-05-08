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

#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "misc.h"
#include "Cpu.h"
//#include "Mcu.h"
#include "CanIf_Cbk.h"

#if(MICRO_TENUX_VERSION == 140)
#  include <libstr.h>
#  include <tk/syscall.h>
#else if(MICRO_TENUX_VERSION == 150)
#  include <string.h>
#  include <tk/tk_syscall.h>
#endif


/* CONFIGURATION NOTES
 * ------------------------------------------------------------------
 * - CanHandleType must be CAN_ARC_HANDLE_TYPE_BASIC
 *   i.e. CanHandleType=CAN_ARC_HANDLE_TYPE_FULL NOT supported
 *   i.e CanIdValue is NOT supported
 * - All CanXXXProcessing must be CAN_ARC_PROCESS_TYPE_INTERRUPT
 *   ie CAN_ARC_PROCESS_TYPE_POLLED not supported
 * - HOH's for Tx are global and Rx are for each controller
 */

/* IMPLEMENTATION NOTES
 * -----------------------------------------------
 * - A HOH us unique for a controller( not a config-set )
 * - Hrh's are numbered for each controller from 0
 * - loopback in HW NOT supported
 * - Only one transmit mailbox is used because otherwise
 *   we cannot use tx_confirmation since there is no way to know
 *   which mailbox caused the tx interrupt. TP will need this feature.
 * - Sleep,wakeup not fully implemented since other modules lack functionality
 */

/* ABBREVATIONS
 *  -----------------------------------------------
 * - Can Hardware unit - One or multiple Can controllers of the same type.
 * - Hrh - HOH with receive definitions
 * - Hth - HOH with transmit definitions
 *
 */

typedef CAN_TypeDef CAN_HW_t;
//-------------------------------------------------------------------

/* ######################## Hardware dependent GLOBALs #################### */
EXPORT Can_GlobalType Can_Global =
{
	CAN_UNINIT, 	/* driverState */
	NULL,			/* config */
	{				/* canUint */
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
#define DET_REPORTERROR(_x,_y,_z,_q) Det_ReportError(_x, _y, _z, _q)
#else
#define VALIDATE(_exp,_api,_err )
#define VALIDATE_NO_RV(_exp,_api,_err )
#define DET_REPORTERROR(_x,_y,_z,_q)
#endif
/* ####################### LOCAL FUNCTIONs ########################### */
static uint32 McuE_GetSystemClock(void)
{
    RCC_ClocksTypeDef clk;
    RCC_GetClocksFreq(&clk);
    return clk.SYSCLK_Frequency;
    //return clk.PCLK1_Frequency;
}

static CAN_HW_t * GetController(int unit)
{
	return ((CAN_HW_t *)(CAN1_BASE + unit*0x400));
}

//-------------------------------------------------------------------
/**
 * Function that finds the Hoh( HardwareObjectHandle ) from a Hth
 * A HTH may connect to one or several HOH's. Just find the first one.
 *
 * @param hth The transmit handle
 * @returns Ptr to the Hoh
 */
static const Can_HardwareObjectType * Can_FindHoh( Can_Arc_HTHType hth , uint32* controller)
{
  const Can_HardwareObjectType *hohObj;
  const Can_ObjectHOHMapType *map;
  //const Can_ControllerConfigType *canHwConfig;

  map = &Can_Global.CanHTHMap[hth];

  // Verify that this is the correct map
  if (map->CanHOHRef->CanObjectId != hth)
  {
    DET_REPORTERROR(MODULE_ID_CAN, 0, 0x6, CAN_E_PARAM_HANDLE);
  }

  //canHwConfig= CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[map->CanControllerRef]);

  hohObj = map->CanHOHRef;

  // Verify that this is the correct Hoh type
  if ( hohObj->CanObjectType == CAN_OBJECT_TYPE_TRANSMIT)
  {
    *controller = map->CanControllerRef;
    return hohObj;
  }

  DET_REPORTERROR(MODULE_ID_CAN, 0, 0x6, CAN_E_PARAM_HANDLE);

  return NULL;
}

/* ==================== ISRs ========================================*/

static void Can_RxIsr( int unit );
static void Can_TxIsr( int unit );
static void Can_ErrIsr( int unit );

void Can_1_RxIsr( void  ) {	Can_RxIsr(CAN_CTRL_1); }
void Can_2_RxIsr( void  ) {	Can_RxIsr(CAN_CTRL_2); }

void Can_1_TxIsr( void  ) {	Can_TxIsr(CAN_CTRL_1); }
void Can_2_TxIsr( void  ) {	Can_TxIsr(CAN_CTRL_2); }

void Can_1_ErrIsr( void  ) {	Can_ErrIsr(CAN_CTRL_1); }
void Can_2_ErrIsr( void  ) {	Can_ErrIsr(CAN_CTRL_2); }

//-------------------------------------------------------------------

// Uses 25.4.5.1 Transmission Abort Mechanism
static void Can_AbortTx( CAN_HW_t *canHw, Can_UnitType *canUnit ) {
	// Disable Transmit irq

	// check if mb's empty

	// Abort all pending mb's

	// Wait for mb's being emptied
}

/**
 * Hardware wake ISR for CAN
 *
 * @param unit CAN controller number( from 0 )
 */
static void Can_WakeIsr( int unit ) {
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
static void Can_ErrIsr( int unit ) {
  CAN_HW_t *canHw = GetController(unit);
  Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(unit);
  Can_Arc_ErrorType err;
  err.R = 0;

  // Check wake up
  if(SET == CAN_GetITStatus(canHw, CAN_IT_WKU)){
	  Can_WakeIsr(unit);
	  CAN_ClearITPendingBit(canHw, CAN_IT_WKU);
  }

  if(SET == CAN_GetITStatus(canHw, CAN_IT_BOF)){
	canUnit->stats.boffCnt++;
	CanIf_ControllerBusOff(unit);
	Can_SetControllerMode(unit, CAN_T_STOP); // CANIF272

	Can_AbortTx( canHw, canUnit ); // CANIF273

	// Clear int
	CAN_ClearITPendingBit(canHw, CAN_IT_BOF);
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
static void Can_RxIsr(int unit) {

  CAN_HW_t *canHw= GetController(unit);
  const Can_ControllerConfigType *canHwConfig= CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[unit]);
  Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(unit);
  const Can_HardwareObjectType *hohObj;

  CanRxMsg RxMessage;

  RxMessage.StdId=0x00;
  RxMessage.ExtId=0x00;
  RxMessage.IDE=0;
  RxMessage.DLC=0;
  RxMessage.FMI=0;
  RxMessage.Data[0]=0x00;
  RxMessage.Data[1]=0x00;
  CAN_Receive(canHw,CAN_FIFO0, &RxMessage);

  // Loop over all the Hoh's
  hohObj= canHwConfig->Can_Hoh;
  --hohObj;
  do {
	++hohObj;

	if (hohObj->CanObjectType == CAN_OBJECT_TYPE_RECEIVE)
	{
	    Can_IdType id=0;

	    // According to autosar MSB shuould be set if extended
		if (RxMessage.IDE != CAN_ID_STD) {
		  id = RxMessage.ExtId;
		  id |= 0x80000000;
		} else {
		  id = RxMessage.StdId;
		}

		CanIf_RxIndication(hohObj->CanObjectId,
									id,
									RxMessage.DLC,
									(uint8 *)&RxMessage.Data[0] ); // Next layer will copy

		// Increment statistics
		canUnit->stats.rxSuccessCnt++;
	}
  } while ( !hohObj->Can_EOL);
}

/**
 * ISR for CAN. Normal Tx operation
 *
 * @param unit CAN controller number( from 0 )
 */
static void Can_TxIsr(int unit) {
  CAN_HW_t *canHw= GetController(unit);
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

		canUnit->swPduHandle = 0;  // Is this really necessary ??

		// Clear Tx interrupt
        CAN_ClearITPendingBit(canHw,CAN_IT_RQCP0);
        CAN_ClearITPendingBit(canHw,CAN_IT_RQCP1);
        CAN_ClearITPendingBit(canHw,CAN_IT_RQCP2);
	}
  } while ( !hohObj->Can_EOL);
}

/* ####################### INTERNAL FUNCTIONs ########################### */
#define INSTALL_HANDLERS(_can_name,_sce,_rx,_tx) 		\
	do { 												\
		T_DINT pk_dint;									\
		pk_dint.intatr = TA_HLNG;						\
		pk_dint.inthdr = _can_name ## _ErrIsr;			\
		tk_def_int(_sce+16,&pk_dint);					\
		pk_dint.inthdr = _can_name ## _RxIsr;			\
		tk_def_int(_rx+16,&pk_dint);					\
		pk_dint.inthdr = _can_name ## _TxIsr;			\
		tk_def_int(_tx+16,&pk_dint);					\
	} while(0);


EXPORT void Can_Hw_Init(const Can_ConfigType* Config)
{
	int configId;
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef  GPIO_InitStructure;
	const Can_ControllerConfigType *canHwConfig;
    
    /* All CAN ISR use the same priority */
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
	for (configId=0; configId < CAN_CTRL_CONFIG_CNT; configId++)
	{
		canHwConfig = CAN_GET_CONTROLLER_CONFIG(configId);
		// Note!
		// Could install handlers depending on HW objects to trap more errors
		// in configuration
		switch( canHwConfig->CanControllerId ) {
		#ifndef STM32F10X_CL
		case CAN_CTRL_1:
        {
			INSTALL_HANDLERS(Can_1, CAN1_SCE_IRQn, USB_LP_CAN1_RX0_IRQn, USB_HP_CAN1_TX_IRQn);
            
            /* GPIO clock enable */
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO |RCC_APB2Periph_GPIOD, ENABLE);
            /* CAN1 Periph clock enable */
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
            
            /* Configure CAN pin: RX */
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//GPIO_Pin_CAN_RX;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
            GPIO_Init(GPIOD, &GPIO_InitStructure);
  
            /* Configure CAN pin: TX */
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//GPIO_Pin_CAN_TX;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_Init(GPIOD, &GPIO_InitStructure);
            /* USE PD0 -->Rx  PD1 -->Tx*/
            GPIO_PinRemapConfig(GPIO_Remap2_CAN1 , ENABLE);
            
            /* Enable CAN1 SCE interrupt IRQ */
            NVIC_InitStructure.NVIC_IRQChannel = CAN1_SCE_IRQn;
            NVIC_Init(&NVIC_InitStructure);            
            /* Enable CAN1 RX0 interrupt IRQ channel */
            NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
            NVIC_Init(&NVIC_InitStructure);
            /* Enable CAN1 TX interrupt IRQ channel */
            NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_TX0_IRQn;
            NVIC_Init(&NVIC_InitStructure);            
            break;
        }
		#else
		case CAN_CTRL_1:
        {
			INSTALL_HANDLERS(Can_1, CAN1_SCE_IRQn, CAN1_RX0_IRQn, CAN1_TX_IRQn);
            
            /* GPIO clock enable */
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO |RCC_APB2Periph_GPIOD, ENABLE);
            /* CAN1 Periph clock enable */
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);            

            /* Configure CAN pin: RX */
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//GPIO_Pin_CAN_RX;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
            GPIO_Init(GPIOD, &GPIO_InitStructure);
  
            /* Configure CAN pin: TX */
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//GPIO_Pin_CAN_TX;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_Init(GPIOD, &GPIO_InitStructure);
            /* USE PD0 -->Rx  PD1 -->Tx*/
            GPIO_PinRemapConfig(GPIO_Remap2_CAN1 , ENABLE);
            
            /* Enable CAN1 SCE interrupt IRQ */
            NVIC_InitStructure.NVIC_IRQChannel = CAN1_SCE_IRQn;
            NVIC_Init(&NVIC_InitStructure);            
            /* Enable CAN1 RX0 interrupt IRQ channel */
            NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
            NVIC_Init(&NVIC_InitStructure);
            /* Enable CAN1 TX interrupt IRQ channel */
            NVIC_InitStructure.NVIC_IRQChannel = CAN1_TX_IRQn;
            NVIC_Init(&NVIC_InitStructure);                     
            break;
        }
		case CAN_CTRL_2:
        {
			INSTALL_HANDLERS(Can_2, CAN2_SCE_IRQn, CAN2_RX0_IRQn, CAN2_TX_IRQn);
            
            /* GPIO clock enable */
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO |RCC_APB2Periph_GPIOB, ENABLE);
            /* CAN2 Periph clock enable */
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);            
            
            /* Configure CAN pin: RX */
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//GPIO_Pin_CAN_RX;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
            GPIO_Init(GPIOB, &GPIO_InitStructure);
  
            /* Configure CAN pin: TX */
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//GPIO_Pin_CAN_TX;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_Init(GPIOB, &GPIO_InitStructure);
            /* USE PB5 -->Rx  PB6 -->Tx*/
            GPIO_PinRemapConfig(GPIO_Remap_CAN2 , ENABLE);
            
            /* Enable CAN2 SCE interrupt IRQ */
            NVIC_InitStructure.NVIC_IRQChannel = CAN2_SCE_IRQn;
            NVIC_Init(&NVIC_InitStructure);
            /* Enable CAN2 RX0 interrupt IRQ channel */
            NVIC_InitStructure.NVIC_IRQChannel = CAN2_RX0_IRQn;
            NVIC_Init(&NVIC_InitStructure);
            /* Enable CAN2 TX interrupt IRQ channel */
            NVIC_InitStructure.NVIC_IRQChannel = CAN2_TX_IRQn;
            NVIC_Init(&NVIC_InitStructure);                 
            break;
        }
		#endif
			default:
				AR_ASSERT(0);
		}
	}
	return;
}

EXPORT Std_ReturnType Can_Hw_InitController(uint8 controller,const Can_ControllerConfigType* config)
{
	  CAN_HW_t *canHw;
	  uint8_t tq;
	  uint8_t tqSync;
	  uint8_t tq1;
	  uint8_t tq2;
	  uint32_t clock;
	  Can_UnitType *canUnit;
	  uint8 cId = controller;
	  const Can_ControllerConfigType *canHwConfig;
	  const Can_HardwareObjectType *hohObj;


	  canUnit = CAN_GET_PRIVATE_DATA(controller);

	  canHw = GetController(cId);
	  canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[cId]);

	  // Start this baby up
	  CAN_DeInit(canHw);

	  /* CAN filter init. We set up two filters - one for the master (CAN1) and
	   * one for the slave (CAN2)
	   *
	   * CAN_SlaveStartBank(n) denotes which filter is the first of the slave.
	   *
	   * The filter registers reside in CAN1 and is shared to CAN2, so we only need
	   * to set up this once.
	   */

	  // We let all frames in and do the filtering in software.
	  CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	  CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;
	  CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;
	  CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;
	  CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
	  CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;
	  CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
	  CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FIFO0;
	  CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;

	  // Init filter 0 (CAN1/master)
	  CAN_FilterInitStructure.CAN_FilterNumber=0;
	  CAN_FilterInit(&CAN_FilterInitStructure);

	  // Init filter 1 (CAN2/slave)
	  CAN_FilterInitStructure.CAN_FilterNumber=1;
	  CAN_FilterInit(&CAN_FilterInitStructure);

	  // Set which filter to use for CAN2.
	  CAN_SlaveStartBank(1);

	  // acceptance filters
	   hohObj = canHwConfig->Can_Hoh;
	   --hohObj;
	   do {
		 ++hohObj;
	     if (hohObj->CanObjectType == CAN_OBJECT_TYPE_RECEIVE)
	     {
	    	 // TODO Hw filtering
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

	  tqSync = config->CanControllerPropSeg + 1;
	  tq1 = config->CanControllerSeg1 + 1;
	  tq2 = config->CanControllerSeg2 + 1;
	  tq = tqSync + tq1 + tq2;

	  CAN_InitTypeDef        CAN_InitStructure;
	  CAN_StructInit(&CAN_InitStructure);

	  /* CAN cell init */
	  CAN_InitStructure.CAN_TTCM=DISABLE;
	  CAN_InitStructure.CAN_ABOM=ENABLE;
	  CAN_InitStructure.CAN_AWUM=ENABLE;
	  CAN_InitStructure.CAN_NART=DISABLE;
	  CAN_InitStructure.CAN_RFLM=DISABLE;
	  CAN_InitStructure.CAN_TXFP=DISABLE;
	  if(config->Can_Loopback){
		  CAN_InitStructure.CAN_Mode=CAN_Mode_LoopBack;
	  }else{
		  CAN_InitStructure.CAN_Mode=CAN_Mode_Normal;
	  }

	  CAN_InitStructure.CAN_SJW=config->CanControllerPropSeg;
	  CAN_InitStructure.CAN_BS1=config->CanControllerSeg1;
	  CAN_InitStructure.CAN_BS2=config->CanControllerSeg2;
	  CAN_InitStructure.CAN_Prescaler= clock/(config->CanControllerBaudRate*1000*tq);

	  if(CANINITOK != CAN_Init(canHw,&CAN_InitStructure))
	  {
		return E_NOT_OK;
	  }

	  canUnit->state = CANIF_CS_STOPPED;
	  Can_EnableControllerInterrupts(cId);

	  return E_OK;
}

EXPORT Can_ReturnType Can_Hw_SetControllerMode(uint8 controller,Can_StateTransitionType transition)
{
	  imask_t state;
	  CAN_HW_t *canHw;
	  Can_ReturnType rv = CAN_OK;

	  Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(controller);

	  VALIDATE( (canUnit->state!=CANIF_CS_UNINIT), 0x3, CAN_E_UNINIT );
	  canHw = GetController(controller);

	  switch(transition )
	  {
	  case CAN_T_START:
	    canUnit->state = CANIF_CS_STARTED;
	    Irq_Save(state);
	    if (canUnit->lock_cnt == 0){   // REQ CAN196
	      Can_EnableControllerInterrupts(controller);
	    }
	    Irq_Restore(state);
	    break;
	  case CAN_T_WAKEUP:
		VALIDATE(canUnit->state == CANIF_CS_SLEEP, 0x3, CAN_E_TRANSITION);
		CAN_WakeUp(canHw);
		canUnit->state = CANIF_CS_STOPPED;
		break;
	  case CAN_T_SLEEP:  //CAN258, CAN290
	    // Should be reported to DEM but DET is the next best
	    VALIDATE(canUnit->state == CANIF_CS_STOPPED, 0x3, CAN_E_TRANSITION);
	    CAN_Sleep(canHw);
	    canUnit->state = CANIF_CS_SLEEP;
		break;
	  case CAN_T_STOP:
	    // Stop
	    canUnit->state = CANIF_CS_STOPPED;
	    Can_AbortTx( canHw, canUnit ); // CANIF282
	    break;
	  default:
	    // Should be reported to DEM but DET is the next best
	    VALIDATE(canUnit->state == CANIF_CS_STOPPED, 0x3, CAN_E_TRANSITION);
	    break;
	  }

	  return rv;
}
EXPORT void Can_Hw_DisableControllerInterrupts(uint8 controller)
{
	  imask_t state;
	  Can_UnitType *canUnit;
	  CAN_HW_t *canHw;

	  canUnit = CAN_GET_PRIVATE_DATA(controller);

	  VALIDATE_NO_RV( (canUnit->state!=CANIF_CS_UNINIT), 0x4, CAN_E_UNINIT );

	  Irq_Save(state);
	  if(canUnit->lock_cnt > 0 )
	  {
	    // Interrupts already disabled
	    canUnit->lock_cnt++;
	    Irq_Restore(state);
	    return;
	  }
	  canUnit->lock_cnt++;
	  Irq_Restore(state);

	  /* Don't try to be intelligent, turn everything off */
	  canHw = GetController(controller);

	  /* Turn off the tx interrupt mailboxes */
	   CAN_ITConfig(canHw, CAN_IT_TME, DISABLE);

	   /* Turn off the bus off/tx warning/rx warning and error and rx  */
	   CAN_ITConfig(canHw, CAN_IT_FMP0 | CAN_IT_BOF | CAN_IT_ERR | CAN_IT_WKU, DISABLE);
}

EXPORT void Can_Hw_EnableControllerInterrupts( uint8 controller )
{
	 imask_t state;
	  Can_UnitType *canUnit;
	  CAN_HW_t *canHw;
	  const Can_ControllerConfigType *canHwConfig;

	  canUnit = CAN_GET_PRIVATE_DATA(controller);

	  VALIDATE_NO_RV( (canUnit->state!=CANIF_CS_UNINIT), 0x5, CAN_E_UNINIT );

	  Irq_Save(state);
	  if( canUnit->lock_cnt > 1 )
	  {
	    // IRQ should still be disabled so just decrement counter
	    canUnit->lock_cnt--;
	    Irq_Restore(state);
	    return;
	  } else if (canUnit->lock_cnt == 1)
	  {
	    canUnit->lock_cnt = 0;
	  }
	  Irq_Restore(state);

	  canHw = GetController(controller);

	  canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[controller]);

	   if( canHwConfig->CanRxProcessing == CAN_PROCESS_TYPE_INTERRUPT ) {
	     /* Turn on the rx interrupt */
	 	CAN_ITConfig(canHw, CAN_IT_FMP0, ENABLE);
	   }
	   if( canHwConfig->CanTxProcessing == CAN_PROCESS_TYPE_INTERRUPT ) {
	 	/* Turn on the tx interrupt mailboxes */
	   	CAN_ITConfig(canHw, CAN_IT_TME, ENABLE);
	   }

	   // BusOff here represents all errors and warnings
	   if( canHwConfig->CanBusOffProcessing == CAN_PROCESS_TYPE_INTERRUPT ) {
	 	/* Turn on the bus off/tx warning/rx warning and error and rx  */
	 	CAN_ITConfig(canHw, CAN_IT_BOF | CAN_IT_ERR | CAN_IT_WKU, ENABLE);
	   }

	   return;
}

EXPORT Can_ReturnType Can_Hw_Write( Can_HwHandleType/* Can_HTHType */ hth, Can_PduType *pduInfo ) {
	  Can_ReturnType rv = CAN_OK;
	  CAN_HW_t *canHw;
	  const Can_HardwareObjectType *hohObj;
	  const Can_ControllerConfigType *canHwConfig;
	  uint32 controller;
	  imask_t state;

	  hohObj = Can_FindHoh(hth, &controller);
	  if (hohObj == NULL)
	    return CAN_NOT_OK;

	  Can_UnitType *canUnit = CAN_GET_PRIVATE_DATA(controller);

	  canHw = GetController(controller);
	  Irq_Save(state);

	  CanTxMsg TxMessage;

	  TxMessage.RTR=CAN_RTR_DATA;
	  TxMessage.DLC=pduInfo->length;

	  memcpy(TxMessage.Data, pduInfo->sdu, pduInfo->length);

	  if (hohObj->CanIdType == CAN_ID_TYPE_EXTENDED) {
		TxMessage.IDE=CAN_ID_EXT;
		TxMessage.ExtId=pduInfo->id;
	  } else {
		TxMessage.IDE=CAN_ID_STD;
		TxMessage.StdId=pduInfo->id;
	  }

	  // check for any free box
	  if(CAN_Transmit(canHw,&TxMessage) != CAN_NO_MB) {
	    canHwConfig = CAN_GET_CONTROLLER_CONFIG(Can_Global.channelMap[controller]);

	    if( canHwConfig->CanTxProcessing == CAN_PROCESS_TYPE_INTERRUPT ) {
	  	  /* Turn on the tx interrupt mailboxes */
	    	CAN_ITConfig(canHw,CAN_IT_TME, ENABLE);
	    }

		// Increment statistics
		canUnit->stats.txSuccessCnt++;

	    // Store pdu handle in unit to be used by TxConfirmation
	    canUnit->swPduHandle = pduInfo->swPduHandle;
	  } else {
	    rv = CAN_BUSY;
	  }
	  Irq_Restore(state);

	  return rv;
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

