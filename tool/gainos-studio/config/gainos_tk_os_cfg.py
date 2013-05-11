# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
import xml.etree.ElementTree as ET
class General():
    def __init__(self, chip):
        self.chip = chip;
        self.max_ipl = 15;
        self.max_pri = 32;
        self.os_class = 'ECC2';
        self.status = 'STANDARD';
        self.sched_policy = 'FULL_PREEMPTIVE_SCHEDULE';
    def save(self, root):
        nd = ET.Element('General');
        nd.attrib['chip'] = str(self.chip);
        nd.attrib['max_ipl'] = str(self.max_ipl);
        nd.attrib['max_pri'] = str(self.max_pri);  
        nd.attrib['os_class'] = str(self.os_class);  
        nd.attrib['status'] = str(self.status);  
        nd.attrib['sched_policy'] = str(self.sched_policy);  
        root.append(nd); 
    def parse(self, nd):
        self.chip = nd.attrib['chip'];
        self.max_ipl = int(nd.attrib['max_ipl']);
        self.max_pri = int(nd.attrib['max_pri']);
        self.status = nd.attrib['status'];
        self.status = nd.attrib['status'];
        self.sched_policy = nd.attrib['sched_policy'];
        
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
            obj = Event('', 0);
            obj.parse(nd2);
            self.eventList.append(obj);
class Counter():
    def __init__(self, name):
        self.name=name;
        self.max = 30000;
        self.min = 10;
        self.tpb = 1; #ticks per base

    def save(self, root):
        nd = ET.Element('Counter');
        nd.attrib['name'] = str(self.name);
        nd.attrib['max'] = str(self.max);
        nd.attrib['min'] = str(self.min);
        nd.attrib['tpb'] = str(self.tpb);
        root.append(nd);

    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.max = int(nd.attrib['max']);
        self.min = int(nd.attrib['min']);
        self.tpb = int(nd.attrib['tpb']);

class Alarm():
    def __init__(self, name):
        self.name=name;
        self.counter = ''
        #callback,task,event
        self.type='callback'; 
        self.task='';
        self.event=''; 
    def save(self, root):
        nd = ET.Element('Alarm');
        nd.attrib['name'] = str(self.name);
        nd.attrib['counter'] = str(self.counter);
        nd.attrib['type'] = str(self.type);
        nd.attrib['task'] = str(self.task);
        nd.attrib['event'] = str(self.event);
        root.append(nd); 
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.counter = nd.attrib['counter'];
        self.type = nd.attrib['type'];
        self.task = nd.attrib['task'];
        self.event = nd.attrib['event'];      

class gainos_tk_os_obj():
    def __init__(self, chip):
        self.general = General(chip);
        self.taskList=[];
        self.resourceList=[];
        self.counterList = [];
        self.alarmList=[];

class gainos_tk_os_cfg():
    def __init__(self, chip):
        self.dlg = None;
        self.cfg = gainos_tk_os_obj(chip);
        self.cfg.general.chip = chip;
        return;

    def show(self, title, fileInd):
        from cd_gainos_tk_os import cd_gainos_tk_os;
        self.dlg  = cd_gainos_tk_os(title, fileInd, self.cfg);
        self.dlg.setModal(False);
        self.dlg.show();
        return;
    
    def save(self, root):
        self.cfg.general.save(root);
        nd = ET.Element('TaskList');
        for task in self.cfg.taskList:
            task.save(nd);
        root.append(nd);
        
        nd = ET.Element('ResurceList');
        for res in self.cfg.resourceList:
            res.save(nd);
        root.append(nd);
        
        nd = ET.Element('CounterList');
        for cnt in self.cfg.counterList:
            cnt.save(nd);
        root.append(nd);
    
        nd = ET.Element('AlarmList');
        for alm in self.cfg.alarmList:
            alm.save(nd);
        root.append(nd);
    
    def parse(self, root):
        self.cfg.general.parse(root.find('General'));
        
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
            
        list = root.find('CounterList');
        for nd in list:
            obj = Counter('unname');
            obj.parse(nd);
            self.cfg.counterList.append(obj);
            
        list = root.find('AlarmList');
        for nd in list:
            obj = Alarm('unname');
            obj.parse(nd);
            self.cfg.alarmList.append(obj);

    def gen(self, path):
        self.genC(path);
        self.genH(path);
        self.genApp(path);
    
    def toString(self):
        return 'OSEK OS Supported!'

    def genH(self, path):
        fp=open('%s/osek_cfg.h'%(path), 'w');
        fp.write(
"""
/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio. Don't Modify it by hand.
 */
#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
/* =====================  MISC  ========================== */
""");
        fp.write('#define cfgOS_STATUS_LEVEL OS_STATUS_%s\n'%(self.cfg.general.status));
        fp.write('#define CHIP_%s\n'%(self.cfg.general.chip));
        fp.write("""#if defined(CHIP_MC9S12) //9s12
#define CPU_FREQUENCY        32000000 /* HZ */
#define OSC_FREQUENCY         8000000 /* HZ */
#elif defined(CHIP_STM32F1)//stm32
#define CPU_FREQUENCY        72000000 /* HZ */
#elif defined(CHIP_AT91SAM3S)
#define CPU_FREQUENCY        64000000 /* HZ */
#elif defined(CHIP_MPC56XX)
#define CPU_FREQUENCY  64000000   /* HZ */
#define OSC_FREQUENCY  8000000    /* Oscillator Clock 8MHZ */
#endif\n\n""")
        #===============================Task ================================
        fp.write('/* =====================  TASK  ========================== */\n');
        fp.write('#define cfgOSEK_MAX_PRIO %s\n'%(self.cfg.general.max_pri));
        fp.write('#define cfgOSEK_TASK_NUM  %s\n'%(len(self.cfg.taskList)));
        id = 0;
        for obj in self.cfg.taskList:
            fp.write('#define ID_%s %s\n'%(obj.name,id))
            id+=1;
        for obj in self.cfg.taskList:
            fp.write('IMPORT TASK(%s);\n'%(obj.name));
        #==================================== EVENT ================================
        fp.write('\n/* =====================  EVENT ========================== */\n')
        id = 0;
        for tsk in self.cfg.taskList:
            if(len(tsk.eventList) > 0):
                fp.write('#define ID_%sEvent %s\n'%(tsk.name,id));
                id += 1;
                for obj in tsk.eventList:
                    fp.write('#define %s %s\n'%(obj.name,obj.mask));
        fp.write('#define cfgOSEK_EVENTFLAG_NUM %s\n'%(id));
        #=================================== ALARM ==========================
        fp.write('\n/* =====================  ALARM ========================== */\n');
        fp.write('#define cfgOSEK_COUNTER_NUM %s\n'%len((self.cfg.counterList)));
        id = 0;
        for obj in self.cfg.counterList:
            fp.write('#define ID_%s %s\n'%(obj.name,id));
            id += 1;
        fp.write('#define cfgOSEK_ALARM_NUM %s\n'%(len(self.cfg.alarmList)));
        id = 0;
        for obj in self.cfg.alarmList:
            fp.write('#define ID_%s %s\n'%(obj.name,id));
            fp.write('IMPORT ALARM(%s);\n'%(obj.name));
            id+=1;
        #=============================== RESOURCE ======================
        fp.write('\n/*  ====================  RESOURCE ======================= */\n');
        fp.write('#define cfgOSEK_RESOURCE_NUM %s\n'%(len(self.cfg.resourceList)));
        id = 0;
        for obj in self.cfg.resourceList:
            fp.write('#define ID_%s %s\n'%(obj.name,id));
            id += 0;
        #=========================== End =========================
        fp.write("""
/*  ====================  HOOKs    ======================= */
#define cfgOS_SHUT_DOWN_HOOK 0
#define cfgOS_START_UP_HOOK  0
#endif /* _OSEK_CFG_H_ */\n""");
        fp.close();
    
    def genC(self, path):
        fp=open('%s/osek_cfg.c'%(path), 'w');
        fp.write("""
/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio. Don't Modify it by hand.
 */
#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"
#include "knl_alarm.h"
#include "knl_event.h"
#include <stdio.h>\n""");
        stack = '';
        gtsk = 'EXPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM]=\n{\n';
        for tsk in self.cfg.taskList:
            stack += 'GenTaskStack(%s,%s);\n'%(tsk.name, tsk.stksz);
            gtsk += '\tGenTaskInfo(%s,%s,%s,'%(tsk.name, tsk.prio, tsk.stksz);
            if(tsk.autostart):
                gtsk += 'AUTOSTART,';
            else:
                gtsk += '0,';
            if(len(tsk.eventList)>0):
                gtsk += 'ID_%sEvent),\n'%(tsk.name);
            else:
                gtsk += 'INVALID_EVENT),\n'
        gtsk += '};\n\n';
        fp.write(stack);
        fp.write(gtsk);
        #================== Counter ==========================
        str = 'EXPORT const AlarmBaseType knl_almbase_table[cfgOSEK_COUNTER_NUM]=\n{\n';
        for obj in self.cfg.counterList:
            str += '\tGenAlarmBaseInfo(%s,%s,%s), /* %s */\n'%(obj.max, obj.tpb, obj.min, obj.name);
        str+='};\n\n'
        fp.write(str);
        #==================== ALARM =======================
        str = 'EXPORT const T_GALM knl_galm_table[cfgOSEK_ALARM_NUM]=\n{\n';
        for obj in self.cfg.alarmList:
            str += '\tGenAlarmInfo(%s,%s),\n'%(obj.name, obj.counter);
        str+='};\n\n'
        fp.write(str);
        #======================= RESOURCE ==============
        str = 'EXPORT const PRI knl_gres_table[cfgOSEK_RESOURCE_NUM]=\n{\n'
        for obj in self.cfg.resourceList:
            str += '\t/* ceilpri */ %s,  /* %s */\n'%(obj.ceilprio, obj.name);
        str+='};\n\n'
        fp.write(str);
        #================================= end ===============
        fp.close();
    
    def genApp(self, path):
        fp = open('%s/app.template.c'%(path), 'w');
        fp.write("""
/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio. 
 * This is a template for "app.c", you can add your application code here.
 */\n""")
        fp.write('#include "Os.h"\n#include <stdio.h>\n\n');
        for tsk in self.cfg.taskList:
            fp.write("""
TASK(%s)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    printf("%s is running.\\r\\n");
    (void)TerminateTask();
}\n"""%(tsk.name, tsk.name))
        for obj in self.cfg.alarmList:
            if(obj.type == 'callback'):
                fp.write("""
ALARM(%s)
{
    /* Alarm Type: Callback, Add your code here. */
}"""%(obj.name));
            elif(obj.type == 'task'):
                fp.write("""
ALARM(%s)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_%s);
}"""%(obj.name, obj.task));
            elif(obj.type == 'event'):
                fp.write("""
ALARM(%s)
{
    /* Alarm Type: Event, you still can add your special code here.*/
    (void)SetEvent(ID_%s,%s);
}"""%(obj.name, obj.task, obj.event));
