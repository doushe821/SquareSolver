#ifndef UNIT_TEST_H_INCLUDED
#define UNIT_TEST_H_INCLUDED

struct test_data
{
    double a, b, c;
    double x1ref, x2ref;
    int nRoots;
};

const double EPS_CL = 1E-5;

bool RunTest(struct test_data test, int test_num);
void get_f_test_data();

#endif
