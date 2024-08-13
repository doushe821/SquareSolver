#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const int inf_roots = -1;

struct user_input {
    double value;
    bool eof_flag;
};

struct solve_output{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct solve_output solve_quad (double a_s, double b_s, double c_s);

struct user_input get_input (char k);

int main (void)
{
    char coefficients_names[3] = {'a', 'b', 'c'};
    double coefficients_values[3] = {0};
    struct user_input input_check = {0};
    struct solve_output output = {0};

    puts("This application solves quadratic equations.");
    puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
    char ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            puts("Invalid input.");
            puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
            continue;
        }
        if (ch == 's' && getc(stdin) == '\n')
        {
            printf("Enter coefficients: ax^2 + bx + c = 0\n"
            "Press \"Ctrl+Z\" to return to menu.\n");
            for (int i = 0; i < 3; i++)
            {
                input_check = get_input(coefficients_names[i]);
                if (input_check.eof_flag)
                {
                    printf("Returning to menu.\n");
                    puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
                    continue;
                }
                else
                coefficients_values[i] = input_check.value;
            }
            output = solve_quad(coefficients_values[0], coefficients_values[1], coefficients_values[2]);
            if (output.roots_num == 2)
                printf("Equation has two roots:\n"
                "x = %lf \t x = %lf\n", output.x1, output.x2);
            else if (output.roots_num == 1)
            {
                if (output.is_linear)
                    printf("Equation is linear and has one root: x = %lf\n", output.x1);
                else
                    printf("Equation has single root: x = %lf\n", output.x1);
            }
            else if (output.roots_num == inf_roots)
                printf("Equation has infinite amount of roots.\n");
            else if (!output.roots_num)
            {
                printf("Equation has no roots.\n");
            }

            puts("Type \"s\" to continue solving equations, type \"q\" to exit program.");
        }
        else if (ch == 'q' && getc(stdin) == '\n')
        {
            printf("Bye.");
            exit(0);
        }
        else
        {
            puts("Invalid input.");
            puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
            while (getchar() != '\n')
                continue;
        }
    }
}

struct solve_output solve_quad (double a_s, double b_s, double c_s)
{
    struct solve_output solve_quad_out = {0};
    double d = b_s*b_s - 4*a_s*c_s;

    if (a_s == 0 && b_s != 0)
    {
        solve_quad_out.x1 = -c_s/b_s;
        solve_quad_out.roots_num = 1;
        solve_quad_out.is_linear = 1;
    }
    else if (a_s == 0 && b_s == 0 && c_s != 0)
        solve_quad_out.roots_num = 0;
    else if (a_s == 0 && b_s == 0 && c_s == 0)
        solve_quad_out.roots_num = inf_roots;
    else if (d < 0)
        solve_quad_out.roots_num = 0;
    else if (d == 0)
    {
        solve_quad_out.x1 = -b_s/(2*a_s);
        solve_quad_out.roots_num = 1;
    }
    else
    {
        d = sqrt(d);
        solve_quad_out.x1 = (-b_s + d)/(2*a_s);
        solve_quad_out.x2 = (-b_s - d)/(2*a_s);
        solve_quad_out.roots_num = 2;
    }
    return solve_quad_out;
}

struct user_input get_input(char k)
{
    struct user_input input = {0, 0};

    while (1)
    {
        printf("%c: ", k);
        int check = 0;
        if ((check = scanf("%lf", &input.value)) == 1 && getchar() == '\n')
            break;
        else if (check == -1)
        {
            input.eof_flag = 1;
            break;
        }
        else
        {
            char miss_input = 0;
            while ((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a number, try again.\n");
        }
    }
    return input;
}
