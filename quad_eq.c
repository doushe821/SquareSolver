#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct value_and_check {
    double value;
    int eof_check;
};
void solve_direct (double a_s, double b_s, double c_s);
struct value_and_check get_input (char k);
int main (void)
{
    double a = 0;
    double b = 0;
    double c = 0;
    struct value_and_check input_check = {0, 0};
    char ch = 0;
    puts("This application solves quadratic equations.");
    puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
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
            input_check = get_input('a');
            if (input_check.eof_check == -1)
            {
                printf("Returning to menu.\n");
                puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
                continue;
            }
            else
            a = input_check.value;
            input_check = get_input('b');
            if (input_check.eof_check == -1)
            {
                printf("Returning to menu.\n");
                puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
                continue;
            }
            else
                b = input_check.value;
            input_check = get_input('c');
            if (input_check.eof_check == -1)
            {
                printf("Returning to menu.\n");
                puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
                continue;
            }
            else
                c = input_check.value;
            solve_direct(a, b, c);
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
void solve_direct (double a_s, double b_s, double c_s)
{
    double d = b_s*b_s - 4*a_s*c_s;
    if (a_s == 0 && b_s != 0)
        printf("Your equation is linear and has single root: %.12lf.\n", -c_s/b_s);
    else if (a_s == 0 && b_s == 0 && c_s != 0)
        puts("Your equation has no variable and no roots.");
    else if (a_s == 0 && b_s == 0 && c_s == 0)
        puts("Your equation has infinite amount of roots.");
    else if (d < 0)
        puts("Your equation has no real roots.");
    else if (d == 0)
        printf("Your equation has single root: x = %.12lf\n", -b_s/(2*a_s));
    else
    {
        d = sqrt(b_s*b_s - 4*a_s*c_s);
        printf("Your equation has two roots:\n");
        printf("x_1 = %.12lf", (-b_s + d)/(2*a_s));
        printf("\tx_2 = %.12lf\n", (-b_s - d)/(2*a_s));
    }
}
struct value_and_check get_input(char k)
{
    struct value_and_check user_input = {0, 0};
    char miss_input = 0;
    while (1)
    {
        printf("%c: ", k);
        if ((user_input.eof_check = scanf("%lf", &user_input.value)) == 1 && getchar() == '\n')
            break;
        else if (user_input.eof_check == -1)
            break;
        else
        {
            while ((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a number, try again.\n");
        }
    }
    return user_input;
}
