# Port seL4 to LS1046A platform.

Forlinx OK1046A-C2 board.

```
dts/
├── dtb
│   └── freescale	-- Compiled device tree. Copied from a compiled kernel(4.19.238).
├── dtb2dts
│   └── freescale	-- DTS dumped from DTB, using `dtbdump.py` or `dtc`.
└── dts-linux
    └── freescale	-- Device tree source. Copied from https://github.com/torvalds/linux/tree/v5.19/arch/arm64/boot/dts/freescale.
```


## seL4 kernel (`kernel/`)

Version: 12.1.0-dev

`src/plat/ls1046a/config.cmake`:

```cmake
declare_default_headers(
	TIMER_FREQUENCY xxx
	MAX_IRQ xxx
	NUM_PPI xxx
	TIMER xxx
	INTERRUPT_CONTROLLER xxx
	KERNEL_WCET xxx
	CLK_MAGIC xxx
	CLK_SHIFT xxx
)
```

### `CLK_MAGIC` & `CLK_SHIFT`

These two can be calculated with `kernel/tools/reciprocal.py`. As is shown in `fsl-ls1046a.dtsi`, section `sysclk.clock-frequency`, the clock frequency is 100MHz. So run `kernel/tools/reciprocal.py --divisor 100000000`.

`CLK_MAGIC=1441151881`, `CLK_SHIFT=57`.

### `MAX_IRQ`, `NUM_PPI`

https://developer.arm.com/documentation/ddi0471/b/Introduction

LS1046A uses a common GIC-400, which implements whe GICv2 architecture.

I search on GitHub for keyword "GIC_SPI 16x", according to DTS I found, the maximum interrupt number is 169. Temporarily let `MAX_IRQ=169`.

`NUM_PPI=32`.

