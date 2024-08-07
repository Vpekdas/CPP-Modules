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
    return getRawBits() / static_cast<float>(1 << _fractionalBits);
}

// Convert the fixed-point value to an integer
// to allow for operations and comparisons in integer arithmetic.
int Fixed::toInt(void) const {
    return getRawBits() >> _fractionalBits;
}

// Output the fixed-point value as a floating-point number
// to provide a human-readable representation of the value.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}

bool Fixed::operator>(const Fixed &other) const {
    return getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((getRawBits() * other.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.getRawBits() == 0) {
        std::cerr << RED << "Error: Division by zero." << RESET << std::endl;
        return Fixed();
    }

    Fixed result;
    result.setRawBits((getRawBits() << _fractionalBits) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++() {
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    _rawBits++;
    return temp;
}

Fixed &Fixed::operator--() {
    --_rawBits;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _rawBits--;
    return temp;
}

int Fixed::getRawBits(void) const {
    std::cout << CYAN << "🔍 getRawBits member function called 🔍" << RESET << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2) {
    if (nb1.getRawBits() < nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}

const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2) {
    if (nb1.getRawBits() < nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2) {
    if (nb1.getRawBits() > nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2) {
    if (nb1.getRawBits() > nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}