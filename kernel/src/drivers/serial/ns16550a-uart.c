/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <config.h>
#include <stdint.h>
#include <util.h>
#include <machine/io.h>
#include <plat/machine/devices_gen.h>

#define UTHR        0x400 // UART Transmitter Holding Register.
                          // Data is written to this register.
                          // UTHRa: 0x400 + a * 0x100 (a=1,2)

#define ULSR        0x405 // UART Line Status Register.
                          // Read-only registers that 
                          // ULSRa: 0x405 + a * 0x100 (a=1,2)

#define ULSR_THRE   BIT(5) // Transmitter Holding Register Empty
// Unused:
// #define ULSR_BI     BIT(4) // Break Interrupt
// #define ULSR_FE     BIT(3) // Framing Error
// #define ULSR_PE     BIT(2) // Parity Error
// #define ULSR_OE     BIT(1) // Overrun Error
#define ULSR_DR     BIT(0) // Data Ready

// UART_PPTR: UART physical base address, defined in `tools/hardware.yml`
#define UART_REG(x) ((volatile uint32_t *)(UART_PPTR + (x)))

#ifdef CONFIG_PRINTING
void uart_drv_putchar(unsigned char c)
{
    while ((*UART_REG(ULSR) & ULSR_THRE) == 0);

    *UART_REG(UTHR) = c;
}
#endif /* CONFIG_PRINTING */

#ifdef CONFIG_DEBUG_BUILD
unsigned char uart_drv_getchar(void)
{
    while ((*UART_REG(ULSR) & ULSR_DR) == 0);

    return *UART_REG(UTHR);
}
#endif /* CONFIG_DEBUG_BUILD */