#include "../include/Intern.hpp"
#include "../include/colors.hpp"

AForm *createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

static const FormTypeMapping formTypeMappings[] = {{"Shrubbery Form", createShrubberyCreationForm},
                                                   {"Robotomy Form", createRobotomyRequestForm},
                                                   {"Presidential Pardon Form", createPresidentialPardonForm}};

Intern::Intern() {
    std::cout << YELLOW << "🛠️ Default Intern Constructor called 🛠️" << RESET << std::endl;
}

Intern::~Intern() {
    std::cout << RED << "🧨 Intern Destructor called 🧨" << RESET << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << YELLOW << "🖨️ Intern Copy Constructor called 🖨️" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 Intern Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {

    for (int i = 0; i < FORM_NUMBER; i++) {
        if (formTypeMappings[i].formName == formName) {
            return formTypeMappings[i].creator(target);
        }
    }
    throw FormDoesNotExistException(formName);
}