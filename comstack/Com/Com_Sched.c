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
 * from Date:2013-04-08 to $Date: 2013-04-17 16:00:59 $
 * $Revision: 1.3 $
 */




#include "Com_Arc_Types.h"
#include "Com.h"
#include "Com_Internal.h"
#include "Com_misc.h"
#if(MICRO_TENUX_VERSION == 140)
#include <libstr.h>
#else
#include <string.h>
#endif
#include "ardebug.h"
#include "Cpu.h"

#define timerDec(timer)                         \
	if (timer > 0) {                            \
		timer = timer - 1;                      \
	}


void Com_MainFunctionRx(void) {	
	uint16 pduId;
	//DEBUG_PRINT0(DEBUG_MEDIUM, "Com_MainFunctionRx() excecuting\n");
#if 0 	
	for (pduId = 0; !ComConfig->ComIPdu[pduId].Com_Arc_EOL; pduId++) {
#else
    for (pduId = 0; pduId < COM_N_IPDUS; pduId++) {
#endif	
		boolean pduUpdated = FALSE;
		const ComIPdu_type *IPdu = GET_IPdu(pduId);
		Com_Arc_IPdu_type *Arc_IPdu = GET_ArcIPdu(pduId);
		imask_t irq_state;
		uint16 i;
		Irq_Save(irq_state);
		for (i = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[i] != NULL); i++) {
			const ComSignal_type *signal = IPdu->ComIPduSignalRef[i];
			Com_Arc_Signal_type * Arc_Signal = GET_ArcSignal(signal->ComHandleId);
			// Monitor signal reception deadline
			if ( (Arc_IPdu->Com_Arc_IpduStarted) && (signal->ComTimeoutFactor > 0) ) {

				// Decrease deadline monitoring timer.
				timerDec(Arc_Signal->Com_Arc_DeadlineCounter);

				// Check if a timeout has occurred.
				if (Arc_Signal->Com_Arc_DeadlineCounter == 0) {
					if (signal->ComRxDataTimeoutAction == COM_TIMEOUT_DATA_ACTION_REPLACE) {
						// Replace signal data.
						Arc_Signal->ComSignalUpdated = TRUE;
						Com_WriteSignalDataToPdu(signal->ComHandleId, signal->ComSignalInitValue);

					}

					// A timeout has occurred.
					if (signal->ComTimeoutNotification != NULL) {
						signal->ComTimeoutNotification();
					}

					// Restart timer
					Arc_Signal->Com_Arc_DeadlineCounter = signal->ComTimeoutFactor;
				}
			}

			if (Arc_Signal->ComSignalUpdated) {
				pduUpdated = TRUE;
			}
		}
		if (pduUpdated && IPdu->ComIPduSignalProcessing == DEFERRED && IPdu->ComIPduDirection == RECEIVE) {
			uint16 i;
			UnlockTpBuffer(getPduId(IPdu));
			memcpy(IPdu->ComIPduDeferredDataPtr,IPdu->ComIPduDataPtr,IPdu->ComIPduSize);
			for (i = 0; (IPdu->ComIPduSignalRef != NULL) && (IPdu->ComIPduSignalRef[i] != NULL); i++) {
				const ComSignal_type *signal = IPdu->ComIPduSignalRef[i];
				Com_Arc_Signal_type * Arc_Signal = GET_ArcSignal(signal->ComHandleId);
				if (Arc_Signal->ComSignalUpdated) {
					if (signal->ComNotification != NULL) {
						signal->ComNotification();
					}
					Arc_Signal->ComSignalUpdated = 0;
				}
			}
		}
		Irq_Restore(irq_state);
	}
}


void Com_MainFunctionTx(void) {
	imask_t irq_state;
	uint16 i;
	const ComIPdu_type *IPdu;

	//DEBUG_PRINT0(DEBUG_MEDIUM, "Com_MainFunctionTx() excecuting\n");
	// Decrease timers.
	
#if 0
	for (i = 0; !ComConfig->ComIPdu[i].Com_Arc_EOL; i++) {
#else /*So I changed it to ...*/
    for(i = 0;i < COM_N_IPDUS;i++){
#endif
	    Com_Arc_IPdu_type *Arc_IPdu;
		IPdu = &ComConfig->ComIPdu[i];
		Arc_IPdu= GET_ArcIPdu(i);

		Irq_Save(irq_state);

		// Is this a IPdu that should be transmitted?
		if ( (IPdu->ComIPduDirection == SEND) && (Arc_IPdu->Com_Arc_IpduStarted) ) {
			// Decrease minimum delay timer
			timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer);

			// If IPDU has periodic or mixed transmission mode.
			if ( (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == PERIODIC)
                 || (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == MIXED) ) {

				timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer);

				// Is it time for a direct transmission?
				if ( (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == MIXED)
                     && (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft > 0) ) {

					timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer);

					// Is it time for a transmission?
					if ( (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer == 0)
                         && (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) ) {

						if (Com_Internal_TriggerIPduSend(i) == E_OK) {
							// Reset periodic timer
							Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeRepetitionPeriodFactor;

							// Register this nth-transmission.
							Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft--;
						}
					}
				}

				// Is it time for a cyclic transmission?
				if ( (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer == 0) && (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) ) {

					if (Com_Internal_TriggerIPduSend(i) == E_OK) {
						// Reset periodic timer.
						Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeTimePeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeTimePeriodFactor;
					}
				}

                // If IPDU has direct transmission mode.
			} else if (IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeMode == DIRECT) {
				// Do we need to transmit anything?
				if (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft > 0) {
					timerDec(Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer);

					// Is it time for a transmission?
					if ( (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer == 0) && (Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduMinimumDelayTimer == 0) ) {
						if (Com_Internal_TriggerIPduSend(i) == E_OK) {
							// Reset periodic timer
							Arc_IPdu->Com_Arc_TxIPduTimers.ComTxModeRepetitionPeriodTimer = IPdu->ComTxIPdu.ComTxModeTrue.ComTxModeRepetitionPeriodFactor;

							// Register this nth-transmission.
							Arc_IPdu->Com_Arc_TxIPduTimers.ComTxIPduNumberOfRepetitionsLeft--;
						}
					}
				}

                // The IDPU has NONE transmission mode.
			} else {
				// Don't send!
			}
		}

		Irq_Restore(irq_state);
	}
}
