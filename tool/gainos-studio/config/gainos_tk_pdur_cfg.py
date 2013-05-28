# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
from Common import *
import os, sys
import shutil 
from time import localtime, time,strftime
import xml.etree.ElementTree as ET
class PduRGeneral():
    def __init__(self):
        self.DevErrorDetection = True;
        self.VersionInfoAPI = True;
        self.ZeroCostOperation = False;
        self.SingleIfEnable = False;
        self.SingleTpEnable = False;
        self.SingleIf = 'CAN_IF';
        self.SingleTp = 'CAN_TP';
        ###Activated Interface
        self.CanIfUsed = True;
        self.CanTpUsed = True;
        self.ComUsed = True;
        self.DcmUsed = False;
        self.LinIfUsed = False;
        self.LinTpUsed = False;
        self.J1939TpUsed = False;

    def save(self, root):
        nd = ET.Element('General');
        nd.attrib['DevErrorDetection'] = str(self.DevErrorDetection);
        nd.attrib['VersionInfoAPI'] = str(self.VersionInfoAPI);
        nd.attrib['ZeroCostOperation'] = str(self.ZeroCostOperation);
        nd.attrib['SingleIfEnable'] = str(self.SingleIfEnable);
        nd.attrib['SingleTpEnable'] = str(self.SingleTpEnable);
        nd.attrib['SingleIf'] = str(self.SingleIf);
        nd.attrib['SingleTp'] = str(self.SingleTp);
        nd.attrib['CanIfUsed'] = str(self.CanIfUsed);
        nd.attrib['CanTpUsed'] = str(self.CanTpUsed);
        nd.attrib['ComUsed'] = str(self.ComUsed);
        nd.attrib['DcmUsed'] = str(self.DcmUsed);
        nd.attrib['LinIfUsed'] = str(self.LinIfUsed);
        nd.attrib['LinTpUsed'] = str(self.LinTpUsed);
        nd.attrib['J1939TpUsed'] = str(self.J1939TpUsed);
        root.append(nd);
    
    def parse(self, node):
        if(node == None):
            return;
        self.DevErrorDetection = bool(node.attrib['DevErrorDetection']);
        self.VersionInfoAPI = bool(node.attrib['VersionInfoAPI']);
        self.ZeroCostOperation = bool(node.attrib['ZeroCostOperation']);
        self.SingleIfEnable = bool(node.attrib['SingleIfEnable']);
        self.SingleTpEnable = bool(node.attrib['SingleTpEnable']);
        self.SingleIf = node.attrib['SingleIf'];
        self.SingleTp = node.attrib['SingleTp'];
        self.CanIfUsed = bool(node.attrib['CanIfUsed']);
        self.CanTpUsed = bool(node.attrib['CanTpUsed']);
        self.ComUsed = bool(node.attrib['ComUsed']);
        self.DcmUsed = bool(node.attrib['DcmUsed']);
        self.LinIfUsed = bool(node.attrib['LinIfUsed']);
        self.LinTpUsed = bool(node.attrib['LinTpUsed']);
        self.J1939TpUsed = bool(node.attrib['J1939TpUsed']);

class PduRDstPath():
    def __init__(self, name):
        self.name=name;
        self.DataProvision = 'NO_PROVISION';
        self.DataProvisionEnable=False;
        self.DestPduId ='';
        self.DestModule='CanIf';
        self.TxBufferRef = 'NULL';#还不清楚其用意
        self.DestModuleEnable=False;

    def save(self, root):
        nd = ET.Element('PduRDstPath');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DataProvision'] = str(self.DataProvision);
        nd.attrib['DataProvisionEnable'] = str(self.DataProvisionEnable);
        nd.attrib['DestPduId'] = str(self.DestPduId);
        nd.attrib['DestModule'] = str(self.DestModule);
        nd.attrib['TxBufferRef'] = str(self.TxBufferRef);
        nd.attrib['DestModuleEnable'] = str(self.DestModuleEnable);
        root.append(nd);

    def parse(self, node):
        self.name = node.attrib['name'];
        self.DataProvision = node.attrib['DataProvision'];
        self.DataProvisionEnable = bool(node.attrib['DataProvisionEnable']);
        self.DestPduId = node.attrib['DestPduId'];
        self.DestModule = node.attrib['DestModule'];
        self.DestModuleEnable = bool(node.attrib['DestModuleEnable']);

class PduRSrcPath():
    def __init__(self, name):
        self.name = name;
        self.SduLength =8;
        self.SrcPduId = '';
        self.SrcModuleEnable = False;
        self.SrcModule = 'Com';
        self.destPathList=[];

    def save(self, root):
        nd = ET.Element('PduRSrcPath');
        nd.attrib['name'] = str(self.name)
        nd.attrib['SduLength'] = str(self.SduLength)
        nd.attrib['SrcPduId'] = str(self.SrcPduId)
        nd.attrib['SrcModuleEnable'] = str(self.SrcModuleEnable)
        nd.attrib['SrcModule'] = str(self.SrcModule)
        nd2 = ET.Element('PduRDestPathList');
        for obj in self.destPathList:
            obj.save(nd2)
        nd.append(nd2)
        root.append(nd)

    def parse(self, node):
        self.name = node.attrib['name'];
        self.SduLength = int(node.attrib['SduLength']);
        self.SrcPduId = node.attrib['SrcPduId'];
        self.SrcModuleEnable = bool(node.attrib['SrcModuleEnable']);
        self.SrcModule = node.attrib['SrcModule'];
        for nd2 in node.find('PduRDestPathList'):
            obj = PduRDstPath('');
            obj.parse(nd2);
            self.destPathList.append(obj)

class PduRTpBuffer():
    def __init__(self, name):
        self.name=name;
        self.size=32;

    def save(self, root):
        nd = ET.Element('PduRTpBuffer');
        nd.attrib['name'] = str(self.name)
        nd.attrib['size'] = str(self.size)
        root.append(nd);
    
    def parse(self, node):
        self.name =node.attrib['name'];
        self.size =int(node.attrib['size']);

class PduRConfig():
    def __init__(self):
        self.General = PduRGeneral();
        self.pduRoutingPathList=[];
        self.tpBufferList=[]

class gainos_tk_pdur_cfg():
    def __init__(self, chip = None):
        self.cfg=PduRConfig();

    def toString(self):
        str='  Double Clicked to Start to Configure the Pdu Router!\n';
        return str;

    def show(self,title, fileInd, module_list):
        from cd_pdur import cd_pdur
        depinfo=[];
        md=gcfindModule(module_list, 'EcuC');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg=cd_pdur(title, fileInd, self.cfg, depinfo);
        self.dlg.setModal(False)
        self.dlg.show();
 
    def saveSrcPathList(self, fp):
        fp.write('<PduRSrcPathList>\n');
        for src in self.cfg.pduRoutingPathList:
            src.save(fp);
        fp.write('</PduRSrcPathList>\n');

    def save(self, root):
        """保存配置信息"""
        self.cfg.General.save(root);
        
        nd = ET.Element('PduRSrcPathList');
        for obj in self.cfg.pduRoutingPathList:
            obj.save(nd);
        root.append(nd);
        nd = ET.Element('PduRTpBufferList');
        for obj in self.cfg.tpBufferList:
            obj.save(nd);
        root.append(nd);

    def parse(self, root):
        self.cfg.General.parse(root.find('PduRGeneral'));
        
        for nd in root.find('PduRSrcPathList'):
            obj = PduRSrcPath('');
            obj.parse(nd)
            self.cfg.pduRoutingPathList.append(obj)
        for nd in root.find('PduRTpBufferList'):
            obj = PduRTpBuffer('');
            obj.parse(nd)
            self.cfg.tpBufferList.append(obj)

    def gen(self, path):
        self.codeGenH(path);
        self.codeGenPbCfgH(path);
        self.codeGenPbCfgC(path);

    def codeGenH(self, path):
        file=path+'/PduR_Cfg.h';
        fp=open(file, 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#if !(((PDUR_SW_MAJOR_VERSION == 2) && (PDUR_SW_MINOR_VERSION == 0)) )\n'
                '#error PduR: Configuration file expected BSW module version to be 2.0.*\n'
                '#endif\n\n'
                '#ifndef PDUR_CFG_H_\n'
                '#define PDUR_CFG_H_\n\n');
        fp.write('// Module support\n');
        fp.write('#define PDUR_CANIF_SUPPORT %s\n'%(gSTD_ON(self.cfg.General.CanIfUsed)));
        fp.write('#define PDUR_CANTP_SUPPORT %s\n'%(gSTD_ON(self.cfg.General.CanTpUsed)));
        fp.write('#define PDUR_FRIF_SUPPORT STD_OFF  /* Not supported */\n');#%(gSTD_ON(self.cfg.General.FrIfUsed)));
        fp.write('#define PDUR_FRTP_SUPPORT STD_OFF  /* Not supported */\n');#%(gSTD_ON(self.cfg.General.FrTpUsed)));
        fp.write('#define PDUR_LINIF_SUPPORT %s\n'%(gSTD_ON(self.cfg.General.LinIfUsed)));
        fp.write('#define PDUR_LINTP_SUPPORT STD_OFF  /* Not supported */\n');#%(gSTD_ON(self.cfg.General.LinTpUsed)));
        fp.write('#define PDUR_COM_SUPPORT %s\n'%(gSTD_ON(self.cfg.General.ComUsed)));
        fp.write('#define PDUR_DCM_SUPPORT %s\n'%(gSTD_ON(self.cfg.General.DcmUsed)));
        fp.write('#define PDUR_IPDUM_SUPPORT STD_OFF  /* Not supported */\n');
        fp.write('#define PDUR_J1939TP_SUPPORT %s\n'%(gSTD_ON(self.cfg.General.J1939TpUsed)));
        fp.write('#define PDUR_SOAD_SUPPORT STD_OFF  /* Not supported */\n\n');
        fp.write('#define PDUR_DEV_ERROR_DETECT		%s\n'%(gSTD_ON(self.cfg.General.DevErrorDetection)));
        fp.write('#define PDUR_VERSION_INFO_API		%s\n\n'%(gSTD_ON(self.cfg.General.VersionInfoAPI)))
        ###################################
        fp.write('// Zero cost operation mode\n');
        fp.write('#define PDUR_ZERO_COST_OPERATION %s\n'%(gSTD_ON(self.cfg.General.ZeroCostOperation)));
        fp.write('#define PDUR_SINGLE_IF %s'%(self.cfg.General.SingleIf));
        fp.write('#define PDUR_SINGLE_TP %s'%(self.cfg.General.SingleTp));
        #####################################
        fp.write('// Gateway operation\n'
            '#define PDUR_GATEWAY_OPERATION				STD_OFF\n'
            '#define PDUR_MEMORY_SIZE					10 /* Not used */\n'
            '#define PDUR_SB_TX_BUFFER_SUPPORT			STD_OFF\n'
            '#define PDUR_FIFO_TX_BUFFER_SUPPORT			STD_OFF\n\n')
        ##########################################
        fp.write('/* The maximum numbers of Tx buffers. */\n'
            '#define PDUR_MAX_TX_BUFFER_NUMBER			10 /* Not used */\n'
            '#define PDUR_N_TP_ROUTES_WITH_BUFFER		"not understand by parai"\n'
            '#define PDUR_N_TP_BUFFERS					"not understand by parai"\n\n');
        ##########################################
        fp.write('// Multicast,not understand by parai\n'
                '#define PDUR_MULTICAST_TOIF_SUPPORT			STD_ON\n'
                '#define PDUR_MULTICAST_FROMIF_SUPPORT		STD_ON\n'
                '#define PDUR_MULTICAST_TOTP_SUPPORT			STD_ON\n'
                '#define PDUR_MULTICAST_FROMTP_SUPPORT		STD_ON\n\n');
        ################################################
        fp.write("""// Minimum routing,not understand by parai
/* Minimum routing not supported.
#define PDUR_MINIMUM_ROUTING_UP_MODULE		COM
#define PDUR_MINIMUM_ROUTING_LO_MODULE		CAN_IF
#define PDUR_MINIMUM_ROUTING_UP_RXPDUID		((PduIdType)100)
#define PDUR_MINIMUM_ROUTING_LO_RXPDUID 	((PduIdType)255)
#define PDUR_MINIMUM_ROUTING_UP_TXPDUID 	((PduIdType)255)
#define PDUR_MINIMUM_ROUTING_LO_TXPDUID 	((PduIdType)255)
*/\n\n""");
        ######################################################
        fp.write("""#if(PDUR_ZERO_COST_OPERATION == STD_ON)
// Zero cost operation support active.
#if PDUR_CANIF_SUPPORT == STD_ON
#define PduR_CanIfRxIndication Com_RxIndication
#define PduR_CanIfTxConfirmation Com_TxConfirmation
#else
#define PduR_CanIfRxIndication(CanRxPduId,PduInfoPtr)
#define PduR_CanIfTxConfirmation(CanTxPduId)
#endif

#if PDUR_CANTP_SUPPORT == STD_ON
#define PduR_CanTpProvideRxBuffer Dcm_ProvideRxBuffer
#define PduR_CanTpRxIndication Dcm_RxIndication
#define PduR_CanTpProvideTxBuffer Dcm_ProvideTxBuffer
#define PduR_CanTpTxConfirmation Dcm_TxConfirmation
#else
#define PduR_CanTpProvideRxBuffer(id,length,PduInfoPtr)
#define PduR_CanTpRxIndication(CanTpRxPduId,Result)
#define PduR_CanTpProvideTxBuffer(CanTpTxId,PduinfoPtr,Length)
#define PduR_CanTpTxConfirmation(CanTpTxPduId,Result)
#endif

#if PDUR_LINIF_SUPPORT == STD_ON 
#define PduR_LinIfRxIndication Com_RxIndication
#define PduR_LinIfTxConfirmation Com_TxConfirmation
#define PduR_LinIfTriggerTransmit Com_TriggerTransmit
#else
#define PduR_LinIfRxIndication(LinRxPduId,PduInfoPtr)
#define PduR_LinIfTxConfirmation(LinTxPduId)
#define PduR_LinIfTriggerTransmit(LinTxPduId,PduInfoPtr)
#endif

#if PDUR_SOAD_SUPPORT == STD_ON
#define PduR_SoAdTpProvideRxBuffer Dcm_ProvideRxBuffer
#define PduR_SoAdTpRxIndication Dcm_RxIndication
#define PduR_SoAdTpProvideTxBuffer Dcm_ProvideTxBuffer
#define PduR_SoAdTpTxConfirmation Dcm_TxConfirmation
#else
#define PduR_SoAdProvideRxBuffer()
#define PduR_SoAdRxIndication()
#define PduR_SoAdProvideTxBuffer()
#define PduR_SoAdTxConfirmation()
#endif

#if PDUR_COM_SUPPORT == STD_ON
#define PduR_ComTransmit CanIf_Transmit
#else
#define PduR_ComTransmit(CanTxPduId,PduInfoPtr)	(E_OK)
#endif

#if PDUR_DCM_SUPPORT == STD_ON
#define PduR_DcmTransmit CanTp_Transmit
#else
#define PduR_DcmTransmit(CanTpTxSduId,CanTpTxInfoPtr)	(E_OK)
#endif
#endif  /* PDUR_ZERO_COST_OPERATION */\n""")
        #######################################################
        fp.write('\n#endif /* PDUR_CFG_H_ */\n\n');
        fp.close();

    def codeGenPbCfgH(self, path):
        file=path+'/PduR_PbCfg.h';
        fp=open(file, 'w');
        fp.write(gcGainOS_TkHead());
        fp.write("""
#ifndef PDUR_PB_CFG_H_H
#define PDUR_PB_CFG_H_H
#if !(((PDUR_SW_MAJOR_VERSION == 2) && (PDUR_SW_MINOR_VERSION == 0)) )
#error PduR: Configuration file expected BSW module version to be 2.0.*
#endif


#if defined(USE_DCM)
#include "Dcm.h"
#endif
#if defined(USE_COM)
#include "Com.h"
#endif
#if defined(USE_CANIF)
#include "CanIf.h"
#endif
#if defined(USE_CANTP)
#include "CanTp.h"
#endif

extern const PduR_PBConfigType PduR_Config;\n""");
        ######################################
        fp.write('//  PduR Polite Defines.\n');
        id=0;
        rstr=tstr='';
        for src in self.cfg.pduRoutingPathList:
            if(src.SrcPduId[:3] == 'RX_'):
                rstr+='#define PDUR_%s %s\n'%(src.SrcPduId,id);
                rstr+='#define %s %s\n'%(src.name,id);
            else:
                tstr+='#define PDUR_%s %s\n'%(src.SrcPduId,id);
                tstr+='#define %s %s\n'%(src.name,id);
            id+=1;
        fp.write('/* PduR Rx NSdu Id */\n');
        fp.write(rstr);
        fp.write('/* PduR Tx NSdu Id */\n');
        fp.write(tstr);
        #######################################
        fp.write('#endif /* PDUR_PB_CFG_H_H */\n\n')
        fp.close();

    def codeGenPbCfgC(self, path):
        file=path+'/PduR_PbCfg.c';
        fp=open(file, 'w');
        fp.write(gcGainOS_TkHead());
        fp.write("""#include "PduR.h"

#if PDUR_CANIF_SUPPORT == STD_ON
#include "CanIf.h"
#endif
#if PDUR_CANTP_SUPPORT == STD_ON
#include "CanTp.h"
#endif
#if PDUR_LINIF_SUPPORT == STD_ON
#include "LinIf.h"
#endif
#if PDUR_COM_SUPPORT == STD_ON
#include "Com.h"
#endif
#if PDUR_DCM_SUPPORT == STD_ON
#include "Dcm.h"
#endif
#if PDUR_J1939TP_SUPPORT == STD_ON
#include "J1939Tp.h"
#endif\n""")
        ###############################################
        str='const PduRTpBufferInfo_type PduRTpBuffers[] = {\n';
        fp.write('//Tp Buffers,not understand by parai\n');
        for buffer in self.cfg.tpBufferList:
            fp.write('uint8 %s[%s];\n'%(buffer.name, buffer.size));
            fp.write('const PduInfoType %s_PduInfo = {\n'%(buffer.name));
            fp.write('\t/* .SduDataPtr = */%s,\n'%(buffer.name));
            fp.write('\t/* .SduLength = */%s\n'%(buffer.size));
            fp.write('};\n');
            str+='\t{\n';
            str+='\t\t/* .pduInfoPtr = */ &%s_PduInfo,\n'%(buffer.name);
            str+='\t\t/* .status = */ PDUR_BUFFER_FREE,\n';
            str+='\t\t/* .bufferSize = */ %s\n'%(buffer.size);
            str+='\t},\n'
        str+='};\n\n';
        if(len(self.cfg.tpBufferList)>0):
            fp.write(str);
        ############################################
        if(len(self.cfg.tpBufferList)>0):
            str = 'const PduRTpBufferInfo_type *PduRTpRouteBufferPtrs[] = {\n'
            for src in self.cfg.pduRoutingPathList:
                str+='\tNULL,/* Now not implemented for %s*/\n'%(src.name);
            str+='};\n\n';
            fp.write(str);
        ###################################################
        for src in self.cfg.pduRoutingPathList:
            str='const PduRDestPdu_type %s_PduRDestination[] = {\n'%(src.name);
            str2='const PduRDestPdu_type * const %s_PduRDestinations[] = {\n'%(src.name);
            index = 0;
            for dest in src.destPathList:
                str+='\t{\n';
                str+='\t\t/* .DataProvision = */ PDUR_%s,\n'%(dest.DataProvision);
                str+='\t\t/* .DestPduId = */ %s_%s,\n'%(dest.DestModule.upper(), dest.DestPduId);
                str+='\t\t/* .TxBufferRef = */ %s,\n'%(dest.TxBufferRef);
                str+='\t\t/* .DestModule = */ ARC_PDUR_%s\n'%(dest.DestModule.upper());
                str+='\t},\n';
                str2+='\t&%s_PduRDestination[%s],/* %s */\n'%(src.name, index, dest.name);
                index+=1;
            str+='};\n'; 
            str2+='\tNULL\n};\n\n';
            fp.write(str);
            fp.write(str2);
        ################################################
        str2='const PduRRoutingPath_type * const PduRRoutingPaths[] = { \n';
        for src in self.cfg.pduRoutingPathList:
            str='const PduRRoutingPath_type %s_PduRRoutingPath = {\n'%(src.name);
            str+='\t/* .SduLength = */ %s,\n'%(src.SduLength);
            str+='\t/* .TpChunkSize = */0xDEAD,\n';
            str+='\t/* .PduRDefaultValue = */{0xDB,NULL},\n';
            str+='\t/* .SrcPduId = */ %s_%s,\n'%(src.SrcModule.upper(), src.SrcPduId);
            str+='\t/* .SrcModule =  */ARC_PDUR_%s,\n'%(src.SrcModule.upper());
            str+='\t/* .PduRDestPdus = */ %s_PduRDestinations\n'%(src.name);
            str+='};\n';
            fp.write(str);
            str2+='\t&%s_PduRRoutingPath,\n'%(src.name);
        str2+='\tNULL\n};\n\n';
        fp.write(str2);
        ################################################
        str='const PduR_PBConfigType PduR_Config = {\n'
        str+='\t/* .PduRConfigurationId = */ 0,\n'
        str+='\t/* .NRoutingPaths = */ %s,\n'%(len(self.cfg.pduRoutingPathList));
        str+='\t/* .RoutingPaths = */ PduRRoutingPaths,\n'
        if(len(self.cfg.tpBufferList)>0):
            str+='\t/* .TpBuffers = */ PduRTpBuffers,\n'
            str+='\t/* .TpRouteBuffers = */ PduRTpRouteBufferPtrs\n'
        else:
            str+='\t/* .TpBuffers = */ NULL,\n'
            str+='\t/* .TpRouteBuffers = */ NULL\n'
        str+='};\n\n'
        fp.write(str);
        ################################################
        fp.close();
            
