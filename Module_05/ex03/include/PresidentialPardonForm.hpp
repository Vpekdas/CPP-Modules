#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
    public:
    // Default constructor
    PresidentialPardonForm();

    // Parameterized constructor
    PresidentialPardonForm(const std::string &target);

    // Copy Constructor
    PresidentialPardonForm(const PresidentialPardonForm &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    // Default Destructor
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;

    const std::string &getTarget() const;

    private:
    const std::string _target;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP