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
        for i in  range(0, 23):
            self.tblDcmCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 23):
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
    def reloadTreeServiceTable(self):
        tree=self.trDcm.topLevelItem(9);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.serviceTableList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            for obj2 in obj.serviceList:
                item2=QTreeWidgetItem(item,QStringList(obj2.name));
    def reloadGui(self):
        self.reloadTreeGui(0, self.cfg.bufferList);         # -- 0  Buffers
        self.reloadTreeDidInfo();                           # -- 1  Did Infos
        self.reloadTreeGui(2, self.cfg.didList);            # -- 2  DIDs
        # -- 3  Memory
        self.reloadTreeProtocol();                          # -- 4  Protocols
        self.reloadTreeGui(5, self.cfg.requestServiceList); # -- 5  Request Services
        # -- 6  Routine Infos
        # -- 7  Routines
        self.reloadTreeGui(8, self.cfg.securityLevelList);  # -- 8  Security Levels
        self.reloadTreeServiceTable();                      # -- 9  Service Tables
        self.reloadTreeGui(10, self.cfg.sessionControlList); # -- 10 Session Controls
        self.reloadTreeGui(11, self.cfg.sessionList);        # -- 11 Sessions
        self.reloadTreeGui(12, self.cfg.timingList); # -- 12 Timings
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
            self.btn1.setText('Add Request Service');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Routine Infos'):
            self.initButton(); # disable all button
        elif(trname=='Routines'):
            self.initButton(); # disable all button
        elif(trname=='Security Levels'):
            self.btn1.setText('Add Security Level');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Service Tables'):
            self.btn1.setText('Add Service Table');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Session Controls'):
            self.btn1.setText('Add Session Control');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Sessions'):
            self.btn1.setText('Add Session');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(trname=='Timings'):
            self.btn1.setText('Add Timing');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
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
        elif(self.curtree.parent().text(0) == 'Request Services'):
            self.btn1.setText('Del Request Service');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Security Levels'):
            self.btn1.setText('Del Security Level');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Service Tables'):
            self.btn1.setText('Del Service Table');
            self.btn1.setDisabled(False);
            self.btn2.setText('Add Service');
            self.btn2.setDisabled(False);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Session Controls'):
            self.btn1.setText('Del Session Control');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Sessions'):
            self.btn1.setText('Del Session');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
            self.btn4.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Timings'):
            self.btn1.setText('Del Timing');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
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
        elif(self.curtree.parent().parent().text(0) == 'Service Tables'):
            self.btn1.setText('Del Service');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
            self.btn3.setDisabled(True);
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
#--------- Tree Control Common operation -----------------------------
    def moveTreeItem(self, trFrom, trTo):
        if(trFrom.currentItem()):
            name = trFrom.currentItem().text(0)
            item = QTreeWidgetItem(trTo, QStringList(name)); #add
            trFrom.takeTopLevelItem(trFrom.indexOfTopLevelItem(trFrom.currentItem()));#remove
    def refreshTreeCtrl(self, trSrc, trDst, lsSrc, lsDst):
        """lsSrc：源资源列表，trSrc：源目录树控件
           lsDst：目标资源列表，trDst：目标目录树控件
           一般的，lsSrc是 GaInOS-TK一个对象列表
           而 lsDst则是一个字符串 String 列表
        """
        #移除所有
        for index in range(0, trSrc.topLevelItemCount()):
            temp=trSrc.takeTopLevelItem(0);
            del temp;
        for index in range(0, trDst.topLevelItemCount()):
            temp=trDst.takeTopLevelItem(0);
            del temp;
        #向相应控件注册对象
        for str in lsDst:
            if(gcfindObj(lsSrc, str) != None):#if it still in the lsSrc
                item=QTreeWidgetItem(trDst,QStringList(str));
            else: # maybe you have removed & rename it, so should remove it from the list
                lsDst.remove(str);
        for obj in lsSrc:
            if(gcfindStr(lsDst, obj.name) == None):
                item=QTreeWidgetItem(trSrc,QStringList(obj.name));
        #print lsDst
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
        self.refreshTreeCtrl(self.trDidCtrlSecSrc, self.trDidCtrlSecDst, self.cfg.securityLevelList, self.curobj.securityRefList);
        self.refreshTreeCtrl(self.trDidCtrlSesSrc, self.trDidCtrlSesDst, self.cfg.sessionList, self.curobj.sessionRefList);
        self.enableTab(2);
    def refreshDidReadTab(self, obj):
        self.curobj = obj;
        self.leDidReadName.setText(obj.name);
        self.refreshTreeCtrl(self.trDidReadSecSrc, self.trDidReadSecDst, self.cfg.securityLevelList, self.curobj.securityRefList);
        self.refreshTreeCtrl(self.trDidReadSesSrc, self.trDidReadSesDst, self.cfg.sessionList, self.curobj.sessionRefList);
        self.enableTab(3);
    def refreshDidWriteTab(self, obj):
        self.curobj = obj;
        self.leDidWriteName.setText(obj.name);
        self.refreshTreeCtrl(self.trDidWriteSecSrc, self.trDidWriteSecDst, self.cfg.securityLevelList, self.curobj.securityRefList);
        self.refreshTreeCtrl(self.trDidWriteSesSrc, self.trDidWriteSesDst, self.cfg.sessionList, self.curobj.sessionRefList);
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
        self.cmbxTimeLimit.clear();
        self.cmbxServiceTable.clear();
        for obj in self.cfg.serviceTableList:
            self.cmbxServiceTable.addItem(obj.name);
        for obj in self.cfg.timingList:
            self.cmbxTimeLimit.addItem(obj.name);
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
    def refreshRequestServiceTab(self, name):
        self.curobj = gcfindObj(self.cfg.requestServiceList, name);
        self.leRequestServiceName.setText(self.curobj.name);
        self.leRequestServiceStart.setText(self.curobj.start);
        self.leRequestServiceStop.setText(self.curobj.stop);
        self.enableTab(10);
    
    def refreshSecurityLevelTab(self, name):
        self.curobj = gcfindObj(self.cfg.securityLevelList, name);
        self.leSecurityLevelName.setText(name);
        self.spbxSecurityLevel.setValue(self.curobj.level);
        self.spbxSecurityLevelRecordSize.setValue(self.curobj.recordSize);
        self.spbxSecurityLevelSeedSize.setValue(self.curobj.seedSize);
        self.spbxSecurityLevelKeySize.setValue(self.curobj.keySize);
        self.leSecurityLevelGetSeedCbk.setText(self.curobj.getSeedCbk);
        self.leSecurityLevelCopmKeyCbk.setText(self.curobj.compKeyCbk);
        self.enableTab(17);
    def refreshServiceTableTab(self, name):
        self.curobj = gcfindObj(self.cfg.serviceTableList, name)
        self.leServiceTableName.setText(name);
        self.enableTab(18);
    def refreshServiceTab(self, name):
        p = gcfindObj(self.cfg.serviceTableList, self.curtree.parent().text(0));
        self.curobj = gcfindObj(p.serviceList, name);
        self.leServiceName.setText(name);
        self.cmbxServiceID.setCurrentIndex(self.cmbxServiceID.findText(self.curobj.serviceId));
        self.cbxSubfuncAvail.setChecked(self.curobj.subfuncAvail);
        self.refreshTreeCtrl(self.trServiceSecSrc, self.trServiceSecDst, self.cfg.securityLevelList, self.curobj.securityRefList);
        self.refreshTreeCtrl(self.trServiceSesSrc, self.trServiceSesDst, self.cfg.sessionList, self.curobj.sessionRefList);
        self.enableTab(19)
    def refreshSessionControlTab(self, name):
        self.curobj = gcfindObj(self.cfg.sessionControlList, name);
        self.leSessionControlName.setText(name);
        self.leGetSesChgPermission.setText(self.curobj.GetSesChgPermission);
        self.enableTab(20);
    def refreshSessionTab(self, name):
        self.curobj = gcfindObj(self.cfg.sessionList, name);
        self.leSessionName.setText(name);
        self.enableTab(21);
    def refreshTimingTab(self, name):
        self.curobj = gcfindObj(self.cfg.timingList, name);
        self.leTimingName.setText(name);
        self.spbxP2ServerMax.setValue(self.curobj.P2ServerMax);
        self.spbxP2ServerMin.setValue(self.curobj.P2ServerMin);
        self.spbxS3Server.setValue(self.curobj.S3Server);
        self.enableTab(22);
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        #------------------------ 一级 ----------------------------------------
        if(trname == 'Buffers'):
            self.refreshBufferTab(objname);
        elif(trname == 'Did Infos'):
            self.refreshDidInfoTab(objname);
        elif(trname == 'DIDs'):
            self.refreshDIDTab(objname);
        elif(trname == 'Protocols'):
            self.refreshProtocolTab(objname);
        elif(trname == 'Request Services'):
            self.refreshRequestServiceTab(objname);
        elif(trname == 'Security Levels'):
            self.refreshSecurityLevelTab(objname);
        elif(trname == 'Service Tables'):
            self.refreshServiceTableTab(objname);
        elif(trname == 'Session Controls'):
            self.refreshSessionControlTab(objname);
        elif(trname == 'Sessions'):
            self.refreshSessionTab(objname);
        elif(trname == 'Timings'):
            self.refreshTimingTab(objname);
        # ----------------------------- 二级 -----------------------
        elif(self.curtree.parent().parent().text(0) == 'Did Infos'):
            self.refreshDidAccessTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Protocols'):
            self.refreshConnectionTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Service Tables'):
            self.refreshServiceTab(objname);
        # ---------------------------- 三级 -----------------------------------
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
        elif(text == 'Del Request Service'):
            self.cfg.requestServiceList.remove(self.curobj);
        elif(text == 'Del Security Level'):
            self.cfg.securityLevelList.remove(self.curobj);
        elif(text == 'Del Service Table'):
            self.cfg.serviceTableList.remove(self.curobj);
        elif(text == 'Del Service'):
            p = gcfindObj(self.cfg.serviceTableList, self.curtree.parent().text(0));
            p.serviceList.remove(self.curobj);
        elif(text == 'Del Session Control'):
            self.cfg.sessionControlList.remove(self.curobj);
        elif(text == 'Del Session'):
            self.cfg.sessionList.remove(self.curobj);
        elif(text == 'Del Timing'):
            self.cfg.timingList.remove(self.curobj);
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
    def addRequestService(self):
        id = len(self.cfg.requestServiceList);
        name=QString('vRequestService%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmRequestService(name);
        self.cfg.requestServiceList.append(obj);
        self.curtree.setExpanded(True);
    def addSecurityLevel(self):
        id = len(self.cfg.securityLevelList);
        name=QString('vSecurityLevel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmSecurityLevel(name);
        self.cfg.securityLevelList.append(obj);
        self.curtree.setExpanded(True);
    def addServiceTable(self):
        id = len(self.cfg.serviceTableList);
        name=QString('vServiceTable%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmServiceTable(name);
        self.cfg.serviceTableList.append(obj);
        self.curtree.setExpanded(True);
    def addService(self):
        id = len(self.curobj.serviceList);
        name=QString('vService%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmService(name);
        self.curobj.serviceList.append(obj);
        self.curtree.setExpanded(True);
    def addSessionControl(self):
        id = len(self.cfg.sessionControlList);
        name=QString('vSessionControl%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmSessionControl(name);
        self.cfg.sessionControlList.append(obj);
        self.curtree.setExpanded(True);
    def addSession(self):
        id = len(self.cfg.sessionList);
        name=QString('vSession%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmSession(name);
        self.cfg.sessionList.append(obj);
        self.curtree.setExpanded(True);
    def addTiming(self):
        id = len(self.cfg.timingList);
        name=QString('vTiming%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj = DcmTiming(name);
        self.cfg.timingList.append(obj);
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
        elif(text == 'Add Request Service'):
            self.addRequestService();
        elif(text == 'Add Security Level'):
            self.addSecurityLevel();
        elif(text == 'Add Service Table'):
            self.addServiceTable();
        elif(text == 'Add Session Control'):
            self.addSessionControl();
        elif(text == 'Add Session'):
            self.addSession();
        elif(text == 'Add Timing'):
            self.addTiming();
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
        elif(text == 'Add Service'):
            self.addService();
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
    @pyqtSignature("")
    def on_btnDidCtrlSecAdd_clicked(self):
        if(self.trDidCtrlSecSrc.currentItem()):
            self.curobj.securityRefList.append(self.trDidCtrlSecSrc.currentItem().text(0));
            self.moveTreeItem(self.trDidCtrlSecSrc, self.trDidCtrlSecDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidCtrlSecDel_clicked(self):
        if(self.trDidCtrlSecDst.currentItem()):
            self.curobj.securityRefList.remove(self.trDidCtrlSecDst.currentItem().text(0));
            self.moveTreeItem(self.trDidCtrlSecDst, self.trDidCtrlSecSrc);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidCtrlSesAdd_clicked(self):
        if(self.trDidCtrlSesSrc.currentItem()):
            self.curobj.sessionRefList.append(self.trDidCtrlSesSrc.currentItem().text(0));
            self.moveTreeItem(self.trDidCtrlSesSrc, self.trDidCtrlSesDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidCtrlSesDel_clicked(self):
        if(self.trDidCtrlSesDst.currentItem()):
            self.curobj.sessionRefList.remove(self.trDidCtrlSesDst.currentItem().text(0));
            self.moveTreeItem(self.trDidCtrlSesDst, self.trDidCtrlSesSrc);
            self.fileInd(False);
# ==================== Did Info Read Access =========================
    @pyqtSignature("QString")
    def on_leDidReadName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidReadSecAdd_clicked(self):
        if(self.trDidReadSecSrc.currentItem()):
            self.curobj.securityRefList.append(self.trDidReadSecSrc.currentItem().text(0));
            self.moveTreeItem(self.trDidReadSecSrc, self.trDidReadSecDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidReadSecDel_clicked(self):
        if(self.trDidReadSecDst.currentItem()):
            self.curobj.securityRefList.remove(self.trDidReadSecDst.currentItem().text(0));
            self.moveTreeItem(self.trDidReadSecDst, self.trDidReadSecSrc);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidReadSesAdd_clicked(self):
        if(self.trDidReadSesSrc.currentItem()):
            self.curobj.sessionRefList.append(self.trDidReadSesSrc.currentItem().text(0));
            self.moveTreeItem(self.trDidReadSesSrc, self.trDidReadSesDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidReadSesDel_clicked(self):
        if(self.trDidReadSesDst.currentItem()):
            self.curobj.sessionRefList.remove(self.trDidReadSesDst.currentItem().text(0));
            self.moveTreeItem(self.trDidReadSesDst, self.trDidReadSesSrc);
            self.fileInd(False);
# ==================== Did Info Write Access =========================
    @pyqtSignature("QString")
    def on_leDidWriteName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidWriteSecAdd_clicked(self):
        if(self.trDidWriteSecSrc.currentItem()):
            self.curobj.securityRefList.append(self.trDidWriteSecSrc.currentItem().text(0));
            self.moveTreeItem(self.trDidWriteSecSrc, self.trDidWriteSecDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidWriteSecDel_clicked(self):
        if(self.trDidWriteSecDst.currentItem()):
            self.curobj.securityRefList.remove(self.trDidWriteSecDst.currentItem().text(0));
            self.moveTreeItem(self.trDidWriteSecDst, self.trDidWriteSecSrc);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidWriteSesAdd_clicked(self):
        if(self.trDidWriteSesSrc.currentItem()):
            self.curobj.sessionRefList.append(self.trDidWriteSesSrc.currentItem().text(0));
            self.moveTreeItem(self.trDidWriteSesSrc, self.trDidWriteSesDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnDidWriteSesDel_clicked(self):
        if(self.trDidWriteSesDst.currentItem()):
            self.curobj.sessionRefList.remove(self.trDidWriteSesDst.currentItem().text(0));
            self.moveTreeItem(self.trDidWriteSesDst, self.trDidWriteSesSrc);
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
#======================= Request Service ==========================
    @pyqtSignature("QString")
    def on_leRequestServiceName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_leRequestServiceStart_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.start!=p0):
                self.curobj.start=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_leRequestServiceStop_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.stop!=p0):
                self.curobj.stop=p0;
                self.fileInd(False);
# ================================= Security Level ==============================
    @pyqtSignature("QString")
    def on_leSecurityLevelName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxSecurityLevel_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.level!=p0):
                self.curobj.level=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxSecurityLevelRecordSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.recordSize!=p0):
                self.curobj.recordSize=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxSecurityLevelSeedSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.seedSize!=p0):
                self.curobj.seedSize=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxSecurityLevelKeySize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.keySize!=p0):
                self.curobj.keySize=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_leSecurityLevelGetSeedCbk_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.getSeedCbk!=p0):
                self.curobj.getSeedCbk=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_leSecurityLevelCopmKeyCbk_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.compKeyCbk!=p0):
                self.curobj.compKeyCbk=p0;
                self.fileInd(False);
# ================================= Service Table ==============================
    @pyqtSignature("QString")
    def on_leServiceTableName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
#================================= Service =====================
    @pyqtSignature("QString")
    def on_leServiceName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxServiceID_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.serviceId!=p0):
                self.curobj.serviceId=p0;
                self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxSubfuncAvail_clicked(self, checked):
        if(self.curobj!=None):
            if(self.curobj.subfuncAvail!=checked):
                self.curobj.subfuncAvail=checked
                self.fileInd(False);
    @pyqtSignature("")
    def on_btnServiceSecAdd_clicked(self):
        if(self.trServiceSecSrc.currentItem()):
            self.curobj.securityRefList.append(self.trServiceSecSrc.currentItem().text(0));
            self.moveTreeItem(self.trServiceSecSrc, self.trServiceSecDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnServiceSecDel_clicked(self):
        if(self.trServiceSecDst.currentItem()):
            self.curobj.securityRefList.remove(self.trServiceSecDst.currentItem().text(0));
            self.moveTreeItem(self.trServiceSecDst, self.trServiceSecSrc);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnServiceSesAdd_clicked(self):
        if(self.trServiceSesSrc.currentItem()):
            self.curobj.sessionRefList.append(self.trServiceSesSrc.currentItem().text(0));
            self.moveTreeItem(self.trServiceSesSrc, self.trServiceSesDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnServiceSesDel_clicked(self):
        if(self.trServiceSesDst.currentItem()):
            self.curobj.sessionRefList.remove(self.trServiceSesDst.currentItem().text(0));
            self.moveTreeItem(self.trServiceSesDst, self.trServiceSesSrc);
            self.fileInd(False);
#====================== session control ================
    @pyqtSignature("QString")
    def on_leSessionControlName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_leGetSesChgPermission_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.GetSesChgPermission!=p0):
                self.curobj.GetSesChgPermission=p0;
                self.fileInd(False);
#====================== session =======================
    @pyqtSignature("QString")
    def on_leSessionName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
#====================== Timing ===========================
    @pyqtSignature("QString")
    def on_leTimingName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxP2ServerMax_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.P2ServerMax!=p0):
                self.curobj.P2ServerMax=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxP2ServerMin_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.P2ServerMin!=p0):
                self.curobj.P2ServerMin=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxS3Server_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.S3Server!=p0):
                self.curobj.S3Server=p0;
                self.fileInd(False);
