CC=gcc -ggdb
AS=nasm -g -Fdwarf -felf64

rpn: crpn.o rpn.o
	gcc -o rpn rpn.o crpn.o

asmrpn: rpn.o
	gcc -o rpn rpn.o

crpn.o: crpn.c
	$(CC) -c crpn.c

rpn.o: rpn.s
	$(AS) rpn.s

clean:
	rm -r *.o rpn
