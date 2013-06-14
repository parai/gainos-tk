# -*- coding: utf-8 -*-

"""
Module implementing cd_nm.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString

from gainos_tk_nm_cfg import *

from Ui_cd_nm import Ui_cd_nm

class cd_nm(QDialog, Ui_cd_nm):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, depinfo, parent = None):
        """
        depinfo[0] == CanNm
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
        self.cbxNodeDetection.setChecked(self.cfg.general.NodeDetection)
        self.cbxNodeId.setChecked(self.cfg.general.NodeId)
        self.cbxUserData.setChecked(self.cfg.general.UserData)
    
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
        tree=self.trNmCfg.topLevelItem(0);
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
        self.cmbxNmChannel.clear();
        for chl in self.depinfo[0].cfg.channelList:
            self.cmbxNmChannel.addItem(chl.name)
        self.cmbxBusType.setCurrentIndex(self.cmbxBusType.findText(obj.BusType));
        self.cmbxComMChannel.setCurrentIndex(self.cmbxComMChannel.findText(obj.ComMNetworkHandle));
        self.cmbxNmChannel.setCurrentIndex(self.cmbxNmChannel.findText(obj.BusNmNetworkHandle));
        self.enableTab(0)
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Channels'):
            self.refreshChannelTab(objname);
    #---------- General ------------------------------
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        if(self.cfg.general.DevError != checked):
            self.cfg.general.DevError = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxNodeDetection_clicked(self, checked):
        if(self.cfg.general.NodeDetection != checked):
            self.cfg.general.NodeDetection = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxVersionInfoApi_clicked(self, checked):
        if(self.cfg.general.VersionInfo != checked):
            self.cfg.general.VersionInfo = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxNodeId_clicked(self, checked):
        if(self.cfg.general.NodeId != checked):
            self.cfg.general.NodeId = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxUserData_clicked(self, checked):
        if(self.cfg.general.UserData != checked):
            self.cfg.general.UserData = checked;
            self.fileInd(False);
    #------------- Channel -------------------------
    @pyqtSignature("QString")
    def on_leChanneName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxComMChannel_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.ComMNetworkHandle!=p0):
                self.curobj.ComMNetworkHandle=p0;
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxNmChannel_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.BusNmNetworkHandle!=p0):
                self.curobj.BusNmNetworkHandle=p0;
                self.fileInd(False);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trNmCfg_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        self.refreshTab();
    
    def addChannel(self):
        id = len(self.cfg.channelList);
        name='vNm_Channel%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=NmChannel(name);
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
            self.on_trNmCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trNmCfg_itemClicked(parent, 0);
    @pyqtSignature("")
    def on_btn1_clicked(self):
        text = self.btn1.text()
        if(text == 'Add Channel'):
            self.addChannel();
        elif(text == 'Del Channel'):
            self.delObj(text);
        self.fileInd(False);

