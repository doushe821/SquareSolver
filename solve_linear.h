#ifndef SOLVE_LINEAR_H_INCLUDED
#define SOLVE_LINEAR_H_INCLUDED

struct solve_output_linear
{
    double root;
    int roots_num;
};

struct solve_output_linear solve_linear(double b_l, double c_l);

#endif // SOLVE_LINEAR_H_INCLUDED
