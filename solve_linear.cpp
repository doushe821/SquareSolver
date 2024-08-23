//---------------------------------------------------------------------
//! Calculates roots if equation is linear: a = 0, b !=0, c != 0.
//!
//! @param [in] b_l, c_l These are b and c coefficients of equation.
//! @param [out] solve_linear_out Contains root of linear equation and linearity flag.
//!
//! @return Root and 1 as number of roots.
//! @note DOUBLE_OVERFLOW is an integer constant, DOUBLE_OVERFLOW = -2. Means numbers are to big to compute.
//---------------------------------------------------------------------

#include <math.h>
#include "solve_linear.h"
#include "solve_quad.h"
#include "doublecmp.h"
#include "C_ASSERT.h"

struct solve_output solve_linear (double b_l, double c_l)
{
    c_assert(b_l != 0, "Non-zero b coefficient.")
    c_assert(c_l != 0, "Non-zero c coefficient.")
    struct solve_output solve_linear_out = {};
    solve_linear_out.x1 = -c_l/b_l;
    solve_linear_out.roots_num = 1;
    solve_linear_out.is_linear = 1;
    return solve_linear_out;
}
