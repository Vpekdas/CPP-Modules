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
            AForm *form = new ShrubberyCreationForm("Home");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 1 attempts to sign and execute a RobotomyRequestForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);
            AForm *form = new RobotomyRequestForm("Terminator");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 1 attempts to sign and execute a PresidentialPardonForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);
            AForm *form = new PresidentialPardonForm("HououinKyouma");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "A Bureaucrat with an initial grade of 150 attempts to sign and execute a "
                                  "PresidentialPardonForm after being incremented.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *form = new PresidentialPardonForm("HououinKyouma");

            for (int i = 0; i < 149; i++) {
                bureaucrat.incrementGrade();
            }

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message =
                "A grade 1 Bureaucrat attempts to sign and execute a Shrubbery Form created by an intern.";
            announcementMessage(message);
            std::cout << BLINK_BOLD_ITALIC_GREEN << "[NEW TEST]" << RESET << std::endl;

            Intern someRandomIntern;
            Bureaucrat bureaucrat("First", 1);
            AForm *form = NULL;

            try {
                form = someRandomIntern.makeForm("Shrubbery Form", "School");
                form->beSigned(bureaucrat);
                form->execute(bureaucrat);
            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            if (form != NULL)
                delete form;
        }
        {
            std::string message =
                "A grade 1 Bureaucrat attempts to sign and execute a Robotomy Form created by an intern.";
            announcementMessage(message);
            std::cout << BLINK_BOLD_ITALIC_GREEN << "[NEW TEST]" << RESET << std::endl;

            Intern someRandomIntern;
            Bureaucrat bureaucrat("First", 1);
            AForm *form;

            try {
                form = someRandomIntern.makeForm("Robotomy Form", "School");
                form->beSigned(bureaucrat);
                form->execute(bureaucrat);
            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            if (form != NULL)
                delete form;
        }
        {
            std::string message =
                "A grade 1 Bureaucrat attempts to sign and execute a Presidential Pardon Form created by an intern.";
            announcementMessage(message);
            std::cout << BLINK_BOLD_ITALIC_GREEN << "[NEW TEST]" << RESET << std::endl;

            Intern someRandomIntern;
            Bureaucrat bureaucrat("First", 1);
            AForm *form;

            try {
                form = someRandomIntern.makeForm("Presidential Pardon Form", "School");
                form->beSigned(bureaucrat);
                form->execute(bureaucrat);
            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            if (form != NULL)
                delete form;
        }
    }
    {
        std::string message = "❌ Exceptions expected. ❌";
        announcementTitle(message);
        {
            std::string message = "Bureaucrat with grade 150 attempts to sign and execute a ShrubberyCreationForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *form = new ShrubberyCreationForm("Home");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 150 attempts to sign and execute a RobotomyRequestForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *form = new RobotomyRequestForm("Terminator");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 150 attempts to sign and execute a PresidentialPardonForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Last", 150);
            AForm *form = new PresidentialPardonForm("HououinKyouma");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 145 attempts to sign and execute a ShrubberyCreationForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Not Last", 145);
            AForm *form = new ShrubberyCreationForm("Home");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 72 attempts to sign and execute a RobotomyRequestForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Middle", 72);
            AForm *form = new RobotomyRequestForm("Terminator");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Bureaucrat with grade 25 attempts to sign and execute a PresidentialPardonForm.";
            announcementMessage(message);

            Bureaucrat bureaucrat("Top tier but not First", 25);
            AForm *form = new PresidentialPardonForm("HououinKyouma");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            delete form;
        }
        {
            std::string message = "Attempting to create a ShrubberyCreationForm with an invalid grade of 0.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);

            try {
                AForm *form = new ShrubberyCreationForm();
                form->beSigned(bureaucrat);
                form->execute(bureaucrat);
                delete form;

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
        }
        {
            std::string message = "Attempting to create a RobotomyRequestForm with an invalid grade of 0.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);

            try {

                AForm *form = new RobotomyRequestForm();

                form->beSigned(bureaucrat);
                form->execute(bureaucrat);

                delete form;
            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
        }
        {
            std::string message = "Attempting to create a PresidentialPardonForm with an invalid grade of 0.";
            announcementMessage(message);

            Bureaucrat bureaucrat("First", 1);

            try {
                AForm *form = new PresidentialPardonForm();

                form->beSigned(bureaucrat);
                form->execute(bureaucrat);

                delete form;

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
            AForm *form = new PresidentialPardonForm("HououinKyouma");

            try {
                form->beSigned(bureaucrat);
                bureaucrat.executeForm(*form);

            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            if (form != NULL)
                delete form;
        }
        {
            std::string message =
                "A grade 1 Bureaucrat attempts to sign and execute an unknown Form created by an intern.";
            announcementMessage(message);
            std::cout << BLINK_BOLD_ITALIC_GREEN << "[NEW TEST]" << RESET << std::endl;

            Intern someRandomIntern;
            Bureaucrat bureaucrat("First", 1);
            AForm *form = NULL;

            try {
                form = someRandomIntern.makeForm("Unknown", "Unknown Target");
                form->beSigned(bureaucrat);
                form->execute(bureaucrat);
            } catch (std::exception &ex) {
                std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
            }
            if (form != NULL)
                delete form;
        }
    }
}

