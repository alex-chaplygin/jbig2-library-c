/**
 * @file   bits.c
 * @author alex <alex@localhost>
 * @date   Thu May  5 06:37:05 2022
 * 
 * @brief  Чтение бит из потока, конвертация данных
 * 
 */
#include "types.h"

byte *bit_stream; // поток бит
int bit_stream_size; // размер потока
byte *cur_byte; // указатель на текущий байт в потоке
int bit_count; // счетчик бит

/** 
 * Устанавливает битовый поток. Инициализирует чтение бит.
 * 
 * @param bs указатель на поток байт
 * @param size размер потока в байтах
 */
void set_bit_stream(byte *bs, int size)
{    
    bit_stream_size = size;
    bit_stream = bs;
    cur_byte = bit_stream;  
    bit_count = 8;
}

/** 
 * Чтение очередного бита из потока
 * 
 * @return значение бита или -1, когда поток закончился
 */
int get_bit()
{
    int res_bit;

    if(cur_byte - bit_stream >= bit_stream_size)
      return -1;
    bit_count--;
    res_bit = 1 & (*cur_byte >> bit_count);
    if(bit_count == 0){
      cur_byte++;
      bit_count = 8;
    }    
    return res_bit;
}
