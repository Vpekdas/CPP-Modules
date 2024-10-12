#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
#define GRADE_TOO_LOW_EXCEPTION_HPP

#include "../include/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <sstream>

class GradeTooLowException : public std::exception {
    public:
    GradeTooLowException(const std::string &name, int grade, ErrorType type);
    virtual const char *what() const throw();
    ~GradeTooLowException() throw();

    private:
    std::string _errorMessage;
    std::string _type;
};

#endif // GRADE_TOO_LOW_EXCEPTION_HPP