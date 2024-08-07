#ifndef POINT_HPP
#define POINT_HPP

#include "../includes/Fixed.hpp"
#include <iostream>

class Point {
  public:
    Point();
    Point(const float x, const float y);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Point(const Point &other);

    ~Point();

    Point &operator=(const Point &other);

    const Fixed &getX() const;
    const Fixed &getY() const;

  private:
    const Fixed _x;
    const Fixed _y;
};

// Determines if point p is inside the triangle formed by points a, b, and c.
// Why: Useful for geometric calculations and algorithms that need to check point inclusion within a
// triangle.
bool bsp(const Point &a, const Point &b, const Point &c, const Point &p);

#endif // POINT_HPP