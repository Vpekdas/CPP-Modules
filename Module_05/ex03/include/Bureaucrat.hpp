#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../include/AForm.hpp"
#include <iostream>

enum ErrorType {
    BUREAUCRAT,
    FORM,
    INCREMENT,
    DECREMENT,
    SIZE,
};

struct ErrorTypeMapping {
    ErrorType type;
    const std::string typeName;
};

extern const ErrorTypeMapping typeMappings[];

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

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void executeForm(AForm const &form);

    private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP