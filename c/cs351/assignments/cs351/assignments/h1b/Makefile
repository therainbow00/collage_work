CC=gcc

PROGS=p6 p7 p8

# Linux defaults:
CFLAGS=-ggdb -pedantic -Wall
#CFLAGS=-O4 -Wall
LDFLAGS=-lm

all:	$(PROGS)

p6:	p6.o
p7:	p7.o
p8:	p8.o
	$(CC) $(LDFLAGS) -o $@ $<

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:	objclean
	for b in $(PROGS); do if [ -f "$$b" ]; then rm "$$b"; fi done

objclean:
	for obj in p?.o; do if [ -f "$$obj" ]; then rm "$$obj"; fi done
