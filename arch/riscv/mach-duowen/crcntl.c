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
 * @(#)crcntl.c: DUOWEN clock/reset controller (CRCNTL) implementation
 * $Id: crcntl.c,v 1.1 2019-11-06 10:39:00 zhenglv Exp $
 */

#include <target/clk.h>
#include <target/panic.h>

/*===========================================================================
 * DUOWEN unitified PLL (crcntl, cohfab, cluster) APIs
 *===========================================================================*/
#ifdef CONFIG_CRCNTL_UNIFIED
phys_addr_t duowen_pll_reg_base[DUOWEN_MAX_PLLS] = {
	__CRCNTL_PLL_REG(0, 0),
	__CRCNTL_PLL_REG(1, 0),
	__CRCNTL_PLL_REG(2, 0),
	__CRCNTL_PLL_REG(3, 0),
	__DUOWEN_CFAB_CLK_BASE,
	__DUOWEN_APC_CLK_BASE(0),
	__DUOWEN_APC_CLK_BASE(1),
	__DUOWEN_APC_CLK_BASE(2),
	__DUOWEN_APC_CLK_BASE(3),
};
#endif

void duowen_pll_reg_write(uint8_t pll, uint8_t reg, uint8_t val)
{
	__raw_writel(PLL_REG_WRITE | PLL_REG_SEL(reg) | PLL_REG_WDATA(val),
		     DW_PLL_REG_ACCESS(pll));
	while (!(__raw_readl(DW_PLL_REG_ACCESS(pll)) & PLL_REG_IDLE));
}

uint8_t duowen_pll_reg_read(uint8_t pll, uint8_t reg)
{
	uint32_t val;

	__raw_writel(PLL_REG_READ | PLL_REG_SEL(reg),
		     DW_PLL_REG_ACCESS(pll));
	do {
		val = __raw_readl(DW_PLL_REG_ACCESS(pll));
	} while (val & PLL_REG_IDLE);
	return PLL_REG_RDATA(val);
}

/*===========================================================================
 * CRCNTL APIs
 *===========================================================================*/
bool crcntl_clk_asserted(clk_clk_t clk)
{
	uint8_t n, bit;

	bit = clk & REG_5BIT_MASK;
	n = clk >> 5;
	return !!(__raw_readl(CRCNTL_SW_RST_CFG(n)) & _BV(bit));
}

void crcntl_clk_assert(clk_clk_t clk)
{
	uint8_t n, bit;

	if (!crcntl_clk_asserted(clk)) {
		bit = clk & REG_5BIT_MASK;
		n = clk >> 5;
		__raw_setl(_BV(bit), CRCNTL_SW_RST_CFG(n));
	}
}

void crcntl_clk_deassert(clk_clk_t clk)
{
	uint8_t n, bit;

	if (crcntl_clk_asserted(clk)) {
		bit = clk & REG_5BIT_MASK;
		n = clk >> 5;
		__raw_clearl(_BV(bit), CRCNTL_SW_RST_CFG(n));
	}
}

bool crcntl_clk_enabled(clk_clk_t clk)
{
	uint8_t n, bit;

	bit = clk & REG_5BIT_MASK;
	n = clk >> 5;
	return !!(__raw_readl(CRCNTL_CLK_EN_CFG(n)) & _BV(bit));
}

void crcntl_clk_enable(clk_clk_t clk)
{
	uint8_t n, bit;

	if (!crcntl_clk_enabled(clk)) {
		bit = clk & REG_5BIT_MASK;
		n = clk >> 5;
		__raw_setl(_BV(bit), CRCNTL_CLK_EN_CFG(n));
	}
}

void crcntl_clk_disable(clk_clk_t clk)
{
	uint8_t n, bit;

	if (crcntl_clk_enabled(clk)) {
		bit = clk & REG_5BIT_MASK;
		n = clk >> 5;
		__raw_clearl(_BV(bit), CRCNTL_CLK_EN_CFG(n));
	}
}

bool crcntl_clk_selected(clk_clk_t clk)
{
	return !(__raw_readl(CRCNTL_CLK_SEL_CFG) & _BV(clk));
}

void crcntl_clk_select(clk_clk_t clk)
{
	if (!crcntl_clk_selected(clk))
		__raw_clearl(_BV(clk), CRCNTL_CLK_SEL_CFG);
}

void crcntl_clk_deselect(clk_clk_t clk)
{
	if (crcntl_clk_selected(clk))
		__raw_setl(_BV(clk), CRCNTL_CLK_SEL_CFG);
}

#ifdef CONFIG_CRCNTL_TRACE
bool crcntl_tracing;

void crcntl_trace_enable(void)
{
	crcntl_tracing = true;
}

void crcntl_trace_disable(void)
{
	crcntl_tracing = false;
}

void cncntl_trace(bool enabling, const char *name)
{
	if (crcntl_tracing)
		printf("%c %s\n", enabling ? 'E' : 'D', name);
}
#endif

#ifdef CONFIG_MMU
void clk_hw_mmu_init(void)
{
	duowen_mmu_map_clk();
}
#endif
