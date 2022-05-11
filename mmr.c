/**
 * @file   mmr.c
 * @author alex <alex@localhost>
 * @date   Wed May 11 09:18:12 2022
 * 
 * @brief  Модуль декодирования изображения, сжатого MMR
 * 
 */

#include "types.h"

int a0;
int a1;    
int a2;
int b1;
int b2;
byte *ref_str; // строка перед текущей строкой, относительно нее декодируется текущая строка

/** 
 * Декодирование данных mmr. 
 * 
 * Данные поступают из текущего потока.
 * 
 * @param out указатель на буфер, куда декодируется изображение
 * @param width ширина изображения
 * @param height высота изображения
 */
void mmr_decode(byte *out, int width, int height)
{
}
