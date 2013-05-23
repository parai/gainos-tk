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
from gainos_tk_canif_cfg import *
from Ui_cd_canif import Ui_cd_canif
from cd_add import *
class cd_canif(QDialog, Ui_cd_canif):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, depinfo, parent = None):
        """
        depinfo[] is an arrray,
        depinfo[0]<--->Can Ctrl List Info
        depinfo[1]<--->EcuC Pdu List Info
        """
        self.cfg=cfg;
        self.depinfo=depinfo;
        self.curobj=None;
        self.curtree=None;
        self.fileInd = fileInd;
        QDialog.__init__(self, parent);
        self.setupUi(self);
        self.setWindowTitle(title);
        self.initGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnAdd2.setDisabled(True);
        self.btnDel.setDisabled(True);

    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 5):
            self.tabCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 5):
            if(i==index):
                self.tabCfg.setTabEnabled(i, True);
                self.tabCfg.setCurrentIndex(i);
            else:
                self.tabCfg.setTabEnabled(i, False); 

    def reloadTreeGui(self):
        tree=self.trCanIfCfg.topLevelItem(0);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.channelList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
            for hoh in obj.hthList+obj.hrhList:
                item2=QTreeWidgetItem(item,QStringList(hoh.name));
                item.addChild(item2);
                for pdu in hoh.pduList:
                    item3=QTreeWidgetItem(item2,QStringList(pdu.name));
                    item2.addChild(item3);
    
    def initTab(self):
        self.disableAllTab();
        #pdu名称不能修改
        self.leTxPduName.setDisabled(True);
        self.leRxPduName.setDisabled(True);
        self.leRxPduUserIndication.setDisabled(True);
        #初始化控件范围
        self.spbxTxPduCanId.setRange(0, 0x1FFFFFFF);
        self.spbxRxPduCanId.setRange(0, 0x1FFFFFFF);
        self.spbxTxPduDlc.setRange(0, 8);
        self.spbxRxPduDlc.setRange(0, 8);
        #禁止不被支持的控件
        self.cbxRuntimePduCfg.setDisabled(True);
        self.cmbxTxPduCanType.setDisabled(True);
        self.cmbxRxPduCanType.setDisabled(True);
        #self.cmbxTxPduCanIdType.setDisabled(True);
        self.spbxTxPduDlc.setDisabled(True);

    def initGui(self):
        #Init General 
        self.cbxDevErr.setChecked(self.cfg.General.DevErrorDetection);
        self.cbxVersionInfo.setChecked(self.cfg.General.VersionInfoApi);
        self.cbxDlcCheck.setChecked(self.cfg.General.DlcCheck);
        self.cbxRuntimePduCfg.setChecked(self.cfg.General.RuntimePduConfig);
        self.leBusoffNf.setText(self.cfg.General.BusoffNotification);
        self.leErrorNf.setText(self.cfg.General.ErrorNotification);
        self.cmbxSoftwareFilterType.setDisabled(True);
        #Init Button and Tab
        self.initButton();
        self.initTab();
        #Init Tree
        self.reloadTreeGui();  

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Channels'):
            self.btnAdd.setText('Add Channel');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='Channels'):
            self.btnAdd.setText('Add Hth');
            self.btnAdd2.setText('Add Hrh');
            self.btnDel.setText('Del Channel');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(False);            
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='Channels'):
            self.btnAdd.setText('Add Pdu');
            self.btnDel.setText('Del Hoh');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().parent().text(0)=='Channels'):
            self.btnDel.setText('Del Pdu');
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
    
    def delObj(self, list):
        list.remove(self.curobj);
        del self.curobj

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def refreshChannelTab(self, name):
        obj = self.findObj(self.cfg.channelList, name);
        if(obj == None):
            return;
        self.curobj=obj;
        self.cmbxCanHwCtrl.clear();
        for ctrl in self.depinfo[0].cfg.CanCtrlList:
            self.cmbxCanHwCtrl.addItem(ctrl.name);
        self.leChannelName.setText(obj.name);
        self.cmbxCanHwCtrl.setCurrentIndex(self.cmbxCanHwCtrl.findText(obj.canHwCtrl));
        self.enableTab(0);
    
    def refreshHthTab(self, obj):
        self.curobj=obj;
        self.leHthName.setText(obj.name);
        self.cmbxHthType.setCurrentIndex(self.cmbxHthType.findText(obj.hohType));
        self.cmbxHthIdSymRef.clear();
        self.enableTab(1);
        #关联hth
        channel=self.findObj(self.cfg.channelList, self.curtree.parent().text(0));
        ctrl=self.findObj(self.depinfo[0].cfg.CanCtrlList, channel.canHwCtrl);
        if(ctrl==None):
            return;
        for hoh in ctrl.hohList:
            if(hoh.objType=='CAN_OBJECT_TYPE_TRANSMIT'):
                self.cmbxHthIdSymRef.addItem(hoh.name);
        self.cmbxHthIdSymRef.setCurrentIndex(self.cmbxHthIdSymRef.findText(obj.hohIdSymRef));
        
    
    def refreshHrhTab(self, obj):
        self.curobj=obj;
        self.leHrhName.setText(obj.name);
        self.cmbxHrhType.setCurrentIndex(self.cmbxHrhType.findText(obj.hohType));
        self.cbxSoftwareFilterHrh.setChecked(obj.softwareFilter);
        self.cmbxHrhIdSymRef.clear();
        self.enableTab(2);
        #关联hrh
        channel=self.findObj(self.cfg.channelList, self.curtree.parent().text(0));
        ctrl=self.findObj(self.depinfo[0].cfg.CanCtrlList, channel.canHwCtrl);
        if(ctrl==None):
            return;
        for hoh in ctrl.hohList:
            if(hoh.objType=='CAN_OBJECT_TYPE_RECEIVE'):
                self.cmbxHrhIdSymRef.addItem(hoh.name);
        self.cmbxHrhIdSymRef.setCurrentIndex(self.cmbxHrhIdSymRef.findText(obj.hohIdSymRef));
    
    def refreshHohTab(self, name):
        channel=self.findObj(self.cfg.channelList, self.curtree.parent().text(0));
        #搜索hohList
        obj = self.findObj(channel.hthList+channel.hrhList, name);
        if(obj==None):
            #搜索失败，直接返回
            return;
        if(obj.type=='hth'):
            self.refreshHthTab(obj);
        elif(obj.type=='hrh'):
            self.refreshHrhTab(obj);

    def refreshRxPduTab(self, obj):
        self.curobj=obj;
        self.leRxPduName.setText(obj.name[3:]);
        self.leRxPduIdMask.setText(obj.canIdMask);
        self.cmbxRxPduCanType.setCurrentIndex(self.cmbxRxPduCanType.findText(obj.canType));
        self.spbxRxPduCanId.setValue(obj.canId);
        self.cmbxRxPduCanIdType.setCurrentIndex(self.cmbxRxPduCanIdType.findText(obj.canIdType));
        self.spbxRxPduDlc.setValue(obj.dlc);
        self.cmbxRxPduIndication.setCurrentIndex(self.cmbxRxPduIndication.findText(obj.indicationType));
        if(obj.indicationType=='CAN_SPECIAL'):
            self.leRxPduUserIndication.setText('CanIf_UserRxIndication');
        else:
            self.leRxPduUserIndication.setText('');
        self.enableTab(4);

    def refreshTxPduTab(self, obj):
        self.curobj=obj;
        self.leTxPduName.setText(obj.name[3:]);
        self.cmbxTxPduCanType.setCurrentIndex(self.cmbxTxPduCanType.findText(obj.canType));
        self.spbxTxPduCanId.setValue(obj.canId);
        self.cmbxTxPduCanIdType.setCurrentIndex(self.cmbxTxPduCanIdType.findText(obj.canIdType));
        self.spbxTxPduDlc.setValue(obj.dlc);
        self.cmbxTxPduConfirmation.setCurrentIndex(self.cmbxTxPduConfirmation.findText(obj.confirmation));
        self.enableTab(3);

    def refreshPduTab(self, name):
        channel=self.findObj(self.cfg.channelList, self.curtree.parent().parent().text(0));
        hoh=self.findObj(channel.hrhList+channel.hthList, self.curtree.parent().text(0))
        #首先搜索hthList
        obj = self.findObj(hoh.pduList, name);
        if(obj==None):
            #搜索失败，直接返回
            return;
        if(obj.type=='rxPdu'):
            self.refreshRxPduTab(obj);
        elif(obj.type=='txPdu'):
            self.refreshTxPduTab(obj);
    
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Channels'):
            self.refreshChannelTab(objname);
        elif(self.curtree.parent().parent().text(0)=='Channels'):
            self.refreshHohTab(objname);
        elif(self.curtree.parent().parent().parent().text(0)=='Channels'):
            self.refreshPduTab(objname);

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trCanIfCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    def addChannel(self):
        id = len(self.cfg.channelList);
        name='vCanIf_Channel%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfChannel(name);
        self.cfg.channelList.append(obj);

    def addHth(self):
        id = len(self.curobj.hthList);
        name='vCanIf_Hth%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfHth(name);
        self.curobj.hthList.append(obj);

    def addHrh(self):
        id = len(self.curobj.hrhList);
        name='vCanIf_Hrh%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=CanIfHrh(name);
        self.curobj.hrhList.append(obj);

    def isPduAlreadyAdded(self, pduname, typeofhoh):
        if(typeofhoh=='hth'):
            #搜索所有Rx Pdu
            for channel in self.cfg.channelList:
                for hth in channel.hthList:
                    for pdu in hth.pduList:
                        print pdu.name[3:], pduname;
                        if(pdu.name[3:]==pduname):
                            return True;
        elif(typeofhoh=='hrh'):
            #搜索所有Tx Pdu
            for channel in self.cfg.channelList:
                for hrh in channel.hrhList:
                    for pdu in hrh.pduList:
                        print pdu.name[3:], pduname;
                        if(pdu.name[3:]==pduname):
                            return True;
        return False;

    def addPdu(self):
        from cd_add import cd_add
        list=[];
        for pdu in self.depinfo[1].cfg.pduList:
            if(self.isPduAlreadyAdded(pdu.name, self.curobj.type)==False):
                list.append(pdu.name);
        dlg=cd_add('Select The Pdu', list);
        dlg.exec_();
        if(dlg.result==True):
            name=dlg.item;
        else:
            return;
        if(self.curobj.type=='hth'):
            name='TX_'+name;
        elif(self.curobj.type=='hrh'):
            name='RX_'+name;
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        if(self.curobj.type=='hth'):
            obj=CanIfTxPdu(name);
        elif(self.curobj.type=='hrh'):
            obj=CanIfRxPdu(name);
        self.curobj.pduList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Channel'):
            self.addChannel();
        elif(text=='Add Hth'):
            self.addHth();
        elif(text=='Add Pdu'):
            self.addPdu();
        self.fileInd(False);

    @pyqtSignature("")
    def on_btnAdd2_clicked(self):
        text=self.btnAdd2.text();
        if(text=='Add Hrh'):
            self.addHrh();
        self.fileInd(False);
    
    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Del Channel'):
            self.delObj(self.cfg.channelList);
        elif(text=='Del Hoh'):
            channel=self.findObj(self.cfg.channelList, parent.text(0));
            if(self.curobj.type=='hth'):
                self.delObj(channel.hthList);
            elif(self.curobj.type=='hrh'):
                self.delObj(channel.hrhList);
        elif(text=='Del Pdu'):
            channel=self.findObj(self.cfg.channelList, parent.parent().text(0));
            hoh=self.findObj(channel.hthList+channel.hrhList, parent.text(0));
            self.delObj(hoh.pduList);
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trCanIfCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trCanIfCfg_itemClicked(parent, 0);
        self.fileInd(False);


    @pyqtSignature("QString")
    def on_cmbxCanHwCtrl_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.canHwCtrl!=p0):
                self.curobj.canHwCtrl=p0;
                self.fileInd(False);

   
    @pyqtSignature("bool")
    def on_cbxSoftwareFilterHrh_clicked(self, checked):
        if(self.curobj!=None):
            self.curobj.softwareFilter=checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        self.cfg.General.DevErrorDetection=checked;
        self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxVersionInfo_clicked(self, checked):
        self.cfg.General.VersionInfoApi=checked;
        self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxDlcCheck_clicked(self, checked):
        self.cfg.General.DlcCheck=checked;
        self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxRuntimePduCfg_clicked(self, checked):
        self.cfg.General.RuntimePduConfig=checked;
        self.fileInd(False);

    @pyqtSignature("QString")
    def on_leBusoffNf_textChanged(self, p0):
        self.cfg.General.BusoffNotification=p0;
        self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leErrorNf_textChanged(self, p0):
        self.cfg.General.ErrorNotification=p0;
        self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxSoftwareFilterType_activated(self, p0):
        #not supported
        return;
    
    @pyqtSignature("QString")
    def on_cmbxHrhType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.hohType=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxHrhIdSymRef_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.hohIdSymRef=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leChannelName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
            self.fileInd(False);
            
    
    @pyqtSignature("QString")
    def on_cmbxHthType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.hohType=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxHthIdSymRef_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.hohIdSymRef=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leHrhName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leHthName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
            self.fileInd(False);

    
    @pyqtSignature("QString")
    def on_leTxPduName_textChanged(self, p0):
        return;
    
    @pyqtSignature("QString")
    def on_cmbxTxPduCanType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.canType=p0;
            self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxTxPduCanId_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.canId=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxTxPduCanIdType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.canIdType=p0;
            self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxTxPduDlc_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.dlc=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxTxPduConfirmation_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.confirmation=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leRxPduName_textChanged(self, p0):
        return;
    
    @pyqtSignature("QString")
    def on_cmbxRxPduCanType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.canType=p0;
            self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxRxPduCanId_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.canId=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxRxPduCanIdType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.canIdType=p0;
            self.fileInd(False);
 
    @pyqtSignature("QString")
    def on_leRxPduIdMask_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.canIdMask=p0;
            self.fileInd(False);

    @pyqtSignature("int")
    def on_spbxRxPduDlc_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.dlc=p0;
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxRxPduIndication_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.indicationType=p0;
            if(p0=='CAN_SPECIAL'):
                self.leRxPduUserIndication.setText(self.curobj.userIndication);
            else:
                self.leRxPduUserIndication.setText('');
            self.fileInd(False);
