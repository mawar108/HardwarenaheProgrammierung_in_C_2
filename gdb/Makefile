CFLAGS = -std=c99
DEBUGFLAGS = -g
CC = gcc

all: buggy

buggy: file1.c file2.c file3.c file1.h file2.h file3.h main.c
	$(CC) file1.c file2.c file3.c main.c -o buggy $(CFLAGS)

debug: CFLAGS += $(DEBUGFLAGS)
debug: clean all

clean:
	rm -f buggy

