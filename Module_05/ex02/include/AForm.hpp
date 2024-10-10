#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    public:
    // Default constructor
    AForm();

    // Parameterized constructor
    AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);

    // Copy Constructor
    AForm(const AForm &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    AForm &operator=(const AForm &other);

    // Default Destructor
    virtual ~AForm();

    const std::string &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    virtual void execute(Bureaucrat const &executor) const = 0;

    private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // A_FORM_HPP