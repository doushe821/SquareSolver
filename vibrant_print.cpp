#include <stdio.h>
#include <io.h>
#include "C_ASSERT.h"
#include "vibrant_print.h"
#include <stdarg.h>

//---------------------------------------------------------------------------
//! Output function based on frprintf(). Can redirect stream to selected file
//! with selected color.
//!
//! @param [in] color Color name (currently supports all colors of rainbow)
//!
//! @param [in] output_stream FILE pointer.
//!
//! @param [in] str String to print
//!
//! @param [in] identificators Works exactly like printf() from stdio.h library.
//------------------------------------------------------------------------------

int vibrant_print(enum spectrum color, FILE* output_stream, const char* str, ...)
{
    va_list factor;
    va_start(factor, str);

    if (_isatty(_fileno(output_stream)))
    {
        int c_read = color_vprintf(output_stream, str,  color, factor);

        va_end(factor);

        return c_read;
    }

    else
    {
        va_end(factor);
        return vfprintf(output_stream, str, factor);
    }
}
