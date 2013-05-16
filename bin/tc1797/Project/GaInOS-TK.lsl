//****************************************************************************
//**                                                                         *
//**  FILE        :  template.lsl                                            *
//**                                                                         *
//**  DESCRIPTION :  Project specific Linker Script.                         *
//**                                                                         *
//**  Copyright 2007-2010 Altium BV                                         *
//**                                                                         *
//****************************************************************************

// Include the CPU specific .lsl file
// The CPU is specified by the __CPU__ macro
#ifndef __CPU__
# error No CPU defined, please link with -D__CPU__=<cpu>
#endif

#define __QUOTE_ME2(x) #x
#define __QUOTE_ME(x) __QUOTE_ME2(x)
#define CPULSL_FILE __QUOTE_ME(__CPU__.lsl)

#include CPULSL_FILE

// Define default external memory
// These memory definitions can be replaced by the Debug Target Configuration Wizard

#ifndef HAS_ON_CHIP_FLASH       // On-chip flash is located at 0x[8a]0000000
memory xrom (tag="External ROM",tag="dtc")
{
        mau = 8;
        size = 1M;
        type = rom;
        // segment 0x8 is mapped on segment 0xa
        map     cached (dest=bus:spe:fpi_bus, dest_offset=0x80000000,           size=1M);
        map not_cached (dest=bus:spe:fpi_bus, dest_offset=0xa0000000, reserved, size=1M);
}
#endif

#ifndef HAS_NO_EXTERNAL_RAM     // No EBU or no xRam
memory xram (tag="External RAM",tag="dtc")
{
        mau = 8;
        size = 1M;
        type = ram;
        // segment 0x8 is mapped on segment 0xa
        map     cached (dest=bus:spe:fpi_bus, dest_offset=0x80400000,           size=1M);
        map not_cached (dest=bus:spe:fpi_bus, dest_offset=0xa0400000, reserved, size=1M);
}
#endif

#ifndef LIBRARIES       /* libraries in abs24 space, but reserve abs18 */
#define LIBRARIES       [0x00000000+16k .. 0x00000000+2M] | \
                        [0x10000000+16k .. 0x10000000+2M] | \
                        [0x20000000+16k .. 0x20000000+2M] | \
                        [0x30000000+16k .. 0x30000000+2M] | \
                        [0x40000000+16k .. 0x40000000+2M] | \
                        [0x50000000+16k .. 0x50000000+2M] | \
                        [0x60000000+16k .. 0x60000000+2M] | \
                        [0x70000000+16k .. 0x70000000+2M] | \
                        [0x80000000+16k .. 0x80000000+2M] | \
                        [0x90000000+16k .. 0x90000000+2M] | \
                        [0xa0000000+16k .. 0xa0000000+2M] | \
                        [0xb0000000+16k .. 0xb0000000+2M] | \
                        [0xc0000000+16k .. 0xc0000000+2M] | \
                        [0xd0000000+16k .. 0xd0000000+2M] | \
                        [0xe0000000+16k .. 0xe0000000+2M] | \
                        [0xf0000000+16k .. 0xf0000000+2M]
#endif

section_layout ::linear
{
        // libraries in abs24 space, but reserve abs18 
        // space for .zro variables 
        group libraries (ordered, contiguous, run_addr=LIBRARIES)
        {
                select "(.text*.libc|.text*.libcs|.text*.libcs_fpu|.text*.libfp|.text*.libfpt|.text*.librt|.text*.libcp*|.text*.libstl*)";
        }
}


