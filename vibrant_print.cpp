#include <stdio.h>
#include "C_ASSERT.h"
#include "vibrant_print.h"
#include <stdarg.h>

int vibrant_print(enum spectrum color, FILE* output_stream, char* str, ...)
{
    const char* const VP_COLORS_AR[] = {"\033[1;31m", "\033[32m", "\033[0m"};
    fprintf(output_stream, "%s", VP_COLORS_AR[color]);
    va_list factor;
    va_start(factor, str);
    int charachters_read = vfprintf(output_stream, str, factor);
    fprintf(output_stream, "%s", "\033[0m");
    return charachters_read;
}
