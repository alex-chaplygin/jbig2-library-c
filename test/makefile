CFLAGS=-I. -I../

all: /tmp/bits_test /tmp/sdict_test

/tmp/bits_test: bits_test.c ../bits.c
	gcc $(CFLAGS) -o $@ $^

/tmp/sdict_test: test_symbol_dict.c ../symbol_dict.c
	gcc $(CFLAGS) -o $@ $^
