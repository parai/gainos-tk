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
    def __init__(self, title, fileInd, cfg, depinfo, parent = None):
        """
        depinfo[0] --> ECUC obj
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title);
        self.cfg = cfg;
        self.depinfo = depinfo;
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
    def reloadTreeDidInfo(self):
        tree=self.trDcm.topLevelItem(1);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.didInfoList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            for obj2 in obj.ControlAccessList+obj.ReadAccessList+obj.WriteAccessList:
                item2 = QTreeWidgetItem(item,QStringList(obj2.name));
    def reloadTreeProtocol(self):
        tree=self.trDcm.topLevelItem(4);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.protocolList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            for obj2 in obj.ConnectionList:
                item2=QTreeWidgetItem(item,QStringList(obj2.name));
                for obj3 in obj2.RxChannelList+obj2.TxChannelList:
                    item3=QTreeWidgetItem(item2,QStringList(obj3.name));
    def reloadGui(self):
        self.reloadTreeGui(0, self.cfg.bufferList); # -- 0  Buffers
        self.reloadTreeDidInfo();                   # -- 1  Did Infos
        self.reloadTreeGui(2, self.cfg.didList);    # -- 2  DIDs
                                                    # -- 3  Memory
        self.reloadTreeProtocol();                  # -- 4  Protocols

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
            self.btn1.setText('Add Did Info');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='DIDs'):
            self.btn1.setText('Add DID');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Memory'):
            self.initButton(); # disable all button
        elif(trname=='Protocols'):
            self.btn1.setText('Add Protocol');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
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
        #-------------------------------  二级 -------------------------------------------------
        elif(self.curtree.parent().text(0) == 'Buffers'):
            self.btn1.setText('Del Buffer');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Did Infos'):
            self.btn1.setText('Del Did Info');
            self.btn1.setDisabled(False);
            self.btn2.setText('Add Control Access')
            self.btn2.setDisabled(False);
            self.btn3.setText('Add Read Access')
            self.btn3.setDisabled(False);
            self.btn4.setText('Add Write Access')
            self.btn4.setDisabled(False);
        elif(self.curtree.parent().text(0) == 'DIDs'):
            self.btn1.setText('Del DID');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Protocols'):
            self.btn1.setText('Del Protocol');
            self.btn1.setDisabled(False);
            self.btn2.setText('Add Connection');
            self.btn2.setDisabled(False);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        #-------------------------------  三级 -------------------------------------------------
        elif(self.curtree.parent().parent().text(0) == 'Did Infos'):
            self.btn1.setText('Del Access');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().parent().text(0) == 'Protocols'):
            self.btn1.setText('Del Connection');
            self.btn1.setDisabled(False);
            self.btn2.setText('Add Rx Channel');
            self.btn2.setDisabled(False);
            self.btn3.setText('Add Tx Channel');
            self.btn3.setDisabled(False);
            self.btn4.setDisabled(True);
        #-------------------------------- 四级 -------------------
        elif(self.curtree.parent().parent().parent().text(0) == 'Protocols'):
            self.btn1.setText('Del Channel');
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
    def refreshDidInfoTab(self, name):
        self.curobj = gcfindObj(self.cfg.didInfoList, name);
        self.leDidInfoName.setText(name);
        self.cbxDidInfoFixedLength.setChecked(self.curobj.FixedLength);
        self.cbxDidInfoDynamicllyDefined.setChecked(self.curobj.DynamicllyDefined);
        self.cbxDidInfoScalingEnable.setChecked(self.curobj.ScalingEnable);
        self.cbxDidInfoScalingEnable.setChecked(self.curobj.ScalingEnable);
        self.spbxDidInfoScalingInfoSize.setDisabled(not self.curobj.ScalingEnable);
        self.spbxDidInfoScalingInfoSize.setValue(self.curobj.ScalingInfoSize);
        self.enableTab(1);
    def refreshDidControlTab(self, obj):
        self.curobj = obj;
        self.leDidControlName.setText(obj.name);
        self.enableTab(2);
    def refreshDidReadTab(self, obj):
        self.curobj = obj;
        self.leDidReadName.setText(obj.name);
        self.enableTab(3);
    def refreshDidWriteTab(self, obj):
        self.curobj = obj;
        self.leDidWriteName.setText(obj.name);
        self.enableTab(4);
    def refreshDidAccessTab(self, name):
        obj = gcfindObj(self.cfg.didInfoList, self.curtree.parent().text(0));
        if(gcfindObj(obj.ControlAccessList, name)):
            self.refreshDidControlTab(gcfindObj(obj.ControlAccessList, name));
        elif(gcfindObj(obj.ReadAccessList, name)):
            self.refreshDidReadTab(gcfindObj(obj.ReadAccessList, name));
        elif(gcfindObj(obj.WriteAccessList, name)):
            self.refreshDidWriteTab(gcfindObj(obj.WriteAccessList, name));
    def refreshDIDTab(self, name):
        self.curobj = gcfindObj(self.cfg.didList, name);
        self.leDIDName.setText(name);
        self.leDidId.setText(self.curobj.id);
        self.spbxDidSize.setValue(self.curobj.size);
        # /---- re-add did info to cmbxDidInfoRef
        self.cmbxDidInfoRef.clear();
        for obj in self.cfg.didInfoList:
            self.cmbxDidInfoRef.addItem(obj.name);
        self.cmbxDidInfoRef.setCurrentIndex(self.cmbxDidInfoRef.findText(self.curobj.didInfoRef));
        #---------- I donn't understand so just disable them
        self.cmbxDidRef.setDisabled(True);
        self.cbxUsePort.setChecked(self.curobj.usePort);
        self.cbxUsePort.setDisabled(True);# -- the others disabled by Qt Creater
        self.enableTab(5);
    def refreshProtocolTab(self, name):
        self.curobj = gcfindObj(self.cfg.protocolList, name);
        self.leProtocolName.setText(name);
        self.cmbxProtocolId.setCurrentIndex(self.cmbxProtocolId.findText(self.curobj.ProtocolId));
        self.cmbxTransType.setCurrentIndex(self.cmbxTransType.findText(self.curobj.TransType));
        self.cmbxRxBufferID.clear();
        self.cmbxTxBufferID.clear();
        for obj in self.cfg.bufferList:
            self.cmbxRxBufferID.addItem(obj.name);
            self.cmbxTxBufferID.addItem(obj.name);
        self.cmbxRxBufferID.setCurrentIndex(self.cmbxRxBufferID.findText(self.curobj.RxBufferID));
        self.cmbxTxBufferID.setCurrentIndex(self.cmbxTxBufferID.findText(self.curobj.TxBufferID));
        self.cmbxTimeLimit.setCurrentIndex(self.cmbxTimeLimit.findText(self.curobj.TimeLimit));
        self.cmbxServiceTable.setCurrentIndex(self.cmbxServiceTable.findText(self.curobj.ServiceTable));
        self.enableTab(6);
    def refreshRxProtocolTab(self, obj):
        self.curobj=obj;
        self.leRxProtocolName.setText(obj.name);
        self.cmbxRxAddrType.setCurrentIndex(self.cmbxRxAddrType.findText(obj.RxAddrType));
        self.cmbxRxPdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxRxPdu.addItem(pdu.name+'_Rx');
        self.cmbxRxPdu.setCurrentIndex(self.cmbxRxPdu.findText(obj.RxPdu));
        self.enableTab(7);
    def refreshConnectionTab(self, name):
        p = gcfindObj(self.cfg.protocolList, self.curtree.parent().text(0));
        self.curobj = gcfindObj(p.ConnectionList, name);
        self.leConnectionName.setText(name);
        self.enableTab(8);
    def refreshTxProtocolTab(self, obj):
        self.curobj=obj;
        self.leTxProtocolName.setText(obj.name);
        self.cmbxTxPdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxTxPdu.addItem(pdu.name+'_Tx');
        self.cmbxTxPdu.setCurrentIndex(self.cmbxTxPdu.findText(obj.TxPdu));
        self.enableTab(9);
    def refreshChannelTab(self, name):
        protocol = gcfindObj(self.cfg.protocolList, self.curtree.parent().parent().text(0));
        connection = gcfindObj(protocol.ConnectionList, self.curtree.parent().text(0));
        if(gcfindObj(connection.RxChannelList, name)):
            self.refreshRxProtocolTab(gcfindObj(connection.RxChannelList, name));
        elif(gcfindObj(connection.TxChannelList, name)):
            self.refreshTxProtocolTab(gcfindObj(connection.TxChannelList, name));
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname == 'Buffers'):
            self.refreshBufferTab(objname);
        elif(trname == 'Did Infos'):
            self.refreshDidInfoTab(objname);
        elif(trname == 'DIDs'):
            self.refreshDIDTab(objname);
        elif(trname == 'Protocols'):
            self.refreshProtocolTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Did Infos'):
            self.refreshDidAccessTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Protocols'):
            self.refreshConnectionTab(objname);
        elif(self.curtree.parent().parent().parent().text(0) == 'Protocols'):
            self.refreshChannelTab(objname);
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trDcm_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        self.refreshTab();
# ========================== Del Object ============  
    def delDidAccess(self):
        #find parent
        obj = gcfindObj(self.cfg.didInfoList, self.curtree.parent().text(0));
        #find access list curobj in
        if(gcfindObj(obj.ControlAccessList, self.curobj.name)):
            obj.ControlAccessList.remove(self.curobj);
        elif(gcfindObj(obj.ReadAccessList, self.curobj.name)):
            obj.ReadAccessList.remove(self.curobj);
        elif(gcfindObj(obj.WriteAccessList, self.curobj.name)):
            obj.WriteAccessList.remove(self.curobj);
    def delProtocolChannel(self):
        protocol = gcfindObj(self.cfg.protocolList, self.curtree.parent().parent().text(0));
        connection = gcfindObj(protocol.ConnectionList, self.curtree.parent().text(0));
        if(gcfindObj(connection.RxChannelList, self.curobj.name)):
            connection.RxChannelList.remove(self.curobj);
        elif(gcfindObj(connection.TxChannelList, self.curobj.name)):
            connection.TxChannelList.remove(self.curobj);
    def delObj(self, text):
        #remove it from obj list
        if(text=='Del Buffer'):
            self.cfg.bufferList.remove(self.curobj);
        elif(text == 'Del Did Info'):
            self.cfg.didInfoList.remove(self.curobj);
        elif(text == 'Del Access'):
            self.delDidAccess();
        elif(text == 'Del DID'):
            self.cfg.didList.remove(self.curobj);
        elif(text == 'Del Protocol'):
            self.cfg.protocolList.remove(self.curobj);
        elif(text == 'Del Connection'):
            p = gcfindObj(self.cfg.protocolList, self.curtree.parent().text(0));
            p.ConnectionList.remove(self.curobj);
        elif(text == 'Del Channel'):
            self.delProtocolChannel();
        #delete the tree, reselect a tree item
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        del self.curtree;
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trDcm_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trDcm_itemClicked(parent, 0);
# ========================== Add Object ============
    def addBuffer(self):
        id = len(self.cfg.bufferList);
        name=QString('vDcmBuffer%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=DcmBuffer(name);
        self.cfg.bufferList.append(obj);
        self.curtree.setExpanded(True);
    def addDidInfo(self):
        id = len(self.cfg.didInfoList);
        name=QString('vDcmDidInfo%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=DcmDidInfo(name);
        self.cfg.didInfoList.append(obj);
        self.curtree.setExpanded(True);
    def addDidInfoControlAccess(self):
        id = len(self.curobj.ControlAccessList);
        name=QString('ControlAccess%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmDidInfoControlAccess(name);
        self.curobj.ControlAccessList.append(obj);
        self.curtree.setExpanded(True);
    def addDidInfoReadAccess(self):
        id = len(self.curobj.ReadAccessList);
        name=QString('ReadAccess%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmDidInfoReadAccess(name);
        self.curobj.ReadAccessList.append(obj);
        self.curtree.setExpanded(True);
    def addDidInfoWriteAccess(self):
        id = len(self.curobj.WriteAccessList);
        name=QString('WriteAccess%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmDidInfoWriteAccess(name);
        self.curobj.WriteAccessList.append(obj);
        self.curtree.setExpanded(True);
    def addDID(self):
        id = len(self.cfg.didList);
        name=QString('vDid%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmDID(name, hex(id));
        self.cfg.didList.append(obj);
        self.curtree.setExpanded(True); 
    def addProtocol(self):
        id = len(self.cfg.protocolList);
        name=QString('vProtocol%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmProtocol(name);
        self.cfg.protocolList.append(obj);
        self.curtree.setExpanded(True);
    def addConnection(self):
        id = len(self.curobj.ConnectionList);
        name=QString('vConnection%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmConnection(name);
        self.curobj.ConnectionList.append(obj);
        self.curtree.setExpanded(True);
    def addRxChannel(self):
        id = len(self.curobj.RxChannelList);
        name=QString('vRxChannel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmRxChannel(name);
        self.curobj.RxChannelList.append(obj);
        self.curtree.setExpanded(True);
    def addTxChannel(self):
        id = len(self.curobj.TxChannelList);
        name=QString('vTxChannel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmTxChannel(name);
        self.curobj.TxChannelList.append(obj);
        self.curtree.setExpanded(True);
# ========================== Button ================        
    @pyqtSignature("")
    def on_btn1_clicked(self):
        text=self.btn1.text();
        if(text=='Add Buffer'):
            self.addBuffer();
        elif(text == 'Add Did Info'):
            self.addDidInfo();
        elif(text == 'Add DID'):
            self.addDID();
        elif(text == 'Add Protocol'):
            self.addProtocol();
        elif(text[:3] == 'Del'):
            self.delObj(text);
        self.fileInd(False);
    @pyqtSignature("")
    def on_btn2_clicked(self):
        text=self.btn2.text();
        if(text=='Add Control Access'):
            self.addDidInfoControlAccess();
        elif(text=='Add Connection'):
            self.addConnection();
        elif(text=='Add Rx Channel'):
            self.addRxChannel();
        self.fileInd(False);
    @pyqtSignature("")
    def on_btn3_clicked(self):
        text=self.btn3.text();
        if(text=='Add Read Access'):
            self.addDidInfoReadAccess();
        elif(text=='Add Tx Channel'):
            self.addTxChannel();
        self.fileInd(False);
    @pyqtSignature("")
    def on_btn4_clicked(self):
        text=self.btn4.text();
        if(text=='Add Write Access'):
            self.addDidInfoWriteAccess();
        self.fileInd(False);
# ========================= General =====================================
    @pyqtSignature("bool")
    def on_cbxDevErrorDetection_clicked(self, checked):
        if self.cfg.general.DevErrorDetection != checked:
            self.cfg.general.DevErrorDetection = checked;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxRespondAllRequest_clicked(self, checked):
        if self.cfg.general.RespondAllRequest != checked:
            self.cfg.general.RespondAllRequest = checked;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxVersionInfoApi_clicked(self, checked):
        if self.cfg.general.VersionInfoApi != checked:
            self.cfg.general.VersionInfoApi = checked;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxResponsePending_clicked(self, checked):
        if self.cfg.general.ResponsePending != checked:
            self.cfg.general.ResponsePending = checked;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMainFunctionPeriod_valueChanged(self, p0):
        if self.cfg.general.MainFunctionPeriod != p0:
            self.cfg.general.MainFunctionPeriod = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMaxNegativeResponse_valueChanged(self, p0):
        if self.cfg.general.MaxNegativeResponse != p0:
            self.cfg.general.MaxNegativeResponse = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMaxNumberofSimultaneousPeriodictransmissions_valueChanged(self, p0):
        if self.cfg.general.MaxNumberofSimultaneousPeriodictransmissions != p0:
            self.cfg.general.MaxNumberofSimultaneousPeriodictransmissions = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPeriodicTransmissionSlow_valueChanged(self, p0):
        if self.cfg.general.PeriodicTransmissionSlow != p0:
            self.cfg.general.PeriodicTransmissionSlow = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPeriodicTransmissionMedium_valueChanged(self, p0):
        if self.cfg.general.PeriodicTransmissionMedium != p0:
            self.cfg.general.PeriodicTransmissionMedium = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPeriodicTransmissionFast_valueChanged(self, p0):
        if self.cfg.general.PeriodicTransmissionFast != p0:
            self.cfg.general.PeriodicTransmissionFast = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMaxSourcesforOneDynamicIdentifier_valueChanged(self, p0):
        if self.cfg.general.MaxSourcesforOneDynamicIdentifier != p0:
            self.cfg.general.MaxSourcesforOneDynamicIdentifier = p0;
            self.fileInd(False);
# ====================== Buffer ======================
    @pyqtSignature("QString")
    def on_leBufferName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxBufferSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.size!=p0):
                self.curobj.size=p0;
                self.fileInd(False);
# ===================== Did Info ======================   
    @pyqtSignature("QString")
    def on_leDidInfoName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxDidInfoFixedLength_clicked(self, checked):
        if(self.curobj!=None):
            if(self.curobj.FixedLength!=checked):
                self.curobj.FixedLength=checked
                self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxDidInfoDynamicllyDefined_clicked(self, checked):
        if(self.curobj!=None):
            if(self.curobj.DynamicllyDefined!=checked):
                self.curobj.DynamicllyDefined=checked;
                self.fileInd(False); 
    @pyqtSignature("bool")
    def on_cbxDidInfoScalingEnable_clicked(self, checked):
        if(self.curobj!=None):
            if(self.curobj.ScalingEnable!=checked):
                self.curobj.ScalingEnable=checked;
                self.spbxDidInfoScalingInfoSize.setDisabled(not checked);
                self.fileInd(False); 
    @pyqtSignature("int")
    def on_spbxDidInfoScalingInfoSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.ScalingInfoSize!=p0):
                self.curobj.ScalingInfoSize=p0;
                self.fileInd(False);
            
# ==================== Did Info Control Access =========================
    @pyqtSignature("QString")
    def on_leDidControlName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
# ==================== Did Info Read Access =========================
    @pyqtSignature("QString")
    def on_leDidReadName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
# ==================== Did Info Write Access =========================
    @pyqtSignature("QString")
    def on_leDidWriteName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
# ==================== DID ===========================================
    @pyqtSignature("QString")
    def on_leDIDName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_leDidId_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.id!=p0):
                self.curobj.id=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxDidSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.size!=p0):
                self.curobj.size=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxDidInfoRef_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.didInfoRef!=p0):
                self.curobj.didInfoRef=p0;
                self.fileInd(False);
# ==================== Protocol ===========================================
    @pyqtSignature("QString")
    def on_leProtocolName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);        
    @pyqtSignature("QString")
    def on_cmbxProtocolId_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.ProtocolId!=p0):
                self.curobj.ProtocolId=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxTransType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.TransType!=p0):
                self.curobj.TransType=p0;
    @pyqtSignature("QString")
    def on_cmbxRxBufferID_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.RxBufferID!=p0):
                self.curobj.RxBufferID=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxTxBufferID_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.TxBufferID!=p0):
                self.curobj.TxBufferID=p0;
    @pyqtSignature("QString")
    def on_cmbxTimeLimit_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.TimeLimit!=p0):
                self.curobj.TimeLimit=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxServiceTable_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.ServiceTable!=p0):
                self.curobj.ServiceTable=p0;
                self.fileInd(False);
# ====================== Connection ====================================
    @pyqtSignature("QString")
    def on_leConnectionName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False); 
#==================== Protocol Rx ============================================                
    @pyqtSignature("QString")
    def on_leRxProtocolName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxRxAddrType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.RxAddrType!=p0):
                self.curobj.RxAddrType=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxRxPdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.RxPdu!=p0):
                self.curobj.RxPdu=p0;
                self.fileInd(False);
#===================== Protocol Tx =======================
    @pyqtSignature("QString")
    def on_leTxProtocolName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxTxPdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.TxPdu!=p0):
                self.curobj.TxPdu=p0;
                self.fileInd(False);
