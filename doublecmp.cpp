#include <math.h>
int doublecmp(double a, double b, double acc)
{
    double delta = a - b;
    if (fabs(delta) <= acc)
        return 0;
    else if (delta > 0)
        return 1;
    return (delta>0)-(delta<0);
}
