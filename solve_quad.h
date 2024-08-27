#ifndef SOLVE_QUAD_H_INCLUDED
#define SOLVE_QUAD_H_INCLUDED

const int INF_ROOTS = -1;
const int DOUBLE_OVERFLOW = -2;

struct solve_output_quad
{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct solve_output_quad solve_quad (double a_s, double b_s, double c_s);

#endif // SOLVE_QUAD_H_INCLUDED
