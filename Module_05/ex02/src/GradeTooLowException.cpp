#include "../include/GradeTooLowException.hpp"

const char *GradeTooLowException::what() const throw() {
    return "Error: Grade is too low !";
}