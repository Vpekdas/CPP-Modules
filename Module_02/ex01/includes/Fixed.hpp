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

    // Allows initialization with an integer
    Fixed(const int number);

    // Allows initialization with a float
    Fixed(const float number);

    ~Fixed();

    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);

    float toFloat(void) const;
    int toInt(void) const;

  private:
    // Stores the fixed-point number value
    int rawBits;
    // Number of fractional bits for fixed-point representation
    static const int fractionalBits = 8;
};

// Overloads the << operator to output the fixed-point number
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP