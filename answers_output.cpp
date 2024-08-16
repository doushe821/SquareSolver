#include <stdio.h>
#include "square_solver_constants.h"
#include "solver_input_output.h"
#include <assert.h>

void answers_output(const struct solve_output answers)
{
    switch (answers.roots_num)
    {
        case 2:
        {
            printf("Equation has two roots:\n"
            "x = %lf \t x = %lf\n", answers.x1, answers.x2);
            break;
        }
        case 1:
        {
            if (answers.is_linear)
                printf("Equation is linear and has one root: x = %lf\n", answers.x1);
            else
                printf("Equation has single root: x = %lf\n", answers.x1);
            break;
        }
        case INF_ROOTS:
        {
            printf("Equation has infinite amount of roots.\n");
            break;
        }
        case 0:
        {
            printf("Equation has no roots.\n");
            break;
        }
        default:
            assert(0 && "Error: unexpected number of roots.");
    }
}
