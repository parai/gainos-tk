# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
import xml.etree.ElementTree as ET
from Common import *
class DcmGeneral():
    def __init__(self):
        self.DevErrorDetection = True;
        self.VersionInfoApi   = False;
        self.RespondAllRequest = True;
        self.MainFunctionPeriod = 10; #ms
        self.ResponsePending = True;
        self.MaxNegativeResponse = 10;
        self.MaxNumberofSimultaneousPeriodictransmissions = 10;
        self.PeriodicTransmissionSlow = 10;
        self.PeriodicTransmissionMedium = 11;
        self.PeriodicTransmissionFast = 12;
        self.MaxSourcesforOneDynamicIdentifier = 10;
    def save(self, root):
        nd = ET.Element('General');
        nd.attrib['DevErrorDetection'] = str(self.DevErrorDetection);
        nd.attrib['VersionInfoApi'] = str(self.VersionInfoApi);
        nd.attrib['RespondAllRequest'] = str(self.RespondAllRequest);
        nd.attrib['MainFunctionPeriod'] = str(self.MainFunctionPeriod);
        nd.attrib['ResponsePending'] = str(self.ResponsePending);
        nd.attrib['MaxNegativeResponse'] = str(self.MaxNegativeResponse);
        nd.attrib['MaxNumberofSimultaneousPeriodictransmissions'] = str(self.MaxNumberofSimultaneousPeriodictransmissions);
        nd.attrib['PeriodicTransmissionSlow'] = str(self.PeriodicTransmissionSlow);
        nd.attrib['PeriodicTransmissionMedium'] = str(self.PeriodicTransmissionMedium);
        nd.attrib['PeriodicTransmissionFast'] = str(self.PeriodicTransmissionFast);
        nd.attrib['MaxSourcesforOneDynamicIdentifier'] = str(self.MaxSourcesforOneDynamicIdentifier);
        root.append(nd); 
    def parse(self, nd):
        self.DevErrorDetection = bool(nd.attrib['DevErrorDetection']);
        self.VersionInfoApi = bool(nd.attrib['VersionInfoApi']);
        self.RespondAllRequest = bool(nd.attrib['RespondAllRequest']);
        self.MainFunctionPeriod = int(nd.attrib['MainFunctionPeriod']);
        self.ResponsePending = bool(nd.attrib['ResponsePending']);
        self.MaxNegativeResponse = int(nd.attrib['MaxNegativeResponse']);
        self.MaxNumberofSimultaneousPeriodictransmissions = int(nd.attrib['MaxNumberofSimultaneousPeriodictransmissions']);
        self.PeriodicTransmissionSlow = int(nd.attrib['PeriodicTransmissionSlow']);
        self.PeriodicTransmissionMedium = int(nd.attrib['PeriodicTransmissionMedium']);
        self.PeriodicTransmissionFast = int(nd.attrib['PeriodicTransmissionFast']);
        self.MaxSourcesforOneDynamicIdentifier = int(nd.attrib['MaxSourcesforOneDynamicIdentifier']);

class DcmBuffer():
    def __init__(self, name):
        self.name = name;
        self.size = 8; #bytes
    def save(self, root):
        nd = ET.Element('DcmBuffer');
        nd.attrib['name'] = str(self.name);
        nd.attrib['size'] = str(self.size);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.size = int(nd.attrib['size']);
class DcmDidInfoControlAccess():
    def __init__(self, name):
        self.name = name;
        self.DspDidFreezeCurrentState = False;
        self.DspDidFreezeCurrentStateRef = 'NULL';
        self.DspDidResetToDefault = False;
        self.DspDidResetToDefaultRef = 'NULL';
        self.DspDidReturnControlToEcu = False;
        self.DspDidReturnControlToEcuRef = 'NULL';
        self.DspDidShortTermAdjustment = False;
        self.DspDidShortTermAdjustmentRef = 'NULL';
        self.sessionRefList = [];
        self.securityRefList = [];
    def save(self, root):
        nd = ET.Element('DcmDidInfoControlAccess');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DspDidFreezeCurrentState'] = str(self.DspDidFreezeCurrentState);
        nd.attrib['DspDidFreezeCurrentStateRef'] = str(self.DspDidFreezeCurrentStateRef);
        nd.attrib['DspDidResetToDefault'] = str(self.DspDidResetToDefault);
        nd.attrib['DspDidResetToDefaultRef'] = str(self.DspDidResetToDefaultRef);
        nd.attrib['DspDidReturnControlToEcu'] = str(self.DspDidReturnControlToEcu);
        nd.attrib['DspDidReturnControlToEcuRef'] = str(self.DspDidReturnControlToEcuRef);
        nd.attrib['DspDidShortTermAdjustment'] = str(self.DspDidShortTermAdjustment);
        nd.attrib['DspDidShortTermAdjustmentRef'] = str(self.DspDidShortTermAdjustmentRef);
        snd = ET.Element('sessionRefList')
        for ses in self.sessionRefList:
            nd2 = ET.Element('SessionRef')
            nd2.attrib['value'] = str(ses);
            snd.append(nd2);
        nd.append(snd);
        snd = ET.Element('securityRefList')
        for sec in self.securityRefList:
            nd2 = ET.Element('SecurityRef')
            nd2.attrib['value'] = str(sec);
            snd.append(nd2);
        nd.append(snd);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.DspDidFreezeCurrentState = bool(nd.attrib['DspDidFreezeCurrentState']);
        self.DspDidFreezeCurrentStateRef = nd.attrib['DspDidFreezeCurrentStateRef'];
        self.DspDidResetToDefault = bool(nd.attrib['DspDidResetToDefault']);
        self.DspDidResetToDefaultRef = nd.attrib['DspDidResetToDefaultRef'];
        self.DspDidReturnControlToEcu = bool(nd.attrib['DspDidReturnControlToEcu']);
        self.DspDidReturnControlToEcuRef = nd.attrib['DspDidReturnControlToEcuRef'];
        self.DspDidShortTermAdjustment = bool(nd.attrib['DspDidShortTermAdjustment']);
        self.DspDidShortTermAdjustmentRef = nd.attrib['DspDidShortTermAdjustmentRef'];
        for nd1 in nd.find('sessionRefList'):
            self.sessionRefList.append(nd1.attrib['value']);
        for nd1 in nd.find('securityRefList'):
            self.securityRefList.append(nd1.attrib['value']);
class  DcmDidInfoReadAccess():
    def __init__(self, name):
        self.name = name;
        self.sessionRefList = [];
        self.securityRefList = [];
    def save(self, root):
        nd = ET.Element('DcmDidInfoControlAccess');
        nd.attrib['name'] = str(self.name);
        snd = ET.Element('sessionRefList')
        for ses in self.sessionRefList:
            nd2 = ET.Element('SessionRef')
            nd2.attrib['value'] = str(ses);
            snd.append(nd2);
        nd.append(snd);
        snd = ET.Element('securityRefList')
        for sec in self.securityRefList:
            nd2 = ET.Element('SecurityRef')
            nd2.attrib['value'] = str(sec);
            snd.append(nd2);
        nd.append(snd);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        for nd1 in nd.find('sessionRefList'):
            self.sessionRefList.append(nd1.attrib['value']);
        for nd1 in nd.find('securityRefList'):
            self.securityRefList.append(nd1.attrib['value']);
class  DcmDidInfoWriteAccess():
    def __init__(self, name):
        self.name = name;
        self.sessionRefList = [];
        self.securityRefList = [];
    def save(self, root):
        nd = ET.Element('DcmDidInfoControlAccess');
        nd.attrib['name'] = str(self.name);
        snd = ET.Element('sessionRefList')
        for ses in self.sessionRefList:
            nd2 = ET.Element('SessionRef')
            nd2.attrib['value'] = str(ses);
            snd.append(nd2);
        nd.append(snd);
        snd = ET.Element('securityRefList')
        for sec in self.securityRefList:
            nd2 = ET.Element('SecurityRef')
            nd2.attrib['value'] = str(sec);
            snd.append(nd2);
        nd.append(snd);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        for nd1 in nd.find('sessionRefList'):
            self.sessionRefList.append(nd1.attrib['value']);
        for nd1 in nd.find('securityRefList'):
            self.securityRefList.append(nd1.attrib['value']);
class DcmDidInfo():
    def __init__(self, name):
        self.name = name;
        self.FixedLength = True;
        self.DynamicllyDefined = False;
        self.ScalingEnable = False;
        self.ScalingInfoSize = 8;
        self.ControlAccessList = [];
        self.ReadAccessList = [];
        self.WriteAccessList = [];
    def save(self, root):
        nd = ET.Element('DcmDidInfo');
        nd.attrib['name'] = str(self.name);
        nd.attrib['FixedLength'] = str(self.FixedLength);
        nd.attrib['DynamicllyDefined'] = str(self.DynamicllyDefined);
        nd.attrib['ScalingEnable'] = str(self.ScalingEnable);
        nd.attrib['ScalingInfoSize'] = str(self.ScalingInfoSize);
        nd2 = ET.Element('ControlAccessList');
        for obj in self.ControlAccessList:
            obj.save(nd2);
        nd.append(nd2);
        nd2 = ET.Element('ReadAccessList');
        for obj in self.ReadAccessList:
            obj.save(nd2);
        nd.append(nd2);
        nd2 = ET.Element('WriteAccessList');
        for obj in self.WriteAccessList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.FixedLength = bool(nd.attrib['FixedLength']);
        self.DynamicllyDefined = bool(nd.attrib['DynamicllyDefined']);
        self.ScalingEnable = bool(nd.attrib['ScalingEnable']);
        self.ScalingInfoSize = int(nd.attrib['ScalingInfoSize']);
        for nd2 in nd.find('ControlAccessList'):
            obj = DcmDidInfoControlAccess('');
            obj.parse(nd2);
            self.ControlAccessList.append(obj);
        for nd2 in nd.find('ReadAccessList'):
            obj = DcmDidInfoReadAccess('');
            obj.parse(nd2);
            self.ReadAccessList.append(obj);
        for nd2 in nd.find('WriteAccessList'):
            obj = DcmDidInfoWriteAccess('');
            obj.parse(nd2);
            self.WriteAccessList.append(obj);
class DcmDID():
    def __init__(self, name, id):
        self.name = name;
        self.id = id;
        self.size = 64;
        self.didInfoRef = '';
        self.didRef = ''; #I cann't understand 
        self.usePort = False; #for interaction with RTE, not supported now.
        #------ so callback info not configured ...
    def save(self, root):
        nd = ET.Element('DcmDID');
        nd.attrib['name'] = str(self.name);
        nd.attrib['id'] = str(self.id);
        nd.attrib['size'] = str(self.size);
        nd.attrib['didInfoRef'] = str(self.didInfoRef);
        nd.attrib['usePort'] = str(self.usePort);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.id = str(nd.attrib['id']);
        self.size = int(nd.attrib['size']);
        self.didInfoRef = str(nd.attrib['didInfoRef']);
        self.usePort = bool(nd.attrib['usePort']);
class DcmRxChannel():
    def __init__(self, name):
        self.name = name;
        self.RxAddrType = 'DCM_PROTOCOL_PHYSICAL_ADDR_TYPE';
        self.RxPdu = ''
    def save(self, root):
        nd  = ET.Element('DcmRxChannel');
        nd.attrib['name'] = str(self.name);
        nd.attrib['RxAddrType'] = str(self.RxAddrType);
        nd.attrib['RxPdu'] = str(self.RxPdu);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.RxAddrType = nd.attrib['RxAddrType'];
        self.RxPdu = nd.attrib['RxPdu'];
        
class DcmTxChannel():
    def __init__(self, name):
        self.name = name;
        self.TxPdu = ''
    def save(self, root):
        nd  = ET.Element('DcmTxChannel');
        nd.attrib['name'] = str(self.name);
        nd.attrib['TxPdu'] = str(self.TxPdu);
        root.append(nd)
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.TxPdu = nd.attrib['TxPdu'];
class DcmConnection():
    def __init__(self, name):
        self.name = name;
        self.RxChannelList = [];
        self.TxChannelList = [];
    def save(self, root):
        nd = ET.Element('DcmConnection');
        nd.attrib['name'] = str(self.name);
        
        nd2 = ET.Element('RxChannelList');
        for obj in self.RxChannelList:
            obj.save(nd2);
        nd.append(nd2);
        
        nd2 = ET.Element('TxChannelList');
        for obj in self.TxChannelList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        for nd2 in nd.find('RxChannelList'):
            obj = DcmRxChannel('');
            obj.parse(nd2);
            self.RxChannelList.append(obj);
        for nd2 in nd.find('TxChannelList'):
            obj = DcmTxChannel('');
            obj.parse(nd2);
            self.TxChannelList.append(obj);
class DcmProtocol():
    def __init__(self, name):
        self.name = name;
        self.ProtocolId = 'DCM_UDS_ON_CAN';
        self.TransType = 'DCM_PROTOCOL_TRANS_TYPE_1';
        self.RxBufferID = '';
        self.TxBufferID = '';
        self.TimeLimit = '';
        self.ServiceTable = '';
        self.ConnectionList = [];
    def save(self, root):
        nd = ET.Element('DcmProtocol');
        nd.attrib['name'] = str(self.name);
        nd.attrib['ProtocolId'] = str(self.ProtocolId);
        nd.attrib['TransType'] = str(self.TransType);
        nd.attrib['RxBufferID'] = str(self.RxBufferID);
        nd.attrib['TxBufferID'] = str(self.TxBufferID);
        nd.attrib['TimeLimit'] = str(self.TimeLimit);
        nd.attrib['ServiceTable'] = str(self.ServiceTable);
        nd2 = ET.Element('ConnectionList');
        for obj in self.ConnectionList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = str(nd.attrib['name']);
        self.ProtocolId = str(nd.attrib['ProtocolId']);
        self.TransType = str(nd.attrib['TransType']);
        self.RxBufferID = str(nd.attrib['RxBufferID']);
        self.TxBufferID = str(nd.attrib['TxBufferID']);
        self.TimeLimit = str(nd.attrib['TimeLimit']);
        self.ServiceTable = str(nd.attrib['ServiceTable']);
        for nd2 in nd.find('ConnectionList'):
            obj = DcmConnection('')
            obj.parse(nd2);
            self.ConnectionList.append(obj)
class DcmRequestService():
        def __init__(self, name):
            self.name = name;
            self.start = 'NULL';    # StartProtocol callback 
            self.stop  = 'NULL';    # StopProtocol callback
        def save(self, root):
            nd = ET.Element('DcmRequestService');
            nd.attrib['name'] = str(self.name);
            nd.attrib['start'] = str(self.start);
            nd.attrib['stop'] = str(self.stop);
            root.append(nd);
        def parse(self, nd):
            self.name = nd.attrib['name'];
            self.start = nd.attrib['start'];
            self.stop = nd.attrib['stop'];
class DcmSecurityLevel():
    def __init__(self, name):
        self.name = name;
        self.level = 0;
        self.recordSize = 1;
        self.seedSize = 1;
        self.keySize = 1;
        self.getSeedCbk = 'NULL';
        self.compKeyCbk = 'NULL';
    def save(self, root):
        nd = ET.Element('DcmSecurityLevel');
        nd.attrib['name'] = str(self.name);
        nd.attrib['level'] = str(self.level);
        nd.attrib['recordSize'] = str(self.recordSize);
        nd.attrib['seedSize'] = str(self.seedSize);
        nd.attrib['keySize'] = str(self.keySize);
        nd.attrib['getSeedCbk'] = str(self.getSeedCbk);
        nd.attrib['compKeyCbk'] = str(self.compKeyCbk);
        root.append(nd);
    def parse(self, nd):
        self.name = str(nd.attrib['name']);
        self.level = int(nd.attrib['level']);
        self.recordSize = int(nd.attrib['recordSize']);
        self.seedSize = int(nd.attrib['seedSize']);
        self.keySize = int(nd.attrib['keySize']);
        self.getSeedCbk = str(nd.attrib['getSeedCbk']);
        self.compKeyCbk = str(nd.attrib['compKeyCbk']);
class DcmService():
    def __init__(self, name):
        self.name = name;
        self.serviceId = '';
        self.subfuncAvail = False;
        self.securityRefList = [];
        self.sessionRefList = [];
    def save(self, root):
        nd = ET.Element('DcmService');
        nd.attrib['name'] = str(self.name);
        nd.attrib['serviceId'] = str(self.serviceId);
        nd.attrib['subfuncAvail'] = str(self.subfuncAvail);
        snd = ET.Element('sessionRefList')
        for ses in self.sessionRefList:
            nd2 = ET.Element('SessionRef')
            nd2.attrib['value'] = str(ses);
            snd.append(nd2);
        nd.append(snd);
        snd = ET.Element('securityRefList')
        for sec in self.securityRefList:
            nd2 = ET.Element('SecurityRef')
            nd2.attrib['value'] = str(sec);
            snd.append(nd2);
        nd.append(snd);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.serviceId = nd.attrib['serviceId'];
        self.subfuncAvail = bool(nd.attrib['subfuncAvail']);
        for nd1 in nd.find('sessionRefList'):
            self.sessionRefList.append(nd1.attrib['value']);
        for nd1 in nd.find('securityRefList'):
            self.securityRefList.append(nd1.attrib['value']);
class DcmServiceTable():
    def __init__(self, name):
        self.name = name;
        self.serviceList = [];
    def save(self, root):
        nd = ET.Element('DcmServiceTable');
        nd.attrib['name'] = str(self.name);
        nd2 = ET.Element('DcmServiceList');
        for obj in self.serviceList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        
        for nd2 in nd.find('DcmServiceList'):
            obj = DcmService('');
            obj.parse(nd2);
            self.serviceList.append(obj);
class DcmSessionControl():
    def __init__(self, name):
        self.name = name;
        self.GetSesChgPermission = 'NULL'
    def save(self, root):
        nd = ET.Element('DcmServiceTable');
        nd.attrib['name'] = str(self.name);
        nd.attrib['GetSesChgPermission'] = str(self.GetSesChgPermission);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.GetSesChgPermission = nd.attrib['GetSesChgPermission'];
class DcmSession():
    def __init__(self, name):
        self.name = name;
    def save(self, root):
        nd = ET.Element('DcmServiceTable');
        nd.attrib['name'] = str(self.name);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
class DcmTiming():
    def __init__(self, name):
        self.name = name;
        self.P2ServerMax = 0; #ms
        self.P2ServerMin = 0; 
        self.S3Server = 0;
    def save(self, root):
        nd = ET.Element('DcmServiceTable');
        nd.attrib['name'] = str(self.name);
        nd.attrib['P2ServerMax'] = str(self.P2ServerMax);
        nd.attrib['P2ServerMin'] = str(self.P2ServerMin);
        nd.attrib['S3Server'] = str(self.S3Server);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.P2ServerMax = int(nd.attrib['P2ServerMax']);
        self.P2ServerMin = int(nd.attrib['P2ServerMin']);
        self.S3Server = int(nd.attrib['S3Server']);
class gainos_tk_dcm_obj():
    def __init__(self):
        self.general = DcmGeneral();
        self.bufferList = [];
        self.didInfoList = [];
        self.didList = [];
        self.protocolList = [];
        self.requestServiceList = [];
        self.securityLevelList = [];
        self.serviceTableList = [];
        self.sessionControlList = [];
        self.sessionList = [];
        self.timingList = [];
        
    def save(self, root):
        self.general.save(root);
        
        nd = ET.Element('DcmBufferList');
        for obj in self.bufferList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmDidInfoList');
        for obj in self.didInfoList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmDIDList');
        for obj in self.didList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmProtocolList');
        for obj in self.protocolList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmRequestServiceList');
        for obj in self.requestServiceList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmSecurityLevelList');
        for obj in self.securityLevelList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmServiceTableList');
        for obj in self.serviceTableList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmSessionControlList');
        for obj in self.sessionControlList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmSessionList');
        for obj in self.sessionList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmTimingList');
        for obj in self.timingList:
            obj.save(nd);
        root.append(nd);
        
    def parse(self, root):
        self.general.parse(root.find("General"));
  
        for nd in root.find('DcmBufferList'):
            obj = DcmBuffer('');
            obj.parse(nd);
            self.bufferList.append(obj);

        for nd in root.find('DcmDidInfoList'):
            obj = DcmDidInfo('');
            obj.parse(nd);
            self.didInfoList.append(obj);
            
        for nd in root.find('DcmDIDList'):
            obj = DcmDID('', 0);
            obj.parse(nd);
            self.didList.append(obj);

        for nd in root.find('DcmProtocolList'):
            obj = DcmProtocol('');
            obj.parse(nd);
            self.protocolList.append(obj);

        for nd in root.find('DcmRequestServiceList'):
            obj = DcmRequestService('');
            obj.parse(nd);
            self.requestServiceList.append(obj);

        for nd in root.find('DcmSecurityLevelList'):
            obj = DcmSecurityLevel('');
            obj.parse(nd);
            self.securityLevelList.append(obj);

        for nd in root.find('DcmServiceTableList'):
            obj = DcmServiceTable('');
            obj.parse(nd);
            self.serviceTableList.append(obj);

        for nd in root.find('DcmSessionControlList'):
            obj = DcmSessionControl('');
            obj.parse(nd);
            self.sessionControlList.append(obj);

        for nd in root.find('DcmSessionList'):
            obj = DcmSession('');
            obj.parse(nd);
            self.sessionList.append(obj);

        for nd in root.find('DcmTimingList'):
            obj = DcmTiming('');
            obj.parse(nd);
            self.timingList.append(obj);
        
class gainos_tk_dcm_cfg():
    def __init__(self, chip=None):
        self.cfg = gainos_tk_dcm_obj();

    def toString(self):
        str='Dcm!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_dcm import cd_dcm
        from PyQt4.QtGui import QMessageBox
        depinfo=[];
        md=gcfindModule(module_list, 'EcuC');
        if(md==None):
            QMessageBox(QMessageBox.Information, 'GaInOS Info', 
                'Please Configure EcuC Firstly!').exec_();
            return;
        depinfo.append(md.obj);
        self.dlg  = cd_dcm(title, fileInd, self.cfg, depinfo);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        self.cfg.save(root);
    
    def parse(self, root):
        self.cfg.parse(root);

    def gen(self, path):
        self.codeGenH(path);
        self.codeGenC(path);
    
    def codeGenH(self, path):
        fp = open(path+'/Dcm_Cfg.h', 'w');
        fp.write(gcGainOS_TkHead());
        fp.write('#ifndef DCM_CFG_H_\n#define DCM_CFG_H_\n\n');
        #-------------------------------------------------------
        fp.write('#define DCM_VERSION_INFO_API              %s\n'%(gSTD_ON(self.cfg.general.VersionInfoApi)))
        fp.write('#define DCM_DEV_ERROR_DETECT              %s\n'%(gSTD_ON(self.cfg.general.DevErrorDetection)))
        fp.write('#define DCM_RESPOND_ALL_REQUEST           %s  // Activate/Deactivate response on SID 0x40-0x7f and 0xc0-0xff.\n'%(gSTD_ON(self.cfg.general.RespondAllRequest)))
        fp.write('#define DCM_REQUEST_INDICATION_ENABLED    STD_ON  // Activate/Deactivate indication request mechanism.\n');
        fp.write('#define DCM_PAGEDBUFFER_ENABLED           STD_OFF	// Enable/disable page buffer mechanism (currently only disabled supported)\n\n')
        fp.write('#define DCM_DSL_BUFFER_LIST_LENGTH		%s\n'%(len(self.cfg.bufferList)));
        lengthRx = lengthTx =0;
        for protocol in self.cfg.protocolList:
            for connection in protocol.ConnectionList:
                lengthRx += len(connection.RxChannelList);
                lengthTx += len(connection.TxChannelList);
        fp.write('#define DCM_DSL_TX_PDU_ID_LIST_LENGTH		%s\n'%(lengthTx));
        fp.write('#define DCM_DSL_RX_PDU_ID_LIST_LENGTH		%s\n\n'%(lengthRx));
        fp.write('#define DCM_MAIN_FUNCTION_PERIOD_TIME_MS	%s\n\n'%(self.cfg.general.MainFunctionPeriod));
        fp.write('#define DCM_LIMITNUMBER_PERIODDATA		%s  //MaxNumberofSimultaneousPeriodictransmissions\n'%(self.cfg.general.MaxNumberofSimultaneousPeriodictransmissions));
        fp.write('#define DCM_MAX_DDDSOURCE_NUMBER			%s  //MaxSourcesforOneDynamicIdentifier\n'%(self.cfg.general.MaxSourcesforOneDynamicIdentifier));
        fp.write('#define DCM_MAX_DDD_NUMBER				%s  //MaxNegativeResponse\n\n'%(self.cfg.general.MaxNegativeResponse));
        fp.write('#define DCM_PERIODICTRANSMIT_SLOW			%s\n'%(self.cfg.general.PeriodicTransmissionSlow));
        fp.write('#define DCM_PERIODICTRANSMIT_MEDIUM		%s\n'%(self.cfg.general.PeriodicTransmissionMedium));
        fp.write('#define DCM_PERIODICTRANSMIT_FAST			%s\n\n'%(self.cfg.general.PeriodicTransmissionFast));
        id = 0;
        for protocol in self.cfg.protocolList:
            for connection in protocol.ConnectionList:
                for rx in connection.RxChannelList:
                    fp.write('#define DCM_%s %s\n'%(rx.RxPdu,id));
                    id += 1;
        fp.write('\n')
        id = 0;
        for protocol in self.cfg.protocolList:
            for connection in protocol.ConnectionList:
                for tx in connection.TxChannelList:
                    fp.write('#define DCM_%s %s\n'%(tx.TxPdu,id));
                    id += 1;
        #-------------------------------------------------------
        fp.write('#endif /*DCM_CFG_H_*/\n\n')
        fp.close();
    def codeGenC(self, path):
        fp = open(path+'/Dcm_LCfg.c', 'w');
        fp.write(gcGainOS_TkHead());
        #------------------------------------------------------------------
        fp.write("""#include "Std_Types.h"
#include "Dcm.h"
#if defined(USE_PDUR)
#include "PduR.h"
#endif\n\n""");
        fp.write('#define DCM_SECURITY_EOL_INDEX %s\n'%(len(self.cfg.securityLevelList)));
        fp.write('#define DCM_SESSION_EOL_INDEX %s\n'%(len(self.cfg.sessionList)));
        fp.write('#define DCM_DID_LIST_EOL_INDEX %s\n\n'%(len(self.cfg.didList)));
        for sec in self.cfg.securityLevelList:
            if(sec.getSeedCbk != 'NULL'):
                fp.write('extern Std_ReturnType %s (uint8 *securityAccessDataRecord, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode);\n'%(sec.getSeedCbk));
            if(sec.compKeyCbk != 'NULL'):
                fp.write('extern Std_ReturnType %s (uint8 *key);\n'%(sec.compKeyCbk));
        for req in self.cfg.requestServiceList:
            if(req.start != 'NULL'):
                fp.write('extern Std_ReturnType %s (Dcm_ProtocolType protocolID);\n'%(req.start))
            if(req.stop != 'NULL'):
                fp.write('extern Std_ReturnType %s (Dcm_ProtocolType protocolID);\n\n'%(req.stop))
        # -=-=-==------- Security Level
        if(len(self.cfg.securityLevelList)):
            str = 'const Dcm_DspSecurityRowType DspSecurityList[] = {\n'
            for sec in self.cfg.securityLevelList:
                str += '\t{ // %s\n'%(sec.name);
                str += '\t\t/* DspSecurityLevel = */ %s,\n'%(sec.level);
                str += '\t\t/* DspSecurityDelayTimeOnBoot = */ 0,/* Value is not configurable */\n';
                str += '\t\t/* DspSecurityNumAttDelay = */ 0, 	/* Value is not configurable */\n';
                str += '\t\t/* DspSecurityDelayTime = */ 0, 	/* Value is not configurable */\n';
                str += '\t\t/* DspSecurityNumAttLock = */ 0, 	/* Value is not configurable */\n';
                str += '\t\t/* DspSecurityADRSize = */ %s,\n'%(sec.recordSize);
                str += '\t\t/* DspSecuritySeedSize = */ %s,\n'%(sec.seedSize);
                str += '\t\t/* DspSecurityKeySize = */ %s,\n'%(sec.keySize);
                str += '\t\t/* GetSeed = */ %s,\n'%(sec.getSeedCbk);
                str += '\t\t/* CompareKey = */ %s,\n'%(sec.compKeyCbk);
                str += '\t\t/* Arc_EOL = */ FALSE\n';
                str += '\t},\n';
            str += '\t{ // %s\n'%('Dummy For EOL');
            str += '\t\t/* DspSecurityLevel = */ %s,\n'%('0xBD');
            str += '\t\t/* DspSecurityDelayTimeOnBoot = */ 0,/* Value is not configurable */\n';
            str += '\t\t/* DspSecurityNumAttDelay = */ 0, 	/* Value is not configurable */\n';
            str += '\t\t/* DspSecurityDelayTime = */ 0, 	/* Value is not configurable */\n';
            str += '\t\t/* DspSecurityNumAttLock = */ 0, 	/* Value is not configurable */\n';
            str += '\t\t/* DspSecurityADRSize = */ %s,\n'%('0xBD');
            str += '\t\t/* DspSecuritySeedSize = */ %s,\n'%('0xBD');
            str += '\t\t/* DspSecurityKeySize = */ %s,\n'%('0xBD');
            str += '\t\t/* GetSeed = */ %s,\n'%('NULL');
            str += '\t\t/* CompareKey = */ %s,\n'%('NULL');
            str += '\t\t/* Arc_EOL = */ TRUE\n';
            str += '\t}\n';
            str += '};\n\n'
            fp.write(str);
            fp.write("""const Dcm_DspSecurityType DspSecurity = {
    /* DspSecurityRow = */ DspSecurityList
};\n""");
        #-------------------------- Session -------------
        if(len(self.cfg.sessionList)):
            str = 'const Dcm_DspSessionRowType DspSessionList[] = {\n';
            for ses in self.cfg.sessionList:
                str +='\t{ //%s\n'%(ses.name);
                str +='\t\t/* DspSessionLevel = */ %s,\n'%('???');
                str +='\t\t/* DspSessionP2ServerMax = */ %s,\n'%('???');
                str +='\t\t/* DspSessionP2StarServerMax = */ %s,\n'%('???');
                str +='\t\t/* Arc_EOL = */ %s\n'%('FALSE');
                str +='\t},\n';
            str +='\t{ //%s\n'%('Dummy Session For EOL');
            str +='\t\t/* DspSessionLevel = */ %s,\n'%('???');
            str +='\t\t/* DspSessionP2ServerMax = */ %s,\n'%('???');
            str +='\t\t/* DspSessionP2StarServerMax = */ %s,\n'%('???');
            str +='\t\t/* Arc_EOL = */ %s\n'%('TRUE');
            str +='\t},\n';
            str += '};\n\n';
            fp.write(str);
        #----------------- Service Table ---------------
        for sertbl in self.cfg.serviceTableList:
            for ser in sertbl.serviceList:
                str = 'const Dcm_DspSessionRowType *%s_%s_SessionList[] = {\n'%(sertbl.name, ser.name);
                for ses in ser.sessionRefList:
                    str += '\t&DspSessionList[%s],//%s\n'%(gcfindIndex(self.cfg.sessionList, ses), ses);
                str += '\t&DspSessionList[DCM_SESSION_EOL_INDEX]\n};\n'
                fp.write(str);
        #------------------------------------------------------------------
        fp.close();
