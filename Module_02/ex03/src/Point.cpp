#include "../includes/Point.hpp"
#include "../includes/colors.hpp"

Point::Point() : x(0), y(0) {
    // std::cout << "🛠️ Default Point Constructor called 🛠️" << std::endl;
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {
    // std::cout << "🛠️ Parameterized Point Constructor called 🛠️" << std::endl;
}

Point::~Point() {
    // std::cout << RED << "🧨 Point Destructor called 🧨" << RESET << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
    // std::cout << YELLOW << "🖨️ Point Copy Constructor called 🖨️" << RESET << std::endl;
}

Point &Point::operator=(const Point &other) {
    (void)other;
    // std::cout << YELLOW << "📞 Point Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

Fixed const &Point::getX() const {
    return this->x;
}

Fixed const &Point::getY() const {
    return this->y;
}

Fixed area(const Point &a, const Point &b, const Point &c) {
    Fixed result;

    // Calculate the area using the determinant method to handle fixed-point arithmetic.
    result = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) +
              c.getX() * (a.getY() - b.getY())) /
             Fixed(2.0f);

    if (result < 0) {
        result = result * -1;
    }
    return result;
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    return (totalArea == (area1 + area2 + area3));
}