//****************************************************************************
// @Module        System Timer (STM)
// @Filename      STM.h
// @Project       DAvE_Bsp.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1797
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the STM module.
//
//----------------------------------------------------------------------------
// @Date          2013/5/22 23:25:46
//
//****************************************************************************

// USER CODE BEGIN (STM_Header,1)

// USER CODE END



#ifndef _STM_H_
#define _STM_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (STM_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (STM_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

#define STM_TIMER_0 STM_TIM0.U
#define STM_TIMER_1 STM_TIM1.U
#define STM_TIMER_2 STM_TIM2.U
#define STM_TIMER_3 STM_TIM3.U
#define STM_TIMER_4 STM_TIM4.U
#define STM_TIMER_5 STM_TIM5.U
#define STM_TIMER_6 STM_TIM6.U
#define STM_TIMER_7 STM_CAP.U


// USER CODE BEGIN (STM_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (STM_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (STM_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (STM_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void STM_vInit(void);


// USER CODE BEGIN (STM_Header,8)

// USER CODE END



#define STM_INT0 0xFD

#define STM_INT1 0xFC


// USER CODE BEGIN (STM_Header,9)

// USER CODE END


#endif  // ifndef _STM_H_
