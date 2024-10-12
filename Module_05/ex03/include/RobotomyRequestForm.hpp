#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

class RobotomyRequestForm : public AForm {
    public:
    // Default constructor
    RobotomyRequestForm();

    // Parameterized constructor
    RobotomyRequestForm(const std::string &target);

    // Copy Constructor
    RobotomyRequestForm(const RobotomyRequestForm &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    // Default Destructor
    ~RobotomyRequestForm();

    const std::string &getTarget() const;

    void execute(Bureaucrat const &executor) const;

    private:
    const std::string _target;
};

#endif // ROBOTOMY_REQUEST_FORM_HPP