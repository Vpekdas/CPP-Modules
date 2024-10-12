#include "../include/FormNotSignedException.hpp"

FormNotSignedException::FormNotSignedException(const std::string &formName, int bureaucratGrade, int signGrade)
    : _formName(formName) {
    std::ostringstream oss;
    oss << "Error: " << _formName << " has not been signed because bureaucrat grade (" << bureaucratGrade
        << ") is lower than the required grade (" << signGrade << ")." << std::endl;
    _errorMessage = oss.str();
}

const char *FormNotSignedException::what() const throw() {
    return _errorMessage.c_str();
}

FormNotSignedException::~FormNotSignedException() throw() {
}