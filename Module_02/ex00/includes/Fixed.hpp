#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed();
    ~Fixed();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int raw);

  private:
    int _rawBits;
    static const int _fractionalBits = 8;
};

#endif