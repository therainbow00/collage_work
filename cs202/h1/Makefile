CC := gcc
CFLAGS := -Wall
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

all: $(OBJS)

%.o: %.c
	-$(CC) $(CFLAGS) $< -o $@
