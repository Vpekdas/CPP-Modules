#include "../include/Fixed.hpp"
#include "../include/colors.hpp"

void testComparisonOperators(const Fixed &a, const Fixed &b) {
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Testing comparison operators" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;

    // Test <
    if (a < b) {
        std::cout << CYAN << a << " is less than " << b << RESET << std::endl;
    } else {
        std::cout << CYAN << a << " is not less than " << b << RESET << std::endl;
    }

    // Test <=
    if (a <= b) {
        std::cout << CYAN << a << " is less than or equal to " << b << RESET << std::endl;
    } else {
        std::cout << CYAN << a << " is not less than or equal to " << b << RESET << std::endl;
    }

    // Test >
    if (a > b) {
        std::cout << CYAN << a << " is greater than " << b << RESET << std::endl;
    } else {
        std::cout << CYAN << a << " is not greater than " << b << RESET << std::endl;
    }

    // Test >=
    if (a >= b) {
        std::cout << CYAN << a << " is greater than or equal to " << b << RESET << std::endl;
    } else {
        std::cout << CYAN << a << " is not greater than or equal to " << b << RESET << std::endl;
    }

    // Test ==
    if (a == b) {
        std::cout << CYAN << a << " is equal to " << b << RESET << std::endl;
    } else {
        std::cout << CYAN << a << " is not equal to " << b << RESET << std::endl;
    }

    // Test !=
    if (a != b) {
        std::cout << CYAN << a << " is not equal to " << b << RESET << std::endl;
    } else {
        std::cout << CYAN << a << " is equal to " << b << RESET << std::endl;
    }
}

void testArithmeticOperators(const Fixed &a, const Fixed &b) {
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Testing arithmetic operators" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;

    // Test +
    Fixed resultAdd = a + b;
    std::cout << CYAN << a << " + " << b << " = " << resultAdd << RESET << std::endl;

    // Test -
    Fixed resultSub = a - b;
    std::cout << CYAN << a << " - " << b << " = " << resultSub << RESET << std::endl;

    // Test *
    Fixed resultMul = a * b;
    std::cout << CYAN << a << " * " << b << " = " << resultMul << RESET << std::endl;

    // Test /
    if (b != 0) {
        Fixed resultDiv = a / b;
        std::cout << CYAN << a << " / " << b << " = " << resultDiv << RESET << std::endl;
    } else {
        std::cout << CYAN << "Division by zero is not allowed" << RESET << std::endl;
    }
}

void testIncrementDecrementOperators(Fixed &a) {
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Testing increment and decrement operators" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;

    // Test pre-increment
    std::cout << CYAN << "Pre-increment: ++a = " << ++a << RESET << std::endl;

    // Test post-increment
    std::cout << CYAN << "Post-increment: a++ = " << a++ << " (after increment: " << a << ")" << RESET << std::endl;

    // Test pre-decrement
    std::cout << CYAN << "Pre-decrement: --a = " << --a << RESET << std::endl;

    // Test post-decrement
    std::cout << CYAN << "Post-decrement: a-- = " << a-- << " (after decrement: " << a << ")" << RESET << std::endl;
}

void testMinMax(const Fixed &a, const Fixed &b) {
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Testing min and max functions." << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;

    // Test non-const min
    const Fixed &minResult = Fixed::min(a, b);
    std::cout << CYAN << "min(a, b) = " << minResult << RESET << std::endl;

    // Test const min
    const Fixed &constMinResult = Fixed::min(static_cast<const Fixed &>(a), static_cast<const Fixed &>(b));
    std::cout << CYAN << "const min(a, b) = " << constMinResult << RESET << std::endl;

    // Test non-const max
    const Fixed &maxResult = Fixed::max(a, b);
    std::cout << CYAN << "max(a, b) = " << maxResult << RESET << std::endl;

    // Test const max
    const Fixed &constMaxResult = Fixed::max(static_cast<const Fixed &>(a), static_cast<const Fixed &>(b));
    std::cout << CYAN << "const max(a, b) = " << constMaxResult << RESET << std::endl;
}