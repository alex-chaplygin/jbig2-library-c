#pragma once
#include "types.h"

enum { // процедуры для контекста
PROC_GB, // общий регион
PROC_GR, // общий с улучшением регион
PROC_IADT, // разница T
PROC_IAFS, // первый S
PROC_IADS, // разница S
PROC_IAIT, // S для экземпляра символа
PROC_IAID, // номер символа
};

int arith_decode(word cx, int proc, int num_bits); // декодирует бит в потоке

void arith_int_decode(int *v, int *s); // целочисленное арифметическое декодирование
// возвращает 2 значения v и s
// если s = 0, то значение v
// если s = 0 и v > 0, то значение -v
// если s = 1 и v = 0, то OOB
