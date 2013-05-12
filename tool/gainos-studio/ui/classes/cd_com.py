# -*- coding: utf-8 -*-

"""
Module implementing Com_Dlg.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString
from Ui_Com_Dlg import Ui_Com_Dlg
from ComCfg import *

class Com_Dlg(QDialog, Ui_Com_Dlg):
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
        self.depinfo = depinfo;
        self.curobj=None;
        self.curtree=None;       
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.initGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnAdd2.setDisabled(True);
        self.btnDel.setDisabled(True);

    def reloadTreeGui0(self, trindex, list):
        tree=self.trComCfg.topLevelItem(trindex);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);

    def reloadTreeGui1(self):
        """加载IPDU"""
        tree=self.trComCfg.topLevelItem(1);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for Ipdu in self.cfg.IPduList:
            item=QTreeWidgetItem(tree,QStringList(Ipdu.name));
            tree.addChild(item);
            for sig in Ipdu.signalList:
                item2=QTreeWidgetItem(item,QStringList(sig.name));
                item.addChild(item2);
            for sig in Ipdu.signalGroupList:
                item2=QTreeWidgetItem(item,QStringList(sig.name));
                item.addChild(item2);
                for grpsig in sig.groupSignalList:
                    item3=QTreeWidgetItem(item2,QStringList(grpsig.name));
                    item2.addChild(item3); 

    def reloadTreeGui(self):
        self.reloadTreeGui0(0, self.cfg.IPduGroupList);
        self.reloadTreeGui1();

    def initGui(self):
        self.reloadTreeGui();
        self.initButton();
        #init General
        self.cbxDevErr.setChecked(self.cfg.General.DevErrorDetection);
        #init Tab
        self.initTab();

    def initTab(self):
        self.disableAllTab();
        #init spinbox range
        self.spbxMinDelayFactor.setRange(0, 65535);
        self.spbxDefaultValueForUnusedAreas.setRange(0, 0xFF);
        self.spbxNumberOfRepetitions.setRange(0, 0xFF);
        self.spbxTimeOffsetFactor.setRange(0, 65535);
        self.spbxTimePeriodFactor.setRange(0, 65535);
        self.spbxSignalPosition.setRange(0, 63);
        self.spbxSignalLSBPosition.setRange(0, 2031);
        self.spbxSignalLSBPosition.setDisabled(True);
        self.spbxSignalSize.setRange(0, 64);
        self.spbxSignalUpdateBitPosition.setRange(0, 63);
        self.spbxSignalTimeoutFactor.setRange(0, 65535);
        self.spbxSignalFirstTimeout.setRange(0, 65535);
        self.spbxSignalGrpPosition.setRange(0, 63);
        self.spbxSignalGrpSize.setRange(0, 64);
        self.spbxSignalGrpUpdateBitPosition.setRange(0, 2031);
        self.spbxSignalGrpTimeoutFactor.setRange(0, 65535);
        self.spbxGrpSignalPosition.setRange(0, 64);
        self.spbxGrpSignalLSBPosition.setRange(0, 2031);
        self.spbxGrpSignalLSBPosition.setDisabled(True);
        self.spbxGrpSignalSize.setRange(0, 64);
        #init IPDU
        self.cmbxGblPdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxGblPdu.addItem('TX_'+pdu.name);
            self.cmbxGblPdu.addItem('RX_'+pdu.name);

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

    def delObj(self, list):
        list.remove(self.curobj);
        del self.curobj

    def findObj(self, list, name):
        for obj in list:
            if(name==obj.name):
                return obj;
        return None;

    def addPduGroup(self):
        id = len(self.cfg.IPduGroupList);
        name='vCom_IPduGrp%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComIPduGroup(name);
        self.cfg.IPduGroupList.append(obj);

    def addIPdu(self):
        id = len(self.cfg.IPduList);
        name='vCom_IPdu%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComIPdu(name);
        self.cfg.IPduList.append(obj);

    def addSignal(self):
        if(self.curobj == None):
            return;
        id = len(self.curobj.signalList);
        name='%s_Signal%s'%(self.curobj.name, id);
        item=QTreeWidgetItem(None,QStringList(name));
        self.curtree.insertChild(id, item);
        self.curtree.setExpanded(True);
        obj=ComSignal(name);
        self.curobj.signalList.append(obj);

    def addSignalGroup(self):
        if(self.curobj == None):
            return;
        id = len(self.curobj.signalGroupList);
        name='%s_SigGrp%s'%(self.curobj.name, id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComSignalGroup(name);
        self.curobj.signalGroupList.append(obj);

    def addGroupSignal(self):
        if(self.curobj == None):
            return;
        id = len(self.curobj.groupSignalList);
        name='%s_Signal%s'%(self.curobj.name, id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComGroupSignal(name);
        self.curobj.groupSignalList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text = self.btnAdd.text();
        if(text == 'Add Pdu Group'):
            self.addPduGroup();
        elif(text == 'Add IPdu'):
            self.addIPdu();
        elif(text == 'Add Signal'):
            self.addSignal();
        elif(text == 'Add Group Signal'):
            self.addGroupSignal();

    @pyqtSignature("")
    def on_btnAdd2_clicked(self):
        text = self.btnAdd2.text();
        if(text == 'Add Signal Group'):
            self.addSignalGroup();

    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text == 'Del Pdu Group'):
            self.delObj(self.cfg.IPduGroupList);
        elif(text == 'Del IPdu'):
            self.delObj(self.cfg.IPduList);
        elif(text == 'Del Signal'):
            pname = parent.text(0);
            Ipdu = self.findObj(self.cfg.IPduList, pname);
            self.delObj(Ipdu.signalList);
        elif(text == 'Del Group Signal'):
            ppname = parent.parent().text(0);
            pname = parent.text(0);
            Ipdu = self.findObj(self.cfg.IPduList, ppname);
            sig = self.findObj(Ipdu.signalGroupList, pname);
            self.delObj(sig.groupSignalList);
        elif(text == 'Del Signal Group'):
            pname = parent.text(0);
            Ipdu = self.findObj(self.cfg.IPduList, pname);
            self.delObj(Ipdu.signalGroupList);
        #reselect a tree item,software trigger on_trComCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trComCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trComCfg_itemClicked(parent, 0);

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Pdu Group'):
            self.btnAdd.setText('Add Pdu Group');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        elif(trname=='Pdus'):
            self.btnAdd.setText('Add IPdu');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='Pdus'):
            self.btnAdd.setText('Add Signal');
            self.btnAdd2.setText('Add Signal Group');
            self.btnDel.setText('Del IPdu');
            self.btnAdd.setDisabled(False);
            self.btnAdd2.setDisabled(False);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Pdu Group'):
            self.btnDel.setText('Del Pdu Group');
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='Pdus'):
            pname = self.curtree.parent().text(0);
            name = self.curtree.text(0);
            Ipdu = self.findObj(self.cfg.IPduList, pname);
            sig = self.findObj(Ipdu.signalList+Ipdu.signalGroupList, name);
            if(sig.isSignalGroup==False):#if it is a general signal
                self.btnDel.setText('Del Signal');
                self.btnAdd.setDisabled(True);
                self.btnAdd2.setDisabled(True);
                self.btnDel.setDisabled(False);
            else:#if it is a signal group
                self.btnAdd.setText('Add Group Signal');
                self.btnDel.setText('Del Signal Group');
                self.btnAdd.setDisabled(False);
                self.btnAdd2.setDisabled(True);
                self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().parent().text(0)=='Pdus'):
            self.btnDel.setText('Del Group Signal');
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(False);
        else:
            self.btnAdd.setDisabled(True);
            self.btnAdd2.setDisabled(True);
            self.btnDel.setDisabled(True);

    def refreshPduGroupTab(self, name):
        self.curobj= obj = self.findObj(self.cfg.IPduGroupList, name);
        if(obj == None):
            return;
        self.lePduGrpName.setText(obj.name);
        self.enableTab(0);

    def disableIPduTxOption(self, disable):
        self.spbxMinDelayFactor.setDisabled(disable);
        self.spbxDefaultValueForUnusedAreas.setDisabled(disable);
        self.cmbxPduTxMode.setDisabled(disable);
        self.spbxNumberOfRepetitions.setDisabled(disable);
        self.spbxRepetitionPeriodFactor.setDisabled(disable);
        self.spbxTimeOffsetFactor.setDisabled(disable);
        self.spbxTimePeriodFactor.setDisabled(disable);
        #rx processing
        self.cmbxPduSignalProcessing.setDisabled(not disable);

    def disenIPuTxOption(self, mode):
        """和cmbxPduTxMode相关联控件的使能和禁止操作"""
        if(mode == 'DIRECT'):
            self.spbxNumberOfRepetitions.setDisabled(False);
            self.spbxRepetitionPeriodFactor.setDisabled(False);
            self.spbxTimeOffsetFactor.setDisabled(True);
            self.spbxTimePeriodFactor.setDisabled(True);
        elif(mode == 'MIXED'):
            self.spbxNumberOfRepetitions.setDisabled(False);
            self.spbxRepetitionPeriodFactor.setDisabled(False);
            self.spbxTimeOffsetFactor.setDisabled(False);
            self.spbxTimePeriodFactor.setDisabled(True);
        elif(mode == 'NONE'):
            self.spbxNumberOfRepetitions.setDisabled(True);
            self.spbxRepetitionPeriodFactor.setDisabled(True);
            self.spbxTimeOffsetFactor.setDisabled(True);
            self.spbxTimePeriodFactor.setDisabled(True);
        elif(mode == 'PERIODIC'):
            self.spbxNumberOfRepetitions.setDisabled(True);
            self.spbxRepetitionPeriodFactor.setDisabled(True);
            self.spbxTimeOffsetFactor.setDisabled(False);
            self.spbxTimePeriodFactor.setDisabled(False);
        

    def refreshIPduTab(self, name):
        self.curobj= obj = self.findObj(self.cfg.IPduList, name);
        if(obj == None):
            return;
        self.leIPduName.setText(obj.name);
        self.cmbxGblPdu.setCurrentIndex(self.cmbxGblPdu.findText(self.curobj.ArcIPduOutgoingId));
        self.cmbxPduDirection.setCurrentIndex(self.cmbxPduDirection.findText(self.curobj.ComIPduDirection));
        self.cmbxPduGrp.clear();
        for obj in self.cfg.IPduGroupList:
            self.cmbxPduGrp.addItem(obj.name);
        self.cmbxPduGrp.setCurrentIndex(self.cmbxPduGrp.findText(self.curobj.ComIPduGroupRef));
        self.lePduCallout.setText(self.curobj.ComIPduCallout);
        if(self.curobj.ComIPduDirection == 'RECEIVE'):
            self.disableIPduTxOption(True);
        elif(self.curobj.ComIPduDirection == 'SEND'):
            self.disableIPduTxOption(False);
            self.disenIPuTxOption(self.curobj.ComTxModeMode);
        self.cmbxPduSignalProcessing.setCurrentIndex(self.cmbxPduSignalProcessing.findText(self.curobj.ComIPduSignalProcessing));
        self.spbxMinDelayFactor.setValue(self.curobj.ComTxIPduMinimumDelayFactor);
        self.spbxDefaultValueForUnusedAreas.setValue(self.curobj.ComTxIPduUnusedAreasDefault);
        self.spbxNumberOfRepetitions.setValue(self.curobj.ComTxModeNumberOfRepetitions);
        self.spbxRepetitionPeriodFactor.setValue(self.curobj.ComTxModeRepetitionPeriodFactor);
        self.spbxTimeOffsetFactor.setValue(self.curobj.ComTxModeTimeOffsetFactor);
        self.spbxTimePeriodFactor.setValue(self.curobj.ComTxModeTimePeriodFactor);
        self.cmbxPduTxMode.setCurrentIndex(self.cmbxPduTxMode.findText(self.curobj.ComTxModeMode));
        self.enableTab(1);

    def refreshGeneralSignalTab(self, sig):
        self.curobj = sig;
        self.leSignalName.setText(sig.name);
        self.cmbxSignalType.setCurrentIndex(self.cmbxSignalType.findText(self.curobj.ComSignalType));
        self.cmbxSignalEndianess.setCurrentIndex(self.cmbxSignalEndianess.findText(self.curobj.ComSignalEndianess));
        self.cmbxSignalTxProperty.setCurrentIndex(self.cmbxSignalTxProperty.findText(self.curobj.ComTransferProperty));
        self.cbxAutoSysSignalMap.setDisabled(True);
        self.cmbxAutoSysSignalMap.setDisabled(True);
        self.spbxSignalPosition.setValue(self.curobj.ComBitPosition);
        self.spbxSignalSize.setValue(self.curobj.ComBitSize);
        self.leSignalInitValue.setText(self.curobj.ComSignalInitValue);
        self.cbxSignalUpdateBitPosition.setChecked(self.curobj.ComSignalArcUseUpdateBit);
        self.spbxSignalUpdateBitPosition.setDisabled(not self.curobj.ComSignalArcUseUpdateBit);
        self.spbxSignalUpdateBitPosition.setValue(self.curobj.ComUpdateBitPosition);
        self.spbxSignalTimeoutFactor.setValue(self.curobj.ComTimeoutFactor);
        self.spbxSignalFirstTimeout.setValue(self.curobj.ComFirstTimeoutFactor);
        self.cmbxSignalTimeoutAction.setCurrentIndex(self.cmbxSignalTimeoutAction.findText(self.curobj.ComRxDataTimeoutAction));
        self.leSignalNotification.setText(self.curobj.ComNotification);
        self.leSignalNotificationOnTimeout.setText(self.curobj.ComTimeoutNotification);
        self.enableTab(2);

    def refreshSignalGroupTab(self, sig):
        self.curobj = sig;
        self.leSignalGrpName.setText(sig.name);
        self.cmbxSignalGrpTxProperty.setCurrentIndex(self.cmbxSignalGrpTxProperty.findText(sig.ComTransferProperty))
        self.cbxAutoSysSignalGrpMap.setDisabled(True);
        self.cmbxAutoSysSignalGrpMap.setDisabled(True);
        self.spbxSignalGrpPosition.setValue(sig.ComBitPosition);
        self.spbxSignalGrpSize.setValue(sig.ComBitSize);
        self.spbxSignalGrpUpdateBitPosition.setValue(sig.ComUpdateBitPosition);
        self.spbxSignalGrpTimeoutFactor.setValue(sig.ComTimeoutFactor);
        self.spbxSignalGrpFirstTimeout.setValue(sig.ComFirstTimeoutFactor);
        self.leSignalGrpNotification.setText(sig.ComNotification);
        self.leSignalGrpNotificationOnTimeout.setText(sig.ComTimeoutNotification);
        self.cbxSignalGrpUpdateBitPosition.setChecked(sig.ComSignalArcUseUpdateBit);
        self.spbxSignalGrpUpdateBitPosition.setDisabled(not sig.ComSignalArcUseUpdateBit);
        self.enableTab(3);
    
    def refreshSignalTab(self, name):
        pname = self.curtree.parent().text(0);
        Ipdu = self.findObj(self.cfg.IPduList, pname);
        sig = self.findObj(Ipdu.signalGroupList+Ipdu.signalList, name);
        if(sig == None):
            return;
        if(sig.isSignalGroup == True):
            self.refreshSignalGroupTab(sig);
        else:
            self.refreshGeneralSignalTab(sig);

    def refreshGroupSignalTab(self, name):
        ppname = self.curtree.parent().parent().text(0);
        pname = self.curtree.parent().text(0);
        Ipdu = self.findObj(self.cfg.IPduList, ppname);
        sigGrp = self.findObj(Ipdu.signalGroupList, pname);
        self.curobj = sig = self.findObj(sigGrp.groupSignalList,name);
        self.leGrpSignalName.setText(sig.name);
        self.leGrpSignalInitValue.setText(sig.ComSignalInitValue);
        self.cmbxGrpSignalType.setCurrentIndex(self.cmbxGrpSignalType.findText(sig.ComSignalType));
        self.cmbxGrpSignalEndianess.setCurrentIndex(self.cmbxGrpSignalEndianess.findText(sig.ComSignalEndianess));
        self.spbxGrpSignalPosition.setValue(sig.ComBitPosition);
        self.spbxGrpSignalLSBPosition.setDisabled(True);
        self.spbxGrpSignalSize.setValue(sig.ComBitSize);
        self.cbxAutoSysGrpSignalMap.setDisabled(True);
        self.cmbxAutoSysGrpSignalMap.setDisabled(True);
        self.enableTab(4);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Pdu Group'):
            self.refreshPduGroupTab(objname);
        elif(trname  == 'Pdus'):
            self.refreshIPduTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Pdus'):
            self.refreshSignalTab(objname);
        elif(self.curtree.parent().parent().parent().text(0) == 'Pdus'):
            self.refreshGroupSignalTab(objname);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trComCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        self.cfg.General.DevErrorDetection = checked;

######################## For Pdu Group Tab ################################
    @pyqtSignature("QString")
    def on_lePduGrpName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0); 

######################## For General I-Pdu Tab ################################
    @pyqtSignature("QString")
    def on_leIPduName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);  
    
    @pyqtSignature("QString")
    def on_cmbxGblPdu_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ArcIPduOutgoingId=p0;
    
    @pyqtSignature("QString")
    def on_cmbxPduDirection_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComIPduDirection=p0;
            if(p0 == 'RECEIVE'):
                self.disableIPduTxOption(True);
            elif(p0 == 'SEND'):
                self.disableIPduTxOption(False);

    @pyqtSignature("QString")
    def on_cmbxPduGrp_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComIPduGroupRef=p0;

    @pyqtSignature("QString")
    def on_lePduCallout_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComIPduCallout=p0;

    @pyqtSignature("QString")
    def on_cmbxPduSignalProcessing_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComIPduSignalProcessing=p0;

    @pyqtSignature("int")
    def on_spbxMinDelayFactor_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxIPduMinimumDelayFactor=p0;

    @pyqtSignature("int")
    def on_spbxDefaultValueForUnusedAreas_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxIPduUnusedAreasDefault=p0;

    @pyqtSignature("QString")
    def on_cmbxPduTxMode_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxModeMode=p0;
            self.disenIPuTxOption(p0);

    @pyqtSignature("int")
    def on_spbxNumberOfRepetitions_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxModeNumberOfRepetitions=p0;

    @pyqtSignature("int")
    def on_spbxRepetitionPeriodFactor_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxModeRepetitionPeriodFactor=p0;

    @pyqtSignature("int")
    def on_spbxTimeOffsetFactor_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxModeTimeOffsetFactor=p0;

    @pyqtSignature("int")
    def on_spbxTimePeriodFactor_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTxModeTimePeriodFactor=p0;

######################## For General Signal Tab################################ 
    @pyqtSignature("QString")
    def on_leSignalName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
    
    @pyqtSignature("QString")
    def on_cmbxSignalType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComSignalType=p0;

    @pyqtSignature("QString")
    def on_cmbxSignalEndianess_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComSignalEndianess=p0;
    
    @pyqtSignature("QString")
    def on_cmbxSignalTxProperty_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTransferProperty=p0;

    @pyqtSignature("int")
    def on_spbxSignalPosition_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComBitPosition=p0;

    @pyqtSignature("int")
    def on_spbxSignalSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComBitSize=p0;

    @pyqtSignature("bool")
    def on_cbxSignalUpdateBitPosition_clicked(self, checked):
        if(self.curobj!=None):
            self.curobj.ComSignalArcUseUpdateBit=checked;
            self.spbxSignalUpdateBitPosition.setDisabled(not checked);

    @pyqtSignature("int")
    def on_spbxSignalUpdateBitPosition_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComUpdateBitPosition=p0;

    @pyqtSignature("int")
    def on_spbxSignalTimeoutFactor_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTimeoutFactor=p0;

    @pyqtSignature("int")
    def on_spbxSignalFirstTimeout_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComFirstTimeoutFactor=p0;

    @pyqtSignature("QString")
    def on_leSignalInitValue_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComSignalInitValue=p0;

    @pyqtSignature("QString")
    def on_leSignalNotification_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComNotification=p0;

    @pyqtSignature("QString")
    def on_leSignalNotificationOnTimeout_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTimeoutNotification=p0;

    @pyqtSignature("QString")
    def on_cmbxSignalTimeoutAction_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComRxDataTimeoutAction=p0;

######################## For Signal Group Tab ################################
    @pyqtSignature("QString")
    def on_leSignalGrpName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);
    
    @pyqtSignature("QString")
    def on_cmbxSignalGrpTxProperty_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTransferProperty=p0;
    @pyqtSignature("int")
    def on_spbxSignalGrpPosition_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComBitPosition=p0;
    @pyqtSignature("int")
    def on_spbxSignalGrpSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComBitSize=p0;

    @pyqtSignature("bool")
    def on_cbxSignalGrpUpdateBitPosition_clicked(self, checked):
        if(self.curobj!=None):
            self.curobj.ComSignalArcUseUpdateBit=checked;
            self.spbxSignalGrpUpdateBitPosition.setDisabled(not checked);

    @pyqtSignature("int")
    def on_spbxSignalGrpUpdateBitPosition_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComUpdateBitPosition=p0;
    @pyqtSignature("int")
    def on_spbxSignalGrpTimeoutFactor_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTimeoutFactor=p0;
    @pyqtSignature("int")
    def on_spbxSignalGrpFirstTimeout_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComFirstTimeoutFactor=p0;
    @pyqtSignature("QString")
    def on_leSignalGrpNotification_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComNotification=p0;
    @pyqtSignature("QString")
    def on_leSignalGrpNotificationOnTimeout_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComTimeoutNotification=p0;

######################## For Group Signal Tab ################################
    @pyqtSignature("QString")
    def on_leGrpSignalName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);

    @pyqtSignature("QString")
    def on_leGrpSignalInitValue_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComSignalInitValue=p0;
    @pyqtSignature("QString")
    def on_cmbxGrpSignalType_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComSignalType=p0;
    @pyqtSignature("QString")
    def on_cmbxGrpSignalEndianess_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.ComSignalEndianess=p0;
    @pyqtSignature("int")
    def on_spbxGrpSignalPosition_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComBitPosition=p0;

    @pyqtSignature("int")
    def on_spbxGrpSignalSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.ComBitSize=p0;
