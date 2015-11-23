all:	kernel.exe

kasm.o: 	kernel.asm
	nasm  -f elf32 kernel.asm -o kasm.o

kc.o: 	kernel.c keyboard_map.h
	gcc -m32 -c kernel.c -o kc.o

kernel.exe: kasm.o kc.o
	ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
	
clean:
	rm -f *.o
