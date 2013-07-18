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
import re
re_action_ActivateTask = re.compile(r'^ActivateTask\((\w+)\)$')
re_action_SetEvent = re.compile(r'^SetEvent\((\w+),(\w+)\)$')
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
            item.setExpanded(True)
        tree.setExpanded(True)

    def initGui(self):
        self.cbxSchedTblRepeatable.setChecked(self.cfg.repeatable)
        self.cmbxSchedTblSyncStrategy.setCurrentIndex(self.cmbxSchedTblSyncStrategy.findText(self.cfg.strategy));
        self.spbxSchedTblFinalDelay.setValue(self.cfg.finaldelay)
        self.spbxSchedTblMaxAdvance.setValue(self.cfg.maxadvance)
        self.spbxSchedTblMaxRetard.setValue(self.cfg.maxretard)
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
            
    def refreshExpiryPointTab(self):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree)
        tbl = self.cfg.table[index]
        self.spbxSchedEpOffset.setValue(tbl.offset)
        self.enableTab(0)
    
    def refreshActivateTaskTab(self):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree.parent())
        tbl = self.cfg.table[index] #parent 
        index = self.curtree.parent().indexOfChild(self.curtree) # index 
        action = tbl.actionList[index]
        task = re_action_ActivateTask.search(action).groups()[0]
        self.cmbxActTskId.clear()
        for tsk in self.depinfo.taskList:
            self.cmbxActTskId.addItem(tsk.name)
        self.cmbxActTskId.setCurrentIndex(self.cmbxActTskId.findText(task))
        self.enableTab(1)

    def refreshSetEventTab(self):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree.parent())
        tbl = self.cfg.table[index] #parent 
        index = self.curtree.parent().indexOfChild(self.curtree) # index 
        action = tbl.actionList[index]
        task = re_action_SetEvent.search(action).groups()[0]
        event = re_action_SetEvent.search(action).groups()[1]
        self.cmbxSetTskId.clear();
        self.cmbxSetEnt.clear();
        for tsk in self.depinfo.taskList:
            if(len(tsk.eventList)>0):
                self.cmbxSetTskId.addItem(tsk.name)
        self.cmbxSetTskId.setCurrentIndex(self.cmbxSetTskId.findText(task))
        tsk = gcfindObj(self.depinfo.taskList, task);
        if(tsk != None):
            for ent in tsk.eventList:
                self.cmbxSetEnt.addItem(ent.name)
        self.cmbxSetEnt.setCurrentIndex(self.cmbxSetEnt.findText(event))
        self.enableTab(2)
        
    def refreshActionTab(self):
        text = self.curtree.text(0);
        if(text[:12] == 'ActivateTask'):
            self.refreshActivateTaskTab()
        elif(text[:8] == 'SetEvent'):
            self.refreshSetEventTab();
    
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        if(trname == 'Expiry Point List'):
            self.refreshExpiryPointTab();
        elif(trname[:22] == 'Expiry Point(offset = '):
            self.refreshActionTab()
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trSchedTable_itemClicked(self, item, column):
        self.curtree = item
        self.refreshButton()
        self.refreshTab()
    
    @pyqtSignature("int")
    def on_spbxSchedEpOffset_valueChanged(self, p0):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree)
        tbl = self.cfg.table[index]
        tbl.offset = p0
        self.curtree.setText(0, 'Expiry Point(offset = %s)'%(p0))
        
    @pyqtSignature("QString")
    def on_cmbxSetTskId_activated(self, p0):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree.parent())
        tbl = self.cfg.table[index] #parent 
        index = self.curtree.parent().indexOfChild(self.curtree) # index 
        tbl.actionList[index] = 'SetEvent(%s,NULL)'%(p0)
        self.cmbxSetEnt.clear();
        tsk = gcfindObj(self.depinfo.taskList, p0);
        if(tsk != None):
            for ent in tsk.eventList:
                self.cmbxSetEnt.addItem(ent.name)
        self.cmbxSetEnt.setCurrentIndex(-1)
        self.curtree.setText(0, tbl.actionList[index])
    
    @pyqtSignature("QString")
    def on_cmbxSetEnt_activated(self, p0):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree.parent())
        tbl = self.cfg.table[index] #parent 
        index = self.curtree.parent().indexOfChild(self.curtree) # index 
        action = tbl.actionList[index]
        task = re_action_SetEvent.search(action).groups()[0]
        tbl.actionList[index] = 'SetEvent(%s,%s)'%(task, p0)
        self.curtree.setText(0, tbl.actionList[index])
    
    @pyqtSignature("QString")
    def on_cmbxActTskId_activated(self, p0):
        index = self.trSchedTable.topLevelItem(0).indexOfChild(self.curtree.parent())
        tbl = self.cfg.table[index] #parent 
        index = self.curtree.parent().indexOfChild(self.curtree) # index 
        tbl.actionList[index] = 'ActivateTask(%s)'%(p0)
        self.curtree.setText(0, tbl.actionList[index])
    
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
        item=QTreeWidgetItem(None,QStringList(name));
        self.curtree.insertChild(0, item);        
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
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Delete Expiry Point'):
            self.cfg.table.remove(self.cfg.table[index]);
        elif(text=='Delete Action'):
            ii = self.trSchedTable.topLevelItem(0).indexOfChild(parent)
            tbl = self.cfg.table[ii]
            tbl.actionList.remove(tbl.actionList[index])
        del self.curtree;
        #reselect a tree item,software trigger on_trModule_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trSchedTable_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trSchedTable_itemClicked(parent, 0);
    
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
        self.cfg.maxadvance = p0
    
    @pyqtSignature("int")
    def on_spbxSchedTblMaxRetard_valueChanged(self, p0):
        self.cfg.maxretard = p0
    
    @pyqtSignature("int")
    def on_spbxSchedTblPrecision_valueChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
