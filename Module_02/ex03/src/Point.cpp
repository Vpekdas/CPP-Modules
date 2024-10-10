#include "../include/Point.hpp"
#include "../include/colors.hpp"

Point::Point() : _x(0), _y(0) {
    // std::cout << "🛠️ Default Point Constructor called 🛠️" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
    // std::cout << "🛠️ Parameterized Point Constructor called 🛠️" << std::endl;
}

Point::~Point() {
    // std::cout << RED << "🧨 Point Destructor called 🧨" << RESET << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
    // std::cout << YELLOW << "🖨️ Point Copy Constructor called 🖨️" << RESET << std::endl;
}

Point &Point::operator=(const Point &other) {
    (void)other;
    // std::cout << YELLOW << "📞 Point Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

Fixed const &Point::getX() const {
    return _x;
}

Fixed const &Point::getY() const {
    return _y;
}

bool bsp(Point const &A, Point const &B, Point const &C, Point const &P) {

    float s1 = C.getY().toFloat() - A.getY().toFloat();
    float s2 = C.getX().toFloat() - A.getX().toFloat();
    float s3 = B.getY().toFloat() - A.getY().toFloat();
    float s4 = P.getY().toFloat() - A.getY().toFloat();

    float w1 = (A.getX().toFloat() * s1 + s4 * s2 - P.getX().toFloat() * s1) /
               (s3 * s2 - (B.getX().toFloat() - A.getX().toFloat()) * s1);
    float w2 = (s4 - w1 * s3) / s1;

    return w1 > 0 && w2 > 0 && (w1 + w2) < 1;
}

// Thanks to this video
// https://www.youtube.com/watch?v=HYAgJN3x4GA&list=PLFt_AvWsXl0cD2LPxcjxVjWTQLxJqKpgZ