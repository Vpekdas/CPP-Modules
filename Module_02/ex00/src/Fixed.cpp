#include "../include/Fixed.hpp"
#include "../include/colors.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << YELLOW << "🛠️ Default Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << "🧨 Fixed Deconstructor called 🧨" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    _rawBits = other._rawBits;
    std::cout << BLUE << "🖨️  Fixed Copy Constructor called 🖨️" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    std::cout << GREEN << "📞 Fixed Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << CYAN << "🔍 getRawBits member function called 🔍" << RESET << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int raw) {
    _rawBits = raw;
}
