# author:parai
# makefile for HC9S12(X)

COMPILER_DIR = D:/usr/opt/SW

CC  = $(COMPILER_DIR)/Prog/chc12.exe
ASM = $(COMPILER_DIR)/SW/Prog/ahc12.exe
LD  = $(COMPILER_DIR)/SW/Prog/linker.exe

COMMON_FLAGS = -WErrFileOff -WOutFileOff -EnvOBJPATH=./
# -Dtk_ppage=$30 for MC9S12DP512
# -Dtk_ppage=$15 for MC9S12XEP100

C_FLAGS   = -I$(COMPILER_DIR)/lib/hc12c/include -Mb -CpuHCS12 -Dtk_ppage=$30
ASM_FLAGS = -I$(COMPILER_DIR)/lib/hc12c/include -Mb -CpuHCS12
LD_FLAGS  = -M -WmsgNu=abcet

LIBS = $(COMPILER_DIR)/lib/hc12c/lib/ansibi.lib

INC=-Iarch/s12cpuv2/ \
	-Ibin/gainos_tk/mc9s12dp512/Project/Sources/ \
	-Iconfig/ \
	-Iinclude/ \
	-Iosek/inc/ \
	-Iosek/portable/s12cpuv2/ \
	-Itoppers_osek/bin/mc9s12dp512/Project/Sources/ \
	-Itoppers_osek/config/ \
	-Itoppers_osek/include/ \
	-Itoppers_osek/kernel/ \
	-Itoppers_osek/portable/s12cpuv2/ \
	
OBJS=app/app.o \
	bin/gainos_tk/mc9s12dp512/Project/Sources/main.o \
	bin/gainos_tk/mc9s12dp512/Project/Sources/datapage.o \
	bin/gainos_tk/mc9s12dp512/Project/Sources/Start12.o \
	config/osek_cfg.o \
	osek/portable/s12cpuv2/portable.o \
	osek/src/knl_alarm.o \
	osek/src/knl_bitop.o \
	osek/src/knl_misc.o \
	osek/src/knl_task.o \
	osek/src/knl_timer.o \
	osek/src/knl_wait.o \
	osek/src/osek_alarm.o \
	osek/src/osek_counter.o \
	osek/src/osek_event.o \
	osek/src/osek_interrupt.o \
	osek/src/osek_osctrl.o \
	osek/src/osek_resource.o \
	osek/src/osek_task.o 	\
	mkfile/mc9s12dp512.o
	
OBJS_LINK= app.o \
	main.o \
	datapage.o \
	Start12.o \
	osek_cfg.o \
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
	osek_task.o 	\
	mc9s12dp512.o

TARGET = Project.abs
.s.o:
	$(ASM) $*.s $(COMMON_FLAGS) $(ASM_FLAGS)

.c.o:
	$(CC) $*.c $(INC) $(COMMON_FLAGS) $(C_FLAGS)

all:$(OBJS) $(TARGET)
	echo "done all"

$(TARGET):
	$(LD) bin/gainos_tk/mc9s12dp512/Project/prm/Project.prm $(COMMON_FLAGS) $(LD_FLAGS) -Add($(LIBS)) -Add($(OBJS_LINK)) -M -O$*.abs

#9s12:
#	D:/usr/opt/SW/Prog/piper.exe D:/usr/opt/SW/Prog/maker.exe ./mkfile/Makefile.9s12.mak

#tbdml:
#	D:/usr/opt/SW/Prog/hiwave.exe -W -Prod=TBDML.ini -instance=tbdml Project.abs -CMD="Go"

#sim:
#	D:/usr/opt/SW/Prog/hiwave.exe -W -Prod=Full_Chip_Simulation.ini -instance=sim Project.abs

