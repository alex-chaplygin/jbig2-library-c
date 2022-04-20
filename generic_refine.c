#include "generic_refine.h"
#include "arith.h"

int decode_refine_prediction(int ltp, int template)
{
}

word get_refine_context(bitmap_t* region, bitmap_t* ref, int x, int y, point_t* offset, int template, point_t* ap) 
{
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
	for (uint i = 0; i < h; i++) 
	{
		if (prediction) 
		{
		  ltp = decode_refine_prediction(ltp, template); //декодируется бит предсказания
			if (ltp == 0)
			{
			  //декодируются все точки ряда
				for (int j = 0; j < w; j++) 
				{
					get_refine_context(b, ref, j, i, offset, template, ap);

				}
				//декодируем точку arith_decode
			}
			if (ltp) 
			{	//для каждой точки из строки
				for (uint j = 0; j < w; j++) 
				{
					if (prediction) 
					{

					}
				}
			}
		}
	}

}
