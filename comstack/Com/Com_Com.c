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
 * License of GaInOS: GNU GPL License version 3.
 * URL:      https://github.com/parai
 * Email:    parai@foxmail.com
 * Name:     parai(Wang Fan)
 * from Date:2013-04-08 to $Date: 2013-04-21 13:47:07 $
 * $Revision: 1.3 $
 */
//lint -esym(960,8.7)	PC-Lint misunderstanding of Misra 8.7 for Com_SystenEndianness and endianess_test

#if(MICRO_TENUX_VERSION == 140)
#include <libstr.h>
#else
#include <stdlib.h>
#include <string.h>
#endif
#include "Com_Arc_Types.h"
#include "Com.h"
#include "Com_Internal.h"
#include "Com_misc.h"
#include "ardebug.h"
#include "PduR.h"
#include "Det.h"
#include "Cpu.h"

Com_BufferPduStateType Com_BufferPduState[COM_N_IPDUS];


uint8 Com_SendSignal(Com_SignalIdType SignalId, const void *SignalDataPtr) {
	const ComSignal_type * Signal;
	const ComIPdu_type *IPdu;
	Com_Arc_IPdu_type *Arc_IPdu;
	INT irq_state;
	VALIDATE_SIGNAL(SignalId, 0x0a, E_NOT_OK);
	// Store pointer to signal for easier coding.
	Signal = GET_Signal(SignalId);
	IPdu = GET_IPdu(Signal->ComIPduHandleId);
	Arc_IPdu = GET_ArcIPdu(Signal->ComIPduHandleId);

	if (isPduBufferLocked(getPduId(IPdu))) {
		return COM_BUSY;
	}
	//DEBUG_PRINT4(DEBUG_LOW, "Com_SendSignal: id %d, nBytes %d, BitPosition %d, intVal %d\n", SignalId, nBytes, signal->ComBitPosition, (uint32)*(uint8 *)SignalDataPtr);

	
	Irq_Save(irq_state);
	Com_WriteSignalDataToPdu(Signal->ComHandleId, SignalDataPtr);

	// If the signal has an update bit. Set it!
	if (Signal->ComSignalArcUseUpdateBit) {
		SETBIT(IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
	}

	/*
	 * If signal has triggered transmit property, trigger a transmission!
	 */
	if (Signal->ComTransferProperty == TRIGGERED) {
		Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions + 1;
	}
	Irq_Restore(irq_state);

	return E_OK;
}

uint8 Com_ReceiveSignal(Com_SignalIdType SignalId, void* SignalDataPtr) {
	const ComSignal_type * Signal;
	const ComIPdu_type *IPdu;

	uint8 r = E_OK;
	const void* pduDataPtr;
	VALIDATE_SIGNAL(SignalId, 0x0b, E_NOT_OK);
	DEBUG_PRINT1(DEBUG_LOW, "Com_ReceiveSignal: SignalId %d\n", SignalId);

	Signal = GET_Signal(SignalId);
	IPdu = GET_IPdu(Signal->ComIPduHandleId);	
	pduDataPtr = 0;
	if (IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
		pduDataPtr = IPdu->ComIPduDeferredDataPtr;
	} else {
		if (isPduBufferLocked(getPduId(IPdu))) {
			r = COM_BUSY;
		}
		pduDataPtr = IPdu->ComIPduDataPtr;
	}
	Com_ReadSignalDataFromPduBuffer(
			SignalId,
			FALSE,
			SignalDataPtr,
			pduDataPtr,
			IPdu->ComIPduSize);

	return r;
}

uint8 Com_ReceiveDynSignal(Com_SignalIdType SignalId, void* SignalDataPtr, uint16* Length) {
	const ComSignal_type * Signal = GET_Signal(SignalId);
	Com_Arc_IPdu_type    *Arc_IPdu   = GET_ArcIPdu(Signal->ComIPduHandleId);
	const ComIPdu_type   *IPdu       = GET_IPdu(Signal->ComIPduHandleId);
    INT state;
   	uint8 startFromPduByte;
	uint8 r = E_OK;
	const void* pduDataPtr;
	Com_SignalType signalType = Signal->ComSignalType;
	if (signalType != UINT8_DYN) {
		return COM_SERVICE_NOT_AVAILABLE;
	}

    Irq_Save(state);

	if (*Length > Arc_IPdu->Com_Arc_DynSignalLength) {
		*Length = Arc_IPdu->Com_Arc_DynSignalLength;
	}
	startFromPduByte = (Signal->ComBitPosition) / 8;
	pduDataPtr = 0;
	if (IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
		pduDataPtr = IPdu->ComIPduDeferredDataPtr;
	} else {
		if (isPduBufferLocked(getPduId(IPdu))) {
			r = COM_BUSY;
		}
		pduDataPtr = IPdu->ComIPduDataPtr;
	}
	memcpy((void*)SignalDataPtr, (void*)((uint8*)pduDataPtr + startFromPduByte), *Length);

    Irq_Restore(state);

	return r;
}

uint8 Com_SendDynSignal(Com_SignalIdType SignalId, const void* SignalDataPtr, uint16 Length) {
	const ComSignal_type * Signal = GET_Signal(SignalId);
	Com_Arc_IPdu_type    *Arc_IPdu   = GET_ArcIPdu(Signal->ComIPduHandleId);
	const ComIPdu_type   *IPdu       = GET_IPdu(Signal->ComIPduHandleId);
    INT state;

	Com_SignalType signalType = Signal->ComSignalType;
	uint8 signalLength;
	Com_BitPositionType bitPosition;
	uint8 startFromPduByte;
	if (signalType != UINT8_DYN) {
		return COM_SERVICE_NOT_AVAILABLE;
	}
	if (isPduBufferLocked(getPduId(IPdu))) {
		return COM_BUSY;
	}

	signalLength = Signal->ComBitSize / 8;
	bitPosition = Signal->ComBitPosition;
	if (signalLength < Length) {
		return E_NOT_OK;
	}
	startFromPduByte = bitPosition / 8;

	Irq_Save(state);
	memcpy((void *)(IPdu->ComIPduDataPtr + startFromPduByte), SignalDataPtr, Length);
	Arc_IPdu->Com_Arc_DynSignalLength = Length;
	// If the signal has an update bit. Set it!
	if (Signal->ComSignalArcUseUpdateBit) {
		SETBIT(IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
	}
	 // If signal has triggered transmit property, trigger a transmission!
	if (Signal->ComTransferProperty == TRIGGERED) {
		Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions + 1;
	}
    Irq_Restore(state);

    return E_OK;
}

Std_ReturnType Com_TriggerTransmit(PduIdType ComTxPduId, PduInfoType *PduInfoPtr) {
	const ComIPdu_type *IPdu;

    INT state;
	PDU_ID_CHECK(ComTxPduId,0x13,E_NOT_OK);
	/*
	 * COM260: This function must not check the transmission mode of the I-PDU
	 * since it should be possible to use it regardless of the transmission mode.
	 */

	/*
	 * COM395: This function must override the IPdu callouts used in Com_TriggerIPduTransmit();
	 */
	IPdu = GET_IPdu(ComTxPduId);
    Irq_Save(state);

    memcpy(PduInfoPtr->SduDataPtr, IPdu->ComIPduDataPtr, IPdu->ComIPduSize);

    Irq_Restore(state);

	PduInfoPtr->SduLength = IPdu->ComIPduSize;
	return E_OK;
}


//lint -esym(904, Com_TriggerIPduSend) //PC-Lint Exception of rule 14.7
Std_ReturnType Com_Internal_TriggerIPduSend(PduIdType ComTxPduId) {
	const ComIPdu_type *IPdu;
	Com_Arc_IPdu_type *Arc_IPdu;
    imask_t state;
    uint8 i;
    PduInfoType PduInfoPackage;
    uint8 sizeWithoutDynSignal;
	PDU_ID_CHECK(ComTxPduId, 0x17,E_NOT_OK);

	IPdu = GET_IPdu(ComTxPduId);
	Arc_IPdu = GET_ArcIPdu(ComTxPduId);
    Irq_Save(state);
    /* ����Arccore�������ص�bug�����ദE_NOT_OK����֮ǰδ�ָ�imask*/
    if( isPduBufferLocked(ComTxPduId) ) {
        Irq_Restore(state);
    	return E_NOT_OK;
    }

	// Is the IPdu ready for transmission?
	if (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) {

        //lint --e(725)	Suppress PC-Lint warning "Expected positive indentation...". What means?
		// Check callout status
		if (IPdu->ComIPduCallout != NULL) {
			if (!IPdu->ComIPduCallout(ComTxPduId, IPdu->ComIPduDataPtr)) {
				// TODO Report error to DET.
				// Det_ReportError();
			    Irq_Restore(state);
				return E_NOT_OK;
			}
		}
		PduInfoPackage;
		PduInfoPackage.SduDataPtr = (uint8 *)IPdu->ComIPduDataPtr;
		if (IPdu->ComIPduDynSignalRef != 0) {
			sizeWithoutDynSignal = IPdu->ComIPduSize - (IPdu->ComIPduDynSignalRef->ComBitSize/8);
			PduInfoPackage.SduLength = sizeWithoutDynSignal + Arc_IPdu->Com_Arc_DynSignalLength;
		} else {
			PduInfoPackage.SduLength = IPdu->ComIPduSize;
		}

		// Send IPdu!
		if (PduR_ComTransmit(IPdu->ArcIPduOutgoingId, &PduInfoPackage) == E_OK) {
			// Clear all update bits for the contained signals
			for (i = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[i] != NULL); i++) {
				if (IPdu->ComIPduSignalRef[i]->ComSignalArcUseUpdateBit) {
					CLEARBIT(IPdu->ComIPduDataPtr, IPdu->ComIPduSignalRef[i]->ComUpdateBitPosition);
				}
			}
		} else {
			UnlockTpBuffer(getPduId(IPdu));
			Irq_Restore(state);
			return E_NOT_OK;
		}

		// Reset miminum delay timer.
		Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer = IPdu->ComTxIPdu.ComTxIPduMinimumDelayFactor;
	} else {
    	Irq_Restore(state);
		return E_NOT_OK;
	}
    Irq_Restore(state);
    return E_OK;

}
//lint -esym(904, Com_TriggerIPduSend) //PC-Lint Exception of rule 14.7
void Com_TriggerIPduSend(PduIdType ComTxPduId) {
	Com_Internal_TriggerIPduSend(ComTxPduId);
}

//lint -esym(904, Com_RxIndication) //PC-Lint Exception of rule 14.7
void Com_RxIndication(PduIdType ComRxPduId, const PduInfoType* PduInfoPtr) {
	
	const ComIPdu_type *IPdu = GET_IPdu(ComRxPduId);
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(ComRxPduId);
	imask_t state;
	
	PDU_ID_CHECK_NO_RV(ComRxPduId, 0x14);

	IPdu = GET_IPdu(ComRxPduId);
	Arc_IPdu = GET_ArcIPdu(ComRxPduId);
	Irq_Save(state);

	// If Ipdu is stopped
	if (!Arc_IPdu->Com_Arc_IpduStarted) {
		Irq_Restore(state);
		return;
	}

	// Check callout status
	if (IPdu->ComIPduCallout != NULL) {
		if (!IPdu->ComIPduCallout(ComRxPduId, PduInfoPtr->SduDataPtr)) {
			// TODO Report error to DET.
			// Det_ReportError();
			Irq_Restore(state);
			return;
		}
	}

	// Copy IPDU data
	memcpy(IPdu->ComIPduDataPtr, PduInfoPtr->SduDataPtr, IPdu->ComIPduSize);

	Com_RxProcessSignals(IPdu,Arc_IPdu);

	Irq_Restore(state);

	return;
}

void Com_TpRxIndication(PduIdType PduId, NotifResultType Result) {
    const ComIPdu_type *IPdu;
    Com_Arc_IPdu_type *Arc_IPdu;
    imask_t state;
    
	PDU_ID_CHECK_NO_RV(PduId, 0x14);

	IPdu = GET_IPdu(PduId);
	Arc_IPdu = GET_ArcIPdu(PduId);
	

	Irq_Save(state);

	// If Ipdu is stopped
	if (!Arc_IPdu->Com_Arc_IpduStarted) {
		UnlockTpBuffer(getPduId(IPdu));
		Irq_Restore(state);
		return;
	}
	if (Result == NTFRSLT_OK) {
		if (IPdu->ComIPduSignalProcessing == IMMEDIATE) {
			// irqs needs to be disabled until signal notifications have been called
			// Otherwise a new Tp session can start and fill up pdus
			UnlockTpBuffer(getPduId(IPdu));
		}
		// In deferred mode, buffers are unlocked in mainfunction
		Com_RxProcessSignals(IPdu,Arc_IPdu);
	} else {
		UnlockTpBuffer(getPduId(IPdu));
	}
	Irq_Restore(state);

}

void Com_TpTxConfirmation(PduIdType PduId, NotifResultType Result) {
	imask_t state;
	PDU_ID_CHECK_NO_RV(PduId, 0x15);
	(void)Result; // touch	
	Irq_Save(state);
	UnlockTpBuffer(PduId);
	Irq_Restore(state);
}
void Com_TxConfirmation(PduIdType ComTxPduId) {
	PDU_ID_CHECK_NO_RV(ComTxPduId, 0x15);

	(void)ComTxPduId; // Nothing to be done. This is just to avoid Lint warning.
}


Std_ReturnType Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId) {
//#warning Com_SendSignalGroup should be performed atomically. Should we disable interrupts here?
	const ComSignal_type * Signal = GET_Signal(SignalGroupId);
	Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(Signal->ComIPduHandleId);
	const ComIPdu_type *IPdu = GET_IPdu(Signal->ComIPduHandleId);
    imask_t irq_state;
    uint8 i;
    // Copy shadow buffer to Ipdu data space
	const ComGroupSignal_type *groupSignal;
	if (isPduBufferLocked(getPduId(IPdu))) {
		return COM_BUSY;
	}
	

	Irq_Save(irq_state);
	for (i = 0; Signal->ComGroupSignal[i] != NULL; i++) {
		groupSignal = Signal->ComGroupSignal[i];

		Com_WriteGroupSignalDataToPdu(Signal->ComHandleId, groupSignal->ComHandleId, Signal->Com_Arc_ShadowBuffer);
	}

	// If the signal has an update bit. Set it!
	if (Signal->ComSignalArcUseUpdateBit) {
		SETBIT(IPdu->ComIPduDataPtr, Signal->ComUpdateBitPosition);
	}

	// If signal has triggered transmit property, trigger a transmission!
	if (Signal->ComTransferProperty == TRIGGERED) {
		Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeNumberOfRepetitions + 1;
	}
	Irq_Restore(irq_state);

	return E_OK;
}


Std_ReturnType Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId) {
	const ComSignal_type * Signal = GET_Signal(SignalGroupId);
	const ComIPdu_type *IPdu = GET_IPdu(Signal->ComIPduHandleId);

	if (isPduBufferLocked(getPduId(IPdu))) {
		return COM_BUSY;
	}
	// Copy Ipdu data buffer to shadow buffer.
	Com_CopySignalGroupDataFromShadowBuffer(SignalGroupId);

	return E_OK;
}

void Com_UpdateShadowSignal(Com_SignalIdType SignalId, const void *SignalDataPtr) {
	Com_Arc_GroupSignal_type *Arc_GroupSignal = GET_ArcGroupSignal(SignalId);

	Com_WriteSignalDataToPduBuffer(SignalId, TRUE, SignalDataPtr, (void *)Arc_GroupSignal->Com_Arc_ShadowBuffer, 8);
}

void Com_ReceiveShadowSignal(Com_SignalIdType SignalId, void *SignalDataPtr) {
	Com_Arc_GroupSignal_type *Arc_GroupSignal = GET_ArcGroupSignal(SignalId);
	uint8 pduSize = GET_IPdu(GET_Signal(SignalId)->ComIPduHandleId)->ComIPduSize;

	Com_ReadSignalDataFromPduBuffer(SignalId, TRUE, SignalDataPtr, (void *)Arc_GroupSignal->Com_Arc_ShadowBuffer,pduSize);
}



