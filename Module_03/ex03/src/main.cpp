#include "../includes/Point.hpp"
#include "../includes/colors.hpp"

int main() {

    // Initialize Fixed objects with specific float values.
    const Fixed fixedX1(20.0f);
    const Fixed fixedY1(0.0f);

    const Fixed fixedX2(-5.0f);
    const Fixed fixedY2(4.0f);

    const Fixed fixedX3(10.0f);
    const Fixed fixedY3(10.0f);

    const Fixed fixedX4(10.0f);
    const Fixed fixedY4(10.0f);

    // Convert Fixed objects to float.
    const float x1 = fixedX1.toFloat();
    const float y1 = fixedY1.toFloat();

    const float x2 = fixedX2.toFloat();
    const float y2 = fixedY2.toFloat();

    const float x3 = fixedX3.toFloat();
    const float y3 = fixedY3.toFloat();

    const float x4 = fixedX4.toFloat();
    const float y4 = fixedY4.toFloat();

    // Create Point objects using float values
    const Point a(x1, y1);
    const Point b(x2, y2);
    const Point c(x3, y3);
    const Point p(x4, y4);

    if (bsp(a, b, c, p)) {
        std::cout << NGREEN << "Point is in triangle" << RESET << std::endl;
    } else {
        std::cout << NRED << "Point is not in triangle" << RESET << std::endl;
    }
    return 0;
}

// https://www.youtube.com/watch?v=H9qu9Xptf-w
// https://www.youtube.com/watch?v=HYAgJN3x4GA
// hanks to these videos !