CC = gcc -ggdb

all: copy remove_directory list_subfolders

copy: copy.o
	$(CC) -o copy copy.o

copy.o: copy.c
	$(CC) -c copy.c

remove_directory: remove_directory.o
	$(CC) -o remove_directory remove_directory.o

remove_directory.o: remove_directory.c
	$(CC) -c remove_directory.c

list_subfolders: list_subfolders.o
	$(CC) -o list_subfolders list_subfolders.o

list_subfolders.o: list_subfolders.c
	$(CC) -c list_subfolders.c
