#include <math.h>
#include <stdio.h>
#include "solve_quad.h"
#include "UnitTest.h"
#include "doublecmp.h"

const double EPS5 = 1E-5;

int RunTest(struct TestData test[])
{
    struct solve_output test_output = {};
    int errors[NUMBER_OF_TESTS] = {};
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        test_output = solve_quad(test[i].a, test[i].b, test[i].c);
        if (test_output.roots_num != test[i].nRoots || doublecmp(test_output.x1, test[i].x1ref, EPS5) != 0 || doublecmp(test_output.x2, test[i].x2ref, EPS5) != 0)
        {
            printf("Expected: %d, %lg, %lg. Got: %d, %lg, %lg.\n", test[i].nRoots, test[i].x1ref, test[i].x2ref, test_output.roots_num, \
            test_output.x1, test_output.x2);
            errors[i] = 1;
        }
        printf("Test %d: %d\n", i+1, errors[i]);
    }
    printf("Errors:\n");
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        printf("%d, ", errors[i]);
    }
}
