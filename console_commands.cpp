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

static struct console_coef_input get_abc_console (char* str[], int* line_n);

int get_console_commands (int c, char* v[])
    {
    struct console_coef_input coef_input = {};

    for (int i = 1; i <= c; i++)
        {
        if (strcmp (v[i], "-help") == 0)
            {
            return HELP_CL;
            }
               else if (strcmp (v[i], "-version") == 0)
            {
            return VERSION_CL;
            }
        else if (strcmp (v[i], "-coefficients") == 0)
            {
            return COEFFICIENTS_CL;
            }
        else
            {
            return UN_COMMAND_CL;
            }
        }
    }

static struct console_coef_input get_abc_console (char* str[], int* line_n)
    {
    struct console_coef_input input = {};
    struct strtd_output converted_double  = {};
    double temp_coef_storage[3] = {};

    for (int n = 0; n < 3; n++)
        {
        converted_double = str_to_double (str[++ (*line_n)]);

        if (converted_double.input_error_flag == true)
            exit (0);

        temp_coef_storage[n] = converted_double.d_value;
        }

    input.a = temp_coef_storage[0];
    input.b = temp_coef_storage[1];
    input.c = temp_coef_storage[2];
    return input;
    }
