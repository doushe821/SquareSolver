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

int const MAX_COMMAND_SIZE = 64;

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option)
{
    for (int j = 0; j < NUMBER_OF_COMMANDS; j++)
    {
        if (strncmp(cl_name[n], option[j].name, MAX_COMMAND_SIZE) == 0)
        {
            return option[j].val;
        }
    }
    return -1;
}
