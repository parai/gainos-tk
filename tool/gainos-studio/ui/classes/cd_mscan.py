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
from Common import *
from gainos_tk_mscan_cfg import CanFilterMaskMscan, CanHohMscan, CanCtrlMscan

from Ui_cd_mscan import Ui_cd_mscan

class cd_mscan(QDialog, Ui_cd_mscan):
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
        QDialog.__init__(self, parent)
        self.setupUi(self);
        self.setWindowTitle(title);
        self.initGui();

    def reloadTreeGui(self, trindex, list):
        tree=self.trCanCfg.topLevelItem(trindex);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);

    def reloadCtrlGui(self):
        tree=self.trCanCfg.topLevelItem(1);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.CanCtrlList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
            for hoh in obj.hohList:
                item2=QTreeWidgetItem(item,QStringList(hoh.name));
                item.addChild(item2);


    def initGui(self):
        #Init General 
        self.cbxDevErr.setChecked(self.cfg.CanGeneral.CanDevErrorDetection);
        self.cbxCanVersionInfo.setChecked(self.cfg.CanGeneral.CanVersionInfoApi);
        self.spbxTimeout.setValue(self.cfg.CanGeneral.CanTimeoutDuration);
        #Init Button and Tab
        self.initButton();
        self.disableAllTab();
        self.leCtrlName.setDisabled(True);
        #Init Tree
        self.reloadTreeGui(0, self.cfg.CanFilterMaskList);
        #Init Ctrl Tree
        self.reloadCtrlGui();

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnDel.setDisabled(True);
    
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        self.cfg.CanGeneral.CanDevErrorDetection=checked;
        self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxCanVersionInfo_clicked(self, checked):
        self.cfg.CanGeneral.CanVersionInfoApi=checked;
        self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr0_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[0]!=p0):
                self.curobj.idmr[0]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr1_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[1]!=p0):
                self.curobj.idmr[1]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr2_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[2]!=p0):
                self.curobj.idmr[2]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr3_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[3]!=p0):
                self.curobj.idmr[3]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr4_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[4]!=p0):
                self.curobj.idmr[4]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr5_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[5]!=p0):
                self.curobj.idmr[5]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr6_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[6]!=p0):
                self.curobj.idmr[6]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdmr7_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idmr[7]!=p0):
                self.curobj.idmr[7]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxIdam_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.idam!=p0):
                self.curobj.idam=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxHohType_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.hohType!=p0):
                self.curobj.hohType=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxIdType_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.idType!=p0):
                self.curobj.idType=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxObjType_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.objType!=p0):
                self.curobj.objType=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxFilterMask_activated(self, p0):
        if(self.curobj != None):
            if(self.curobj.filterMask!=p0):
                self.curobj.filterMask=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leMbMask_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.mbMask!=p0):
                self.curobj.mbMask=p0;
                self.fileInd(False);

    
    @pyqtSignature("int")
    def on_spbxTimeout_valueChanged(self, p0):
        self.cfg.CanGeneral.CanTimeoutDuration=p0;
        self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar0_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[0]!=p0):
                self.curobj.idar[0]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar1_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[1]!=p0):
                self.curobj.idar[1]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar2_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[2]!=p0):
                self.curobj.idar[2]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar3_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[3]!=p0):
                self.curobj.idar[3]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar4_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[4]!=p0):
                self.curobj.idar[4]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar5_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[5]!=p0):
                self.curobj.idar[5]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar6_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[6]!=p0):
                self.curobj.idar[6]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdar7_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idar[7]!=p0):
                self.curobj.idar[7]=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leFmName_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leHohName_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leIdValue_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.idValue!=p0):
                self.curobj.idValue=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leCtrlName_textChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.name != p0):
                self.curobj.name = p0;
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxBaudrate_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.baudrate != p0):
                self.curobj.baudrate = p0;
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxPropSeg_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.propseg != p0):
                self.curobj.propseg = p0;
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxSeg1_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.seg1 != p0):
                self.curobj.seg1 = p0;
                self.fileInd(False);
    
    @pyqtSignature("int")
    def on_spbxSeg2_valueChanged(self, p0):
        if(self.curobj != None):
            if(self.curobj.seg2 != p0):
                self.curobj.seg2 = p0;
                self.fileInd(False);

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='CanFilterMask'):
            self.btnAdd.setText('Add Filter');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='CanController'):
            self.btnAdd.setText('Add Ctrl');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0)=='CanFilterMask'):
            self.btnDel.setText('Del Filter');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='CanController'):
            self.btnAdd.setText('Add Hoh');
            self.btnDel.setText('Del Ctrl');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='CanController'):
            self.btnDel.setText('Del Hoh');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);


    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 3):
            self.tabCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 3):
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

    def refreshFilterMaskTab(self, name):
        obj = self.findObj(self.cfg.CanFilterMaskList, name);
        if(obj == None):
            return;
        self.curobj=obj;
        self.leFmName.setText(obj.name);
        self.leIdar0.setText(obj.idar[0]);
        self.leIdar1.setText(obj.idar[1]);
        self.leIdar2.setText(obj.idar[2]);
        self.leIdar3.setText(obj.idar[3]);
        self.leIdmr0.setText(obj.idmr[0]);
        self.leIdmr1.setText(obj.idmr[1]);
        self.leIdmr2.setText(obj.idmr[2]);
        self.leIdmr3.setText(obj.idmr[3]);
        self.leIdar4.setText(obj.idar[4]);
        self.leIdar5.setText(obj.idar[5]);
        self.leIdar6.setText(obj.idar[6]);
        self.leIdar7.setText(obj.idar[7]);
        self.leIdmr4.setText(obj.idmr[4]);
        self.leIdmr5.setText(obj.idmr[5]);
        self.leIdmr6.setText(obj.idmr[6]);
        self.leIdmr7.setText(obj.idmr[7]);
        self.cmbxIdam.setCurrentIndex(self.cmbxIdam.findText(obj.idam));
        self.enableTab(2);

    def refreshCanCtrlTab(self, name):
        obj = self.findObj(self.cfg.CanCtrlList, name);
        if(obj == None):
            return;
        self.curobj=obj;
        self.leCtrlName.setText(obj.name);
        self.spbxBaudrate.setValue(obj.baudrate);
        self.spbxPropSeg.setValue(obj.propseg);
        self.spbxSeg1.setValue(obj.seg1);
        self.spbxSeg2.setValue(obj.seg2);
        self.enableTab(0);
    
    def refreshCanHohTab(self, name):
        ctrl=self.findObj(self.cfg.CanCtrlList, self.curtree.parent().text(0));
        obj = self.findObj(ctrl.hohList, name);
        if(obj == None):
            return;
        self.curobj=obj;
        self.leHohName.setText(obj.name);
        self.cmbxHohType.setCurrentIndex(self.cmbxHohType.findText(obj.hohType));
        self.cmbxIdType.setCurrentIndex(self.cmbxIdType.findText(obj.idType));
        self.cmbxObjType.setCurrentIndex(self.cmbxObjType.findText(obj.objType));
        #Add Mask
        self.cmbxFilterMask.clear();
        index=i=-1;
        for mask in self.cfg.CanFilterMaskList:
            i+=1;
            if(obj.filterMask==mask.name):
                index=i;
            self.cmbxFilterMask.addItem(mask.name);
        self.cmbxFilterMask.setCurrentIndex(index);
        self.leIdValue.setText(obj.idValue);
        self.leMbMask.setText(obj.mbMask);
        self.enableTab(1);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'CanFilterMask'):
            self.refreshFilterMaskTab(objname);
        elif(trname  == 'CanController'):
            self.refreshCanCtrlTab(objname);
        elif(self.curtree.parent().parent().text(0)  == 'CanController'):
            self.refreshCanHohTab(objname);
        
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trCanCfg_itemClicked(self, item, column):
        self.curtree=item;
        self.refreshButton();
        self.refreshTab();

    def addFilter(self):
        id = len(self.cfg.CanFilterMaskList);
        name=QString('vCanFilterMask%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=CanFilterMaskMscan(name);
        self.cfg.CanFilterMaskList.append(obj);
        self.curtree.setExpanded(True);

    def addCtrlDlg(self):
        from cd_add import cd_add
        fullList=['CAN_CTRL_0', 'CAN_CTRL_1','CAN_CTRL_2','CAN_CTRL_3','CAN_CTRL_4',];
        list=[];
        for it in fullList:
            if(self.findObj(self.cfg.CanCtrlList, it)==None):
                list.append(it);
        dlg=cd_add('Add Can Controller', list);
        dlg.exec_();
        if(dlg.result==True):
            return dlg.item;
        else:
            return None;
        
    def addCtrl(self):
        id = len(self.cfg.CanCtrlList);
        name=self.addCtrlDlg();
        if(name == None):
            return;
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=CanCtrlMscan(name);
        self.cfg.CanCtrlList.append(obj);
        self.curtree.setExpanded(True);

    def addHoh(self):
        id = len(self.curobj.hohList);
        if(id>1):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                    'Only 2 Hardware Object Handlers allowed for 1 Can Controller.\nOne should be Tx and the other one should be Rx.').exec_();
            return;
        name=QString('%s_vCanHoh%d'%(self.curobj.name, id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=CanHohMscan(name);
        self.curobj.hohList.append(obj);
        self.curtree.setExpanded(True);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Filter'):
            self.addFilter();
        elif(text=='Add Ctrl'):
            self.addCtrl();
        elif(text=='Add Hoh'):
            self.addHoh();
        self.fileInd(False);

    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Del Filter'):
            self.delObj(self.cfg.CanFilterMaskList);
        elif(text=='Del Ctrl'):
            self.delObj(self.cfg.CanCtrlList);
        elif(text=='Del Hoh'):
            ctrl=self.findObj(self.cfg.CanCtrlList, parent.text(0))
            self.delObj(ctrl.hohList);
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trCanCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trCanCfg_itemClicked(parent, 0);
        self.fileInd(False);

