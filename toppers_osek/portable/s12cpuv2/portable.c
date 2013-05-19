#include "osek_kernel.h"
#include "task.h"
#include "derivative.h"

VP tcxb_sp[cfgOSEK_TASK_NUM];
FP tcxb_pc[cfgOSEK_TASK_NUM];
#define SYSTEM_STACK_SZ 512
static UINT8 lc_system_stack[SYSTEM_STACK_SZ];
/* ================== FUNCTIONs DECLARE ========================*/
void activate_r(void);
void pre_idle(void);
void dispatch_task(void);

/* ================== FUNCTIONs  ===============================*/

void set_ipl(IPL ipl)
{
    (void)ipl;
    if(ipl > 0)
    {
        __asm SEI;// disable interrupt
    }
}
IPL current_ipl(void)
{
    return 0;
}
//   activate_r:
//       When a task is scheduled and dispatched for the first time, this function is called
//      Address "activare_r" is set to the PC saving area in TCB by activate_context( ) in portable.h
//           set tinib_exepri[runtsk] to   tcb_curpri[runtsk], where runtsk is the ID of the task to be dispatched
//           enabe interrupt
//           jump to tinib_task[runtsk]
void activate_r(void)
{
    tcb_curpri[runtsk] = tinib_exepri[runtsk];
    __asm CLI; // enable interrupt
    tinib_task[runtsk]();    
}

//     pre_idle:
//        switch the stack from a task stack to the "system_stack"
//        callevel = TCL_ISR2 (type2 interrupt level)
//        fall to idle_loop
void pre_idle(void)
{
    __asm  lds #lc_system_stack:SYSTEM_STACK_SZ 
    callevel = TCL_ISR2;
    //  idle_loop:
    //     the body of the idle task
    //         enable interrupt
    //         wait  for a while  (wait for an interrupt to arrive)
    //         disable interupt
    //         if (schedtsk == INVALID)  jump back to "idle_loop"
    //         callevel = TCS_TASK
    //         jump to "start_dispatch"
    idle_loop:
    __asm CLI; // enable interrupt
    __asm nop; // wait for a while
    __asm nop;
    __asm nop;
    __asm nop;
    __asm SEI;// disable interrupt
    if (INVALID_TASK == schedtsk)
    {
        goto  idle_loop;
    }
    callevel = TCL_TASK;
    __asm jmp start_dispatch;  
}
//    start_dispatch:
//       this function is called to dispatch schedtsk (the task that the scheduler has just selected)
//          set schedtsk to runtsk
//          if (runtsk == INVALID_TASK) jump to "pre_idle"
//          restore sp from tcxb_sp[runtsk] 
//          if  (PreTaskHook != 0) call_pretaskhook()
//          continue on to dispatch_task
void start_dispatch(void)
{
    runtsk = schedtsk;
    if (INVALID_TASK == runtsk)
    {
        __asm jmp  pre_idle;
    }
    __asm ldx  #tcxb_sp;
    __asm ldab #2
    __asm ldaa runtsk
    __asm mul 
    __asm lds  d,x;     // sp = tcxb_sp[runtsk]
    PreTaskHook();
    
    __asm jmp dispatch_task;
}

//   dispatch_task:  this is called only from start_dispatch 
//       dispatch to the locatoin saved in tcxb_pc[runtsk]
void dispatch_task(void)
{
    //tcxb_pc[runtsk]();
    __asm{
        ldab  #3
        ldaa  runtsk
        mul   
        tfr   d,y
        jmp  [tcxb_pc,y]
    }
}
//    exit_and_dispatch:
//       this is called from TerminateTask() and ChainTask(), when one task relinquishes CPU
//       and another task is scheduled and dispatched
//             if (PostTaskHook != 0) PosTaskHook();
//             continue on to "start_dispatch"
void exit_and_dispatch(void)
/* void dispatcher(void)*/
{
    PostTaskHook();
    __asm jmp start_dispatch;
}

//      dispatcher_r:
//          If a task relinquishes the CPU through "dispatch",  
//          it executes this function to be dispatched when it is scheduled again.
//              restore the non-desctructive registers (PPAGE)
//              restore the value of PC (the address  to return from "dispatch") from stack
void dispatcher_r(void)
{
    __asm   pula
    __asm   staa	$30	      /* restore PPAGE */
    __asm   rti     
}
void activate_context(TaskType TaskID)
{
    tcxb_pc[TaskID] = (FP)activate_r;

	tcxb_sp[TaskID] = (VP)( (UINT32)tinib_stk[TaskID] + (UINT32)tinib_stksz[TaskID]);
}
static UINT8 knl_tskind = 0; /* task independent part nested value */
void EnterISR2(void)
{
    if (INVALID_TASK != runtsk)
    {
        callevel = TCL_ISR2;
        knl_tskind++;
    }
}
void ExitISR2(void)
{
    if (INVALID_TASK != runtsk)
    {
        knl_tskind--;
        if(0U == knl_tskind)
        {
            callevel = TCL_TASK;
            if(schedtsk != runtsk)
            {
                dispatch();
            }
        }
    }
}
#pragma CODE_SEG __NEAR_SEG NON_BANKED
//   dispatch:
//      this function is called by a task
//            save the non-distructive registers (PPAGE)
//            save sp in the sp saving area in TCB
//            save "dispatcher_r" in the pc saving area in TCB
//            jump to "dispatcher
interrupt 4 void dispatch_impl(void)
{
    __asm ldaa	$30;		        
	__asm psha;                  /* save PPAGE */
	__asm ldx  #tcxb_sp;
    __asm ldab  #2
    __asm ldaa  runtsk
    __asm mul 
    __asm sts  d,x;             // tcxb_sp[runtsk] = sp
    
    tcxb_pc[runtsk] = (FP)dispatcher_r;
    
    __asm jmp exit_and_dispatch // jump to "dispatcher"
}

interrupt 7 ISR(SystemTick)
{ 
    CRGFLG &=0xEF;			// clear the interrupt flag
    EnterISR2();
    (void)SignalCounter(0);
    ExitISR2(); 
}
#pragma CODE_SEG DEFAULT
