#include "../include/RPN.hpp"
#include "../include/colors.hpp"

// https://www.youtube.com/watch?v=qN8LPIcY6K4

int main(int ac, char **av) {
    if (ac != 2) {
        return 1;
    }

    try {
        RPN rpn;

        if (!rpn.parseInput(av[1])) {
            return 1;
        }

        rpn.calculate(av[1]);
    } catch (std::exception &ex) {
        std::cout << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }
}