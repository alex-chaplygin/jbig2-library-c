#include <stdio.h>
#include "symbol_dict.h"

int values_array[] = { 10, 2, 4, 5, 3, 7, 9, 6 }; // массив значений delta height и delta width
int height_class_change_indexes[] = { 2, 5 }; // индексы массива values_array, на которых меняется класс высот
int change_indexes_length = sizeof(height_class_change_indexes) / sizeof(int);
int current_class_index = 0;
int class_counter = 0;
int last_oob = 0;

int huff_decode(int *val, int *code_size) 
{
    *code_size = 1;
    
    if (current_class_index < change_indexes_length
        && class_counter == height_class_change_indexes[current_class_index] 
        && last_oob == 1) 
    {
        last_oob = 0;
        if (current_class_index < change_indexes_length)
            current_class_index++;
    } 
    else if (current_class_index < change_indexes_length
        && class_counter == height_class_change_indexes[current_class_index] 
        || class_counter >= sizeof(values_array) / sizeof(int)) 
    {
        *val = 0;
        last_oob = 1;
        return last_oob;
    }
    
    *val = values_array[class_counter++];
    return last_oob;
}

void huff_set_pref_table(byte *table) 
{
    return;
}

void arith_int_decode(int *v, int *s) 
{
    if (current_class_index < change_indexes_length
        && class_counter == height_class_change_indexes[current_class_index] 
        && *s == 1) 
    {
        *s = 0;
        if (current_class_index < change_indexes_length)
            current_class_index++;
    } 
    else if (current_class_index < change_indexes_length
        && class_counter == height_class_change_indexes[current_class_index] 
        || class_counter >= sizeof(values_array) / sizeof(int)) 
    {
        *v = 0;
        *s = 1;
        return;
    }    
    *v = values_array[class_counter++];
}

void bitmap_crop(bitmap_t *src, bitmap_t *dst, int start_col, int width) 
{
    dst->width = width;
    dst->height = src->height;
}

int main()
{
    int huff = 0;
    int refine_agg = 1; 
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
