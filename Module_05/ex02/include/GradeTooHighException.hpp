#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
#define GRADE_TOO_HIGH_EXCEPTION_HPP

#include "../include/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <sstream>

class GradeTooHighException : public std::exception {
    public:
    GradeTooHighException(const std::string &name, int grade, ErrorType type);
    virtual const char *what() const throw();
    ~GradeTooHighException() throw();

    private:
    std::string _errorMessage;
    std::string _type;
};

#endif // GRADE_TOO_HIGH_EXCEPTION_HPP