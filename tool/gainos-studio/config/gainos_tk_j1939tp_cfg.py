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
        
class gainos_tk_j1939tp_cfg():
    def __init__(self, chip=None):
        self.cfg=None;

    def toString(self):
        str='J1939Tp!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_j1939tp import cd_j1939tp
        self.dlg  = cd_j1939tp(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        return
    
    def parse(self, root):
        return

    def gen(self, path):
        return;
  
