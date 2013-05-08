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
 * from Date:2013-04-08 to $Date: 2013-04-08 12:08:19 $
 * $Revision: 1.2 $
 */

/** @addtogroup TBD
 *  @{ */

/** @file CanTp_Cbk.h
 * TBD.
 */

/** req:  **/
#ifndef CANTP_CBK_H_
#define CANTP_CBK_H_

#include "ComStack_Types.h"


void CanTp_RxIndication( PduIdType CanTpRxPduId, const PduInfoType *CanTpRxPduPtr ); /** @req CANTP214 */

void CanTp_TxConfirmation( PduIdType CanTpTxPduId ); /** @req CANTP215 */


#endif /* CANTP_CBK_H_ */
