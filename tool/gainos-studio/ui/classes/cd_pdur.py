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

from PduRCfg import *
from Ui_PduR_Dlg import Ui_PduR_Dlg

class PduR_Dlg(QDialog, Ui_PduR_Dlg):
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

    def initGeneralGui(self):
        self.cbxDevErr.setChecked(self.cfg.General.DevErrorDetection);
        self.cbxVersionInfo.setChecked(self.cfg.General.VersionInfoAPI);
        self.cbxZeroCostEnable.setChecked(self.cfg.General.ZeroCostOperation);
        if(self.cfg.General.ZeroCostOperation == True):
            self.cbxSingleIf.setChecked(self.cfg.General.SingleIfEnable);
            self.cbxSingleTp.setChecked(self.cfg.General.SingleTpEnable);
            self.cmbxSingleIf.setDisabled(not self.cfg.General.SingleIfEnable);
            self.cmbxSingleTp.setDisabled(not self.cfg.General.SingleTpEnable);
        else:
            self.cbxSingleIf.setDisabled(True);
            self.cbxSingleTp.setDisabled(True);
            self.cmbxSingleIf.setDisabled(True);
            self.cmbxSingleTp.setDisabled(True);
        self.cmbxSingleIf.setCurrentIndex(self.cmbxSingleIf.findText(self.cfg.General.SingleIf));
        self.cmbxSingleTp.setCurrentIndex(self.cmbxSingleTp.findText(self.cfg.General.SingleTp));
        ####activated interface
        self.cbxCanIf.setChecked(self.cfg.General.CanIfUsed);
        self.cbxCanTp.setChecked(self.cfg.General.CanTpUsed);
        self.cbxLinIf.setChecked(self.cfg.General.LinIfUsed);
        self.cbxLinTp.setChecked(self.cfg.General.LinTpUsed);
        self.cbxCom.setChecked(self.cfg.General.ComUsed);
        self.cbxDcm.setChecked(self.cfg.General.DcmUsed);
        self.cbxJ1939Tp.setChecked(self.cfg.General.J1939TpUsed);

    def initTab(self):
        self.disableAllTab();
        self.spbxBufferSize.setRange(0, 65535);
        self.spbxSduLength.setRange(0, 65535);
        self.cmbxSrcPdu.clear();
        self.cmbxDstPdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxSrcPdu.addItem('RX_'+pdu.name);
            self.cmbxDstPdu.addItem('RX_'+pdu.name);
        for pdu in self.depinfo[0].cfg.pduList:
            self.cmbxSrcPdu.addItem('TX_'+pdu.name);
            self.cmbxDstPdu.addItem('TX_'+pdu.name);
    
    def reloadTreeGui(self):
        #Tp Buffers
        tree=self.trPduRCfg.topLevelItem(1);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.tpBufferList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
        ### Routing Path
        tree=self.trPduRCfg.topLevelItem(0);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for src in self.cfg.pduRoutingPathList:
            text = "%s(%s, %s)"%(src.name, src.SrcModule, src.SrcPduId);
            item=QTreeWidgetItem(tree,QStringList(text));
            tree.addChild(item);
            for dest in src.destPathList:
                text = "%s(%s, %s)"%(dest.name, dest.DestModule, dest.DestPduId);
                item2=QTreeWidgetItem(item,QStringList(text));
                item.addChild(item2);

    def initGui(self):
        self.initGeneralGui();
        self.initTab();
        #init Button
        self.btnAdd.setDisabled(True);
        self.btnDel.setDisabled(True);
        #reload
        self.reloadTreeGui();

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

    def refreshButton(self):
        trname = self.curtree.text(0);
        if(trname=='Routing Table'):
            self.btnAdd.setText('Add Routing Path');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Tp Buffers'):
            self.btnAdd.setText('Add Tp Buffer');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(self.curtree.parent().text(0) == 'Routing Table'):
            self.btnAdd.setText('Add Dest Path');
            self.btnDel.setText('Del Src Path');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0) == 'Tp Buffers'):
            self.btnDel.setText('Del Tp Buffer');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().parent().text(0) == 'Routing Table'):
            self.btnDel.setText('Del Dest Path');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);

    def refreshSrcPathTab(self, name):
        self.curobj=obj=self.findObj(self.cfg.pduRoutingPathList, name);
        if(obj==None):
            return;
        self.leSrcName.setText(obj.name);
        self.spbxSduLength.setValue(obj.SduLength);
        self.cmbxSrcPdu.setCurrentIndex(self.cmbxSrcPdu.findText(obj.SrcPduId));
        self.cbxSrcModule.setChecked(obj.SrcModuleEnable);
        self.cmbxSrcModule.setDisabled(not obj.SrcModuleEnable);
        self.cmbxSrcModule.setCurrentIndex(self.cmbxSrcModule.findText(obj.SrcModule));
        self.enableTab(0);
        
    def refreshDestPathTab(self, name):
        pname = self.curtree.parent().text(0).split('(')[0];
        src = self.findObj(self.cfg.pduRoutingPathList, pname);
        self.curobj=obj=self.findObj(src.destPathList, name);
        if(obj==None):
            return;#something wrong
        self.leDstName.setText(obj.name);
        self.cmbxDataProvision.setCurrentIndex(self.cmbxDataProvision.findText(obj.DataProvision));
        self.cmbxDataProvision.setDisabled(not obj.DataProvisionEnable);
        self.cbxDataProvision.setChecked(obj.DataProvisionEnable);
        self.cmbxDstPdu.setCurrentIndex(self.cmbxDstPdu.findText(obj.DestPduId));
        self.cbxDstModule.setChecked(obj.DestModuleEnable);
        self.cmbxDstModule.setDisabled(not obj.DestModuleEnable);
        self.cmbxDstModule.setCurrentIndex(self.cmbxDstModule.findText(obj.DestModule));
        self.enableTab(1);
        
    def refreshTpBufferTab(self, name):
        self.curobj=obj=self.findObj(self.cfg.tpBufferList, name);
        if(obj==None):
            return;#something wrong
        self.leBufferName.setText(obj.name);
        self.spbxBufferSize.setValue(obj.size);
        self.enableTab(2);

    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'Routing Table'):
            self.refreshSrcPathTab(objname.split('(')[0]);
        elif(trname  == 'Tp Buffers'):
            self.refreshTpBufferTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Routing Table' ):
            self.refreshDestPathTab(objname.split('(')[0]);

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trPduRCfg_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        self.refreshTab();
#########Tp Buffer#################################################    
    @pyqtSignature("QString")
    def on_leBufferName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            self.curtree.setText(0, p0);

    @pyqtSignature("int")
    def on_spbxBufferSize_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.size=p0;

####################### Src Path######################    
    @pyqtSignature("QString")
    def on_leSrcName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            text='%s(%s, %s)'%(self.curobj.name, self.curobj.SrcModule, self.curobj.SrcPduId);
            self.curtree.setText(0, text);
    
    @pyqtSignature("int")
    def on_spbxSduLength_valueChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.SduLength=p0;

    @pyqtSignature("QString")   
    def on_cmbxSrcPdu_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.SrcPduId=p0;
            text='%s(%s, %s)'%(self.curobj.name, self.curobj.SrcModule, self.curobj.SrcPduId);
            self.curtree.setText(0, text);
    
    @pyqtSignature("bool")
    def on_cbxSrcModule_clicked(self, checked):
        if(self.curobj!=None):
            self.curobj.SrcModuleEnable=checked;
            self.cmbxSrcModule.setDisabled(not checked);
            if(checked == False):
                ###reset it to Com
                self.on_cmbxSrcModule_activated('Com');
                self.cmbxSrcModule.setCurrentIndex(self.cmbxSrcModule.findText('Com'));

    @pyqtSignature("QString")
    def on_cmbxSrcModule_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.SrcModule=str(p0);
            text='%s(%s, %s)'%(self.curobj.name, self.curobj.SrcModule, self.curobj.SrcPduId);
            self.curtree.setText(0, text);

########################## Dst Path #########################
    @pyqtSignature("QString")
    def on_leDstName_textChanged(self, p0):
        if(self.curobj!=None):
            self.curobj.name=p0;
            text='%s(%s, %s)'%(self.curobj.name, self.curobj.DestModule, self.curobj.DestPduId);
            self.curtree.setText(0, text);

    @pyqtSignature("bool")
    def on_cbxDataProvision_clicked(self, checked):
        if(self.curobj!=None):
            self.curobj.DataProvisionEnable=checked;
            self.cmbxDataProvision.setDisabled(not checked);
            if(checked==False):
                ##reset it
                self.cmbxDataProvision.setCurrentIndex(-1);
                self.curobj.DataProvision='NO_PROVISION';
        
    @pyqtSignature("QString")
    def on_cmbxDataProvision_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.DataProvision=p0;
    
    @pyqtSignature("QString")
    def on_cmbxDstPdu_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.DestPduId=p0;
            text='%s(%s, %s)'%(self.curobj.name, self.curobj.DestModule, self.curobj.DestPduId);
            self.curtree.setText(0, text);
    
    @pyqtSignature("bool")
    def on_cbxDstModule_clicked(self, checked):
        if(self.curobj!=None):
            self.curobj.DestModuleEnable=checked;
            self.cmbxDstModule.setDisabled(not checked);
            if(checked == False):
                ###reset it to CanIf
                self.on_cmbxDstModule_activated('CanIf');
                self.cmbxDstModule.setCurrentIndex(self.cmbxDstModule.findText('CanIf'));
    
    @pyqtSignature("QString")
    def on_cmbxDstModule_activated(self, p0):
        if(self.curobj!=None):
            self.curobj.DestModule=str(p0);
            text='%s(%s, %s)'%(self.curobj.name, self.curobj.DestModule, self.curobj.DestPduId);
            self.curtree.setText(0, text);

    def addSrcPath(self):
        id = len(self.cfg.pduRoutingPathList);
        name='vPduR_SrcPath%s(Com,)'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=PduRSrcPath(name.split('(')[0]);
        self.cfg.pduRoutingPathList.append(obj);

    def addDestPath(self):
        pname=self.curtree.text(0).split('(')[0];
        src=self.findObj(self.cfg.pduRoutingPathList, pname);
        if(src == None):
            return;#something wrong.
        id = len(src.destPathList);
        name='vPduR_DestPath%s(CanIf,)'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=PduRDstPath(name.split('(')[0]);
        src.destPathList.append(obj);
 
    def addTpBuffer(self):
        id = len(self.cfg.tpBufferList);
        name='vPduR_TpBuffer%s'%(id);
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        self.curtree.setExpanded(True);
        obj=PduRTpBuffer(name);
        self.cfg.tpBufferList.append(obj);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text == 'Add Routing Path'):
            self.addSrcPath(); 
        elif(text == 'Add Dest Path'):
            self.addDestPath();
        elif(text == 'Add Tp Buffer'):
            self.addTpBuffer();
    
    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Del Src Path'):
            self.delObj(self.cfg.pduRoutingPathList);
        elif(text=='Del Tp Buffer'):
            self.delObj(self.cfg.tpBufferList);
        elif(text=='Del Dest Path'):
            pname = parent.text(0).split('(')[0];
            src = self.findObj(self.cfg.pduRoutingPathList, pname);
            self.delObj(src.destPathList);
        del self.curtree;
        #reselect a tree item,software trigger on_trGaInOsCfgList_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trPduRCfg_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trPduRCfg_itemClicked(parent, 0);
    
    @pyqtSignature("bool")
    def on_cbxDevErr_clicked(self, checked):
        self.cfg.General.DevErrorDetection = checked;

    @pyqtSignature("bool")
    def on_cbxVersionInfo_clicked(self, checked):
        self.cfg.General.VersionInfoAPI=checked;
    
    @pyqtSignature("bool")
    def on_cbxZeroCostEnable_clicked(self, checked):
        self.cfg.General.ZeroCostOperation=checked;
        if(checked == True):
            self.cbxSingleIf.setDisabled(False);
            self.cbxSingleTp.setDisabled(False);
            self.cmbxSingleIf.setDisabled(not self.cfg.General.SingleIfEnable);
            self.cmbxSingleTp.setDisabled(not self.cfg.General.SingleTpEnable);
        else:
            self.cbxSingleIf.setDisabled(True);
            self.cbxSingleTp.setDisabled(True);
            self.cmbxSingleIf.setDisabled(True);
            self.cmbxSingleTp.setDisabled(True);
    
    @pyqtSignature("bool")
    def on_cbxSingleIf_clicked(self, checked):
        self.cfg.General.SingleIfEnable=checked;
        self.cmbxSingleIf.setDisabled(not checked);
    
    @pyqtSignature("QString")
    def on_cmbxSingleIf_activated(self, p0):
        self.cfg.General.SingleIf = p0;
    
    @pyqtSignature("bool")
    def on_cbxSingleTp_clicked(self, checked):
        self.cfg.General.SingleTpEnable=checked;
        self.cmbxSingleTp.setDisabled(not checked);
    
    @pyqtSignature("QString")
    def on_cmbxSingleTp_activated(self, p0):
        self.cfg.General.SingleTp = p0;
    
    @pyqtSignature("bool")
    def on_cbxCanIf_clicked(self, checked):
        self.cfg.General.CanIfUsed = checked;
    
    @pyqtSignature("bool")
    def on_cbxCanTp_clicked(self, checked):
        self.cfg.General.CanTpUsed = checked;
    
    @pyqtSignature("bool")
    def on_cbxCom_clicked(self, checked):
        self.cfg.General.ComUsed = checked;
    
    @pyqtSignature("bool")
    def on_cbxDcm_clicked(self, checked):
        self.cfg.General.DcmUsed = checked;
    
    @pyqtSignature("bool")
    def on_cbxLinIf_clicked(self, checked):
        self.cfg.General.LinIfUsed = checked;
    
    @pyqtSignature("bool")
    def on_cbxLinTp_clicked(self, checked):
        self.cfg.General.LinTpUsed = checked;
    
    @pyqtSignature("bool")
    def on_cbxJ1939Tp_clicked(self, checked):
        self.cfg.General.J1939TpUsed = checked;
