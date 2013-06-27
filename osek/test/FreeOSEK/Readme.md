# Open OSEK Conformance Test
	Yeah, I want to test, but I don't want to design the test sequence.
	so I get the osek conformance test case code from FreeOSEK.
	
# Failed Tests

### FreeOSEK\Resource\Test_Sequence_02
	Failed at get resource for non-preemtable tasks.But I don't think this is a problem.
	As task is non-preemtable, it doesn't need to care about the priority inversion problems.
	In gainos-tk,when a task is non-preemtable,its priority when be the highest when it start
	to run.
### FreeOSEK\Resource\Test_Sequence_05
	According to OSEK OS 2.2.3 specification, I think an ISR category can get/release resource
# bugs at test codes

### FreeOSEK\Resource\Test_Sequence_03
	according to < ostestproc20.pdf > of osek 2.2.3, at page 37, Task3's priority is 3, 
	but I think should change it to 5, so that let Task3 has higher priority than Resource1.	
	
	