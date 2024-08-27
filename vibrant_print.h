#ifndef VIBRANT_PRINT_H_INLUDED
#define VIBRANT_PRINT_H_INLUDED

#include <stdio.h>
#include "color_vprintf.h"

int vibrant_print(enum spectrum color, FILE* output_stream, const char* str, ...);

#endif
