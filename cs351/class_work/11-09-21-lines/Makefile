CC=gcc -ggdb
LIBS=-lm -lcursesw

ship: main.o point.o path.o
	$(CC) -o ship main.o point.o path.o $(LIBS)

main.o: main.c point.h
	$(CC) -c main.c $(LIBS)

point.o: point.c point.h
	$(CC) -c point.c $(LIBS)

path.o: path.c point.h
	$(CC) -c path.c $(LIBS)
