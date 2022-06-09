#include <stdio.h>
#include "symbol_dict.h"

void bitmap_crop(bitmap_t *src, bitmap_t *dst, int start_col, int width) 
{
    dst->width = width;
    dst->height = src->height;
}

int main()
{
    int huff = 1;
	int refine_agg = 0; 
	uint num_input_syms = 5; 
	bitmap_t input_syms[5]; 
	uint num_new_syms = 5; 
	uint num_export_syms = 5; 
	int height_table[] = { 0 }; 
	int width_table[] = { 0 }; 
	int size_table[10]; 
	int agg_table[10]; 
	int sym_template; 
	point_t sym_adaptive_pixels[10]; 
	int refine_template; 
	point_t refine_adaptive_pixels[10];
    
    bitmap_t *result = sym_dict_decode(
        huff,
        refine_agg,
        num_input_syms,
        input_syms,
        num_new_syms,
        num_export_syms,
        height_table,
        width_table,
        size_table,
        agg_table,
        sym_template,
        sym_adaptive_pixels,
        refine_template,
        refine_adaptive_pixels);
        
    for (int i = 0; i < num_export_syms; i++)
        printf("%d %d\n", result[i].height, result[i].width);
    
    return 0;
}
