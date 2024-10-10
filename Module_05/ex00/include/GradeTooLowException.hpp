#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
#define GRADE_TOO_LOW_EXCEPTION_HPP

#include <exception>
#include <iostream>

class GradeTooLowException : public std::exception {
    public:
    // Create a parameterized too.
    virtual const char *what() const throw();
};

#endif // GRADE_TOO_LOW_EXCEPTION_HPP