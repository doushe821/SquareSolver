#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#define MENU_INPUT "Type \"s\" to start solving equations, type \"q\" to exit program.\n"

const double EPS = 1E-12;
const int INF_ROOTS = -1;

struct solve_output{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct solve_output solve_quad (double a_s, double b_s, double c_s);

bool get_input (double * cfs);

int doublecmp(double a, double b, double acc);

void answers_output(const struct solve_output console_out);

int main (void)
{
    double coefficients_values[3] = {};
    struct solve_output output = {};
    puts("This application solves quadratic equations.");
    printf("%s", MENU_INPUT);
    int ch = 0;
    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            puts("Invalid input.");
            printf("%s", MENU_INPUT);
            continue;
        }
        if (ch == 's' && getc(stdin) == '\n')
        {
            printf("Enter coefficients: ax^2 + bx + c = 0\n");
            bool eof_flag = get_input(coefficients_values);
            if (eof_flag)
            {
                printf("%s", MENU_INPUT);
                continue;
            }
            output = solve_quad(coefficients_values[0], coefficients_values[1], coefficients_values[2]);
            answers_output(output);
            printf("%s", MENU_INPUT);
        }
        else if (ch == EOF)
        {

            puts("Invalid input.");
            printf("%s", MENU_INPUT);
                continue;
        }
        else
        {
            puts("Invalid input.");
            printf("%s", MENU_INPUT);
            while (getchar() != '\n')
                continue;
        }
    }
    printf("Bye.");
    return 0;
}

struct solve_output solve_quad (double a_s, double b_s, double c_s)
{
    struct solve_output solve_quad_out = {};
    double d = b_s*b_s - 4*a_s*c_s;

    if (!doublecmp(a_s, 0, EPS) && doublecmp(b_s, 0, EPS))
    {
        solve_quad_out.x1 = -c_s/b_s;
        solve_quad_out.roots_num = 1;
        solve_quad_out.is_linear = 1;
    }
    else if (!doublecmp(a_s, 0, EPS) && !doublecmp(b_s, 0, EPS) && doublecmp(c_s, 0, EPS))
        solve_quad_out.roots_num = 0;
    else if (!doublecmp(a_s, 0, EPS) && !doublecmp(b_s, 0, EPS) && !doublecmp(c_s, 0, EPS))
        solve_quad_out.roots_num = INF_ROOTS;
    else if (doublecmp(d, 0, EPS) == -1)
        solve_quad_out.roots_num = 0;
    else if (!doublecmp(d, 0, EPS))
    {
        solve_quad_out.x1 = -b_s/(2*a_s);
        solve_quad_out.roots_num = 1;
    }
    else
    {
        double d_sqrt = sqrt(d);
        solve_quad_out.x1 = (-b_s + d_sqrt)/(2*a_s);
        solve_quad_out.x2 = (-b_s - d_sqrt)/(2*a_s);
        solve_quad_out.roots_num = 2;
    }
    return solve_quad_out;
}

bool get_input(double * cfs)
{
    char coefficients_names[3] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++)
    {
        while (1)
        {
            printf("%c: ", coefficients_names[i]);
            int check = 0;
            if ((check = scanf("%lf", &cfs[i])) == 1 && getchar() == '\n')
                break;
            else if (check == -1)
            {
                return 1;
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
    return 0;
}

int doublecmp(double a, double b, double acc)
{
    double delta = a - b;
    if (fabs(delta) <= acc)
        return 0;
    else if (delta > 0)
        return 1;
    else
        return -1;
}

void answers_output(const struct solve_output console_out)
{
    if (console_out.roots_num == 2)
        printf("Equation has two roots:\n"
        "x = %lf \t x = %lf\n", console_out.x1, console_out.x2);
    else if (console_out.roots_num == 1)
    {
        if (console_out.is_linear)
            printf("Equation is linear and has one root: x = %lf\n", console_out.x1);
        else
            printf("Equation has single root: x = %lf\n", console_out.x1);
    }
    else if (console_out.roots_num == INF_ROOTS )
        printf("Equation has infinite amount of roots.\n");
    else if (!console_out.roots_num)
    {
        printf("Equation has no roots.\n");
    }
}
