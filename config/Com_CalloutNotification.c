#include "Com.h"

// Notifications
void vCom_IPdu1_TX_Signal0_Notification(void){}
void vCom_IPdu1_TX_Signal0_TimeoutNotification(void){}
void vCom_IPdu1_RX_Signal0_Notification(void){}
void vCom_IPdu1_RX_Signal0_TimeoutNotification(void){}
void vCom_IPdu2_TX_Signal0_Notification(void){}
void vCom_IPdu2_TX_Signal0_TimeoutNotification(void){}
void vCom_IPdu2_RX_Signal0_Notification(void){}
void vCom_IPdu2_RX_Signal0_TimeoutNotification(void){}

// Callouts
boolean vCom_IPdu1_TX_Callout(PduIdType PduId, const uint8 *IPduData){}
boolean vCom_IPdu1_RX_Callout(PduIdType PduId, const uint8 *IPduData){}
boolean vCom_IPdu2_TX_Callout(PduIdType PduId, const uint8 *IPduData){}
boolean vCom_IPdu2_RX_Callout(PduIdType PduId, const uint8 *IPduData){}
