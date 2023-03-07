# Port seL4 to LS1046A platform.

Forlinx OK1046A-C2 board with FET1046A-C core platform.

## DTS & DTB files

```
├── apps
│   └── hello
├── build
│   ├── apps
│   └── CMakeFiles
├── diffs	-- Patches from the original commits
├── dts
│   ├── dtb
│   │   └── freescale	-- Compiled device tree. Copied from a compiled kernel(4.19.238).
│   ├── dtb2dts
│   │   └── freescale	-- DTS dumped from DTB, using `dtbdump.py` or `dtc`.
│   └── dts-linux
│	    └── freescale	-- Device tree source.
│				   Copied from https://github.com/torvalds/linux/tree/v5.19/arch/arm64/boot/dts/freescale.
├── kernel
│   ├── configs
│   ├── include
│   ├── libsel4
│   ├── LICENSES
│   ├── manual
│   ├── src
│   └── tools
├── projects
│   ├── capdl
│   ├── musllibc
│   ├── seL4_libs
│   ├── seL4_projects_libs
│   ├── sel4runtime
│   ├── sel4-tutorials
│   └── util_libs
├── scripts
└── tools
    └── seL4
dts/
├── dtb
│   └── freescale	-- Compiled device tree. Copied from a compiled kernel(4.19.238).
├── dtb2dts
│   └── freescale	-- DTS dumped from DTB, using `dtbdump.py` or `dtc`.
└── dts-linux
    └── freescale	-- Device tree source.
					   Copied from https://github.com/torvalds/linux/tree/v5.19/arch/arm64/boot/dts/freescale.
```


## seL4 kernel (`kernel/`)

URL: https://github.com/seL4/seL4

Version: 12.1.0-dev.

Commit: dd41d4de63949e689e54844089f851425e2ab748

### `tools/dts/ok1046a-c2.dts`

Copied from `dts/dtb2dts/freescale/fsl-ok1046a-1133-5a59-c2.dts`.

### `src/plat/ls1046a/`

`config.cmake`:

```cmake
declare_platform(ls1046a KernelPlatformOK1046AC2 PLAT_LS1046A KernelArchARM)

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

## seL4 tools

URL: https://github.com/seL4/seL4_tools

Commit: 074a54aedcef97bfcc4ea0724a4c5d75fa311b3e

