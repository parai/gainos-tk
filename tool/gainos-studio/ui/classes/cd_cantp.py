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

from CanTpCfg import *

from Ui_CanTp_Dlg import Ui_CanTp_Dlg

class CanTp_Dlg(QDialog, Ui_CanTp_Dlg):
    """
    Class documentation goes here.
    """
    def __init__(self, cfg, depinfo, parent = None):
        """
        depinfo[]: 
        -> depinfo[0]: the info about the list configured in EcuC,
        It is just obj<EcuCObj>;
        """
        self.cfg=cfg;
        self.depinfo=depinfo;
        self.curobj=None;
        self.curtree=None;
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.initGui();

    def reloadTreeGui(self, trindex, list):
        tree=self.trCanTpCfg.topLevelItem(trindex);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);

    def initTab(self):
        for obj in self.depinfo[0].cfg.pduList:
            self.cmbxRxPduId.addItem('RX_'+obj.name);
            self.cmbxRxFcPduId.addItem('RX_'+obj.name);
            self.cmbxTxFcPduId.addItem('TX_'+obj.name);
            self.cmbxTxPduId.addItem('TX_'+obj.name);
        #初始化 Rx
        self.cmbxRxTaType.setDisabled(True);# only physical is allowed.
        self.spbxRxPduDlc.setRange(0, 8);
        self.spbxRxSTmin.setRange(0, 65535);
        self.spbxRxWftMax.setRange(0, 65535);
        self.spbxRxNTa.setRange(0, 0x1FFFFFFF);
        self.spbxRxNSa.setRange(0, 0x1FFFFFFF);
        self.spbxRxNar.setRange(0, 65535);
        self.spbxRxNbr.setRange(0, 65535);
        self.spbxRxNcr.setRange(0, 65535);
        #初始化 Tx
        self.cmbxTxTaType.setDisabled(True);# only physical is allowed.
        self.spbxTxPduDlc.setRange(0, 8);
        self.spbxTxNTa.setRange(0, 0x1FFFFFFF);
        self.spbxTxNSa.setRange(0, 0x1FFFFFFF);
        self.spbxTxNas.setRange(0, 65535);
        self.spbxTxNbs.setRange(0, 65535);
        self.spbxTxNcs.setRange(0, 65535);

    def initGui(self):
        #Init General 
        self.cbxDevErr.setChecked(self.cfg.General.DevErrorDetection);
        self.spbxMainFunctionPeriod.setValue(self.cfg.General.MainFunctionPeriod);
        #init button
        self.btnAdd.setDisabled(True);
        #init tab
        self.disableAllTab();
        self.initTab();
        #Init Tree
        self.reloadTreeGui(0, self.cfg.RxNSduList);
        self.reloadTreeGui(1, self.cfg.TxNSduList);

    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 2):
            self.tabCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 2):
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

    @pyqtSignature("int")
    def on_spbxMainFunctionPeriod_valueChanged(self, p0):
        self.cfg.General.MainFunctionPeriod = p0;
    
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        self.cfg.General.DevErrorDetection = checked;
    
    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='RX SDU'):
            self.btnAdd.setText('Add Rx NSdu');
            self.btnAdd.setDisabled(False);
        elif(trname=='TX SDU'):
            self.btnAdd.setText('Add Tx NSdu');
            self.btnAdd.setDisabled(False);
        elif(self.curtree.parent().text(0)=='RX SDU'):
            self.btnAdd.setText('Del Rx NSdu');
            self.btnAdd.setDisabled(False);
        elif(self.curtree.parent().text(0)=='TX SDU'):
            self.btnAdd.setText('Del Tx NSdu');
    
    def refreshRxNSduTab(self, name):
        self.curobj= obj = self.findObj(self.cfg.RxNSduList, name);
        if(obj == None):
            return;
        self.leRxPduName.setText(obj.name);
        self.cmbxRxPduId.setCurrentIndex(self.cmbxRxPduId.findText(obj.PduR_PduId));
        self.cmbxTxFcPduId.setCurrentIndex(self.cmbxTxFcPduId.findText(obj.CanIf_FcPduId));
        self.cmbxRxPduPadding.setCurrentIndex(self.cmbxRxPduPadding.findText(obj.CanTpRxPaddingActivation));
        self.cmbxRxTaType.setCurrentIndex(self.cmbxRxTaType.findText(obj.CanTpRxTaType));
        self.cmbxRxAddressingFormat.setCurrentIndex(self.cmbxRxAddressingFormat.findText(obj.CanTpAddressingFormant));
        self.spbxRxPduDlc.setValue(obj.CanTpRxDI);
        self.spbxRxBs.setValue(obj.CanTpBs);
        self.spbxRxSTmin.setValue(obj.CanTpSTmin);
        self.spbxRxWftMax.setValue(obj.CanTpWftMax);
        self.spbxRxNTa.setValue(obj.CanTpNTa);
        self.spbxRxNSa.setValue(obj.CanTpNSa);
        self.spbxRxNar.setValue(obj.CanTpNar);
        self.spbxRxNbr.setValue(obj.CanTpNbr);
        self.spbxRxNcr.setValue(obj.CanTpNcr);
        if(obj.CanTpAddressingFormant == 'CANTP_STANDARD'):
            self.spbxRxNTa.setDisabled(True);
            self.spbxRxNSa.setDisabled(True);
        elif(obj.CanTpAddressingFormant == 'CANTP_EXTENDED'):
            self.spbxRxNTa.setDisabled(False);
            self.spbxRxNSa.setDisabled(False);
        self.enableTab(0);

    def refreshTxNSduTab(self, name):
        self.curobj= obj = self.findObj(self.cfg.TxNSduList, name);
        if(obj == None):
            return;
        self.leTxPduName.setText(obj.name);
        self.cmbxTxPduId.setCurrentIndex(self.cmbxTxPduId.findText(obj.PduR_PduId));
        self.cmbxRxFcPduId.setCurrentIndex(self.cmbxRxFcPduId.findText(obj.CanIf_FcPduId));
        self.cmbxTxPduPadding.setCurrentIndex(self.cmbxTxPduPadding.findText(obj.CanTpTxPaddingActivation));
        self.cmbxTxTaType.setCurrentIndex(self.cmbxTxTaType.findText(obj.CanTpTxTaType));
        self.cmbxTxAddressingFormat.setCurrentIndex(self.cmbxTxAddressingFormat.findText(obj.CanTpAddressingFormant));
        self.spbxTxPduDlc.setValue(obj.CanTpTxDI);
        self.spbxTxNTa.setValue(obj.CanTpNTa);
        self.spbxTxNSa.setValue(obj.CanTpNSa);
        self.spbxTxNas.setValue(obj.CanTpNas);
        self.spbxTxNbs.setValue(obj.CanTpNbs);
        self.spbxTxNcs.setValue(obj.CanTpNcs);
        if(obj.CanTpAddressingFormant == 'CANTP_STANDARD'):
            self.spbxTxNTa.setDisabled(True);
            self.spbxTxNSa.setDisabled(True);
        elif(obj.CanTpAddressingFormant == 'CANTP_EXTENDED'):
            self.spbxTxNTa.setDisabled(False);
            self.spbxTxNSa.setDisabled(False);
        self.enableTab(1);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'RX SDU'):
            self.refreshRxNSduTab(objname);
        elif(trname == 'TX SDU'):
            self.refreshTxNSduTab(objname)
            
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trCanTpCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    @pyqtSignature("QString")
    def on_leRxPduName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);

    @pyqtSignature("QString")
    def on_cmbxRxPduId_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.PduR_PduId=p0;
    
    @pyqtSignature("QString")
    def on_cmbxTxFcPduId_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanIf_FcPduId=p0;
    
    @pyqtSignature("int")
    def on_spbxRxPduDlc_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpRxDI=p0;
    
    @pyqtSignature("QString")
    def on_cmbxRxPduPadding_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpRxPaddingActivation=p0;
    
    @pyqtSignature("QString")
    def on_cmbxRxTaType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpRxTaType=p0;
    
    @pyqtSignature("int")
    def on_spbxRxBs_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpBs=p0;
    
    @pyqtSignature("int")
    def on_spbxRxSTmin_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpSTmin=p0;
    
    @pyqtSignature("int")
    def on_spbxRxWftMax_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpWftMax=p0;
    
    @pyqtSignature("QString")
    def on_cmbxRxAddressingFormat_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpAddressingFormant=p0;
            if(p0 == 'CANTP_STANDARD'):
                self.spbxRxNTa.setDisabled(True);
                self.spbxRxNSa.setDisabled(True);
            elif(p0 == 'CANTP_EXTENDED'):
                self.spbxRxNTa.setDisabled(False);
                self.spbxRxNSa.setDisabled(False);
    
    @pyqtSignature("int")
    def on_spbxRxNTa_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNTa=p0;
    
    @pyqtSignature("int")
    def on_spbxRxNSa_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNSa=p0;
    
    @pyqtSignature("int")
    def on_spbxRxNar_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNar=p0;
    
    @pyqtSignature("int")
    def on_spbxRxNbr_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNbr=p0;
    
    @pyqtSignature("int")
    def on_spbxRxNcr_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNcr=p0;

    @pyqtSignature("QString")
    def on_leTxPduName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);

    @pyqtSignature("int")
    def on_spbxTxNas_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNas=p0;
    
    @pyqtSignature("int")
    def on_spbxTxNbs_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNbs=p0;
    
    @pyqtSignature("int")
    def on_spbxTxNcs_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNcs=p0;
    
    @pyqtSignature("QString")
    def on_cmbxTxAddressingFormat_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpAddressingFormant=p0;
            if(p0 == 'CANTP_STANDARD'):
                self.spbxTxNTa.setDisabled(True);
                self.spbxTxNSa.setDisabled(True);
            elif(p0 == 'CANTP_EXTENDED'):
                self.spbxTxNTa.setDisabled(False);
                self.spbxTxNSa.setDisabled(False);
    
    @pyqtSignature("int")
    def on_spbxTxNTa_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNTa=p0;
    
    @pyqtSignature("int")
    def on_spbxTxNsa_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpNSa=p0;
    
    @pyqtSignature("QString")
    def on_cmbxTxPduId_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.PduR_PduId=p0;
    
    @pyqtSignature("QString")
    def on_cmbxRxFcPduId_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanIf_FcPduId=p0;
    
    @pyqtSignature("int")
    def on_spbxTxPduDlc_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpTxDI=p0;
    
    @pyqtSignature("QString")
    def on_cmbxTxPduPadding_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpTxPaddingActivation=p0;
    
    @pyqtSignature("QString")
    def on_cmbxTxTaType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.CanTpTxTaType=p0;
    
    def addRxNSdu(self):
        id = len(self.cfg.RxNSduList);
        name='vCanTp_RxNSdu%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanTpRxNPdu(name);
        self.cfg.RxNSduList.append(obj);

    def addTxNSdu(self):
        id = len(self.cfg.TxNSduList);
        name='vCanTp_TxNSdu%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanTpTxNPdu(name);
        self.cfg.TxNSduList.append(obj);

    def delNSdu(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnAdd.text();
        if(text=='Del Rx NSdu'):
            self.delObj(self.cfg.RxNSduList);
        elif(text=='Del Tx NSdu'):
            self.delObj(self.cfg.TxNSduList);
        #reselect a tree item,software trigger on_trCanTpCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trCanTpCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trCanTpCfg_itemClicked(parent, 0);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Rx NSdu'):
            self.addRxNSdu();
        elif(text=='Add Tx NSdu'):
            self.addTxNSdu();
        elif(text=='Del Rx NSdu'
            or text == 'Del Tx NSdu'):
            self.delNSdu();
