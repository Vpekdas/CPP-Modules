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
    // Constructor
    Point();
    Point(const float x, const float y);

    // Destructor
    ~Point();

    // Copy Constructor
    Point(const Point &other);

    // Copy Assignment Operator
    Point &operator=(const Point &other);

    // Getters
    const Fixed &getX() const;
    const Fixed &getY() const;

  private:
    const Fixed x;
    const Fixed y;
};

// Function to calculate the area of a triangle formed by three points
Fixed area(const Point &a, const Point &b, const Point &c);

// Function to check if a point is inside the triangle formed by three points
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif // POINT_HPP