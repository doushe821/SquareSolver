#ifndef COOL_ASSERT_H
#define COOL_ASSERT_H
#include <stdio.h>
#include <stdlib.h>
#include "square_solver_io.h"

#define c_assert (condition) if(!condition)fprintf(stderr, "Assertion failed: #condition. %s -> %s -> %d",\
                                file_name, func_name, line_n)

#endif

