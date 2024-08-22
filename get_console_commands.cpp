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
#include "get_console_commands.h"

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option)
{
    for (int j = 0; j < NUMBER_OF_COMMANDS; j++)
    {
        if (strcmp(cl_name[n], option[j].name) == 0)
        {
            return option[j].val;
        }
    }
    return UN_COMMAND_CL;
}
