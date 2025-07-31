# aiOS Makefile

all: build/aios.img

build/aios.img: boot/boot.asm kernel/kernel_entry.asm kernel/kernel.c
	mkdir -p build
	nasm -f bin boot/boot.asm -o build/boot.bin
	nasm -f elf32 kernel/kernel_entry.asm -o build/kernel_entry.o
	gcc -ffreestanding -m32 -fno-pic -fno-pie -nostdlib -nodefaultlibs -c kernel/kernel.c -o build/kernel.o
	ld -m elf_i386 -Ttext 0x1000 --oformat binary build/kernel_entry.o build/kernel.o -o build/kernel.bin
	cat build/boot.bin build/kernel.bin > build/aios.img

run: build/aios.img
	qemu-system-x86_64 -drive format=raw,file=build/aios.img

clean:
	rm -rf build
