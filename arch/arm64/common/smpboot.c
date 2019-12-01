#include <target/arch.h>
#include <target/smp.h>

#define INVALID_ADDR		0

static volatile uint64_t *cpu_spin_table = (uint64_t *)(0x10000 - NR_CPUS * 8);
static uint64_t cpu_context_table[NR_CPUS];
void __smp_jump(void *, void *, void *, void *, void *);

__noreturn void cpu_spin(int cpu)
{
	/* In simulation environment, cores are not run parallel, it relies
	 * on other cores get to this line first, otherwise secondary cores
	 * bring up will fail.
	 */
	cpu_spin_table[cpu] = INVALID_ADDR;

	do {
		wfe();
	} while (cpu_spin_table[cpu] == INVALID_ADDR);
	__smp_jump((void *)cpu_context_table[cpu], 0, 0, 0,
		   (void *)cpu_spin_table[cpu]);
	__builtin_unreachable();
}

void smp_hw_cpu_on(cpu_t cpu, caddr_t ep, caddr_t context)
{
	cpu_spin_table[cpu & 0xff] = ep;
	cpu_context_table[cpu & 0xff] = context;
	dsb(sy);
	sev();
}

void smp_hw_cpu_boot(void)
{
	smp_boot_cpu = 0;
}