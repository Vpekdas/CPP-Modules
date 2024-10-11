#ifndef FORM_NOT_SIGNED_EXCEPTION_HPP
#define FORM_NOT_SIGNED_EXCEPTION_HPP

#include <exception>
#include <string>

class FormNotSignedException : public std::exception {
    public:
    FormNotSignedException(const std::string &formName);
    virtual const char *what() const throw();
    ~FormNotSignedException() throw();

    private:
    std::string _formName;
    std::string _errorMessage;
};

#endif // FORM_NOT_SIGNED_EXCEPTION_HPP