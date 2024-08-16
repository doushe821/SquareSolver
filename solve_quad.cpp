#include <math.h>
#include "doublecmp.h"
#include "square_solver_constants.h"
#include "square_solver_structures.h"

struct solve_output solve_quad (double a_s, double b_s, double c_s)
{
    struct solve_output solve_quad_out = {};
    double d = b_s*b_s - 4*a_s*c_s;

    if (doublecmp(a_s, 0, EPS) == 0 && doublecmp(b_s, 0, EPS) != 0)
    {
        solve_quad_out.x1 = -c_s/b_s;
        solve_quad_out.roots_num = 1;
        solve_quad_out.is_linear = 1;
    }
    else if (doublecmp(a_s, 0, EPS) == 0 && doublecmp(b_s, 0, EPS) == 0)
        if (doublecmp(c_s, 0, EPS) != 0)
            solve_quad_out.roots_num = 0;
        else
            solve_quad_out.roots_num = INF_ROOTS;
    else if (doublecmp(d, 0, EPS) == -1)
        solve_quad_out.roots_num = 0;
    else if (doublecmp(d, 0, EPS) == 0)
    {
        solve_quad_out.x1 = -b_s/(2*a_s);
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
