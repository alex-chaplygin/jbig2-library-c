#include "types.h" 
#include "bitmap.h"

bitmap_t *generic_decode( // возвращаемая битовая карта региона 
			 int mmr, // если 1, то кодирование MMR 
			 uint w, // ширина региона 
			 uint h, // высота региона 
			 uint template, // номер шаблона от 0 до 3 
			 int prediction, // если 1, то используется предсказание (повторение) строк 
			 int use_skip, // если 1, то используется карта пропуска бит 
			 bitmap_t *skip, // битовая карта пропуска точек, такого же размера как и регион 
			 point_t adaptive_pixels[]); // массив адаптивных шаблонных точек размером 1 или 4
