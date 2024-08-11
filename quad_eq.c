#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void solve_direct ();
double get_input(char k);
int main (void)
{
    char ch = '0';
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
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    printf("Enter coefficients: ax^2 + bx + c = 0\n");
    a = get_input('a');
    b = get_input('b');
    c = get_input('c');
    d = b*b - 4*a*c;
    if (d < 0)
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
double get_input(char k)
{
    double v = 0;
    char miss_input = '0';
    while(1)
    {
        printf("%c: ", k);
        if (scanf("%lf", &v) && getchar() == '\n')
            break;
        else
        {
            while((miss_input = getchar()) != '\n')
                printf("%c", miss_input);
            printf(" is not a number, try again.\n");
        }    }
    return(v);
}