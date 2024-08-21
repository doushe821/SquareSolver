//-------------------------------------------------------
//! Converts string into double.
//!
//! @param [in] str String to be converted.
//!
//! @return double number.
//-------------------------------------------------------

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "str_to_double.h"

struct strtd_output str_to_double(char* str)
{
    int k = 0;
    struct strtd_output output = {};
    if (str[k] != '-' && str[k] != '+' && !isdigit[str[k]])
    {
        output.input_error_flag = true;
        return output;
    }
    double sign = (str[k] == '-') ? -1 : 1;
    if (str[k] == '-' || str[k] == '+')
        k++;
    if(isdigit(str[k]))
        output.d_value = str[k] - '0';
    while(isdigit(str[++k]))
    {
        output.d_value = output.d_value*10 + (str[k] - '0');
    }
    if (str[k] == '.')
    {
        double  power = 1;
        while(isdigit(str[++k]))
        {
            output.d_value = output.d_value*10 + (str[k] - '0');
            power *= 10;
        }
        output.d_value = sign*output.d_value/power;
    }
    return output;
}
