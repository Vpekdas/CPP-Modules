#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
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

    std::cout << CYAN << "\n🩵 [CYAN] represents the Bureaucrat's name.\n"
              << YELLOW << "💛 [YELLOW] represents the target's name." << RESET << std::endl;

    {
        std::string message = "✅ No exceptions expected. ✅";
        announcementTitle(message);
        {
            std::string message = "Bureaucrat with grade 1 attempts to sign and execute a ShrubberyCreationForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);
            AForm *ShrubberyForm = new ShrubberyCreationForm("Home");

            try {
                ShrubberyForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*ShrubberyForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete ShrubberyForm;
        }
        {
            std::string message = "Bureaucrat with grade 1 attempts to sign and execute a RobotomyRequestForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);
            AForm *RobotomyForm = new RobotomyRequestForm("Terminator");

            try {
                RobotomyForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*RobotomyForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete RobotomyForm;
        }
        {
            std::string message = "Bureaucrat with grade 1 attempts to sign and execute a PresidentialPardonForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);
            AForm *PresidentialForm = new PresidentialPardonForm("HououinKyouma");

            try {
                PresidentialForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*PresidentialForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete PresidentialForm;
        }
        {
            std::string message = "A Bureaucrat with an initial grade of 150 attempts to sign and execute a "
                                  "PresidentialPardonForm after being incremented.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *PresidentialForm = new PresidentialPardonForm("HououinKyouma");

            for (int i = 0; i < 149; i++) {
                bureaucrat.incrementGrade();
            }

            try {
                PresidentialForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*PresidentialForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete PresidentialForm;
        }
    }
    {
        std::string message = "❌ Exceptions expected. ❌";
        announcementTitle(message);
        {
            std::string message = "Bureaucrat with grade 150 attempts to sign and execute a ShrubberyCreationForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *ShrubberyForm = new ShrubberyCreationForm("Home");

            try {
                ShrubberyForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*ShrubberyForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete ShrubberyForm;
        }
        {
            std::string message = "Bureaucrat with grade 150 attempts to sign and execute a RobotomyRequestForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *RobotomyForm = new RobotomyRequestForm("Terminator");

            try {
                RobotomyForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*RobotomyForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete RobotomyForm;
        }
        {
            std::string message = "Bureaucrat with grade 150 attempts to sign and execute a PresidentialPardonForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *PresidentialForm = new PresidentialPardonForm("HououinKyouma");

            try {
                PresidentialForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*PresidentialForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete PresidentialForm;
        }
        {
            std::string message = "Bureaucrat with grade 145 attempts to sign and execute a ShrubberyCreationForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Not Last", 145);
            AForm *ShrubberyForm = new ShrubberyCreationForm("Home");

            try {
                ShrubberyForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*ShrubberyForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete ShrubberyForm;
        }
        {
            std::string message = "Bureaucrat with grade 72 attempts to sign and execute a RobotomyRequestForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Middle", 72);
            AForm *RobotomyForm = new RobotomyRequestForm("Terminator");

            try {
                RobotomyForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*RobotomyForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete RobotomyForm;
        }
        {
            std::string message = "Bureaucrat with grade 25 attempts to sign and execute a PresidentialPardonForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Top tier but not First", 25);
            AForm *PresidentialForm = new PresidentialPardonForm("HououinKyouma");

            try {
                PresidentialForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*PresidentialForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete PresidentialForm;
        }
        {
            std::string message = "Attempting to create a ShrubberyCreationForm with an invalid grade of 0.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);

            try {
                AForm *ShrubberyForm = new ShrubberyCreationForm();
                ShrubberyForm->beSigned(bureaucrat);
                ShrubberyForm->execute(bureaucrat);
                delete ShrubberyForm;

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
        }
        {
            std::string message = "Attempting to create a RobotomyRequestForm with an invalid grade of 0.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);

            try {

                AForm *RobotomyForm = new RobotomyRequestForm();

                RobotomyForm->beSigned(bureaucrat);
                RobotomyForm->execute(bureaucrat);

                delete RobotomyForm;
            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
        }
        {
            std::string message = "Attempting to create a PresidentialPardonForm with an invalid grade of 0.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);

            try {
                AForm *PresidentialForm = new PresidentialPardonForm();

                PresidentialForm->beSigned(bureaucrat);
                PresidentialForm->execute(bureaucrat);

                delete PresidentialForm;

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
        }
        {
            std::string message = "A Bureaucrat with an initial grade of 1 attempts to sign and execute a "
                                  "PresidentialPardonForm after being decremented.";

            announcementMessage(message);

            Bureaucrat bureaucrat("Was First", 1);

            for (int i = 0; i < 20; i++) {
                bureaucrat.decrementGrade();
            }
            AForm *PresidentialForm = new PresidentialPardonForm("HououinKyouma");

            try {
                PresidentialForm->beSigned(bureaucrat);
                bureaucrat.executeForm(*PresidentialForm);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete PresidentialForm;
        }
    }
    {
        Intern someRandomIntern;
        Bureaucrat bureaucrat("First", 1);
        AForm *rrf;

        try {
            rrf = someRandomIntern.makeForm("Robotomy Form", "Bender");
            rrf->beSigned(bureaucrat);
            rrf->execute(bureaucrat);
        } catch (std::exception &ex) {
            std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
        }
        delete rrf;
    }
}