#include "Com.h"

// Notifications
void vCom_IPdu1_TX_Signal0_Notification(void){}
void vCom_IPdu1_TX_Signal0_TimeoutNotification(void){}
void vCom_IPdu1_Signal0_Notification(void){}
void vCom_IPdu1_Signal0_TimeoutNotification(void){}

// Callouts
boolean vCom_IPdu0_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
boolean vCom_IPdu1_Callout(PduIdType PduId, const uint8 *IPduData){return TRUE;}
