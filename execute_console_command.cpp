#include <stdio.h>
#include "get_console_commands.h"
#include "solve_quad_command_line.h"
#include "str_to_double.h"
#include "execute_console_command.h"

void execute_console_command(int c, int* j, char* const v[])
{
    switch (c)
    {
        case HELP_CL:
        {
            printf("%s", HELP);
            break;
        }
        case VERSION_CL:
        {
            printf("%s", VERSION);
            break;
        }
        case COEFFICIENTS_CL:
        {
            solve_quad_command_line(j, v);
            break;
        }
        case UN_COMMAND_CL:
        {
            printf("%s", UNKNOWN_COMMAND);
            break;
        }
        default:
            break;
    }
}
