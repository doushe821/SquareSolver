#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct v_c {
    double value;
    int eof_check;
};
void solve_direct ();
void get_input(char k, struct v_c * user_input);
int main (void)
{
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
            solve_direct();
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
            while(getchar() != '\n')
                continue;
        }
    }
}
void solve_direct ()
{
    struct v_c input_check = {0, 0};
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    printf("Enter coefficients: ax^2 + bx + c = 0\n"
    "Press \"Ctrl+Z\" to return to menu.\n");
    get_input('a', &input_check);
    if (input_check.eof_check == -1)
    {
        printf("Returning to menu.\n");
        return 0;
    }
    else
        a = input_check.value;
    get_input('b', &input_check);
    if (input_check.eof_check == -1)
    {
        printf("Returning to menu.\n");
        return 0;
    }
    else
        b = input_check.value;
    get_input('c', &input_check);
    if (input_check.eof_check == -1)
    {
        printf("Returning to menu.\n");
        return 0;
    }
    else
        c = input_check.value;
        d = b*b - 4*a*c;
    if (a == 0 && b != 0)
        printf("Your equation is linear and has single root: %.12lf.\n", -c/b);
    else if (a == 0 && b == 0 && c != 0)
        puts("Your equation has no variable and no roots.");
    else if (a == 0 && b == 0 && c == 0)
        puts("Your equation has infinite amount of roots.");
    else if (d < 0)
        puts("Your equation has no real roots.");
    else if (d == 0)
        printf("Your equation has single root: x = %.12lf\n", -b/(2*a));
    else
    {
        d = sqrt(b*b - 4*a*c);
        printf("Your equation has two roots:\n");
        printf("x_1 = %.12lf", (-b + d)/(2*a));
        printf("\tx_2 = %.12lf\n", (-b - d)/(2*a));
    }
}
void get_input(char k, struct v_c * user_input)
{
    double v = 0;
    char miss_input = 0;
    int check = 0;
    while(1)
    {
        printf("%c: ", k);
        if ((check =scanf("%lf", &v)) == 1 && getchar() == '\n')
            break;
        else if (check == -1)
            break;
        else
        {
            while((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a number, try again.\n");
        }
    }
    user_input->eof_check = check;
    user_input->value = v;
}
