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
import os, sys
from Common import *
import xml.etree.ElementTree as ET
class CanFilterMaskMscan():
    def __init__(self, name):
        self.name=name;
        self.idam='CAN_IDAM_2_32BIT';
        self.idar=['0', '0','0', '0','0', '0', '0','0'];
        self.idmr=['0xFF', '0xFF', '0xFF', '0xFF', '0xFF', '0xFF', '0xFF', '0xFF'];
    def save(self, root):
        nd = ET.Element('CanFilterMaskMscan');
        nd.attrib['name'] = str(self.name);
        nd.attrib['idam'] = str(self.idam);
        nd.attrib['idar0'] = str(self.idar[0]);
        nd.attrib['idar1'] = str(self.idar[1]);
        nd.attrib['idar2'] = str(self.idar[2]);
        nd.attrib['idar3'] = str(self.idar[3]);
        nd.attrib['idar4'] = str(self.idar[4]);
        nd.attrib['idar5'] = str(self.idar[5]);
        nd.attrib['idar6'] = str(self.idar[6]);
        nd.attrib['idar7'] = str(self.idar[7]);
        nd.attrib['idmr0'] = str(self.idmr[0]);
        nd.attrib['idmr1'] = str(self.idmr[1]);
        nd.attrib['idmr2'] = str(self.idmr[2]);
        nd.attrib['idmr3'] = str(self.idmr[3]);
        nd.attrib['idmr4'] = str(self.idmr[4]);
        nd.attrib['idmr5'] = str(self.idmr[5]);
        nd.attrib['idmr6'] = str(self.idmr[6]);
        nd.attrib['idmr7'] = str(self.idmr[7]);
        root.append(nd);

    def parse(self, node):
        self.idam=node.attrib['idam'];
        self.name=node.attrib['name'];
        self.idar[0]=node.attrib['idar0'];
        self.idar[1]=node.attrib['idar1'];
        self.idar[2]=node.attrib['idar2'];
        self.idar[3]=node.attrib['idar3'];
        self.idar[4]=node.attrib['idar4'];
        self.idar[5]=node.attrib['idar5'];
        self.idar[6]=node.attrib['idar6'];
        self.idar[7]=node.attrib['idar7'];
        self.idmr[0]=node.attrib['idmr0'];
        self.idmr[1]=node.attrib['idmr1'];
        self.idmr[2]=node.attrib['idmr2'];
        self.idmr[3]=node.attrib['idmr3'];
        self.idmr[4]=node.attrib['idmr4'];
        self.idmr[5]=node.attrib['idmr5'];
        self.idmr[6]=node.attrib['idmr6'];
        self.idmr[7]=node.attrib['idmr7'];
class CanHohMscan():
    def __init__(self, name):
        self.name=name;
        self.hohType='CAN_ARC_HANDLE_TYPE_BASIC';
        self.idType ='CAN_ID_TYPE_STANDARD';
        self.idValue =0;
        self.objType= 'CAN_OBJECT_TYPE_RECEIVE';
        self.filterMask = '';
        self.mbMask = '0x00000000';
    def save(self, root):
        nd = ET.Element('CanHohMscan');
        nd.attrib['name'] = str(self.name);
        nd.attrib['hohType'] = str(self.hohType);
        nd.attrib['idType'] = str(self.idType);
        nd.attrib['idValue'] = str(self.idValue);
        nd.attrib['objType'] = str(self.objType);
        nd.attrib['filterMask'] = str(self.filterMask);
        nd.attrib['mbMask'] = str(self.mbMask);
        root.append(nd);

    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.hohType = nd.attrib['hohType'];
        self.idType = nd.attrib['idType'];
        self.idValue = int(nd.attrib['idValue']);
        self.objType = nd.attrib['objType'];
        self.filterMask = nd.attrib['filterMask'];
        self.mbMask = nd.attrib['mbMask'];

class CanCtrlMscan():
    def __init__(self, name):
        self.name = name;
        self.baudrate=250;
        self.propseg=0;
        self.seg1=12;
        self.seg2=1;
        self.hohList=[];
    def save(self, root):
        nd = ET.Element('CanCtrlMscan');
        nd.attrib['name'] = str(self.name);
        nd.attrib['baudrate'] = str(self.baudrate);
        nd.attrib['propseg'] = str(self.propseg);
        nd.attrib['seg1'] = str(self.seg1);
        nd.attrib['seg2'] = str(self.seg2);
        for obj in self.hohList:
            obj.save(nd);
        root.append(nd);
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.baudrate = int(nd.attrib['baudrate']);
        self.propseg = int(nd.attrib['propseg']);
        self.seg1 = int(nd.attrib['seg1']);
        self.seg2 = int(nd.attrib['seg2']);
        for nd2 in nd:
            obj = CanHohMscan('');
            obj.parse(nd2);
            self.hohList.append(obj);

class CanGeneralMscan():
    def __init__(self):
        self.CanDevErrorDetection=True;
        self.CanVersionInfoApi = False;
        self.CanTimeoutDuration=10;

    def save(self, root):
        nd = ET.Element('General');
        nd.attrib['CanDevErrorDetection'] = str(self.CanDevErrorDetection);
        nd.attrib['CanVersionInfoApi'] = str(self.CanVersionInfoApi);
        nd.attrib['CanTimeoutDuration'] = str(self.CanTimeoutDuration);
        root.append(nd);
    def parse(self, nd):
        self.CanDevErrorDetection = bool(nd.attrib['CanDevErrorDetection']);
        self.CanVersionInfoApi = bool(nd.attrib['CanVersionInfoApi']);
        self.CanTimeoutDuration = int(nd.attrib['CanTimeoutDuration']);

class CanCfgMscan():
    def __init__(self):
        self.CanGeneral = CanGeneralMscan();
        self.CanFilterMaskList = [];
        self.CanCtrlList=[];

class gainos_tk_mscan_cfg():
    def __init__(self, chip):
        self.cfg=CanCfgMscan();
    
    def toString(self):
        str='  MSCAN !\n';
        return str;

    def show(self, title, fileInd, module_list= None):
        from cd_mscan import cd_mscan
        dlg=cd_mscan(title, fileInd, self.cfg);
        dlg.setModal(False);
        dlg.show();
        self.dlg = dlg;
        return;

    def save(self, root):
        """保存配置信息"""
        self.cfg.CanGeneral.save(root);
        
        nd = ET.Element('FilterMaskList');
        for obj in self.cfg.CanFilterMaskList:
            obj.save(nd);
        root.append(nd);
        
        nd = ET.Element('CtrlList');
        for obj in self.cfg.CanCtrlList:
            obj.save(nd);
        root.append(nd);

    def parse(self, root):
        self.cfg.CanGeneral.parse(root.find('General'));
        
        list = root.find('FilterMaskList');
        for nd in list:
            obj = CanFilterMaskMscan('unname');
            obj.parse(nd);
            self.cfg.CanFilterMaskList.append(obj);
            
        list = root.find('CtrlList');
        for nd in list:
            obj = CanCtrlMscan('unname');
            obj.parse(nd);
            self.cfg.CanCtrlList.append(obj);
    
    def gen(self, path):
        self.codeGenH(path);
        self.codeGenC(path);

    def codeGenH(self, path):
        file=path+'/Can_Cfg.h';
        fp=open(file, 'w');
        fp.write('#ifndef CAN_CFG_H_\n#define CAN_CFG_H_\n\n');
        fp.write('/* ################ Can General ################ */\n');
        fp.write('#define CAN_DEV_ERROR_DETECT %s\n'%(
                gSTD_ON(self.cfg.CanGeneral.CanDevErrorDetection)));
        fp.write('#define CAN_VERSION_INFO_API %s\n'%(
                gSTD_ON(self.cfg.CanGeneral.CanVersionInfoApi)));
        fp.write('#define CAN_TIMEOUT_DURATION %s /* ms */\n'%(
                self.cfg.CanGeneral.CanTimeoutDuration));
        fp.write('\n/* Number of controller configs */\n')
        fp.write('#define CAN_CTRL_CONFIG_CNT %s\n\n'%(len(self.cfg.CanCtrlList)));
        fp.write('/* Info used by CanIF,index of configure in Can_ControllerCfgData[] */\n');
        index=0;
        for obj in self.cfg.CanCtrlList:
            fp.write('#define INDEX_OF_%s %s\n'%(obj.name,index));
            index+=1;
        fp.write('\n');
        hths=hrhs='typedef enum {\n'
        for obj in self.cfg.CanCtrlList:
            for hoh in obj.hohList:
                if(hoh.objType=='CAN_OBJECT_TYPE_RECEIVE'):
                    hrhs+='\t%s,\n'%(hoh.name);
                elif(hoh.objType=='CAN_OBJECT_TYPE_TRANSMIT'):
                    hths+='\t%s,\n'%(hoh.name);
        hths+='\tNUM_OF_HTHS\n} Can_Arc_HTHType;\n\n'
        hrhs+='\tNUM_OF_HRHS\n} Can_Arc_HRHType;\n\n'
        fp.write(hths);
        fp.write(hrhs);
        fp.write('IMPORT const Can_ConfigType Can_ConfigData;\n');
        fp.write('#endif /* CAN_CFG_H_ */\n\n')
        fp.close();

    def codeGenC(self, path):
        file=path+'/Can_PBcfg.c';
        fp=open(file, 'w');
        fp.write('#include "Can.h"\n#include "Can_Cfg.h"\n\n');
        mask=''
        for obj in self.cfg.CanFilterMaskList:
            mask+='LOCAL const Can_FilterMaskType %s=\n{\n'%(obj.name)
            mask+='\t{%s,%s,%s,%s,%s,%s,%s,%s},\n'%(
                obj.idmr[0],obj.idmr[1],obj.idmr[2],obj.idmr[3],
                obj.idmr[4],obj.idmr[5],obj.idmr[6],obj.idmr[7]);
            mask+='\t{%s,%s,%s,%s,%s,%s,%s,%s},\n'%(
                obj.idar[0],obj.idar[1],obj.idar[2],obj.idar[3],
                obj.idar[4],obj.idar[5],obj.idar[6],obj.idar[7]);
            mask+='\t%s\n'%(obj.idam);
            mask+='};\n\n'
        fp.write(mask);
        hohs='';
        for obj in self.cfg.CanCtrlList:
            hohs+='LOCAL const Can_HardwareObjectType %s_HOHCfgData[]=\n{\n'%(obj.name);
            eol=0;
            for hoh in obj.hohList:
                eol+=1;
                hohs+='\t{\n';
                hohs+='\t\t%s,\n'%(hoh.hohType);
                hohs+='\t\t%s,\n'%(hoh.idType);
                hohs+='\t\t%s,\n'%(hoh.idValue);
                hohs+='\t\t%s,\n'%(hoh.name);
                hohs+='\t\t%s,\n'%(hoh.objType);
                hohs+='\t\t&%s,\n'%(hoh.filterMask);
                hohs+='\t\t%s,/* mbMask */\n'%(hoh.mbMask);
                if(eol==len(obj.hohList)):
                    hohs+='\t\tTRUE\n';
                else:
                    hohs+='\t\tFALSE\n';
                hohs+='\t},\n'
            hohs+='};\n\n';
        fp.write(hohs);
        ctrls='EXPORT const Can_ControllerConfigType  Can_ControllerCfgData[]=\n{\n';
        for obj in self.cfg.CanCtrlList:
            ctrls+='\t{\n';
            ctrls+='\t\t%s,\n'%(obj.name);
            ctrls+='\t\tCAN_PROCESS_TYPE_INTERRUPT,\n\t\tCAN_PROCESS_TYPE_INTERRUPT,\n\t\tCAN_PROCESS_TYPE_INTERRUPT,\n\t\tCAN_PROCESS_TYPE_INTERRUPT,\n';
            ctrls+='\t\t%s, /* baudrate(kbs) */\n'%(obj.baudrate);
            ctrls+='\t\t%s, /* propseg(SJW) */\n'%(obj.propseg);
            ctrls+='\t\t%s, /* seg1 */\n'%(obj.seg1);
            ctrls+='\t\t%s, /* seg2 */\n'%(obj.seg2);
            ctrls+='\t\t%s_HOHCfgData,\n'%(obj.name);
            ctrls+='\t\tFALSE\t/* LoopBack */\n';
            ctrls+='\t},\n';
        ctrls+='};\n';
        fp.write(ctrls);
        fp.write('EXPORT const Can_ConfigSetType Can_ConfigSetData ={Can_ControllerCfgData};\n'); 
        fp.write('EXPORT const Can_ConfigType Can_ConfigData ={&Can_ConfigSetData};\n');
        fp.close();
