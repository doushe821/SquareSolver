//---------------------------------------------------------------------
//! Gets double number.
//!
//! @return Double number, EOF flag and overflow flag.
//---------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include "get_input_double.h"
#include "doublecmp.h"
#include "solve_quad.h"

struct coef_input get_input_double(void)
{
    struct coef_input input = {};
    while (1)
    {
        int check = 0;

        if ((check = scanf("%lf", &input.temp_value)) == 1 && getchar() == '\n')
        {
            if (isfinite(input.temp_value) == false)
            {
                printf("# Coefficient is too big to be processed, try another one.\n");
                continue;
            }
            return input;
        }

        else if (check == -1)
        {
            input.eof_flag = 1;
            return input;
        }

        else
        {
            int miss_input = 0;
            while ((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a number, try again.\n");
        }
    }
}


