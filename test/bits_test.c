#include <stdio.h>
#include "types.h"
#include "bits.h"

int main()
{
    byte byte_stream[3] = {0x2F, 0x05, 0xC1};
    int res[] = {0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1};

    set_bit_stream(byte_stream, sizeof(byte_stream));
    
    for(int i=0; i < sizeof(res) / sizeof(int); i++){
      int gb = get_bit();
      if(gb == res[i])
	printf("i = %d %d OK\n", i, gb);
      else
	printf("i = %d %d != %d fail\n", i, gb, res[i]);
    }
    printf("%d\n",get_bit()) ; 
    
    return 0;
}
