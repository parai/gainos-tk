# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
class gainos_tk_default_cfgobj():
    def __init__(self, chip):
        return;

    def show(self, title, fileInd, module_list = None):
        return;
    
    def save(self, root):
        return;
    
    def parse(self, root):
        return;
    
    def gen(self, path):
        return;
    
    def toString(self):
        return 'Not Supported'

from gainos_tk_os_cfg import gainos_tk_os_cfg
from gainos_tk_mscan_cfg import gainos_tk_mscan_cfg
from gainos_tk_ecuc_cfg import gainos_tk_ecuc_cfg
from gainos_tk_canif_cfg import gainos_tk_canif_cfg
from gainos_tk_cantp_cfg import gainos_tk_cantp_cfg
from gainos_tk_pdur_cfg import gainos_tk_pdur_cfg
from gainos_tk_com_cfg import gainos_tk_com_cfg
from gainos_tk_dcm_cfg import gainos_tk_dcm_cfg
#dictionary for MC9S12
gainos_tk_mc9s12_dc ={
    'Adc':gainos_tk_default_cfgobj,   'Can':gainos_tk_mscan_cfg, 
    'CanIf':gainos_tk_canif_cfg, 'CanNm':gainos_tk_default_cfgobj,
    'CanTp':gainos_tk_cantp_cfg, 'CanSm':gainos_tk_default_cfgobj,
    'Com':gainos_tk_com_cfg,   'Dio':gainos_tk_default_cfgobj,
    'Eep':gainos_tk_default_cfgobj,   'EcuC':gainos_tk_ecuc_cfg,
    'Fls':gainos_tk_default_cfgobj,   'Gpt':gainos_tk_default_cfgobj,   
    'Icu':gainos_tk_default_cfgobj,   'Pwm':gainos_tk_default_cfgobj,
    'Port':gainos_tk_default_cfgobj,  'PduR':gainos_tk_pdur_cfg,
    'Spi':gainos_tk_default_cfgobj,   'Wdg':gainos_tk_default_cfgobj,
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_os_cfg, 
    'Dcm':gainos_tk_dcm_cfg}
    
#dictionary for STM32F1
gainos_tk_stm32f1_dc ={
    'Adc':gainos_tk_default_cfgobj,   'Can':gainos_tk_mscan_cfg, 
    'CanIf':gainos_tk_canif_cfg, 'CanNm':gainos_tk_default_cfgobj,
    'CanTp':gainos_tk_cantp_cfg, 'CanSm':gainos_tk_default_cfgobj,
    'Com':gainos_tk_com_cfg,   'Dio':gainos_tk_default_cfgobj,
    'Eep':gainos_tk_default_cfgobj,   'EcuC':gainos_tk_ecuc_cfg,
    'Fls':gainos_tk_default_cfgobj,   'Gpt':gainos_tk_default_cfgobj,   
    'Icu':gainos_tk_default_cfgobj,   'Pwm':gainos_tk_default_cfgobj,
    'Port':gainos_tk_default_cfgobj,  'PduR':gainos_tk_pdur_cfg,
    'Spi':gainos_tk_default_cfgobj,   'Wdg':gainos_tk_default_cfgobj,
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_os_cfg, 
    'Dcm':gainos_tk_dcm_cfg }
 
#dictionary for AT91SAM3S
gainos_tk_at91sam3s_dc ={
    'Adc':gainos_tk_default_cfgobj,   'Can':gainos_tk_default_cfgobj, 
    'CanIf':gainos_tk_default_cfgobj, 'CanNm':gainos_tk_default_cfgobj,
    'CanTp':gainos_tk_default_cfgobj, 'CanSm':gainos_tk_default_cfgobj,
    'Com':gainos_tk_default_cfgobj,   'Dio':gainos_tk_default_cfgobj,
    'Eep':gainos_tk_default_cfgobj,   'EcuC':gainos_tk_default_cfgobj,
    'Fls':gainos_tk_default_cfgobj,   'Gpt':gainos_tk_default_cfgobj,   
    'Icu':gainos_tk_default_cfgobj,   'Pwm':gainos_tk_default_cfgobj,
    'Port':gainos_tk_default_cfgobj,  'PduR':gainos_tk_default_cfgobj,
    'Spi':gainos_tk_default_cfgobj,   'Wdg':gainos_tk_default_cfgobj,
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_os_cfg, 
    'Dcm':gainos_tk_default_cfgobj } 
 
#dictionary for MPC56XX
gainos_tk_mpc56xx_dc ={
    'Adc':gainos_tk_default_cfgobj,   'Can':gainos_tk_default_cfgobj, 
    'CanIf':gainos_tk_default_cfgobj, 'CanNm':gainos_tk_default_cfgobj,
    'CanTp':gainos_tk_default_cfgobj, 'CanSm':gainos_tk_default_cfgobj,
    'Com':gainos_tk_default_cfgobj,   'Dio':gainos_tk_default_cfgobj,
    'Eep':gainos_tk_default_cfgobj,   'EcuC':gainos_tk_default_cfgobj,
    'Fls':gainos_tk_default_cfgobj,   'Gpt':gainos_tk_default_cfgobj,   
    'Icu':gainos_tk_default_cfgobj,   'Pwm':gainos_tk_default_cfgobj,
    'Port':gainos_tk_default_cfgobj,  'PduR':gainos_tk_default_cfgobj,
    'Spi':gainos_tk_default_cfgobj,   'Wdg':gainos_tk_default_cfgobj,
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_os_cfg, 
    'Dcm':gainos_tk_default_cfgobj}   

#common dictionary
gainos_tk_dc = {
    'MC9S12':gainos_tk_mc9s12_dc, 
    'STM32F1':gainos_tk_stm32f1_dc,
    'MPC56XX':gainos_tk_mpc56xx_dc, 
    'AT91SAM3S':gainos_tk_at91sam3s_dc}

class gainos_tk_obj():
    """this an common config obj to store all the info for each module"""
    def __init__(self, chip, module):
        self.chip = chip;
        self.module = module;
        self.obj = gainos_tk_dc[chip][module](chip);
    
    def show(self, fileInd, module_list = None):
        title = '%s For %s, < GaInOS-TK by parai >'%(self.module, self.chip);
        self.obj.show(title, fileInd, module_list);
    
    def save(self, root):
        self.obj.save(root);
    
    def parse(self, root):
        self.obj.parse(root);

    def gen(self, path):
        self.obj.gen(path);
    
    def toString(self):
        return '%s For %s:\n%s\n'%(self.module, self.chip, self.obj.toString())

class gainos_tk_cfg():
    def __init__(self, chip):
        self.chip = chip;
        self.module_list = [];
    
    def findModule(self, module):
        for md in self.module_list:
            if(module == md.module):
                return md;
        return None;
    
    def addModule(self, module):
        if(self.findModule(module) == None):
            md = gainos_tk_obj(self.chip, module);
            self.module_list.append(md);
    
    def delModule(self, module):
        md = self.findModule(module);
        if( md != None):
            self.module_list.remove(md);
    
    def save(self, arxml):
        import xml.etree.ElementTree as ET
        root = ET.Element('gainos_tk_root');
        root.attrib['chip'] =self.chip;
        for md in self.module_list:
            nd = ET.Element('gainos_tk_module');
            nd.attrib['chip'] = md.chip;
            nd.attrib['module'] = md.module;
            md.save(nd);
            root.append(nd);
        tree = ET.ElementTree(root)
        tree.write(arxml, encoding="utf-8", xml_declaration=True);
        return;
    
    def parse(self, root):
        self.chip = root.attrib['chip'];
        for node in root:
            md = gainos_tk_obj(node.attrib['chip'], node.attrib['module']);
            md.parse(node);
            self.module_list.append(md);

    def open(self, arxml):
        """try open arxml,if failed just return."""
        import xml.etree.ElementTree as ET
        #try:  
        root = ET.parse(arxml).getroot();
        self.parse(root);
        #except Exception, e:
        #    print e
        #    return False;
        return True;

    def show(self, module, fileInd):
        md = self.findModule(module);
        md.show(fileInd, self.module_list);

    def gen(self, path):
        for md in self.module_list:
            md.gen(path);
