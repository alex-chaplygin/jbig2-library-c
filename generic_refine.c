#include "generic_refine.h"
#include "arith.h"

int num_bits_values[2] = { 13, 10 };

int decode_refine_prediction(int ltp, int template)
{
  int context;
  if (template) context = 8; else context = 16;
  ltp = ltp ^ arith_decode(context, PROC_GR, num_bits_values[template]);
  return ltp;
}

word get_refine_context(bitmap_t* region, bitmap_t* ref, int x, int y, point_t* offset, int template, point_t* ap) 
{
  return 0;
}

int equal_pixels(bitmap_t* ref, int x, int y, int template) 
{
	return 1;
}

/** 
 * Декодирование обновленного общего региона
 *
 * Алгоритм:
 * 
 *     1. Создать битовую карту (new_bitmap)
 *     2. Для каждой строки:
 *     2.1. если предсказание включено, то декодируется бит предсказания (ltp = decode_refine_prediction)
 *     2.2. если ltp = 0, то декодируются все точки ряда
 *     2.2.1 чтение шаблона get_refine_context
 *     2.2.2 декодируем точку arith_decode
 *     2.3 если ltp = 1 то для каждой точки из строки
 *     2.3.1 если prediction = 1 и шаблон точек (3, 3) в ref содержит все одинаковые точки, то значение из ref записывается в region
 *     2.3.2 иначе декодируется значение как в 2.2.1 и 2.2.2
 * 
 * @param w ширина региона
 * @param h высота региона
 * @param template  номер шаблона 0 или 1
 * @param ref битовая карта которая обновляется
 * @param offset смещение относительно исходной карты
 * @param prediction если 1, то есть предсказание
 * @param adaptive_pixels // массив адаптивных шаблонных точек
 * 
 * @return возвращает битовую карту общего обновленного региона
 */
bitmap_t *generic_refine_decode( 
				uint w, 
				uint h, 
				uint template,
				bitmap_t *ref, 
				point_t *offset, 
				int prediction, 
				point_t adaptive_pixels[])
{
        uint ltp = 0;
	bitmap_t* b = new_bitmap(w, h);
	byte* p = b->data;

	for (int i = 0; i < h; i++)
	{
		if (prediction) //предсказание включено
			ltp = decode_refine_prediction(ltp, template); //декодируется бит предсказания
						
		//декодируются все точки ряда
		for (int j = 0; j < w; j++)
			if(ltp && prediction && equal_pixels(ref, j, i, template))
			{
				*p++ = get_pixel(ref, j + offset->x, i + offset->y);
			}
			else 
			{
				word context = get_refine_context(b, ref, j, i, offset, template, adaptive_pixels);
				*p++ = arith_decode(context, PROC_GR, num_bits_values[template]);
			}
	}
	return ref;
}
