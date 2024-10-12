#ifndef INTERN_HPP
#define INTERN_HPP

#include "../include/FormDoesNotExistException.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>

typedef AForm *(*FormCreator)(const std::string &target);
#define FORM_NUMBER 3

struct FormTypeMapping {
    std::string formName;
    FormCreator creator;
};

class Intern {
    public:
    // Default constructor
    Intern();

    // Copy Constructor
    Intern(const Intern &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Intern &operator=(const Intern &other);

    // Default Destructor
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif // INTERN_HPP
