#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/colors.hpp"
#include <iomanip>

void announcementTitle(std::string &message) {
    std::cout << "\n" << NEON_BLUE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_YELLOW << message << RESET << std::endl;
    std::cout << NEON_BLUE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

void announcementMessage(std::string &message) {
    std::cout << "\n" << NEON_PURPLE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_GREEN << message << RESET << std::endl;
    std::cout << NEON_PURPLE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

int main() {
    srand(time(0));

    Bureaucrat bureaucrat("First", 1);
    AForm *ShrubberyForm = new ShrubberyCreationForm("Home");
    AForm *RobotomyForm = new RobotomyRequestForm("Terminator");
    AForm *PresidentialForm = new PresidentialPardonForm("President");

    try {
        ShrubberyForm->beSigned(bureaucrat);
        bureaucrat.executeForm(*ShrubberyForm);

        RobotomyForm->beSigned(bureaucrat);
        bureaucrat.executeForm(*RobotomyForm);

        PresidentialForm->beSigned(bureaucrat);
        bureaucrat.executeForm(*PresidentialForm);

    } catch (std::exception &ex) {
        std::cerr << NEON_RED << ex.what() << RESET << std::endl;
    }
    delete ShrubberyForm;
    delete RobotomyForm;
    delete PresidentialForm;
}