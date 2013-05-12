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

class ComGeneral():
    def __init__(self):
        self.DevErrorDetection = False;

    def save(self, fp):
        fp.write('<ComGeneral>\n');
        fp.write('<DevErrorDetection value="%s"></DevErrorDetection>\n'%(self.DevErrorDetection));
        fp.write('</ComGeneral>\n');

    def parse(self, node):
        self.DevErrorDetection=bool(node.find('DevErrorDetection').attrib['value']);

class ComIPduGroup():
    def __init__(self, name):
        self.name = name;

    def save(self, fp):
        fp.write('<ComIPduGroup name="%s"></ComIPduGroup>\n'%(self.name));

    def parse(self, node):
        self.name = node.attrib['name'];

class ComSignal():
    def __init__(self, name):
        self.name = name;
        self.isSignalGroup=False;
        self.ComBitPosition = 0;#应该是8的整数倍
        self.ComBitSize = 8;
        self.ComErrorNotification = 'NULL';
        self.ComFirstTimeoutFactor = 10;
        self.ComNotification = name+'_Notification';
        self.ComRxDataTimeoutAction = 'NONE';
        self.ComSignalEndianess = 'COM_BIG_ENDIAN';
        self.ComSignalInitValue = '0x00';
        self.ComSignalType = 'UINT8';
        self.ComTimeoutFactor =10;
        self.ComTimeoutNotification = name+'_TimeoutNotification';
        self.ComTransferProperty = 'TRIGGERED';
        self.ComUpdateBitPosition = 0;
        self.ComSignalArcUseUpdateBit = False;

    def codeGenInitValue(self, fp):
        if(self.ComSignalType == 'UINT8_N' or self.ComSignalType == 'UINT8_DYN'):
            array = self.ComSignalInitValue.split(' ');
            fp.write('const uint8 %s_InitValue[] ={'%(self.name));
            for vl in array:
                fp.write('%s, '%(vl));
            fp.write('};\n');
        else:
            fp.write('const %s %s_InitValue = %s;\n'%(str(self.ComSignalType).lower(), self.name, self.ComSignalInitValue));
    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib += 'ComBitPosition="%s" '%(self.ComBitPosition);
        attrib += 'ComBitSize="%s" '%(self.ComBitSize);
        attrib += 'ComErrorNotification="%s" '%(self.ComErrorNotification);
        attrib += 'ComFirstTimeoutFactor="%s" '%(self.ComFirstTimeoutFactor);
        attrib += 'ComNotification="%s" '%(self.ComNotification);
        attrib += 'ComRxDataTimeoutAction="%s" '%(self.ComRxDataTimeoutAction);
        attrib += 'ComSignalEndianess="%s" '%(self.ComSignalEndianess);
        attrib += 'ComSignalInitValue="%s" '%(self.ComSignalInitValue);
        attrib += 'ComSignalType="%s" '%(self.ComSignalType);
        attrib += 'ComTimeoutFactor="%s" '%(self.ComTimeoutFactor);
        attrib += 'ComTimeoutNotification="%s" '%(self.ComTimeoutNotification);
        attrib += 'ComTransferProperty="%s" '%(self.ComTransferProperty);
        attrib += 'ComUpdateBitPosition="%s" '%(self.ComUpdateBitPosition);
        attrib += 'ComSignalArcUseUpdateBit="%s" '%(self.ComSignalArcUseUpdateBit);
        fp.write('<ComSignal %s></ComSignal>\n'%(attrib));

    def parse(self, node):
        self.name = node.attrib['name'];
        self.ComBitPosition = int(node.attrib['ComBitPosition']);
        self.ComBitSize = int(node.attrib['ComBitSize']);
        self.ComErrorNotification = node.attrib['ComErrorNotification'];
        self.ComFirstTimeoutFactor = int(node.attrib['ComFirstTimeoutFactor']);
        self.ComNotification = node.attrib['ComNotification'];
        self.ComRxDataTimeoutAction = node.attrib['ComRxDataTimeoutAction'];
        self.ComSignalEndianess = node.attrib['ComSignalEndianess'];
        self.ComSignalInitValue = node.attrib['ComSignalInitValue'];
        self.ComSignalType = node.attrib['ComSignalType'];
        self.ComTimeoutFactor = int(node.attrib['ComTimeoutFactor']);
        self.ComTimeoutNotification = node.attrib['ComTimeoutNotification'];
        self.ComTransferProperty = node.attrib['ComTransferProperty'];
        self.ComUpdateBitPosition = int(node.attrib['ComUpdateBitPosition']);
        self.ComSignalArcUseUpdateBit = bool(node.attrib['ComSignalArcUseUpdateBit']);

class ComGroupSignal():
    def __init__(self, name):
        self.name = name;
        self.ComSignalType = 'UINT8';
        self.ComSignalEndianess = 'COM_BIG_ENDIAN';
        self.ComBitPosition = 0;#应该是8的整数倍
        self.ComBitSize = 8;
        self.ComSignalInitValue = '0x00';

    def codeGenInitValue(self, fp):
        if(self.ComSignalType == 'UINT8_N'):
            array = self.ComSignalInitValue.split(' ');
            fp.write('const uint8 %s_InitValue[] ={'%(self.name));
            for vl in array:
                fp.write('%s, '%(vl));
            fp.write('};\n');
        else:
            fp.write('const %s %s_InitValue = %s;\n'%(self.ComSignalType.lower(), self.name, self.ComSignalInitValue));
    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib += 'ComSignalType="%s" '%(self.ComSignalType);
        attrib += 'ComSignalEndianess="%s" '%(self.ComSignalEndianess);
        attrib += 'ComBitPosition="%s" '%(self.ComBitPosition);
        attrib += 'ComBitSize="%s" '%(self.ComBitSize);
        attrib += 'ComSignalInitValue="%s" '%(self.ComSignalInitValue);
        fp.write('<ComGroupSignal %s></ComGroupSignal>\n'%(attrib));
    
    def parse(self, node):
        self.name = node.attrib['name'];
        self.ComSignalType = node.attrib['ComSignalType'];
        self.ComSignalEndianess = node.attrib['ComSignalEndianess'];
        self.ComBitPosition = int(node.attrib['ComBitPosition']);
        self.ComBitSize = int(node.attrib['ComBitSize']);
        self.ComSignalInitValue = node.attrib['ComSignalInitValue'];

class ComSignalGroup():
    def __init__(self, name):
        self.name = name;
        self.isSignalGroup=True;
        self.ComTransferProperty = 'TRIGGERED';
        self.ComUpdateBitPosition = 0;
        self.ComSignalArcUseUpdateBit = False;
        self.ComBitPosition = 0;#应该是8的整数倍
        self.ComBitSize = 8;
        self.ComFirstTimeoutFactor = 10;
        self.ComTimeoutFactor = 10;
        self.ComNotification = name+'_Notification';
        self.ComTimeoutNotification = name+'_TimeoutNotification';
        self.groupSignalList = [];

    def sizeInByte(self):
        """ComSignalGroup有ComBitSize配置位，所以。。。"""
        sizeInBit=self.ComBitSize;
        if(self.ComSignalArcUseUpdateBit == True):
            sizeInBit +=1;
        sizeInByte = (sizeInBit+7)/8;
        #print 'sizeInByte:', sizeInByte
        return sizeInByte;

    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib += 'ComTransferProperty="%s" '%(self.ComTransferProperty);
        attrib += 'ComUpdateBitPosition="%s" '%(self.ComUpdateBitPosition);
        attrib += 'ComSignalArcUseUpdateBit="%s" '%(self.ComSignalArcUseUpdateBit);
        attrib += 'ComBitPosition="%s" '%(self.ComBitPosition);
        attrib += 'ComBitSize="%s" '%(self.ComBitSize);
        attrib += 'ComFirstTimeoutFactor="%s" '%(self.ComFirstTimeoutFactor);
        attrib += 'ComTimeoutFactor="%s" '%(self.ComTimeoutFactor);
        attrib += 'ComNotification="%s" '%(self.ComNotification);
        attrib += 'ComTimeoutNotification="%s" '%(self.ComTimeoutNotification);
        fp.write('<ComSignalGroup %s>\n'%(attrib));
        #save groupSignalList
        fp.write('<ComGroupSignalList>\n');
        for obj in self.groupSignalList:
            obj.save(fp);
        fp.write('</ComGroupSignalList>\n'); 
        fp.write('</ComSignalGroup>\n')

    def parse(self, node):
        self.name  = node.attrib['name'];
        self.ComTransferProperty  = node.attrib['ComTransferProperty'];
        self.ComUpdateBitPosition  = int(node.attrib['ComUpdateBitPosition']);
        self.ComSignalArcUseUpdateBit  = bool(node.attrib['ComSignalArcUseUpdateBit']);
        self.ComBitPosition  = int(node.attrib['ComBitPosition']);
        self.ComBitSize  = int(node.attrib['ComBitSize']);
        self.ComFirstTimeoutFactor  = int(node.attrib['ComFirstTimeoutFactor']);
        self.ComTimeoutFactor  = int(node.attrib['ComTimeoutFactor']);
        self.ComNotification  = node.attrib['ComNotification'];
        self.ComTimeoutNotification  = node.attrib['ComTimeoutNotification'];
        if(node.find('ComGroupSignalList') != None):
            for nd in node.find('ComGroupSignalList'):
                obj = ComGroupSignal('');
                obj.parse(nd);
                self.groupSignalList.append(obj);
    
class ComIPdu():
    def __init__(self, name):
        self.name = name;
        self.ComIPduCallout = name+'_Callout';
        self.ArcIPduOutgoingId ='';
        self.ComIPduSignalProcessing ='DEFERRED';
        #self.ComIPduSize = 64;#should calculate it
        self.ComIPduDirection = 'SEND';
        self.ComIPduGroupRef = '';
        self.ComTxIPduMinimumDelayFactor = 1;
        self.ComTxIPduUnusedAreasDefault = 0;
        self.ComTxModeMode = 'PERIODIC';
        self.ComTxModeNumberOfRepetitions = 0;
        self.ComTxModeRepetitionPeriodFactor = 10;
        self.ComTxModeTimeOffsetFactor = 20;
        self.ComTxModeTimePeriodFactor = 10;
        self.signalList = [];
        self.signalGroupList = [];
    
    def sizeInByte(self):
        return 8;##Arccore 的代码实现决定了必须为8字节
        sizeInByte = 0;
        for sig in self.signalList:
            #基于配置原则，每个信号起始地址必须是8 bit的整数倍，
            #从而，每个信号实际占用的bit size必须是8 bit的整数倍
            #且必须连续配置，若信号地址不连续，则出错
            sizeInBit = sig.ComBitSize;
            if(sig.ComSignalArcUseUpdateBit == True):
                sizeInBit +=1;
            sizeInByte += (sizeInBit+7)/8;
        #print 'sizeInByte:', sizeInByte
        for sig in self.signalGroupList:
            sizeInByte += sig.sizeInByte();
        return sizeInByte;

    def save(self, fp):
        attrib = 'name="%s" '%(self.name);
        attrib += 'ComIPduCallout="%s" '%(self.ComIPduCallout);
        attrib += 'ArcIPduOutgoingId="%s" '%(self.ArcIPduOutgoingId);
        attrib += 'ComIPduSignalProcessing="%s" '%(self.ComIPduSignalProcessing);
        attrib += 'ComIPduDirection="%s" '%(self.ComIPduDirection);
        attrib += 'ComIPduGroupRef="%s" '%(self.ComIPduGroupRef);
        attrib += 'ComTxIPduMinimumDelayFactor="%s" '%(self.ComTxIPduMinimumDelayFactor);
        attrib += 'ComTxIPduUnusedAreasDefault="%s" '%(self.ComTxIPduUnusedAreasDefault);
        attrib += 'ComTxModeMode="%s" '%(self.ComTxModeMode);
        attrib += 'ComTxModeNumberOfRepetitions="%s" '%(self.ComTxModeNumberOfRepetitions);
        attrib += 'ComTxModeRepetitionPeriodFactor="%s" '%(self.ComTxModeRepetitionPeriodFactor);
        attrib += 'ComTxModeTimeOffsetFactor="%s" '%(self.ComTxModeTimeOffsetFactor);
        attrib += 'ComTxModeTimePeriodFactor="%s" '%(self.ComTxModeTimePeriodFactor);
        fp.write('<ComIPdu %s>\n'%(attrib));
        #save signalList
        fp.write('<ComSignalList>\n');
        for obj in self.signalList:
            obj.save(fp);
        fp.write('</ComSignalList>\n');
        #save signalGroupList
        fp.write('<ComSignalGroupList>\n');
        for obj in self.signalGroupList:
            obj.save(fp);
        fp.write('</ComSignalGroupList>\n');
        fp.write('</ComIPdu>\n');

    def parse(self, node):
        self.name = node.attrib['name'];
        self.ComIPduCallout = node.attrib['ComIPduCallout'];
        self.ArcIPduOutgoingId = node.attrib['ArcIPduOutgoingId'];
        self.ComIPduSignalProcessing = node.attrib['ComIPduSignalProcessing'];
        self.ComIPduDirection = node.attrib['ComIPduDirection'];
        self.ComIPduGroupRef = node.attrib['ComIPduGroupRef'];
        self.ComTxIPduMinimumDelayFactor = int(node.attrib['ComTxIPduMinimumDelayFactor']);
        self.ComTxIPduUnusedAreasDefault = int(node.attrib['ComTxIPduUnusedAreasDefault']);
        self.ComTxModeMode = node.attrib['ComTxModeMode'];
        self.ComTxModeNumberOfRepetitions = int(node.attrib['ComTxModeNumberOfRepetitions']);
        self.ComTxModeRepetitionPeriodFactor = int(node.attrib['ComTxModeRepetitionPeriodFactor']);
        self.ComTxModeTimeOffsetFactor = int(node.attrib['ComTxModeTimeOffsetFactor']);
        self.ComTxModeTimePeriodFactor = int(node.attrib['ComTxModeTimePeriodFactor']);
        if(node.find('ComSignalList') != None):
            for nd in node.find('ComSignalList'):
                obj = ComSignal('');
                obj.parse(nd);
                self.signalList.append(obj);
        if(node.find('ComSignalGroupList') != None):
            for nd in node.find('ComSignalGroupList'):
                obj = ComSignalGroup('');
                obj.parse(nd);
                self.signalGroupList.append(obj);

class ComConfig():
    def __init__(self):
        self.General=ComGeneral();
        self.IPduGroupList = [];
        self.IPduList = [];

from Com_Dlg import *
class ComObj():
    def __init__(self):
        self.cfg=ComConfig();
        print "init Com Object"

    def toString(self):
        str='  Double Clicked to Start to Configure the Com!\n';
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
        dlg=Com_Dlg(self.cfg, depinfo);
        dlg.exec_();
  
    def saveIPduGroup(self, fp):
        fp.write('<ComIPduGroupList>\n');
        for obj in self.cfg.IPduGroupList:
            obj.save(fp);
        fp.write('</ComIPduGroupList>\n');

    def saveIPdu(self, fp):
        fp.write('<ComIPduList>\n');
        for obj in self.cfg.IPduList:
            obj.save(fp);
        fp.write('</ComIPduList>\n');
    
    def save(self, fp):
        """保存配置信息"""
        self.cfg.General.save(fp);
        self.saveIPduGroup(fp);
        self.saveIPdu(fp);
    
    def doParseIPduGroup(self, list):
        for node in list:
            obj = ComIPduGroup('');
            obj.parse(node);
            self.cfg.IPduGroupList.append(obj);

    def doParseIPdu(self, list):
        for node in list:
            obj = ComIPdu('');
            obj.parse(node);
            self.cfg.IPduList.append(obj);
    
    def doParse(self, arxml):
        self.cfg.General.parse(arxml.find('ComGeneral'));
        self.doParseIPduGroup(arxml.find('ComIPduGroupList'));
        self.doParseIPdu(arxml.find('ComIPduList'));

    def backup(self, file):
        tm=localtime(time());
        file2=file+strftime("-%Y-%m-%d-%H-%M-%S",tm);
        shutil.copy(file, file2+'.bak');

    def codeGen(self, path):
#        path1=path+'/autosar/comstack/config/Com';
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
#            os.mkdir(path+'/autosar/comstack/config/Com');
#        except:
#            print "nothing serious!file already exists."
        self.codeGenCfgH(path);
        self.codeGenPbCfgH(path);
        self.codeGenPbCfgC(path);

    def codeGenCfgH(self, path):
        file=path+'/Com_Cfg.h';
        if os.path.isfile(file) and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 2)))\n'
                '#error Com: Configuration file expected BSW module version to be 1.2.*\n'
                '#endif\n\n');
        fp.write('#ifndef COM_CFG_H_\n#define COM_CFG_H_\n\n');
        fp.write('#define COM_MODULE_ID 20\n'
                '#define COM_INSTANCE_ID 1\n'
                '#define COM_E_INVALID_FILTER_CONFIGURATION 101\n'
                '#define COM_E_INITIALIZATION_FAILED 102\n'
                '#define COM_E_INVALID_SIGNAL_CONFIGURATION 103\n'
                '#define COM_INVALID_PDU_ID 104\n'
                '#define COM_INVALID_SIGNAL_ID 109\n'
                '#define COM_ERROR_SIGNAL_IS_SIGNALGROUP 105\n'
                '#define COM_E_TOO_MANY_IPDU 106\n'
                '#define COM_E_TOO_MANY_SIGNAL 107\n'
                '#define COM_E_TOO_MANY_GROUPSIGNAL 108\n'
                '#define CPU_ENDIANESS COM_BIG_ENDIAN\n\n');
        fp.write('#define COM_DEV_ERROR_DETECT %s\n\n'%(gSTD_ON(self.cfg.General.DevErrorDetection)));
        fp.write('#define COM_N_IPDUS %s\n'%(len(self.cfg.IPduList)));
        cnt =cnt2 = 0;
        for obj in self.cfg.IPduList:
            cnt += len(obj.signalList) + len(obj.signalGroupList);
            for sig in obj.signalGroupList:
                cnt2 += len(sig.groupSignalList);
        fp.write('#define COM_N_SIGNALS %s\n'%(cnt));
        fp.write('#define COM_N_GROUP_SIGNALS %s\n\n'%(cnt2));
        fp.write('#define ComConfigurationTimeBase 0\n'
                '#define ComVersionInfoApi\n'
                '#define USE_PDUR\n'
                '#endif /*COM_CFG_H*/\n\n');
        fp.close();

    def codeGenPbCfgH(self, path):
        file=path+'/Com_PbCfg.h';
        if os.path.isfile(file) and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 2)) )\n'
                '#error Com: Configuration file expected BSW module version to be 1.2.*\n'
                '#endif\n\n'
                '#ifndef COM_PBCFG_H\n'
                '#define COM_PBCFG_H\n\n'
                '#include "Com_Types.h"\n\n'
                'extern const Com_ConfigType ComConfiguration;\n\n');
        fp.write('// PDU group id definitions\n');
        id=0;
        for obj in self.cfg.IPduGroupList:
            fp.write('#define %s %s\n'%(obj.name,id));
            id+=1;
        fp.write('\n//  COM IPDU Id Defines.\n');
        id = 0;
        for ipdu in self.cfg.IPduList:
            fp.write('#define %s %s\n'%(ipdu.name,id));
            fp.write('#define COM_%s %s\t/* for %s */\n'%(ipdu.ArcIPduOutgoingId,id,ipdu.name));
            id+=1;
        fp.write('\n//General Signal (Group) Id defines\n');
        id = 0;
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalList+ipdu.signalGroupList:
                fp.write('#define %s %s\n'%(sig.name,id));
                id+=1;
        fp.write('\n//Group Signal Id defines\n');
        id=0;
        for ipdu in self.cfg.IPduList:
            for grpsig in ipdu.signalGroupList:
                for sig in grpsig.groupSignalList:
                   fp.write('#define %s %s\n'%(sig.name,id)); 
                   id+=1;
        fp.write('\n// Notifications\n');
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalList+ipdu.signalGroupList:
                if(sig.ComNotification!= 'NULL'):
                    fp.write('extern void %s(void);\n'%(sig.ComNotification));
                if(sig.ComTimeoutNotification!= 'NULL'):
                    fp.write('extern void %s(void);\n'%(sig.ComTimeoutNotification));
        fp.write('\n// Callouts\n');
        for ipdu in self.cfg.IPduList:
            if(ipdu.ComIPduCallout != 'NULL'):
                fp.write('extern boolean %s(PduIdType PduId, const uint8 *IPduData);\n'%(ipdu.ComIPduCallout));
        fp.write('#endif /* COM_PBCFG_H */\n\n')
        fp.close();

    def codeGenPbCfgC(self, path):
        file=path+'/Com_PbCfg.c';
        if os.path.isfile(file) and File_BakeUp_On_Gen:
            self.backup(file);
        fp=open(file, 'w');
        fp.write('#include "Com.h"\n'
                '#include "Com_Internal.h"\n'
                '//#include <stdlib.h>\n'
                '#if defined(USE_PDUR)\n'
                '#include "PduR.h"\n'
                '#endif\n\n');
        ########### init value###################
        fp.write('//Signal init values.\n');
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalList:
                sig.codeGenInitValue(fp);
            for grpsig in ipdu.signalGroupList:
                for sig in grpsig.groupSignalList:
                    sig.codeGenInitValue(fp);
        ########## Group Signal#################
        fp.write('\n//Group signal definitions\n');
        str = '#if(COM_N_GROUP_SIGNALS > 0)\n'\
            'const ComGroupSignal_type ComGroupSignal[] = {\n'
        cnt = 0;
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalGroupList:
                for grpsig in sig.groupSignalList:
                    cnt+=1;
        eol =0;
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalGroupList:
                for grpsig in sig.groupSignalList:
                    eol+=1;
                    str+='\t{\n';
                    str+='\t\t/*ComBitPosition=*/ %s,\n'%(grpsig.ComBitPosition);
                    str+='\t\t/*ComBitSize=*/ %s,\n'%(grpsig.ComBitSize);
                    str+='\t\t/*ComHandleId=*/ %s,\n'%(grpsig.name);
                    str+='\t\t/*ComSignalEndianess=*/ %s,\n'%(grpsig.ComSignalEndianess);
                    if(grpsig.ComSignalType != 'UNIT8_N'):
                        str+='\t\t/*ComSignalInitValue=*/ &%s_InitValue,\n'%(grpsig.name);
                    else:
                        str+='\t\t/*ComSignalInitValue=*/ %s_InitValue,\n'%(grpsig.name);
                    str+='\t\t/*ComSignalType=*/ %s,\n'%(grpsig.ComSignalType);
                    if(eol == cnt):
                        str+='\t\t/*Com_Arc_EOL=*/ TRUE\n';
                    else:
                        str+='\t\t/*Com_Arc_EOL=*/ FALSE\n';
                    str+='\t},\n'
        str+='};\n\n';
        fp.write(str);
        fp.write('/* SignalGroup GroupSignals lists. */\n');
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalGroupList:
                str='const ComGroupSignal_type * const %s_SignalRefs[] = {\n'%(sig.name);
                for grpsig in sig.groupSignalList:
                    str+='\t&ComGroupSignal[ %s ],\n'%(grpsig.name);
                str+='\tNULL\n};\n'
                fp.write(str);
        fp.write('#endif\t/* COM_N_GROUP_SIGNALS */\n\n');
        #########/* IPdu buffers and signal group buffers */#########
        fp.write('/* IPdu buffers and signal group buffers */\n');
        for ipdu in self.cfg.IPduList:
            fp.write('uint8 %s_IPduBuffer[%s];\n'%(ipdu.name, ipdu.sizeInByte()));
            if(ipdu.ComIPduDirection == 'RECEIVE' and ipdu.ComIPduSignalProcessing=='DEFERRED'):
                fp.write('uint8 %s_IPduDeferredRxBuffer[%s];\n'%(ipdu.name, ipdu.sizeInByte()));
            for siggrp in ipdu.signalGroupList:
                fp.write('uint8 %s_SignalGroupBuffer[%s];\n'%(siggrp.name, siggrp.sizeInByte()));                
        ##########Signal definitions####################
        cnt =0;
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalList:
                cnt+=1;
            for grpsig in ipdu.signalGroupList:
                cnt+=1;
        fp.write('\n//Signal definitions\n');
        str='const ComSignal_type ComSignal[] = {\n';
        eol=0;
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalList:
                eol+=1;
                str+='\t{\n';
                str+='\t\t/* .ComBitPosition = */ %s,\n'%(sig.ComBitPosition);
                str+='\t\t/* .ComBitSize = */ %s,\n'%(sig.ComBitSize);
                str+='\t\t/* .ComErrorNotification = */ NULL,\n'
                str+='\t\t/* .ComFirstTimeoutFactor = */ %s,\n'%(sig.ComFirstTimeoutFactor);
                str+='\t\t/* .ComHandleId = */ %s,\n'%(sig.name);
                str+='\t\t/* .ComNotification = */ %s,\n'%(sig.ComNotification);
                str+='\t\t/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_%s,\n'%(sig.ComRxDataTimeoutAction);
                str+='\t\t/* .ComSignalEndianess = */ %s,\n'%(sig.ComSignalEndianess);
                if(sig.ComSignalType != 'UNIT8_N' or sig.ComSignalType != 'UNIT8_DYN'):
                    str+='\t\t/* .ComSignalInitValue = */ &%s_InitValue,\n'%(sig.name);
                else:
                    str+='\t\t/* .ComSignalInitValue = */ %s_InitValue,\n'%(sig.name);
                str+='\t\t/* .ComSignalType = */ %s,\n'%(sig.ComSignalType);
                str+='\t\t/* .ComTimeoutFactor = */ %s,\n'%(sig.ComTimeoutFactor);
                str+='\t\t/* .ComTimeoutNotification = */ %s,\n'%(sig.ComTimeoutNotification);
                str+='\t\t/* .ComTransferProperty = */ %s,\n'%(sig.ComTransferProperty);
                str+='\t\t/* .ComUpdateBitPosition = */ %s,\n'%(sig.ComUpdateBitPosition);
                str+='\t\t/* .ComSignalArcUseUpdateBit = */ %s,\n'%(TRUE(sig.ComSignalArcUseUpdateBit));
                str+='\t\t/* .Com_Arc_IsSignalGroup = */ FALSE,\n';
                str+='\t\t/* .ComGroupSignal = */ NULL,\n';
                str+='\t\t/* .Com_Arc_ShadowBuffer = */ NULL,\n';
                str+='\t\t/* .ComIPduHandleId = */ %s,\n'%(ipdu.name);
                if(eol==cnt):
                    str+='\t\t/* .Com_Arc_EOL = */ TRUE\n';
                else:
                    str+='\t\t/* .Com_Arc_EOL = */ FALSE\n';
                str+='\t},\n';
            for sig in ipdu.signalGroupList:
                eol+=1;
                str+='\t{\n';
                str+='\t\t/* .ComBitPosition = */ %s,\n'%(sig.ComBitPosition);
                str+='\t\t/* .ComBitSize = */ %s,\n'%(sig.ComBitSize);
                str+='\t\t/* .ComErrorNotification = */ NULL,\n'
                str+='\t\t/* .ComFirstTimeoutFactor = */ %s,\n'%(sig.ComFirstTimeoutFactor);
                str+='\t\t/* .ComHandleId = */ %s,\n'%(sig.name);
                str+='\t\t/* .ComNotification = */ %s,\n'%(sig.ComNotification);
                str+='\t\t/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,\n';
                str+='\t\t/* .ComSignalEndianess = */ COM_OPAQUE,\n'
                str+='\t\t/* .ComSignalInitValue = */ NULL,\n';
                str+='\t\t/* .ComSignalType = */ UINT8_N,\n';
                str+='\t\t/* .ComTimeoutFactor = */ %s,\n'%(sig.ComTimeoutFactor);
                str+='\t\t/* .ComTimeoutNotification = */ %s,\n'%(sig.ComTimeoutNotification);
                str+='\t\t/* .ComTransferProperty = */ %s,\n'%(sig.ComTransferProperty);
                str+='\t\t/* .ComUpdateBitPosition = */ %s,\n'%(sig.ComUpdateBitPosition);
                str+='\t\t/* .ComSignalArcUseUpdateBit = */ %s,\n'%(TRUE(sig.ComSignalArcUseUpdateBit));
                str+='\t\t/* .Com_Arc_IsSignalGroup = */ TRUE,\n';
                str+='\t\t/* .ComGroupSignal = */ %s_SignalRefs,\n'%(sig.name);
                str+='\t\t/* .Com_Arc_ShadowBuffer = */ %s_SignalGroupBuffer,\n'%(sig.name);
                str+='\t\t/* .ComIPduHandleId = */ %s,\n'%(ipdu.name);
                if(eol==cnt):
                    str+='\t\t/* .Com_Arc_EOL = */ TRUE\n';
                else:
                    str+='\t\t/* .Com_Arc_EOL = */ FALSE\n';
                str+='\t},\n'; 
        str+='};\n\n'
        fp.write(str);
        #######I-PDU group definitions######################
        fp.write('//I-PDU group definitions\n');
        str= 'const ComIPduGroup_type ComIPduGroup[] = {\n'
        eol=0;
        for grp in self.cfg.IPduGroupList:
            eol+=1;
            str+='\t{\n';
            str+='\t\t/* .ComIPduGroupHandleId = */ %s,\n'%(grp.name);
            if(eol==len(self.cfg.IPduGroupList)):
                str+='\t\t/* .Com_Arc_EOL = */ TRUE\n';
            else:
                str+='\t\t/* .Com_Arc_EOL = */ FALSE\n';
            str+='\t},\n';
        str+='};\n\n';
        fp.write(str);
        ####################/* IPdu signal lists. */############
        fp.write('/* IPdu signal lists. */\n');
        for ipdu in self.cfg.IPduList:
            str='const ComSignal_type * const %s_SignalRefs[] = {\n'%(ipdu.name);
            for sig in ipdu.signalList+ipdu.signalGroupList:
                str+='\t&ComSignal[ %s ],\n'%(sig.name);
            str+='\tNULL\n};\n'
            fp.write(str);
        #####################I-PDU definitions################
        fp.write('//I-PDU definitions\n');
        str='const ComIPdu_type ComIPdu[] = {\n';
        eol=0;
        for ipdu in  self.cfg.IPduList:
            eol+1;
            str+='\t{// %s\n'%(ipdu.name);
            str+='\t\t/* .ComIPduCallout = */ %s,\n'%(ipdu.ComIPduCallout);
            str+='\t\t/* .ArcIPduOutgoingId = */ PDUR_%s,\n'%(ipdu.ArcIPduOutgoingId);
            str+='\t\t/* .ComIPduSignalProcessing = */ %s,\n'%(ipdu.ComIPduSignalProcessing);
            str+='\t\t/* .ComIPduSize = */ %s,\n'%(ipdu.sizeInByte());
            str+='\t\t/* .ComIPduDirection = */ %s,\n'%(ipdu.ComIPduDirection);
            str+='\t\t/* .ComIPduGroupRef = */ %s,\n'%(ipdu.ComIPduGroupRef);
            str+='\t\t{/* .ComTxIPdu = */\n'
            str+='\t\t\t/* .ComTxIPduMinimumDelayFactor = */ %s,\n'%(ipdu.ComTxIPduMinimumDelayFactor);
            str+='\t\t\t/* .ComTxIPduUnusedAreasDefault = */ %s,\n'%(ipdu.ComTxIPduUnusedAreasDefault);
            str+='\t\t\t{/* .ComTxModeTrue = */\n';
            str+='\t\t\t\t/* .ComTxModeMode =  */ %s,\n'%(ipdu.ComTxModeMode);
            str+='\t\t\t\t/* .ComTxModeNumberOfRepetitions =  */ %s,\n'%(ipdu.ComTxModeNumberOfRepetitions);
            str+='\t\t\t\t/* .ComTxModeRepetitionPeriodFactor =  */ %s,\n'%(ipdu.ComTxModeRepetitionPeriodFactor);
            str+='\t\t\t\t/* .ComTxModeTimeOffsetFactor =  */ %s,\n'%(ipdu.ComTxModeTimeOffsetFactor);
            str+='\t\t\t\t/* .ComTxModeTimePeriodFactor =  */ %s,\n'%(ipdu.ComTxModeTimePeriodFactor);
            str+='\t\t\t},\n'
            str+='\t\t},\n'
            str+='\t\t/* .ComIPduDataPtr = */ %s_IPduBuffer,\n'%(ipdu.name);
            if(ipdu.ComIPduDirection=='RECEIVE' and ipdu.ComIPduSignalProcessing == 'DEFERRED'):
                str+='\t\t/* .ComIPduDeferredDataPtr = */ %s_IPduDeferredRxBuffer,\n'%(ipdu.name);
            else:
                str+='\t\t/* .ComIPduDeferredDataPtr = */ NULL,\n';
            str+='\t\t/* .ComIPduGroupRef = */ %s_SignalRefs,\n'%(ipdu.name);
            lastsig = ipdu.signalList[len(ipdu.signalList)-1];
            if(lastsig.ComSignalType == 'UINT8_DYN'):
                str+='\t\t/* .ComIPduDynSignalRef = */ &ComSignal[ %s ],\n'%(lastsig.name);
            else:
                str+='\t\t/* .ComIPduDynSignalRef = */ NULL,\n';
            if(eol==len(self.cfg.IPduList)):
                str+='\t\t/* .Com_Arc_EOL = */ TRUE,\n';
            else:
                str+='\t\t/* .Com_Arc_EOL = */ FALSE,\n';
            str+='\t},\n'
        str+='};\n\n';
        fp.write(str);
        #############Last
        fp.write('const Com_ConfigType ComConfiguration = {\n'
                '\t/* .ComConfigurationId = */ 1,\n'
                '\t/* .ComIPdu = */ ComIPdu,\n'
                '\t/* .ComIPduGroup = */ ComIPduGroup,\n'
                '\t/* .ComSignal = */ ComSignal,\n'
                '#if(COM_N_GROUP_SIGNALS > 0)\n'
                '\t/* .ComGroupSignal = */ ComGroupSignal\n'
                '#else\n'
                '\t/* .ComGroupSignal = */ NULL\n'
                '#endif\n'
                '};\n\n');
        ######### Arc Run time need buffers
        str='Com_Arc_IPdu_type Com_Arc_IPdu[] = {\n';
        for ipdu in self.cfg.IPduList:
            str+='\t{ // %s\n'%(ipdu.name)
            str+='\t\t{/* .Com_Arc_TxIPduTimers = */\n' 
            str+='\t\t\t/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,\n'
            str+='\t\t\t/* .ComTxModeRepetitionPeriodTimer = */ 0,\n'
            str+='\t\t\t/* .ComTxIPduMinimumDelayTimer = */ 0,\n'
            str+='\t\t\t/* .ComTxModeTimePeriodTimer = */ 0\n'
            str+='\t\t},\n'		
            str+='\t\t/* .Com_Arc_IpduStarted = */ 0\n'	
            str+='\t},\n'
        str+='};\n\n';
        fp.write(str);
        str='Com_Arc_Signal_type Com_Arc_Signal[] = {\n';
        for ipdu in self.cfg.IPduList:
            for sig in ipdu.signalList+ipdu.signalGroupList:
                str+='\t{ // %s\n'%(sig.name);
                str+='\t\t/* .Com_Arc_DeadlineCounter = */ 0,\n'
                str+='\t\t/* .ComSignalUpdated = */ 0,\n'
                str+='\t},\n'
        str+='};\n\n';
        fp.write(str);
        fp.write('#if(COM_N_GROUP_SIGNALS > 0)\n'
                'Com_Arc_GroupSignal_type Com_Arc_GroupSignal[COM_N_GROUP_SIGNALS];\n'
                '#endif\n\n'
                'const Com_Arc_Config_type Com_Arc_Config = {\n'
                '	/* .ComIPdu = */ Com_Arc_IPdu,\n'
                '	/* .ComSignal = */ Com_Arc_Signal,\n'
                '#if(COM_N_GROUP_SIGNALS > 0)\n'	
                '	/* .ComGroupSignal = */ Com_Arc_GroupSignal\n'
                '#else\n'
                '    /* .ComGroupSignal = */ NULL\n'
                '#endif\n'    	
                '};\n\n');
        fp.close();
