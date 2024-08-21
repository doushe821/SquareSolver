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
    static struct console_coef_input coef_input = {};
    for (int i = 0; i < c; i++)
    {
        if (strcmp(v[i], "help") == false)
        {
            printf("%s", HELP);
            exit (0);
        }
        else if (strcmp(v[i], "version") == false)
        {
                printf("%s", VERSION);
                exit (0);
        }
        else if (strcmp(v[i], "coefficients"))
        {

        }
        else
        {
            printf("%s", UNKNOWN_COMMAND);
            exit (0);
        }
    }
}
