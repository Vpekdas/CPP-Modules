#include "../include/FormNotSignedException.hpp"

FormNotSignedException::FormNotSignedException(const std::string &formName) : _formName(formName) {
    _errorMessage = "Error: " + _formName + " has not been signed !";
}

const char *FormNotSignedException::what() const throw() {
    return _errorMessage.c_str();
}

FormNotSignedException::~FormNotSignedException() throw() {
}