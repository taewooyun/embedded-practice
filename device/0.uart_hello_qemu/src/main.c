#include "uart.h"

int main(void) {
    uart_init();
    uart_puts("Hello from QEMU UART!\n");

    while (1);
    return 0;
}