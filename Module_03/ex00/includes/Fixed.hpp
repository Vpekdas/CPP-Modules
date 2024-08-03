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
    // Default Constructor
    Fixed();

    // Destructor
    ~Fixed();

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator overload.
    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int rawBits;
    static const int fractionalBits = 8;
};

#endif