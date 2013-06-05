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
        self.DynamicIdentifierNr = 10;
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
        nd.attrib['DynamicIdentifierNr'] = str(self.DynamicIdentifierNr);
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
        self.DynamicIdentifierNr = int(nd.attrib['DynamicIdentifierNr']);

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
        #---------- TODO: add Did Reference List
        self.didRef = ''; #not supported by tool,but implemented by arccore 
        self.usePort = False; #for interaction with RTE, not supported now.
        self.DspDidReadDataLengthFnc = '%s_ReadDataLength_Cbk'%(name)
        self.DspDidConditionCheckReadFnc = '%s_ConditionCheckRead_Cbk'%(name)
        self.DspDidReadDataFnc = '%s_ReadData_Cbk'%(name)
        self.DspDidConditionCheckWriteFnc = '%s_ConditionCheckWrite_Cbk'%(name)
        self.DspDidWriteDataFnc = '%s_WriteData_Cbk'%(name)
        self.DspDidGetScalingInfoFnc = '%s_GetScalingInfo_Cbk'%(name)
        self.DspDidFreezeCurrentStateFnc = 'NULL'
        self.DspDidResetToDefaultFnc = 'NULL'
        self.DspDidReturnControlToEcuFnc = 'NULL'
        self.DspDidShortTermAdjustmentFnc = 'NULL'
        self.DspDidControlRecordSize = 'NULL'
    def save(self, root):
        nd = ET.Element('DcmDID');
        nd.attrib['name'] = str(self.name);
        nd.attrib['id'] = str(self.id);
        nd.attrib['size'] = str(self.size);
        nd.attrib['didInfoRef'] = str(self.didInfoRef);
        nd.attrib['usePort'] = str(self.usePort);
        nd.attrib['DspDidReadDataLengthFnc'] = str(self.DspDidReadDataLengthFnc);
        nd.attrib['DspDidConditionCheckReadFnc'] = str(self.DspDidConditionCheckReadFnc);
        nd.attrib['DspDidReadDataFnc'] = str(self.DspDidReadDataFnc);
        nd.attrib['DspDidConditionCheckWriteFnc'] = str(self.DspDidConditionCheckWriteFnc);
        nd.attrib['DspDidWriteDataFnc'] = str(self.DspDidWriteDataFnc);
        nd.attrib['DspDidGetScalingInfoFnc'] = str(self.DspDidGetScalingInfoFnc);
        nd.attrib['DspDidFreezeCurrentStateFnc'] = str(self.DspDidFreezeCurrentStateFnc);
        nd.attrib['DspDidResetToDefaultFnc'] = str(self.DspDidResetToDefaultFnc);
        nd.attrib['DspDidReturnControlToEcuFnc'] = str(self.DspDidReturnControlToEcuFnc);
        nd.attrib['DspDidShortTermAdjustmentFnc'] = str(self.DspDidShortTermAdjustmentFnc);
        nd.attrib['DspDidControlRecordSize'] = str(self.DspDidControlRecordSize);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.id = str(nd.attrib['id']);
        self.size = int(nd.attrib['size']);
        self.didInfoRef = str(nd.attrib['didInfoRef']);
        self.usePort = bool(nd.attrib['usePort']);
        self.DspDidReadDataLengthFnc = str(nd.attrib['DspDidReadDataLengthFnc']);
        self.DspDidConditionCheckReadFnc = str(nd.attrib['DspDidConditionCheckReadFnc']);
        self.DspDidReadDataFnc = str(nd.attrib['DspDidReadDataFnc']);
        self.DspDidConditionCheckWriteFnc = str(nd.attrib['DspDidConditionCheckWriteFnc']);
        self.DspDidWriteDataFnc = str(nd.attrib['DspDidWriteDataFnc']);
        self.DspDidGetScalingInfoFnc = str(nd.attrib['DspDidGetScalingInfoFnc']);
        self.DspDidFreezeCurrentStateFnc = str(nd.attrib['DspDidFreezeCurrentStateFnc']);
        self.DspDidResetToDefaultFnc = str(nd.attrib['DspDidResetToDefaultFnc']);
        self.DspDidReturnControlToEcuFnc = str(nd.attrib['DspDidReturnControlToEcuFnc']);
        self.DspDidShortTermAdjustmentFnc = str(nd.attrib['DspDidShortTermAdjustmentFnc']);
        self.DspDidControlRecordSize = str(nd.attrib['DspDidControlRecordSize']);
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
            self.indication  = 'NULL';    # indication callback
        def save(self, root):
            nd = ET.Element('DcmRequestService');
            nd.attrib['name'] = str(self.name);
            nd.attrib['start'] = str(self.start);
            nd.attrib['stop'] = str(self.stop);
            nd.attrib['indication'] = str(self.indication);
            root.append(nd);
        def parse(self, nd):
            self.name = nd.attrib['name'];
            self.start = nd.attrib['start'];
            self.stop = nd.attrib['stop'];
            self.indication = nd.attrib['indication'];
class DcmSecurityLevel():
    def __init__(self, name):
        self.name = name;
        self.level = 0;
        self.recordSize = 0;    #must be ZERO
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
        self.level = 1; #default session
        self.P2ServerMax = 10; #ms
        self.P2StarServerMax = 10; #ms
    def save(self, root):
        nd = ET.Element('DcmServiceTable');
        nd.attrib['name'] = str(self.name);
        nd.attrib['level'] = str(self.level);
        nd.attrib['P2ServerMax'] = str(self.P2ServerMax);
        nd.attrib['P2StarServerMax'] = str(self.P2StarServerMax);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.level = int(nd.attrib['level']);
        self.P2ServerMax = int(nd.attrib['P2ServerMax']);
        self.P2StarServerMax = int(nd.attrib['P2StarServerMax']);
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
class DcmRoutineInfoAuthorization():
    def __init__(self, name):
        self.name = name;
        self.sessionRefList = []
        self.securityRefList = []
    def save(self, root):
        nd = ET.Element('DcmRoutineInfoAuthorization');
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
class DcmRoutineInfoStart():
    def __init__(self, name):
        self.name = name;  
        self.DspStartRoutineCtrlOptRecSize = 0; # Routine Option Parameter For Start
        self.DspStartRoutineStsOptRecSize = 0;  # Routine Option Response Result For Start
    def save(self, root):
        nd = ET.Element('DcmRoutineInfoStart');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DspStartRoutineCtrlOptRecSize'] = str(self.DspStartRoutineCtrlOptRecSize);
        nd.attrib['DspStartRoutineStsOptRecSize'] = str(self.DspStartRoutineStsOptRecSize);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.DspStartRoutineCtrlOptRecSize = int(nd.attrib['DspStartRoutineCtrlOptRecSize']);
        self.DspStartRoutineStsOptRecSize = int(nd.attrib['DspStartRoutineStsOptRecSize']);
class DcmRoutineInfoStop():
    def __init__(self, name):
        self.name = name;  
        self.DspStopRoutineCtrlOptRecSize = 0;
        self.DspStopRoutineStsOptRecSize = 0;
    def save(self, root):
        nd = ET.Element('DcmRoutineInfoStop');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DspStopRoutineCtrlOptRecSize'] = str(self.DspStopRoutineCtrlOptRecSize);
        nd.attrib['DspStopRoutineStsOptRecSize'] = str(self.DspStopRoutineStsOptRecSize);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.DspStopRoutineCtrlOptRecSize = int(nd.attrib['DspStopRoutineCtrlOptRecSize']);
        self.DspStopRoutineStsOptRecSize = int(nd.attrib['DspStopRoutineStsOptRecSize']);
class DcmRoutineInfoRequest():
    def __init__(self, name):
        self.name = name;  
        self.DspReqResRtnCtrlOptRecSize = 0  # respones record size
    def save(self, root):
        nd = ET.Element('DcmService');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DspReqResRtnCtrlOptRecSize'] = str(self.DspReqResRtnCtrlOptRecSize);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.DspReqResRtnCtrlOptRecSize = int(nd.attrib['DspReqResRtnCtrlOptRecSize']);
class DcmRoutineInfo():
    def __init__(self, name):
        self.name = name;
        self.AuthorizationList = [];#最多仅有一个元素
        self.StartList = [];#最多仅有一个元素
        self.StopList = [];#最多仅有一个元素
        self.RequestList = [];#最多仅有一个元素
    def save(self, root):
        nd = ET.Element('DcmRoutineInfo');
        nd.attrib['name'] = str(self.name);
        nd2 = ET.Element('AuthorizationList');
        for obj in self.AuthorizationList:
            obj.save(nd2)
        nd.append(nd2);
        
        nd2 = ET.Element('StartList');
        for obj in self.StartList:
            obj.save(nd2)
        nd.append(nd2);
        
        nd2 = ET.Element('StopList');
        for obj in self.StopList:
            obj.save(nd2)
        nd.append(nd2);
        
        nd2 = ET.Element('RequestList');
        for obj in self.RequestList:
            obj.save(nd2)
        nd.append(nd2);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name']

        for nd2 in nd.find('AuthorizationList'):
            obj = DcmRoutineInfoAuthorization('');
            obj.parse(nd2);
            self.AuthorizationList.append(obj);
        
        for nd2 in nd.find('StartList'):
            obj = DcmRoutineInfoStart('');
            obj.parse(nd2);
            self.StartList.append(obj);
        
        for nd2 in nd.find('StopList'):
            obj = DcmRoutineInfoStop('');
            obj.parse(nd2);
            self.StopList.append(obj);
        
        for nd2 in nd.find('RequestList'):
            obj = DcmRoutineInfoRequest('');
            obj.parse(nd2);
            self.RequestList.append(obj);
            
class DcmRoutine():
    def __init__(self, name, id):
        self.name = name;
        self.DspRoutineUsePort = False;
        self.DspRoutineIdentifier = '%s'%(hex(id));
        self.DspRoutineInfoRef = ''
        self.DspStartRoutineFnc =  'NULL'
        self.DspStopRoutineFnc =  'NULL'
        self.DspRequestResultRoutineFnc = 'NULL'
    def save(self, root):
        nd = ET.Element('DcmRoutineInfo');
        nd.attrib['name'] = str(self.name);
        nd.attrib['DspRoutineUsePort'] = str(self.DspRoutineUsePort);
        nd.attrib['DspRoutineIdentifier'] = str(self.DspRoutineIdentifier);
        nd.attrib['DspRoutineInfoRef'] = str(self.DspRoutineInfoRef);
        nd.attrib['DspStartRoutineFnc'] = str(self.DspStartRoutineFnc);
        nd.attrib['DspStopRoutineFnc'] = str(self.DspStopRoutineFnc);
        nd.attrib['DspRequestResultRoutineFnc'] = str(self.DspRequestResultRoutineFnc);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name']
        self.DspRoutineUsePort = bool(nd.attrib['DspRoutineUsePort'])
        self.DspRoutineIdentifier = str(nd.attrib['DspRoutineIdentifier'])
        self.DspRoutineInfoRef = str(nd.attrib['DspRoutineInfoRef'])
        self.DspStartRoutineFnc = str(nd.attrib['DspStartRoutineFnc'])
        self.DspStopRoutineFnc = str(nd.attrib['DspStopRoutineFnc'])
        self.DspRequestResultRoutineFnc = str(nd.attrib['DspRequestResultRoutineFnc'])
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
        self.routineInfoList = [];
        self.routineList = [];
        
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
        
        nd = ET.Element('DcmRoutineInfoList');
        for obj in self.routineInfoList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('DcmRoutineList');
        for obj in self.routineList:
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

        for nd in root.find('DcmRoutineInfoList'):
            obj = DcmRoutineInfo('');
            obj.parse(nd);
            self.routineInfoList.append(obj);

        for nd in root.find('DcmRoutineList'):
            obj = DcmRoutine('', 0);
            obj.parse(nd);
            self.routineList.append(obj);
            
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
        fp.write('#define DCM_MAX_DDD_NUMBER				%s  \n\n'%(self.cfg.general.DynamicIdentifierNr));
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
        fp.write('\n\n#define USE_PDUR\n\n')
        fp.write("""//do add/subtract by hand.please
//#define USE_DEM
#define DCM_USE_SERVICE_DIAGNOSTICSESSIONCONTROL
#define DCM_USE_SERVICE_ECURESET
//#define DCM_USE_SERVICE_CLEARDIAGNOSTICINFORMATION
//#define DCM_USE_SERVICE_READDTCINFORMATION
#define DCM_USE_SERVICE_READDATABYIDENTIFIER
#define DCM_USE_SERVICE_READMEMORYBYADDRESS
#define DCM_USE_SERVICE_WRITEMEMORYBYADDRESS
#define DCM_USE_SERVICE_READSCALINGDATABYIDENTIFIER
#define DCM_USE_SERVICE_SECURITYACCESS
#define DCM_USE_SERVICE_WRITEDATABYIDENTIFIER
#define DCM_USE_SERVICE_ROUTINECONTROL
#define DCM_USE_SERVICE_TESTERPRESENT
//#define DCM_USE_SERVICE_CONTROLDTCSETTING
#define DCM_USE_SERVICE_READDATABYPERIODICIDENTIFIER
#define DCM_USE_SERVICE_DYNAMICALLYDEFINEDATAIDENTIFIER
#define DCM_USE_SERVICE_INPUTOUTPUTCONTROLBYIDENTIFIER
""")
        #-------------------------------------------------------
        fp.write('#endif /*DCM_CFG_H_*/\n\n')
        fp.close();
    def codeGenC(self, path):
        fp = open(path+'/Dcm_LCfg.c', 'w');
        fp.write(gcGainOS_TkHead());
        #------------------------------------------------------------------
        fp.write("""#include "Std_Types.h"
#include "Dcm.h"
#include "Dcm_Internal.h"
#if defined(USE_PDUR)
#include "PduR.h"
#endif\n\n""");
        fp.write('#define DCM_SECURITY_EOL_INDEX %s\n'%(len(self.cfg.securityLevelList)));
        fp.write('#define DCM_SESSION_EOL_INDEX %s\n'%(len(self.cfg.sessionList)));
        fp.write('#define DCM_DID_LIST_EOL_INDEX %s\n\n'%(len(self.cfg.didList)));
        for did in self.cfg.didList:
            if(did.DspDidReadDataLengthFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint16 *didLength);\n'%(did.DspDidReadDataLengthFnc))
            if(did.DspDidConditionCheckReadFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidConditionCheckReadFnc))
            if(did.DspDidReadDataFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *data);\n'%(did.DspDidReadDataFnc))
            if(did.DspDidConditionCheckWriteFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidConditionCheckWriteFnc))
            if(did.DspDidWriteDataFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *data, uint16 dataLength, Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidWriteDataFnc))
            if(did.DspDidGetScalingInfoFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *scalingInfo, Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidGetScalingInfoFnc))
            if(did.DspDidFreezeCurrentStateFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *controlOptionRecord, uint8 *controlEnableMaskRecord, uint8 *controlStatusRecord, Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidFreezeCurrentStateFnc))
            if(did.DspDidResetToDefaultFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *controlOptionRecord, uint8 *controlEnableMaskRecord, uint8 *controlStatusRecord, Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidResetToDefaultFnc))
            if(did.DspDidReturnControlToEcuFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *controlOptionRecord, uint8 *controlEnableMaskRecord, uint8 *controlStatusRecord, Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidReturnControlToEcuFnc))
            if(did.DspDidShortTermAdjustmentFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *controlOptionRecord, uint8 *controlEnableMaskRecord, uint8 *controlStatusRecord, Dcm_NegativeResponseCodeType *errorCode);\n'%(did.DspDidShortTermAdjustmentFnc))
        fp.write('/* --------------------------------------------------------- */\n\n')
        for sec in self.cfg.securityLevelList:
            if(sec.getSeedCbk != 'NULL'):
                fp.write('extern Std_ReturnType %s (uint8 *securityAccessDataRecord, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode);\n'%(sec.getSeedCbk));
            if(sec.compKeyCbk != 'NULL'):
                fp.write('extern Std_ReturnType %s (uint8 *key);\n'%(sec.compKeyCbk));
        for req in self.cfg.requestServiceList:
            if(req.start != 'NULL'):
                fp.write('extern Std_ReturnType %s (Dcm_ProtocolType protocolID);\n'%(req.start))
            if(req.stop != 'NULL'):
                fp.write('extern Std_ReturnType %s (Dcm_ProtocolType protocolID);\n'%(req.stop))
            if(req.indication != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *requestData, uint16 dataSize);\n\n'%(req.indication));
        for sesc in self.cfg.sessionControlList:
            if(sesc.GetSesChgPermission != 'NULL'):
                fp.write('extern Std_ReturnType %s(Dcm_SesCtrlType sesCtrlTypeActive, Dcm_SesCtrlType sesCtrlTypeNew);\n'%(sesc.GetSesChgPermission));
        for rtn in self.cfg.routineList:
            if(rtn.DspStartRoutineFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *inBuffer, uint8 *outBuffer, Dcm_NegativeResponseCodeType *errorCode);\n'%(rtn.DspStartRoutineFnc));
            if(rtn.DspStopRoutineFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *inBuffer, uint8 *outBuffer, Dcm_NegativeResponseCodeType *errorCode);\n'%(rtn.DspStopRoutineFnc));
            if(rtn.DspRequestResultRoutineFnc != 'NULL'):
                fp.write('extern Std_ReturnType %s(uint8 *outBuffer, Dcm_NegativeResponseCodeType *errorCode);\n'%(rtn.DspRequestResultRoutineFnc));
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
                str +='\t\t/* DspSessionLevel = */ %s,\n'%(ses.level);
                str +='\t\t/* DspSessionP2ServerMax = */ %s,\n'%(ses.P2ServerMax);
                str +='\t\t/* DspSessionP2StarServerMax = */ %s,\n'%(ses.P2StarServerMax);
                str +='\t\t/* Arc_EOL = */ %s\n'%('FALSE');
                str +='\t},\n';
            str +='\t{ //%s\n'%('Dummy Session For EOL');
            str +='\t\t/* DspSessionLevel = */ %s,\n'%('0xBD');
            str +='\t\t/* DspSessionP2ServerMax = */ %s,\n'%('0xBD');
            str +='\t\t/* DspSessionP2StarServerMax = */ %s,\n'%('0xBD');
            str +='\t\t/* Arc_EOL = */ %s\n'%('TRUE');
            str +='\t},\n';
            str += '};\n\n';
            fp.write(str);
            fp.write("""const Dcm_DspSessionType DspSession = {
    /* DspSessionRow = */ DspSessionList,
};\n\n""")
        #----------------- Service Table ---------------
        for sertbl in self.cfg.serviceTableList:
            for ser in sertbl.serviceList:
                str = 'const Dcm_DspSecurityRowType *%s_%s_SecurityList[] = {\n'%(sertbl.name, ser.name);
                for sec in ser.securityRefList:
                    str += '\t&DspSecurityList[%s],//%s\n'%(gcfindIndex(self.cfg.securityLevelList, sec), sec);
                str += '\t&DspSecurityList[DCM_SECURITY_EOL_INDEX]\n};\n'
                fp.write(str);
        for sertbl in self.cfg.serviceTableList:
            for ser in sertbl.serviceList:
                str = 'const Dcm_DspSessionRowType *%s_%s_SessionList[] = {\n'%(sertbl.name, ser.name);
                for ses in ser.sessionRefList:
                    str += '\t&DspSessionList[%s],//%s\n'%(gcfindIndex(self.cfg.sessionList, ses), ses);
                str += '\t&DspSessionList[DCM_SESSION_EOL_INDEX]\n};\n'
                fp.write(str);
        fp.write('\n')
        #----------------- DID INFOs ----------------
        for didInfo in self.cfg.didInfoList:
            #-------------- read access
            for read in didInfo.ReadAccessList:
                str1 = str2 = 'NULL';
                if(len(read.sessionRefList)):
                    str1 = '%s_read_sessionRefList'%(didInfo.name);
                    str = 'const Dcm_DspSessionRowType *%s_%s_sessionRefList[] = {\n'%(didInfo.name, 'read');
                    for ses in read.sessionRefList:
                        str += '\t&DspSessionList[%s],//%s\n'%(gcfindIndex(self.cfg.sessionList, ses), ses);
                    str += '\t&DspSessionList[DCM_SESSION_EOL_INDEX]\n};\n'
                    fp.write(str);
                #----
                if(len(read.securityRefList)):
                    str2 = '%s_read_securityRefList'%(didInfo.name);
                    str = 'const Dcm_DspSecurityRowType *%s_%s_securityRefList[] = {\n'%(didInfo.name, 'read');
                    for sec in read.securityRefList:
                        str += '\t&DspSecurityList[%s],//%s\n'%(gcfindIndex(self.cfg.securityLevelList, sec), sec);
                    str += '\t&DspSecurityList[DCM_SECURITY_EOL_INDEX]\n};\n'
                    fp.write(str);
                fp.write("""const Dcm_DspDidReadType %s_didRead = {
    /* DspDidReadSessionRef = */ %s,
    /* DspDidReadSecurityLevelRef = */ %s
};\n\n"""%(didInfo.name, str1, str2));
            #----------- write access ------
            for write in didInfo.WriteAccessList:
                str1 = str2 = 'NULL';
                if(len(write.sessionRefList)):
                    str1 = '%s_write_sessionRefList'%(didInfo.name);
                    str = 'const Dcm_DspSessionRowType *%s_%s_sessionRefList[] = {\n'%(didInfo.name, 'write');
                    for ses in write.sessionRefList:
                        str += '\t&DspSessionList[%s],//%s\n'%(gcfindIndex(self.cfg.sessionList, ses), ses);
                    str += '\t&DspSessionList[DCM_SESSION_EOL_INDEX]\n};\n'
                    fp.write(str);
                #----
                if(len(write.securityRefList)):
                    str2 = '%s_write_securityRefList'%(didInfo.name);
                    str = 'const Dcm_DspSecurityRowType *%s_%s_securityRefList[] = {\n'%(didInfo.name, 'write');
                    for sec in write.securityRefList:
                        str += '\t&DspSecurityList[%s],//%s\n'%(gcfindIndex(self.cfg.securityLevelList, sec), sec);
                    str += '\t&DspSecurityList[DCM_SECURITY_EOL_INDEX]\n};\n'
                    fp.write(str);
                fp.write("""const Dcm_DspDidWriteType %s_didWrite = {
    /* DspDidReadSessionRef = */ %s,
    /* DspDidReadSecurityLevelRef = */ %s
};\n\n"""%(didInfo.name, str1, str2));
            #----------- Control access -----------------
            for ctrl in didInfo.ControlAccessList:
                str1 = str2 = 'NULL';
                if(len(ctrl.sessionRefList)):
                    str1 = '%s_control_sessionRefList'%(didInfo.name);
                    str = 'const Dcm_DspSessionRowType *%s_%s_sessionRefList[] = {\n'%(didInfo.name, 'control');
                    for ses in ctrl.sessionRefList:
                        str += '\t&DspSessionList[%s],//%s\n'%(gcfindIndex(self.cfg.sessionList, ses), ses);
                    str += '\t&DspSessionList[DCM_SESSION_EOL_INDEX]\n};\n'
                    fp.write(str);
                #----
                if(len(ctrl.securityRefList)):
                    str2 = '%s_control_securityRefList'%(didInfo.name);
                    str = 'const Dcm_DspSecurityRowType *%s_%s_securityRefList[] = {\n'%(didInfo.name, 'control');
                    for sec in ctrl.securityRefList:
                        str += '\t&DspSecurityList[%s],//%s\n'%(gcfindIndex(self.cfg.securityLevelList, sec), sec);
                    str += '\t&DspSecurityList[DCM_SECURITY_EOL_INDEX]\n};\n'
                    fp.write(str);
                fp.write("""const Dcm_DspDidControlType %s_didControl = {
    /* DspDidReadSessionRef = */ %s,
    /* DspDidReadSecurityLevelRef = */ %s,
    /* DspDidFreezeCurrentState = */ NULL,
    /* DspDidResetToDefault = */ NULL,
    /* DspDidReturnControlToEcu = */ NULL,
    /* DspDidShortTermAdjustment = */ NULL
};\n\n"""%(didInfo.name, str1, str2));
        str = 'const Dcm_DspDidInfoType DspDidInfoList[] = {\n';
        for didInfo in self.cfg.didInfoList:
            str += '\t{ // %s\n'%(didInfo.name);
            str += '\t\t /* DspDidDynamicllyDefined = */ %s,\n'%(TRUE(didInfo.DynamicllyDefined));
            str += '\t\t /* DspDidFixedLength = */ %s,\n'%(TRUE(didInfo.FixedLength));
            str += '\t\t /* DspDidScalingInfoSize = */ %s,\n'%(didInfo.ScalingInfoSize);
            str += '\t\t{ // DspDidAccess\n';
            if(len(didInfo.ReadAccessList)>0):
                str += '\t\t\t /* DspDidRead */ &%s_didRead,\n'%(didInfo.name);
            else:
                str += '\t\t\t /* DspDidRead */ NULL,\n';
            if(len(didInfo.WriteAccessList)>0):
                str += '\t\t\t /* DspDidWrite */ &%s_didWrite,\n'%(didInfo.name);
            else:
                str += '\t\t\t /* DspDidWrite */ NULL,\n';
            if(len(didInfo.ControlAccessList)>0):
                str += '\t\t\t /* DspDidControl */ &%s_didControl,\n'%(didInfo.name);
            else:
                str += '\t\t\t /* DspDidControl */ NULL,\n';
            str += '\t\t}\n';
            str += '\t}, \n';
        str += '};\n\n'
        fp.write(str);
        #------------------ DIDs ----------
        fp.write('extern const Dcm_DspDidType DspDidList[];\n');
        for did in self.cfg.didList:
            fp.write("""const Dcm_DspDidType* %s_dididRefList[] =
{
    &DspDidList[DCM_DID_LIST_EOL_INDEX]  //add did ref by hand please,If you need it
};\n"""%(did.name));
        str = 'const Dcm_DspDidType DspDidList[] = { \n';
        for did in self.cfg.didList:
            str += '\t{ // %s,\n'%(did.name);
            str += '\t\t/* DspDidUsePort = */ %s,/* Value is not configurable */\n'%(TRUE(did.usePort));
            str += '\t\t/* DspDidIdentifier = */ %s,\n'%(did.id);
            str += '\t\t/* DspDidInfoRef = */ &DspDidInfoList[%s], //%s\n'%(gcfindIndex(self.cfg.didInfoList, did.didInfoRef), did.didInfoRef);
            str += '\t\t/* DspDidRef = */ %s_dididRefList,\n'%(did.name);
            str += '\t\t/* DspDidSize = */ %s,\n'%(did.size);
            str += '\t\t/* /* DspDidReadDataLengthFnc = */ %s,\n'%(did.DspDidReadDataLengthFnc);
            str += '\t\t/* /* DspDidConditionCheckReadFnc = */ %s,\n'%(did.DspDidConditionCheckReadFnc);
            str += '\t\t/* /* DspDidReadDataFnc = */ %s,\n'%(did.DspDidReadDataFnc);
            str += '\t\t/* /* DspDidConditionCheckWriteFnc = */ %s,\n'%(did.DspDidConditionCheckWriteFnc);
            str += '\t\t/* /* DspDidWriteDataFnc = */ %s,\n'%(did.DspDidWriteDataFnc);
            str += '\t\t/* /* DspDidGetScalingInfoFnc = */ %s,\n'%(did.DspDidGetScalingInfoFnc);
            str += '\t\t/* /* DspDidFreezeCurrentStateFnc = */ %s,\n'%(did.DspDidFreezeCurrentStateFnc);
            str += '\t\t/* /* DspDidResetToDefaultFnc = */ %s,\n'%(did.DspDidResetToDefaultFnc);
            str += '\t\t/* /* DspDidReturnControlToEcuFnc = */ %s,\n'%(did.DspDidReturnControlToEcuFnc);
            str += '\t\t/* /* DspDidShortTermAdjustmentFnc = */ %s,\n'%(did.DspDidShortTermAdjustmentFnc);
            #TODO: ?? what does DspDidControlRecordSize means
            str += '\t\t/* /* DspDidControlRecordSize = */ NULL,\n';
            str += '\t\t/* Arc_EOL = */ %s\n'%('FALSE');
            str += '\t},\n'
        str += '\t{ // %s,\n'%('Dummy for EOL');
        str += '\t\t/* DspDidUsePort = */ %s,/* Value is not configurable */\n'%('FALSE');
        str += '\t\t/* DspDidIdentifier = */ %s,\n'%('0xDB');
        str += '\t\t/* DspDidInfoRef = */ NULL,\n';
        str += '\t\t/* DspDidRef = */ NULL, //%s\n'%('I cann\'t understand');
        str += '\t\t/* DspDidSize = */ %s,\n'%('0xDB');
        str += """		/* DspDidReadDataLengthFnc = */ NULL,
        /* DspDidConditionCheckReadFnc = */ NULL,
        /* DspDidReadDataFnc = */ NULL,
        /* DspDidConditionCheckWriteFnc = */ NULL,
        /* DspDidWriteDataFnc = */ NULL,
        /* DspDidGetScalingInfoFnc = */ NULL,
        /* DspDidFreezeCurrentStateFnc = */ NULL,	
        /* DspDidResetToDefaultFnc = */ NULL,
        /* DspDidReturnControlToEcuFnc = */ NULL,
        /* DspDidShortTermAdjustmentFnc = */ NULL,
        /* DspDidControlRecordSize = */ NULL,\n""";
        str += '\t\t/* Arc_EOL = */ %s\n'%('TRUE');
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        #---------------------- Routines -------
        fp.write("""/************************************************************************
 *							Routine control								*
 ************************************************************************/\n\n""");
        for rtninfo in self.cfg.routineInfoList:
            for start in rtninfo.StartList:
                fp.write("""const Dcm_DspStartRoutineType %s_start = {
    /* DspStartRoutineCtrlOptRecSize = */ %s,
    /* DspStartRoutineStsOptRecSize = */ %s
};\n"""%(rtninfo.name, start.DspStartRoutineCtrlOptRecSize, start.DspStartRoutineStsOptRecSize));
            for stop in rtninfo.StopList:
                fp.write("""const Dcm_DspRoutineStopType %s_stop = {
    /* DspStopRoutineCtrlOptRecSize = */ %s,
    /* DspStopRoutineStsOptRecSize = */ %s,
};\n"""%(rtninfo.name,stop.DspStopRoutineCtrlOptRecSize, stop.DspStopRoutineStsOptRecSize))
            for auth in rtninfo.AuthorizationList:
                str = 'const Dcm_DspSessionRowType *%s_sessionRefList[] = {\n'%(rtninfo.name)
                for ses in auth.sessionRefList:
                    str += '\t&DspSessionList[%s],//%s\n'%(gcfindIndex(self.cfg.sessionList, ses), ses)
                str += '\t&DspSessionList[DCM_SESSION_EOL_INDEX]\n'
                str +='};\n'
                fp.write(str);
                str = 'const Dcm_DspSecurityRowType *%s_securityRefList[] = {\n'%(rtninfo.name)
                for sec in auth.securityRefList:
                    str += '\t&DspSecurityList[%s],//%s\n'%(gcfindIndex(self.cfg.securityLevelList, sec), sec)
                str += '\t&DspSecurityList[DCM_SECURITY_EOL_INDEX]\n'
                str +='};\n'
                fp.write(str);
            for req in rtninfo.RequestList:
                fp.write("""const Dcm_DspRoutineRequestResType %s_request = {
    /* DspReqResRtnCtrlOptRecSize = */ %s
};\n"""%(rtninfo.name, req.DspReqResRtnCtrlOptRecSize))
        str = 'const Dcm_DspRoutineInfoType DspRoutineInfoList[] = {\n'
        for rtninfo in self.cfg.routineInfoList:
            str += '\t{//%s\n'%(rtninfo.name);
            str += '\t\t{//DspRoutineAuthorization\n'
            str += '\t\t\t /* DspRoutineSessionRef = */ %s_sessionRefList,\n'%(rtninfo.name)
            str += '\t\t\t /* DspRoutineSecurityLevelRef = */ %s_securityRefList,\n'%(rtninfo.name)
            str += '\t\t},\n'
            str += '\t\t /* DspStartRoutine = */ &%s_start,\n'%(rtninfo.name);
            if(len(rtninfo.StopList) > 0):
                str += '\t\t /* DspRoutineStop = */ &%s_stop,\n'%(rtninfo.name);
            else:
                str += '\t\t /* DspRoutineStop = */ NULL,\n'
            if(len(rtninfo.RequestList) > 0):
                str += '\t\t /* DspRoutineRequestRes = */ &%s_request,\n'%(rtninfo.name);
            else:
                str += '\t\t /* DspRoutineRequestRes = */ NULL\n'
            str += '\t},\n'
        str += '};\n\n'
        fp.write(str);
        str = 'const Dcm_DspRoutineType  DspRoutineList[] = {\n'
        for rtn in self.cfg.routineList:
            str += '\t{//%s\n'%(rtn.name);
            str += '\t\t /* DspRoutineUsePort = */ %s,\n'%(TRUE(rtn.DspRoutineUsePort))
            str += '\t\t /* DspRoutineIdentifier = */ %s,\n'%(rtn.DspRoutineIdentifier)
            str += '\t\t /* DspRoutineInfoRef = */ &DspRoutineInfoList[%s],//%s\n'%(gcfindIndex(self.cfg.routineInfoList, rtn.DspRoutineInfoRef), rtn.DspRoutineInfoRef)
            str += '\t\t /* DspStartRoutineFnc = */ %s,\n'%(rtn.DspStartRoutineFnc)
            str += '\t\t /* DspStopRoutineFnc = */ %s,\n'%(rtn.DspStopRoutineFnc)
            str += '\t\t /* DspRequestResultRoutineFnc = */ %s,\n'%(rtn.DspRequestResultRoutineFnc)
            str += '\t\t /* Arc_EOL */ FALSE\n'
            str += '\t},\n'
        str += '\t{//%s\n'%('Dummy For EOL');
        str += '\t\t /* DspRoutineUsePort = */ %s,\n'%('FALSE')
        str += '\t\t /* DspRoutineIdentifier = */ %s,\n'%('0xDB')
        str += '\t\t /* DspRoutineInfoRef = */ %s,\n'%('NULL')
        str += '\t\t /* DspStartRoutineFnc = */ %s,\n'%('NULL')
        str += '\t\t /* DspStopRoutineFnc = */ %s,\n'%('NULL')
        str += '\t\t /* DspRequestResultRoutineFnc = */ %s,\n'%('NULL')
        str += '\t\t /* Arc_EOL */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        #--------------------- Memory ------------------------------------
        fp.write("""/************************************************************************
 *							Memory Info             					*
 ************************************************************************/\n\n""")
        #---------------------- DSP
        fp.write("""const Dcm_DspType Dsp = {
    /* DspMaxDidToRead = */ 0x99,//????
    /* DspDid = */ DspDidList,
    /* DspDidInfo = */ DspDidInfoList,
    /* DspEcuReset = */ NULL,
    /* DspPid = */ NULL,
    /* DspReadDTC = */ NULL,
    /* DspRequestControl = */ NULL,
    /* DspRoutine = */ DspRoutineList,
    /* DspRoutineInfo = */ DspRoutineInfoList,
    /* DspSecurity = */ &DspSecurity,
    /* DspSession = */ &DspSession,
    /* DspTestResultByObdmid = */ NULL,
    /* DspVehInfo = */ NULL
};\n\n""");
        # ------------------------------- DSD
        fp.write("""/************************************************************************
 *									DSD									*
 ************************************************************************/\n\n""");
        for sertbl in self.cfg.serviceTableList:
            str = 'const Dcm_DsdServiceType %s_serviceList[] = {\n'%(sertbl.name);
            for ser in sertbl.serviceList:
                str += '\t{ // %s\n'%(ser.name);
                str += '\t\t /* DsdSidTabServiceId =*/ %s,\n'%(ser.serviceId);
                str += '\t\t /* DsdSidTabSubfuncAvail =*/ %s,\n'%(TRUE(ser.subfuncAvail));
                str += '\t\t /* DsdSidTabSecurityLevelRef =*/ %s_%s_SecurityList,\n'%(sertbl.name, ser.name);
                str += '\t\t /* DsdSidTabSessionLevelRef =*/ %s_%s_SessionList,\n'%(sertbl.name, ser.name);
                str += '\t\t /* Arc_EOL = */ FALSE\n'
                str += '\t},\n';
            str += '\t{ // %s\n'%('Dummy For EOL');
            str += '\t\t /* DsdSidTabServiceId =*/ %s,\n'%('0xDB');
            str += '\t\t /* DsdSidTabSubfuncAvail =*/ %s,\n'%('FALSE');
            str += '\t\t /* DsdSidTabSecurityLevelRef =*/ NULL,\n';
            str += '\t\t /* DsdSidTabSessionLevelRef =*/ NULL,\n';
            str += '\t\t /* Arc_EOL = */ TRUE\n'
            str += '\t}\n';
            str += '};\n\n'
            fp.write(str);
        str = 'const Dcm_DsdServiceTableType DsdServiceTable[] = {	\n';
        id = 0;
        for sertbl in self.cfg.serviceTableList:
            str += '\t{ // %s\n'%(sertbl.name);
            str += '\t\t /* DsdSidTabId = */ %s,\n'%(id);
            str += '\t\t /* DsdService = */ %s_serviceList,\n'%(sertbl.name);
            str += '\t\t /* Arc_EOL = */ FALSE\n'
            str += '\t},\n'
            id += 1;
        str += '\t{ // %s\n'%('Dummy For EOL ');
        str += '\t\t /* DsdSidTabId = */ %s,\n'%('0xDB');
        str += '\t\t /* DsdService = */ NULL,\n'
        str += '\t\t /* Arc_EOL = */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        fp.write("""const Dcm_DsdType Dsd = {
    /* DsdServiceTable = */ DsdServiceTable
};\n\n""");
        #----------------------- DSL
        fp.write("""/************************************************************************
 *									DSL									*
 ************************************************************************/\n\n""")
        #--------------- buffer 
        str = 'const Dcm_DslBufferType DcmDslBufferList[DCM_DSL_BUFFER_LIST_LENGTH] = {\n'
        id = 0;
        for buf in self.cfg.bufferList:
            fp.write("""uint8 %s[%s];
Dcm_DslBufferRuntimeType rxBufferParams_%s =
{
	/* status = */ NOT_IN_USE
};\n"""%(buf.name, buf.size, buf.name));
            str += '\t{ // %s\n'%(buf.name);
            str += '\t\t/* DslBufferID = */ %s,//? I am not that clear.\n'%(id);
            str += '\t\t/* DslBufferSize = */ %s,/* ?Value is not configurable */\n'%(buf.size);
            str += '\t\t{ /* pduInfo */\n';
            str += '\t\t\t/* SduDataPtr = */ %s,\n'%(buf.name);
            str += '\t\t\t/* SduLength = */ %s,\n'%(buf.size);
            str += '\t\t},\n'
            str += '\t\t/* externalBufferRuntimeData = */ &rxBufferParams_%s\n'%(buf.name);
            str += '\t},\n';
            id += 1;
        str += '};\n\n'
        fp.write(str);
        #----------------- Request Service
        str = 'const Dcm_DslCallbackDCMRequestServiceType DCMRequestServiceList[] = {\n'
        for reqser in self.cfg.requestServiceList:
            str += '\t{ // %s\n'%(reqser.name);
            str += '\t\t/* StartProtocol = */ %s,\n'%(reqser.start);
            str += '\t\t/* StopProtocol = */ %s,\n'%(reqser.stop);
            str += '\t\t/* Arc_EOL = */ FALSE\n'
            str += '\t},\n'
        str += '\t{ // %s\n'%('Dummy For EOL');
        str += '\t\t/* StartProtocol = */ %s,\n'%('NULL');
        str += '\t\t/* StopProtocol = */ %s,\n'%('NULL');
        str += '\t\t/* Arc_EOL = */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n';
        fp.write(str);
        str = 'const Dcm_DslServiceRequestIndicationType DCMServiceRequestIndicationList[] = {\n'
        for reqser in self.cfg.requestServiceList:
            if(reqser.indication != 'NULL'):
                str += '\t{ // %s\n'%(reqser.name);
                str += '\t\t/* Indication = */ %s,\n'%(reqser.indication);
                str += '\t\t/* Arc_EOL = */ FALSE\n'
                str += '\t},\n'
        str += '\t{ // %s\n'%('Dummy For EOL');
        str += '\t\t/* Indication = */ NULL,\n'
        str += '\t\t/* Arc_EOL = */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n';
        fp.write(str);
        #--------------------- Protocol
        fp.write('extern const Dcm_DslMainConnectionType DslMainConnectionList[];\n\n');
        #here I am confused witn Main Connection and Connection.
        #So I assume the first configured one was main connection.
        str = 'const Dcm_DslProtocolRxType DcmDslProtocolRxList[] = {\n';
        cid = 0;
        for pro in self.cfg.protocolList:
            for con in pro.ConnectionList:
                for rx in con.RxChannelList:
                    str += '\t{// %s->%s->%s\n'%(pro.name, con.name, rx.name);
                    str += '\t\t/* DslMainConnectionParent = */ &DslMainConnectionList[%s],\n'%(cid);
                    str += '\t\t/* DslProtocolAddrType = */ %s,\n'%(rx.RxAddrType);
                    str += '\t\t/* DcmDslProtocolRxPduId = */ PDUR_%s,\n'%(rx.RxPdu);
                    str += '\t\t/* DcmDslProtocolRxTesterSourceAddr_v4 = */ 0,		/* Value is not configurable */\n'
                    str += '\t\t/* DcmDslProtocolRxChannelId_v4 = */ 0,				/* Value is not configurable */\n'
                    str += '\t\t/* Arc_EOL = */ FALSE\n'
                    str += '\t},\n'
            cid += 1;
        str += '\t{// Dummy for EOL\n'
        str += '\t\t/* DslMainConnectionParent = */ NULL,\n';
        str += '\t\t/* DslProtocolAddrType = */ 0xDB,\n';
        str += '\t\t/* DcmDslProtocolRxPduId = */ 0xDB,\n';
        str += '\t\t/* DcmDslProtocolRxTesterSourceAddr_v4 = */ 0,		/* Value is not configurable */\n'
        str += '\t\t/* DcmDslProtocolRxChannelId_v4 = */ 0,				/* Value is not configurable */\n'
        str += '\t\t/* Arc_EOL = */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        #---tx
        str = 'const Dcm_DslProtocolTxType DcmDslProtocolTxList[] = {\n';
        cid = 0;
        for pro in self.cfg.protocolList:
            for con in pro.ConnectionList:
                for tx in con.TxChannelList:
                    str += '\t{// %s->%s->%s\n'%(pro.name, con.name, tx.name);
                    str += '\t\t/* DslMainConnectionParent = */ &DslMainConnectionList[%s],\n'%(cid);
                    str += '\t\t/* DcmDslProtocolTxPduId = */ PDUR_%s,\n'%(tx.TxPdu);
                    str += '\t\t/* Arc_EOL = */ FALSE\n'
                    str += '\t},\n'
            cid += 1;
        str += '\t{// Dummy for EOL\n'
        str += '\t\t/* DslMainConnectionParent = */ NULL,\n';
        str += '\t\t/* DcmDslProtocolTxPduId = */ 0xDB,\n';
        str += '\t\t/* Arc_EOL = */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        #--- 
        fp.write('extern const Dcm_DslConnectionType DslConnectionList[];\n\n');
        str = 'const Dcm_DslMainConnectionType DslMainConnectionList[] = {\n'
        cid = tid =0; # help me to record the index for connection and transmit Pdu ID
        for pro in self.cfg.protocolList:
            for con in pro.ConnectionList:
                str += '\t{//%s->%s\n'%(pro.name, con.name);
                str += '\t\t/* DslConnectionParent = */ &DslConnectionList[%s],\n'%(cid);
                str += '\t\t/* DslPeriodicTransmissionConRef = */ NULL,		/* Value is not configurable */\n'
                str += '\t\t/* DslROEConnectionRef = */ NULL,				/* Value is not configurable */\n'
                str += '\t\t/* DslProtocolRx = */ NULL,						/* Value is not configurable */\n'
                str += '\t\t/* DslProtocolTx = */ &DcmDslProtocolTxList[%s],\n'%(tid);
                # 实际上 TxChannelList的长度永远应该为 1
                tid += len(con.TxChannelList) #calculate the next tid
                str += '\t},\n'
                cid += 1;
        str += '};\n\n'
        fp.write(str);
        #-----------
        fp.write('extern const Dcm_DslProtocolRowType DslProtocolRowList[];\n\n')
        pid = cid =0;
        str = 'const Dcm_DslConnectionType DslConnectionList[] = {\n'
        for pro in self.cfg.protocolList:
            for con in pro.ConnectionList:
                str += '\t{//%s->%s\n'%(pro.name, con.name);
                str += '\t\t/* DslProtocolRow = */ &DslProtocolRowList[%s],\n'%(pid);
                str += '\t\t/* DslMainConnection = */ &DslMainConnectionList[%s],\n'%(cid);
                str += '\t\t/* DslPeriodicTransmission = */ NULL,	/* Value is not configurable */\n'
                str += '\t\t/* DslResponseOnEvent = */ NULL,	/* Value is not configurable */\n'
                str += '\t\t/* Arc_EOL = */ %s\n'%('FALSE');
                str += '\t},\n'
                cid += 1;
            pid += 1;
            
        str += '\t{//Dummy For EOL\n'
        str += '\t\t/* DslProtocolRow = */ NULL,\n'
        str += '\t\t/* DslMainConnection = */ NULL,\n'
        str += '\t\t/* DslPeriodicTransmission = */ NULL,\n'
        str += '\t\t/* DslResponseOnEvent = */ NULL,\n'
        str += '\t\t/* Arc_EOL = */ %s\n'%('TRUE');
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        # now I am really very confused by the relation between Connection and Main Connection, ???
        #----------------
        fp.write('extern const Dcm_DslProtocolTimingRowType ProtocolTimingList[];\n\n');
        fp.write('Dcm_DslRunTimeProtocolParametersType dcmDslRuntimeVariables[%s];\n'%(len(self.cfg.protocolList)))
        str = 'const Dcm_DslProtocolRowType DslProtocolRowList[]= {\n'
        id = 0;
        for pro in self.cfg.protocolList:
            str += '\t{//%s\n'%(pro.name)
            str += '\t\t/* DslProtocolID = */ %s,\n'%(pro.ProtocolId)
            str += '\t\t/* DslProtocolIsParallelExecutab = */ FALSE, // not supported\n'
            str += '\t\t/* DslProtocolPreemptTimeout = */ 0,	// not supported\n'
            str += '\t\t/* DslProtocolPriority = */ 0,	// not supported\n'
            str += '\t\t/* DslProtocolTransType = */ %s,\n'%(pro.TransType)
            str += '\t\t/* DslProtocolRxBufferID = */ &DcmDslBufferList[%s],//%s\n'%(gcfindIndex(self.cfg.bufferList, pro.RxBufferID), pro.RxBufferID)
            str += '\t\t/* DslProtocolTxBufferID = */ &DcmDslBufferList[%s],//%s\n'%(gcfindIndex(self.cfg.bufferList, pro.TxBufferID), pro.TxBufferID)
            str += '\t\t/* DslProtocolSIDTable = */ &DsdServiceTable[%s],//%s\n'%(gcfindIndex(self.cfg.serviceTableList, pro.ServiceTable), pro.ServiceTable)
            str += '\t\t/* DslProtocolTimeLimit = */ &ProtocolTimingList[%s],//%s\n'%(gcfindIndex(self.cfg.timingList, pro.TimeLimit), pro.TimeLimit)
            str += '\t\t/* DslConnection = */ %s,\n'%('DslConnectionList')
            str += '\t\t/* DslRunTimeProtocolParameters = */ &dcmDslRuntimeVariables[%s],\n'%(id)
            str += '\t\t/* Arc_EOL = */ %s\n'%('FALSE')
            str += '\t},\n'
            id += 1;
        str += '\t{//%s\n'%('Dummy for EOL')
        str += '\t\t/* DslProtocolID = */ %s,\n'%('0xDB')
        str += '\t\t/* DslProtocolIsParallelExecutab = */ FALSE, // not supported\n'
        str += '\t\t/* DslProtocolPreemptTimeout = */ 0,	// not supported\n'
        str += '\t\t/* DslProtocolPriority = */ 0,	// not supported\n'
        str += '\t\t/* DslProtocolTransType = */ %s,\n'%('0xDB')
        str += '\t\t/* DslProtocolRxBufferID = */ NULL,\n'
        str += '\t\t/* DslProtocolTxBufferID = */ NULL,\n'
        str += '\t\t/* DslProtocolSIDTable = */ NULL,\n'
        str += '\t\t/* DslProtocolTimeLimit = */ NULL,\n'
        str += '\t\t/* DslConnection = */ %s,\n'%('NULL')
        str += '\t\t/* DslRunTimeProtocolParameters = */ NULL,\n'
        str += '\t\t/* Arc_EOL = */ %s\n'%('TRUE')
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        fp.write("""const Dcm_DslProtocolType DslProtocol = {
    /* DslProtocolRxGlobalList = */ DcmDslProtocolRxList,
    /* DslProtocolTxGlobalList = */ DcmDslProtocolTxList,
    /* DslProtocolRowList = */ DslProtocolRowList
};\n\n""")
        str = 'const Dcm_DslProtocolTimingRowType ProtocolTimingList[] = {\n'
        for tim in self.cfg.timingList:
            str += '\t{//%s\n'%(tim.name);
            str += '\t\t/* TimStrP2ServerMax = */ %s,\n'%(tim.P2ServerMax)
            str += '\t\t/* TimStrP2ServerMin = */ %s,\n'%(tim.P2ServerMin)
            str += '\t\t/* TimStrP2StarServerMax = */ 0,		/* Value is not configurable */\n'
            str += '\t\t/* TimStrP2StarServerMin = */ 0,		/* Value is not configurable */\n'
            str += '\t\t/* TimStrS3Server = */ %s,\n'%(tim.S3Server)
            str += '\t\t/* Arc_EOL = */ FALSE\n'
            str +='\t},\n'
        str += '\t{//%s\n'%('Dummy For EOL');
        str += '\t\t/* TimStrP2ServerMax = */ %s,\n'%('0')
        str += '\t\t/* TimStrP2ServerMin = */ %s,\n'%('0')
        str += '\t\t/* TimStrP2StarServerMax = */ 0,		/* Value is not configurable */\n'
        str += '\t\t/* TimStrP2StarServerMin = */ 0,		/* Value is not configurable */\n'
        str += '\t\t/* TimStrS3Server = */ %s,\n'%('0')
        str += '\t\t/* Arc_EOL = */ TRUE\n'
        str +='\t},\n'
        str += '};\n\n'
        fp.write(str);
        fp.write("""const Dcm_DslProtocolTimingType ProtocolTiming = {
    /* DslProtocolTimingRow = */ ProtocolTimingList
};\n\n""")
        #--------------
        str = 'const Dcm_DslSessionControlType SessionControlList[] = {\n'
        for ses in self.cfg.sessionControlList:
            str += '\t{//%s\n'%(ses.name)
            str += '\t\t /* GetSesChgPermission = */ %s,\n'%(ses.GetSesChgPermission)
            str += '\t\t /* ChangeIndication = */ NULL,\n'
            str += '\t\t /* ConfirmationRespPend = */ NULL,\n'
            str += '\t\t /* Arc_EOL = */ FALSE\n'
            str += '\t},\n'
        str += '\t{//%s\n'%('Dummy For EOL')
        str += '\t\t /* GetSesChgPermission = */ %s,\n'%('NULL')
        str += '\t\t /* ChangeIndication = */ NULL,\n'
        str += '\t\t /* ConfirmationRespPend = */ NULL,\n'
        str += '\t\t /* Arc_EOL = */ TRUE\n'
        str += '\t}\n'
        str += '};\n\n'
        fp.write(str);
        # also I am not sure, so ... ??????
        fp.write("""const Dcm_DslDiagRespType DiagResp = {
    /* DslDiagRespForceRespPendEn = */ %s,
    /* DslDiagRespMaxNumRespPend = */ %s
};\n"""%(TRUE(self.cfg.general.ResponsePending), self.cfg.general.MaxNegativeResponse));

        fp.write("""
const Dcm_DslType Dsl = {
    /* DslBuffer = */ DcmDslBufferList,
    /* DslCallbackDCMRequestService = */ DCMRequestServiceList,
    /* DslDiagResp = */ &DiagResp,
    /* DslProtocol = */ &DslProtocol,
    /* DslProtocolTiming = */ &ProtocolTiming,
    /* DslServiceRequestIndication = */ DCMServiceRequestIndicationList,
    /* DslSessionControl = */ SessionControlList
};

const Dcm_ConfigType DCM_Config = {
    /* Dsp = */ &Dsp,
    /* Dsd = */ &Dsd,
    /* Dsl = */ &Dsl
};
""");
        #------------------------------------------------------------------
        fp.close();
