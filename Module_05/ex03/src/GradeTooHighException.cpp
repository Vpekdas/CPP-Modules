#include "../include/GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(const std::string &name, int grade, ErrorType type) {
    std::string typeName = "Unknown";
    std::ostringstream oss;
    for (int i = 0; i < SIZE; i++) {
        if (typeMappings[i].type == type) {
            typeName = typeMappings[i].typeName;
            break;
        }
    }

    if (type == INCREMENT) {
        oss << typeName << " Error: '" << name << "' grade (" << grade
            << ") is too high after increment. The grade must be at least 1." << std::endl;
    } else {
        oss << typeName << " Error: '" << name << "' grade (" << grade << ") is too high. The grade must be at least 1."
            << std::endl;
    }

    _errorMessage = oss.str();
}

const char *GradeTooHighException::what() const throw() {
    return _errorMessage.c_str();
}

GradeTooHighException::~GradeTooHighException() throw() {
}