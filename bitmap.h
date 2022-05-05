#include "types.h"

/// точка
typedef struct {
  int x;			/**< координата x */
  int y;			/**< координата y */
} point_t;

/// битовая карта
typedef struct {
    int width;			/**< ширина */
    int height;			/**< высота */
    byte *data;			/**< массив пикселей по строкам сверху-вниз справо-налево */
} bitmap_t;

bitmap_t *new_bitmap(int w, int h); // создать новую карту
int get_pixel(bitmap_t *bm, int x, int y); // прочитать точку (точки за пределами карты равны 0)
