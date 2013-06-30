#Result for ConfTest
I am sorry that I cann't let the ConfTest code to be source open as some reasons.
But well I will give the test results and the reasons why some tests are failed.
#------------- Conformance Test Result ---------------
###test1   OK
###test2   OK
###test3   OK
###test4   OK
###test5   Failed
	task share resource with ISR not supported by gainos-tk
###test6   Failed
	task share resource with ISR not supported by gainos-tk
###test7   OK 
	if do the change as below
		Task4 PRIORITY(6)  --> PRIORITY(5)
###test8   OK
###test9   OK
###test10  OK
###test11  OK
###test12  OK
###test12  OK
###test13  OK
###test14  OK
###test15  OK
###test16  Failed
	GetResource for Non-preematble task was not supported by gainos-tk
	As I think,if a task is non-preemtable,it seems that it will get the RES_SCHEDULER when 
	start to run. A Non-preemtable task is treated as a task that has an internal resource 
	linked to RES_SCHEDULER in gainos-tk.
###test17  OK
###test18  OK
###test19  OK
###test20  OK
###test21  Failed,the same reason as test16
###test22  OK
###test23  Failed,the same reason as test16
