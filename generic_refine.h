#pragma once

#include "types.h"
#include "bitmap.h"

bitmap_t *generic_refine_decode( // возвращает битовую карту региона
				uint w, // ширина региона
				uint h, // высота региона
				uint template, // номер шаблона 0 или 1
				bitmap_t *ref, // битовая карта которая обновляется
				point_t *offset, // смещение относительно исходной карты
				int prediction, // если 1, то есть предсказание
				point_t adaptive_pixels[] // массив адаптивных шаблонных точек размером 1 или 2
);
