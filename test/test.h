#ifndef __TEST__
#define __TEST__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool assert_string_equal(const char *actual, const char *expected);

bool assert_string_not_equal(const char *actual, const char *expected);

#endif
