#include "../include/Fixed.hpp"
#include "../include/colors.hpp"
#include "../include/test.hpp"

int main(void) {

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating a Fixed instance 'a'" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed a;

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating a Fixed instance 'b' with Fixed(5.05f) * Fixed(2)" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    testComparisonOperators(a, b);
    testArithmeticOperators(a, b);
    testIncrementDecrementOperators(a);
    testMinMax(a, b);
    return 0;
}