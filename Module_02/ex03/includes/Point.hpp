#ifndef POINT_HPP
#define POINT_HPP

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // LIBRARIES //      +   +   +   +   +   +  //
// -----------------------------------------------------------------------------//

#include "../includes/Fixed.hpp"
#include <iostream>

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // CLASS //     +   +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

class Point {
  public:
    Point(const float x, const float y);
    ~Point();
    Point(const Point &other);
    Point &operator=(const Point &other);

    const Fixed &getX() const;
    const Fixed &getY() const;

  private:
    const Fixed x;
    const Fixed y;
};

// Calculates the area of the triangle formed by three points, used for geometric computations.
Fixed area(const Point &a, const Point &b, const Point &c);

bool isInside(const Point &a, const Point &b, const Point &c, const Point &p);

#endif // POINT_HPP