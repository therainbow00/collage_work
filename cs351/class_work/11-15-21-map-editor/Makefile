CC=gcc -ggdb
LIBS=-lm -lcursesw
OBJS=editor.o util.o io.o

editor: $(OBJS)
	$(CC) -o editor $(OBJS) $(LIBS)

editor.o: editor.c editor.h
	$(CC) -c editor.c $(LIBS)

util.o: util.c editor.h
	$(CC) -c util.c $(LIBS)

io.o: io.c editor.h
	$(CC) -c io.c $(LIBS)

clean:
	rm -f *.o editor
