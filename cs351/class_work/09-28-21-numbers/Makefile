AS=nasm -felf64
OBJS=lib.o printnum.o prime.o

prime: $(OBJS)
	ld -o prime $(OBJS)

lib.o: lib.s
	$(AS) lib.s

printnum.o: printnum.s
	$(AS) printnum.s

prime.o: prime.s
	$(AS) prime.s

clean:
	rm -f *.o prime
