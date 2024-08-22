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
#include <string.h>
#include <assert.h>
#include "square_solver_io.h"
#include "solve_quad.h"
#include "doublecmp.h"
#include "get_console_commands.h"
#include "execute_console_command.h"

int main (int argc, char* argv[])
{
    int cl_values[3] = {};

    const struct command_line_option square_solver_commands[] = {
    {"--help", HELP_CL},
    {"--version", VERSION_CL},
    {"--coefficients", COEFFICIENTS_CL}
};

    for (int i = 1; i < argc; i++)
    {
        execute_console_command(get_console_commands(i, argv, square_solver_commands), &i, argv);
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
        struct solve_output output = solve_quad(coefficients_values.a, coefficients_values.b, coefficients_values.c);
        answers_output(output);
        printf("%s", MENU_INPUT);
    }
    printf("Bye.");
    return 0;
}
