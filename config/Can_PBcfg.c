#include "Can.h"
#include "Can_Cfg.h"

LOCAL const Can_FilterMaskType vCanFilterMask0=
{
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0,0,0,0,0,0,0,0},
	CAN_IDAM_2_32BIT
};

LOCAL const Can_HardwareObjectType CAN_CTRL_1_HOHCfgData[]=
{
	{
		CAN_ARC_HANDLE_TYPE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_1_vCanHoh0,
		CAN_OBJECT_TYPE_RECEIVE,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		FALSE
	},
	{
		CAN_ARC_HANDLE_TYPE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_1_vCanHoh1,
		CAN_OBJECT_TYPE_TRANSMIT,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		TRUE
	},
};

LOCAL const Can_HardwareObjectType CAN_CTRL_2_HOHCfgData[]=
{
	{
		CAN_ARC_HANDLE_TYPE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_2_vCanHoh0,
		CAN_OBJECT_TYPE_RECEIVE,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		FALSE
	},
	{
		CAN_ARC_HANDLE_TYPE_BASIC,
		CAN_ID_TYPE_STANDARD,
		0,
		CAN_CTRL_2_vCanHoh1,
		CAN_OBJECT_TYPE_TRANSMIT,
		&vCanFilterMask0,
		0x00000000,/* mbMask */
		TRUE
	},
};

EXPORT const Can_ControllerConfigType  Can_ControllerCfgData[]=
{
	{
		CAN_CTRL_1,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		250, /* baudrate(kbs) */
		0, /* propseg(SJW) */
		12, /* seg1 */
		1, /* seg2 */
		CAN_CTRL_1_HOHCfgData,
		FALSE	/* LoopBack */
	},
	{
		CAN_CTRL_2,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		CAN_PROCESS_TYPE_INTERRUPT,
		250, /* baudrate(kbs) */
		0, /* propseg(SJW) */
		12, /* seg1 */
		1, /* seg2 */
		CAN_CTRL_2_HOHCfgData,
		TRUE	/* LoopBack */
	},
};
EXPORT const Can_ConfigSetType Can_ConfigSetData ={Can_ControllerCfgData};
EXPORT const Can_ConfigType Can_ConfigData ={&Can_ConfigSetData};
