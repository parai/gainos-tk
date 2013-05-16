//****************************************************************************
// @Module        Interrupt System (INT)
// @Filename      INT.h
// @Project       DAvE_Bsp.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1797
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the INT module.
//
//----------------------------------------------------------------------------
// @Date          2013/5/16 21:37:27
//
//****************************************************************************

// USER CODE BEGIN (INT_Header,1)

// USER CODE END



#ifndef _INT_H_
#define _INT_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (INT_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (INT_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   -------------------------------------------------------------------------
//   Defines for the parameter IntName
//   -------------------------------------------------------------------------

#define SSC0_TRANSMIT_SRN        SSC0_TSRC
#define SSC0_ERROR_SRN           SSC0_ESRC
#define SSC0_RECEIVE_SRN         SSC0_RSRC
#define SSC1_TRANSMIT_SRN        SSC1_TSRC
#define SSC1_ERROR_SRN           SSC1_ESRC
#define SSC1_RECEIVE_SRN         SSC1_RSRC
#define ASC0_TRANSMIT_SRN        ASC0_TSRC
#define ASC0_ERROR_SRN           ASC0_ESRC
#define ASC0_RECEIVE_SRN         ASC0_RSRC
#define ASC0_TRANSMIT_BUFFER_SRN ASC0_TBSRC
#define ASC1_TRANSMIT_SRN        ASC1_TSRC
#define ASC1_ERROR_SRN           ASC1_ESRC
#define ASC1_RECEIVE_SRN         ASC1_RSRC
#define ASC1_TRANSMIT_BUFFER_SRN ASC1_TBSRC
#define GPTA0_SRN_0              GPTA0_SRC00
#define GPTA0_SRN_1              GPTA0_SRC01
#define GPTA0_SRN_2              GPTA0_SRC02
#define GPTA0_SRN_3              GPTA0_SRC03
#define GPTA0_SRN_4              GPTA0_SRC04
#define GPTA0_SRN_5              GPTA0_SRC05
#define GPTA0_SRN_6              GPTA0_SRC06
#define GPTA0_SRN_7              GPTA0_SRC07
#define GPTA0_SRN_8              GPTA0_SRC08
#define GPTA0_SRN_9              GPTA0_SRC09
#define GPTA0_SRN_10             GPTA0_SRC10
#define GPTA0_SRN_11             GPTA0_SRC11
#define GPTA0_SRN_12             GPTA0_SRC12
#define GPTA0_SRN_13             GPTA0_SRC13
#define GPTA0_SRN_14             GPTA0_SRC14
#define GPTA0_SRN_15             GPTA0_SRC15
#define GPTA0_SRN_16             GPTA0_SRC16
#define GPTA0_SRN_17             GPTA0_SRC17
#define GPTA0_SRN_18             GPTA0_SRC18
#define GPTA0_SRN_19             GPTA0_SRC19
#define GPTA0_SRN_20             GPTA0_SRC20
#define GPTA0_SRN_21             GPTA0_SRC21
#define GPTA0_SRN_22             GPTA0_SRC22
#define GPTA0_SRN_23             GPTA0_SRC23
#define GPTA0_SRN_24             GPTA0_SRC24
#define GPTA0_SRN_25             GPTA0_SRC25
#define GPTA0_SRN_26             GPTA0_SRC26
#define GPTA0_SRN_27             GPTA0_SRC27
#define GPTA0_SRN_28             GPTA0_SRC28
#define GPTA0_SRN_29             GPTA0_SRC29
#define GPTA0_SRN_30             GPTA0_SRC30
#define GPTA0_SRN_31             GPTA0_SRC31
#define GPTA0_SRN_32             GPTA0_SRC32
#define GPTA0_SRN_33             GPTA0_SRC33
#define GPTA0_SRN_34             GPTA0_SRC34
#define GPTA0_SRN_35             GPTA0_SRC35
#define GPTA0_SRN_36             GPTA0_SRC36
#define GPTA0_SRN_37             GPTA0_SRC37
#define GPTA1_SRN_0              GPTA1_SRC00
#define GPTA1_SRN_1              GPTA1_SRC01
#define GPTA1_SRN_2              GPTA1_SRC02
#define GPTA1_SRN_3              GPTA1_SRC03
#define GPTA1_SRN_4              GPTA1_SRC04
#define GPTA1_SRN_5              GPTA1_SRC05
#define GPTA1_SRN_6              GPTA1_SRC06
#define GPTA1_SRN_7              GPTA1_SRC07
#define GPTA1_SRN_8              GPTA1_SRC08
#define GPTA1_SRN_9              GPTA1_SRC09
#define GPTA1_SRN_10             GPTA1_SRC10
#define GPTA1_SRN_11             GPTA1_SRC11
#define GPTA1_SRN_12             GPTA1_SRC12
#define GPTA1_SRN_13             GPTA1_SRC13
#define GPTA1_SRN_14             GPTA1_SRC14
#define GPTA1_SRN_15             GPTA1_SRC15
#define GPTA1_SRN_16             GPTA1_SRC16
#define GPTA1_SRN_17             GPTA1_SRC17
#define GPTA1_SRN_18             GPTA1_SRC18
#define GPTA1_SRN_19             GPTA1_SRC19
#define GPTA1_SRN_20             GPTA1_SRC20
#define GPTA1_SRN_21             GPTA1_SRC21
#define GPTA1_SRN_22             GPTA1_SRC22
#define GPTA1_SRN_23             GPTA1_SRC23
#define GPTA1_SRN_24             GPTA1_SRC24
#define GPTA1_SRN_25             GPTA1_SRC25
#define GPTA1_SRN_26             GPTA1_SRC26
#define GPTA1_SRN_27             GPTA1_SRC27
#define GPTA1_SRN_28             GPTA1_SRC28
#define GPTA1_SRN_29             GPTA1_SRC29
#define GPTA1_SRN_30             GPTA1_SRC30
#define GPTA1_SRN_31             GPTA1_SRC31
#define GPTA1_SRN_32             GPTA1_SRC32
#define GPTA1_SRN_33             GPTA1_SRC33
#define GPTA1_SRN_34             GPTA1_SRC34
#define GPTA1_SRN_35             GPTA1_SRC35
#define GPTA1_SRN_36             GPTA1_SRC36
#define GPTA1_SRN_37             GPTA1_SRC37
#define LTCA2_SRN_0              LTCA2_SRC00
#define LTCA2_SRN_1              LTCA2_SRC01
#define LTCA2_SRN_2              LTCA2_SRC02
#define LTCA2_SRN_3              LTCA2_SRC03
#define LTCA2_SRN_4              LTCA2_SRC04
#define LTCA2_SRN_5              LTCA2_SRC05
#define LTCA2_SRN_6              LTCA2_SRC06
#define LTCA2_SRN_7              LTCA2_SRC07
#define DMA_SRN_0                DMA_SRC0
#define DMA_SRN_1                DMA_SRC1
#define DMA_SRN_2                DMA_SRC2
#define DMA_SRN_3                DMA_SRC3
#define DMA_SRN_4                DMA_SRC4
#define DMA_SRN_5                DMA_SRC5
#define DMA_SRN_6                DMA_SRC6
#define DMA_SRN_7                DMA_SRC7
#define CPU_SRN_0                CPU_SRC0
#define CPU_SRN_1                CPU_SRC1
#define CPU_SRN_2                CPU_SRC2
#define CPU_SRN_3                CPU_SRC3
#define ADC_SRN_0                ADC0_SRC0
#define ADC_SRN_1                ADC0_SRC1
#define ADC_SRN_2                ADC0_SRC2
#define ADC_SRN_3                ADC0_SRC3
#define ADC_SRN_4                ADC0_SRC4
#define ADC_SRN_5                ADC0_SRC5
#define ADC_SRN_6                ADC0_SRC6
#define ADC_SRN_7                ADC0_SRC7
#define ADC_SRN_8                ADC0_SRC8
#define FADC_SRN_0               FADC_SRC0
#define FADC_SRN_1               FADC_SRC1
#define FADC_SRN_2               FADC_SRC2
#define FADC_SRN_3               FADC_SRC3
#define CAN_SRN_0                CAN_SRC0
#define CAN_SRN_1                CAN_SRC1
#define CAN_SRN_2                CAN_SRC2
#define CAN_SRN_3                CAN_SRC3
#define CAN_SRN_4                CAN_SRC4
#define CAN_SRN_5                CAN_SRC5
#define CAN_SRN_6                CAN_SRC6
#define CAN_SRN_7                CAN_SRC7
#define CAN_SRN_8                CAN_SRC8
#define CAN_SRN_9                CAN_SRC9
#define CAN_SRN_10               CAN_SRC10
#define CAN_SRN_11               CAN_SRC11
#define CAN_SRN_12               CAN_SRC12
#define CAN_SRN_13               CAN_SRC13
#define CAN_SRN_14               CAN_SRC14
#define CAN_SRN_15               CAN_SRC15
#define SCU_SRN_0                SCU_SRC0
#define SCU_SRN_1                SCU_SRC1
#define SCU_SRN_2                SCU_SRC2
#define SCU_SRN_3                SCU_SRC3
#define STM_SRN_0                STM_SRC0
#define STM_SRN_1                STM_SRC1
#define MSC0_SRN_0               MSC0_SRC0
#define MSC0_SRN_1               MSC0_SRC1
#define MSC1_SRN_0               MSC1_SRC0
#define MSC1_SRN_1               MSC1_SRC1
#define MLI0_SRN_0               DMA_MLI0SRC0
#define MLI0_SRN_1               DMA_MLI0SRC1
#define MLI0_SRN_2               DMA_MLI0SRC2
#define MLI0_SRN_3               DMA_MLI0SRC3
#define MLI1_SRN_0               DMA_MLI1SRC0
#define MLI1_SRN_1               DMA_MLI1SRC1
#define PCP_ERROR_CPU_SRN        PCP_ESRC

// USER CODE BEGIN (INT_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (INT_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (INT_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (INT_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void INT_vInit(void);


// USER CODE BEGIN (INT_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CPU0INT    0xFE

// USER CODE BEGIN (INT_Header,9)

// USER CODE END


#endif  // ifndef _INT_H_
