
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m3 -mthumb -nostdlib -Wall
LDFLAGS=-T linker.ld

all: main.elf

main.elf: startup.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.s
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.elf
