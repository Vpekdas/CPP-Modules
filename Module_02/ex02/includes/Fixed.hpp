#ifndef FIXED_HPP
#define FIXED_HPP

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // LIBRARIES //      +   +   +   +   +   +  //
// -----------------------------------------------------------------------------//

#include <cmath>
#include <iostream>

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // CLASS //     +   +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

class Fixed {
  public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);

    ~Fixed();
    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);

    float toFloat(void) const;

    int toInt(void) const;

    // Comparison operators to enable fixed-point number comparisons.
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators to enable fixed-point number arithmetic.
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment and decrement operators for fixed-point numbers.
    Fixed &operator++();   // Prefix increment
    Fixed operator++(int); // Postfix increment
    Fixed &operator--();   // Prefix decrement
    Fixed operator--(int); // Postfix decrement

    // Returns the smaller of two fixed-point numbers, allowing modification of the result.
    static Fixed &min(Fixed &nb1, Fixed &nb2);

    // Returns the smaller of two fixed-point numbers, without allowing modification of the result.
    static const Fixed &min(const Fixed &nb1, const Fixed &nb2);

    // Returns the larger of two fixed-point numbers, allowing modification of the result.
    static Fixed &max(Fixed &nb1, Fixed &nb2);

    // Returns the larger of two fixed-point numbers, without allowing modification of the result.
    static const Fixed &max(const Fixed &nb1, const Fixed &nb2);

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    // Stores the fixed-point number value
    int rawBits;

    // Number of fractional bits for fixed-point representation
    static const int fractionalBits = 8;
};

// Overloads the << operator to provide a convenient way to output the fixed-point number.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP