AS=nasm -g -Fdwarf -felf64
LD=ld

all: p1 p2 p3 p4 p5 p6

p%: p%.o lib.o
	$(LD) -o $@ $< lib.o

p%.o: p%.s lib.h
	$(AS) $<

lib.o: lib.s lib.h
	$(AS) lib.s

clean:
	rm -f *.o p[1-6]
