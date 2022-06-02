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

/** 
 * Чтение последовательности бит из потока
 * 
 * @param num число бит, сколько необходимо прочитать
 * 
 * @return последовательность бит
 */
int get_bits(int num)
{
    int sub_bits = 0;
    int cur_sub_bit = 0;
    
    for (int i = num - 1; i >= 0 ; i--){
        cur_sub_bit = get_bit();
        sub_bits = sub_bits + (cur_sub_bit << i);
    }
    return sub_bits;  
}

/** 
 * Перемещает указатель бит на следующий байт,
 * если указатель не находится на границе байтов
 */
void next_byte()
{
    if( bit_count != 8){
        cur_byte++;
        bit_count = 8;
    }
}

/** 
 * Меняет порядок байт в слове
 * 
 * @param val слово
 * 
 * @return слово с переставленными байтами
 */
word swap_word(word val)
{
  return (val >> 8) + ((val & 0xff) << 8);
}
