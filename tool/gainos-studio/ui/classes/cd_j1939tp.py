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
    def __init__(self, title, fileInd, cfg, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title);
        self.cfg = cfg;
        self.fileInd = fileInd;
        self.curtree = None;
        self.curobj = None;
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
    def initGui(self):
        self.initGeneral();
        self.reloadTreeChannel(0, self.cfg.rxChannelList)
        self.reloadTreeChannel(1, self.cfg.txChannelList)
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
    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trJ1939Tp_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshButton();
        
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
    

    

    

    
    @pyqtSignature("QString")
    def on_leTxChlName_textChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxTxProType_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxTxCmNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxTxDtNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxRxFcNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_leParmName_textChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_lePgn_textChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxParmNSdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("")
    def on_cbxDynNPdu_clicked(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("")
    def on_cbxEnDrtNPdu_clicked(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxDrtNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_leRxChlName_textChanged(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxRxProType_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxRxCmNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxRxDtNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    
    @pyqtSignature("QString")
    def on_cmbxTxFcNpdu_activated(self, p0):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
    def addRxChannel(self):
        id = len(self.cfg.rxChannelList);
        name=QString('vRxChannel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        obj = J1939TpChannel(name);
        self.cfg.rxChannelList.append(obj);
        obj.PgsList.append(J1939TpPgs('vPgs0'));
        QTreeWidgetItem(item,QStringList('vPgs0'));
        self.curtree.setExpanded(True);
    def addTxChannel(self):
        id = len(self.cfg.txChannelList);
        name=QString('vTxChannel%s'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        obj = J1939TpChannel(name);
        self.cfg.txChannelList.append(obj);
        obj.PgsList.append(J1939TpPgs('vPgs0'));
        QTreeWidgetItem(item,QStringList('vPgs0'));
        self.curtree.setExpanded(True);
    @pyqtSignature("")
    def on_btn1_clicked(self):
        text = self.btn1.text();
        if(text == 'Add Rx Channel'):
            self.addRxChannel();
        elif(text == 'Add Tx Channel'):
            self.addTxChannel();
        self.fileInd(False);
    
    @pyqtSignature("")
    def on_btn2_clicked(self):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
