#include "../includes/Bureaucrat.hpp"
#include "../includes/GradeTooHighException.hpp"
#include "../includes/GradeTooLowException.hpp"
#include "../includes/colors.hpp"

// TODO: Check for int overflow.

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {
    std::cout << YELLOW << "🛠️ Default Bureaucrat Constructor called 🛠️" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade) {
    std::cout << YELLOW << "🛠️ Parameterized Bureaucrat Constructor called 🛠️" << RESET << std::endl;
    if (grade > 150) {
        throw GradeTooHighException();
    } else if (grade < 0) {
        throw GradeTooLowException();
    }
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

const std::string &Bureaucrat::getName() const {
    return _name;
}
int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade - 1 <= 0) {
        throw GradeTooHighException();
    }
    _grade--;
}
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    return out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}