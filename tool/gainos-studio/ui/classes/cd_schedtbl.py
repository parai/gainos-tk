# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtCore import QStringList,QString
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from Ui_cd_schedtbl import Ui_cd_schedtbl
from Common import *

from gainos_tk_os_cfg import *
class cd_schedtbl(QDialog, Ui_cd_schedtbl):
    """
    Class documentation goes here.
    """
    def __init__(self, schedtbl, depinfo, parent = None):
        """
        depinfo: the os cfg
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle('config %s, <gainos-tk by parai>'%(schedtbl.name))
        self.cfg = schedtbl
        self.depinfo = depinfo
        self.curtree = None
        self.initGui();
        self.reloadGui();
    
    def reloadGui(self):
        tree=self.trSchedTable.topLevelItem(0);
        for tbl in self.cfg.table:
            item=QTreeWidgetItem(tree,QStringList('Expiry Point(offset = %s)'%(tbl.offset)));
            tree.addChild(item);
            for action in tbl.actionList:
                item2=QTreeWidgetItem(item,QStringList(action));
                item.addChild(item2);
    def initGui(self):
        self.cbxSchedTblRepeatable.setChecked(self.cfg.repeatable)
        self.cmbxSchedTblSyncStrategy.setCurrentIndex(self.cmbxSchedTblSyncStrategy.findText(self.cfg.strategy));
        self.spbxSchedTblFinalDelay.setValue(self.cfg.finaldelay)
        for cnt in self.depinfo.counterList:
            self.cmbxSchedTblDrivingCounter.addItem(cnt.name)
        self.cmbxSchedTblDrivingCounter.setCurrentIndex(self.cmbxSchedTblDrivingCounter.findText(self.cfg.owner))
        self.initButton();
        self.disableAllTab();
    
    def initButton(self):
        self.btnAdd1.setDisabled(True)
        self.btnAdd2.setDisabled(True)
        self.btnDel.setDisabled(True)
    
    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 3):
            self.tabSchedTblCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 3):
            if(i==index):
                self.tabSchedTblCfg.setTabEnabled(i, True);
                self.tabSchedTblCfg.setCurrentIndex(i);
            else:
                self.tabSchedTblCfg.setTabEnabled(i, False);

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        #--------------------- 一级目录
        if(trname=='Expiry Point List'):
            self.btnAdd1.setText('Add Expiry Point');
            self.btnAdd1.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        #--------------------- 二级目录
        elif(self.curtree.parent().text(0)=='Expiry Point List'):
            self.btnAdd1.setText('Add ActivateTask');
            self.btnAdd2.setText('Add SetEvent');
            self.btnDel.setText('Delete Expiry Point');
            self.btnAdd1.setDisabled(False);
            self.btnAdd2.setDisabled(False);
            self.btnDel.setDisabled(False);
        #--------------------- 三级目录
        elif(self.curtree.parent().parent().text(0)=='Expiry Point List'):
            self.btnDel.setText('Delete Action');
            self.btnAdd1.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trSchedTable_itemClicked(self, item, column):
        self.curtree = item
        self.refreshButton()
    
    @pyqtSignature("int")
    def on_spbxSchedEpOffset_valueChanged(self, p0):
        return
        
    @pyqtSignature("QString")
    def on_cmbxSetTskId_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxSetEnt_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxActTskId_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    def addEp(self):
        id = len(self.cfg.table)
        obj=ExpiryPoint();
        self.cfg.table.append(obj);
        if(id == 0):
            obj.offset = 10;
        else:
            obj.offset = self.cfg.table[id-1].offset + 10;
        name=QString('Expiry Point(offset = %s)'%(obj.offset));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);        
        self.curtree.setExpanded(True);
    def addActivateTask(self):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree) 
        tbl = self.cfg.table[index]
        tbl.actionList.insert(0, 'ActivateTask(NULL)')
        name=QString('ActivateTask(NULL)')
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);        
        self.curtree.setExpanded(True);
    def addSetEvent(self):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree) 
        tbl = self.cfg.table[index]
        tbl.actionList.append('SetEvent(NULL,NULL)')
        name=QString('SetEvent(NULL,NULL)')
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);        
        self.curtree.setExpanded(True);
    @pyqtSignature("")
    def on_btnAdd1_clicked(self):
        text = self.btnAdd1.text();
        if(text == 'Add Expiry Point'):
            self.addEp();
        elif(text == 'Add ActivateTask'):
            self.addActivateTask();
    
    @pyqtSignature("")
    def on_btnAdd2_clicked(self):
        text = self.btnAdd2.text();
        if(text == 'Add SetEvent'):
            self.addSetEvent();
    
    @pyqtSignature("")
    def on_btnAdd3_clicked(self):
        return
    
    @pyqtSignature("bool")
    def on_cbxSchedTblRepeatable_clicked(self, checked):
        self.cfg.repeatable = checked;
    
    @pyqtSignature("QString")
    def on_cmbxSchedTblDrivingCounter_activated(self, p0):
        self.cfg.owner = p0
    
    @pyqtSignature("bool")
    def on_cbxSchedTblAutostartable_clicked(self, checked):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxSchedTblAutoStartType_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("int")
    def on_spbxSchedTblAbsRel_valueChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("int")
    def on_spbxSchedTblFinalDelay_valueChanged(self, p0):
        self.cfg.finaldelay = p0
    
    @pyqtSignature("QString")
    def on_cmbxSchedTblSyncStrategy_activated(self, p0):
        self.cfg.strategy = p0
    
    @pyqtSignature("int")
    def on_spbxSchedTblMaxAdvance_valueChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("int")
    def on_spbxSchedTblMaxRetard_valueChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("int")
    def on_spbxSchedTblPrecision_valueChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
