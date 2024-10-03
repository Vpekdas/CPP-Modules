#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
    public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);

    // Converts the fixed-point value to a floating-point number
    // to allow for operations and comparisons in floating-point arithmetic.
    float toFloat(void) const;

    // Converts the fixed-point value to an integer
    // to allow for operations and comparisons in integer arithmetic.
    int toInt(void) const;

    private:
    int _rawBits;
    static const int _fractionalBits = 8;
};

// Overloads the << operator to output the fixed-point number
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP