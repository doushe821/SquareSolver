//-------------------------------------------------------
//! Converts string into double.
//!
//! @param [in] str String to be converted.
//!
//! @return double number.
//-------------------------------------------------------

#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

double str_to_double(char* str)
{
    int i = 0;
    double strtod_val = 0, power = 0, sign = 0;
    if (str[i] != '-' && str[i] != '+' && !isdigit[str[i]])
    {
        printf("Wrong input, enter a number with floating point as coefficient.\n");
        exit (1);
    }
    sign = (str[i] == '-') ? -1 : 1;
    return strtod_val*sign;
}
