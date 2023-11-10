CC=gcc -ggdb
AS=nasm -g -Fdwarf -felf64

pipe: cpipe.o pipe.o
	gcc -o pipe pipe.o cpipe.o

asmpipe: pipe.o
	gcc -o pipe pipe.o

cpipe.o: cpipe.c
	$(CC) -c cpipe.c

pipe.o: pipe.s
	$(AS) pipe.s

clean:
	rm -r *.o pipe
