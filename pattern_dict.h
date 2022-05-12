#include "bitmap.h"

bitmap_t *decode_pattern_dict(
int mmr, // 1, если используется MMR
int pattern_width, // ширина шаблона
int pattern_height, // высота шаблона
int max_num, // максимальный номер шаблона
int template // тип шаблона пикселей
			      ); // возвращает массив шаблонов размером (max_num + 1)
