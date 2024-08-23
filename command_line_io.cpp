#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "command_line_io.h"
#include "solve_quad_command_line.h"
#include "solve_quad.h"
#include "square_solver_io.h"
#include "doublecmp.h"
#include "vibrant_print.h"

#include "C_ASSERT.h"

struct TestData data[NUMBER_OF_TESTS]
//   a          b           c           x1ref     x2ref     nRoots
{
    {0        , 0         , 0         , 0       , 0       , INF_ROOTS      },
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
    c_assert(0, "Unexpected behavior, contact dev(contacts undefined).");
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

void execute_console_command(int flag, int* j, char* v[])
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
            RunTest(data, EPS_CL);
            break;
        }
        case UN_COMMAND_CL:
        {
            printf("%s", UNKNOWN_COMMAND);
            break;
        }
        default:
            c_assert(0, "Unexpected behavior, contact dev(contacts undefined).");
    }
}

void RunTest(struct TestData test[], double test_eps)
{
    struct solve_output test_output = {};
    int results[NUMBER_OF_TESTS] = {};
    int err_num = 0;
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        test_output = solve_quad(test[i].a, test[i].b, test[i].c);
        if (test_output.roots_num != test[i].nRoots || doublecmp(test_output.x1, test[i].x1ref, EPS_CL) != 0 || doublecmp(test_output.x2, test[i].x2ref, EPS_CL) != 0)
        {
            vibrant_print(red, stdout, "Expected: %d, %lg, %lg. Got: %d, %lg, %lg", test[i].nRoots, test[i].x1ref, test[i].x2ref, test_output.roots_num,
                          test_output.x1, test_output.x2);
            results[i] = 1;
            err_num++;
        }
        printf("Test %d: %d\n", i+1, results[i]);
    }
    printf("%sErrors:%s\n", RED, RESET);
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        if(results[i])
            vibrant_print(red, stdout, "%d, ", results[i]);
        else
            vibrant_print(green, stdout, "%d, ", results[i]);
    }
    if(!err_num)
        vibrant_print(green, stdout, "No errors, all good.\n");
    else
        printf("%d errors. Fix.\n", err_num);
}
