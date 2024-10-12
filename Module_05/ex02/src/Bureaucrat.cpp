#include "../include/Bureaucrat.hpp"
#include "../include/GradeTooHighException.hpp"
#include "../include/GradeTooLowException.hpp"
#include "../include/colors.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {
    throw GradeTooHighException(_name, _grade, BUREAUCRAT);
    std::cout << YELLOW << "🛠️ Default Bureaucrat Constructor called. 🛠️" << RESET << std::endl;
    std::cout << *this;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade) {
    if (grade > 150) {
        throw GradeTooLowException(_name, _grade, BUREAUCRAT);
    } else if (grade <= 0) {
        throw GradeTooHighException(_name, _grade, BUREAUCRAT);
    }
    std::cout << YELLOW << "🛠️ Parameterized Bureaucrat Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED << "🧨 Bureaucrat Destructor called 🧨" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << YELLOW << "🖨️ Bureaucrat Copy Constructor called 🖨️" << RESET << std::endl;
    std::cout << *this;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    // Check for self-assignment
    if (this != &other) {
        _grade = other._grade;
    }
    std::cout << YELLOW << "📞 Bureaucrat Copy Assignment Operator called 📞" << RESET << std::endl;
    std::cout << *this;

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
        throw GradeTooHighException(_name, _grade, BUREAUCRAT);
    }
    _grade--;
}
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw GradeTooLowException(_name, _grade, BUREAUCRAT);
    }
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    return out << NEON_CYAN << "👨‍💼 " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
               << RESET << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) {
    form.execute(*this);
    std::cout << BOLD_ITALIC_CYAN << "[" << getName() << "]" << CYAN << " executed " << form.getName() << "\n"
              << RESET << std::endl;
    std::cout << form;
}