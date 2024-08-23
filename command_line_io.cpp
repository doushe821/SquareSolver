#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "command_line_io.h"
#include "solve_quad_command_line.h"
#include "str_to_double.h"
#include "solve_quad.h"
#include "doublecmp.h"

struct TestData data[NUMBER_OF_TESTS]
//   a          b           c           x1ref     x2ref     nRoots
{
    {0        , 0         , 0         , 0       , 0       , INF_ROOTS},  //a, b, c, x1ref, x2ref, nRoots.
    {1        , 0         , 0         , 0       , 0       , 1              },
    {0        , 22        , 133       , -6.04545, 0       , 1              },
    {0        , 0         , 89        , 0       , 0       , 0              },
    {5        , 5         , 5         , 0       , 0       , 0              },
    {NAN      , NAN       , NAN       , 0       , 0       , DOUBLE_OVERFLOW},
    {NAN      , INFINITY  , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {NAN      , -INFINITY , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {NAN      , -INFINITY , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {NAN      , INFINITY  , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY , INFINITY  , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY , -INFINITY , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY , INFINITY  , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY , NAN       , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY , NAN       , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY ,  INFINITY , NAN       , 0       , 0       , DOUBLE_OVERFLOW},
    {INFINITY , -INFINITY , NAN       , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, -INFINITY , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, INFINITY  , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, -INFINITY , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, NAN       , -INFINITY , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, NAN       , INFINITY  , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, INFINITY  , NAN       , 0       , 0       , DOUBLE_OVERFLOW},
    {-INFINITY, -INFINITY , NAN       , 0       , 0       , DOUBLE_OVERFLOW},
    {1.5      , 2.7       , -11.2     , 1.97692 , -3.77692,               2}};

//---------------------------------------------------------------------
//! Runs unit test. Data should be written inside command_line_io.cpp as TestData structure array.
//!
//! @param [in] test TestData structure array.
//!
//! @param test_eps Accuracy for comparing answers with actual ones from tests[].
//!
//---------------------------------------------------------------------

void RunTest(struct TestData test[], double test_eps);

//-------------------------------------------------------
//! Processes command-line input.
//!
//! @param c value from argc from main.
//!
//! @param v values from argv from main.
//-------------------------------------------------------

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option)
{
    for (int j = 0; j < NUMBER_OF_COMMANDS; j++)
    {
        if (strncmp(cl_name[n], option[j].name, MAX_COMMAND_SIZE) == 0)
        {
            return option[j].val;
        }
    }
    return -1;
}

//---------------------------------------------------------------------
//! Executes console commands.
//!
//! @param [in] c
//!
//! @param [in] j
//!
//! @param [in] v
//---------------------------------------------------------------------

void execute_console_command(int c, int* j, char* v[])
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
        case TEST:
        {
            RunTest(data, EPS5);
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

void RunTest(struct TestData test[], double test_eps)
{
    const char* RED = "\033[1;31m";
    const char* GREEN = "\033[32m";
    const char* RESET = "\033[0m";
    struct solve_output test_output = {};
    int errors[NUMBER_OF_TESTS] = {};
    int err_num = 0;
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        test_output = solve_quad(test[i].a, test[i].b, test[i].c);
        if (test_output.roots_num != test[i].nRoots || doublecmp(test_output.x1, test[i].x1ref, EPS5) != 0 || doublecmp(test_output.x2, test[i].x2ref, EPS5) != 0)
        {
            printf("%sExpected: %d, %lg, %lg. Got: %d, %lg, %lg.%s\n", RED, test[i].nRoots, test[i].x1ref, test[i].x2ref, test_output.roots_num, \
            test_output.x1, test_output.x2, RESET);
            errors[i] = 1;
            err_num++;
        }
        printf("Test %d: %d\n", i+1, errors[i]);
    }
    printf("%sErrors:%s\n", RED, RESET);
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        if(errors[i])
            printf("%s%d%s, ", RED, errors[i], RESET);
        else
            printf("%s%d, %s", GREEN, errors[i], RESET);
    }
    if(!err_num)
        printf("%sNo errors, all good.\n%s", GREEN, RESET);
    else
        printf("%d errors. Fix.\n", err_num);
}
