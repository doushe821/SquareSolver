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
double temp_value;
double a;
double b;
double c;
bool eof_flag;
bool quit_flag;
};

struct solve_output solve_quad (double a_s, double b_s, double c_s);

struct check_input get_abc ();

struct check_input get_input_double (void);

int doublecmp(double a, double b, double acc);

struct check_input user_menu ();

void answers_output(const struct solve_output answers);

int main (void)
{
    puts("This application solves quadratic equations.");
    printf("%s", MENU_INPUT);
    while (1)
    {
        struct check_input coefficients_values = user_menu();
        if (coefficients_values.quit_flag == true)
            break;
        struct solve_output output = solve_quad(coefficients_values.a, coefficients_values.b, coefficients_values.c);
        answers_output(output);
        printf("%s", MENU_INPUT);
    }
    printf("Bye.");
    return 0;
}

struct check_input user_menu ()
{
    int ch = 0;
    struct check_input user_menu_input = {};
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
            user_menu_input = get_abc();
            if (user_menu_input.eof_flag)
            {
                printf("%s%s", INVALID_IN, MENU_INPUT);
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

struct solve_output solve_quad (double a_s, double b_s, double c_s)
{
    struct solve_output solve_quad_out = {};
    double d = b_s*b_s - 4*a_s*c_s;

    if (doublecmp(a_s, 0, EPS) == 0 && doublecmp(b_s, 0, EPS) != 0)
    {
        solve_quad_out.x1 = -c_s/b_s;
        solve_quad_out.roots_num = 1;
        solve_quad_out.is_linear = 1;
    }
    else if (doublecmp(a_s, 0, EPS) == 0 && doublecmp(b_s, 0, EPS) == 0)
        if (doublecmp(c_s, 0, EPS) != 0)
            solve_quad_out.roots_num = 0;
        else
            solve_quad_out.roots_num = INF_ROOTS;
    else if (doublecmp(d, 0, EPS) == -1)
        solve_quad_out.roots_num = 0;
    else if (doublecmp(d, 0, EPS) == 0)
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

struct check_input get_abc()
{
    char coefficients_names[3] = {'a', 'b', 'c'};
    struct check_input get_abc_input = {};
    double cfs[3] = {};
    for (int i = 0; i < 3; i++)
    {
        struct check_input abc_check = {};
        printf("%c: ", coefficients_names[i]);
        abc_check = get_input_double();
        if (abc_check.eof_flag == true)
            return abc_check;
        cfs[i] = abc_check.temp_value;
    }
    get_abc_input.a = cfs[0];
    get_abc_input.b = cfs[1];
    get_abc_input.c = cfs[2];
    return get_abc_input;
}

struct check_input get_input_double(void)
{
    struct check_input user_input = {};
    while (1)
    {
        int check = 0;
        if ((check = scanf("%lf", &user_input.temp_value)) == 1 && getchar() == '\n')
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
    switch (answers.roots_num)
    {
        case 2:
        {
            printf("Equation has two roots:\n"
            "x = %lf \t x = %lf\n", answers.x1, answers.x2);
            break;
        }
        case 1:
        {
            if (answers.is_linear)
                printf("Equation is linear and has one root: x = %lf\n", answers.x1);
            else
                printf("Equation has single root: x = %lf\n", answers.x1);
            break;
        }
        case INF_ROOTS:
        {
            printf("Equation has infinite amount of roots.\n");
            break;
        }
        case 0:
        {
            printf("Equation has no roots.\n");
            break;
        }
        default:
            abort();
    }
}
