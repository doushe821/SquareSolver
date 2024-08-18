#include <math.h>
#include "overflow_check_double.h"
#include "solve_quad.h" '
#include "doublecmp.h"

bool overflow_check_double (double value_ofc)
{
    if (value_ofc == INFINITY || value_ofc == -INFINITY || value_ofc == NAN)
        return true;
    else
        return false;
}
