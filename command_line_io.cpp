#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command_line_io.h"
#include "solve_quad_command_line.h"
#include "solve_quad.h"
#include "square_solver_io.h"
#include "doublecmp.h"
#include "s_gets.h"
#include "vibrant_print.h"
#include "unit_test.h"
#include "C_ASSERT.h"

//---------------------------------------------------------------------
//! Runs unit test. Data should be written inside command_line_io.cpp
//! as test_data structure array.
//!
//! @param [in] test test_data structure array.
//!
//! @param test_eps Accuracy for comparing answers with actual ones
//! from tests[].
//!
//---------------------------------------------------------------------

//-------------------------------------------------------
//! Processes command-line input.
//!
//! @param c value from argc from main.
//!
//! @param v values from argv from main.
//-------------------------------------------------------

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option)
{
    bool command_flag = false;
    for (int j = 0; j < NUMBER_OF_COMMANDS; j++)
    {
        if (strncmp(cl_name[n], option[j].name, MAX_COMMAND_SIZE) == 0)
        {
            command_flag = true;
            return option[j].val;
        }
    }
    if (!command_flag)
    {
        return UN_COMMAND_CL;
    }
    c_assert(0, "Unexpected behavior, contact dev(contacts undefined).");
    return(3);
}

//---------------------------------------------------------------------
//! Executes console commands.
//!
//! @param [in] flag
//!
//! @param [in] j
//!
//! @param [in] v
//---------------------------------------------------------------------

bool execute_console_command(int flag, int* j, char* v[])
{
    switch (flag)
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
        case TEST:
        {
            get_f_test_data();
            break;
        }
        case UN_COMMAND_CL:
        {
            printf("%s", UNKNOWN_COMMAND);
            return false;
        }
        default:
        {
        }
    }
    return false;
}
