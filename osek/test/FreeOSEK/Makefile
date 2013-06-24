# makefile for osek concofmance test

COMPILER_DIR = D:/usr/opt/SW

.PHONY:clean all

clean:
	rm -f *.o *.abs *.map err.log

all:
	make start -f ./mak/Makefile

tbdml:
	$(COMPILER_DIR)/Prog/hiwave.exe -W -Prod=TBDML.ini -instance=tbdml Project.abs -CMD="Go"

sim:
	$(COMPILER_DIR)/Prog/hiwave.exe -W -Prod=Full_Chip_Simulation.ini -instance=sim Project.abs