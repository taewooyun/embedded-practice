
.section .isr_vector, "a", %progbits
.global __vectors
__vectors:
    .word _estack
    .word Reset_Handler
    .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.section .text.Reset_Handler
.global Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    bl main
    b .
