#include "types.h"

/// битовая карта
typedef struct {
    int width;			/**< ширина */
    int height;			/**< высота */
    byte *data;			/**< массив пикселей по строкам сверху-вниз справо-налево */
} bitmap_t;
