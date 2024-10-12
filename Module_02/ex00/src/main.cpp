#include "../include/Fixed.hpp"
#include "../include/colors.hpp"

int main(void) {
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed a" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed a;

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed b by copying a" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed b(a);

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed c" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed c;

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Assigning content of b to c" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    c = b;

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Printing raw bits of a, b, and c" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}