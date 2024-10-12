#ifndef EXECUTE_GRADE_TOO_LOW_EXCEPTION_HPP
#define EXECUTE_GRADE_TOO_LOW_EXCEPTION_HPP

#include <exception>
#include <sstream>
#include <string>

class ExecuteGradeTooLowException : public std::exception {
    public:
    ExecuteGradeTooLowException(const std::string &formName, int bureaucratGrade, int executeGrade);
    virtual const char *what() const throw();
    ~ExecuteGradeTooLowException() throw();

    private:
    std::string _errorMessage;
};

#endif // EXECUTE_GRADE_TOO_LOW_EXCEPTION_HPP