AS=nasm -felf64
LD=ld
DEST=game
OBJS=game.o lib.o

$(DEST): $(OBJS)
	$(LD) -o $(DEST) $(OBJS)

lib.o: lib.s
	$(AS) lib.s

clean:
	rm -f *.o
