#include "../include/ShrubberyCreationForm.hpp"
#include "../include/GradeTooLowException.hpp"
#include "../include/colors.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("") {
    std::cout << YELLOW << "🛠️ Default ShrubberyCreationForm Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << YELLOW << "🛠️ Parameterized ShrubberyCreationForm Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED << "🧨 ShrubberyCreationForm Destructor called 🧨" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
    std::cout << YELLOW << "🖨️ ShrubberyCreationForm Copy Constructor called 🖨️" << RESET << std::endl;
    std::cout << *this;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    // Check for self-assignment
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << YELLOW << "📞 ShrubberyCreationForm Copy Assignment Operator called 📞" << RESET << std::endl;
    std::cout << *this;

    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > 145 || executor.getGrade() > 137) {
        throw GradeTooLowException();
    }
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream outfile(filename);

    if (!outfile.is_open()) {
        throw std::runtime_error("Error: Failed to create the output file: " + filename);
    }

    srand(time(0));
    const int randNumber = rand() % 150;

    for (int i = 0; i < randNumber; i++)
        outfile << _tree << std::endl;
    outfile << "\nCongratulations! You have successfully planted " << randNumber
            << " 🌳 trees! 🌱 Keep up the great work!" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const {
    return _target;
}

// clang-format off
const std::string ShrubberyCreationForm::_tree = 
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"      // \\";