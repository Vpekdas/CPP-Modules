#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    public:
    // Default constructor
    Bureaucrat();

    // Parameterized constructor
    Bureaucrat(const std::string &name, const int grade);

    // Copy Constructor
    Bureaucrat(const Bureaucrat &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Bureaucrat &operator=(const Bureaucrat &other);

    // Default Destructor
    ~Bureaucrat();

    private:
    const std::string _name;
    int _grade;
};

#endif // BUREAUCRAT_HPP