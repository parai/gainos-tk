#include "Os.h"
#include "Dcm.h"
#include "Can.h"
#include "CanIf.h"
#include "CanTp.h"
#include "PduR.h"
#include <stdio.h>
/* 通知回调函数 */
Std_ReturnType vSecurityLevel_1_GetSeed (uint8 *securityAccessDataRecord, uint8 *seed, 
                        Dcm_NegativeResponseCodeType *errorCode)
{
    printf("in vSecurityLevel_1_GetSeed().\r\n");
    *seed = 0xEF;
    *errorCode = E_OK;
    return E_OK;
}
Std_ReturnType vSecurityLevel_1_CompKey (uint8 *key)
{
    printf("in vSecurityLevel_1_CompKey().\r\n");
    if(*key == 0xEF)
    {
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
}

Std_ReturnType vSecurityLevel_Locked_GetSeed (uint8 *securityAccessDataRecord, uint8 *seed, 
                            Dcm_NegativeResponseCodeType *errorCode)
{
    printf("in vSecurityLevel_Locked_GetSeed().\r\n");
    *seed = 0xEF;
    *errorCode = E_OK;
    return E_OK;
}
Std_ReturnType vSecurityLevel_Locked_CompKey (uint8 *key)
{
    printf("in vSecurityLevel_Locked_CompKey().\r\n");
    if(*key == 0xEF)
    {
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
}

Std_ReturnType vRequestService_1_Start (Dcm_ProtocolType protocolID)
{
     printf("in vRequestService_1_Start().\r\n");
    return E_OK;
}
Std_ReturnType vRequestService_1_Stop (Dcm_ProtocolType protocolID)
{
    printf("in vRequestService_1_Stop().\r\n");
    return E_OK;
}

Std_ReturnType vSessionControl_1_GetSesChgPer(Dcm_SesCtrlType sesCtrlTypeActive, 
                                            Dcm_SesCtrlType sesCtrlTypeNew)
{
    printf("in vSessionControl_1_GetSesChgPer().\r\n");
    return E_OK;
}
Std_ReturnType vDid_1_ReadDataLength_Cbk(uint16 *didLength){
    return E_OK;
}
Std_ReturnType vDid_1_ConditionCheckRead_Cbk(Dcm_NegativeResponseCodeType *errorCode){
    *errorCode = E_OK;
    return E_OK;
}
Std_ReturnType vDid_1_ReadData_Cbk(uint8 *data){

}
Std_ReturnType vDid_1_ConditionCheckWrite_Cbk(Dcm_NegativeResponseCodeType *errorCode){
    return E_OK;
}
Std_ReturnType vDid_1_WriteData_Cbk(uint8 *data, uint16 dataLength, 
                Dcm_NegativeResponseCodeType *errorCode){
    return E_OK;               
}
Std_ReturnType vDid_1_GetScalingInfo_Cbk(uint8 *scalingInfo, 
                Dcm_NegativeResponseCodeType *errorCode){
    return E_OK;
}
Std_ReturnType vRequestService_1_Indication(uint8 *requestData, uint16 dataSize)
{
    return E_OK;
}
/* Dcm Example Initialise Routine.
 * 初始化Can、CanIf、PduR和DCM ，
 * 需要使用“dcm_ex1.arxml”生成其相应配置文件。*/
void DcmEx1Init(void)
{
    Can_Init(&Can_ConfigData); 
    CanIf_Init(&CanIf_Config);
    CanTp_Init();
    PduR_Init(&PduR_Config);
    Dcm_Init();
    //启动配置的两个CAN通道 CAN_CTRL_0 和 CAN_CTRL_1
    CanIf_SetControllerMode(vCanIf_Channel_0,CANIF_CS_STARTED);
    CanIf_SetControllerMode(vCanIf_Channel_1,CANIF_CS_STARTED);
}

/* Dcm Example Main Function Routine.
 * 这个API必须被周期性的调用，建议每 5ms 一次*/
void DcmEx1MainFunction(void)
{
    CanTp_MainFunction();
    Dcm_MainFunction();
}
#define ISO15765_TPCI_SF        0x00  /* Single Frame */
static void ex1DiagnosticSessionControl(void)
{
    static uint8 callcnt = 0;
    uint8  sduData[8];
    PduInfoType pduinfo;
    sduData[0] = ISO15765_TPCI_SF | 2;
    sduData[1] = 0x10;
    callcnt++;
    switch(callcnt)
    {
        case 1:
            sduData[2] = 0x01;  //default Session
        break;
        case 2:
            sduData[2] = 0x02;  //program Session
        break;
        case 3:
            sduData[2] = 0x03;  //extended Session
        break;
        case 4:
            sduData[2] = 0x04;  //safety system Session
        break;
        default:
            callcnt = 0;
        break;
    }
    pduinfo.SduDataPtr = sduData;
    pduinfo.SduLength = 3;
    
    CanIf_Transmit(vCanIf_Channel_0, &pduinfo);
}
static void ex1SecurityAccess_RequestSeed(void)
{
    uint8  sduData[8];
    PduInfoType pduinfo;
    sduData[0] = ISO15765_TPCI_SF|2;
    sduData[1] = 0x27;
    sduData[2] = 0x01|(1<<1);   //requestSeed,want to set level 1
    pduinfo.SduDataPtr = sduData;
    pduinfo.SduLength = 3;
    
    CanIf_Transmit(vCanIf_Channel_0, &pduinfo);
}
static void ex1SecurityAccess_SendKey(void)
{
    uint8  sduData[8];
    PduInfoType pduinfo;
    sduData[0] = ISO15765_TPCI_SF | 3;
    sduData[1] = 0x27;
    sduData[2] = 0x02;   //sendKey,want to set level 1
    sduData[3] = 0xEF;
    pduinfo.SduDataPtr = sduData;
    pduinfo.SduLength = 4;
    
    CanIf_Transmit(vCanIf_Channel_0, &pduinfo);
}
void CanIf_UserRxIndication(uint8 channel, PduIdType pduId, const uint8 *sduPtr,
                           uint8 dlc, Can_IdType canId)
{
    int len = dlc;
    char* ptr= sduPtr;
    printf("channel=%d,pduId=%d,canId=%d.\r\r\n",(int)channel,(int)pduId,(int)canId);
    printf("[");      
    while(len > 0)
    {
        printf("0x%x,",(uint8)(*ptr));
        ptr++;
        len--;
    } 
    printf("]\r\n");
}
void DcmEx1Sender(void)
{
    
    static uint8 callcnt = 0;
    /* 摆在我面前的难题，没有专业的CAN调试设备，我将如何测试DCM */
    /* 使用CanIf来发送SF，模拟 Client */
    callcnt++; 
    switch(callcnt)
    {
        case 1:
            ex1SecurityAccess_RequestSeed(); //try to get the seed              
        break;
        case 2:
            ex1SecurityAccess_SendKey();    //try to unlock for level 1
        break;
        case 3:
            ex1DiagnosticSessionControl();    //now,unlocked, can do session control on level 1   
        break;
        default:
            callcnt = 0;
    }     
}