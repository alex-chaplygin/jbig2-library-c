CFLAGS=-I. -I../

all: /tmp/bits_test

/tmp/bits_test: bits_test.c ../bits.c
	gcc $(CFLAGS) -o $@ $^
