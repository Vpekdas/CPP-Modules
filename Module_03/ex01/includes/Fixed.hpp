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

  private:
    int rawBits;
    static const int fractionalBits = 8;
};

// Declaration of the << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP