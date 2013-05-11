# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
import xml.etree.ElementTree as ET
class Resource():
    def __init__(self, name, ceilprio):
        self.name=name;
        self.ceilprio=ceilprio;
    def save(self, root):
        nd = ET.Element('Resource');
        nd.attrib['name'] = str(self.name);
        nd.attrib['ceilprio'] = str(self.ceilprio);  
        root.append(nd); 
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.ceilprio = int(nd.attrib['ceilprio']);

class Event():
    def __init__(self, name, mask):
        self.name=name;
        self.mask=mask;
    def save(self, root):
        nd = ET.Element('Event');
        nd.attrib['name'] = str(self.name);
        nd.attrib['mask'] = str(self.mask); 
        root.append(nd); 

    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.mask = nd.attrib['mask'];
    
class Task():
    def __init__(self, name, prio, stksz):
        self.name=name;
        self.prio=prio;
        self.stksz=stksz;
        self.autostart=True;
        self.eventList=[];
    
    def save(self, root):
        nd = ET.Element('Task');
        nd.attrib['name'] = str(self.name);
        nd.attrib['prio'] = str(self.prio);
        nd.attrib['stksz'] = str(self.stksz);
        nd.attrib['autostart'] = str(self.autostart);
        for obj in self.eventList:
            obj.save(nd);
        root.append(nd);
    
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.prio = int(nd.attrib['prio']);
        self.stksz = int(nd.attrib['stksz']);
        self.autostart = bool(nd.attrib['autostart']);
        for nd2 in nd:
            obj = Event('');
            obj.parse(nd2);
            self.eventList.append(obj);

class Alarm():
    def __init__(self, name):
        self.name=name;
        #callback,task,event
        self.type='callback'; 
        self.task='';
        self.event=''; 
    def save(self, root):
        nd = ET.Element('Alarm');
        nd.attrib['name'] = str(self.name);
        nd.attrib['type'] = str(self.type);
        nd.attrib['task'] = str(self.task);
        nd.attrib['event'] = str(self.event);
        root.append(nd); 
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.type = nd.attrib['type'];
        self.task = nd.attrib['task'];
        self.event = nd.attrib['event'];      

class gainos_tk_os_obj():
    def __init__(self):
        self.taskList=[];
        self.resourceList=[];
        self.alarmList=[];

class gainos_tk_os_cfg():
    def __init__(self):
        self.dlg = None;
        self.cfg = gainos_tk_os_obj();
        return;

    def show(self, title, fileInd):
        from cd_gainos_tk_os import cd_gainos_tk_os;
        self.dlg  = cd_gainos_tk_os(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
        return;
    
    def save(self, root):
        nd = ET.Element('TaskList');
        for task in self.cfg.taskList:
            task.save(nd);
        root.append(nd);
        
        nd = ET.Element('ResurceList');
        for res in self.cfg.resourceList:
            res.save(nd);
        root.append(nd);
        
        nd = ET.Element('AlarmList');
        for alm in self.cfg.alarmList:
            alm.save(nd);
        root.append(nd);
    
    def parse(self, root):
        list = root.find('TaskList');
        for nd in list:
            obj = Task('unname', 0, 0);
            obj.parse(nd);
            self.cfg.taskList.append(obj);
    
        list = root.find('ResurceList');
        for nd in list:
            obj = Resource('unname', 0);
            obj.parse(nd);
            self.cfg.resourceList.append(obj);

        list = root.find('AlarmList');
        for nd in list:
            obj = Alarm('unname');
            obj.parse(nd);
            self.cfg.alarmList.append(obj);

    def gen(self):
        return;
    
    def toString(self):
        return 'Supported'
