#ifndef COOL_ASSERT_H_INCLUDED
#define COOL_ASSERT_H_INCLUDED

void cool_assert(int condition_l, const char* condition_s, const char* file, const char* func, \
                 int line, const char* comment, ...);

#endif // COOL_ASSERT_H_INCLUDED
