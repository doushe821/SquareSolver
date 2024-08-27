#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "solve_quad.h"
#include "solve_quad_command_line.h"
#include "square_solver_io.h"
#include "C_ASSERT.h"

//------------------------------------------------------
//! Iteratively calls strtod() to get coefficients.
//!
//! @param [in] str Array of strings.
//!
//! @param [in] line_n Number of line in argv.
//!
//! @return Structure that consist of 3 coefficients and
//! overflow/miss input flag.
//-------------------------------------------------------

static struct console_coef_input get_abc_console(char* str[], int* line_n);

//------------------------------------------------------
//! Solves quadratic equation (only difference between
//! this one and solve_quad is input source).
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
            c_assert(0, "Wrong coefficients, enter numbers with floating point"
                        "(exponential notation is allowed)");
        }

    struct solve_output_quad cons_answers = solve_quad(coeffs.a, coeffs.b, coeffs.c);
    answers_output(cons_answers);
}

static struct console_coef_input get_abc_console(char* str[], int* line_n)
{
    struct console_coef_input input = {};
    double temp_coef_storage[3] = {};

    for (int n = 0; n < 3; n++)
    {
        char strend = 0;
        char* strend_pointer = &strend;
        double d_value = strtod(str[++(*line_n)], &strend_pointer);
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
