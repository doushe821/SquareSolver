//---------------------------------------------------------------------
//! @fn user_menu Gets user's input and coefficients.
//!
//! @return user_menu_input Contains coefficients (a, b, c), EOF flag
//! and quit flag (if user wants to quit).
//!
//! @fn get_abc Consequently gets coefficients values
//!
//! @return get_abc_input Also contains coefficients and EOF, overflow flags.
//---------------------------------------------------------------------

#include <stdio.h>
#include "square_solver_io.h"
#include "solve_quad.h"
#include "get_input_double.h"

static struct equation_input get_abc ();

struct equation_input user_menu ()
{
    int ch = 0;
    struct equation_input user_menu_input = {};
    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            printf("%s%s", INVALID_IN, MENU_INPUT);
            continue;
        }
        if (ch == 's' && getc(stdin) == '\n')
        {
            printf("# Enter coefficients: ax^2 + bx + c = 0\n");
            user_menu_input = get_abc();
            if (user_menu_input.eof_flag == true)
            {
                printf("%s", MENU_INPUT);
                continue;
            }
            return user_menu_input;
        }
        else
        {
            printf("%s%s", INVALID_IN, MENU_INPUT);
            if (ch != EOF)
            {
                while (getchar() != '\n')
                continue;
            }
        }
    }
    user_menu_input.quit_flag = true;
    return user_menu_input;
}

static struct equation_input get_abc()
{
    char coefficients_names[3] = {'a', 'b', 'c'};
    struct equation_input get_abc_input = {};
    double cfs[3] = {};
    for (int i = 0; i < 3; i++)
    {
        struct coef_input abc_check = {};
        printf("%c: ", coefficients_names[i]);
        abc_check = get_input_double();
        if (abc_check.eof_flag == true)
        {
            get_abc_input.eof_flag = true;
            return get_abc_input;
        }
        cfs[i] = abc_check.temp_value;
    }
    get_abc_input.a = cfs[0];
    get_abc_input.b = cfs[1];
    get_abc_input.c = cfs[2];
    return get_abc_input;
}
