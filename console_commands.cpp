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
#include "str_to_double.h"
#include "console_commands.h"

struct console_coef_input console_commands(int c, char* v[])
{
    struct console_coef_input coef_input = {};
    for (int i = 1; i <= c; i++)
    {
        if (strcmp(v[i], "help") == 0)
        {
            printf("%s", HELP);
            exit (0);
        }
        else if (strcmp(v[i], "version") == 0)
        {
                printf("%s", VERSION);
                exit (0);
        }
        else if (strcmp(v[i], "coefficients") == 0)
        {
            struct strtd_output cons_val = str_to_double(v[++i]);
            coef_input.a = cons_val.d_value;
            cons_val = str_to_double(v[++i]);
            coef_input.b = cons_val.d_value;
            cons_val = str_to_double(v[++i]);
            coef_input.c = cons_val.d_value;
            return coef_input;
        }
        else
        {
            printf("%s", UNKNOWN_COMMAND);
            exit (0);
        }
    }
    coef_input.error_flag = true;
    return coef_input;
}
