#include "../include/Fixed.hpp"
#include "../include/colors.hpp"

int main(void) {
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed 'a'" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed a;

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed 'b' with integer constructor (10)" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const b(10);

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed 'c' with float constructor (42.42f)" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const c(42.42f);

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed 'd' by copying 'b'" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const d(b);

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed 'b' with integer constructor (-42)" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const e(-42);

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating Fixed 'c' with float constructor (-42.42f)" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    Fixed const f(-42.42f);

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN
              << "Assigning a new Fixed value to 'a' with float constructor "
                 "(1234.4321f)"
              << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;

    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Converting Fixed values to integers" << RESET << std::endl;
    std::cout << NEON_PURPLE << "------------------------------------------" << RESET << std::endl;
    a = Fixed(1234.4321f);
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "e is " << e.toInt() << " as integer" << std::endl;
    std::cout << "f is " << e.toInt() << " as integer" << std::endl;
    return 0;
}