# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
class gainos_tk_dcm_cfg():
    def __init__(self, chip=None):
        self.cfg = None;
        return;

    def toString(self):
        str='Dcm!\n';
        return str;

    def show(self, title, fileInd, module_list = None):
        from cd_dcm import cd_dcm
        self.dlg  = cd_dcm(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
   
    def save(self, root):
        return;
    
    def parse(self, root):
        return;

    def gen(self, path):
        return;
  
