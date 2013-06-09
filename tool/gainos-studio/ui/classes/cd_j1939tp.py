# -*- coding: utf-8 -*-

"""
Module implementing cd_j1939tp.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtCore import QStringList,QString
from Ui_cd_j1939tp import Ui_cd_j1939tp
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox
from gainos_tk_j1939tp_cfg import *
class cd_j1939tp(QDialog, Ui_cd_j1939tp):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, depinfo, parent = None):
        """
        depinfo[0] = EcuC Cfg
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title);
        self.cfg = cfg;
        self.fileInd = fileInd;
        self.curtree = None;
        self.curobj = None;
        self.depinfo = depinfo;
        self.initGui();
    def initGeneral(self):
        self.cbxDevError.setChecked(self.cfg.general.DevError);
        self.spbxPktBlk.setValue(self.cfg.general.PacketBlock);
        self.spbxMainFncPeriod.setValue(self.cfg.general.MainFunctionPeriod);
        self.spbxCfTmo.setValue(self.cfg.general.TxConfirmTimeout);
    def reloadTreeChannel(self, index, list):
        tree=self.trJ1939Tp.topLevelItem(index);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            for obj2 in obj.PgsList:
                item2 = QTreeWidgetItem(item,QStringList(obj2.name));
    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 3):
            self.tabJ1939Tp.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 3):
            if(i==index):
                self.tabJ1939Tp.setTabEnabled(i, True);
                self.tabJ1939Tp.setCurrentIndex(i);
            else:
                self.tabJ1939Tp.setTabEnabled(i, False); 
    def initGui(self):
        self.initGeneral();
        self.reloadTreeChannel(0, self.cfg.rxChannelList)
        self.reloadTreeChannel(1, self.cfg.txChannelList)
        self.disableAllTab();
    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        if(trname=='RxChannel'):
            self.btn1.setText('Add Rx Channel');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
        elif(trname=='TxChannel'):
            self.btn1.setText('Add Tx Channel');
            self.btn1.setDisabled(False);
            self.btn2.setDisabled(True);
        elif(self.curtree.parent().text(0)=='RxChannel'):
            self.btn1.setText('Add Rx Pgs');
            self.btn1.setDisabled(False);
            self.btn2.setText('Del Rx Channel');
            self.btn2.setDisabled(False);
        elif(self.curtree.parent().text(0)=='TxChannel'):
            self.btn1.setText('Add Tx Pgs');
            self.btn1.setDisabled(False);
            self.btn2.setText('Del Tx Channel');
            self.btn2.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='RxChannel'):
            self.btn1.setText('');
            self.btn1.setDisabled(True);
            self.btn2.setText('Del Rx Pgs');
            self.btn2.setDisabled(False);
        elif(self.curtree.parent().parent().text(0)=='TxChannel'):
            self.btn1.setText('');
            self.btn1.setDisabled(True);
            self.btn2.setText('Del Tx Pgs');
            self.btn2.setDisabled(False);
    def refreshRxChannelTab(self, name):
        self.curobj = gcfindObj(self.cfg.rxChannelList, name)
        self.leRxChlName.setText(name);
        self.cmbxRxCmNpdu.clear();
        self.cmbxRxDtNpdu.clear();
        self.cmbxTxFcNpdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            # as Now I am not that clear about CM DT and FC, So add all..
            self.cmbxRxCmNpdu.addItem('RX_'+pdu.name);
            self.cmbxRxCmNpdu.addItem('TX_'+pdu.name);
            self.cmbxRxDtNpdu.addItem('RX_'+pdu.name);
            self.cmbxRxDtNpdu.addItem('TX_'+pdu.name);
            self.cmbxTxFcNpdu.addItem('RX_'+pdu.name);
            self.cmbxTxFcNpdu.addItem('TX_'+pdu.name);
        if(self.curobj.Protocol == 'J1939TP_PROTOCOL_BAM'):
            self.cmbxTxFcNpdu.clear();
            self.cmbxTxFcNpdu.setDisabled(True);
        else:
            self.cmbxTxFcNpdu.setDisabled(False);
        self.cmbxRxProType.setCurrentIndex(self.cmbxRxProType.findText(self.curobj.Protocol))
        self.cmbxRxCmNpdu.setCurrentIndex(self.cmbxRxCmNpdu.findText(self.curobj.CmNPdu))
        self.cmbxRxDtNpdu.setCurrentIndex(self.cmbxRxDtNpdu.findText(self.curobj.DtNPdu))
        self.cmbxTxFcNpdu.setCurrentIndex(self.cmbxTxFcNpdu.findText(self.curobj.FcNPdu))
        self.enableTab(0);
    def refreshTxChannelTab(self, name):
        self.curobj = gcfindObj(self.cfg.txChannelList, name)
        self.leTxChlName.setText(name);
        self.cmbxTxCmNpdu.clear();
        self.cmbxTxDtNpdu.clear();
        self.cmbxRxFcNpdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            # as Now I am not that clear about CM DT and FC, So add all..
            self.cmbxTxCmNpdu.addItem('RX_'+pdu.name);
            self.cmbxTxCmNpdu.addItem('TX_'+pdu.name);
            self.cmbxTxDtNpdu.addItem('RX_'+pdu.name);
            self.cmbxTxDtNpdu.addItem('TX_'+pdu.name);
            self.cmbxRxFcNpdu.addItem('RX_'+pdu.name);
            self.cmbxRxFcNpdu.addItem('TX_'+pdu.name);
        if(self.curobj.Protocol == 'J1939TP_PROTOCOL_BAM'):
            self.cmbxRxFcNpdu.clear();
            self.cmbxRxFcNpdu.setDisabled(True);
        else:
            self.cmbxRxFcNpdu.setDisabled(False);
        self.cmbxTxProType.setCurrentIndex(self.cmbxTxProType.findText(self.curobj.Protocol))
        self.cmbxTxCmNpdu.setCurrentIndex(self.cmbxTxCmNpdu.findText(self.curobj.CmNPdu))
        self.cmbxTxDtNpdu.setCurrentIndex(self.cmbxTxDtNpdu.findText(self.curobj.DtNPdu))
        self.cmbxRxFcNpdu.setCurrentIndex(self.cmbxRxFcNpdu.findText(self.curobj.FcNPdu))
        self.enableTab(2);
    def refreshRxPgsTab(self, name):
        pname = self.curtree.parent().text(0)
        p = gcfindObj(self.cfg.rxChannelList, pname)
        self.curobj = gcfindObj(p.PgsList, name);
        self.leParmName.setText(name);
        self.lePgn.setText(self.curobj.Pgn);
        self.cmbxParmNSdu.clear();
        self.cmbxDrtNpdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            # as Now I am not that clear about CM DT and FC, So add all..
            self.cmbxParmNSdu.addItem('RX_'+pdu.name);
            self.cmbxParmNSdu.addItem('TX_'+pdu.name);
            self.cmbxDrtNpdu.addItem('RX_'+pdu.name);
            self.cmbxDrtNpdu.addItem('TX_'+pdu.name);
        self.cmbxParmNSdu.setCurrentIndex(self.cmbxParmNSdu.findText(self.curobj.NSdu))
        self.cmbxDrtNpdu.setCurrentIndex(self.cmbxDrtNpdu.findText(self.curobj.DirectNPdu))
        self.cbxDynNPdu.setChecked(self.curobj.DynLength);
        self.cbxEnDrtNPdu.setChecked(self.curobj.EnDirectNPdu);
        self.cmbxDrtNpdu.setDisabled(not self.curobj.EnDirectNPdu);
        self.enableTab(1);
    def refreshTxPgsTab(self, name):
        pname = self.curtree.parent().text(0)
        p = gcfindObj(self.cfg.txChannelList, pname)
        self.curobj = gcfindObj(p.PgsList, name);
        self.leParmName.setText(name);
        self.lePgn.setText(self.curobj.Pgn);
        self.cmbxParmNSdu.clear();
        self.cmbxDrtNpdu.clear();
        for pdu in self.depinfo[0].cfg.pduList:
            # as Now I am not that clear about CM DT and FC, So add all..
            self.cmbxParmNSdu.addItem('RX_'+pdu.name);
            self.cmbxParmNSdu.addItem('TX_'+pdu.name);
            self.cmbxDrtNpdu.addItem('RX_'+pdu.name);
            self.cmbxDrtNpdu.addItem('TX_'+pdu.name);
        self.cmbxParmNSdu.setCurrentIndex(self.cmbxParmNSdu.findText(self.curobj.NSdu))
        self.cmbxDrtNpdu.setCurrentIndex(self.cmbxDrtNpdu.findText(self.curobj.DirectNPdu))
        self.cbxDynNPdu.setChecked(self.curobj.DynLength);
        self.cbxEnDrtNPdu.setChecked(self.curobj.EnDirectNPdu);
        self.cmbxDrtNpdu.setDisabled(not self.curobj.EnDirectNPdu);
        self.enableTab(1);
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname  == 'RxChannel'):
            self.refreshRxChannelTab(objname);
        elif(trname  == 'TxChannel'):
            self.refreshTxChannelTab(objname);
        elif(self.curtree.parent().parent().text(0)  == 'RxChannel'):
            self.refreshRxPgsTab(objname);
        elif(self.curtree.parent().parent().text(0)  == 'TxChannel'):
            self.refreshTxPgsTab(objname);
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trJ1939Tp_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshTab();
        self.refreshButton();

    def delObj(self, text):
        #remove it from obj list
        if(text=='Del Rx Channel'):
            self.cfg.rxChannelList.remove(self.curobj);
        elif(text == 'Del Tx Channel'):
            self.cfg.txChannelList.remove(self.curobj);
        elif(text == 'Del Rx Pgs'):
            pname = self.curtree.parent().text(0);
            p = gcfindObj(self.cfg.rxChannelList,pname);
            p.PgsList.remove(self.curobj);
        elif(text == 'Del Tx Pgs'):
            pname = self.curtree.parent().text(0);
            p = gcfindObj(self.cfg.txChannelList,pname);
            p.PgsList.remove(self.curobj);
        #delete the tree, reselect a tree item
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        del self.curtree;
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trJ1939Tp_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trJ1939Tp_itemClicked(parent, 0);
    
    def addRxChannel(self):
        id = len(self.cfg.rxChannelList);
        name=QString('vRxChannel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        obj = J1939TpChannel(name);
        self.cfg.rxChannelList.append(obj);
        obj.PgsList.append(J1939TpPgs('vRxPg0'));
        QTreeWidgetItem(item,QStringList('vRxPg0'));
        self.curtree.setExpanded(True);
    def addTxChannel(self):
        id = len(self.cfg.txChannelList);
        name=QString('vTxChannel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        obj = J1939TpChannel(name);
        self.cfg.txChannelList.append(obj);
        obj.PgsList.append(J1939TpPgs('vTxPg0'));
        QTreeWidgetItem(item,QStringList('vTxPg0'));
        self.curtree.setExpanded(True);
    def addRxPgs(self):
        p = self.curobj;
        id = len(p.PgsList);
        name=QString('vRxPg%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        obj = J1939TpPgs(name);
        p.PgsList.append(obj);
        self.curtree.setExpanded(True); 
    def addTxPgs(self):
        p = self.curobj;
        id = len(p.PgsList);
        name=QString('vTxPg%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        obj = J1939TpPgs(name);
        p.PgsList.append(obj);
        self.curtree.setExpanded(True); 

    @pyqtSignature("")
    def on_btn1_clicked(self):
        text = self.btn1.text();
        if(text == 'Add Rx Channel'):
            self.addRxChannel();
        elif(text == 'Add Tx Channel'):
            self.addTxChannel();
        elif(text == 'Add Rx Pgs'):
            self.addRxPgs();
        elif(text == 'Add Tx Pgs'):
            self.addTxPgs();    
        self.fileInd(False);
    
    @pyqtSignature("")
    def on_btn2_clicked(self):
        text = self.btn2.text();
        if(text[:3] == 'Del'):
            self.delObj(text);
        
    #------------- General -------------------------
    @pyqtSignature("bool")
    def on_cbxDevError_clicked(self, checked):
        if(self.cfg.general.DevError != checked):
            self.cfg.general.DevError = checked;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxPktBlk_valueChanged(self, p0):
        if(self.cfg.general.PacketBlock != p0):
            self.cfg.general.PacketBlock = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxMainFncPeriod_valueChanged(self, p0):
        if(self.cfg.general.MainFunctionPeriod != p0):
            self.cfg.general.MainFunctionPeriod = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxCfTmo_valueChanged(self, p0):
        if(self.cfg.general.TxConfirmTimeout != p0):
            self.cfg.general.TxConfirmTimeout = p0;
            self.fileInd(False);
    #-------------------- Rx Channel ---------------    
    @pyqtSignature("QString")
    def on_leRxChlName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxRxProType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.Protocol != p0):
                self.curobj.Protocol=p0;
                self.on_trJ1939Tp_itemClicked(self.curtree,0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxRxCmNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.CmNPdu != p0):
                self.curobj.CmNPdu=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxRxDtNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.DtNPdu != p0):
                self.curobj.DtNPdu=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxTxFcNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.FcNPdu != p0):
                self.curobj.FcNPdu=p0;
                self.fileInd(False);
    #-------------------- Tx Channel ---------------    
    @pyqtSignature("QString")
    def on_leTxChlName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxTxProType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.Protocol != p0):
                self.curobj.Protocol=p0;
                self.on_trJ1939Tp_itemClicked(self.curtree,0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxTxCmNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.CmNPdu != p0):
                self.curobj.CmNPdu=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxTxDtNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.DtNPdu != p0):
                self.curobj.DtNPdu=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxRxFcNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.FcNPdu != p0):
                self.curobj.FcNPdu=p0;
                self.fileInd(False);
    #------------- PGS ---------------------
    @pyqtSignature("QString")
    def on_leParmName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_lePgn_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.Pgn!=p0):
                self.curobj.Pgn=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxParmNSdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.NSdu!=p0):
                self.curobj.NSdu=p0;
                self.fileInd(False);
    
    @pyqtSignature("bool")
    def on_cbxDynNPdu_clicked(self,p0):
        if(self.curobj!=None):
            if(self.curobj.DynLength!=p0):
                self.curobj.DynLength=p0;
                self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxEnDrtNPdu_clicked(self,p0):
        if(self.curobj!=None):
            if(self.curobj.EnDirectNPdu!=p0):
                self.curobj.EnDirectNPdu=p0;
                self.cmbxDrtNpdu.setDisabled(not p0);
                self.curobj.DirectNPdu = '';
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxDrtNpdu_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.DirectNPdu!=p0):
                self.curobj.DirectNPdu=p0;
                self.fileInd(False);