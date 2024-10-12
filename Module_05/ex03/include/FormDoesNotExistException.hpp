#ifndef FORM_DOES_NOT_EXIST_EXCEPTION_HPP
#define FORM_DOES_NOT_EXIST_EXCEPTION_HPP

#include <exception>
#include <sstream>
#include <string>

class FormDoesNotExistException : public std::exception {
    public:
    FormDoesNotExistException(const std::string &formName);
    virtual const char *what() const throw();
    ~FormDoesNotExistException() throw();

    private:
    std::string _errorMessage;
};

#endif // FORM_DOES_NOT_EXIST_EXCEPTION_HPP