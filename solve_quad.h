#ifndef SOLVE_QUAD_H_INCLUDED
#define SOLVE_QUAD_H_INCLUDED

const int INF_ROOTS = -1;
const double EPS = 1E-12;

struct solve_output{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct solve_output solve_quad (double a_s, double b_s, double c_s);

#endif // SOLVE_QUAD_H_INCLUDED
