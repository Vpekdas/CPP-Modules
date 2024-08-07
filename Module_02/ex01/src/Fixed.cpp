#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << YELLOW << "🛠️ Default Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::Fixed(const int number) {
    _rawBits = number << _fractionalBits;
    std::cout << YELLOW << "🛠️ Int Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::Fixed(const float number) {
    _rawBits = static_cast<int>(roundf(number * (1 << _fractionalBits)));
    std::cout << YELLOW << "🛠️ Float Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << "🧨 Fixed Destructor called 🧨" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    _rawBits = other._rawBits;
    std::cout << YELLOW << "🖨️ Fixed Copy Constructor called 🖨️" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    std::cout << YELLOW << "📞 Fixed Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

// Convert the fixed-point value to a floating-point number
// by dividing by 2^fractionalBits.
float Fixed::toFloat(void) const {
    return _rawBits / static_cast<float>(1 << _fractionalBits);
}

// Convert the fixed-point value to an integer
// to allow for operations and comparisons in integer arithmetic.
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// Output the fixed-point value as a floating-point number
// to provide a human-readable representation of the value.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}
