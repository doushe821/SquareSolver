//------------------------------------------------------------
//! @mainpage This application solves quadratic equations: ax^2 + bx + c.
//------------------------------------------------------------
//------------------------------------------------------------
//! Main function. Gets coefficients with user_menu(), gives the, to
//! solve_quad, then calls answers_output() to display answers.
//------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "square_solver_io.h"
#include "C_ASSERT.h"
#include "solve_quad.h"
#include "doublecmp.h"
#include "command_line_io.h"
#include "vibrant_print.h"

int main (int argc, char* argv[])
{
    const struct command_line_option square_solver_commands[] =
    {
        {"--help",         HELP_CL},
        {"--version",      VERSION_CL},
        {"--coefficients", COEFFICIENTS_CL},
        {"--test",         TEST},
        {"--ftest",        FTEST}
    };

    for (int i = 1; i < argc; i++)
    {
        if(!execute_console_command(get_console_commands(i, argv, square_solver_commands), &i, argv))
        {
            return EXIT_FAILURE;
        }
    }
    if (argc > 1)
        return 0;

    puts("# This application solves quadratic equations.");
    printf("%s", MENU_INPUT);

    while (1)
    {
        struct equation_input coefficients_values = user_menu();
        if (coefficients_values.quit_flag == true)
            break;

        struct solve_output_quad output = solve_quad(coefficients_values.a, coefficients_values.b, coefficients_values.c);
        answers_output(output);
        printf("%s", MENU_INPUT);
    }

    printf("Bye.");
    return 0;
}
