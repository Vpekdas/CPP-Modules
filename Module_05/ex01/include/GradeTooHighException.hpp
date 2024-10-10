#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
#define GRADE_TOO_HIGH_EXCEPTION_HPP

#include <exception>
#include <iostream>

class GradeTooHighException : public std::exception {
    public:
    // Create a parameterized too.
    virtual const char *what() const throw();
};

#endif // GRADE_TOO_HIGH_EXCEPTION_HPP