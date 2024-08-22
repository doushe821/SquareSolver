#ifndef SOLVE_QUAD_COMMAND_LINE_H_INCLUDED
#define SOLVE_QUAD_COMMAND_LINE_H_INCLUDED

struct console_coef_input{
    double a;
    double b;
    double c;
    bool overflow_flag;
};

void solve_quad_command_line(int* k, char* const values_str[]);

#endif // SOLVE_QUAD_COMMAND_LINE_H_INCLUDED
