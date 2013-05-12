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
  
