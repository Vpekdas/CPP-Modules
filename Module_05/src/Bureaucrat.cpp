#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {
    std::cout << YELLOW << "🛠️ Default Bureaucrat Constructor called 🛠️" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade) {
    std::cout << YELLOW << "🛠️ Parameterized Bureaucrat Constructor called 🛠️" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED << "🧨 Bureaucrat Destructor called 🧨" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << YELLOW << "🖨️ Bureaucrat Copy Constructor called 🖨️" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    // Check for self-assignment
    if (this != &other) {
        _grade = other._grade;
    }
    std::cout << YELLOW << "📞 Bureaucrat Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}