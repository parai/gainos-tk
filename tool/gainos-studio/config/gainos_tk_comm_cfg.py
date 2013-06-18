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
class ComMGeneral():
    def __init__(self):
        self.DevError = True;
        self.VersionInfo = True;
        self.NoCom = True; #No Communication
        self.ModeLimitation = True;
        self.MinTimeInFull = 10;
    def save(self, root):
        nd = ET.Element('ComMGeneral');
        nd.attrib['DevError'] = str(self.DevError);
        nd.attrib['VersionInfo'] = str(self.VersionInfo);
        nd.attrib['NoCom'] = str(self.NoCom);
        nd.attrib['ModeLimitation'] = str(self.ModeLimitation);
        nd.attrib['MinTimeInFull'] = str(self.MinTimeInFull);
        root.append(nd);
    def parse(self, nd):
        self.DevError = bool(nd.attrib['DevError']);
        self.VersionInfo = bool(nd.attrib['VersionInfo']);
        self.NoCom = bool(nd.attrib['NoCom']);
        self.ModeLimitation = bool(nd.attrib['ModeLimitation']);
        self.MinTimeInFull = int(nd.attrib['MinTimeInFull']);
class ComMChannel():
    def __init__(self, name):
        self.name = name;
        self.BusType = 'COMM_BUS_TYPE_CAN';
        self.BusSMNetworkHandle = '';
        self.NmChannelHandle = '';
        self.NmVariant = '';
        self.MainFunctionPeriod = 4;
        self.LightTimeout = 1000;
        self.Number = 0;# ?seems to be the id
    def save(self, root):
        nd = ET.Element('ComMChannel')
        nd.attrib['name'] = str(self.name)
        nd.attrib['BusType'] = str(self.BusType)
        nd.attrib['BusSMNetworkHandle'] = str(self.BusSMNetworkHandle)
        nd.attrib['NmChannelHandle'] = str(self.NmChannelHandle)
        nd.attrib['NmVariant'] = str(self.NmVariant)
        nd.attrib['MainFunctionPeriod'] = str(self.MainFunctionPeriod)
        nd.attrib['LightTimeout'] = str(self.LightTimeout)
        nd.attrib['Number'] = str(self.Number)
        root.append(nd)
    def parse(self, nd):
        self.name = str(nd.attrib['name'])
        self.BusType = str(nd.attrib['BusType'])
        self.BusSMNetworkHandle = str(nd.attrib['BusSMNetworkHandle'])
        self.NmChannelHandle = str(nd.attrib['NmChannelHandle'])
        self.NmVariant = str(nd.attrib['NmVariant'])
        self.MainFunctionPeriod = int(nd.attrib['MainFunctionPeriod'])
        self.LightTimeout = int(nd.attrib['LightTimeout'])
        self.Number = int(nd.attrib['Number'])
class ComMUser():
    def __init__(self, name):
        self.name = name;
        self.channelList = []; #just the name list of channnel
    def save(self, root):
        nd = ET.Element('ComMUser')
        nd.attrib['name'] = str(self.name)
        nd2 = ET.Element('channelList')
        for chl in self.channelList:
            nd2.append(ET.Element(str(chl)))
        nd.append(nd2)
        root.append(nd)
    def parse(self, nd):
        self.name = str(nd.attrib['name'])
        for nd2 in nd.find('channelList'):
            self.channelList.append(nd2.tag);
class ComMConfig():
    def __init__(self):
        self.general = ComMGeneral()
        self.channelList = []
        self.userList = []
    def save(self, root):
        self.general.save(root);
        nd = ET.Element('ComMChannelList');
        for chl in self.channelList:
            chl.save(nd);
        root.append(nd);
        nd = ET.Element('ComMUserList');
        for usr in self.userList:
            usr.save(nd);
        root.append(nd);
    def parse(self, root):
        self.general.parse(root.find('ComMGeneral'))
        for nd in root.find('ComMChannelList'):
            chl = ComMChannel('');
            chl.parse(nd)
            self.channelList.append(chl);
        for nd in root.find('ComMUserList'):
            usr = ComMUser('');
            usr.parse(nd)
            self.userList.append(usr);
class gainos_tk_comm_cfg():
    def __init__(self, chip=None):
        self.cfg=ComMConfig();

    def toString(self):
        str='Nm!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_comm import cd_comm
        depinfo=[];
        md=gcfindModule(module_list, 'Nm');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure Nm Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg  = cd_comm(title, fileInd, self.cfg, depinfo);
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
        fp = open(path+'/ComM_Cfg.h', 'w');
        fp.write(gcGainOS_TkHead());
        self.DevError = True;
        self.VersionInfo = True;
        self.NoCom = True; #No Communication
        self.ModeLimitation = True;
        self.MinTimeInFull = 10;
        fp.write('#ifndef COMM_CFG_H_H_H\n#define COMM_CFG_H_H_H\n\n');
        fp.write('#define COMM_VERSION_INFO_API %s\n'%(gSTD_ON(self.cfg.general.VersionInfo)))
        fp.write('#define COMM_DEV_ERROR_DETECT %s\n'%(gSTD_ON(self.cfg.general.DevError)))
        fp.write('#define COMM_NO_COM %s\n'%(gSTD_ON(self.cfg.general.NoCom)))
        fp.write('#define COMM_MODE_LIMITATION_ENABLED %s\n'%(gSTD_ON(self.cfg.general.ModeLimitation)))
        fp.write('#define COMM_T_MIN_FULL_COM_MODE_DURATION %s\n'%(self.cfg.general.MinTimeInFull))
        fp.write('\n#define COMM_CHANNEL_COUNT %s\n'%(len(self.cfg.channelList)))
        id = 0
        for chl in self.cfg.channelList:
            fp.write('#define %s %s\n'%(chl.name,id))
            id += 1
        str = '\ntypedef enum\n{\n'
        for usr in self.cfg.userList:
            str += '\t%s,\n'%(usr.name)
        str += '\tCOMM_USER_COUNT\n'
        str += '}ComM_UserHandleType;\n\n'
        fp.write(str)
        fp.write('extern const ComM_ConfigType ComM_Cfg;\n\n')
        fp.write('#endif /* COMM_CFG_H_H_H */\n\n')
        fp.close()
    def codeGenC(self, path):
        fp = open(path+'/ComM_Cfg.c', 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#include "ComM.h"\n#include "Nm.h"\n#include "CanSM.h"\n\n')
        str = 'const ComM_ChannelType ComM_Channels[] = \n{\n'
        id = 0
        for chl in self.cfg.channelList:
            str += '\t{//%s\n'%(chl.name)
            str += '\t\t/* BusType = */  %s,\n'%(chl.BusType)
            str += '\t\t/* BusSMNetworkHandle = */  %s,\n'%(chl.BusSMNetworkHandle)
            str += '\t\t/* NmChannelHandle = */  %s,\n'%(chl.NmChannelHandle)
            str += '\t\t/* NmVariant = */  %s,\n'%(chl.NmVariant)
            str += '\t\t/* MainFunctionPeriod = */  %s,\n'%(chl.MainFunctionPeriod)
            str += '\t\t/* LightTimeout = */  %s,\n'%(chl.LightTimeout)
            str += '\t\t/* Number = */  %s\n'%(id)
            id += 1
            str += '\t},\n'
        str += '};\n\n'
        fp.write(str)
        for usr in self.cfg.userList:
            str = 'const ComM_ChannelType* %s_ChannleList[] = \n{\n'%(usr.name)
            for cl in usr.channelList:
                str += '\t&ComM_Channels[%s],//%s\n'%(gcfindIndex(self.cfg.channelList, cl), cl)
            str += '};\n'
            fp.write(str);
        str = 'const ComM_UserType ComM_Users[] =\n{\n'
        for usr in self.cfg.userList:
            str += '\t{//%s\n'%(usr.name)
            str += '\t\t/* ChannelList = */ %s_ChannleList,\n'%(usr.name);
            str += '\t\t/* ChannelCount = */ %s\n'%(len(usr.channelList))
            str += '\t},\n'
        str += '};\n\n'
        fp.write(str)
        fp.write("""const ComM_ConfigType ComM_Cfg = 
{
    /* Channels = */ ComM_Channels,
    /* Users = */ ComM_Users
};\n\n""")
        fp.close()
