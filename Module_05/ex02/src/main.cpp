#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

#include "../include/colors.hpp"

int main() {
    const Bureaucrat bureaucrat("First", 1);
    const ShrubberyCreationForm form("home");
    const RobotomyRequestForm form2("RobotomyRequestForm");
    const PresidentialPardonForm form3("PresidentialPardonForm");
    try {
        form.execute(bureaucrat);
        form2.execute(bureaucrat);
        form3.execute(bureaucrat);

    } catch (std::exception &ex) {
        std::cerr << NEON_RED << ex.what() << RESET << std::endl;
    }
}