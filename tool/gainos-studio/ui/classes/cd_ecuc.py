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
