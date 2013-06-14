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

import os, sys
from Common import *
import xml.etree.ElementTree as ET

class CanNmGeneral():
    def __init__(self):
        self.DevError = True;
        self.VersionInfo = True;
        self.PassiveModeEn = True;
    def save(self, root):
        nd = ET.Element('CanNmGeneral');
        nd.attrib['DevError'] = str(self.DevError);
        nd.attrib['VersionInfo'] = str(self.VersionInfo);
        nd.attrib['PassiveModeEn'] = str(self.PassiveModeEn);
        root.append(nd);
    def parse(self, nd):
        self.DevError = bool(nd.attrib['DevError']);
        self.VersionInfo = bool(nd.attrib['VersionInfo']);
        self.PassiveModeEn = bool(nd.attrib['PassiveModeEn']);

class CanNmChannel():
    def __init__(self, name):
        self.name = name;
        self.Active = True;
        self.NmNetworkHandle = '';
        self.NodeId = '0xEF';
        self.MainFunctionPeriod = 4; #ms
        self.TimeoutTime = 1000; #ms
        self.RepeatMessageTime = 1000; #ms
        self.WaitBusSleepTime = 1000; #ms
        self.MessageCycleTime = 1000; #ms
        self.MessageCycleOffsetTime = 100; #ms
        self.CanIfPduId = ''
        self.RxPduId = ''
        self.PduLength = 8; #ms
        self.NidPosition = 'CANNM_PDU_OFF'; #ms
        self.CbvPosition = 'CANNM_PDU_OFF'; #ms
    def save(self, root):
        nd = ET.Element('CanNmChannel')
        nd.attrib['name'] = str(self.name)
        nd.attrib['Active'] = str(self.Active)
        nd.attrib['NmNetworkHandle'] = str(self.NmNetworkHandle)
        nd.attrib['NodeId'] = str(self.NodeId)
        nd.attrib['MainFunctionPeriod'] = str(self.MainFunctionPeriod)
        nd.attrib['TimeoutTime'] = str(self.TimeoutTime)
        nd.attrib['RepeatMessageTime'] = str(self.RepeatMessageTime)
        nd.attrib['WaitBusSleepTime'] = str(self.WaitBusSleepTime)
        nd.attrib['MessageCycleTime'] = str(self.MessageCycleTime)
        nd.attrib['MessageCycleOffsetTime'] = str(self.MessageCycleOffsetTime)
        nd.attrib['CanIfPduId'] = str(self.CanIfPduId)
        nd.attrib['RxPduId'] = str(self.RxPduId)
        nd.attrib['PduLength'] = str(self.PduLength)
        nd.attrib['NidPosition'] = str(self.NidPosition)
        nd.attrib['CbvPosition'] = str(self.CbvPosition)
        root.append(nd);
    def parse(self, nd):
        self.name = str(nd.attrib['name'])
        self.Active = bool(nd.attrib['Active'])
        self.NmNetworkHandle = str(nd.attrib['NmNetworkHandle'])
        self.NodeId = str(nd.attrib['NodeId'])
        self.MainFunctionPeriod = int(nd.attrib['MainFunctionPeriod'])
        self.TimeoutTime = int(nd.attrib['TimeoutTime'])
        self.RepeatMessageTime = int(nd.attrib['RepeatMessageTime'])
        self.WaitBusSleepTime = int(nd.attrib['WaitBusSleepTime'])
        self.MessageCycleTime = int(nd.attrib['MessageCycleTime'])
        self.MessageCycleOffsetTime = int(nd.attrib['MessageCycleOffsetTime'])
        self.CanIfPduId = str(nd.attrib['CanIfPduId'])
        self.RxPduId = str(nd.attrib['RxPduId'])
        self.PduLength = int(nd.attrib['PduLength'])
        self.NidPosition = str(nd.attrib['NidPosition'])
        self.CbvPosition = str(nd.attrib['CbvPosition'])
class CanNmConfig():
    def __init__(self):
        self.general = CanNmGeneral();
        self.channelList = [];
    def save(self, root):
        self.general.save(root);
        nd = ET.Element('CanNmChannelList');
        for chl in self.channelList:
            chl.save(nd);
        root.append(nd);
    def parse(self, root):
        self.general.parse(root.find('CanNmGeneral'))
        for nd in root.find('CanNmChannelList'):
            chl = CanNmChannel('');
            chl.parse(nd)
            self.channelList.append(chl);
class gainos_tk_cannm_cfg():
    def __init__(self, chip=None):
        self.cfg=CanNmConfig();

    def toString(self):
        str='CanNm!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_cannm import cd_cannm
        depinfo=[];
        md=gcfindModule(module_list, 'EcuC');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        md=gcfindModule(module_list, 'Nm');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Add Nm Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg  = cd_cannm(title, fileInd, self.cfg, depinfo);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        self.cfg.save(root);
        
    def parse(self, root):
        self.cfg.parse(root);

    def gen(self, path):
        self.codeGenH(path)
        self.codeGenC(path)
    
    def codeGenH(self, path):
        fp = open(path+'/CanNm_Cfg.h', 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#ifndef CANNM_CFG_H_H\n#define CANNM_CFG_H_H\n\n')
        fp.write('#define CANNM_DEV_ERROR_DETECT				%s\n'%(gSTD_ON(self.cfg.general.DevError)))
        fp.write('#define CANNM_VERSION_INFO_API				%s\n'%(gSTD_ON(self.cfg.general.VersionInfo)))
        fp.write('#define CANNM_PASSIVE_MODE_ENABLED			%s\n'%(gSTD_ON(self.cfg.general.PassiveModeEn)))
        fp.write('#define CANNM_USER_DATA_ENABLED				STD_ON\n')
        fp.write('#define CANNM_REMOTE_SLEEP_IND_ENABLED		STD_OFF	// Not supported\n')
        fp.write('#define CANNM_BUS_SYNCHRONIZATION_ENABLED	STD_OFF	// Not supported\n')
        fp.write('#define CANNM_BUS_LOAD_REDUCTION_ENABLED	STD_OFF	// Not supported\n')
        fp.write('#define CANNM_NODE_ID_ENABLED				STD_ON\n')
        fp.write('#define CANNM_NODE_DETECTION_ENABLED		STD_ON\n')
        fp.write('#define CANNM_IMMEDIATE_RESTART_ENABLED		STD_OFF	// Not supported\n')
        fp.write('#define CANNM_PDU_RX_INDICATION_ENABLED		STD_ON\n')
        fp.write('#define CANNM_STATE_CHANGE_IND_ENABLED		STD_OFF	// Not supported\n')
        fp.write('#define CANNM_COM_CONTROL_ENABLED			STD_OFF	// Not supported\n')
        fp.write('#define CANNM_IMMEDIATE_TXCONF_ENABLED		STD_OFF	// Not supported\n')
        fp.write('#define CANNM_REPEAT_MSG_IND_ENABLED		STD_OFF	// Not supported\n\n')
        fp.write('#define CANNM_CHANNEL_COUNT %s\n'%(len(self.cfg.channelList)))
        id = 0
        for chl in self.cfg.channelList:
            fp.write('#define %s %s\n'%(chl.name,id))
            fp.write('#define CANNM_%s %s\n'%(chl.CanIfPduId,id))
            fp.write('#define CANNM_%s %s\n'%(chl.RxPduId,id))
            id += 1
        fp.write('\nextern const CanNm_ConfigType CanNm_Config;\n\n')
        fp.write('#endif /* CANNM_CFG_H_H */ \n\n')
        fp.close();
    def codeGenC(self, path):
        fp = open(path+'/CanNm_Cfg.c', 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#include "CanNm.h"\n#include "CanIf.h"\n#include "Nm.h"\n\n');
        str = 'const CanNm_ChannelType  CanNm_Channels[] = {\n'
        for chl in self.cfg.channelList:
            str += '\t{//%s\n'%(chl.name)
            str += '\t\t/* Active = */ %s,\n'%(TRUE(chl.Active))
            str += '\t\t/* NmNetworkHandle = */ %s,\n'%(chl.NmNetworkHandle)
            str += '\t\t/* NodeId = */ %s,\n'%(chl.NodeId)
            str += '\t\t/* MainFunctionPeriod = */ %s,\n'%(chl.MainFunctionPeriod)
            str += '\t\t/* TimeoutTime = */ %s,\n'%(chl.TimeoutTime)
            str += '\t\t/* RepeatMessageTime = */ %s,\n'%(chl.RepeatMessageTime)
            str += '\t\t/* WaitBusSleepTime = */ %s,\n'%(chl.WaitBusSleepTime)
            str += '\t\t/* MessageCycleTime = */ %s,\n'%(chl.MessageCycleTime)
            str += '\t\t/* MessageCycleOffsetTime = */ %s,\n'%(chl.MessageCycleOffsetTime)
            str += '\t\t/* CanIfPduId = */ CANIF_%s,\n'%(chl.CanIfPduId)
            str += '\t\t/* PduLength = */ %s,\n'%(chl.PduLength)
            str += '\t\t/* NidPosition = */ %s,\n'%(chl.NidPosition)
            str += '\t\t/* CbvPosition = */ %s\n'%(chl.CbvPosition)
            str += '\t},\n'
        str += '};\n\n'
        fp.write(str)
        fp.write('const CanNm_ConfigType CanNm_Config = {\n\t/* CanNm_ChannelType* = */ CanNm_Channels\n};\n\n ')
        fp.close()
        
        
