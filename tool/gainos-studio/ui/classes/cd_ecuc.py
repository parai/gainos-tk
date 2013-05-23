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
from Ui_cd_ecuc import Ui_cd_ecuc
from gainos_tk_ecuc_cfg import EcuCPdu
class cd_ecuc(QDialog, Ui_cd_ecuc):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, parent = None):
        """
        Constructor
        """
        self.cfg=cfg;
        self.curobj=None;
        self.curtree=None;
        self.fileInd = fileInd;
        QDialog.__init__(self, parent);
        self.setupUi(self);
        self.setWindowTitle(title);
        self.initGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnDel.setDisabled(True);

    def reloadTreeGui(self):
        tree=self.trEcucCfg.topLevelItem(0);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.pduList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);

    def initGui(self):
        self.reloadTreeGui();
        self.initButton();
        self.disableAllTab();
        self.spbxRxPduSize.setRange(0, 65535);
        self.spbxTxPduSize.setRange(0, 65535);
    
    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Pdus'):
            self.btnAdd.setText('Add Pdu');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='Pdus'):
            self.btnDel.setText('Del Pdu');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);

    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 1):
            self.tabCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 1):
            if(i==index):
                self.tabCfg.setTabEnabled(i, True);
                self.tabCfg.setCurrentIndex(i);
            else:
                self.tabCfg.setTabEnabled(i, False); 

    def delObj(self, list):
        list.remove(self.curobj);
        del self.curobj

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def refreshPduTab(self, name):
        obj=self.findObj(self.cfg.pduList, name);
        if(obj==None):
            return;
        self.curobj=obj;
        self.lePduName.setText(obj.name);
        self.spbxRxPduSize.setValue(obj.rxSize);
        self.spbxTxPduSize.setValue(obj.txSize);
        self.enableTab(0);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Pdus'):
            self.refreshPduTab(objname);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trEcucCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    def addPdu(self):
        id = len(self.cfg.pduList);
        name='vEcuC_Pdu%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=EcuCPdu(name);
        self.cfg.pduList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Pdu'):
            self.addPdu();
            self.fileInd(False);
    
    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Del Pdu'):
            self.delObj(self.cfg.pduList);
        del self.curtree;
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trEcucCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trEcucCfg_itemClicked(parent, 0);
        self.fileInd(False);

    @pyqtSignature("QString")
    def on_lePduName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);

    @pyqtSignature("int")
    def on_spbxRxPduSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.rxSize=p0;
            self.fileInd(False);

    @pyqtSignature("int")
    def on_spbxTxPduSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.txSize=p0;
            self.fileInd(False);
