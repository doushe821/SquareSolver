#include <stdio.h>
#include <errno.h>
#include "square_solver_io.h"
#include "solve_quad.h"
#include "square_solver_io.h"
#include "get_input_double.h"

//---------------------------------------------------------------------
//! Calls for get_input_double() 3 times, puts all values in structure
//! equation_input.
//!
//! @return Coefficients' values and EOF flag (if user types EOF).
//---------------------------------------------------------------------

static struct equation_input get_abc();

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
            printf("Program read triads of coefficients divided by space or end of line.\n"
            "So make sure your file consists only of these elements and exists in directory of SquareSolver.exe.\n"
            "Enter file's name: ");
            char fileName[MAX_FILENAME_LENGTH] = {};
            scanf("%s", &fileName);
            while (getchar() != '\n')
                continue;
            FILE* inputFile = fopen(fileName, "r");
            if (inputFile == NULL)
            {
                fprintf(stderr, "Cannot open file.\n");  //  errno
                printf("\n%s", MENU_INPUT);
                continue;
            }
            else
            {
                while(fscanf(inputFile, "%lf %lf %lf", &user_menu_input.a, &user_menu_input.b, &user_menu_input.c) == 3)
                {
                    printf("\nCoefficients: a = %lg, b = %lg, c = %lg\n", user_menu_input.a, user_menu_input.b, user_menu_input.c);
                    struct solve_output f_output = solve_quad(user_menu_input.a, user_menu_input.b, user_menu_input.c);
                    answers_output(f_output);
                }
                printf("\n%s", MENU_INPUT);
            }
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
