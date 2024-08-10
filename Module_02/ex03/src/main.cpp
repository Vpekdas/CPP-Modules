#include "../includes/Point.hpp"
#include "../includes/colors.hpp"

int main() {
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Edge." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(0, 0);
        Point b(20, 0);
        Point c(10, 30);
        Point to_check(10, 0);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Point of the triangle." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(0, 0);
        Point b(20, 0);
        Point c(10, 30);
        Point to_check(10, 30);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Edge with floats." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(10.2, 15.6);
        Point b(20.55, 15.6);
        Point c(15.78, 42.42);
        Point to_check(13.8, 15.6);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Point of the triangle with floats." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(10.2, 15.6);
        Point b(20.55, 15.6);
        Point c(15.78, 42.42);
        Point to_check(15.78, 42.42);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Point inside the triangle (1)." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(10.2, 15.6);
        Point b(20.55, 15.6);
        Point c(15.78, 42.42);
        Point to_check(15.78, 41.42);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Point inside the triangle (2)." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(10.2, 15.6);
        Point b(20.55, 15.6);
        Point c(15.78, 42.42);
        Point to_check(15.78, 39.42);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Point inside the triangle (3)." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(10.2, 15.6);
        Point b(20.55, 15.6);
        Point c(15.78, 42.42);
        Point to_check(12.28, 16.6);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    {
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        std::cout << NGREEN << "Point inside the triangle (4)." << RESET << std::endl;
        std::cout << NPURPLE << "------------------------------------------" << RESET << std::endl;
        Point a(10.2, 15.6);
        Point b(20.55, 15.6);
        Point c(15.78, 42.42);
        Point to_check(19.54, 16.7);

        if (bsp(a, b, c, to_check))
            std::cout << NGREEN << "Inside" << std::endl;
        else
            std::cout << NRED << "Not Inside" << std::endl;
    }
    return 0;
}