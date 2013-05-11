# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature

from Ui_cd_select import Ui_cd_select

class cd_select(QDialog, Ui_cd_select):
    """
    common dialog for select a item
    """
    def __init__(self, title, list, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.result = False;
        self.select = list[0];
        self.setWindowTitle(title);
        for item in list:
            self.cmbxSelect.addItem(item);
    
    @pyqtSignature("QString")
    def on_cmbxSelect_activated(self, p0):
        self.select = p0;
    
    @pyqtSignature("")
    def on_btnYes_clicked(self):
        if(self.select != ''):
            self.result = True;
            self.close();
    
    @pyqtSignature("")
    def on_btnNo_clicked(self):
        self.close();
