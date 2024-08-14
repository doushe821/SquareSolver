#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

const char MENU_INPUT[]= "Type \"s\" to start solving equations, type \"q\" to exit program.\n";
const char INVALID_IN[]= "Invalid input\n";
const double EPS = 1E-12;
const int INF_ROOTS = -1;

struct solve_output{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct check_input{
double value;
bool eof_flag;
};

struct solve_output solve_quad (double a_s, double b_s, double c_s);

bool get_abc (double * cfs);

struct check_input get_input_double (void);

int doublecmp(double a, double b, double acc);

bool menu (double * abc_values);

void answers_output(const struct solve_output answers);

int main (void)
{
    puts("This application solves quadratic equations.");
    printf("%s", MENU_INPUT);
    double coefficients_values[3] = {};
    struct solve_output output = {};
    while (!menu(coefficients_values))
    {
        output = solve_quad(coefficients_values[0], coefficients_values[1], coefficients_values[2]);
        answers_output(output);
        printf("%s", MENU_INPUT);
    }
    printf("Bye.");
    return 0;
}

bool menu (double * abc_values)
{
    int ch = 0;
    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
        {
            printf("%s%s", INVALID_IN, MENU_INPUT);
            continue;
        }
        if (ch == 's' && getc(stdin) == '\n')
        {
            printf("Enter coefficients: ax^2 + bx + c = 0\n");
            bool eof_flag = get_abc(abc_values);
            if (eof_flag)
            {
                printf("%s%s", INVALID_IN, MENU_INPUT);
                continue;
            }
            return 0;
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
    return 1;
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

bool get_abc(double * cfs)
{
    char coefficients_names[3] = {'a', 'b', 'c'};
    struct check_input processed_input = {};
    for (int i = 0; i < 3; i++)
    {
        printf("%c: ", coefficients_names[i]);
        processed_input = get_input_double();
        if (processed_input.eof_flag == 1)
            return 1;
        cfs[i] = processed_input.value;
    }
    return 0;
}

struct check_input get_input_double(void)
{
    struct check_input user_input = {};
    while (1)
    {
        int check = 0;
        if ((check = scanf("%lf", &user_input.value)) == 1 && getchar() == '\n')
            break;
        else if (check == -1)
        {
            user_input.eof_flag = 1;
            return user_input;
        }
        else
        {
            int miss_input = 0;
            while ((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a number, try again.\n");
        }
    }
    return user_input;
}

int doublecmp(double a, double b, double acc)
{
    double delta = a - b;
    if (fabs(delta) <= acc)
        return 0;
    else if (delta > 0)
        return 1;
    return (delta>0)-(delta<0);
}

void answers_output(const struct solve_output answers)
{
    if (answers.roots_num == 2)
        printf("Equation has two roots:\n"
        "x = %lf \t x = %lf\n", answers.x1, answers.x2);
    else if (answers.roots_num == 1)
    {
        if (answers.is_linear)
            printf("Equation is linear and has one root: x = %lf\n", answers.x1);
        else
            printf("Equation has single root: x = %lf\n", answers.x1);
    }
    else if (answers.roots_num == INF_ROOTS )
        printf("Equation has infinite amount of roots.\n");
    else if (!answers.roots_num)
    {
        printf("Equation has no roots.\n");
    }
}
