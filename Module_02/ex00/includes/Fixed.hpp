#ifndef FIXED_HPP

#define FIXED_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// LIBRARIES //		+	+	+	+ 	+	+	//
// -----------------------------------------------------------------------------//

#include <iostream>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+	+	// CLASS //		+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

class Fixed {
  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    // Stores the fixed-point number value
    int rawBits;

    // Number of fractional bits for fixed-point representation
    static const int fractionalBits = 8;
};

#endif