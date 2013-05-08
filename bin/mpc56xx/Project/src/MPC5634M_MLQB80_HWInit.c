
/*
 *
 * FILE : MPC5634M_MLQB80_HWInit.c
 *
 * DESCRIPTION:
 *  This file contains all MPC5634M_MLQB80 derivative needed initializations, 
 *  and all initializations for the MPC5634M_MLQB80 boards which are supported.
 *  This includes setting up the External Bus Interface to allow access
 *  to memory on the external bus, and ensuring there is a valid entry in
 *  the MMU for the external memory access.
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include "MPC5634M_MLQB80.h"       /* MPC55xx platform development header            */
#include "MPC5634M_MLQB80_HWInit.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************/
/* MPC5634M_MLQB80 derivative specific hardware initialization */
/*******************************************************/

/* Symbol L2SRAM_LOCATION is defined in the application linker command file (.lcf) 
   It is defined to the start of the L2SRAM of the MPC5634M_MLQB80. 
*/
/*lint -esym(752, L2SRAM_LOCATION) */
extern long L2SRAM_LOCATION;  


__asm void INIT_Derivative(void) 
{
nofralloc

    /* MPC5634M_MLQB80 L2SRAM initialization code                         */
    lis r11,L2SRAM_LOCATION@h /* Base address of the L2SRAM, 64-bit word aligned */
    ori r11,r11,L2SRAM_LOCATION@l

    li r12,752  /* Loop counter to get all of L2SRAM; 94k/4 bytes/32 GPRs = 752 */
    mtctr r12

    init_l2sram_loop:
        stmw r0,0(r11)        /* Write all 32 GPRs to L2SRAM */
        addi r11,r11,128      /* Inc the ram ptr; 32 GPRs * 4 bytes = 128 */
        bdnz init_l2sram_loop /* Loop for 94k of L2SRAM */

    blr
}

/*******************************************************/
/* MPC5634M_MLQB80 boards specific hardware initializations    */
/*******************************************************/

/** This macro allows to use C defined address with the inline assembler */
#define MAKE_HLI_COMPATIBLE(hli_name, c_expr) enum { hli_name=/*lint -e30*/((int)(c_expr)) };

/*----------------------------------------------------------------------------*/
/* Function declarations                                                      */
/*----------------------------------------------------------------------------*/

/* Initialize a set of contiguous PCRs */
__asm void InitPCRs(void); 

/* Initialize the SIU External Bus Interface */
__asm void __initSIUExtBusInterface(void);

/* Initialize the used EBI Chip Selects */
__asm void __initEBIChipSelects(void);

/* Write one MMU Table Entry */
__asm void WriteMMUTableEntry( void );

/* Initialize the needed MMU Table entries */
__asm void __initMMUExternalMemory(void);

/*----------------------------------------------------------------------------*/
/* Function implementations                                                   */
/*----------------------------------------------------------------------------*/

__asm void INIT_ExternalBusAndMemory(void) 
{
nofralloc

    mflr     r28
    
    /* Initialize the SIU External Bus Interface */
    bl __initSIUExtBusInterface
    /* Initialize the used EBI Chip Selects */
    bl __initEBIChipSelects
    /* Initialize the needed MMU Table entries */
    bl __initMMUExternalMemory
    
    mtlr     r28
    
    blr
}

/*----------------------------------------------------------------------------*/
/* External Memory Locations from lcf file                                    */
/*----------------------------------------------------------------------------*/

#if INIT_USED_BOARD==MPC5633DEMO_AXM_0321
/* Symbol AXM_0321_EXTERNAL_RAM is defined in the application linker command file (.lcf) 
   It is defined to the start of the external memory on the MPC5633DEMO_AXM-0321 board 
*/
extern unsigned long AXM_0321_EXTERNAL_RAM[]; 
#endif

/*----------------------------------------------------------------------------*/
/* SIU External Bus Interface                                                 */
/*----------------------------------------------------------------------------*/

/* Initialize a set of contiguous PCRs:               */
/* r3: the firts PCR to initialize                    */
/* r4: the value to write in the PCRs                 */ 
/* r5: the number of PCRs to initialize               */
__asm void InitPCRs(void) 
{
nofralloc

    mtctr r5                   /* intialize ctr with the number of PCRs to initialize */
    pcr_init_loop:
        sth r4,0(r3)           /* Write r4 to current PCR address */
        addi r3,r3, 2          /* Inc the memory ptr by 2 to point to the next PCR */
        bdnz pcr_init_loop     /* Loop for ctr PCRs */

    blr
}

/* Initialize the SIU External Bus Interface */
__asm void __initSIUExtBusInterface(void)
{ 
MAKE_HLI_COMPATIBLE(SIU_PCR0,&SIU.PCR[0].R)
MAKE_HLI_COMPATIBLE(SIU_PCR4,&SIU.PCR[4].R)
MAKE_HLI_COMPATIBLE(SIU_PCR28,&SIU.PCR[28].R)
MAKE_HLI_COMPATIBLE(SIU_PCR62,&SIU.PCR[62].R)
MAKE_HLI_COMPATIBLE(SIU_PCR64,&SIU.PCR[64].R)
MAKE_HLI_COMPATIBLE(SIU_PCR68,&SIU.PCR[68].R)
nofralloc

    mflr r27

    /*  This initializes the MPC5633 external bus
        Set up the pins
        Address bus PCR 4 - 27
        Configure address bus pins
    */
    lis r3,SIU_PCR4@h          /* First PCR Address bus is PCR 4 */
    ori r3,r3,SIU_PCR4@l
    li r5,24                   /* Loop counter to get all address bus PCR (4 to 27) -> 24 PCRs  */
    li r4, 0x0440              /* PCRs initialization value */
    bl InitPCRs

    /*  Data bus PCR 28-59
        Configure data bus pins
    */
    lis r3,SIU_PCR28@h         /* First PCR for data bus is PCR 28 */
    ori r3,r3,SIU_PCR28@l
    li r5,32                   /* Loop counter to get all data bus PCR (28-59) -> 32 PCRs  */
    li r4, 0x0440              /* PCRs initialization value */
    bl InitPCRs

    /*  Configure minimum bus control pins
        RD/WR  & BDIP PCR 62/63
    */
    lis r3,SIU_PCR62@h         /* First PCR for is PCR 62 */
    ori r3,r3,SIU_PCR62@l
    li r5,2                    /* Loop counter to get all PCR (62-63) -> 2 PCRs  */
    li r4, 0x0440              /* PCRs initialization value */
    bl InitPCRs

    /*  WE[0-4] PCR 64-67
    */
    lis r3,SIU_PCR64@h         /* First PCR for is PCR 64 */
    ori r3,r3,SIU_PCR64@l
    li r5,4                    /* Loop counter to get all PCR (64-67) -> 4 PCRs  */
    li r4, 0x0443              /* PCRs initialization value */
    bl InitPCRs

    /*  OE & TS
    */
    lis r3,SIU_PCR68@h         /* First PCR for is PCR 68 */
    ori r3,r3,SIU_PCR68@l
    li r5,2                    /* Loop counter to get all PCR (68-69) -> 2 PCRs  */
    li r4, 0x0443              /* PCRs initialization value */
    bl InitPCRs
    
    /*  Configure the chip selects
        CS[0-3]
    */
    lis r3,SIU_PCR0@h          /* First PCR for is PCR 0 */
    ori r3,r3,SIU_PCR0@l
    li r5,4                    /* Loop counter to get all PCR (0-3) -> 4 PCRs  */
    li r4, 0x0443              /* PCRs initialization value */
    bl InitPCRs
    
    mtlr r27
    
    blr
}

/*----------------------------------------------------------------------------*/
/* EBI Chip Selects                                                           */
/*----------------------------------------------------------------------------*/

/* Initialize the used EBI Chip Selects */
__asm void __initEBIChipSelects(void)
{
#if INIT_USED_BOARD==MPC5633DEMO_AXM_0321
MAKE_HLI_COMPATIBLE(EBBI_CS0_BR,&EBI.CS[0].BR.R)
MAKE_HLI_COMPATIBLE(EBBI_CS0_OR,&EBI.CS[0].OR.R)
#endif
nofralloc

#if INIT_USED_BOARD==MPC5633DEMO_AXM_0321
    /*  CY7C1338 512K External SRAM - 4 beat burst, 0 wait
        Set up Memory Controller CS0 @ AXM_0321_EXTERNAL_RAM
    */
    /*  EBI.CS[0].BR.R = (unsigned long)AXM_0321_EXTERNAL_RAM | 0x41UL;
    */
    lis      r3,AXM_0321_EXTERNAL_RAM@h
    addi     r0,r3,AXM_0321_EXTERNAL_RAM@l
    ori      r0,r0,0x0041    
    lis      r3,EBBI_CS0_BR@h
    ori      r3,r3,EBBI_CS0_BR@l
    stw      r0,0(r3)
    /*  EBI.CS[0].OR.R = 0xfff80000;
    */
    lis      r0,0xfff8
    lis      r3,EBBI_CS0_OR@h
    ori      r3,r3,EBBI_CS0_OR@l
    stw      r0,0(r3)    
#endif

    blr
}

/*----------------------------------------------------------------------------*/
/* Writing to MMU Table Entries                                               */
/*----------------------------------------------------------------------------*/

/* Write one MMU Table Entry:               */
/* r3, r4, r5 and r6 must hold              */
/* the values of MAS0, MAS1, MAS2 and MAS3  */
__asm void WriteMMUTableEntry( void )
{ 
nofralloc

    /* Write MMU Assist Register 0 (MAS0); SPR 624 */
    mtspr   624, r3
    /* Write MMU Assist Register 1 (MAS1); SPR 625 */
    mtspr   625, r4
    /* Write MMU Assist Register 2 (MAS2); SPR 626 */
    mtspr   626, r5
    /* Write MMU Assist Register 3 (MAS3); SPR 627 */
    mtspr   627, r6
    /* Write the table entry */
    tlbwe

    blr
}

/* Initialize the needed MMU Table entries */
__asm void __initMMUExternalMemory(void)
{
#if INIT_USED_BOARD==MPC5633DEMO_AXM_0321
/* Set up MMU for External Memory
   Base address = 0x2000_0000
   16 MByte Memory Space, Not Guarded, Cachable, All Access
*/
MAKE_HLI_COMPATIBLE(AXM_0321_EXT_RAM_MAS0_VALUE,MAS0_VALUE(2))
/* 16 MB memory space, valid, protected, global which matches with all process IDs */
MAKE_HLI_COMPATIBLE(AXM_0321_EXT_RAM_MAS1_VALUE,MAS1_VALUE(V_VALID, IPROT_PROTECTED, TID_GLOBAL, 0, TSIZE_16MB)) 
MAKE_HLI_COMPATIBLE(AXM_0321_EXT_RAM_MAS2_FLAGS,MAS2_FLAGS(SHARED_CACHE_STATE_NOT_USED, WRITE_BACK, CACHEABLE, MEM_COHERENCE_NREQ, NOT_GUARDED, BIG_ENDIAN ))
MAKE_HLI_COMPATIBLE(AXM_0321_EXT_RAM_MAS3_FLAGS,MAS3_FLAGS(READ_WRITE_EXECUTE))
#endif
nofralloc

     mflr     r27

#if INIT_USED_BOARD==MPC5633DEMO_AXM_0321
     /* load r3 with MAS0 value */
     lis r3,AXM_0321_EXT_RAM_MAS0_VALUE@h
     ori r3,r3,AXM_0321_EXT_RAM_MAS0_VALUE@l
     
     /* load r4 with MAS1 value */
     lis r4,AXM_0321_EXT_RAM_MAS1_VALUE@h
     ori r4,r4,AXM_0321_EXT_RAM_MAS1_VALUE@l
     
     /* load r5 with the external RAM address from the lcf file */       
     lis r5,AXM_0321_EXTERNAL_RAM@h
     ori r5,r5,AXM_0321_EXTERNAL_RAM@l
     
     /* mask with 0xfffff000 */
     clrrwi   r5,r5,12
     
     /* copy the masked external ram address to r6 also */
     mr r6,r5
     
     /* end MAS2 setup in r3 */
     ori r5,r5,AXM_0321_EXT_RAM_MAS2_FLAGS@l
     
     /* end MAS3 setup in r4 */
     ori r6,r6,AXM_0321_EXT_RAM_MAS3_FLAGS@l
     
     /* write the MMU entry defined through r3, r4, r5 and r6 */ 
     bl WriteMMUTableEntry 
#endif

     mtlr r27

     blr
}

#ifdef __cplusplus
}
#endif
