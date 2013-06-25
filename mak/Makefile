# author:parai
# makefile for HC9S12(X)

COMPILER_DIR = D:/usr/opt/SW

BD = 

CC  = $(COMPILER_DIR)/Prog/chc12.exe
ASM = $(COMPILER_DIR)/Prog/ahc12.exe
LD  = $(COMPILER_DIR)/Prog/linker.exe

COMMON_FLAGS = -WErrFileOff -WOutFileOff -EnvOBJPATH=./
# -Dtk_ppage=$30 for MC9S12DP512
# -Dtk_ppage=$15 for MC9S12XEP100
C_FLAGS   = -I$(COMPILER_DIR)/lib/hc12c/include -Mb -D__NO_FLOAT__ -CpuHCS12 -Dtk_ppage=$30 -DcfgOSEK_STD_ISR_PROCESS
ASM_FLAGS = -I$(COMPILER_DIR)/lib/hc12c/include -Mb -CpuHCS12
LD_FLAGS  = -M -WmsgNu=abcet

LIBS = $(COMPILER_DIR)/lib/hc12c/lib/ansibi.lib

INC=-I$(BD)arch/s12cpuv2/ \
	-I$(BD)bin/gainos_tk/mc9s12dp512/Project/Sources/ \
	-I$(BD)config/		\
	-I$(BD)app/ \
	-I$(BD)include/ \
	-I$(BD)osek/inc/ \
	-I$(BD)osek/portable/s12cpuv2/	\
	-I$(BD)osek/test/FreeOSEK/common/
	
OBJS=	\
	$(BD)bin/gainos_tk/mc9s12dp512/Project/Sources/main.o \
	$(BD)bin/gainos_tk/mc9s12dp512/Project/Sources/datapage.o \
	$(BD)bin/gainos_tk/mc9s12dp512/Project/Sources/Start12.o \
	$(BD)bin/gainos_tk/mc9s12dp512/Project/Sources/mc9s12dp512.o \
	$(BD)config/osek_cfg.o \
	$(BD)app/test.o \
	$(BD)osek/portable/s12cpuv2/portable.o \
	$(BD)osek/src/knl_alarm.o \
	$(BD)osek/src/knl_bitop.o \
	$(BD)osek/src/knl_misc.o \
	$(BD)osek/src/knl_task.o \
	$(BD)osek/src/knl_timer.o \
	$(BD)osek/src/knl_wait.o \
	$(BD)osek/src/osek_alarm.o \
	$(BD)osek/src/osek_counter.o \
	$(BD)osek/src/osek_event.o \
	$(BD)osek/src/osek_interrupt.o \
	$(BD)osek/src/osek_osctrl.o \
	$(BD)osek/src/osek_resource.o \
	$(BD)osek/src/osek_task.o 		\
	$(BD)osek/test/FreeOSEK/common/ctest_rst.o	
	
OBJS_LINK= 	\
	main.o \
	datapage.o \
	Start12.o \
	mc9s12dp512.o	\
	osek_cfg.o \
	test.o	\
	portable.o \
	knl_alarm.o \
	knl_bitop.o \
	knl_misc.o \
	knl_task.o \
	knl_timer.o \
	knl_wait.o \
	osek_alarm.o \
	osek_counter.o \
	osek_event.o \
	osek_interrupt.o \
	osek_osctrl.o \
	osek_resource.o \
	osek_task.o		\
	ctest_rst.o	

# common rules	
.asm.o:
	$(ASM) $*.s $(COMMON_FLAGS) $(ASM_FLAGS)

.c.o:
	$(CC) $*.c $(INC) $(COMMON_FLAGS) $(C_FLAGS)

#.prm.abs:
#	$(LD) ./prm/$*.prm $(COMMON_FLAGS) $(LD_FLAGS) -Add($(LIBS)) -Add($(OBJS_LINK)) -O$*.abs
	
all: $(OBJS) Project.abs
	echo "done all"
	
Project.abs:
	$(LD) $(BD)bin/gainos_tk/mc9s12dp512/Project/prm/Project.prm $(COMMON_FLAGS) $(LD_FLAGS) -Add($(LIBS)) -Add($(OBJS_LINK)) -O$*.abs


