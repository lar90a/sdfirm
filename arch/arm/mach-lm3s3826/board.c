#include <target/generic.h>
#include <target/arch.h>
#include <target/irq.h>
#include <target/heap.h>
#include <target/mtd.h>

extern caddr_t __bss_stop[];

void mem_init(void)
{
	heap_range_init((caddr_t)__bss_stop);
}

#define cpu_init()	clk_hw_set_config(CLK_CONFIG)

void board_early_init(void)
{
	cpu_init();
	mem_init();

	DEVICE_ARCH(DEVICE_ARCH_ARM);
}

void board_late_init(void)
{
}
