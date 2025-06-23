CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -nostdlib -nostartfiles -Wall -g
LDFLAGS = -T linker/linker.ld

SRC = src/main.c src/uart.c src/startup.s
OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.s=.o)
OBJ := $(notdir $(OBJ))

BUILD = build
TARGET = $(BUILD)/cm3.elf

all: $(TARGET)

$(TARGET): $(addprefix $(BUILD)/,$(OBJ))
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(BUILD)/%.o: src/%.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(BUILD)/%.o: src/%.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD)/*.o $(TARGE