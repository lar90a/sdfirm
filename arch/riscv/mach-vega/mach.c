/*
 * ZETALOG's Personal COPYRIGHT
 *
 * Copyright (c) 2019
 *    ZETALOG - "Lv ZHENG".  All rights reserved.
 *    Author: Lv "Zetalog" Zheng
 *    Internet: zhenglv@hotmail.com
 *
 * This COPYRIGHT used to protect Personal Intelligence Rights.
 * Redistribution and use in source and binary forms with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the Lv "Zetalog" ZHENG.
 * 3. Neither the name of this software nor the names of its developers may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 4. Permission of redistribution and/or reuse of souce code partially only
 *    granted to the developer(s) in the companies ZETALOG worked.
 * 5. Any modification of this software should be published to ZETALOG unless
 *    the above copyright notice is no longer declaimed.
 *
 * THIS SOFTWARE IS PROVIDED BY THE ZETALOG AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE ZETALOG OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * @(#)mach.c: RV32M1 (VEGA) specific board initialization
 * $Id: mach.c,v 1.1 2019-08-14 16:15:00 zhenglv Exp $
 */

#include <target/irq.h>
#include <target/cpus.h>
#include <target/arch.h>
#include <target/clk.h>
#include <target/heap.h>

bool board_in_irq(void)
{
	return __raw_readl(EVENT_INTPTENACTIVE) != 0;
}

#ifdef CONFIG_REBOOT
void board_reboot(void)
{
	__raw_setl(SLPCTRL_SYSRSTREQST, EVENT_SLPCTRL);
}
#endif

#ifdef CONFIG_SUSPEND
void board_suspend(void)
{
	__raw_writel_mask(SLPCTRL_SLPCTRL(EVENT_SLP_SLEEP_ENABLE),
			  SLPCTRL_SLPCTRL(SLPCTRL_SLPCTRL_MASK),
			  EVENT_SLPCTRL);
}

void board_resume(void)
{
}
#endif

#ifdef CONFIG_HIBERNATE
void board_hibernate(void)
{
	__raw_writel_mask(SLPCTRL_SLPCTRL(EVENT_SLP_DEEP_SLEEP_ENABLE),
			  SLPCTRL_SLPCTRL(SLPCTRL_SLPCTRL_MASK),
			  EVENT_SLPCTRL);
}
#endif

void board_early_init(void)
{
	DEVICE_ARCH(DEVICE_ARCH_RISCV);
	wdog_disable();
}

void board_late_init(void)
{
}
