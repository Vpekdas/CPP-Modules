#include "../include/PresidentialPardonForm.hpp"
#include "../include/FormNotSignedException.hpp"
#include "../include/GradeTooLowException.hpp"
#include "../include/colors.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("") {
    std::cout << YELLOW << "🛠️ Default PresidentialPardonForm Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << YELLOW << "🛠️ Parameterized PresidentialPardonForm Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED << "🧨 PresidentialPardonForm Destructor called 🧨" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
    std::cout << YELLOW << "🖨️ PresidentialPardonForm Copy Constructor called 🖨️" << RESET << std::endl;
    std::cout << *this;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    // Check for self-assignment
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << YELLOW << "📞 PresidentialPardonForm Copy Assignment Operator called 📞" << RESET << std::endl;
    std::cout << *this;

    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > 25 || executor.getGrade() > 5) {
        throw GradeTooLowException();
    } else if (!getSigned()) {
        throw FormNotSignedException(getName());
    }

    std::cout << BOLD_ITALIC_CYAN << "[" << getTarget() << "]" << BOLD_ITALIC_BLUE
              << " has been 🙏 officially and galactically pardoned 🙏 by the one and only Zaphod Beeblebrox! 🚀✨"
              << RESET << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
    return _target;
}