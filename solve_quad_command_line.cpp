static struct console_coef_input get_abc_console(char* str[], int line_n);

#include <stdlib.h>
#include "solve_quad.h"
#include "solve_quad_command_line.h"
#include "square_solver_io.h"
#include "str_to_double.h"


void solve_quad_command_line(int k, char* values_str[])
{
    struct console_coef_input coeffs = get_abc_console(values_str, k);
    struct solve_output cons_answers = solve_quad(coeffs.a, coeffs.b, coeffs.c);
    answers_output(cons_answers);
}

static struct console_coef_input get_abc_console(char* str[], int line_n)
{
    struct console_coef_input input = {};
    struct strtd_output converted_double  = {};
    double temp_coef_storage[3] = {};
    for (int n = 0; n < 3; n++)
    {
        converted_double = str_to_double(str[++line_n]);
        if(converted_double.input_error_flag == true)
            exit(0);
        temp_coef_storage[n] = converted_double.d_value;
    }
    input.a = temp_coef_storage[0];
    input.b = temp_coef_storage[1];
    input.c = temp_coef_storage[2];
    return input;
}
