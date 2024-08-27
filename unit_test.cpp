#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "vibrant_print.h"
#include "command_line_io.h"
#include "square_solver_io.h"
#include "solve_quad.h"
#include "doublecmp.h"
#include "s_gets.h"
#include "unit_test.h"

//--------------------------------------------------------------------------------------------------------------
//! Runs unit test.
//!
//! @param [in] test Massive of TestData structures. Contains a, b and c coefficients, reference roots and
//! number of roots.
//!
//! @param [in] test_eps Minimal distance between numbers. Used to compare reference roots with calculated ones.
//--------------------------------------------------------------------------------------------------------------

bool RunTest(struct test_data test, int test_num)
{
    struct solve_output_quad test_output = {};
    test_output = solve_quad(test.a, test.b, test.c);
    if (test_output.roots_num != test.nRoots || doublecmp(test_output.x1, test.x1ref, EPS_CL) != 0
        || doublecmp(test_output.x2, test.x2ref, EPS_CL) != 0)
    {
        printf("Test %d:", test_num);
        vibrant_print(red, stdout, "Expected: %lg, %lg, %d. Got: %lg, %lg, %d. ", test.x1ref,
                      test.x2ref, test.nRoots, test_output.x1, test_output.x2, test_output.roots_num);
                      return true;
    }
    return false;
}

//--------------------------------------------------------------------------------------------------------------
//! Gets .scv file with test_data lines.
//!
//! @return Massive of test_data structures.
//--------------------------------------------------------------------------------------------------------------

void get_f_test_data()
{
    struct test_data f_data= {};
    char fileName[FILENAME_MAX] = {};
    printf("Input file name:");
    s_gets(fileName, FILENAME_MAX);
    FILE* inputFile = fopen(fileName, "r");

    if (inputFile == NULL)
    {
        vibrant_print(red, stderr, "%s\n", strerror(errno));
        printf("\n%s", MENU_INPUT);
    }
    int i = 0;
    while(fscanf(inputFile, "%lg,%lg,%lg,%lg,%lg,%d", &f_data.a, &f_data.b, &f_data.c,
                                                      &f_data.x1ref, &f_data.x2ref, &f_data.nRoots) == 6)
    {
        if (RunTest(f_data, i+1))
            i++;
        else
        continue;
    }
    printf("%d errors\n", i);
}
