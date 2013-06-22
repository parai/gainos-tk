# -*- coding: utf-8 -*-

"""
Module implementing cd_gainos_tk_os.
"""

from PyQt4.QtGui import QDialog
from PyQt4.QtCore import pyqtSignature
from PyQt4.QtCore import QStringList,QString
from PyQt4.QtGui import QTreeWidgetItem, QMessageBox

from Common import *

from Ui_cd_os import Ui_cd_os
from gainos_tk_os_cfg import *
class cd_os(QDialog, Ui_cd_os):
    """
    Class documentation goes here.
    """
    def __init__(self, title, fileInd, cfg, parent = None):
        """
        Constructor
        """
        QDialog.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(title);
        self.fileInd = fileInd;
        self.cfg = cfg;
        self.curtree = None;
        self.curobj = None;
        self.initGui();
    
    def reloadTaskGui(self):
        tree=self.trModule.topLevelItem(1);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in self.cfg.taskList:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);
            for ent in obj.eventList:
                item2=QTreeWidgetItem(item,QStringList(ent.name));
                item.addChild(item2);

    def reloadTreeGui(self, trindex, list):
        tree=self.trModule.topLevelItem(trindex);
        for index in range(0, tree.childCount()):
            temp=tree.takeChild(0);
            del temp;
        for obj in list:
            item=QTreeWidgetItem(tree,QStringList(obj.name));
            tree.addChild(item);

    def reloadGui(self):
        self.reloadTreeGui(0, self.cfg.appmodeList);   # 0 AppMode
        self.reloadTaskGui();                           # 1 Task
        self.reloadTreeGui(2, self.cfg.resourceList);   # 2 Resource
        self.reloadTreeGui(3, self.cfg.counterList);    # 3 Counter
        self.reloadTreeGui(4, self.cfg.alarmList);      # 4 Alarm

    def initButton(self):
        self.btnAdd.setDisabled(True);
        self.btnDel.setDisabled(True);

    def initSpbxRange(self):
        self.spbxResCeilPrio.setRange(1, 140);
        self.spbxTskPrio.setRange(1, 140);
        self.spbxTskStkSize.setRange(32, 1024*10);
        self.spbxMaxPrio.setRange(0, 255);
    
    def initGeneral(self):
        self.spbxMaxIpl.setDisabled(True);
        #self.cmbxSchedPolicy.setDisabled(True);
        #self.cmbxOSConfCls.setDisabled(True);
        self.on_cmbxSchedPolicy_activated(self.cfg.general.sched_policy);
        self.cmbxSchedPolicy.setCurrentIndex(self.cmbxSchedPolicy.findText(self.cfg.general.sched_policy));
        self.cmbxOSConfCls.setCurrentIndex(self.cmbxOSConfCls.findText(self.cfg.general.os_class));
        self.cmbxStatus.setCurrentIndex(self.cmbxStatus.findText(self.cfg.general.status));
        self.spbxMaxPrio.setValue(self.cfg.general.max_pri);
        self.cbxTkExtend.setChecked(self.cfg.general.tk_extend);
        self.cbxTskStkOverflowCheck.setChecked(self.cfg.general.os_stack_overflow_check);
        self.cbxOsStartUpHook.setChecked(self.cfg.general.os_startup_hook);
        self.cbxOsShutDownHook.setChecked(self.cfg.general.os_shutdown_hook);
        self.cbxPreTaskHook.setChecked(self.cfg.general.os_pretask_hook);
        self.cbxPostTaskHook.setChecked(self.cfg.general.os_post_task_hook);
        self.cbxOsErrorHook.setChecked(self.cfg.general.os_error_hook);
        self.spbxSystenStkSz.setValue(self.cfg.general.system_stack_size);
        if(self.cfg.general.os_class[:3] == 'BCC'):
            self.cbxShareSystemStack.setDisabled(False);
        elif(self.cfg.general.os_class[:3] == 'ECC'):
            self.cbxShareSystemStack.setDisabled(True);
        self.cbxShareSystemStack.setChecked(self.cfg.general.share_system_stack);
        
    def initGui(self):
        self.initButton();
        self.disableAllTab();
        self.reloadGui();
        self.initSpbxRange();
        self.initGeneral();

    def disableAllTab(self):
        """禁止所有的Tab页"""
        for i in  range(0, 8):
            self.tblGaInOsCfg.setTabEnabled(i, False);
    
    def enableTab(self, index):
        """使能xIndex指向的Tab页"""
        for i in  range(0, 8):
            if(i==index):
                self.tblGaInOsCfg.setTabEnabled(i, True);
                self.tblGaInOsCfg.setCurrentIndex(i);
            else:
                self.tblGaInOsCfg.setTabEnabled(i, False);

    def refreshButton(self):
        if(self.curtree==None):
            return;
        trname = self.curtree.text(0);
        #--------------------- 一级目录
        if(trname=='AppMode'):
            self.btnAdd.setText('Add AppMode');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
            if(len(self.cfg.appmodeList) >= 15):
                #use attribute 4 LSB bits to store the taskmode
                self.btnAdd.setDisabled(True);
        elif(trname=='Task'):
            self.btnAdd.setText('Add Task');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Resource'):
            self.btnAdd.setText('Add Resource');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Counter'):
            self.btnAdd.setText('Add Counter');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        elif(trname=='Alarm'):
            self.btnAdd.setText('Add Alarm');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(True);
        #--------------------- 二级目录
        elif(self.curtree.parent().text(0)=='AppMode'):
            self.btnDel.setText('Delete AppMode');
            self.btnAdd.setDisabled(True);
            if(trname == 'OSDEFAULTAPPMODE'):
                self.btnDel.setDisabled(True);
            else:
                self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Task'):
            self.btnAdd.setText('Add Event');
            self.btnDel.setText('Delete Task');
            self.btnAdd.setDisabled(False);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Resource'):
            self.btnDel.setText('Delete Resource');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Counter'):
            self.btnDel.setText('Delete Counter');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        elif(self.curtree.parent().text(0)=='Alarm'):
            self.btnDel.setText('Delete Alarm');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);
        #--------------------- 三级目录
        elif(self.curtree.parent().parent().text(0)=='Task'):
            self.btnDel.setText('Delete Event');
            self.btnAdd.setDisabled(True);
            self.btnDel.setDisabled(False);

    def refreshTaskTab(self, name):
        self.curobj=gcfindObj(self.cfg.taskList, name);
        self.leTskName.setText(name);
        if(self.cfg.general.share_system_stack == True):
            self.spbxTskStkSize.setDisabled(True)
        else:
            self.spbxTskStkSize.setDisabled(False)
        self.spbxTskStkSize.setValue(self.curobj.stksz);
        self.cbxTskPreemtable.setChecked(self.curobj.preemtable);
        self.cbxTaskAutostart.setChecked(self.curobj.autostart);
        self.spbxTskPrio.setValue(self.curobj.prio);
        self.spbxTskMaxActivateCount.setValue(self.curobj.maxactcnt);
        self.refreshTreeCtrl(self.trTaskAppModeSrc, self.trTaskAppModeDst, self.cfg.appmodeList, self.curobj.appmode)
        self.btnTaskModeAdd.setDisabled(not self.curobj.autostart);
        self.btnTaskModeDel.setDisabled(not self.curobj.autostart);
        self.trTaskAppModeDst.setDisabled(not self.curobj.autostart);
        self.trTaskAppModeSrc.setDisabled(not self.curobj.autostart);
        if(len(self.curobj.eventList)):
            self.cmbxTskType.setCurrentIndex(1);
        else:
            self.cmbxTskType.setCurrentIndex(0);
        self.enableTab(0);

    def refreshResourceTab(self, name):
        self.curobj=gcfindObj(self.cfg.resourceList, name);
        self.leResName.setText(name);
        self.spbxResCeilPrio.setValue(self.curobj.ceilprio);
        self.enableTab(1);

    def refreshCounterTab(self, name):
        self.curobj=gcfindObj(self.cfg.counterList, name);
        self.leCntName.setText(name);
        self.spbxCntMaxAllowedValue.setValue(self.curobj.max);
        self.spbxCntTickBase.setValue(self.curobj.tpb);
        self.spbxCntMinCycle.setValue(self.curobj.min);
        self.enableTab(3);
        
    def refreshAlarmTabCmbx(self):
        """根据Alarm的类型刷新Alarm tab中的combox组建"""
        self.cmbxAlarmTask.clear();
        self.cmbxAlarmEvent.clear();
        self.cmbxAlarmOwner.clear();
        for obj in self.cfg.counterList:
            self.cmbxAlarmOwner.addItem(obj.name);
        self.cmbxAlarmOwner.setCurrentIndex(self.cmbxAlarmOwner.findText(self.curobj.counter))
        self.cmbxAlarmType.setCurrentIndex(self.cmbxAlarmType.findText(self.curobj.type));
        if(self.curobj.type == 'callback'):
            self.cmbxAlarmTask.setDisabled(True);
            self.cmbxAlarmEvent.setDisabled(True);
        elif(self.curobj.type == 'task'):
            self.cmbxAlarmTask.setDisabled(False);
            self.cmbxAlarmEvent.setDisabled(True);
            self.lblAlarmTask.setText('Alarm Activate Task:');
            #task
            for obj in self.cfg.taskList:
                self.cmbxAlarmTask.addItem(obj.name);
            self.cmbxAlarmTask.setCurrentIndex(self.cmbxAlarmTask.findText(self.curobj.task));
        elif(self.curobj.type == 'event'):
            self.cmbxAlarmTask.setDisabled(False);
            self.cmbxAlarmEvent.setDisabled(False);
            self.lblAlarmTask.setText('Alarm Event Task:');
            #task
            tsk=None;
            for obj in self.cfg.taskList:
                self.cmbxAlarmTask.addItem(obj.name);
                if(self.curobj.task == obj.name):
                    #find it
                    tsk=obj;
            self.cmbxAlarmTask.setCurrentIndex(self.cmbxAlarmTask.findText(self.curobj.task));
            #task event
            if(tsk != None):
                for obj in tsk.eventList:
                    self.cmbxAlarmEvent.addItem(obj.name);
            self.cmbxAlarmEvent.setCurrentIndex(self.cmbxAlarmEvent.findText(self.curobj.event));
 
    def refreshAlarmTab(self, name):
        self.curobj=gcfindObj(self.cfg.alarmList, name);
        self.leAlarmName.setText(name);
        self.refreshAlarmTabCmbx();        
        self.enableTab(4);

    def refreshEventTab(self, name):
        tsk=gcfindObj(self.cfg.taskList, self.curtree.parent().text(0));
        self.curobj=gcfindObj(tsk.eventList, name);
        self.leEventName.setText(self.curobj.name);
        self.leEventMask.setText(self.curobj.mask);
        self.enableTab(6);
    def refreshAppModeTab(self, name):
        self.curobj = gcfindObj(self.cfg.appmodeList, name);
        if(name == 'OSDEFAULTAPPMODE'):
            self.leAppModeName.setDisabled(True);
        else:
            self.leAppModeName.setDisabled(False);
        self.leAppModeName.setText(name);
        self.enableTab(7);
    def refreshTab(self):
        if(self.curtree.parent() == None):
            self.disableAllTab();
            self.curobj=None;
            return;
        trname = self.curtree.parent().text(0);
        objname= self.curtree.text(0);
        if(trname == 'AppMode'):
            self.refreshAppModeTab(objname);
        elif(trname == 'Task'):
            self.refreshTaskTab(objname);
        elif(trname == 'Resource'):
            self.refreshResourceTab(objname);
        elif(trname == 'Counter'):
            self.refreshCounterTab(objname);
        elif(trname == 'Alarm'):
            self.refreshAlarmTab(objname);
        elif(trname == 'Autosar'):
            self.refreshAutosarTab(objname);
        elif(self.curtree.parent().parent().text(0) == 'Task'):
            self.refreshEventTab(objname);

    @pyqtSignature("QTreeWidgetItem*, int")
    def on_trModule_itemClicked(self, item, column):
        self.curtree = item;
        self.refreshTab();
        self.refreshButton();
    
    def addAppMode(self):
        id = len(self.cfg.appmodeList);
        name=QString('vAppMode%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=AppMode(name);
        self.cfg.appmodeList.append(obj);
        self.curtree.setExpanded(True);
        if(len(self.cfg.appmodeList) >= 8):
            #use attribute 8 LSB bits to store the taskmode
            self.btnAdd.setDisabled(True);
        
    def addTask(self):
        """添加一个任务节点，使用默认名称"""
        id = len(self.cfg.taskList);
        name=QString('vTask%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Task(name,id+1,512);
        self.cfg.taskList.append(obj);
        self.curtree.setExpanded(True);

    def addResource(self):
        """添加一个资源节点，使用默认名称"""
        id = len(self.cfg.resourceList);
        name=QString('vRes%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Resource(name,id+1);
        self.cfg.resourceList.append(obj);
        self.curtree.setExpanded(True);

    def addCounter(self):
        """添加一个报警器节点，使用默认名称"""
        id = len(self.cfg.counterList);
        name=QString('vCounter%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Counter(name);
        self.cfg.counterList.append(obj);
        self.curtree.setExpanded(True);

    def addAlarm(self):
        """添加一个报警器节点，使用默认名称"""
        id = len(self.cfg.alarmList);
        name=QString('vAlarm%d'%(id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Alarm(name);
        self.cfg.alarmList.append(obj);
        self.curtree.setExpanded(True);

    def addEvent(self):
        """添加一个报警器节点，使用默认名称"""
        id = len(self.curobj.eventList);
        name=QString('%sEvent%d'%(self.curobj.name,id));
        item=QTreeWidgetItem(self.curtree,QStringList(name));
        self.curtree.addChild(item);
        obj=Event(name, hex(1<<id));
        self.curobj.eventList.append(obj);
        self.curtree.setExpanded(True);
        self.cmbxTskType.setCurrentIndex(1);

    @pyqtSignature("")
    def on_btnAdd_clicked(self):
        text=self.btnAdd.text();
        if(text=='Add Task'):
            self.addTask();
        elif(text=='Add Resource'):
            self.addResource();
        elif(text=='Add Counter'):
            self.addCounter();
        elif(text=='Add Alarm'):
            self.addAlarm();
        elif(text=='Add Event'):
            self.addEvent();
        elif(text=='Add AppMode'):
            self.addAppMode();
        self.fileInd(False);
    
    @pyqtSignature("")
    def on_btnDel_clicked(self):
        parent = self.curtree.parent();
        index = parent.indexOfChild(self.curtree);
        parent.takeChild(index);
        text=self.btnDel.text();
        if(text=='Delete Task'):
            self.cfg.taskList.remove(self.curobj);
        elif(text=='Delete Resource'):
            self.cfg.resourceList.remove(self.curobj);
        elif(text=='Delete Counter'):
            self.cfg.counterList.remove(self.curobj);
        elif(text=='Delete Alarm'):
            self.cfg.alarmList.remove(self.curobj);
        elif(text=='Delete AppMode'):
            self.cfg.appmodeList.remove(self.curobj);
        elif(text=='Delete Event'):
            tsk=gcfindObj(self.cfg.taskList, parent.text(0));
            tsk.eventList.remove(self.curobj);
            if(len(tsk.eventList) == 0):
                self.cmbxTskType.setCurrentIndex(0);
        del self.curtree;
        #reselect a tree item,software trigger on_trModule_itemClicked()
        if(index>0):
            parent.child(index-1).setSelected(True);
            self.on_trModule_itemClicked(parent.child(index-1), 0);
        else:
            parent.setSelected(True);
            self.on_trModule_itemClicked(parent, 0);
        self.fileInd(False);
#--------- Tree Control Common operation -----------------------------
    def moveTreeItem(self, trFrom, trTo):
        if(trFrom.currentItem()):
            name = trFrom.currentItem().text(0)
            item = QTreeWidgetItem(trTo, QStringList(name)); #add
            trFrom.takeTopLevelItem(trFrom.indexOfTopLevelItem(trFrom.currentItem()));#remove
    def refreshTreeCtrl(self, trSrc, trDst, lsSrc, lsDst):
        """lsSrc：源资源列表，trSrc：源目录树控件
           lsDst：目标资源列表，trDst：目标目录树控件
           一般的，lsSrc是 GaInOS-TK一个对象列表
           而 lsDst则是一个字符串 String 列表
        """
        #移除所有
        for index in range(0, trSrc.topLevelItemCount()):
            temp=trSrc.takeTopLevelItem(0);
            del temp;
        for index in range(0, trDst.topLevelItemCount()):
            temp=trDst.takeTopLevelItem(0);
            del temp;
        #向相应控件注册对象
        for str in lsDst:
            if(gcfindObj(lsSrc, str) != None):#if it still in the lsSrc
                item=QTreeWidgetItem(trDst,QStringList(str));
            else: # maybe you have removed & rename it, so should remove it from the list
                lsDst.remove(str);
        for obj in lsSrc:
            if(gcfindStr(lsDst, obj.name) == None):
                item=QTreeWidgetItem(trSrc,QStringList(obj.name));
        #print lsDst
    #========================== Alarm ==================================
    @pyqtSignature("QString")
    def on_leAlarmName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxAlarmType_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.type!=p0):
                self.curobj.type=p0;
                self.refreshAlarmTabCmbx();
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxAlarmTask_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.task!=p0):
                self.curobj.task=p0;
                self.refreshAlarmTabCmbx();
                self.fileInd(False);

    @pyqtSignature("QString")
    def on_cmbxAlarmEvent_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.event!=p0):
                self.curobj.event=p0;
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_cmbxAlarmOwner_activated(self, p0):
        if(self.curobj!=None):
            if(self.curobj.counter!=p0):
                self.curobj.counter=p0;
                self.fileInd(False);
    #===================== Resource ====================================
    @pyqtSignature("QString")
    def on_leResName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxResCeilPrio_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.ceilprio!=p0):
                self.curobj.ceilprio=p0;
                self.fileInd(False);
    #=========================== Task ============================
    @pyqtSignature("QString")
    def on_leTskName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);       
    @pyqtSignature("int")
    def on_spbxTskStkSize_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.stksz!=p0):
                self.curobj.stksz=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxTskPrio_valueChanged(self, p0):
        if(self.curobj!=None):  
            if(self.curobj.prio!=p0):
                self.curobj.prio=p0
                self.fileInd(False); 
    @pyqtSignature("int")
    def on_spbxTskMaxActivateCount_valueChanged(self, p0):
        if(self.curobj!=None):  
            if(self.curobj.maxactcnt!=p0):
                self.curobj.maxactcnt=p0
                self.fileInd(False); 
    @pyqtSignature("bool")
    def on_cbxTskPreemtable_clicked(self, p0):
        if(self.curobj!=None):  
            if(self.curobj.preemtable!=p0):
                self.curobj.preemtable=p0
                self.fileInd(False); 
    @pyqtSignature("bool")
    def on_cbxTaskAutostart_clicked(self, p0):
        if(self.curobj!=None):  
            if(self.curobj.autostart!=p0):
                self.curobj.autostart=p0
                self.btnTaskModeAdd.setDisabled(not self.curobj.autostart);
                self.btnTaskModeDel.setDisabled(not self.curobj.autostart);
                self.trTaskAppModeDst.setDisabled(not self.curobj.autostart);
                self.trTaskAppModeSrc.setDisabled(not self.curobj.autostart);
                self.fileInd(False); 
    @pyqtSignature("")
    def on_btnTaskModeAdd_clicked(self):
        if(self.trTaskAppModeSrc.currentItem()):
            self.curobj.appmode.append(self.trTaskAppModeSrc.currentItem().text(0));
            self.moveTreeItem(self.trTaskAppModeSrc, self.trTaskAppModeDst);
            self.fileInd(False);
    @pyqtSignature("")
    def on_btnTaskModeDel_clicked(self):
        if(self.trTaskAppModeDst.currentItem()):
            self.curobj.appmode.remove(self.trTaskAppModeDst.currentItem().text(0));
            self.moveTreeItem(self.trTaskAppModeDst, self.trTaskAppModeSrc);
            self.fileInd(False);
    #============================= Event =================================
    @pyqtSignature("QString")
    def on_leEventName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    @pyqtSignature("QString")
    def on_leEventMask_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.mask!=p0):
                self.curobj.mask=p0;
                self.fileInd(False);
    #===================== Counter ==================================
    @pyqtSignature("QString")
    def on_leCntName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxCntMaxAllowedValue_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.max!=p0):
                self.curobj.max=p0;
                self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxCntTickBase_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.tpb!=p0):
                self.curobj.tpb=p0;
                self.fileInd(False); 
    @pyqtSignature("int")
    def on_spbxCntMinCycle_valueChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.min!=p0):
                self.curobj.min=p0;
                self.fileInd(False);
    #======================== General ================================
    @pyqtSignature("QString")
    def on_cmbxSchedPolicy_activated(self, p0):
        if self.cfg.general.sched_policy != p0:
            self.cfg.general.sched_policy = p0;
            self.fileInd(False);
        if(p0 == 'FULL_PREEMPTIVE_SCHEDULE' or p0 == 'NONE_PREEMPTIVE_SCHEDULE'):
            self.cbxTskPreemtable.setDisabled(True);
        else:
            self.cbxTskPreemtable.setDisabled(False);
    @pyqtSignature("int")
    def on_spbxMaxPrio_valueChanged(self, p0):
        if self.cfg.general.max_pri != p0:
            self.cfg.general.max_pri = p0;
            self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxStatus_activated(self, p0):
        if self.cfg.general.status != p0:
            self.cfg.general.status = p0;
            self.fileInd(False);
    @pyqtSignature("QString")
    def on_cmbxOSConfCls_activated(self, p0):
        if self.cfg.general.os_class != p0:
            self.cfg.general.os_class = p0;
            if(p0[:3] == 'BCC'):
                self.cbxShareSystemStack.setDisabled(False);
            elif(p0[:3] == 'ECC'):
                self.cbxShareSystemStack.setDisabled(True);
                self.cfg.general.share_system_stack = False
                self.cbxShareSystemStack.setChecked(False)
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxTkExtend_clicked(self, p0):
        if(self.cfg.general.tk_extend != p0):
            self.cfg.general.tk_extend = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxTskStkOverflowCheck_clicked(self, p0):
        if(self.cfg.general.os_stack_overflow_check != p0):
            self.cfg.general.os_stack_overflow_check = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxOsStartUpHook_clicked(self, p0):
        if(self.cfg.general.os_startup_hook != p0):
            self.cfg.general.os_startup_hook = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxOsShutDownHook_clicked(self, p0):
        if(self.cfg.general.os_shutdown_hook != p0):
            self.cfg.general.os_shutdown_hook = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxPreTaskHook_clicked(self, p0):
        if(self.cfg.general.os_pretask_hook != p0):
            self.cfg.general.os_pretask_hook = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxPostTaskHook_clicked(self, p0):
        if(self.cfg.general.os_post_task_hook != p0):
            self.cfg.general.os_post_task_hook = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxOsErrorHook_clicked(self, p0):
        if(self.cfg.general.os_error_hook != p0):
            self.cfg.general.os_error_hook = p0;
            self.fileInd(False);
    @pyqtSignature("int")
    def on_spbxSystenStkSz_valueChanged(self, p0):
        if self.cfg.general.system_stack_size != p0:
            self.cfg.general.system_stack_size = p0;
            self.fileInd(False);
    @pyqtSignature("bool")
    def on_cbxShareSystemStack_clicked(self, p0):
        if(self.cfg.general.share_system_stack != p0):
            self.cfg.general.share_system_stack = p0;
            self.fileInd(False);
    #==================== APP MODE ========================================
    @pyqtSignature("QString")
    def on_leAppModeName_textChanged(self, p0):
        if(self.curobj!=None):
            if(self.curobj.name!=p0):
                self.curobj.name=p0;
                self.curtree.setText(0, p0);
                self.fileInd(False);
    
    
