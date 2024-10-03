#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
#define GRADE_TOO_HIGH_EXCEPTION_HPP

#include <exception>
#include <iostream>

class GradeTooHighException : public std::exception {
    public:
    // Default constructor
    GradeTooHighException();

    // Default Destructor
    ~GradeTooHighException();
};

#endif // GRADE_TOO_HIGH_EXCEPTION_HPP