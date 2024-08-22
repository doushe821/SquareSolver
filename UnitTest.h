#ifndef UNITTEST_H_INCLUDED
#define UNITTEST_H_INCLUDED

struct TestData{
    double a, b, c;
    double x1ref, x2ref;
    int nRoots;
};

const int NUMBER_OF_TESTS = 25;

int RunTest(struct TestData test[]);

#endif // UNITTEST_H_INCLUDED
