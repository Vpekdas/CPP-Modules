#include "../include/GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(const std::string &name, int grade, ErrorType type) {
    std::string typeName = "Unknown";
    std::ostringstream oss;
    for (int i = 0; i < SIZE; i++) {
        if (typeMappings[i].type == type) {
            typeName = typeMappings[i].typeName;
            break;
        }
    }

    if (type == DECREMENT) {
        oss << typeName << " Error: '" << name << "' grade (" << grade
            << ") is too loq after decrement. The grade must be at most 150." << std::endl;
    } else {
        oss << typeName << " Error: '" << name << "' grade (" << grade << ") is too low. The grade must be at most 150."
            << std::endl;
    }

    _errorMessage = oss.str();
}

const char *GradeTooLowException::what() const throw() {
    return _errorMessage.c_str();
}

GradeTooLowException::~GradeTooLowException() throw() {
}