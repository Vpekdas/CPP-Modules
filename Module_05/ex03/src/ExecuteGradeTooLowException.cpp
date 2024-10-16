#include "../include/ExecuteGradeTooLowException.hpp"

ExecuteGradeTooLowException::ExecuteGradeTooLowException(const std::string &formName, int bureaucratGrade,
                                                         int executeGrade) {
    std::ostringstream oss;
    oss << "Error: " << formName << " has not been executed because bureaucrat grade (" << bureaucratGrade
        << ") is lower than the required grade (" << executeGrade << ")." << std::endl;
    _errorMessage = oss.str();
}

const char *ExecuteGradeTooLowException::what() const throw() {
    return _errorMessage.c_str();
}

ExecuteGradeTooLowException::~ExecuteGradeTooLowException() throw() {
}