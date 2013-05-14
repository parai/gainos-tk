//
//  Linker script file for the VX-toolset for C166
//

// Define the near page addresses. Each DPP will point to a near page.
// It is recommended to keep __DPP3_ADDR at 0x00C000
#define __DPP0_ADDR	0xC00000
#define __DPP1_ADDR	0xE00000
#define __DPP2_ADDR	0x008000
#define __DPP3_ADDR	0x00C000

#if defined(__CPU_XC2365B__)
#include "xc2365b.lsl"
derivative my_xc2365b extends xc2365b
{
}
#else
#include <cpu.lsl>
#endif

// Define interrupt vector table
section_setup ::code
{
	vector_table "vector_table" ( vector_size = 4, size = 128, run_addr = 0xC00000, 
  				template="__vector_template", template_symbol="__lc_vector_target", 
				vector_prefix=".vector.", fill = loop)
	{
		vector (id=0, fill="__cstart");
	}
}

// Define the system stack
section_layout ::shuge (direction = high_to_low)
{
	group ( run_addr = [0xF200..0xFC00], ordered ) stack "system_stack" ( size = 512 );
}

