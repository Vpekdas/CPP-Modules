#include "../include/ScalarConverter.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << NEON_RED << "Error: Exactly one argument is required. Usage: ./program_name <value_to_convert>"
                  << RESET << std::endl;
        return 0;
    }

    std::string input = av[1];
    if (input.empty()) {
        std::cerr << NEON_RED << "Error: The provided argument is empty." << RESET << std::endl;
        return 0;
    }

    ScalarConverter::convert(input);
}