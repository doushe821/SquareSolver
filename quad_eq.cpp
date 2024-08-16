#include <stdio.h>
#include "square_solver_constants.h"
#include "solver_input_output.h"

int main (void)
{
    puts("This application solves quadratic equations.");
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
