#include "../include/GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(const std::string &name, int grade, ErrorType type) {
    std::ostringstream oss;
    if (type == BUREAUCRAT)
        _type = "{BUREAUCRAT}";
    else if (type == FORM) {
        _type = "{FORM}";
    }
    oss << _type << " Error: '" << name << "' grade (" << grade << ") is too high. The grade must be at most 150."
        << std::endl;
    _errorMessage = oss.str();
}

const char *GradeTooHighException::what() const throw() {
    return _errorMessage.c_str();
}

GradeTooHighException::~GradeTooHighException() throw() {
}