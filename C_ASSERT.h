#ifndef C_ASSERT_H_INCLUDED
#define C_ASSERT_H_INCLUDED

#include <stdlib.h>
#include <stdarg.h>
#include "vibrant_print.h"
#include "cool_assert.h"

#ifdef NDEBUG
#define c_assert
#else
#define c_assert(condition, comment, ...) cool_assert(condition, #condition, __FILE__, \
                                                      __func__, __LINE__, comment, ##__VA_ARGS__)
#endif

#endif
