gainos-tk
=========

	A real time operating system conformed to osek os 2.2.3 specification. 
	A communication stack from arccore(http://www.arccore.com/) integrated.
	A configuring GUI tool based on python and Qt4.8.
概述
====
	GaInOS-TK 首先是一个符合OSEK OS 2.2.3 规范的实时操作系统，其实现架构基于uTenux（http://www.uloong.cc）， 其遵循开源U-License协议。
	在此 RTOS 的基础之上集成来自arccore（http://www.arccore.com/）的开源GPL协议的Com通讯栈代码。
	并为上述两模块开发出静态配置工具gainos-studio。

自述
====
	和大多数嵌入式技术爱好者一样，最初我也仅仅是学习ucOS，但渐渐的，我发现我喜欢嵌入式微内核技术。之后也相继学习过FreeRTOS 和 RT-Thread，并也曾经阅读过linux 0.11代码。 并在阅读了 于渊 《自己动手写操作系统》这样一本书之后，在自己的内心里也就一直有了这样的一个念头，那就是我希望有一天，我可以动手开始打造属于我自己的操作系统。那一年，我大三了。也就是在那一年，我有点懊恼我那浑浑噩噩的大一与大二。
	但是，我也发现纯粹的自己动手写一个操作系统，实在是有点难度，因为我没有方向，难免将会以ucOS、FreeRTOS等为方向标，那最终的结果很可能就是抄袭，那样也就成了抄作系统了。
	
	毕业开始工作，也算是有幸能够进入汽车电子领域，虽说工资待遇极差，但是这工作一年来，我真的是受益匪浅。
	
	这里，我找到了研究的方向。于2012年9月27日，开始了符合OSEK OS 2.2.3规范的操作系统的编写，并于3个月之后完成，并通过OSEK OS官方符合性测试用例。也就是在这三个月的时间之内，让我对微内核操作系统有了一个彻底的认识。但是，也深深的让我体会到，一个人的力量可以很伟大，也可以很渺小。
	之后，得到uLoong社区的邀请，加入了uLoong社区，开始接触uTenux这样一个操作系统，开始时得知其发源于日本，有点不屑于顾，但深入的阅读内核代码之后，我为之叹服，原来操作系统可以这样来写，可以如此来抽象，达到简洁大一统的效果。总结一下，uTenux吸引我的地方主要有两点：1、精简易懂的API，易于理解的内核设计思路；2、基于 Queue 的大一统的任务、信号量、互斥量等的管理，基于 TMEB 时间事件的内核调度机制。
	
	之后，开始了基于uTenux的OSEK OS工作，这里感谢uLoong社区在此期间给予的帮助。所以到今天，有了基于uTenux的GaInOS-TK，之所以取名GaInOS，是因为我相信 No pain，No gain。还有就是GaIn 在韩语里面和 "가인" （佳人）同音，So I like it。
	
	
	

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
	+---+ tool               <--- GaInOS-TK 工具（gainos-studio）
	
