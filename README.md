gainos-tk
=========

	A real time operating system conformed to osek os 2.2.3 specification. 
	A communication stack from arccore(http://www.arccore.com/) integrated.
	A configuring GUI tool based on python and Qt4.8.
概述
====
	GaInOS-TK 首先是一个符合OSEK OS 2.2.3 规范的实时操作系统，其实现架构基于uTenux（http://www.uloong.cc） 其遵循开源U-License协议。
	在此 RTOS 的基础之上集成来自arccore（http://www.arccore.com/）的开源GPL协议的Com通讯栈代码。
	并为上述两模块开发出静态配置工具gainos-studio。

源码说明
========
	
	+ gainos-tk
	+---+ app                <--- 客户应用程序（TASK、ALARM、ISR）
	+---+ arch               <--- 平台相关文件及基础板级支持包
	+---+ bin                <--- 各平台工程目录
	+---+ comstack           <--- Autosar Com通讯栈代码集
	+---+ config             <--- GaInOS-TK及通讯栈模块配置文件集
	+---+ diag               <--- Autosar 诊断代码集
	+---+ ecual              <--- Autosar ECU Abstraction Layer（ECU抽象层） 
	+---+ include            <--- 公用头文件
	+---+ mcal               <--- Autosar 微控制器抽象层（现仅有CAN模块）
	+---+ osek               <--- GaInOS-TK 核心
	+-------+ inc            <--- GaInOS-TK 内核 .h 
	+-------+ src            <--- GaInOS-TK 内核 .c 
	+-------+ vPort          <--- GaInOS-TK 内核移植部分
	
	
