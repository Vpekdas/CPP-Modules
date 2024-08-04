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
    // Default Constructor
    Fixed();

    // Int Constructor
    Fixed(const int number);

    // Float Constructor
    Fixed(const float number);

    // Destructor
    ~Fixed();

    // Copy Constructor
    Fixed(const Fixed &other);

    // Copy Assignment Operator
    Fixed &operator=(const Fixed &other);

    // Converts the Fixed-point value to a floating-point value
    float toFloat(void) const;

    // Converts the fixed-point value to an integer value
    int toInt(void) const;

    // Overloads the comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Overload the arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Overload the increment and decrement operators

    // Prefix/Postfix increment
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    // Return a reference to the smallest fixed point.
    static Fixed &min(Fixed &nb1, Fixed &nb2);

    // Return a reference to the smallest constant fixed point.
    static const Fixed &min(const Fixed &nb1, const Fixed &nb2);

    // Return a reference to the greated fixed point.
    static Fixed &max(Fixed &nb1, Fixed &nb2);

    // Return a reference to the greatest constant fixed point.
    static const Fixed &max(const Fixed &nb1, const Fixed &nb2);

    // Getter for the raw bits of the fixed point number
    int getRawBits(void) const;

    // Setter for the raw bits of the fixed point number
    void setRawBits(int const raw);

  private:
    int rawBits;
    static const int fractionalBits = 8;
};

// Declaration of the << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP