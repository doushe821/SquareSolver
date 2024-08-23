#ifndef C_ASSERT_H_INCLUDED
#define C_ASSERT_H_INCLUDED

#include "vibrant_print.h"
#include <stdlib.h>

#define c_assert(x, comment)\
if(!(x))\
{vibrant_print(red, stderr, "Assertion failed ("comment"): "#x". %s -> %s -> %d", __FILE__, __func__, __LINE__);\
abort();}

#endif
