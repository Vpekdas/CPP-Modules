#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

int main() {
    // TODO: Code a snippet to display an explaining message with format.
    {
        Bureaucrat bureaucrat("First", 1);
        try {
        } catch (std::exception &ex) {
            std::cerr << NEON_CYAN << bureaucrat << NEON_RED << ex.what() << RESET << std::endl;
        }
    }
    {
        Bureaucrat bureaucrat("Last", 150);
        try {
        } catch (std::exception &ex) {
            std::cerr << NEON_CYAN << bureaucrat << NEON_RED << ex.what() << RESET << std::endl;
        }
    }
    {
        Bureaucrat bureaucrat("First", 1);
        try {
            bureaucrat.incrementGrade();
            bureaucrat.incrementGrade();
        } catch (std::exception &ex) {
            std::cerr << NEON_CYAN << bureaucrat << NEON_RED << ex.what() << RESET << std::endl;
        }
    }
    {
        Bureaucrat bureaucrat("Last", 150);
        try {
            bureaucrat.decrementGrade();
            bureaucrat.decrementGrade();
        } catch (std::exception &ex) {
            std::cerr << NEON_CYAN << bureaucrat << NEON_RED << ex.what() << RESET << std::endl;
        }
    }
    {
        Bureaucrat bureaucrat;
        try {
            bureaucrat.incrementGrade();
        } catch (std::exception &ex) {
            std::cerr << NEON_CYAN << bureaucrat << NEON_RED << ex.what() << RESET << std::endl;
        }
    }
}