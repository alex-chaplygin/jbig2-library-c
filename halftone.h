#include "types.h"

bitmap_t* decode_halftone( // возвращает битовую карту региона
	uint w, // ширина региона
	uint h, // высота региона
	int mmr, // если 1, то используется mmr
	int template, // номер шаблона
	int num_patterns, // число шаблонов региона
	bitmap_t* patterns, // массив шаблонов
	int def_pixel, // точка по умолчанию
	int operator, // оператор комбинации OR, AND, XOR, XNOR, REPLACE
	int skip, // если 1, то серые значения пропускаются
	uint gray_width, // ширина полутонового изображения
	uint gray_height, // высота полутонового изображения
	int grid_x, // смещение начала координат сетки ( * 256)
	int grid_y,
	word rx, // вектор сетки ( * 256)
	word ry,
	byte cell_width, // ширина ячейки
	byte cell_height // высота ячейки
			   ); 
