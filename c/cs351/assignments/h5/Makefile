AS=nasm -g F dwarf -felf64
LD=ld
CC=gcc

all: h5

h5: h5.o lib.o
	$(LD) -o h5 h5.o lib.o

h5.o: h5.s
	$(AS) h5.s

lib.o:	lib.s lib.h
	$(AS) lib.s

p:
	$(CC) -o p p.c

clean:
	rm -f *.o h5 p
