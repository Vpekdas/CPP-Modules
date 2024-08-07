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

    // Comparison operators to allow Fixed objects to be compared.
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators to allow Fixed objects to be added, subtracted, multiplied, and divided.
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment and decrement operators to allow Fixed objects to be incremented and decremented.
    Fixed &operator++();   // Prefix increment
    Fixed operator++(int); // Postfix increment
    Fixed &operator--();   // Prefix decrement
    Fixed operator--(int); // Postfix decrement

    // Utility functions to find the minimum and maximum of two Fixed objects.
    static Fixed &min(Fixed &nb1, Fixed &nb2);
    static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
    static Fixed &max(Fixed &nb1, Fixed &nb2);
    static const Fixed &max(const Fixed &nb1, const Fixed &nb2);

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int _rawBits;
    static const int _fractionalBits = 8;
};

// Overloads the << operator to output the fixed-point number
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP