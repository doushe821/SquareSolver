//-------------------------------------------------------
//! Processes command-line input.
//!
//! @param c value from argc from main.
//!
//! @param v values from argv from main.
//-------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "console_commands.h"

int get_console_commands(int c, char* v[])
{
    struct console_coef_input coef_input = {};
    for (int i = 1; i <= c; i++)
    {
        if (strcmp(v[i], "-help") == 0)
        {
            return HELP_CL;
        }
        else if (strcmp(v[i], "-version") == 0)
        {
                return VERSION_CL;
        }
        else if (strcmp(v[i], "-coefficients") == 0)
        {
            return COEFFICIENTS_CL;
        }
        else
        {
            return UN_COMMAND_CL;
        }
    }
}
