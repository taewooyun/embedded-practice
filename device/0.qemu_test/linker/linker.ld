ENTRY(Reset_Handler)

SECTIONS {
    . = 0x00000000;
    .text : {
        *(.isr_vector)
        *(.text*)
        *(.rodata*)
    }

    . = 0x20000000;
    .data : { *(.data*) }
    .bss : { *(.bss*) }
}