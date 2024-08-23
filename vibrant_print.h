#ifndef VIBRANT_PRINT_H_INLUDED
#define VIBRANT_PRINT_H_INLUDED

#include <stdio.h>

enum spectrum{
    red   ,
    green ,
    blue  ,
    yellow,
    orange,
    reset
    };


int vibrant_print(enum spectrum color, FILE* output_stream, char* str, ...);

#endif
