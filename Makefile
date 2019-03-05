CC=clang
CFLAGS=-I. -g

all: test

clean:
	rm -f test *.o

test: test.c sort.c
	$(CC) -o test test.c sort.c $(CFLAGS)
