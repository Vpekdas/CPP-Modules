#include "../include/FormDoesNotExistException.hpp"

FormDoesNotExistException::FormDoesNotExistException(const std::string &formName) {
    std::ostringstream oss;

    oss << "Error: " << formName << " does not exists." << std::endl;
    _errorMessage = oss.str();
}

const char *FormDoesNotExistException::what() const throw() {
    return _errorMessage.c_str();
}

FormDoesNotExistException::~FormDoesNotExistException() throw() {
}