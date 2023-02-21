## Port seL4 to LS1046A platform.

`dts/freescale/`: Device tree source. From https://github.com/torvalds/linux/tree/v5.19/arch/arm64/boot/dts/freescale.

### `CLK_MAGIC` & `CLK_SHIFT`

These two can be calculated with `kernel/tools/reciprocal.py`. As is shown in `fsl-ls1046a.dtsi`, the clock frequency is 100000000 Hz. So run `kernel/tools/reciprocal.py --divisor 100000000`.

CLK_MAGIC = 1441151881, CLK_SHIFT=57

