#ifndef STR_TO_DOUBLE_H_INCLUDED
#define STR_TO_DOUBLE_H_INCLUDED

struct strtd_output{
    double d_value;
    int wrong_input;
};

struct strtd_output str_to_double(char* str);

#endif // STR_TO_DOUBLE_H_INCLUDED
