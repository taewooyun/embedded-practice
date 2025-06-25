
#define UART0_DR (*(volatile unsigned int *)0x4000C000)
#define UART0_FR (*(volatile unsigned int *)0x4000C018)

void uart_send(char c) {
    while (UART0_FR & (1 << 5));
    UART0_DR = c;
}

void uart_print(const char *s) {
    while (*s) uart_send(*s++);
}

int main(void) {
    uart_print("UART Echo Ready\r\n");
    while (1) {
        char c = (char)(UART0_DR & 0xFF);
        uart_send(c);
    }
}
