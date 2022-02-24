CC=gcc
objs=main.o expr.o lex.o

expr: $(objs)
	$(CC) -o expr $(objs)

main.o: main.c expr.h
	$(CC) -c main.c

expr.o: expr.c expr.h
	$(CC) -c expr.c

lex.o: lex.c expr.h
	$(CC) -c lex.c

clean:
	rm -f expr *.o
