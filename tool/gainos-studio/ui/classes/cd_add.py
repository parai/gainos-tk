# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem
from PyQt4.QtCore import QStringList,QString

from Ui_cd_add import Ui_cd_add

class cd_add(QDialog, Ui_cd_add):
    """
    common dialog to add a module or a item.
    """
    def __init__(self,  title, list, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title);
        for it in list:
            item=QTreeWidgetItem(self.trModule,QStringList(it));
            self.trModule.insertTopLevelItem(0, item);
        self.trModule.sortColumn();
        self.item = '';
        self.result = False;
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trModule_itemClicked(self, item, column):
        self.item = item.text(0);

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trModule_itemDoubleClicked(self, item, column):
        self.item = item.text(0);
        self.result = True;
        self.close();
        
    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        if(self.item != ''):
            self.result = True;
            self.close();
    
    @pyqtSignature("")
    def on_btnCancel_clicked(self):
        self.close();
