gainos-tk
=========

	A real time operating system conformed to osek os 2.2.3 specification. 
	A communication stack from arccore(http://www.arccore.com/) integrated.
	A configuring GUI tool based on python and Qt4.8.
# 概述
	GaInOS-TK 首先是一个符合OSEK OS 2.2.3 规范的实时操作系统，其实现架构基于uTenux（http://www.uloong.cc），其
	遵循开源U-License协议。在此 RTOS 的基础之上集成来自arccore（http://www.arccore.com/）的开源GPL协议的Com通讯
	栈代码。并为上述两模块开发出静态配置工具gainos-studio。

# 自述
	和大多数嵌入式技术爱好者一样，最初我也仅仅是学习ucOS，但渐渐的，我发现我喜欢嵌入式微内核技术。之后也相继学习过
	FreeRTOS 和 RT-Thread，并也曾经阅读过linux 0.11代码。 并在阅读了 于渊 《自己动手写操作系统》这样一本书之后，在
	自己的内心里也就一直有了这样的一个念头，那就是我希望有一天，我可以动手开始打造属于我自己的操作系统。那一年，我
	大三了。也就是在那一年，我有点懊恼我那浑浑噩噩的大一与大二。

	但是，我也发现纯粹的自己动手写一个操作系统，实在是有点难度，因为我没有方向，难免将会以ucOS、FreeRTOS等
	为方向标，那最终的结果很可能就是抄袭，那样也就成了抄作系统了。

	毕业开始工作，也算是有幸能够进入汽车电子领域，虽说工资待遇极差，但是这工作一年来，我真的是受益匪浅。
	
	这里，我找到了研究的方向。于2012年9月27日，开始了符合OSEK OS 2.2.3规范的操作系统的编写，并于3个月之
	后完成，并通过OSEK OS官方符合性测试用例。也就是在这三个月的时间之内，让我对微内核操作系统有了一个彻底的
	认识。但是，也深深的让我体会到，一个人的力量可以很伟大，也可以很渺小。

	之后，得到uLoong社区的邀请，加入了uLoong社区，开始接触uTenux这样一个操作系统，开始时得知其发源于日本，
	有点不屑于顾，但深入的阅读内核代码之后，我为之叹服，原来操作系统可以这样来写，可以如此来抽象，达到简洁大
	一统的效果。总结一下，uTenux吸引我的地方主要有两点：1、精简易懂的API，易于理解的内核设计思路；2、基于 
	Queue 的大一统的任务、信号量、互斥量等的管理，基于 TMEB 时间事件的内核调度机制。

	之后，开始了基于uTenux的OSEK OS工作，这里感谢uLoong社区在此期间给予的帮助。所以到今天，
	有了基于uTenux的GaInOS-TK，之所以取名GaInOS，是因为我相信 No pain，No gain。还有就是GaIn 在韩语里面
	和 "가인" （佳人）同音，So I like it。

	但渐渐的我再想为什么OSEK OS 规范没有描述任务之间的通信机制，后来我在OSEK COM中找到了答案，所以我个人
	很想架构这样的一整套的OSEK 基础软件。但是个人能力毕竟有限，所以想到了arccore，既然其代码开源且遵循GPL协
	议，那么有就有权利去修改于在发布其源代码，所以我开始了集成arccore的通讯栈代码（含诊断）。至今已经完成相当
	一部分工作。

    还是由于个人能力有限，这里很希望有志同道合之人能够加入我的此开源项目之中。
	
	Author ： 汪帆 （parai）	
	Email ：parai@foxmail.com	
	Blog: http://hi.baidu.com/parai

# 源码说明
	
	+ gainos-tk
	+---+ app                <--- 客户应用程序（TASK、ALARM、ISR）
	+---+ arch               <--- 平台相关文件及基础板级支持包
	+---+ bin                <--- 各平台工程目录
	+---+ comstack           <--- Autosar Com通讯栈代码集
	+-------+ CanIf          <--- Autosar Can Interface
	+-------+ CanNm          <--- Autosar Can Network Management
	+-------+ CanSM          <--- Autosar Can State Management
	+-------+ CanTp          <--- Autosar Can Transport Layer（ISO 15765-2-2004ocr）
	+-------+ J1939Tp        <--- SAE J1939 Transport Layer（under construct）
	+-------+ Nm             <--- Autosar Network Management
	+-------+ PduR           <--- Autosar Pdu Router
	+-------+ Com            <--- Autosar Communication
	+-------+ ComM           <--- Autosar Communication Manager
	+---+ config             <--- GaInOS-TK及通讯栈模块配置文件集
	+---+ diag               <--- Autosar 诊断代码集
	+-------+ Dcm            <--- Autosar Diagnostic Communication Manager(only UDS,no OBD) 
	+-------+ Dem
	+-------+ Det
	+---+ include            <--- 公用头文件
	+---+ mcal               <--- Autosar 微控制器抽象层（现仅有CAN模块）
	+-------+ Can            <--- Autosar Can Driver
	+---+ osek               <--- GaInOS-TK 核心
	+-------+ inc            <--- GaInOS-TK 内核 .h 
	+-------+ src            <--- GaInOS-TK 内核 .c 
	+-------+ portable       <--- GaInOS-TK 内核移植部分
	+-------+ test           <--- GaInOS-TK 内核OSEK 符合性测试
	+---+ system             <--- Autosar 系统
	+---+ tool               <--- gainos-tk 工具	
	+---+ toppers_osek       <--- GaInOS-TK 实现时参考的一个os
	
# 使用说明
##  1.bin 目录下工程使用
	目前为止GaInOS提供5个工程包：
	at91sam3s4c  <---> IAR 6.5
	mc9s12dp512  <---> Codewarrior 5.0
	mpc5634      <---> Codewarrior 2.8
	stm32f107vc  <---> IAR 6.5
	tc1797       <---> Tasking VX for TriCore <需修改 添加 GAINOS_BD 参数>
	xc2364       <---> Tasking VX for C166    <需修改 添加 GAINOS_BD 参数>
## 2.关于移植 portable 的说明
    本OS在9S12平台上开发与测试，并给出了其他4个平台( XC2364 TC1797 ARM_CORTEXM3 MPC5634)的移植示例，
	不保证完全移植的正确性。即使是对于9S12平台gainos-tk的移植，我认为也存在很多可以优化的地方。由于，
	对于硬件CPU细节的不关心，也为了有更多的时间专注于gainos-tk上层调度逻辑的实现，这里寄期望于熟悉
	相关CPU的开源爱好人士能够贡献gainos-tk的底层 portable 移植代码。
		
**附注：**
		对于Tasking，需要在path and symbols 中添加 GAINOS_BD = "path/to/gainos-tk"
	
##  2.tool/gainos-studio 工具的使用
	首先要安装 python27 < http://www.python.org/download/releases/2.7/ >
	其次安装 PyQt4-4.10.1-gpl-Py2.7-Qt4.8.4  < http://www.riverbankcomputing.com/software/pyqt/download >
	程序入口为 main.py, 终端模式下，python main.py 运行之
	或者使用tool/gainos-studio/start gainos studio.bat双击运行，但需要保证python目录位于环境变量path之中。
	如果您希望开发gainos-studio，推荐安装Eric，详情请百度。
	
##  3.实现的另一个参考 toppers_osek 
	toppers_osek无疑是一个优秀的OSKE OS，实时性超棒，任务启动激活快速。
	对于该OS，本次只是实现了9S12平台的移植，编译器codewarrior 5.0，利用该IDE可以完美仿真运行，从而可以初步
	体验一下该RTOS的魅力。
	对于该OS，本项目不提供配置工具，要创建Task、Counter、Alarm、Event、ISR以及Resource，只能通过手动的方式
	编写os_cfg.c 和 os_cfg.h。
	由于，该OS，源码注释为日文，很多我自己都没看明白，我是参照其默认提供的一个at91sam7的底层移植文件来往
	MC9S12DP512 平台来移植的，我不保证移植的完全正确性。并且，由于原at91sam7移植文件太多，被我有所精简，
	现在只有portable.h 和 portable.c (我喜欢FreeRTOS的代码目录结构)。并且该OS的代码很多地方，被我有所改动。
	
#Add-on features
###  1.实现一个共用堆栈的OSEK OS(仅支持BCC，FULL模式)
	传统OS每一个任务都享有独立的堆栈控件，对于资源较小的微控制器，显然是不太合适的。这里，我想设计出虽有一定
	约束，但是具有相当好实时性的且支持所有任务共用一个堆栈的的gainos-tk。
	（1）对于一般的微控制器，堆栈向下生长，只要保证任务剥夺嵌套时，按嵌套顺序terminate就不会存在问题。
	问题的关键是，任务的等待状态的处理。
	当当前高优先级任务等待某个事件进行同步时，必然将交出CPU的使用权，这个时候将由次最高优先级就绪任务
	（如果存在）获得CPU的使用权，势必会存在和（1）描述相冲突的情景。
	
	用“=”代表高优先级任务1，用“-”代表中优先级任务2，用“+"代表低优先级任务3，t0时刻，该3个任务均处于就绪状态。
	
	t0       t1        t2      t3     t4       t5    t6        t7
	|=======/|         |       |      /========\     |         |            <--任务1生命线
	|        \---------/       |      |        |     /---------\            <--任务2生命线
	|                  \+++++++/      |        |     |         |            <--任务3生命线
	                           |~~~~~~|        |~~~~~|         |~~~~~~~~~~~~~~~~~~~~~~~~
	t1时刻，任务1等待某个时间同步而进入Waiting状态，中优先级任务2开始运行。
	t2时刻任务任务2也因事件等待而进入waiting状态，低优先级任务3开始运行。
	t3时刻任务3结束，陷入idle loop(~).
	t4时刻产生事件激活任务1，任务1恢复运行,于t5时刻结束运行，陷入idle loop。
	t6时刻产生事件激活任务2，任务2恢复运行,于t7时刻结束运行，陷入idle loop。
	如上述情况，如何合理规划共同使用同一个系统堆栈呢？
	显然，这个时候的情景是异常复杂的，共用堆栈貌似是处理不了的。
	俗话说的好，车到山前必有路，由于OSKE OS有四个等级BCC1、BCC2、ECC1、ECC2。
	显然上述情景仅发生于ECC1和ECC2，那么，我可以先将共用堆栈在BCC1和BCC2上予以实现。
	至于ECC1和ECC2的情景下，如何实现，待往后慢慢研究。
**成果：**
	已经初步实现在9S12和mpc56xx平台该功能的支持。在Arm Cortex M7平台上，由于历史遗留问题，必须创建
	vTaskIdle任务的原因，暂不支持。

#TODO
###  1.优化gainos-tk
######深层次，优化内核代码，优化临界段的处理，解决因内核调度机制多样而导致内核不易被理解的问题。
	**疑问1**
	离散TCB成员还是聚合？这个一直是我所思考的问题，到底以何种方式来处理，会获得更好的综合性能，
	如何来控制CB变量占用的RAM资源至最小化。
	**疑问2**
	继承自uTenux的任务队列管理方式是否足够的优秀。是否有必要使用后来扩展的FIFO任务就绪队列来
	统一管理。
######发布0.02
######时间：2013年7月至2013年10月31日
###  2.基于优化后的gainos-tk，构建符合Autosar OS规范的RTOS。
######发布0.03
######时间：2013年11月至2014年9月
###  3.解决Arm Cortex M7平台现移植必须创建vTaskIdle的问题
**希望有热心的网友能够给予帮助，个人讨厌研究CPU内核相关的事情**

#gainos-studio 成果展示
### gainos-tk osek os的配置界面
![gainos os][logo1]
[logo1]:http://f.hiphotos.bdimg.com/album/s%3D1100%3Bq%3D90/sign=d9a841482e2eb938e86d7ef3e552be44/8b82b9014a90f603fec2deee3812b31bb051ed2d.jpg
### gainos-tk Com的配置界面
![gainos com][logo2]
[logo2]:http://d.hiphotos.bdimg.com/album/s%3D900%3Bq%3D90/sign=59cd59ea8ad4b31cf43c98bbb7ed5642/e4dde71190ef76c6b4cfb9829c16fdfaaf51677d.jpg

### gainos-tk Dcm的配置界面
![gainos dcm][logo3]
[logo3]:http://h.hiphotos.bdimg.com/album/s%3D1000%3Bq%3D90/sign=ded9c1645366d0167a199a28a71bef76/3bf33a87e950352a215e67a15243fbf2b2118b58.jpg

	