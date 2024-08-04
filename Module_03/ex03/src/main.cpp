#include "../includes/Point.hpp"
#include "../includes/colors.hpp"

int main() {

    // Initialize Fixed objects with specific float values.
    Fixed fixedX1(20.0f);
    Fixed fixedY1(0.0f);

    Fixed fixedX2(-5.0f);
    Fixed fixedY2(4.0f);

    Fixed fixedX3(10.0f);
    Fixed fixedY3(10.0f);

    Fixed fixedX4(10.0f);
    Fixed fixedY4(10.0f);

    // Convert Fixed objects to float.
    float x1 = fixedX1.toFloat();
    float y1 = fixedY1.toFloat();

    float x2 = fixedX2.toFloat();
    float y2 = fixedY2.toFloat();

    float x3 = fixedX3.toFloat();
    float y3 = fixedY3.toFloat();

    float x4 = fixedX4.toFloat();
    float y4 = fixedY4.toFloat();

    // Create Point objects using float values
    Point a(x1, y1);
    Point b(x2, y2);
    Point c(x3, y3);
    Point p(x4, y4);

    if (isInside(a, b, c, p)) {
        std::cout << NGREEN << "Point is in triangle" << RESET << std::endl;
    } else {
        std::cout << NRED << "Point is not in triangle" << RESET << std::endl;
    }
    return 0;
}