CC=gcc -ggdb

all: p1 p2 p3 p4 p5 p6

p%: p%.o
	$(CC) -o $@ $<

p%.o: p%.c
	$(CC) -c $<

clean:
	rm -f *.o p[1-6]
