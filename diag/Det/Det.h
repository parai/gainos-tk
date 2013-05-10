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
#ifndef DET_H_
#define DET_H_
#define DET_MODULE_ID            MODULE_ID_DET
#define DET_VENDOR_ID            1

/* Implementation version */
#define DET_SW_MAJOR_VERSION     1
#define DET_SW_MINOR_VERSION     0
#define DET_SW_PATCH_VERSION     0

/* AUTOSAR specification document version */
#define DET_AR_MAJOR_VERSION     2
#define DET_AR_MINOR_VERSION     2
#define DET_AR_PATCH_VERSION     2

#include "Std_Types.h"
#include "Modules.h"

void Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId); /** @req DET009 */
#define Det_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi,DET) /** @req DET011 */ /** @req DET012 */


#endif /* DET_H_ */
