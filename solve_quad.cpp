#include <math.h>
#include "solve_quad.h"
#include "doublecmp.h"
#include "overflow_check_double.h"

//---------------------------------------------------------------------
//! Calculates roots if equation is linear: a = 0, b !=0, c != 0.
//!
//! @param [in] b_l, c_l These are b and c coefficients of equation.
//! @param [out] solve_linear_out Contains root of linear equation and linearity flag.
//!
//! @return Root and 1 as number of roots.
//! @note DOUBLE_OVERFLOW is an integer constant, DOUBLE_OVERFLOW = -2. Means numbers are to big to compute.
//---------------------------------------------------------------------

static struct solve_output solve_linear (double b_l, double c_l);

//---------------------------------------------------------------------
//! Calculates roots of quadratic equation.
//!
//! @param [in] a, b, c Coefficients of quadratic equation.
//!
//! @return Roots and their quantity.
//!
//! @note INF_ROOTS is an integer constant. INF_ROOTS = -1, Means a = 0, b = 0, c = 0.
//! @note DOUBLE_OVERFLOW is also an integer constant, DOUBLE_OVERFLOW = -2. Means numbers are to big to compute.
//!
//---------------------------------------------------------------------

struct solve_output solve_quad (double a_s, double b_s, double c_s)
{
    struct solve_output solve_quad_out = {};
    double d = b_s*b_s - 4*a_s*c_s;

    if (overflow_check_double(d) == true)
    {
        solve_quad_out.roots_num = DOUBLE_OVERFLOW;
        return solve_quad_out;
    }

    if (doublecmp(a_s, 0, EPS) == 0 && doublecmp(b_s, 0, EPS) != 0)
    {
        solve_quad_out = solve_linear(b_s, c_s);
    }
    else if (doublecmp(a_s, 0, EPS) == 0 && doublecmp(b_s, 0, EPS) == 0)
    {
        if (doublecmp(c_s, 0, EPS) != 0)
            solve_quad_out.roots_num = 0;
        else
            solve_quad_out.roots_num = INF_ROOTS;
    }
    else if (doublecmp(d, 0, EPS) == -1)
        solve_quad_out.roots_num = 0;
    else if (doublecmp(d, 0, EPS) == 0)
    {
        if (doublecmp(-b_s/(2*a_s), 0, EPS) == 0)
        {
            solve_quad_out.x1 = fabs(-b_s/2*a_s);
        }
        else
        {
        solve_quad_out.x1 = -b_s/(2*a_s);
        }
        solve_quad_out.roots_num = 1;
    }
    else
    {
        double d_sqrt = sqrt(d);
        solve_quad_out.x1 = (-b_s + d_sqrt)/(2*a_s);
        solve_quad_out.x2 = (-b_s - d_sqrt)/(2*a_s);
        solve_quad_out.roots_num = 2;
    }

    return solve_quad_out;
}

static struct solve_output solve_linear (double b_l, double c_l)
{
    struct solve_output solve_linear_out = {};
    solve_linear_out.x1 = -c_l/b_l;
    solve_linear_out.roots_num = 1;
    solve_linear_out.is_linear = 1;
    return solve_linear_out;
}
