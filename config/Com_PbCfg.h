#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 2)) )
#error Com: Configuration file expected BSW module version to be 1.2.*
#endif

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

#include "Com_Types.h"

extern const Com_ConfigType ComConfiguration;

// PDU group id definitions
#define vCom_IPduGrp0 0

//  COM IPDU Id Defines.
#define vCom_IPdu1_TX 0
#define COM_TX_vEcuC_Pdu1 0	/* for vCom_IPdu1_TX */
#define vCom_IPdu1_RX 1
#define COM_RX_vEcuC_Pdu1 1	/* for vCom_IPdu1_RX */
#define vCom_IPdu2_TX 2
#define COM_TX_vEcuC_Pdu2 2	/* for vCom_IPdu2_TX */
#define vCom_IPdu2_RX 3
#define COM_RX_vEcuC_Pdu2 3	/* for vCom_IPdu2_RX */

//General Signal (Group) Id defines
#define vCom_IPdu1_TX_Signal0 0
#define vCom_IPdu1_RX_Signal0 1
#define vCom_IPdu2_TX_Signal0 2
#define vCom_IPdu2_RX_Signal0 3

//Group Signal Id defines

// Notifications
extern void vCom_IPdu1_TX_Signal0_Notification(void);
extern void vCom_IPdu1_TX_Signal0_TimeoutNotification(void);
extern void vCom_IPdu1_RX_Signal0_Notification(void);
extern void vCom_IPdu1_RX_Signal0_TimeoutNotification(void);
extern void vCom_IPdu2_TX_Signal0_Notification(void);
extern void vCom_IPdu2_TX_Signal0_TimeoutNotification(void);
extern void vCom_IPdu2_RX_Signal0_Notification(void);
extern void vCom_IPdu2_RX_Signal0_TimeoutNotification(void);

// Callouts
extern boolean vCom_IPdu1_TX_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu1_RX_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu2_TX_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu2_RX_Callout(PduIdType PduId, const uint8 *IPduData);
#endif /* COM_PBCFG_H */

