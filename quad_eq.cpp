//------------------------------------------------------------
//! @mainpage This application solves quadratic equations: ax^2 + bx + c.
//------------------------------------------------------------
//------------------------------------------------------------
//! Main function. Gets coefficients with user_menu(), gives the, to
//! solve_quad, then calls answers_output() to display answers.
//------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "square_solver_io.h"
#include "solve_quad.h"
#include "doublecmp.h"
#include "console_commands.h"

int main (int argc, char* argv[])
{
    if (argc > 1)
    {
        struct console_coef_input c_coefs = console_commands(argc, argv);
        struct equation_input console_coefficients_values = {};
        console_coefficients_values.a = c_coefs.a;
        console_coefficients_values.b = c_coefs.b;
        console_coefficients_values.c = c_coefs.c;
        struct solve_output console_output = solve_quad(console_coefficients_values.a, console_coefficients_values.b,
        console_coefficients_values.c);
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
