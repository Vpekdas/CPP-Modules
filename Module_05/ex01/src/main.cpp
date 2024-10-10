#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include "../include/colors.hpp"
#include <exception>
#include <iomanip>
#include <iostream>

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
    {
        std::string message = "✅ No exceptions expected. ✅";
        announcementTitle(message);
        {
            std::string message = "Bureaucrat Tests";
            announcementTitle(message);
            {

                std::string message = "Creating a Bureaucrat with an initial grade of 1 and performing 149 decrements.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);
                std::cout << bureaucrat;

                try {
                    for (int i = 0; i < 149; i++) {
                        bureaucrat.decrementGrade();
                    }
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
                std::cout << BOLD_ITALIC_ORANGE << "After decrements: " << bureaucrat << RESET;
            }

            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 150 and performing 149 increments.";
                announcementMessage(message);

                Bureaucrat bureaucrat("Last", 150);
                std::cout << bureaucrat;

                try {
                    for (int i = 0; i < 149; i++) {
                        bureaucrat.incrementGrade();
                    }
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
                std::cout << BOLD_ITALIC_ORANGE << "After increments: " << bureaucrat;
            }
        }

        {
            std::string message = "Form Tests.";
            announcementTitle(message);
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 1 and attempting to sign a form "
                                      "that requires a grade of 1.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);
                std::cout << bureaucrat;

                Form form("Form First", 1, 1);
                std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form;

                try {
                    bureaucrat.signForm(form);
                    std::cout << form;
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 1 and attempting to sign a form "
                                      "that requires a grade of 150.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);
                std::cout << bureaucrat;

                Form form("Form Last", 150, 150);
                std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form;

                try {
                    bureaucrat.signForm(form);
                    std::cout << form;
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 150 and try to sign a form which "
                                      "require grade 150.";
                announcementMessage(message);

                Bureaucrat bureaucrat("Last", 150);
                std::cout << bureaucrat;

                Form form("Form Last", 150, 150);
                std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form;

                try {
                    bureaucrat.signForm(form);
                    std::cout << form;
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 150, incrementing 149 times and "
                                      "try to sign a form which "
                                      "require grade 1.";
                announcementMessage(message);

                Bureaucrat bureaucrat("Last", 150);
                std::cout << bureaucrat;

                Form form("Form First", 1, 1);
                std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form;

                for (int i = 0; i < 149; i++) {
                    bureaucrat.incrementGrade();
                }
                std::cout << BOLD_ITALIC_ORANGE << "After decrements: " << bureaucrat;

                try {
                    bureaucrat.signForm(form);
                    std::cout << form;
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
        }
    }
    {
        std::string message = "❌ Exceptions expected. ❌";
        announcementTitle(message);
        {
            std::string message = "Bureaucrat Tests.";
            announcementTitle(message);
            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 1 and attempting to increment the grade.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);
                try {
                    bureaucrat.incrementGrade();
                    bureaucrat.incrementGrade();
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 150 and attempting to decrement the grade.";
                announcementMessage(message);

                Bureaucrat bureaucrat("Last", 150);
                try {
                    bureaucrat.decrementGrade();
                    bureaucrat.decrementGrade();
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 0.";
                announcementMessage(message);

                try {
                    Bureaucrat bureaucrat;
                    std::cout << bureaucrat;
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 151.";
                announcementMessage(message);

                try {
                    Bureaucrat bureaucrat("Too too roo!", 151);
                    std::cout << bureaucrat;
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
        }
        {
            std::string message = "Form Tests.";
            announcementTitle(message);
            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 1 and attempting to create a form with grade 0.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);

                try {
                    Form form;
                    std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form << RESET
                              << std::endl;

                    bureaucrat.signForm(form);

                    std::cout << bureaucrat;
                    std::cout << form;

                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 1 and attempting to create a form with grade 151.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);

                try {
                    Form form("Form Outbound", 151, 151);
                    std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form << RESET
                              << std::endl;

                    bureaucrat.signForm(form);

                    std::cout << bureaucrat;
                    std::cout << form;

                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 150 and attempting to sign a form with grade 1.";
                announcementMessage(message);

                Bureaucrat bureaucrat("Last", 150);
                std::cout << bureaucrat;

                Form form("Form High Grade", 1, 1);
                std::cout << BOLD_ITALIC_ORANGE << "Before attempting to sign the form " << form;

                try {
                    bureaucrat.signForm(form);

                    std::cout << bureaucrat;
                    std::cout << form;

                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
        }
    }
}