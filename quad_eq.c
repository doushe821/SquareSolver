#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NAME_LENGTH 81
void solve_direct ();
int main (void)
{
    char ch;
    puts("This application solves quadratic equations.");
    puts("Type \"s\" to start solving equations, type \"q\" to exit program.");
    while ((ch = getchar()) != EOF)
    {
    if (ch == 's')
    {
        solve_direct();
        puts("Type \"s\" to continue solving equations, type \"q\" to exit program.");
    }
    else if (ch == 'q')
    {
        printf("Bye.");
        exit(0);
    }
    }
}
void solve_direct ()
{
    while (getc(stdin) != '\n')
        continue;
    double a, b, c;
    printf("Enter coefficients: ax^2 + bx + c = 0\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    double d = b*b - 4*a*c;
    if (d < 0)
        puts("Your equation has no real roots.");
    else if (d == 0)
        printf("Your equation has single root: x = %.3lf\n", -b/(2*a));
    else 
        {
            printf("Your equation has two roots:\n");
            printf("x_1 = %lf", (-b + sqrt(d))/(2*a));
            printf("\tx_2 = %lf\n", (-b - sqrt(d))/(2*a));
        }
}