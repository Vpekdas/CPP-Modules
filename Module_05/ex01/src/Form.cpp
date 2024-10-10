#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/GradeTooHighException.hpp"
#include "../include/GradeTooLowException.hpp"
#include "../include/colors.hpp"
#include <iomanip>

Form::Form() : _name(""), _signed(false), _gradeToSign(0), _gradeToExecute(0) {
    throw GradeTooHighException();
    std::cout << YELLOW << "🛠️ Default Form Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    _signed = false;
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    } else if (gradeToSign <= 0 || gradeToExecute <= 0) {
        throw GradeTooHighException();
    }
    std::cout << YELLOW << "🛠️ Parameterized Form Constructor called 🛠️" << RESET << std::endl;
    std::cout << *this;
}

Form::~Form() {
    std::cout << RED << "🧨 Form Destructor called 🧨" << RESET << std::endl;
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
    std::cout << YELLOW << "🖨️ Form Copy Constructor called 🖨️" << RESET << std::endl;
    std::cout << *this;
}

Form &Form::operator=(const Form &other) {
    // Check for self-assignment
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << YELLOW << "📞 Form Copy Assignment Operator called 📞" << RESET << std::endl;
    std::cout << *this;

    return *this;
}

const std::string &Form::getName() const {
    return _name;
}
bool Form::getSigned() const {
    return _signed;
}
int Form::getGradeToSign() const {
    return _gradeToSign;
}
int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToExecute) {
        _signed = true;
    } else {
        std::cout << BOLD_ITALIC_CYAN << "[" << bureaucrat.getName() << "]" << BOLD_ITALIC_RED << " could not sign "
                  << BOLD_ITALIC_CYAN << "[" << getName() << "]" << BOLD_ITALIC_RED << " because their grade ("
                  << bureaucrat.getGrade() << ") is lower than the required grade (" << getGradeToSign() << ") ❌"
                  << RESET << std::endl;
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "\n" << NEON_ORANGE << std::setfill('-') << std::setw(42) << RESET << std::endl;
    out << BOLD_ITALIC_ORANGE << std::setfill(' ') << std::setw(22) << "FORM INFO" << RESET << std::endl;
    out << "🆔 Form name: '" << BOLD_ITALIC_WHITE << form.getName() << "'\n";
    if (!form.getSigned()) {
        out << RED;
    } else {
        out << GREEN;
    }
    out << "📜 Form signed: '" << form.getSigned() << "'\n"
        << WHITE << "🖋️  Grade needed to sign: '" << BOLD_ITALIC_WHITE << form.getGradeToSign() << "'\n"
        << WHITE << "🏃 Grade needed to execute: '" << BOLD_ITALIC_WHITE << form.getGradeToExecute() << "'" << RESET
        << std::endl;

    out << NEON_ORANGE << std::setfill('-') << std::setw(42) << RESET << std::endl;
    return out;
}