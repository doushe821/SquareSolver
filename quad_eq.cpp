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
#include "console_commands.h"

int main (int argc, char* argv[])
{
    if (argc > 1)
    {
        struct console_coef_input c_coefs = console_commands(argc, argv);

        assert(!c_coefs.error_flag && "Console input error.");

        struct solve_output console_output = solve_quad(c_coefs.a, c_coefs.b, c_coefs.c);
        answers_output(console_output);
        return 0;
    }
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
