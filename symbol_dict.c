/**
 * @file   symbol_dict.c
 * @author alex <alex@localhost>
 * @date   Mon Apr 18 07:21:27 2022
 * 
 * @brief  Декодирование словаря символов
 * 
 * Класс символов - символы одной высоты. Классы обычно располагаются в порядке возрастания высоты.
 * 
 * Структура словаря:
 * 1-й класс символов
 * 2-й класс символов
 * ...
 * Последний класс символов
 * Список экспортируемых символов
 * 
 * Структура класса:
 * delta_height
 * delta_width 1-го символа
 * битовая карта 1-го символа (если huff = 0 и refine_agg = 1)
 * delta_width 2-го символа
 * битовая карта 2-го символа (если huff = 0 и refine_agg = 1)
 * OOB
 * Коллективная битовая карта (если huff = 1 и refine_agg = 0)
 */

#include "symbol_dict.h"

bitmap_t *new_syms;  /**< массив симовлов в этом словаре */
uint class_height; /**< высота текущего класса высот (начинается с 0) */
int height_delta; /**< разница между высотами в классе */
uint cur_width; /**< ширина текущего символа */
uint cur_class_width; /**< ширина текущего класса высот */
int width_delta; /**< разница в ширине между двумя символами */
bitmap_t *current_symbol; /**< битовая карта текущего символа */
bitmap_t *class_bitmap; /**< общая битовая карта символов одного класса высот */
byte *export_flags; /**< массив флагов словаря (число символов - исходные + новые) по 1 биту */
uint run_length; /**< длина серии одинаковых флагов */
int oob; /**< если 1, то конец данных */

/** 
 * Декодирует значение
 * 
 * @param huff если 1, то декодируем значение используя таблицу Хаффмана (huff_set_table, huff_decode)
 * @param huff_table таблица для декодирования
 * 
 * @return декодированное значение
 */
int sym_dict_decode_val(int huff, byte *huff_table)
{
    return 1;
}

bitmap_t *sym_dict_decode_symbol(int refine_agg, int width, int height, int template, point_t *adaptive_points);
{
    
}

void export_symbols(bitmap_t *input, int num_input, bitmap_t *output, int num_output)
{
    for (int i = 0; i < num_output; i++)
        output[i] = input[i];
}

/** 
 * Декодирование словаря символов
 * 
 * Алгоритм:
 *    1. Создать массив битовых карт для новых символов
 *    2. Текущая высота = 0
 *    3. Цикл по числу новых символов
 *    3.1 Декодирование delta_height (sym_dict_decode_val)
 *    height_class += delta_height
 *    ширина символа = общая ширина = 0
 *    3.2 Цикл по символам в классе (пока не встретится OOB)
 *    3.2.1 Декодирование delta_width (sym_dict_decode_val)
 *    cur_width += delta_width;
 *    cur_class_width += cur_width;
 *    3.2.2 если huff = 0 или refine_agg = 1 то декодируем битовую карту символа (sym_dict_decode_symbol)
 *    3.2.3 если huff = 1 и refine_agg = 0 то запоминаем текущую ширину символа в массиве символов (по текущему индексу)
 *    3.3 если huff = 1 и refine_agg = 0 то декодируем коллективную битовую карту класса (размеры cur_class_width, class_height) decode_collective_bitmap
 *    3.3.1 разбить коллективную карту на символы, используя запомненные ширины символов и записать в массив новых символов (bitmap_crop) (нужно посчитать число символов в классе высот)
 *    4. Определить какие символы экспортируются (export_syms)
 *
 * @param huff если 1, то кодирование Хаффмана
 * @param refine_agg если 1, то используется улучшение и соединение символов
 * @param num_input_syms число символов во входном словаре
 * @param input_syms входной словарь символов
 * @param num_new_syms число символов в этом словаре
 * @param num_export_syms число символов на выходе словаря
 * @param height_table таблица Хаффмана для декодирования разницы высоты символов между 2-мя классами высот 
 * @param width_table таблица Хаффмана для декодирования разницы ширины между 2-мя символами
 * @param size_table таблица Хаффмана для декодирования размера битовой карты класса высот
 * @param agg_table таблица Хаффмана для декодирования числа экземпляров символов в объединении
 * @param sym_template шаблон битовых карт символов
 * @param sym_adaptive_pixels массив адаптивных шаблонных точек размером 4 для символов
 * @param refine_template шаблон битовых карт улучшения
 * @param refine_adaptive_pixels массив адаптивных шаблонных точек размером 2 для улучшения
 * 
 * @return словарь символов (массив битовых карт)
 */
bitmap_t *sym_dict_decode(
			  int huff, 
			  int refine_agg, 
			  uint num_input_syms, 
			  bitmap_t *input_syms, 
			  uint num_new_syms, 
			  uint num_export_syms, 
			  int *height_table, 
			  int *width_table, 
			  int *size_table, 
			  int *agg_table, 
			  int sym_template, 
			  point_t sym_adaptive_pixels[], 
			  int refine_template, 
			  point_t refine_adaptive_pixels[])
{
    bitmap_t *output_dict = malloc(sizeof(bitmap_t) * num_export_syms);
    class_height = 0;
    bitmap_t *new_syms_dict = malloc(sizeof(bitmap_t) * num_new_syms);
    int *syms_widths = malloc(sizeof(int) * num_new_syms);
    
    for (int i = 0; i < num_new_syms; i++) {
        height_delta = sym_dict_decode_val(huff, height_table);
        class_height += height_delta;
        cur_class_width = 0;
        cur_width = cur_class_width;
        int num_class_syms = 0;
        
        while (1) {            
            width_delta = sym_dict_decode_val(huff, width_table);
            if (oob == 1)
                break;                
            cur_width += width_delta;
            cur_class_width += cur_width;     
            num_class_syms++;
            
            if (huff == 0 || refine_agg == 1)
                new_syms_dict[i] = sym_dict_decode_symbol(refine_agg, cur_width, class_height, refine_template, sym_adaptive_pixels);                
            else if (huff == 1 && refine_agg == 0)
                syms_widths[i] = cur_width;
	    i++;
        }   
        if (huff == 1 && refine_agg == 0) {
            class_bitmap = decode_collective_bitmap(cur_class_width, class_height);
            int start_col = 0;
            for (int j = 0; j < num_class_syms; j++) {
                current_symbol = &new_syms_dict[i - num_class_syms + j];
                current_symbol->data = malloc(class_height * syms_widths[j]);
                bitmap_crop(class_bitmap, current_symbol, start_col, syms_widths[j]);
                start_col += syms_widths[j];
            }
        }
    }
    export_symbols(new_syms_dict, num_new_syms, output_dict, num_export_syms);
    free(sym_widths);
    free(new_syms_dict);
    return output_dict;
}
