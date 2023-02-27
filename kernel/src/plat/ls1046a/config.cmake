cmake_minimum_required(VERSION 3.7.2)

declare_platform(ls1046a KernelPlatformOK1046AC2 PLAT_LS1046A KernelArchARM)

if(KernelPlatformOK1046AC2)
    if("${KernelSel4Arch}" STREQUAL aarch64)
        declare_seL4_arch(aarch64)
    else()
        # set aarch64 as default for LS1046A
        fallback_declare_seL4_arch_default(aarch64)
    endif()
    set(KernelArmCortexA72 ON)
    set(KernelArchArmV8a ON)
    config_set(KernelARMPlatform ARM_PLAT ls1046a)
    set(KernelArmMachFeatureModifiers "+crc" CACHE INTERNAL "")
    list(APPEND KernelDTSList "tools/dts/ok1046a-c2.dts")
    list(APPEND KernelDTSList "src/plat/ls1046a/overlay-ls1046a.dts")

    declare_default_headers(
        TIMER_FREQUENCY 100000000
        MAX_IRQ 232
        NUM_PPI 32
        TIMER drivers/timer/arm_generic.h
        INTERRUPT_CONTROLLER arch/machine/gic_v2.h
        KERNEL_WCET 10u
        CLK_MAGIC 1441151881llu
        CLK_SHIFT 57u
    )
endif()

add_sources(
    DEP "KernelPlatformOK1046AC2"
    CFILES src/arch/arm/machine/gic_v2.c src/arch/arm/machine/l2c_nop.c
)