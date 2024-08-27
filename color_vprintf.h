#ifndef COLOR_VPRINTF_H_INCLUDED
#define COLOR_VPRINTF_H_INCLUDED

#include <stdarg.h>

enum spectrum
{
    red   ,
    green ,
    blue  ,
    yellow,
    orange,
    reset
};

int color_vprintf (FILE* stream, const char* format, enum spectrum color, va_list ap);

#endif // COLOR_VPRINTF_H_INCLUDED
