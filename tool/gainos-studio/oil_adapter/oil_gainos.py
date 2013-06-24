# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai). All rights reserved.
 *
 * This file is part of GaInOS-Studio.
 */
 This version is just for oil25
"""
import re, string, os
from config.gainos_tk_cfg import gainos_tk_cfg
from common.Common import *
from config.gainos_tk_os_cfg import *
#定义所有正则表达式
# 1: for comment 
re_comment_type1 = re.compile(r'/\*[^/]*\*/');
re_comment_type2 = re.compile(r'//.*');
## include 
re_include = re.compile(r'\s*#include\s+["<]([^\s]+)[">]');

# 2: for os obj
re_oil_os_obj = re.compile(r'^\s*OS|^\s*TASK|^\s*ALARM|^\s*COUNTER|^\s*RESOURCE||^\s*EVENT')
re_oil_os_obj_type_name = re.compile(r"""
    ^\s*(OS)\s*(\w+)
    |^\s*(TASK)\s*(\w+)
    |^\s*(ALARM)\s*(\w+)
    |^\s*(COUNTER)\s*(\w+)
    |^\s*(RESOURCE)\s*(\w+)
    """, re.VERBOSE)
# 3: for os <general>    
re_oil_os_general = re.compile(r'^\s*(OS)\s*(\w+)')
re_general_STATUS = re.compile(r'STATUS\s*=\s*(\w+)\s*;')
re_general_ERRORHOOK = re.compile(r'ERRORHOOK\s*=\s*(\w+)\s*;')
re_general_PRETASKHOOK = re.compile(r'PRETASKHOOK\s*=\s*(\w+)\s*;')
re_general_POSTTASKHOOK = re.compile(r'POSTTASKHOOK\s*=\s*(\w+)\s*;')
re_general_SHUTDOWNHOOK = re.compile(r'SHUTDOWNHOOK\s*=\s*(\w+)\s*;')
re_general_STARTUPHOOK = re.compile(r'STARTUPHOOK\s*=\s*(\w+)\s*;')
re_general_SystemTimer = re.compile(r'SystemTimer\s*=\s*(\w+)\s*;')
re_general_TickTime = re.compile(r'TickTime\s*=\s*(\w+)\s*;')

# 4: for task
re_oil_os_task = re.compile(r'^\s*(TASK)\s*(\w+)')
re_task_SCHEDULE = re.compile(r'SCHEDULE\s*=\s*(\w+)\s*;')
re_task_PRIORITY = re.compile(r'PRIORITY\s*=\s*(\w+)\s*;')
re_task_ACTIVATION = re.compile(r'ACTIVATION\s*=\s*(\w+)\s*;')
re_task_AUTOSTART = re.compile(r'AUTOSTART\s*=\s*(\w+)\s*[;{]')
re_task_StackSize = re.compile(r'StackSize\s*=\s*(\w+)\s*;')
re_task_appmode_list = re.compile(r'AUTOSTART\s*=\s*TRUE\s*{([^{}]*)}\s*;')
re_task_APPMODE = re.compile(r'APPMODE\s*=\s*(\w+)')
re_task_RESOURCE = re.compile(r'RESOURCE\s*=\s*(\w+)')
re_task_EVENT = re.compile(r'EVENT\s*=\s*(\w+)')

# 6: for counter
re_oil_os_counter = re.compile(r'^\s*(COUNTER)\s*(\w+)')
re_counter_MAXALLOWEDVALUE = re.compile(r'MAXALLOWEDVALUE\s*=\s*(\w+)\s*;')
re_counter_TICKSPERBASE = re.compile(r'TICKSPERBASE\s*=\s*(\w+)\s*;')
re_counter_MINCYCLE = re.compile(r'MINCYCLE\s*=\s*(\w+)\s*;')

# 5: for alarm
re_oil_os_alarm = re.compile(r'^\s*(ALARM)\s*(\w+)')
re_alarm_COUNTER = re.compile(r'COUNTER\s*=\s*(\w+)\s*;')
re_alarm_ACTION = re.compile(r'ACTION\s*=\s*(ACTIVATETASK|SETEVENT|ALARMCALLBACK)\s*{([^{}]+)}\s*;')
re_action_TASK = re.compile(r'TASK\s*=\s*(\w+)\s*;')
re_action_EVENT = re.compile(r'EVENT\s*=\s*(\w+)\s*;')
re_action_ALARMCALLBACKNAME = re.compile(r'ALARMCALLBACKNAME\s*=\s*(\w+)\s*;')
re_alarm_AUTOSTART = re.compile(r'AUTOSTART\s*=\s*(\w+)\s*[;{]')
re_alarm_appmode_list = re.compile(r'AUTOSTART\s*=\s*TRUE\s*{([^{}]*)}\s*;')
re_alarm_APPMODE = re.compile(r'APPMODE\s*=\s*(\w+)')
re_alarm_ALARMTIME = re.compile(r'ALARMTIME\s*=\s*(\w+)')
re_alarm_CYCLETIME = re.compile(r'CYCLETIME\s*=\s*(\w+)')

# 6: for resource
re_oil_os_resource = re.compile(r'^\s*(RESOURCE)\s*(\w+)')
re_resource_property = re.compile(r'RESOURCEPROPERTY\s*=\s*(STANDARD|LINKED|INTERNAL)\s*;')

# 7: for event
re_oil_os_event = re.compile(r'^\s*(EVENT)\s*(\w+)')
re_event_MASK = re.compile(r'MASK\s*=\s*(\w+)\s*;')

def filter_out_comment(text):
    """text should be just a line"""
    #过滤形如 “/* .. */” 的注释
    grp = re_comment_type1.split(text)
    result = string.join(grp);
    #过滤形如 “//....” 的注释
    grp = re_comment_type2.split(result);
    result = string.join(grp);
    result = string.join(result.split('\n')) #remove the line break
    return(' '+result);

def oil_process_os(item, oscfg):
    grp = re_oil_os_general.search(item).groups();
    if(grp[0] != 'OS'):
        return;
    if(re_general_STATUS.search(item)):
        oscfg.cfg.general.status = re_general_STATUS.search(item).groups()[0];
    if(re_general_ERRORHOOK.search(item)):
        oscfg.cfg.general.os_error_hook = bool(re_general_ERRORHOOK.search(item).groups()[0]);
    if(re_general_PRETASKHOOK.search(item)):
        oscfg.cfg.general.os_pretask_hook = bool(re_general_PRETASKHOOK.search(item).groups()[0]);
    if(re_general_POSTTASKHOOK.search(item)):
        oscfg.cfg.general.os_post_task_hook = bool(re_general_POSTTASKHOOK.search(item).groups()[0]);
    if(re_general_SHUTDOWNHOOK.search(item)):
        oscfg.cfg.general.os_shutdown_hook = bool(re_general_SHUTDOWNHOOK.search(item).groups()[0]);
    if(re_general_STARTUPHOOK.search(item)):
        oscfg.cfg.general.os_startup_hook = bool(re_general_STARTUPHOOK.search(item).groups()[0]);
    #process the system counter
    if(re_general_SystemTimer.search(item)):
        name = 'SystemTimer'  #re_general_SystemTimer.search(item).groups()[0];
        if(gcfindObj(oscfg.cfg.counterList, name)):
            cnt = gcfindObj(oscfg.cfg.counterList, name);
        else:
            cnt = Counter(name);
            oscfg.cfg.counterList.insert(0, cnt);
#        if(re_general_TickTime.search(item)):
#            cnt.max = int(re_general_TickTime.search(item).groups()[0])
        cnt.max = 32767;
        
def oil_process_task(item, oscfg):
    grp = re_oil_os_task.search(item).groups();
    if(grp[0] != 'TASK'):
        return
    name = grp[1];
    if(gcfindObj(oscfg.cfg.taskList, name)):
        tsk = gcfindObj(oscfg.cfg.taskList, name)
    else:
        tsk = Task(name, 10, 512); #use default value
        oscfg.cfg.taskList.append(tsk)
    #now start to process it
    if(re_task_SCHEDULE.search(item)):
        schedule = re_task_SCHEDULE.search(item).groups()[0];
        if(schedule == 'FULL'):
            tsk.preemtable = True;
        else:
            tsk.preemtable = False;
    # should convert priority,because in gainos, the smaller value of priority has higher
    # priority,so now I am tired....
    if(re_task_PRIORITY.search(item)):
        tsk.prio = int(re_task_PRIORITY.search(item).groups()[0]);
    if(re_task_ACTIVATION.search(item)):
        tsk.maxactcnt = int(re_task_ACTIVATION.search(item).groups()[0]) - 1;
    if(re_task_AUTOSTART.search(item)):
        tsk.autostart = bool(re_task_AUTOSTART.search(item).groups()[0]);
        if(tsk.autostart == True):
            tsk.appmode = [];
            if(re_task_appmode_list.search(item)):
                appmode = re_task_appmode_list.search(item).groups()[0];
                for mode in appmode.split(';'):
                    if(re_task_APPMODE.search(mode)):
                        modename = re_task_APPMODE.search(mode).groups()[0]
                        tsk.appmode.append(modename)
                        if(gcfindObj(oscfg.cfg.appmodeList, modename) == None):
                            oscfg.cfg.appmodeList.append(AppMode(modename));
    if(re_task_StackSize.search(item)):
        tsk.stksz = int(re_task_StackSize.search(item).groups()[0]);
    #for resource
    for subitem in item.split(';'): #maybe sereval resource
        if(re_task_RESOURCE.search(subitem)): 
            resname = re_task_RESOURCE.search(subitem).groups()[0]
            if(gcfindStr(tsk.resourceList, resname) == None):
                tsk.resourceList.append(resname)
    # for EVENT
    for subitem in item.split(';'): #maybe sereval event
        if(re_task_EVENT.search(subitem)): 
            name = re_task_EVENT.search(subitem).groups()[0]
            if(gcfindObj(tsk.eventList, name)):
                ent = gcfindObj(tsk.eventList, name)
                ent.mask = 'AUTO'
            else:
                ent = Event(name, 'AUTO'); #default
                tsk.eventList.append(ent)

def oil_process_counter(item, oscfg):
    grp = re_oil_os_counter.search(item).groups();
    if(grp[0] != 'COUNTER'):
        return
    name = grp[1];
    if(gcfindObj(oscfg.cfg.counterList, name)):
        cnt = gcfindObj(oscfg.cfg.counterList, name)
    else:
        cnt = Counter(name); #use default value
        oscfg.cfg.counterList.append(cnt)
    if(re_counter_MAXALLOWEDVALUE.search(item)):
        cnt.max = int(re_counter_MAXALLOWEDVALUE.search(item).groups()[0]); 
    if(re_counter_TICKSPERBASE.search(item)):
        cnt.tpb = int(re_counter_TICKSPERBASE.search(item).groups()[0]); 
    if(re_counter_MINCYCLE.search(item)):
        cnt.min = int(re_counter_MINCYCLE.search(item).groups()[0]); 
    
def oil_process_alarm(item, oscfg):
    grp = re_oil_os_alarm.search(item).groups();
    if(grp[0] != 'ALARM'):
        return
    name = grp[1];
    if(gcfindObj(oscfg.cfg.alarmList, name)):
        alm = gcfindObj(oscfg.cfg.alarmList, name)
    else:
        alm = Alarm(name); #use default value
        oscfg.cfg.alarmList.append(alm)
    if(re_alarm_COUNTER.search(item)):
        alm.counter = str(re_alarm_COUNTER.search(item).groups()[0]);
    if(re_alarm_ACTION.search(item)):
        action = re_alarm_ACTION.search(item).groups(); 
        if(action[0] == 'ACTIVATETASK'):
            alm.type = 'task';
            if(re_action_TASK.search(action[1])):
                alm.task = re_action_TASK.search(action[1]).groups()[0]
        elif(action[0] == 'SETEVENT'):
            alm.type = 'event';
            if(re_action_TASK.search(action[1])):
                alm.task = re_action_TASK.search(action[1]).groups()[0]
            if(re_action_EVENT.search(action[1])):
                alm.event = re_action_EVENT.search(action[1]).groups()[0]
        elif(action[0] == 'ALARMCALLBACK'):
            alm.type = 'callback';
    if(re_alarm_AUTOSTART.search(item)):
        alm.autostart = bool(re_alarm_AUTOSTART.search(item).groups()[0]);
        if(alm.autostart == True):
            alm.appmode = [];
            if(re_alarm_appmode_list.search(item)):
                appmode = re_alarm_appmode_list.search(item).groups()[0];
                for mode in appmode.split(';'):
                    if(re_alarm_APPMODE.search(mode)):
                        modename = re_alarm_APPMODE.search(mode).groups()[0]
                        alm.appmode.append(modename)
                        if(gcfindObj(oscfg.cfg.appmodeList, modename) == None):
                            oscfg.cfg.appmodeList.append(AppMode(modename));
    if(re_alarm_ALARMTIME.search(item)):
        alm.alarmTime = int(re_alarm_ALARMTIME.search(item).groups()[0])
    if(re_alarm_CYCLETIME.search(item)):
        alm.cycleTime = int(re_alarm_CYCLETIME.search(item).groups()[0])

def oil_process_resource(item, oscfg):
    grp = re_oil_os_resource.search(item).groups();
    if(grp[0] != 'RESOURCE'):
        return
    name = grp[1];
    if(re_resource_property.search(item)):
        type = re_resource_property.search(item).groups()[0];
        if(type == 'STANDARD'):
            if(gcfindObj(oscfg.cfg.resourceList, name)):
                res = gcfindObj(oscfg.cfg.resourceList, name)
            else:
                res = Resource(name, 0); #should resolve ceiling priority when parse done
                oscfg.cfg.resourceList.append(res);
        elif(type == 'INTERNAL'):
            if(gcfindObj(oscfg.cfg.internalResourceList, name)):
                res = gcfindObj(oscfg.cfg.internalResourceList, name)
            else:
                res = InternalResource(name,0); #should resolve ceiling priority when parse done
                oscfg.cfg.internalResourceList.append(res);

def oil_process_event(item, oscfg):
    grp = re_oil_os_event.search(item).groups();
    if(grp[0] != 'EVENT'):
        return
    name = grp[1];
    if(gcfindObj(oscfg.cfg.eventList, name)):
        ent = gcfindObj(oscfg.cfg.eventList, name)
        ent.mask = 'AUTO'
    else:
        ent = Event(name, 'AUTO');
        oscfg.cfg.eventList.append(ent);
    if(re_event_MASK.search(item)):
        ent.mask = re_event_MASK.search(item).groups()[0]
def oil_process(item, oscfg):
    if(re_oil_os_task.search(item)):
        oil_process_task(item, oscfg);
    elif(re_oil_os_general.search(item)):
        oil_process_os(item, oscfg);
    elif(re_oil_os_counter.search(item)):
        oil_process_counter(item, oscfg);
    elif(re_oil_os_alarm.search(item)):
        oil_process_alarm(item, oscfg);
    elif(re_oil_os_resource.search(item)):
        oil_process_resource(item, oscfg);
    elif(re_oil_os_event.search(item)):
        oil_process_event(item, oscfg);
        
def to_oscfg(oilfile, oscfg):
    """convert the standard osek oil file to or merge to oscfg
    return True:convert successfully,else failed
    oscfg -> gainos_tk_os_cfg
    """
    fp = open(oilfile, 'r');
    oneitem = ''; #one item is minimum object such as TASK,ALARM ...
    barcenum = 0; #remember the brace number，when encounter " { ", +1; when " } " -1.
    brace_flag = False; #has " { " encountered or not
    process_one_item_start = False #has match an obj start or not
    for el in fp.readlines():
        #firstly, filter out the comment on this line
        el = filter_out_comment(el);
        if(process_one_item_start == False):
        #{
            oneitem = ''; 
            barcenum = 0;
            brace_flag = False;
            if(re_oil_os_obj.search(el)):
                process_one_item_start = True;
                oneitem += el;
                if(el.count('{') > 0):  #so at comment should not include '{}'
                    brace_flag = True;
                    barcenum += el.count('{');
                if(el.count('}') > 0):
                    barcenum -= el.count('}');
            elif(re_include.search(el)): #include file
                basep = os.path.dirname(oilfile)
                file = re_include.search(el).groups()[0];
                file = basep+'/'+file;
                to_oscfg(file, oscfg);
        #}
        else:
        #{
            if(re_include.search(el)): #include file
                basep = os.path.dirname(oilfile)
                file = re_include.search(el).groups()[0];
                file = basep+file;
                continue;
            if(el.count('{') > 0):  #so at comment should not include '{}'
                brace_flag = True;
                barcenum += el.count('{');
            if(el.count('}') > 0):
                barcenum -= el.count('}');
            oneitem += el;
            if((brace_flag == True) and (barcenum == 0)):
                #filter out the multi-line comment
                oneitem = filter_out_comment(oneitem)
                oil_process(oneitem, oscfg);
                process_one_item_start = False
        #}
    fp.close();
    return True;
# ----------------------------- Post Process ---------------
def resource_priority_post_process1(res, oscfg):
    """each resource should has a special priority where without task assigned"""
    for tsk in oscfg.cfg.taskList:
        if(tsk.prio == res.ceilprio):
            res.ceilprio += 1;

def resource_priority_post_process2(res, oscfg):
    """each resource should has a special priority where without task assigned
    and internal resource assigned"""
    for tsk in oscfg.cfg.taskList:
        if(tsk.prio == res.ceilprio):
            res.ceilprio += 1;
    for inres in oscfg.cfg.internalResourceList:
        if(inres.ceilprio == res.ceilprio):
            res.ceilprio += 1;

def oil_resolve_event_mask(eventList):
    for i in range(0, 32): #each bit corresponds to an event
        found = 0
        mask = 1<<i
        for ent in eventList:
            found += 1;
            if(ent.mask != 'AUTO'):
                if(mask == int(ent.mask, 16)):
                    found = 0;
                    break
        if(found == len(eventList)):
            return hex(mask);
    return hex(mask)
        
def post_process(oscfg):
    # resolve internal and standard resource priority
    for res in oscfg.cfg.internalResourceList+oscfg.cfg.resourceList:
            res.taskList = []
    for tsk in oscfg.cfg.taskList:
        for res in oscfg.cfg.internalResourceList+oscfg.cfg.resourceList:
            if(gcfindStr(tsk.resourceList, res.name)):
                res.taskList.append(tsk.name)
                if(res.ceilprio < (tsk.prio+1)):
                   res.ceilprio =  (tsk.prio+1)
    for res in oscfg.cfg.internalResourceList:
        resource_priority_post_process1(res, oscfg);
    for res in oscfg.cfg.resourceList:
        resource_priority_post_process2(res, oscfg);
    #resolve Event Mask
    for tsk in oscfg.cfg.taskList:
        for ent in tsk.eventList:
            entp = gcfindObj(oscfg.cfg.eventList, ent.name);
            if(entp.mask != 'AUTO'):
                ent.mask = entp.mask;
    for tsk in oscfg.cfg.taskList:
        for ent in tsk.eventList:
            entp = gcfindObj(oscfg.cfg.eventList, ent.name);
            if(entp.mask == 'AUTO'):
                ent.mask = oil_resolve_event_mask(tsk.eventList);
        
    
    
