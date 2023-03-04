/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include <elfloader_common.h>
#include <devices_gen.h>
#include <drivers/common.h>
#include <drivers/uart.h>

#include <printf.h>
#include <types.h>

#define UTHR        0x0 // UART Transmitter Holding Register.
                        // Data is written to this register.
                        // UTHRa: 0x400 + a * 0x100 (a=1,2)

#define ULSR        0x5 // UART Line Status Register.
                        // Read-only registers that 
                        // ULSRa: 0x405 + a * 0x100 (a=1,2)

#define ULSR_THRE   BIT(5) // Transmitter Holding Register Empty
// #define ULSR_BI     BIT(4) // Break Interrupt
// #define ULSR_FE     BIT(3) // Framing Error
// #define ULSR_PE     BIT(2) // Parity Error
// #define ULSR_OE     BIT(1) // Overrun Error
#define ULSR_DR     BIT(0) // Data Ready

#define UART_REG(mmio, x) ((volatile uint32_t *)(((uintptr_t)mmio) + (x)))

static int uart_ns16550a_putchar(struct elfloader_device *dev, unsigned int c)
{
    volatile void *mmio = dev->region_bases[0];

    /* Wait until UART ready for the next character. */
    while ((*UART_REG(mmio, ULSR) & ULSR_THRE) == 0);

    /* Add character to the buffer. */
    *UART_REG(mmio, UTHR) = c;

    return 0;
}

static int uart_ns16550a_init(struct elfloader_device *dev,
                          UNUSED void *match_data)
{
    uart_set_out(dev);
    return 0;
}

static const struct dtb_match_table uart_ns16550a_matches[] = {
    { .compatible = "fsl,ns16550" },
    { .compatible = "ns16550a" },
    { .compatible = NULL /* sentinel */ },
};

static const struct elfloader_uart_ops uart_ns16550a_ops = {
    .putc = &uart_ns16550a_putchar,
};

static const struct elfloader_driver uart_ns16550a = {
    .match_table = uart_ns16550a_matches,
    .type = DRIVER_UART,
    .init = &uart_ns16550a_init,
    .ops = &uart_ns16550a_ops,
};

ELFLOADER_DRIVER(uart_ns16550a);
