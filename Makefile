# makefile for osek concofmance test

COMPILER_DIR = D:/usr/opt/SW
BD = .

.PHONY:clean all

clean:
	rm -f *.o *.abs *.map err.log
	rm -f $(BD)/app/test.c $(BD)/app/test.h

tm1:
	cp -f $(BD)/osek/test/FreeOSEK/Task/Test_Sequence_01/test.c  $(BD)/app/
	cp -f $(BD)/osek/test/FreeOSEK/Task/Test_Sequence_01/test.h  $(BD)/app/
	python $(BD)/tool/gainos-studio/main.py --test $(BD)/osek/test/FreeOSEK/Task/Test_Sequence_01/test.oil $(BD)/config
	make all
	make sim

tm2:
	cp -f $(BD)/osek/test/FreeOSEK/Task/Test_Sequence_02/test.c  $(BD)/app/
	cp -f $(BD)/osek/test/FreeOSEK/Task/Test_Sequence_02/test.h  $(BD)/app/
	python $(BD)/tool/gainos-studio/main.py --test $(BD)/osek/test/FreeOSEK/Task/Test_Sequence_02/test.oil $(BD)/config
	make all
	make sim

all:
	$(COMPILER_DIR)/Prog/piper.exe $(COMPILER_DIR)/Prog/maker.exe ./mak/Makefile

tbdml:
	$(COMPILER_DIR)/Prog/hiwave.exe -W -Prod=TBDML.ini -instance=tbdml Project.abs -CMD="Go"

sim:
	$(COMPILER_DIR)/Prog/hiwave.exe -W -Prod=Full_Chip_Simulation.ini -instance=sim Project.abs