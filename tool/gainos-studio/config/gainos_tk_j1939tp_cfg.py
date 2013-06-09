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

import os, sys
from Common import *
import xml.etree.ElementTree as ET
class J1939TpGeneral():
    def __init__(self):
        self.DevError = True;
        self.PacketBlock = 5;
        self.MainFunctionPeriod = 4;
        self.TxConfirmTimeout = 100;
    def save(self, root):
        nd = ET.Element('J1939TpGeneral');
        nd.attrib['DevError'] = str(self.DevError);
        nd.attrib['PacketBlock'] = str(self.PacketBlock);
        nd.attrib['MainFunctionPeriod'] = str(self.MainFunctionPeriod);
        nd.attrib['TxConfirmTimeout'] = str(self.TxConfirmTimeout);
        root.append(nd);
    def parse(self, nd):
        self.DevError = bool(nd.attrib['DevError']);
        self.PacketBlock = int(nd.attrib['PacketBlock']);
        self.MainFunctionPeriod = int(nd.attrib['MainFunctionPeriod']);
        self.TxConfirmTimeout = int(nd.attrib['TxConfirmTimeout']);
class J1939TpPgs():
    def __init__(self, name):
        self.name = name;
        self.Pgn = '0x0';
        self.EnDirectNPdu = False;
        self.DirectNPdu = '';
        self.NSdu = '';
        self.DynLength = False;     #Dynamic NPdu ???
    def save(self, root):
        nd = ET.Element('J1939TpPgs');
        nd.attrib['name'] = str(self.name);
        nd.attrib['Pgn'] = str(self.Pgn);
        nd.attrib['EnDirectNPdu'] = str(self.EnDirectNPdu);
        nd.attrib['DirectNPdu'] = str(self.DirectNPdu);
        nd.attrib['NSdu'] = str(self.NSdu);
        nd.attrib['DynLength'] = str(self.DynLength);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.Pgn = str(nd.attrib['Pgn']);
        self.EnDirectNPdu = bool(nd.attrib['EnDirectNPdu']);
        self.DirectNPdu = str(nd.attrib['DirectNPdu']);
        self.NSdu = str(nd.attrib['NSdu']);
        self.DynLength = bool(nd.attrib['DynLength']);
class J1939TpChannel():
    def __init__(self, name):
        self.name = name;
        self.Protocol = ''
        self.DtNPdu = ''
        self.CmNPdu = ''
        self.FcNPdu = ''
        #self.Direction = '' #no need to care while configure
        self.PgsList = []
    def save(self, root):
        nd = ET.Element('J1939TpChannel');
        nd.attrib['name'] = str(self.name);
        nd.attrib['Protocol'] = str(self.Protocol);
        nd.attrib['DtNPdu'] = str(self.DtNPdu);
        nd.attrib['CmNPdu'] = str(self.CmNPdu);
        nd.attrib['FcNPdu'] = str(self.FcNPdu);
        #nd.attrib['Direction'] = str(self.Direction);
        nd2 = ET.Element('PgsList');
        for obj in self.PgsList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.Protocol = str(nd.attrib['Protocol']);
        self.DtNPdu = str(nd.attrib['DtNPdu']);
        self.CmNPdu = str(nd.attrib['CmNPdu']);
        self.FcNPdu = str(nd.attrib['FcNPdu']);
        #self.Direction = str(nd.attrib['Direction']);
        for nd2 in nd.find('PgsList'):
            obj = J1939TpPgs('');
            obj.parse(nd2);
            self.PgsList.append(obj);
class gainos_tk_j1939tp_obj():
    def __init__(self):
        self.general = J1939TpGeneral();
        self.rxChannelList = [];
        self.txChannelList = [];
    def save(self, root):
        self.general.save(root);
        nd = ET.Element('rxChannelList');
        for obj in self.rxChannelList:
            obj.save(nd);
        root.append(nd);
        nd = ET.Element('txChannelList');
        for obj in self.txChannelList:
            obj.save(nd);
        root.append(nd);
    def parse(self, root):
        self.general.parse(root.find('J1939TpGeneral'));
        for nd in root.find('rxChannelList'):
            obj = J1939TpChannel('');
            obj.parse(nd);
            self.rxChannelList.append(obj);
        for nd in root.find('txChannelList'):
            obj = J1939TpChannel('');
            obj.parse(nd);
            self.txChannelList.append(obj);
class gainos_tk_j1939tp_cfg():
    def __init__(self, chip=None):
        self.cfg=gainos_tk_j1939tp_obj();

    def toString(self):
        str='J1939Tp!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_j1939tp import cd_j1939tp
        depinfo=[];
        md=gcfindModule(module_list, 'EcuC');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg  = cd_j1939tp(title, fileInd, self.cfg, depinfo);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        self.cfg.save(root);
    
    def parse(self, root):
        self.cfg.parse(root);

    def gen(self, path):
        self.codeGenH(path);
    def codeGenH(self,path):
        fp = open(path+'/J1939Tp_Cfg.h','w');
        fp.write(gcGainOS_TkHead());
        fp.write("""#if !(((J1939TP_SW_MAJOR_VERSION == 1) && (J1939TP_SW_MINOR_VERSION == 0)) )
#error J1939Tp: Configuration file expected BSW module version to be 1.0.*
#endif

#ifndef J1939TP_CFG_H
#define J1939TP_CFG_H

#include "J1939Tp.h\n\n""");
        fp.write('#define J1939TP_DEV_ERROR_DETECT %s\n'%gSTD_ON((self.cfg.general.DevError)));
        fp.write('#define J1939TP_PACKETS_PER_BLOCK     %s\n'%(self.cfg.general.PacketBlock))
        fp.write('#define J1939TP_MAIN_FUNCTION_PERIOD  %s\n'%(self.cfg.general.MainFunctionPeriod))
        fp.write('#define J1939TP_TX_CONF_TIMEOUT       %s\n'%(self.cfg.general.TxConfirmTimeout))
        fp.write('\n');
        fp.write('#define J1939TP_CHANNEL_COUNT       %s\n'%(len(self.cfg.rxChannelList+self.cfg.txChannelList)));
        fp.write('#define J1939TP_TX_CHANNEL_COUNT    %s\n'%(len(self.cfg.txChannelList)));
        fp.write('#define J1939TP_RX_CHANNEL_COUNT    %s\n'%(len(self.cfg.rxChannelList)));
        fp.write('\n');
        fp.write('#define J1939TP_RX_PDU_COUNT   /*? I don\'t understand */\n')
        fp.write('\n');
        txlen = rxlen = 0;
        for chl in self.cfg.txChannelList:
            txlen += len(chl.PgsList);
        for chl in self.cfg.rxChannelList:
            rxlen += len(chl.PgsList);
        fp.write('#define J1939TP_PG_COUNT        %s\n'%(txlen + rxlen));
        fp.write('#define J1939TP_TX_PG_COUNT     %s\n'%(txlen));
        fp.write('#define J1939TP_RX_PG_COUNT     %s\n'%(rxlen));
        fp.write('\n// Number of pgs for each channel \n');
        for chl in self.cfg.rxChannelList + self.cfg.txChannelList:
            fp.write('#define J1939TP_%s_PG_COUNT %s\n'%(chl.name.upper(),len(chl.PgsList)));
        fp.write('\n// NSDU:s\n');
        id = 0 
        for chl in self.cfg.txChannelList+self.cfg.rxChannelList:
            for pgs in chl.PgsList:
                fp.write('#define J1939TP_%s %s\n'%(pgs.NSdu,id))
                id += 1
        fp.write('\n// PDU:s\n')
        id = 0
        for chl in self.cfg.txChannelList+self.cfg.rxChannelList:
            #does the order matter ?
            if(chl.Protocol == 'J1939TP_PROTOCOL_CMDT'):
                fp.write('#define J1939TP_%s %s //FcNPdu\n'%(chl.FcNPdu,id));
                id += 1
            fp.write('#define J1939TP_%s %s //DtNPdu\n'%(chl.DtNPdu,id))
            id += 1
            for pgs in chl.PgsList:
                if(pgs.EnDirectNPdu):
                    fp.write('#define J1939TP_%s %s //DirectNPdu\n'%(pgs.DirectNPdu,id));
                    id += 1
            fp.write('#define J1939TP_%s %s //CmNPdu\n'%(chl.CmNPdu,id))
            id += 1
        fp.write('\n\n#endif /*J1939TP_CFG_H*/\n\n');
