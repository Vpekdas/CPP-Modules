#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << YELLOW << "🛠️ Default Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << "🧨 Fixed Deconstructor called 🧨" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    this->rawBits = other.rawBits;
    std::cout << BLUE << "🖨️  Fixed Copy Constructor called 🖨️" << RESET << std::endl;
}

// Ensures proper assignment of rawBits when using the assignment operator.
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->rawBits = other.rawBits;
    }
    std::cout << GREEN << "📞 Fixed Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << CYAN << "🔍 getRawBits member function called 🔍" << RESET << std::endl;
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}
