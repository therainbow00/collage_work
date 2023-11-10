CC=gcc -ggdb
AS=nasm -g -Fdwarf -felf64

foo: foo.o
	gcc -o foo foo.o

foo.o: foo.s
	$(AS) foo.s

cfoo.o: cfoo.c
	$(CC) -c cfoo.c

clean:
	rm -f *.o foo
