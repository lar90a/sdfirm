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
 * @(#)reg.h: DUOWEN space and register definitions
 * $Id: reg.h,v 1.1 2019-09-02 11:12:00 zhenglv Exp $
 */

#ifndef __REG_DUOWEN_H_INCLUDE__
#define __REG_DUOWEN_H_INCLUDE__

/* System fabric */
#define CRCNTL_BASE		ULL(0xFF60000000)
#define SCSR_BASE		ULL(0xFF60100000)
#define TLMM_BASE		ULL(0xFF60200000)
#define DEBUG_BASE		ULL(0xFF60300000)
#define SFAB_RAM_BASE		ULL(0xFF60400000) /* Sys Mem */
#define SFAB_RAM_SIZE		0x200000
#define IMC_BASE		ULL(0xFF60600000)
#define GPIO0_BASE		ULL(0xFF61000000)
#define GPIO1_BASE		ULL(0xFF61100000)
#define GPIO2_BASE		ULL(0xFF61200000)
#define SPI0_BASE		ULL(0xFF62000000)
#define SPI1_BASE		ULL(0xFF62100000)
#define SPI2_BASE		ULL(0xFF62200000)
#define SPI3_BASE		ULL(0xFF62300000)
#define SPISLV_BASE		ULL(0xFF62400000)
#define UART0_BASE		ULL(0xFF63000000)
#define UART1_BASE		ULL(0xFF63100000)
#define UART2_BASE		ULL(0xFF63200000)
#define UART3_BASE		ULL(0xFF63300000)
#define I2C0_BASE		ULL(0xFF64000000)
#define I2C1_BASE		ULL(0xFF64100000)
#define I2C2_BASE		ULL(0xFF64200000)
#define I2C3_BASE		ULL(0xFF64300000)
#define I2C4_BASE		ULL(0xFF64400000)
#define I2C5_BASE		ULL(0xFF64500000)
#define I2C6_BASE		ULL(0xFF64600000)
#define I2C7_BASE		ULL(0xFF64700000)
#define I2CSLV0_BASE		ULL(0xFF64800000)
#define I2CSLV1_BASE		ULL(0xFF64900000)
#define I2CSLV2_BASE		ULL(0xFF64A00000)
#define I2CSLV3_BASE		ULL(0xFF64B00000)
#define WDT0_BASE		ULL(0xFF65000000)
#define WDT1_BASE		ULL(0xFF65100000)
#define TIMER0_BASE		ULL(0xFF66000000)
#define TIMER1_BASE		ULL(0xFF66100000)
#define TIMER2_BASE		ULL(0xFF66200000)
#define TIMER3_BASE		ULL(0xFF66300000)
#define SD_BASE			ULL(0xFF67000000)
#define FLASH_BASE		ULL(0xFF68000000)
#define PLIC_BASE		ULL(0xFF70000000)
#define SFAB_ROM_BASE		ULL(0xFF7FF00000) /* Boot ROM */
#define SFAB_ROM_SIZE		0x100000

/* Config fabric */
#define CLUSTER0_BASE		ULL(0xFF01000000)
#define CLUSTER1_BASE		ULL(0xFF01100000)
#define CLUSTER2_BASE		ULL(0xFF01200000)
#define CLUSTER3_BASE		ULL(0xFF01300000)
#define COHFAB_BASE		ULL(0xFF02000000)
#define COHFAB_PLL_BASE		ULL(0xFF02100000)
#define DMA_BASE		ULL(0xFF03000000)
#define DDR0_CTRL_BASE		ULL(0xFF04000000)
#define DDR0_PHY_BASE		ULL(0xFF05000000)
#define DDR1_CTRL_BASE		ULL(0xFF06000000)
#define DDR1_PHY_BASE		ULL(0xFF07000000)
#define DMA_SMMU_BASE		ULL(0xFF08000000)
#define PCIE_SMMU_BASE		ULL(0xFF08400000)
#define PCIE_SUB_CUST_BASE	ULL(0xFF09000000)
#define PCIE0_CUST_BASE		ULL(0xFF09001000)
#define PCIE1_CUST_BASE		ULL(0xFF09002000)
#define PCIE2_CUST_BASE		ULL(0xFF09003000)
#define PCIE3_CUST_BASE		ULL(0xFF09004000)
#define PCIE0_CTRL_BASE		ULL(0xFF09100000)
#define PCIE0_PHY_BASE		ULL(0xFF09180000)
#define PCIE1_CTRL_BASE		ULL(0xFF09200000)
#define PCIE1_PHY_BASE		ULL(0xFF09280000)
#define PCIE2_CTRL_BASE		ULL(0xFF09300000)
#define PCIE2_PHY_BASE		ULL(0xFF09380000)
#define PCIE3_CTRL_BASE		ULL(0xFF09400000)
#define PCIE3_PHY_BASE		ULL(0xFF09480000)
#define TSENSOR_BASE		ULL(0xFF0A000000)

#define MSG_BASE		ULL(0xFF601FFF00)

#define DEV_BASE		ULL(0xFF00000000)
#define DEV_SIZE		ULL(0x0080000000)

#ifdef CONFIG_DUOWEN_IMC
#define IMC_ROM_BASE		SFAB_ROM_BASE
#define IMC_ROM_SIZE		0xE0000
#define IMC_RAM_BASE		SFAB_RAM_BASE
#define IMC_RAM_SIZE		SFAB_RAM_SIZE
#endif /* CONFIG_DUOWEN_IMC */

/* DDR memory region */
#define DDR_BASE		ULL(0x0000000000)
#ifdef CONFIG_DUOWEN_ASIC
#define DDR_SIZE		SZ_512G
#endif
#ifdef CONFIG_DUOWEN_FPGA
#ifdef CONFIG_DUOWEN_FPGA_DDR_MODEL
#define DDR_SIZE		SZ_32M
#else
#define DDR_SIZE		SZ_16G
#endif

/* PCIe memory region */
#define PCIE_BASE		ULL(0x40000000000)
#define PCIE_SIZE		SZ_2T

#define APC_ROM_BASE		(SFAB_ROM_BASE + 0xE0000)
#define APC_ROM_SIZE		0x20000
#define APC_RAM_BASE		SFAB_RAM_BASE
#define APC_RAM_SIZE		SFAB_RAM_SIZE
#endif /* CONFIG_DUOWEN_APC */

#ifdef CONFIG_DUOWEN_ZSBL
#ifdef CONFIG_DUOWEN_BOOT_APC
#define ROM_BASE		APC_ROM_BASE
#define ROMEND			(APC_ROM_BASE + APC_ROM_SIZE)
#else /* CONFIG_DUOWEN_BOOT_APC */
#define ROM_BASE		IMC_ROM_BASE
#define ROMEND			(IMC_ROM_BASE + IMC_ROM_SIZE)
#endif /* CONFIG_DUOWEN_BOOT_APC */
#endif /* CONFIG_DUOWEN_ZSBL */

#ifdef CONFIG_DUOWEN_FSBL
#ifdef CONFIG_DUOWEN_BOOT_APC
#define ROM_BASE		APC_RAM_BASE
#define ROMEND			(APC_RAM_BASE + APC_RAM_SIZE)
#else /* CONFIG_DUOWEN_BOOT_APC */
#define ROM_BASE		IMC_RAM_BASE
#define ROMEND			(IMC_RAM_BASE + IMC_RAM_SIZE)
#endif /* CONFIG_DUOWEN_BOOT_APC */
#endif /* CONFIG_DUOWEN_FSBL */

#ifdef CONFIG_DUOWEN_BOOT_APC
#define RAM_BASE		APC_RAM_BASE
#define RAM_SIZE		APC_RAM_SIZE
#else /* CONFIG_DUOWEN_BOOT_APC */
#ifdef CONFIG_DUOWEN_APC
#define RAM_BASE		DDR_BASE
#define RAM_SIZE		DDR_SIZE
#else
#define RAM_BASE		IMC_RAM_BASE
#define RAM_SIZE		IMC_RAM_SIZE
#endif
#endif /* CONFIG_DUOWEN_BOOT_APC */
#define RAMEND			(RAM_BASE + RAM_SIZE)

#endif /* __REG_DUOWEN_H_INCLUDE__ */
