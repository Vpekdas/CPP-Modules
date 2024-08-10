#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"

int main(void) {
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Creating Fixed a" << RESET << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed a;

    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Creating Fixed b by copying a" << RESET << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed b(a);

    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Creating Fixed c" << RESET << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed c;

    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Assigning content of b to c" << RESET << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    c = b;

    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Printing raw bits of a, b, and c" << RESET << std::endl;
    std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}