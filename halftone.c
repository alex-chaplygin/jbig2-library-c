#include <stdio.h>
#include <strings.h>
#include "bitmap.h"
#include "types.h"

uint num_bits; // число бит для значения в сетке
byte* gray; // серое изображение

void halftone_compute_skip(bitmap_t* skipbm, uint gray_width, uint gray_height, point_t* origin, point_t* vec)
{
	int x;
	int y;
	for (int j = 0; j< gray_height;j++)
	{
		for (int i = 0; i < gray_width; i++)
		{
			 x = (origin->x + j * vec->y + i * vec->x) >> 8;
			 y = (origin->y + j * vec->x + i * vec->y) >> 8;
			 if ((x + pattern_w <= 0)||(x >= region_width)||(y + pat_h <= 0)||(y >= region_height))
			 {
				

			 }
		}

	}


}
 
int get_num_bits(int n)
{
    return 8;
}

byte* decode_gray(int w, int h)
{
    
    
}

void halftone_draw_grid()
{
    
    
}

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
) 
{
	point_t orig = {grid_x, grid_y};
	point_t vec = {rx, ry};
	bitmap_t* bt = new_bitmap(w,h);
	bitmap_t* pat = new_bitmap(cell_width, cell_height);
	memset(bt->data, def_pix, w * h);
	if (skip == 1)	
		halftone_compute_skip(bt, gray_width, gray_height, &orig, &vec);
    
    num_bits = get_num_bits(num_patterns);
    gray = decode_gray(w, h);
    for(int i = 0; i < gray_height / cell_height;i++)
    {
        for(int j = 0; i < gray_width / cell_width; j++)
        {
            
            
        }
    }

}
