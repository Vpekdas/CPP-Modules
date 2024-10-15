#include "../include/ScalarConverter.hpp"

int main(int ac, char **av) {
    //TODO: Add some cerr message.

    if (ac != 2) {
        return 0;
    }

    std::string input = av[1];
    if (input.empty()) {
        return 0;
    }

    ScalarConverter::convert(input);
}