#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << YELLOW << "🛠️ Default Fixed Constructor called 🛠️" << RESET << std::endl;
}

// Ensures a valid default state by initializing rawBits to 0.
Fixed::Fixed(const int number) {
    this->rawBits = number << fractionalBits;
    std::cout << YELLOW << "🛠️ Int Fixed Constructor called 🛠️" << RESET << std::endl;
}

// Initializes the fixed-point number using a float by scaling and rounding.
Fixed::Fixed(const float number) {
    this->rawBits = static_cast<int>(roundf(number * (1 << fractionalBits)));
    std::cout << YELLOW << "🛠️ Float Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << "🧨 Fixed Destructor called 🧨" << RESET << std::endl;
}

// Copy constructor to create a new object as a copy of an existing one.
Fixed::Fixed(const Fixed &other) {
    this->rawBits = other.rawBits;
    std::cout << YELLOW << "🖨️ Fixed Copy Constructor called 🖨️" << RESET << std::endl;
}

// Ensures proper assignment of rawBits when using the assignment operator.
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->rawBits = other.rawBits;
    }
    std::cout << YELLOW << "📞 Fixed Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

float Fixed::toFloat(void) const {
    return this->rawBits / static_cast<float>(1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}
