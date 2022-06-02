#include <stdio.h>
#include "types.h"
#include "bits.h"
#include "test.h"

byte byte_stream[3] = {0x2F, 0x05, 0xC1};

void test_get_bit(){

    int res[] = {0,   0, 1,   0, 1, 1,   1, 1, 0, 0,   0, 0, 0, 1, 0,   1, 1, 1, 0, 0, 0,    0, 0, 1};

    set_bit_stream(byte_stream, sizeof(byte_stream));
   
    for(int i=0; i < sizeof(res) / sizeof(int); i++) {
        int gb = get_bit();
        ASSERT(gb, res[i]);
    }
    ASSERT(get_bit(), -1); 
}

void test_get_bits()
{
    struct bits{
        int num;
        int res;
    } res_bits[]= { {1,0}, {2,1}, {3,3}, {4,12}, {5,2}, {6, 8 + 16 + 32}, {3,1}, {1, -1} };
        
   set_bit_stream(byte_stream, sizeof(byte_stream));
   
    for(int i = 0; i < sizeof(res_bits) / sizeof(struct bits); i++) {
        int gbs = get_bits(res_bits[i].num);
        ASSERT(gbs, res_bits[i].res);
    }
    ASSERT(get_bits(1), -1); 
}

void test_next_byte()
{
    set_bit_stream(byte_stream, sizeof(byte_stream));
    get_bits(8);
    next_byte();
    int bits = get_bits(4);
    ASSERT(bits, 0)
    next_byte();
    bits = get_bits(4);
    ASSERT(bits, 0xC);
}

void test_swap_word()
{
    word w = swap_word(0xaabb);
    ASSERT(w, 0xbbaa);
}

int main()
{
    test_get_bit();
    test_get_bits();
    test_next_byte();
    test_swap_word();
    return 0;
}
