#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
    public:
    // Default constructor
    ShrubberyCreationForm();

    // Parameterized constructor
    ShrubberyCreationForm(const std::string &target);

    // Copy Constructor
    ShrubberyCreationForm(const ShrubberyCreationForm &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    // Default Destructor
    ~ShrubberyCreationForm();

    const std::string &getTarget() const;

    void execute(Bureaucrat const &executor) const;

    void beSigned(Bureaucrat &bureaucrat);

    private:
    const std::string _target;
    static const std::string _tree;
};

#endif // SHRUBBERY_CREATION_FORM_HPP