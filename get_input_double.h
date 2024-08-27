#ifndef GET_DOUBLE_INPUT_H_INCLUDED
#define GET_DOUBLE_INPUT_H_INCLUDED

struct coef_input
{
    double temp_value;
    bool eof_flag;
    bool overflow_flag;
};

struct coef_input get_input_double (void);

#endif // GET_DOUBLE_INPUT_H_INCLUDED
