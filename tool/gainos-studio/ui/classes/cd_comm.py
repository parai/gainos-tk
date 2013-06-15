# -*- coding: utf-8 -*-

"""
Module implementing cd_comm.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from PyQt4.QtCore import QStringList,QString

from gainos_tk_comm_cfg import *
from Ui_cd_comm import Ui_cd_comm

class cd_comm(QDialog, Ui_cd_comm):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, depinfo, parent = None):
        """
        depinfo[0] = Nm
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
        self.reloadTreeGui(0, self.cfg.channelList);
        self.reloadTreeGui(1, self.cfg.userList);
        self.disableAllTab();
        self.btn1.setDisabled(True);
        #init General
        self.cbxDevErr.setChecked(self.cfg.general.DevError)
        self.cbxVersionInfoApi.setChecked(self.cfg.general.VersionInfo)
        self.cbxNoCommu.setChecked(self.cfg.general.NoCom)
        self.cbxModeLimit.setChecked(self.cfg.general.ModeLimitation)
        self.spbxMinTime.setValue(self.cfg.general.MinTimeInFull)
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
    
    def reloadTreeGui(self, index, list):
        tree=self.trComMCfg.topLevelItem(index);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='Channels'):
            self.btn1.setText('Add Channel');
            self.btn1.setDisabled(False);
        elif(trname=='Users'):
            self.btn1.setText('Add User');
            self.btn1.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Channels'):
            self.btn1.setText('Del Channel');
            self.btn1.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Users'):
            self.btn1.setText('Del User');
            self.btn1.setDisabled(False);
    def refreshChannelTab(self, name):
        obj=gcfindObj(self.cfg.channelList, name);
        if(obj==None):
            return;
        self.curobj=obj;
        self.leChanneName.setText(obj.name);
        self.cmbxNmChannel.clear();
        self.cmbxSmChannel.clear();
        for chl in self.depinfo[0].cfg.channelList:
            self.cmbxNmChannel.addItem(chl.name)
        self.cmbxBusType.setCurrentIndex(self.cmbxBusType.findText(obj.BusType));
        self.cmbxNmVariant.setCurrentIndex(self.cmbxNmVariant.findText(obj.NmVariant));
        self.cmbxNmChannel.setCurrentIndex(self.cmbxNmChannel.findText(obj.NmChannelHandle));
        self.cmbxSmChannel.setCurrentIndex(self.cmbxSmChannel.findText(obj.BusSMNetworkHandle));
        self.spbxMainFncPeriod.setValue(obj.MainFunctionPeriod)
        self.spbxLightTimeout.setValue(obj.LightTimeout)
        if(obj.NmVariant == 'COMM_NM_VARIANT_LIGHT'):
            self.spbxLightTimeout.setDisabled(False);
        else:
            self.spbxLightTimeout.setDisabled(True);
        self.enableTab(0)
    def refreshUserTab(self, name):
        obj=gcfindObj(self.cfg.userList, name);
        if(obj==None):
            return;
        self.curobj=obj;
        self.leUserName.setText(obj.name);
        self.refreshTreeCtrl(self.trChannelSrc, self.trChannelDst, self.cfg.channelList, obj.channelList);
        self.enableTab(1)
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Channels'):
            self.refreshChannelTab(objname);
        elif(trname  == 'Users'):
            self.refreshUserTab(objname);
    #----------------- General -----------------------
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        if(self.cfg.general.DevError != checked):
            self.cfg.general.DevError = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxNoCommu_clicked(self, checked):
        if(self.cfg.general.NoCom != checked):
            self.cfg.general.NoCom = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxVersionInfoApi_clicked(self, checked):
        if(self.cfg.general.VersionInfo != checked):
            self.cfg.general.VersionInfo = checked;
            self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxModeLimit_clicked(self, checked):
        if(self.cfg.general.ModeLimitation != checked):
            self.cfg.general.ModeLimitation = checked;
            self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxMinTime_valueChanged(self, p0):
        if(self.cfg.general.MinTimeInFull != p0):
            self.cfg.general.MinTimeInFull = p0;
            self.fileInd(False);
    #-------------------- User ---------------------
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
    @pyqtSignature("")
    def on_btnAddChl_clicked(self):
        if(self.trChannelSrc.currentItem()):
            self.curobj.channelList.append(self.trChannelSrc.currentItem().text(0));
            self.moveTreeItem(self.trChannelSrc, self.trChannelDst);
            self.fileInd(False);
    
    @pyqtSignature("")
    def on_btnDelChl_clicked(self):
        if(self.trChannelDst.currentItem()):
            self.curobj.channelList.remove(self.trChannelDst.currentItem().text(0));
            self.moveTreeItem(self.trChannelDst, self.trChannelSrc);
            self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leUserName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    # -------------- Channel ------------------------
    @pyqtSignature("QString")
    def on_leChanneName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxBusType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.BusType!=p0):
                self.curobj.BusType=p0;
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxMainFncPeriod_valueChanged(self, p0):
       if(self.curobj!=None):
            if(self.curobj.MainFunctionPeriod!=p0):
                self.curobj.MainFunctionPeriod=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxNmVariant_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.NmVariant!=p0):
                self.curobj.NmVariant=p0;
                if(p0 == 'COMM_NM_VARIANT_LIGHT'):
                    self.spbxLightTimeout.setDisabled(False);
                else:
                    self.spbxLightTimeout.setDisabled(True);
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxLightTimeout_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.LightTimeout!=p0):
                self.curobj.LightTimeout=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxNmChannel_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.NmChannelHandle!=p0):
                self.curobj.NmChannelHandle=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxSmChannel_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.BusSMNetworkHandle!=p0):
                self.curobj.BusSMNetworkHandle=p0;
                self.fileInd(False);
    
    def addChannel(self):
        id = len(self.cfg.channelList);
        name='vComM_Channel%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComMChannel(name);
        self.cfg.channelList.append(obj);
    def addUser(self):
        id = len(self.cfg.userList);
        name='vComM_User%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=ComMUser(name);
        self.cfg.userList.append(obj);
    def delObj(self, text):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        if(text=='Del Channel'):
            self.cfg.channelList.remove(self.curobj);
        elif(text=='Del User'):
            self.cfg.userList.remove(self.curobj);
        del self.curtree;
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trComMCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trComMCfg_itemClicked(parent, 0);
    @pyqtSignature("")
    def on_btn1_clicked(self):
        text = self.btn1.text()
        if(text == 'Add Channel'):
            self.addChannel();
        elif(text == 'Add User'):
            self.addUser();
        elif(text[:3] == 'Del'):
            self.delObj(text);
        self.fileInd(False);
    
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trComMCfg_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        self.refreshTab();
