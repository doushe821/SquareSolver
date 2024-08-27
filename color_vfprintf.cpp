#include <stdarg.h>
#include <io.h>
#include <stdio.h>
#include "color_vprintf.h"

int color_vprintf (FILE* stream, const char* format, enum spectrum color, va_list ap)
{
    if (_isatty(_fileno(stream)))
    {
        const char* const VP_COLORS_AR[] = {"\033[1;31m", "\033[32m", "\033[0m"};

        fprintf(stream, "%s", VP_COLORS_AR[color]);

        int c_read = vfprintf(stream, format, ap);

        fprintf(stream, "%s", "\033[0m");

        return c_read;
    }
    else
    {
        return vfprintf(stream, format, ap);
    }

}
