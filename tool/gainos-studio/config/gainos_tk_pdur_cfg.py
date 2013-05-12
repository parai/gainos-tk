# -*- coding: utf-8 -*-
"""
/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
"""
from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
from Common import *
import os, sys
import shutil 
from time import localtime, time,strftime
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

    def save(self, fp):
        attrib='DevErrorDetection="%s" '%(self.DevErrorDetection);
        attrib+='VersionInfoAPI="%s" '%(self.VersionInfoAPI);
        attrib+='ZeroCostOperation="%s" '%(self.ZeroCostOperation);
        attrib+='SingleIfEnable="%s" '%(self.SingleIfEnable);
        attrib+='SingleTpEnable="%s" '%(self.SingleTpEnable);
        attrib+='SingleIf="%s" '%(self.SingleIf);
        attrib+='SingleTp="%s" '%(self.SingleTp);
        attrib+='CanIfUsed="%s" '%(self.CanIfUsed);
        attrib+='CanTpUsed="%s" '%(self.CanTpUsed);
        attrib+='ComUsed="%s" '%(self.ComUsed);
        attrib+='DcmUsed="%s" '%(self.DcmUsed);
        attrib+='LinIfUsed="%s" '%(self.LinIfUsed);
        attrib+='LinTpUsed="%s" '%(self.LinTpUsed);
        attrib+='J1939TpUsed="%s" '%(self.J1939TpUsed);
        fp.write('<PduRGeneral %s></PduRGeneral>\n'%(attrib));
    
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

    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib +='DataProvision="%s" '%(self.DataProvision);
        attrib +='DataProvisionEnable="%s" '%(self.DataProvisionEnable);
        attrib +='DestPduId="%s" '%(self.DestPduId);
        attrib +='DestModule="%s" '%(self.DestModule);
        attrib +='DestModuleEnable="%s" '%(self.DestModuleEnable);
        fp.write('<PduRDstPath %s></PduRDstPath>\n'%(attrib));

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

    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib += 'SduLength="%s" '%(self.SduLength);
        attrib += 'SrcPduId="%s" '%(self.SrcPduId);
        attrib += 'SrcModuleEnable="%s" '%(self.SrcModuleEnable);
        attrib += 'SrcModule="%s" '%(self.SrcModule);   
        fp.write('<PduRSrcPath %s>\n'%(attrib));
        self.saveDestPathList(fp);
        fp.write('</PduRSrcPath>\n');

    def saveDestPathList(self, fp):
        fp.write('<PduRDestPathList>\n');
        for dest in self.destPathList:
            dest.save(fp);
        fp.write('</PduRDestPathList>\n');

    def doParseDestPathList(self, list):
        if(list == None):
            return;
        for node in list:
            dest=PduRDstPath('');
            dest.parse(node);
            self.destPathList.append(dest);

    def parse(self, node):
        self.name = node.attrib['name'];
        self.SduLength = int(node.attrib['SduLength']);
        self.SrcPduId = node.attrib['SrcPduId'];
        self.SrcModuleEnable = bool(node.attrib['SrcModuleEnable']);
        self.SrcModule = node.attrib['SrcModule'];
        self.doParseDestPathList(node.find('PduRDestPathList'));

class PduRTpBuffer():
    def __init__(self, name):
        self.name=name;
        self.size=32;

    def save(self, fp):
        fp.write('<PduRTpBuffer name="%s" size="%s"></PduRTpBuffer>\n'%
                 (self.name, self.size));
    
    def parse(self, node):
        self.name =node.attrib['name'];
        self.size =int(node.attrib['size']);

class PduRConfig():
    def __init__(self):
        self.General = PduRGeneral();
        self.pduRoutingPathList=[];
        self.tpBufferList=[]

from PduR_Dlg import *
class PduRObj():
    def __init__(self):
        self.cfg=PduRConfig();
        print "init PduR Object"

    def toString(self):
        str='  Double Clicked to Start to Configure the Pdu Router!\n';
        return str;

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def show(self, cfg):
        depinfo=[];
        obj=self.findObj(cfg.arobjList, 'EcuC');
        if(obj==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(obj.arobj);
        dlg=PduR_Dlg(self.cfg, depinfo);
        dlg.exec_();
 
    def saveSrcPathList(self, fp):
        fp.write('<PduRSrcPathList>\n');
        for src in self.cfg.pduRoutingPathList:
            src.save(fp);
        fp.write('</PduRSrcPathList>\n');

    def saveTpBufferList(self, fp):
        fp.write('<PduRTpBufferList>\n');
        for obj in self.cfg.tpBufferList:
            obj.save(fp);
        fp.write('</PduRTpBufferList>\n');

    def save(self, fp):
        """保存配置信息"""
        self.cfg.General.save(fp);
        self.saveSrcPathList(fp);
        self.saveTpBufferList(fp);
  
    def doParseTpBufferList(self, list):
        if(list == None):
            return;
        for node in list:
            obj = PduRTpBuffer('');
            obj.parse(node);
            self.cfg.tpBufferList.append(obj);

    def doParseSrcPathList(self, list):
        if(list == None):
            return;
        for node in list:
            obj = PduRSrcPath('');
            obj.parse(node);
            self.cfg.pduRoutingPathList.append(obj);

    def doParse(self, arxml):
        self.cfg.General.parse(arxml.find('PduRGeneral'));
        self.doParseTpBufferList(arxml.find('PduRTpBufferList'));
        self.doParseSrcPathList(arxml.find('PduRSrcPathList'));

    def backup(self, file):
        tm=localtime(time());
        file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
        shutil.copy(file, file2+'.bak');

    def codeGen(self, path):
#        path1=path+'/autosar/comstack/config/PduR';
#        try:
#            os.mkdir(path+'/autosar');
#        except:
#            print "nothing serious!file already exists."
#        try:
#            os.mkdir(path+'/autosar/comstack');
#        except:
#            print "nothing serious!file already exists."
#        try:
#            os.mkdir(path+'/autosar/comstack/config');
#        except:
#            print "nothing serious!file already exists."
#        try:
#            os.mkdir(path+'/autosar/comstack/config/PduR');
#        except:
#            print "nothing serious!file already exists."
        self.codeGenH(path);
        self.codeGenPbCfgH(path);
        self.codeGenPbCfgC(path);

    def codeGenH(self, path):
        file=path+'/PduR_Cfg.h';
        if os.path.isfile(file)  and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
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
        if os.path.isfile(file)  and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
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
        if os.path.isfile(file)  and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
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
            
