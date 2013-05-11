# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
class gainos_tk_default_cfgobj():
    def __init__(self):
        return;

    def show(self):
        return;
    
    def save(self):
        return;
    
    def gen(self):
        return;
    
    def toString(self):
        return 'Not Supported'

#dictionary for MC9S12
gainos_tk_mc9s12_dc ={
    'Adc':gainos_tk_default_cfgobj,   'Can':gainos_tk_default_cfgobj, 
    'CanIf':gainos_tk_default_cfgobj, 'CanNm':gainos_tk_default_cfgobj,
    'CanTp':gainos_tk_default_cfgobj, 'CanSm':gainos_tk_default_cfgobj,
    'Com':gainos_tk_default_cfgobj,   'Dio':gainos_tk_default_cfgobj,
    'Eep':gainos_tk_default_cfgobj,   'EcuC':gainos_tk_default_cfgobj,
    'Fls':gainos_tk_default_cfgobj,   'Gpt':gainos_tk_default_cfgobj,   
    'Icu':gainos_tk_default_cfgobj,   'Pwm':gainos_tk_default_cfgobj,
    'Port':gainos_tk_default_cfgobj,  'PduR':gainos_tk_default_cfgobj,
    'Spi':gainos_tk_default_cfgobj,   'Wdg':gainos_tk_default_cfgobj,
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_default_cfgobj}
    
#dictionary for STM32F1
gainos_tk_stm32f1_dc ={
    'Adc':gainos_tk_default_cfgobj,   'Can':gainos_tk_default_cfgobj, 
    'CanIf':gainos_tk_default_cfgobj, 'CanNm':gainos_tk_default_cfgobj,
    'CanTp':gainos_tk_default_cfgobj, 'CanSm':gainos_tk_default_cfgobj,
    'Com':gainos_tk_default_cfgobj,   'Dio':gainos_tk_default_cfgobj,
    'Eep':gainos_tk_default_cfgobj,   'EcuC':gainos_tk_default_cfgobj,
    'Fls':gainos_tk_default_cfgobj,   'Gpt':gainos_tk_default_cfgobj,   
    'Icu':gainos_tk_default_cfgobj,   'Pwm':gainos_tk_default_cfgobj,
    'Port':gainos_tk_default_cfgobj,  'PduR':gainos_tk_default_cfgobj,
    'Spi':gainos_tk_default_cfgobj,   'Wdg':gainos_tk_default_cfgobj,
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_default_cfgobj} 
 
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
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_default_cfgobj}  
 
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
    'WdgIf':gainos_tk_default_cfgobj, 'OS':gainos_tk_default_cfgobj}   

#common dictionary
gainos_tk_dc = {
    'MC9S12':gainos_tk_mc9s12_dc, 
    'STM32F1':gainos_tk_stm32f1_dc,
    'MPC56XX':gainos_tk_mpc56xx_dc, 
    'AT91SAM3S':gainos_tk_at91sam3s_dc
    
}
class gainos_tk_obj():
    """this an common config obj to store all the info for each module"""
    def __init__(self, chip, module):
        self.chip = chip;
        self.module = module;
        self.obj = gainos_tk_dc[chip][module]();
    
    def show(self):
        return;
    
    def save(self):
        return;
    
    def gen(self):
        return;
    
    def toString(self):
        return '%s For %s:\n%s.\n'%(self.module, self.chip, self.obj.toString())

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
        
