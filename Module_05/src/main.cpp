#include "../includes/colors.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("Hello exception!");
    } catch (std::exception &ex) {
        std::cout << CYAN << "Exception received: " << ex.what() << RESET << std::endl;
    }
    std::cout << CYAN << "hello" << RESET << std::endl;
}