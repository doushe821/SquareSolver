#ifndef SQUARE_SOLVER_STRUCTURES_H_INCLUDED
#define SQUARE_SOLVER_STRUCTURES_H_INCLUDED

struct solve_output{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct equation_input{
    double a;
    double b;
    double c;
    bool eof_flag;
    bool quit_flag;
};

struct coef_input{
    double temp_value;
    bool eof_flag;
};

#endif // SQUARE_SOLVER_STRUCTURES_H_INCLUDED
