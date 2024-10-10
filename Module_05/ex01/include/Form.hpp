#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
    public:
    // Default constructor
    Form();

    // Parameterized constructor
    Form(const std::string &name, const int gradeToSign, const int gradeToExecute);

    // Copy Constructor
    Form(const Form &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Form &operator=(const Form &other);

    // Default Destructor
    ~Form();

    const std::string &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat &bureaucrat);

    private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // FORM_HPP