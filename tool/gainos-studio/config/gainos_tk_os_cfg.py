# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
"""
import xml.etree.ElementTree as ET
from Common import *
class General():
    def __init__(self, chip):
        self.chip = chip;
        self.max_ipl = 15;
        self.max_pri = 32;
        self.os_class = 'ECC2';
        self.status = 'STANDARD';
        self.sched_policy = 'MIXED_PREEMPTIVE_SCHEDULE';
        self.tk_extend = False;
        self.os_startup_hook = True;
        self.os_shutdown_hook = False;
        self.os_pretask_hook = False;
        self.os_post_task_hook = False;
        self.os_error_hook = False;
        self.os_stack_overflow_check = False;
        self.system_stack_size = 512;
        self.share_system_stack = False;
    def save(self, root):
        nd = ET.Element('General');
        nd.attrib['chip'] = str(self.chip);
        nd.attrib['max_ipl'] = str(self.max_ipl);
        nd.attrib['max_pri'] = str(self.max_pri);  
        nd.attrib['os_class'] = str(self.os_class);  
        nd.attrib['status'] = str(self.status);  
        nd.attrib['sched_policy'] = str(self.sched_policy);  
        nd.attrib['tk_extend'] = str(self.tk_extend);  
        nd.attrib['os_startup_hook'] = str(self.os_startup_hook);  
        nd.attrib['os_shutdown_hook'] = str(self.os_shutdown_hook);  
        nd.attrib['os_pretask_hook'] = str(self.os_pretask_hook);  
        nd.attrib['os_post_task_hook'] = str(self.os_post_task_hook);  
        nd.attrib['os_error_hook'] = str(self.os_error_hook);  
        nd.attrib['os_stack_overflow_check'] = str(self.os_stack_overflow_check);  
        nd.attrib['system_stack_size'] = str(self.system_stack_size);  
        nd.attrib['share_system_stack'] = str(self.share_system_stack);  
        root.append(nd); 
    def parse(self, nd):
        self.chip = nd.attrib['chip'];
        self.max_ipl = int(nd.attrib['max_ipl']);
        self.max_pri = int(nd.attrib['max_pri']);
        self.os_class = nd.attrib['os_class'];
        self.status = nd.attrib['status'];
        self.sched_policy = nd.attrib['sched_policy'];
        self.tk_extend = bool(nd.attrib['tk_extend']);
        self.os_startup_hook = bool(nd.attrib['os_startup_hook']);
        self.os_shutdown_hook = bool(nd.attrib['os_shutdown_hook']);
        self.os_pretask_hook = bool(nd.attrib['os_pretask_hook']);
        self.os_post_task_hook = bool(nd.attrib['os_post_task_hook']);
        self.os_error_hook = bool(nd.attrib['os_error_hook']);
        self.os_stack_overflow_check = bool(nd.attrib['os_stack_overflow_check']);
        self.system_stack_size = int(nd.attrib['system_stack_size']);
        self.share_system_stack = bool(nd.attrib['share_system_stack']);
        
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
        self.maxactcnt = 1;
        self.appmode = [];
        self.preemtable = True;
        self.eventList=[];
    
    def save(self, root):
        nd = ET.Element('Task');
        nd.attrib['name'] = str(self.name);
        nd.attrib['prio'] = str(self.prio);
        nd.attrib['stksz'] = str(self.stksz);
        nd.attrib['autostart'] = str(self.autostart);
        nd.attrib['maxactcnt'] = str(self.maxactcnt);
        #nd.attrib['appmode'] = str(self.appmode);
        nd2 = ET.Element('appmode');
        for mode in self.appmode:
            nd2.append(ET.Element(str(mode)));
        nd.append(nd2);
        nd.attrib['preemtable'] = str(self.preemtable);
        nd2 = ET.Element('eventList');
        for obj in self.eventList:
            obj.save(nd2);
        nd.append(nd2);
        root.append(nd);
    
    def parse(self, nd):
        self.name = nd.attrib['name'];
        self.prio = int(nd.attrib['prio']);
        self.stksz = int(nd.attrib['stksz']);
        self.autostart = bool(nd.attrib['autostart']);
        self.maxactcnt = int(nd.attrib['maxactcnt']);
        nd2 = ET.Element('appmode');
        for nd2 in nd.find('appmode'):
            self.appmode.append(nd2.tag);
        nd.append(nd2);
        self.preemtable = bool(nd.attrib['preemtable']);
        for nd2 in nd.find('eventList'):
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
class AppMode():
    def __init__(self, name):
        self.name = name;
    def save(self, root):
        nd = ET.Element('AppMode');
        nd.attrib['name'] = str(self.name);
        root.append(nd); 
    def parse(self, nd):
        self.name = nd.attrib['name'];
class gainos_tk_os_obj():
    def __init__(self, chip):
        self.general = General(chip);
        self.taskList=[];
        self.resourceList=[];
        self.counterList = [];
        self.alarmList=[];
        self.appmodeList = [];
        self.appmodeList.append(AppMode('OSDEFAULTAPPMODE'));

class gainos_tk_os_cfg():
    def __init__(self, chip):
        self.dlg = None;
        self.cfg = gainos_tk_os_obj(chip);
        self.cfg.general.chip = chip;
        return;

    def show(self, title, fileInd, module_list = None):
        from cd_os import cd_os;
        self.dlg  = cd_os(title, fileInd, self.cfg);
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

        nd = ET.Element('AppModeList');
        for mode in self.cfg.appmodeList:
            if(mode.name != 'OSDEFAULTAPPMODE'):
                mode.save(nd);
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

        list = root.find('AppModeList');
        for nd in list:
            obj = AppMode('unname');
            obj.parse(nd);
            self.cfg.appmodeList.append(obj);

    def gen(self, path):
        self.genC(path);
        self.genH(path);
        self.genApp(path);
    
    def toString(self):
        return 'OSEK OS Supported!'

    def genH(self, path):
        fp=open('%s/osek_cfg.h'%(path), 'w');
        fp.write(gcGainOS_TkHead());
        fp.write(
"""
#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
/* =====================  MISC  ========================== */
""");
        fp.write('#define FULL_PREEMPTIVE_SCHEDULE  0\n');
        fp.write('#define MIXED_PREEMPTIVE_SCHEDULE 1\n');
        fp.write('#define NONE_PREEMPTIVE_SCHEDULE  2\n');
        fp.write('#define cfgOS_SCHEDULE_POLICY %s\n'%(self.cfg.general.sched_policy));
        fp.write('#define cfgOS_CONFORMANCE_CLASS %s\n'%(self.cfg.general.os_class))
        fp.write('#define cfgOS_STATUS_LEVEL OS_STATUS_%s\n'%(self.cfg.general.status));
        fp.write('#define cfgOS_TK_EXTEND %s\n'%(gSTD_ON(self.cfg.general.tk_extend)));
        fp.write('#define cfgOS_SYSTEM_STACK_SIZE %s\n'%(self.cfg.general.system_stack_size));
        fp.write('#define cfgOS_SHARE_SYSTEM_STACK %s\n'%(gSTD_ON(self.cfg.general.share_system_stack)))
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
        fp.write('/* App Mode */\n')
        id = 2;
        for appmode in self.cfg.appmodeList:
            if(appmode.name != 'OSDEFAULTAPPMODE'):
                fp.write('#define %s %s\n'%(appmode.name,hex(id)));
                id *= 2;
        #===============================Task ================================
        fp.write('/* =====================  TASK  ========================== */\n');
        fp.write('#define cfgOSEK_MAX_PRIO %s\n'%(self.cfg.general.max_pri));
        fp.write('#define cfgOSEK_TASK_NUM  %s\n'%(len(self.cfg.taskList)));
        id = 0;
        for obj in self.cfg.taskList:
            fp.write('#define ID_%s %s\n'%(obj.name,id))
            id+=1;
        for obj in self.cfg.taskList:
            fp.write('#define %sPri PRIORITY(%s)\n'%(obj.name, obj.prio))
        for obj in self.cfg.taskList:
            fp.write('#define %sStkSz %s\n'%(obj.name,obj.stksz))
        for obj in self.cfg.taskList:
            fp.write('#define %sMaxAct %s\n'%(obj.name,obj.maxactcnt))
        for obj in self.cfg.taskList:
            str = ' OSNONEAPPMODE '
            if(obj.autostart):
                for mode in obj.appmode:
                    str += '| %s '%(mode);
            fp.write('#define %sMode (%s)\n'%(obj.name,str));
        fp.write('#if !defined(MACROS_ONLY)\n')
        for obj in self.cfg.taskList:
            fp.write('IMPORT TASK(%s);\n'%(obj.name));
        fp.write('#endif')
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
            id+=1;
        fp.write('#if !defined(MACROS_ONLY)\n')
        for obj in self.cfg.alarmList:
            fp.write('IMPORT ALARM(%s);\n'%(obj.name));
        fp.write('#endif')
        #=============================== RESOURCE ======================
        fp.write('\n/*  ====================  RESOURCE ======================= */\n');
        fp.write('#define cfgOSEK_RESOURCE_NUM %s\n'%(len(self.cfg.resourceList)));
        id = 0;
        for obj in self.cfg.resourceList:
            fp.write('#define ID_%s %s\n'%(obj.name,id));
            fp.write('#define %sPri PRIORITY(%s)\n'%(obj.name,obj.ceilprio))
            id += 0;
        #=========================== End =========================
        fp.write('/*  ====================  HOOKs    ======================= */\n');
        fp.write('#define cfgOS_STACK_USAGE_CHECK %s\n'%(gSTD_ON(self.cfg.general.os_stack_overflow_check)));
        fp.write('#define cfgOS_SHUT_DOWN_HOOK %s\n'%(gSTD_ON(self.cfg.general.os_shutdown_hook)));
        fp.write('#define cfgOS_START_UP_HOOK %s\n'%(gSTD_ON(self.cfg.general.os_startup_hook)));
        fp.write('#define cfgOS_ERROR_HOOK %s\n'%(gSTD_ON(self.cfg.general.os_error_hook)));
        fp.write('#define cfgOS_PRE_TASK_HOOK %s\n'%(gSTD_ON(self.cfg.general.os_pretask_hook)));
        fp.write('#define cfgOS_POST_TASK_HOOK %s\n'%(gSTD_ON(self.cfg.general.os_post_task_hook)));
        fp.write('#endif /* _OSEK_CFG_H_ */\n\n')
        fp.close();
    
    def genC(self, path):
        fp=open('%s/osek_cfg.c'%(path), 'w');
        fp.write(gcGainOS_TkHead());
        fp.write("""
#include "osek_os.h"
#include "osek_cfg.h"
#include "knl_task.h"
#include "knl_alarm.h"
#include "knl_event.h"
#include <stdio.h>\n""");
        stack = '';
        gtsk = 'EXPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM]=\n{\n';
        for tsk in self.cfg.taskList:
            stack += 'GenTaskStack(%s);\n'%(tsk.name);
            gtsk += '\tGenTaskInfo(%s,'%(tsk.name);
            gtsk += '%sMode'%(tsk.name);
            if(self.cfg.general.sched_policy == 'MIXED_PREEMPTIVE_SCHEDULE'):
                if(tsk.preemtable):
                    gtsk += '|PREEMTABLE,'
                else:
                    gtsk += '|NON_PREEMTABLE,'
            elif(self.cfg.general.sched_policy == 'FULL_PREEMPTIVE_SCHEDULE'):
                gtsk += '|PREEMTABLE,'
            elif(self.cfg.general.sched_policy == 'NONE_PREEMPTIVE_SCHEDULE'):
                gtsk += '|NON_PREEMTABLE,'
            if(len(tsk.eventList)>0):
                gtsk += 'ID_%sEvent,'%(tsk.name);
            else:
                gtsk += 'INVALID_EVENT,'
            #gtsk += '%s,'%(tsk.maxactcnt);
            if(self.cfg.general.sched_policy == 'MIXED_PREEMPTIVE_SCHEDULE'):
                if(tsk.preemtable):
                    gtsk += '%sPri),\n'%(tsk.name);
                else:
                    gtsk += 'OS_HIGHEST_PRIORITY),\n'
            elif(self.cfg.general.sched_policy == 'FULL_PREEMPTIVE_SCHEDULE'):
                gtsk += '%sPri),\n'%(tsk.name);
            elif(self.cfg.general.sched_policy == 'NONE_PREEMPTIVE_SCHEDULE'):
                gtsk += 'OS_HIGHEST_PRIORITY),\n'
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
            str += '\t/* ceilpri */ %sPri,  /* %s */\n'%(obj.name, obj.name);
        str+='};\n\n'
        fp.write(str);
        #================================= end ===============
        fp.close();
    
    def genApp(self, path):
        fp = open('%s/app.template'%(path), 'w');
        fp.write(gcGainOS_TkHead());
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

        if(self.cfg.general.os_startup_hook):
            fp.write("""
            
void StartupHook(void)
{
    /* Add Code Here */
}\n""")
        if(self.cfg.general.os_shutdown_hook):
            fp.write("""
void ShutdownHook(StatusType Error)
{
    /* Add Code Here */
}\n""")
        if(self.cfg.general.os_pretask_hook):
            fp.write("""
void PreTaskHook(void)
{
    /* Add Code Here */
}\n""")
        if(self.cfg.general.os_post_task_hook):
            fp.write("""
void PostTaskHook(void)
{
    /* Add Code Here */
}\n""")
        if(self.cfg.general.os_error_hook):
            fp.write("""
void ErrorHook(StatusType Error)
{
    /* Add Code Here */
}\n""")
