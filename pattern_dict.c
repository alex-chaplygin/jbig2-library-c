#include <stdlib.h>
#include "bitmap.h"

bitmap_t *decode_pattern_dict(
int mmr, // 1, если используется MMR
int pattern_width, // ширина шаблона
int pattern_height, // высота шаблона
int max_num, // максимальный номер шаблона
int template // тип шаблона пикселей
) // возвращает массив шаблонов размером (max_num + 1)
{
    point_t adaptive_pixels[] = {{-pattern_width, 0}, {-3, -1}, {2, -2}, {-2, -2}};
        
    bitmap_t *b;
    bitmap_t *dict;
    b = generic_decode(mmr, pattern_width * (max_num + 1), pattern_height, template, 0, 0, 0, adaptive_pixels);
    
    return dict;
}
