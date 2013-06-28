#! /bib/python

# Automatic test script for gainos-tk
import sys,os
COMPILER_DIR = 'D:/usr/opt/SW'
def FreeOSEK(path):
	#test code is from FreeOSEK
	cwd = os.getcwd();
	bd = cwd+'/../..'
	os.system('rm -f %s/*.o %s/*.abs %s/*.map'%(bd,bd,bd))
	app = cwd+'/../../app/'
	config = cwd+'/../../config/'
	tool = cwd+'/../../tool/gainos-studio'
	print 'Copy %s/test.c and %s/test.h to %s'%(path,path,app)
	os.system('cp -f %s/test.c %s'%(path,app));
	os.system('cp -f %s/test.h %s'%(path,app));
	print 'Convert %s/test.oil to osek_cfg.c/h'%(path)
	os.system('python %s/main.py --test %s/test.oil %s'%(tool,path,config))
	os.chdir(bd);
	mkfile = '%s/osek/test/FreeOSEK/mak/Makefile'%(bd)
	os.system('%s/Prog/piper.exe %s/Prog/maker.exe %s'%(COMPILER_DIR,COMPILER_DIR,mkfile))
	os.system('%s/Prog/hiwave.exe -W -Prod=Full_Chip_Simulation.ini -instance=sim Project.abs'%(COMPILER_DIR));
	#os.system('%s/Prog/hiwave.exe -W -Prod=TBDML.ini -instance=tbdml Project.abs -CMD="Go"'%(COMPILER_DIR));
	print '          ^_^              ^_^                       ^_^                '

def ConfTest(path):
	#test code is private
	cwd = os.getcwd();
	bd = cwd+'/../..'
	os.system('rm -f %s/*.o %s/*.abs %s/*.map'%(bd,bd,bd))
	app = cwd+'/../../app/'
	config = cwd+'/../../config/'
	tool = cwd+'/../../tool/gainos-studio'
	print 'Copy %s/test.c and %s/test.h to %s'%(path,path,app)
	os.system('cp -f %s/test.c %s'%(path,app));
	os.system('cp -f %s/test.h %s'%(path,app));
	print 'Convert %s/test.oil to osek_cfg.c/h'%(path)
	os.system('python %s/main.py --test %s/test.oil %s'%(tool,path,config))
	os.chdir(bd);
	mkfile = '%s/osek/test/ConfTest/mak/Makefile'%(bd)
	os.system('%s/Prog/piper.exe %s/Prog/maker.exe %s'%(COMPILER_DIR,COMPILER_DIR,mkfile))
	os.system('%s/Prog/hiwave.exe -W -Prod=Full_Chip_Simulation.ini -instance=sim Project.abs'%(COMPILER_DIR));
	#os.system('%s/Prog/hiwave.exe -W -Prod=TBDML.ini -instance=tbdml Project.abs -CMD="Go"'%(COMPILER_DIR));
	print '          ^_^              ^_^                       ^_^                '


if __name__ == "__main__":
	# example
	# test.py FreeOSEK/Task/Test_Sequence_01
	if(len(sys.argv) == 2):
		path = sys.argv[1];
		if(path[:8] == 'FreeOSEK'):
			FreeOSEK(path);
		elif(path[:8] == 'ConfTest'):
			ConfTest(path);
