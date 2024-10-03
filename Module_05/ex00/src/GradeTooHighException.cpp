#include "../includes/GradeTooHighException.hpp"

const char *GradeTooHighException::what() const throw() {
    return "Error: Grade is too high !";
}