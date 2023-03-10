#ifndef __MATHEMATICS__
#define __MATHEMATICS__

#define MATHEMATICS_FLOAT_PRECISION 0.00000001

#include <stdbool.h>

bool mathematics_equals(const float number1, const float number2);

unsigned long long mathematics_absolute_value(const long long number);

unsigned long long mathematics_pow(unsigned long long base, unsigned long long exponent);

/**
 * @brief Calculates the nth root of a number using Heron's method.
 *
 * @param number
 * @param nth_root
 * @return float
 */
float mathematics_root(float number, unsigned int nth_root);

float mathematics_square_root(float number);

unsigned long long mathematics_factorial(unsigned long long number);

#endif
