//---------------------------------------------------------------------
//! Displays answers to equation.
//!
//! @param [in] answers Contains values of roots and number of them.
//!
//! @note INF_ROOTS is an integer constant. INF_ROOTS = -1.
//! Means a = 0, b = 0, c = 0.
//! @note DOUBLE_OVERFLOW is also an integer constant.
//! DOUBLE_OVERFLOW = -2. Means numbers are to big to compute.
//!
//---------------------------------------------------------------------

#include <stdio.h>
#include "square_solver_io.h"
#include "solve_quad.h"
#include "C_ASSERT.h"

void answers_output(const struct solve_output answers)
{
    switch (answers.roots_num)
    {
        case 2:
        {
            printf("Equation has two roots:\n"
            "x = %lg \t x = %lg\n", answers.x1, answers.x2);
            break;
        }
        case 1:
        {
            if (answers.is_linear)
                printf("Equation is linear and has one root: x = %.6lg\n", answers.x1);
            else
                printf("Equation has single root: x = %.6lg\n", answers.x1);
            break;
        }
        case INF_ROOTS:
        {
            printf("Equation has infinite amount of roots.\n");
            break;
        }
        case DOUBLE_OVERFLOW:
        {
            printf("Roots are to big to be processed.\n");
            break;
        }
        case 0:
        {
            printf("Equation has no roots.\n");
            break;
        }
        default:
            c_assert(0, "Error: unexpected number of roots.");
    }
}
