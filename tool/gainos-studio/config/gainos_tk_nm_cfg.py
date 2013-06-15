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

class NmGeneral():
    def __init__(self):
        self.DevError = True;
        self.VersionInfo = True;
        self.NodeDetection = True;
        self.NodeId = True;
        self.UserData = True;
    def save(self, root):
        nd = ET.Element('NmGeneral');
        nd.attrib['DevError'] = str(self.DevError);
        nd.attrib['VersionInfo'] = str(self.VersionInfo);
        nd.attrib['NodeDetection'] = str(self.NodeDetection);
        nd.attrib['NodeId'] = str(self.NodeId);
        nd.attrib['UserData'] = str(self.UserData);
        root.append(nd);
    def parse(self, nd):
        self.DevError = bool(nd.attrib['DevError']);
        self.VersionInfo = bool(nd.attrib['VersionInfo']);
        self.NodeDetection = bool(nd.attrib['NodeDetection']);
        self.NodeId = bool(nd.attrib['NodeId']);
        self.UserData = bool(nd.attrib['UserData']);
class NmChannel():
    def __init__(self, name):
        self.name = name;
        self.BusType = 'NM_BUSNM_CANNM';
        self.BusNmNetworkHandle = '';
        self.ComMNetworkHandle = '';
    def save(self, root):
        nd = ET.Element('NmChannel')
        nd.attrib['name'] = str(self.name)
        nd.attrib['BusNmNetworkHandle'] = str(self.BusNmNetworkHandle)
        nd.attrib['ComMNetworkHandle'] = str(self.ComMNetworkHandle)
        root.append(nd)
    def parse(self, nd):
        self.name = str(nd.attrib['name'])
        self.BusNmNetworkHandle = str(nd.attrib['BusNmNetworkHandle'])
        self.ComMNetworkHandle = str(nd.attrib['ComMNetworkHandle'])
class NmConfig():
    def __init__(self):
        self.general = NmGeneral();
        self.channelList = [];
    def save(self, root):
        self.general.save(root);
        nd = ET.Element('NmChannelList');
        for chl in self.channelList:
            chl.save(nd);
        root.append(nd);
    def parse(self, root):
        self.general.parse(root.find('NmGeneral'))
        for nd in root.find('NmChannelList'):
            chl = NmChannel('');
            chl.parse(nd)
            self.channelList.append(chl);

class gainos_tk_nm_cfg():
    def __init__(self, chip=None):
        self.cfg=NmConfig();

    def toString(self):
        str='Nm!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_nm import cd_nm
        depinfo=[];
        md=gcfindModule(module_list, 'CanNm');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure CanNm Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        md=gcfindModule(module_list, 'ComM');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure ComM Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg  = cd_nm(title, fileInd, self.cfg, depinfo);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        self.cfg.save(root);
        
    def parse(self, root):
        self.cfg.parse(root);

    def gen(self, path):
        self.codeGenH(path);
        self.codeGenC(path);

    def codeGenH(self, path):
        fp = open(path+'/Nm_Cfg.h', 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#ifndef NM_CFG_H_H\n#define NM_CFG_H_H\n\n')
        fp.write('#define NM_DEV_ERROR_DETECT %s\n'%(gSTD_ON(self.cfg.general.DevError)))
        fp.write('#define NM_VERSION_INFO_API %s\n'%(gSTD_ON(self.cfg.general.VersionInfo)))
        fp.write('#define NM_USER_DATA_ENABLED %s\n'%(gSTD_ON(self.cfg.general.UserData)))
        fp.write('#define NM_NODE_ID_ENABLED %s\n'%(gSTD_ON(self.cfg.general.NodeId)))
        fp.write('#define NM_NODE_DETECTION_ENABLED %s\n\n'%(gSTD_ON(self.cfg.general.NodeDetection)))
        id = 0
        for chl in self.cfg.channelList:
            fp.write('#define %s %s\n'%(chl.name,id))
            id += 1
        fp.write('\n#define USE_CANNM\n')
        fp.write('\nextern const Nm_ConfigType Nm_Config;\n\n')
        fp.write('#endif /* NM_CFG_H_H */\n\n')
        fp.close();
    def codeGenC(self, path):
        fp = open(path+'/Nm_Cfg.c', 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#include "Nm.h"\n#include "CanNm.h"\n#include "ComM.h"\n\n')
        str = 'const Nm_ChannelType Nm_Channels[] = {\n'
        for chl in self.cfg.channelList:
            str += '\t{//%s\n'%(chl.name)
            str += '\t\t/* BusType = */ %s,\n'%(chl.BusType)
            str += '\t\t/* BusNmNetworkHandle = */ %s,\n'%(chl.BusNmNetworkHandle)
            str += '\t\t/* ComMNetworkHandle = */ %s,\n'%(chl.ComMNetworkHandle)
            str += '\t},\n'
        str += '};\n\n'
        fp.write(str);
        fp.write('const Nm_ConfigType Nm_Config = \n{\n\t/* Channels = */ Nm_Channels\n};\n\n')
