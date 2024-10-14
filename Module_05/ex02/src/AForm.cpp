#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/GradeTooHighException.hpp"
#include "../include/GradeTooLowException.hpp"
#include "../include/colors.hpp"

AForm::AForm() : _name(""), _signed(false), _gradeToSign(0), _gradeToExecute(0) {
    throw GradeTooHighException(_name, _gradeToSign, FORM);
    std::cout << YELLOW << "🛠️ Default AForm Constructor called 🛠️" << RESET << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    _signed = false;
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException(name, (gradeToSign > 150) ? gradeToSign : gradeToExecute, FORM);
    } else if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException(name, (gradeToSign < 1) ? gradeToSign : gradeToExecute, FORM);
    }
    std::cout << YELLOW << "🛠️ Parameterized AForm Constructor called 🛠️" << RESET << std::endl;
}

AForm::~AForm() {
    std::cout << RED << "🧨 AForm Destructor called 🧨" << RESET << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
    std::cout << YELLOW << "🖨️ AForm Copy Constructor called 🖨️" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    // Check for self-assignment
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << YELLOW << "📞 AForm Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

const std::string &AForm::getName() const {
    return _name;
}
bool AForm::getSigned() const {
    return _signed;
}
int AForm::getGradeToSign() const {
    return _gradeToSign;
}
int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    std::cout << BOLD_ITALIC_CYAN << "[" << bureaucrat.getName() << "]" << BOLD_ITALIC_ORANGE
              << " is attempting to sign the form.\n"
              << *this << RESET << std::endl;
    if (bureaucrat.getGrade() <= _gradeToSign && !_signed) {
        _signed = true;
        std::cout << BOLD_ITALIC_GREEN << "Form ✅ successfully ✅ signed." << RESET << std::endl;
    } else {
        std::cout << BOLD_ITALIC_RED << "❌ Failed ❌ to sign the form." << RESET << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform) {
    out << NEON_ORANGE << std::setfill('-') << std::setw(42) << RESET << std::endl;
    out << BOLD_ITALIC_ORANGE << std::setfill(' ') << std::setw(28) << Aform.getName() << " INFO" << RESET << std::endl;

    out << "🆔 AForm name: '" << BOLD_ITALIC_WHITE << Aform.getName() << "'\n";
    if (!Aform.getSigned()) {
        out << RED;
    } else {
        out << GREEN;
    }
    out << "📜 AForm signed: '" << Aform.getSigned() << "'\n"
        << WHITE << "🖋️  Grade needed to sign: '" << BOLD_ITALIC_WHITE << Aform.getGradeToSign() << "'\n"
        << WHITE << "🏃 Grade needed to execute: '" << BOLD_ITALIC_WHITE << Aform.getGradeToExecute() << "'" << RESET
        << std::endl;

    out << NEON_ORANGE << std::setfill('-') << std::setw(42) << RESET << std::endl;
    return out;
}
