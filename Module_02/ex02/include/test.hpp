#ifndef TEST_HPP
#define TEST_HPP

#include "../include/Fixed.hpp"

void testComparisonOperators(const Fixed &a, const Fixed &b);
void testArithmeticOperators(const Fixed &a, const Fixed &b);
void testIncrementDecrementOperators(Fixed &a);
void testMinMax(const Fixed &a, const Fixed &b);
#endif // TEST_HPP