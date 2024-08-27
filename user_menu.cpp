#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "square_solver_io.h"
#include "solve_quad.h"
#include "square_solver_io.h"
#include "get_input_double.h"
#include "vibrant_print.h"
#include "s_gets.h"

//---------------------------------------------------------------------
//! Calls for get_input_double() 3 times, puts all values in structure
//! equation_input.
//!
//! @return Coefficients' values and EOF flag (if user types EOF).
//---------------------------------------------------------------------

static struct equation_input get_abc();

//---------------------------------------------------------------------
//! Processes file input.
//---------------------------------------------------------------------

void process_file_input ();

//---------------------------------------------------------------------
//! @note Processes user's input,
//! @return Coefficients (a, b, c) with EOF and quit flag.
//---------------------------------------------------------------------

struct equation_input user_menu()
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

        else if(ch == 'f' && getc(stdin) == '\n')
        {
            process_file_input();
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

void process_file_input ()
{
    printf("# Program read triads of coefficients divided by space or end of line.\n"
           "# So make sure your file consists only of these elements and exists in directory of SquareSolver.exe.\n"
           "# Enter file's name: ");
    char fileName[FILENAME_MAX] = {};
    s_gets(fileName, FILENAME_MAX);
    FILE* inputFile = fopen(fileName, "r");
    if (inputFile == NULL)
    {
        vibrant_print(red, stderr, "%s", strerror(errno));
        printf("\n%s", MENU_INPUT);
    }

    else
    {
        struct equation_input file_input = {};
        while(fscanf(inputFile, "%lf %lf %lf", &file_input.a, &file_input.b, &file_input.c) == 3)
        {
            if(!isfinite(file_input.a) || !isfinite(file_input.b) || !isfinite(file_input.c))
            {
                printf("Some coefficients are too big to be processed. Rewrite them.\n");
                break;
            }
            else
            {
            printf("\nCoefficients: a = %lg, b = %lg, c = %lg\n", file_input.a, file_input.b, file_input.c);
            struct solve_output_quad f_output = solve_quad(file_input.a, file_input.b, file_input.c);
            answers_output(f_output);
            }
        }
        printf("\n%s", MENU_INPUT);
    }
}
