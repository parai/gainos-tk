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
from Ui_cd_dcm import Ui_cd_dcm
from gainos_tk_dcm_cfg import *
class cd_dcm(QDialog, Ui_cd_dcm):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title);
        self.cfg = cfg;
        self.fileInd = fileInd;
        self.curtree = None; 
        self.curobj = None;
        self.initGui();
    def initGeneral(self):
        self.cbxDevErrorDetection.setChecked(self.cfg.general.DevErrorDetection);
        self.cbxRespondAllRequest.setChecked(self.cfg.general.RespondAllRequest);
        self.cbxVersionInfoApi.setChecked(self.cfg.general.VersionInfoApi);
        self.cbxResponsePending.setChecked(self.cfg.general.ResponsePending);
        self.spbxMainFunctionPeriod.setValue(self.cfg.general.MainFunctionPeriod)
        self.spbxMaxNegativeResponse.setValue(self.cfg.general.MaxNegativeResponse)
        self.spbxMaxNumberofSimultaneousPeriodictransmissions.setValue(self.cfg.general.MaxNumberofSimultaneousPeriodictransmissions)
        self.spbxPeriodicTransmissionSlow.setValue(self.cfg.general.PeriodicTransmissionSlow)
        self.spbxPeriodicTransmissionMedium.setValue(self.cfg.general.PeriodicTransmissionMedium)
        self.spbxPeriodicTransmissionFast.setValue(self.cfg.general.PeriodicTransmissionFast)
        self.spbxMaxSourcesforOneDynamicIdentifier.setValue(self.cfg.general.MaxSourcesforOneDynamicIdentifier)
    def initButton(self):
        self.btn1.setDisabled(True);
        self.btn2.setDisabled(True);
        self.btn3.setDisabled(True);
        self.btn4.setDisabled(True);
    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 22):
            self.tblDcmCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 22):
            if(i==index):
                self.tblDcmCfg.setTabEnabled(i, True);
                self.tblDcmCfg.setCurrentIndex(i);
            else:
                self.tblDcmCfg.setTabEnabled(i, False);
    
    def initTab(self):
        self.disableAllTab();
    
    def reloadTreeGui(self, trindex, list):
        tree=self.trDcm.topLevelItem(trindex);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
    def reloadGui(self):
        self.reloadTreeGui(0, self.cfg.bufferList);
    def initGui(self):
        self.initGeneral();
        self.initTab();
        self.initButton();
        self.reloadGui();

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Buffers'):
            self.btn1.setText('Add Buffer');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Did Infos'):
            self.initButton(); # disable all button
        elif(trname=='DIDs'):
            self.initButton(); # disable all button
        elif(trname=='Memory'):
            self.initButton(); # disable all button
        elif(trname=='Request Services'):
            self.initButton(); # disable all button
        elif(trname=='Protocols'):
            self.initButton(); # disable all button
        elif(trname=='Request Services'):
            self.initButton(); # disable all button
        elif(trname=='Service Tables'):
            self.initButton(); # disable all button
        elif(trname=='Routine Infos'):
            self.initButton(); # disable all button
        elif(trname=='Routines'):
            self.initButton(); # disable all button
        elif(trname=='Security Levels'):
            self.initButton(); # disable all button
        elif(trname=='Service Tables'):
            self.initButton(); # disable all button
        elif(trname=='Seeion Controls'):
            self.initButton(); # disable all button
        elif(trname=='Sessions'):
            self.initButton(); # disable all button
        elif(trname=='Timings'):
            self.initButton(); # disable all button
        elif(self.curtree.parent().text(0) == 'Buffers'):
            self.btn1.setText('Del Buffer');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        else:
            self.initButton(); # disable all button
    def refreshBufferTab(self, name):
        self.curobj=gcfindObj(self.cfg.bufferList, name);
        self.leBufferName.setText(name);
        self.spbxBufferSize.setValue(self.curobj.size);
        self.enableTab(0);
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname == 'Buffers'):
            self.refreshBufferTab(objname);
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trDcm_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        self.refreshTab();
# ========================== Del Object ============  
    def delObj(self, text):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        if(text=='Del Buffer'):
            self.cfg.bufferList.remove(self.curobj);
        del self.curtree;
        #reselect a tree item,software trigger on_trModule_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trDcm_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trDcm_itemClicked(parent, 0);
        self.fileInd(False);
# ========================== Add Object ============
    def addBuffer(self):
        id = len(self.cfg.bufferList);
        name=QString('vDcmBuffer%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=DcmBuffer(name);
        self.cfg.bufferList.append(obj);
        self.curtree.setExpanded(True);
# ========================== Button ================        
    @pyqtSignature("")
    def on_btn1_clicked(self):
        text=self.btn1.text();
        if(text=='Add Buffer'):
            self.addBuffer();
        elif(text == 'Del Buffer'):
            self.delObj(text);
# ========================= General =====================================
    @pyqtSignature("bool")
    def on_cbxDevErrorDetection_clicked(self, checked):
        self.cfg.general.DevErrorDetection = checked;
        self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxRespondAllRequest_clicked(self, checked):
        self.cfg.general.RespondAllRequest = checked;
        self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxVersionInfoApi_clicked(self, checked):
        self.cfg.general.VersionInfoApi = checked;
        self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxResponsePending_clicked(self, checked):
        self.cfg.general.ResponsePending = checked;
        self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMainFunctionPeriod_valueChanged(self, p0):
        self.cfg.general.MainFunctionPeriod = p0;
        self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMaxNegativeResponse_valueChanged(self, p0):
        self.cfg.general.MaxNegativeResponse = p0;
    @pyqtSignature("int")
    def on_spbxMaxNumberofSimultaneousPeriodictransmissions_valueChanged(self, p0):
        self.cfg.general.MaxNumberofSimultaneousPeriodictransmissions = p0;
        self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPeriodicTransmissionSlow_valueChanged(self, p0):
        self.cfg.general.PeriodicTransmissionSlow = p0;
        self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPeriodicTransmissionMedium_valueChanged(self, p0):
        self.cfg.general.PeriodicTransmissionMedium = p0;
        self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPeriodicTransmissionFast_valueChanged(self, p0):
        self.cfg.general.PeriodicTransmissionFast = p0;
        self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMaxSourcesforOneDynamicIdentifier_valueChanged(self, p0):
        self.cfg.general.MaxSourcesforOneDynamicIdentifier = p0;
        self.fileInd(False);
# ====================== Buffer ======================
    @pyqtSignature("QString")
    def on_leBufferName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxBufferSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.size=p0;
            self.fileInd(False);
        
