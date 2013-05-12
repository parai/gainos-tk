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
import xml.etree.ElementTree as ET
class CanTpGeneral():
    def __init__(self):
        self.DevErrorDetection = True;
        self.MainFunctionPeriod = 10; #ms
    def save(self, root):
        nd  = ET.Element('General');
        nd.attrib['DevErrorDetection'] = str(self.DevErrorDetection);
        nd.attrib['MainFunctionPeriod'] = str(self.MainFunctionPeriod);
        root.append(nd);
    def parse(self, nd):
        self.DevErrorDetection = bool(nd.attrib['DevErrorDetection'])
        self.MainFunctionPeriod = int(nd.attrib['MainFunctionPeriod'])

class CanTpRxNPdu():
    def __init__(self, name):
        self.name = name;
        self.PduR_PduId = ''
        self.CanIf_FcPduId = '';
        self.CanTpRxDI = 8; #date length code
        self.CanTpRxPaddingActivation = 'CANTP_OFF';
        self.CanTpRxTaType = 'CANTP_PHYSICAL';
        self.CanTpBs = 4; #if it is MSCAN
        self.CanTpSTmin = 0;
        self.CanTpWftMax = 5; #max FC transfer count
        self.CanTpAddressingFormant = 'CANTP_STANDARD';
        self.CanTpNSa = 0; # extended source address
        self.CanTpNTa = 0; # extended target address
        self.CanTpNar = 100; #ms
        self.CanTpNbr = 100; #ms
        self.CanTpNcr = 100; #ms
    def save(self, root):
        nd = ET.Element('CanTpRxNPdu');
        nd.attrib['name'] = str(self.name);
        nd.attrib['PduR_PduId'] = str(self.PduR_PduId);
        nd.attrib['CanIf_FcPduId'] = str(self.CanIf_FcPduId);
        nd.attrib['CanTpRxDI'] = str(self.CanTpRxDI);
        nd.attrib['CanTpRxPaddingActivation'] = str(self.CanTpRxPaddingActivation);
        nd.attrib['CanTpRxTaType'] = str(self.CanTpRxTaType);
        nd.attrib['CanTpBs'] = str(self.CanTpBs);
        nd.attrib['CanTpSTmin'] = str(self.CanTpSTmin);
        nd.attrib['CanTpWftMax'] = str(self.CanTpWftMax);
        nd.attrib['CanTpAddressingFormant'] = str(self.CanTpAddressingFormant);
        nd.attrib['CanTpNSa'] = str(self.CanTpNSa);
        nd.attrib['CanTpNTa'] = str(self.CanTpNTa);
        nd.attrib['CanTpNar'] = str(self.CanTpNar);
        nd.attrib['CanTpNbr'] = str(self.CanTpNbr);
        nd.attrib['CanTpNcr'] = str(self.CanTpNcr);
        root.append(nd);
    def parse(self, node):
        self.name = node.attrib['name']
        self.PduR_PduId = node.attrib['PduR_PduId'];
        self.CanIf_FcPduId = node.attrib['CanIf_FcPduId'];
        self.CanTpRxDI = int(node.attrib['CanTpRxDI']);
        self.CanTpRxPaddingActivation = node.attrib['CanTpRxPaddingActivation'];
        self.CanTpRxTaType = node.attrib['CanTpRxTaType'];
        self.CanTpBs = int(node.attrib['CanTpBs']);
        self.CanTpSTmin = int(node.attrib['CanTpSTmin']);
        self.CanTpWftMax = int(node.attrib['CanTpWftMax']);
        self.CanTpAddressingFormant = node.attrib['CanTpAddressingFormant'];
        self.CanTpNSa = int(node.attrib['CanTpNSa']);
        self.CanTpNTa = int(node.attrib['CanTpNTa']);
        self.CanTpNar = int(node.attrib['CanTpNar']);
        self.CanTpNbr = int(node.attrib['CanTpNbr']);
        self.CanTpNcr = int(node.attrib['CanTpNcr']);
class CanTpTxNPdu():
    def __init__(self, name):
        self.name = name;
        self.PduR_PduId = ''
        self.CanIf_FcPduId = '';
        self.CanTpTxDI = 8; #date length code
        self.CanTpTxPaddingActivation = 'CANTP_OFF';
        self.CanTpTxTaType = 'CANTP_PHYSICAL';
        self.CanTpAddressingFormant = 'CANTP_STANDARD';
        self.CanTpNSa = 0; # extended source address
        self.CanTpNTa = 0; # extended target address
        self.CanTpNas = 100; #ms
        self.CanTpNbs = 100; #ms
        self.CanTpNcs = 100; #ms
    def save(self, root):
        nd = ET.Element('CanTpTxNPdu');
        nd.attrib['name'] = str(self.name)
        nd.attrib['PduR_PduId'] = str(self.PduR_PduId)
        nd.attrib['CanIf_FcPduId'] = str(self.CanIf_FcPduId)
        nd.attrib['CanTpTxDI'] = str(self.CanTpTxDI)
        nd.attrib['CanTpTxPaddingActivation'] = str(self.CanTpTxPaddingActivation)
        nd.attrib['CanTpTxTaType'] = str(self.CanTpTxTaType)
        nd.attrib['CanTpAddressingFormant'] = str(self.CanTpAddressingFormant)
        nd.attrib['CanTpNSa'] = str(self.CanTpNSa)
        nd.attrib['CanTpNTa'] = str(self.CanTpNTa)
        nd.attrib['CanTpNas'] = str(self.CanTpNas)
        nd.attrib['CanTpNbs'] = str(self.CanTpNbs)
        nd.attrib['CanTpNcs'] = str(self.CanTpNcs)
        root.append(nd);
    def parse(self, node):
        self.name = node.attrib['name'];
        obj.PduR_PduId = node.attrib['PduR_PduId'];
        obj.CanIf_FcPduId = node.attrib['CanIf_FcPduId'];
        obj.CanTpTxDI = int(node.attrib['CanTpTxDI']);
        obj.CanTpTxPaddingActivation = node.attrib['CanTpTxPaddingActivation'];
        obj.CanTpTxTaType = node.attrib['CanTpTxTaType'];
        obj.CanTpAddressingFormant = node.attrib['CanTpAddressingFormant'];
        obj.CanTpNSa = int(node.attrib['CanTpNSa']);
        obj.CanTpNTa = int(node.attrib['CanTpNTa']);
        obj.CanTpNas = int(node.attrib['CanTpNas']);
        obj.CanTpNbs = int(node.attrib['CanTpNbs']);
        obj.CanTpNcs = int(node.attrib['CanTpNcs']);
        
class CanTpConfig():
    def __init__(self):
        self.General = CanTpGeneral();
        self.RxNSduList = [];
        self.TxNSduList = [];


class gainos_tk_cantp_cfg():
    def __init__(self, chip=None):
        self.cfg=CanTpConfig();
        print "init CanTp Object"

    def toString(self):
        str='  Double Clicked to Start to Configure the CanTp!\n';
        return str;

    def show(self, title, fileInd, module_list):
        from cd_cantp import cd_cantp
        depinfo=[];
        md=gcfindModule(module_list, 'EcuC');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg=cd_cantp(title, fileInd, self.cfg, depinfo);
        self.dlg.setModal(False);
        self.dlg.show();

    def save(self, root):
        """保存配置信息"""
        self.cfg.General.save(root);
        nd = ET.Element("RxNSduList");
        for obj in self.cfg.RxNSduList:
            obj.save(nd);
        root.append(nd);
        nd = ET.Element("TxNSduList");
        for obj in self.cfg.TxNSduList:
            obj.save(nd);
        root.append(nd);
        
    def parse(self, root):
        self.cfg.General.parse(root.find('General'));
        for nd in root.find('RxNSduList'):
            obj = CanTpRxNPdu('');
            obj.parse(nd);
            self.cfg.RxNSduList.append(obj);
        for nd in root.find('TxNSduList'):
            obj = CanTpTxNPdu('');
            obj.parse(nd);
            self.cfg.TxNSduList.append(obj);

    def gen(self, path):
        self.codeGenH(path);
        self.codeGenC(path);

    def codeGenH(self, path):
        file=path+'/CanTp_Cfg.h';
        fp=open(file, 'w');
        fp.write('#ifndef CANTP_CFG_H_\n#define CANTP_CFG_H_\n\n');
        fp.write('#include "CanTp_Types.h"\n\n');
        fp.write('#define CANTP_MAIN_FUNCTION_PERIOD_TIME_MS	%s  /* ms */\n'
                 %(self.cfg.General.MainFunctionPeriod));
        fp.write('#define CANTP_CONVERT_MS_TO_MAIN_CYCLES(x) 	(x)/CANTP_MAIN_FUNCTION_PERIOD_TIME_MS\n\n');
        fp.write('#define CANTP_NSDU_CONFIG_LIST_SIZE %s\n'
                 %(len(self.cfg.RxNSduList)+len(self.cfg.TxNSduList)));
        fp.write('#define CANTP_NSDU_RUNTIME_LIST_SIZE %s\n'
                 %(len(self.cfg.RxNSduList)+len(self.cfg.TxNSduList)));
        fp.write('#define CANTP_RXID_LIST_SIZE %s\n\n'
                 %(len(self.cfg.RxNSduList)+len(self.cfg.TxNSduList)));
        fp.write('#define FRTP_CANCEL_TRANSMIT_REQUEST 	STD_OFF\n');
        fp.write('#define CANTP_VERSION_INFO_API STD_OFF   /**< Build version info API */\n');
        fp.write('#define CANTP_DEV_ERROR_DETECT %s\n\n'%(gSTD_ON(self.cfg.General.DevErrorDetection)));
        fp.write('/* CanTp Rx NSdu Id */\n')
        id = 0;
        for obj in self.cfg.RxNSduList:
            fp.write('#define CANTP_%s %s\n'%(obj.PduR_PduId,id));
            id += 1;
        fp.write('\n/* CanTp Tx NSdu Id */\n')
        for obj in self.cfg.TxNSduList:
            fp.write('#define CANTP_%s %s\n'%(obj.PduR_PduId,id));
            id += 1;
        fp.write('\n#define USE_CANIF\n\n');
        fp.write('extern const CanTp_ConfigType CanTpConfig;\n'
                'extern const CanTp_NSduType CanTpNSduConfigList[];\n'
                'extern const CanTp_RxIdType CanTp_RxIdList[];\n')
        fp.write('\n#endif\n\n');
        fp.close();

    def codeGenC(self, path):
        file=path+'/CanTp_Cfg.c';
        if os.path.isfile(file) and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#include "CanTp.h"\n'
                '#if defined(USE_CANIF)\n'
                '#include "CanIf.h"\n'
                '#endif\n'
                '#if defined(USE_PDUR)\n'
                '#include "PduR.h"\n'
                '#endif\n\n');
        fp.write('const CanTp_GeneralType CanTpGeneralConfig =\n'
                '{\n'
                '\t/* .main_function_period = */ %s,\n'
                '};\n\n'%(self.cfg.General.MainFunctionPeriod));
        for obj in self.cfg.RxNSduList+self.cfg.TxNSduList:
            fp.write('//NSa\n'
                    'const CanTp_NSaType CanTpNSaConfig_%s = \n'
                    '{\n'	
                    '\t/* .CanTpNSa = */ %s,\n'
                    '};\n'
                    '//NTa\n'
                    'const CanTp_NTaType CanTpNTaConfig_%s = \n'
                    '{\n'
                    '\t/* .CanTpNTa = */ %s,\n'
                    '};\n\n'%(obj.PduR_PduId, obj.CanTpNSa, obj.PduR_PduId, obj.CanTpNTa));
        sduList='const CanTp_NSduType CanTpNSduConfigList[] =\n'    \
                '{\n';
        for obj in self.cfg.RxNSduList:
            sduList+='\t{\n'
            sduList+='\t\t/* .direction = */ ISO15765_RECEIVE,\n'
            sduList+='\t\t/* .listItemType = */ CANTP_NOT_LAST_ENTRY,\n'
            sduList+='\t\t{\n'
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTp_FcPduId = */ 0xDEAD,\n'
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanIf_FcPduId = */ CANIF_%s,\n'%(obj.CanIf_FcPduId);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.PduR_PduId = */ PDUR_%s,\n'%(obj.PduR_PduId);	
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpAddressingFormant = */ %s,\n'%(obj.CanTpAddressingFormant);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpBs = */ %s,\n'%(obj.CanTpBs);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpNar = */ %s,\n'%(obj.CanTpNar);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpNbr = */ %s,\n'%(obj.CanTpNbr);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpNcr = */ %s,\n'%(obj.CanTpNcr);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpRxChannel = */ CANTP_%s,\n'%(obj.PduR_PduId);    		
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpRxDI = */ %s,\n'%(obj.CanTpRxDI);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpRxPaddingActivation = */ %s,\n'%(obj.CanTpRxPaddingActivation);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpRxTaType = */ %s,\n'%(obj.CanTpRxTaType);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpWftMax = */ %s,\n'%(obj.CanTpWftMax);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpSTmin = */ %s,\n'%(obj.CanTpSTmin);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpNSa = */ &CanTpNSaConfig_%s,\n'%(obj.PduR_PduId);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.CanTpNTa = */ &CanTpNTaConfig_%s,\n'%(obj.PduR_PduId);
            sduList+='\t\t}\n'
            sduList+='\t},\n'
        eol = 0;
        for obj in self.cfg.TxNSduList:
            eol += 1;
            sduList+='\t{\n'
            sduList+='\t\t/* .direction = */ IS015765_TRANSMIT,\n'
            if(eol == len(self.cfg.TxNSduList)):
                sduList+='\t\t/* .listItemType = */ CANTP_END_OF_LIST,\n';
            else:
                sduList+='\t\t/* .listItemType = */ CANTP_NOT_LAST_ENTRY,\n';
            sduList+='\t\t{\n'
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTp_FcPduId = */ 0xDEAD,\n'
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanIf_PduId = */ CANIF_%s,\n'%(obj.PduR_PduId);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.PduR_PduId = */ PDUR_%s,\n'%(obj.PduR_PduId);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpAddressingMode = */ %s,\n'%(obj.CanTpAddressingFormant);
            sduList+='\t\t\t/* .configData.CanTpRxNSdu.reserved_CanTpBs = */ 0xDB,\n'
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpNas = */ %s,\n'%(obj.CanTpNas);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpNbs = */ %s,\n'%(obj.CanTpNbs);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpNcs = */ %s,\n'%(obj.CanTpNcs);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpTxChannel = */ CANTP_%s,\n'%(obj.PduR_PduId);   		
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpTxDI = */ %s,\n'%(obj.CanTpTxDI);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpTxPaddingActivation = */ %s,\n'%(obj.CanTpTxPaddingActivation);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpTxTaType = */ %s,\n'%(obj.CanTpTxTaType);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.reserved_CanTpWftMax = */ 0xDB,\n'
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.reserved_CanTpSTmin = */ 0xDEAD,\n'    		
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpNSa = */ &CanTpNSaConfig_%s,\n'%(obj.PduR_PduId);
            sduList+='\t\t\t/* .configData.CanTpTxNSdu.CanTpNTa = */ &CanTpNTaConfig_%s,\n'%(obj.PduR_PduId);
            sduList+='\t\t}\n'
            sduList+='\t},\n'
        sduList+='};\n\n';
        fp.write(sduList);
        rxIdList='const CanTp_RxIdType CanTp_RxIdList[] = \n'   \
                '{\n';
        index = 0;
        for obj in self.cfg.RxNSduList:
            rxIdList+='\t/* %s */\n'%(obj.PduR_PduId);
            rxIdList+='\t{\n';
            rxIdList+='\t\t/* .CanTpAddressingMode =  */%s,\n'%(obj.CanTpAddressingFormant);
            rxIdList+='\t\t/* .CanTpNSduIndex =  */%s,\n'%(index);
            rxIdList+='\t\t/* .CanTpReferringTxIndex = */ %s,\n'%(self.findCanTpReferringTxIndex(obj));
            rxIdList+='\t},\n'
            index+=1; 
        for obj in self.cfg.TxNSduList:
            rxIdList+='\t/* %s */\n'%(obj.PduR_PduId);
            rxIdList+='\t{\n';
            rxIdList+='\t\t/* .CanTpAddressingMode =  */%s,\n'%(obj.CanTpAddressingFormant);
            rxIdList+='\t\t/* .CanTpNSduIndex =  */%s,\n'%(index);
            rxIdList+='\t\t/* .CanTpReferringTxIndex = */ 0xFFFF,\n';
            rxIdList+='\t},\n'
            index+=1;
        rxIdList+='};\n\n';
        fp.write(rxIdList);
        fp.write('const CanTp_ConfigType CanTpConfig =\n'
                '{\n'
                '\t/* .CanTpGeneral 	= */ 	&CanTpGeneralConfig,\n'
                '\t/* .CanTpNSduList = */	CanTpNSduConfigList,\n'
                '\t/* .CanTpRxIdList = */    CanTp_RxIdList\n'
                '};\n\n');
        fp.close();
    
    def findCanTpReferringTxIndex(self, obj):
        index = len(self.cfg.RxNSduList);
        for obj1 in self.cfg.TxNSduList:
            if(obj.CanIf_FcPduId == obj1.PduR_PduId):
                return index;
            index +=1;
        return 0xFFFF;

