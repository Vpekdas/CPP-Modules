#include "../includes/Fixed.hpp"
#include "../includes/colors.hpp"

Fixed::Fixed() : rawBits(0) {
    std::cout << YELLOW << "🛠️ Default Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::Fixed(const int number) {
    this->rawBits = number << fractionalBits;
    std::cout << YELLOW << "🛠️ Int Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::Fixed(const float number) {
    this->rawBits = static_cast<int>(roundf(number * (1 << fractionalBits)));
    std::cout << YELLOW << "🛠️ Float Fixed Constructor called 🛠️" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << RED << "🧨 Fixed Destructor called 🧨" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    this->rawBits = other.rawBits;
    std::cout << YELLOW << "🖨️ Fixed Copy Constructor called 🖨️" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->rawBits = other.rawBits;
    }
    std::cout << YELLOW << "📞 Fixed Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

float Fixed::toFloat(void) const {
    return this->getRawBits() / static_cast<float>(1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return this->getRawBits() >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}

bool Fixed::operator>(const Fixed &other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() * other.getRawBits()) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.getRawBits() == 0) {
        std::cerr << RED << "Error: Division by zero." << RESET << std::endl;
        return Fixed();
    }

    Fixed result;
    result.setRawBits((this->getRawBits() << fractionalBits) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++() {
    ++this->rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->rawBits++;
    return temp;
}

Fixed &Fixed::operator--() {
    --this->rawBits;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->rawBits--;
    return temp;
}

int Fixed::getRawBits(void) const {
    std::cout << CYAN << "🔍 getRawBits member function called 🔍" << RESET << std::endl;
    return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
    if (raw < 0) {
        std::cerr << RED << "❌ Error: raw bits cannot be negative. ❌" << RESET << std::endl;
        return;
    }
    this->rawBits = raw;
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