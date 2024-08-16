#include <stdio.h>
#include "square_solver_structures.h"
#include "get_double_input.h"

struct coef_input get_input_double(void)
{
    struct coef_input input = {};
    while (1)
    {
        int check = 0;
        if ((check = scanf("%lf", &input.temp_value)) == 1 && getchar() == '\n')
            break;
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
    return input;
}
