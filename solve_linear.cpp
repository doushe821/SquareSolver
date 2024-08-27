//---------------------------------------------------------------------
//! Calculates roots if equation is linear: a = 0, b !=0, c != 0.
//!
//! @param [in] b_l, c_l These are b and c coefficients of equation.
//! @param [out] solve_linear_out Contains root of linear equation and
//! linearity flag.
//!
//! @return Root and 1 as number of roots.
//! @note DOUBLE_OVERFLOW is an integer constant, DOUBLE_OVERFLOW = -2.
//! Means numbers are to big to compute.
//---------------------------------------------------------------------

#include <math.h>
#include "solve_linear.h"
#include "solve_quad.h"
#include "doublecmp.h"
#include "C_ASSERT.h"

struct solve_output_linear solve_linear(double b_l, double c_l)
{
    c_assert(doublecmp(b_l, 0, EPS), "Non-zero b coefficient.");
    c_assert(doublecmp(c_l, 0, EPS), "Non-zero c coefficient.");

    struct solve_output_linear solve_linear_out = {};
    if(doublecmp(b_l, 0, EPS) == 0)
    {
        solve_linear_out.roots_num = 0;
        return solve_linear_out;
    }
    else if (doublecmp(b_l, 0, EPS) == 0 && doublecmp(c_l, 0, EPS) == 0)
    {
        solve_linear_out.roots_num = INF_ROOTS;
        return solve_linear_out;
    }
    else
    {
        solve_linear_out.root = -c_l/b_l;
        solve_linear_out.roots_num = 1;
        return solve_linear_out;
    }
}
