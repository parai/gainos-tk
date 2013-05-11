# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 *
 * GaInOS-Studio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * GaInOS-Studio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS-Studio. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: parai
 * Email: parai@foxmail.com
 * URL: https://github.com/parai/gainos-tk
 */
"""

from PyQt4.QtGui import QMainWindow
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem
from PyQt4.QtCore import QStringList,QString

from gainos_tk_cfg import gainos_tk_cfg

from Ui_gainos_studio import Ui_mwgainostk

class mwgainostk(QMainWindow, Ui_mwgainostk):
    """
    Class documentation goes here.
    """
    def __init__(self, argc, argv, parent = None):
        """
        Constructor
        """
        QMainWindow.__init__(self, parent)
        self.setupUi(self)
        self.initGui()
        self.cfg = None;
        self.curtree = None;

    def initGui(self):
        #Disable All Ctrl
        self.trModule.setDisabled(True);
        self.btnAdd.setDisabled(True);
        self.btnDel.setDisabled(True);
        self.btnEdit.setDisabled(True);
        self.btnFileSave.setDisabled(True);
        self.btnGen.setDisabled(True);
        self.teInfo.setDisabled(True);
        self.teInfo.setText("Please load or new a config project firstly.")
        #init Menu Action
        self.actionOpen.setShortcut('Ctrl+O');
        self.actionSave.setShortcut('Ctrl+S');
        self.actionSave_As.setShortcut('Ctrl+Shift+S');
        self.actionNew.setShortcut('Ctrl+N');
    
    @pyqtSignature("")
    def on_actionNew_triggered(self):
        from cd_select import cd_select
        #firstly let you choose a chip
        chip_supported = ['MC9S12','MPC56XX', 'STM32F1', 'AT91SAM3S' ]
        dlg = cd_select('Chip for this config.', chip_supported)
        dlg.exec_();
        if(dlg.result == True):
            # re-init GUI
            self.trModule.setDisabled(False);
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
            self.btnEdit.setDisabled(True);
            self.btnFileSave.setDisabled(True);
            self.btnGen.setDisabled(True);
            self.teInfo.setText("For %s:\n"%(dlg.select));
            for i in range(0, self.trModule.topLevelItemCount()):
                self.trModule.takeTopLevelItem(0);
            self.cfg = gainos_tk_cfg(str(dlg.select));
    
    @pyqtSignature("")
    def on_actionOpen_triggered(self):
        return
    
    @pyqtSignature("")
    def on_actionSave_triggered(self):
        return
    
    @pyqtSignature("")
    def on_actionSave_As_triggered(self):
        return
        
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trModule_itemClicked(self, item, column):
        self.curtree = item;
        md = self.cfg.findModule(item.text(0));
        self.teInfo.setText(md.toString());
        #refresh button 
        self.btnDel.setDisabled(False);
        self.btnEdit.setDisabled(False);
        self.btnFileSave.setDisabled(False);
        self.btnGen.setDisabled(False);
    
    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        from cd_add import cd_add
        ArModule=['OS','Adc', 'Can','CanIf','CanNm', 'CanTp', 'CanSm', 'Com', 
            'Dio', 'Eep', 'EcuC', 'Fls', 'Gpt', 'Icu', 'Pwm', 'Port', 'Mcu', 
            'PduR', 'Spi', 'Wdg', 'WdgIf']
        list =[];
        for it in ArModule:
            if(self.cfg.findModule(it) == None):
                list.append(it);
        dlg = cd_add('Add a Module', list);
        dlg.exec_();
        if(dlg.result == True):
            item=QTreeWidgetItem(self.trModule,QStringList(dlg.item));
            self.trModule.insertTopLevelItem(0, item);
            self.cfg.addModule(str(dlg.item));
    
    @pyqtSignature("")
    def on_btnDel_clicked(self):
        module = self.curtree.text(0);
        index = self.trModule.indexOfTopLevelItem(self.curtree);
        self.trModule.takeTopLevelItem(index);
        self.cfg.delModule(module);
        if(index > 0):
            self.curtree = self.trModule.topLevelItem(index -1);
        else:
            self.curtree = None;
            self.btnDel.setDisabled(True);
            self.btnEdit.setDisabled(True);
            
        
        
