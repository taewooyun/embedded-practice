.section .isr_vector, "a", %progbits
.word   0x20001000       // 초기 스택 포인터
.word   Reset_Handler    // 초기 PC

.text
.global Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    bl main
loop: b loop