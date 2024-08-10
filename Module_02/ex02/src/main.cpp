#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"
#include "../includes/test.hpp"

int main(void) {

    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Creating a Fixed instance 'a'" << RESET << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed a;

    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Creating a Fixed instance 'b' with Fixed(5.05f) * Fixed(2)" << RESET
              << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    testComparisonOperators(a, b);
    testArithmeticOperators(a, b);
    testIncrementDecrementOperators(a);
	testMinMax(a, b);
    return 0;
}