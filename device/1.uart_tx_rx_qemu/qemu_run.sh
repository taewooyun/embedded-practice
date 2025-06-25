
#!/bin/bash
qemu-system-arm -M lm3s6965evb -nographic -serial mon:stdio -kernel main.elf
