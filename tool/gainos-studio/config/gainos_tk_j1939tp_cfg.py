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
class J1939TpGeneral():
    def __init__(self):
        self.DevError = True;
        self.PacketBlock = 5;
        self.MainFunctionPeriod = 4;
        self.TxConfirmTimeout = 100;
    def save(self, root):
        nd = ET.Element('J1939TpGeneral');
        nd.attrib['DevError'] = str(self.DevError);
        nd.attrib['PacketBlock'] = str(self.PacketBlock);
        nd.attrib['MainFunctionPeriod'] = str(self.MainFunctionPeriod);
        nd.attrib['TxConfirmTimeout'] = str(self.TxConfirmTimeout);
        root.append(nd);
    def parse(self, nd):
        self.DevError = bool(nd.attrib['DevError']);
        self.PacketBlock = int(nd.attrib['PacketBlock']);
        self.MainFunctionPeriod = int(nd.attrib['MainFunctionPeriod']);
        self.TxConfirmTimeout = int(nd.attrib['TxConfirmTimeout']);
class J1939TpPgs():
    def __init__(self, name):
        self.name = name;
    def save(self, root):
        nd = ET.Element('J1939TpPgs');
        nd.attrib['name'] = str(self.name);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
class J1939TpChannel():
    def __init__(self, name):
        self.name = name;
        self.Protocol = ''
        self.DtNPdu = ''
        self.CmNPdu = ''
        self.FcNPdu = ''
        self.Direction = ''
        self.PgsList = []
    def save(self, root):
        nd = ET.Element('J1939TpChannel');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DtNPdu'] = str(self.DtNPdu);
        nd.attrib['CmNPdu'] = str(self.CmNPdu);
        nd.attrib['FcNPdu'] = str(self.FcNPdu);
        nd.attrib['Direction'] = str(self.Direction);
        nd2 = ET.Element('PgsList');
        for obj in self.PgsList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.DtNPdu = str(nd.attrib['DtNPdu']);
        self.CmNPdu = str(nd.attrib['CmNPdu']);
        self.FcNPdu = str(nd.attrib['FcNPdu']);
        self.Direction = str(nd.attrib['Direction']);
        for nd2 in nd.find('PgsList'):
            obj = J1939TpPgs('');
            obj.parse(nd2);
            self.PgsList.append(obj);
class gainos_tk_j1939tp_obj():
    def __init__(self):
        self.general = J1939TpGeneral();
        self.rxChannelList = [];
        self.txChannelList = [];
    def save(self, root):
        self.general.save(root);
        nd = ET.Element('rxChannelList');
        for obj in self.rxChannelList:
            obj.save(nd);
        root.append(nd);
        nd = ET.Element('txChannelList');
        for obj in self.txChannelList:
            obj.save(nd);
        root.append(nd);
    def parse(self, root):
        self.general.parse(root.find('J1939TpGeneral'));
        for nd in root.find('rxChannelList'):
            obj = J1939TpChannel('');
            obj.parse(nd);
            self.rxChannelList.append(obj);
        for nd in root.find('txChannelList'):
            obj = J1939TpChannel('');
            obj.parse(nd);
            self.txChannelList.append(obj);
class gainos_tk_j1939tp_cfg():
    def __init__(self, chip=None):
        self.cfg=gainos_tk_j1939tp_obj();

    def toString(self):
        str='J1939Tp!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_j1939tp import cd_j1939tp
        self.dlg  = cd_j1939tp(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        self.cfg.save(root);
    
    def parse(self, root):
        self.cfg.parse(root);

    def gen(self, path):
        return;
  
