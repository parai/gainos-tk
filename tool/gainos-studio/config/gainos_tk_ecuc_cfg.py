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

class EcuCPdu():
    def __init__(self, name):
        self.name=name;
        self.rxSize=64;#bits for Rx Pdu
        self.txSize=64;#bits for Tx Pdu
    def save(self, root):
        nd = ET.Element('EcuCPdu');
        nd.attrib['name'] = str(self.name);
        nd.attrib['rxSize'] = str(self.rxSize);
        nd.attrib['txSize'] = str(self.txSize);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.rxSize = int(nd.attrib['rxSize']);
        self.txSize = int(nd.attrib['txSize']);

class EcuCConfig():
    def __init__(self):
        self.pduList=[];
        
class gainos_tk_ecuc_cfg():
    def __init__(self, chip=None):
        self.cfg=EcuCConfig();

    def toString(self):
        str='EcuC!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_ecuc import cd_ecuc
        self.dlg  = cd_ecuc(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        nd = ET.Element('PduList');
        for obj in self.cfg.pduList:
            obj.save(nd);
        root.append(nd);
    
    def parse(self, root):
        list = root.find('PduList');
        if(list == None):
            return;
        for nd in list:
            obj = EcuCPdu('');
            obj.parse(nd);
            self.cfg.pduList.append(obj);

    def gen(self, path):
        return;
  
