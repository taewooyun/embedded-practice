#include "uart.h"

#define UART0_DR *((volatile unsigned int *)0x4000C000)
#define UART0_FR *((volatile unsigned int *)0x4000C018)

void uart_init(void) {
    // QEMU에서는 초기화 생략 가능 (기본 설정되어 있음)
}

void uart_putc(char c) {
    while (UART0_FR & (1 << 5)); // TXFF 비트 확인
    UART0_DR = c;
}

void uart_puts(const char* s) {
    while (*s) {
        uart_putc(*s++);
    }
}