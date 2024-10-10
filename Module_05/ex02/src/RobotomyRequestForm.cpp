#include "../include/RobotomyRequestForm.hpp"
#include "../include/GradeTooLowException.hpp"
#include "../include/colors.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("") {
    std::cout << YELLOW << "🛠️ Default RobotomyRequestForm Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << YELLOW << "🛠️ Parameterized RobotomyRequestForm Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED << "🧨 RobotomyRequestForm Destructor called 🧨" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
    std::cout << YELLOW << "🖨️ RobotomyRequestForm Copy Constructor called 🖨️" << RESET << std::endl;
    std::cout << *this;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    // Check for self-assignment
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << YELLOW << "📞 RobotomyRequestForm Copy Assignment Operator called 📞" << RESET << std::endl;
    std::cout << *this;

    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > 72 || executor.getGrade() > 45) {
        throw GradeTooLowException();
    }
    std::cout << BOLD_ITALIC_PINK << "🤖 Bzzzz... Bzzzz... Bzzzz..." << RESET << std::endl;

    srand(time(0));
    const int randNumber = rand();

    if (randNumber % 2)
        std::cout << BOLD_ITALIC_CYAN << "[" << getTarget() << "]" << BOLD_ITALIC_GREEN
                  << " has been successfully 🦾🦿🔩 robotomized! 🦾🦿🔩 They are now part machine, part legend! 🤖"
                  << RESET << std::endl;
    else {
        std::cout << BOLD_ITALIC_RED << "Oh no! " << BOLD_ITALIC_CYAN << "[" << getTarget() << "]" << BOLD_ITALIC_RED
                  << " 💀 robotomization failed! 💀 Better luck next time!" << RESET << std::endl;
    }
}

const std::string &RobotomyRequestForm::getTarget() const {
    return _target;
}