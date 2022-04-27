/**
 * @file   generic.c
 * @author alex <alex@localhost>
 * @date   Wed Apr 27 07:09:01 2022
 * 
 * @brief  Общий регион
 * 
 */

#include"generic.h"


/** Алгоритм (mmr = 0):
* 1. Создать битовую карту (new_bitmap)
* 2. Для каждой строки:
*   2.1. если предсказание включено, то декодируется бит предсказания (ltp = decode_prediction)
*   2.2. если ltp = 1, то текущая строка равна предыдущей
* 3. Для всех точек в ряде
*   3.1. если пропуск точки(1 в маске), то точка устанавливается в 0
*   3.2. иначе чтение шаблона get_context
*   3.3. декодируем точку arith_decode
* 
* bitmap_t *generic_decode // возвращаемая битовая карта региона
* int mmr, // если 1, то кодирование MMR
* uint w, // ширина региона
* uint h, // высота региона
* uint template, // номер шаблона от 0 до 3
* int prediction, // если 1, то используется предсказание (повторение) строк
* int use_skip, // если 1, то используется карта пропуска бит
* bitmap_t skip, // битовая карта пропуска точек, такого же размера как и регион
* point_t adaptive_pixels // массив адаптивных шаблонных точек размером 1 или 4 (координаты относительные)
*/
bitmap_t *generic_decode(
			 int mmr,
			 uint w,
			 uint h,
			 uint template,
			 int prediction,
			 int use_skip,
			 bitmap_t *skip,
			 point_t adaptive_pixels[])
{
  bitmap_t* b = new_bitmap(w, h);
  for (uint i = 0; i < h; i++) 
    {
      if (prediction == 1) 
	{
	  ltp = decode_prediction(,); //декодируется бит предсказания
	}
    }
}
