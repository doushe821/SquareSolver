#include <stdio.h>
#include <math.h>
#include "get_console_commands.h"
#include "solve_quad_command_line.h"
#include "str_to_double.h"
#include "execute_console_command.h"
#include "UnitTest.h"
#include "solve_quad.h"

struct TestData data[NUMBER_OF_TESTS]{
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
void execute_console_command(int c, int* j, char* const v[])
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
            RunTest(data);
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
