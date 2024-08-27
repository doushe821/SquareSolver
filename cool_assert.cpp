#include "C_ASSERT.h"
#include "color_vprintf.h"
#include <stdarg.h>

//--------------------------------------------------------------------------
//! Upgraded assert that writes in red color and also allows you to print
//! message alongside with condition. Besides that works exactly like assert
//! from assert.h. All "cool asserts" can be turned off by
//! #include "C_NDEBUG.h" preprocessor directive.
//--------------------------------------------------------------------------

void cool_assert(int condition_l, const char* condition_s, const char* file, const char* func, int line, \
                 const char* comment, ...)
{
    if(!condition_l)
    {
        va_list factor;
        va_start(factor, comment);

        color_vprintf(stderr, comment, red, factor);
        vibrant_print(red, stderr, "Assertion failed: %s. %s -> %s -> %d",
                      condition_s, file, func, line);

        va_end (factor);
        abort();
    }
}
