# -*- coding: utf-8 -*-

"""
Module implementing cd_cannm.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString

from gainos_tk_cannm_cfg import *

from Ui_cd_cannm import Ui_cd_cannm

class cd_cannm(QDialog, Ui_cd_cannm):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, depinfo, parent = None):
        """
        depinfo[0] == EcuC.cfg
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title)
        self.cfg = cfg
        self.fileInd = fileInd
        self.initGui()
        self.curtree = None;
        self.curobj = None;
        self.depinfo = depinfo;
    
    def initGui(self):
        self.reloadTreeGui();
        self.disableAllTab();
        self.btn1.setDisabled(True);
        #init General
        self.cbxDevErr.setChecked(self.cfg.general.DevError)
        self.cbxVersionInfoApi.setChecked(self.cfg.general.VersionInfo)
        self.cbxPassiveModeEn.setChecked(self.cfg.general.PassiveModeEn)
        
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
    
    def reloadTreeGui(self):
        tree=self.trCanNmCfg.topLevelItem(0);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.channelList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Channels'):
            self.btn1.setText('Add Channel');
            self.btn1.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Channels'):
            self.btn1.setText('Del Channel');
            self.btn1.setDisabled(False);
    def refreshChannelTab(self, name):
        obj=gcfindObj(self.cfg.channelList, name);
        if(obj==None):
            return;
        self.curobj=obj;
        self.leChanneName.setText(obj.name);
        self.spbxMainFncPeriod.setValue(obj.MainFunctionPeriod);
        self.leNodeId.setText(obj.NodeId)
        self.cmbxTxPdu.clear();
        self.cmbxRxPdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxTxPdu.addItem('TX_'+pdu.name)
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxRxPdu.addItem('RX_'+pdu.name)
        self.cmbxNmChannel.setCurrentIndex(self.cmbxNmChannel.findText(obj.NmNetworkHandle))
        self.cbxChlActive.setChecked(obj.Active)
        self.spbxRepeatMessageTime.setValue(obj.RepeatMessageTime)
        self.spbxPrepareBusSleepTime.setValue(obj.WaitBusSleepTime)
        self.spbxTimeoutTime.setValue(obj.TimeoutTime)
        self.cmbxTxPdu.setCurrentIndex(self.cmbxTxPdu.findText(obj.CanIfPduId))
        self.cmbxRxPdu.setCurrentIndex(self.cmbxRxPdu.findText(obj.RxPduId))
        self.spbxTxCycleTime.setValue(obj.MessageCycleTime)
        self.spbxTxCycleTimeOffset.setValue(obj.MessageCycleOffsetTime)
        self.cmbxCBVPosition.setCurrentIndex(self.cmbxCBVPosition.findText(obj.CbvPosition))
        self.cmbxNodeIdPosition.setCurrentIndex(self.cmbxCBVPosition.findText(obj.NidPosition))
        self.spbxPduLength.setValue(obj.PduLength);
        self.enableTab(0);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Channels'):
            self.refreshChannelTab(objname);

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trCanNmCfg_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        self.refreshTab();
    #------------------ General -----------------
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        if(self.cfg.general.DevError != checked):
            self.cfg.general.DevError = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxVersionInfoApi_clicked(self, checked):
        if(self.cfg.general.VersionInfo != checked):
            self.cfg.general.VersionInfo = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxPassiveModeEn_clicked(self, checked):
        if(self.cfg.general.PassiveModeEn != checked):
            self.cfg.general.PassiveModeEn = checked;
            self.fileInd(False);
    #------------------- Channel ------------------------
    @pyqtSignature("QString")
    def on_cmbxTxPdu_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.CanIfPduId != p0):
                self.curobj.CanIfPduId = p0;
                self.fileInd(False)
    
    @pyqtSignature("QString")
    def on_cmbxRxPdu_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.RxPduId != p0):
                self.curobj.RxPduId = p0;
                self.fileInd(False)
    
    @pyqtSignature("int")
    def on_spbxTxCycleTime_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.MessageCycleTime != p0):
                self.curobj.MessageCycleTime = p0;
                self.fileInd(False)
    
    @pyqtSignature("int")
    def on_spbxTxCycleTimeOffset_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.MessageCycleOffsetTime != p0):
                self.curobj.MessageCycleOffsetTime = p0;
                self.fileInd(False)
    
    @pyqtSignature("QString")
    def on_cmbxCBVPosition_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.CbvPosition != p0):
                self.curobj.CbvPosition = p0;
                self.fileInd(False)
    
    @pyqtSignature("QString")
    def on_cmbxNodeIdPosition_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.NidPosition != p0):
                self.curobj.NidPosition = p0;
                self.fileInd(False)
    
    @pyqtSignature("int")
    def on_spbxPduLength_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.PduLength != p0):
                self.curobj.PduLength = p0;
                self.fileInd(False)
    
    @pyqtSignature("bool")
    def on_cbxChlActive_clicked(self, checked):
        if(self.curobj != None):
            if(self.curobj.Active != p0):
                self.curobj.Active = p0;
                self.fileInd(False)
    
    @pyqtSignature("int")
    def on_spbxRepeatMessageTime_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.RepeatMessageTime != p0):
                self.curobj.RepeatMessageTime = p0;
                self.fileInd(False)
    
    @pyqtSignature("int")
    def on_spbxPrepareBusSleepTime_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.WaitBusSleepTime != p0):
                self.curobj.WaitBusSleepTime = p0;
                self.fileInd(False)
    
    @pyqtSignature("int")
    def on_spbxTimeoutTime_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.TimeoutTime != p0):
                self.curobj.TimeoutTime = p0;
                self.fileInd(False)
    
    @pyqtSignature("QString")
    def on_leChanneName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxMainFncPeriod_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.MainFunctionPeriod != p0):
                self.curobj.MainFunctionPeriod = p0;
                self.fileInd(False)
    
    @pyqtSignature("QString")
    def on_leNodeId_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.NodeId != p0):
                self.curobj.NodeId = p0;
                self.fileInd(False)
    
    @pyqtSignature("QString")
    def on_cmbxNetworkHandle_activated(self, p0):
        return
    
    @pyqtSignature("QString")
    def on_cmbxNmChannel_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.NmNetworkHandle != p0):
                self.curobj.NmNetworkHandle = p0;
                self.fileInd(False)
    
    def addChannel(self):
        id = len(self.cfg.channelList);
        name='vCanNm_Channel%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanNmChannel(name);
        self.cfg.channelList.append(obj);
    def delObj(self, text):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        if(text=='Del Channel'):
            self.cfg.channelList.remove(self.curobj);
        del self.curtree;
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trCanNmCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trCanNmCfg_itemClicked(parent, 0);
    @pyqtSignature("")
    def on_btn1_clicked(self):
        text = self.btn1.text()
        if(text == 'Add Channel'):
            self.addChannel();
        elif(text == 'Del Channel'):
            self.delObj(text);
        self.fileInd(False);
