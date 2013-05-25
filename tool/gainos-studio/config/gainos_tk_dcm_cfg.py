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
class gainos_tk_dcm_obj():
    def __init__(self):
        self.general = DcmGeneral();
        self.bufferList = [];
    def save(self, root):
        self.general.save(root);
        
        nd = ET.Element('DcmBufferList');
        for obj in self.bufferList:
            obj.save(nd);
        root.append(nd);
        
    def parse(self, root):
        self.general.parse(root.find("General"));
  
        for nd in root.find('DcmBufferList'):
            obj = DcmBuffer('');
            obj.parse(nd);
            self.bufferList.append(obj);
        
class gainos_tk_dcm_cfg():
    def __init__(self, chip=None):
        self.cfg = gainos_tk_dcm_obj();

    def toString(self):
        str='Dcm!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_dcm import cd_dcm
        self.dlg  = cd_dcm(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        self.cfg.save(root);
    
    def parse(self, root):
        self.cfg.parse(root);

    def gen(self, path):
        return;
  
