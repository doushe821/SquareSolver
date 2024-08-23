#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "solve_quad.h"
#include "solve_quad_command_line.h"
#include "square_solver_io.h"
#include "str_to_double.h"

//------------------------------------------------------
//! Iteratively calls strtod() to get coefficients.
//!
//! @param [in] str Array of strings.
//!
//! @param [in] line_n Number of line in argv.
//!
//! @return Structure that consist of 3 coefficients and overflow/miss input flag.
//-------------------------------------------------------

static struct console_coef_input get_abc_console(char* str[], int* line_n);

//------------------------------------------------------
//! Solves quadratic equation (only difference between this one and solve_quad is input source).
//!
//! @param [in] k Number of line in argv.
//!
//! @param [in] values_str Array of strings.
//------------------------------------------------------

void solve_quad_command_line(int* k, char* values_str[])
{
    struct console_coef_input coeffs = get_abc_console(values_str, k);
    if(coeffs.missinput_flag == true)
        {
            printf("Wrong input, please enter only numbers with floating point.\n");
            exit(1);
        }
    struct solve_output cons_answers = solve_quad(coeffs.a, coeffs.b, coeffs.c);
    answers_output(cons_answers);
}

static struct console_coef_input get_abc_console(char* str[], int* line_n)
{
    struct console_coef_input input = {};;
    double temp_coef_storage[3] = {};
    for (int n = 0; n < 3; n++)
    {
        char strend = 0;
        char* strend_pointer = &strend;
        double d_value = strtod(str[++(*line_n)], &strend_pointer);//str_to_double(str[++(*line_n)]);////
        if(*strend_pointer != ' ' && *strend_pointer != '\n' && *strend_pointer != '\0')
        {
            input.missinput_flag = true;
            return input;
        }
        temp_coef_storage[n] = d_value;
    }
    input.a = temp_coef_storage[0];
    input.b = temp_coef_storage[1];
    input.c = temp_coef_storage[2];
    return input;
}
