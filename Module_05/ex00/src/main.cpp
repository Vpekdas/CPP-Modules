#include "../include/Bureaucrat.hpp"
#include "../include/colors.hpp"

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
            {

                std::string message = "Creating a Bureaucrat with an initial grade of 1 and performing 149 decrements.";
                announcementMessage(message);

                Bureaucrat bureaucrat("First", 1);

                try {
                    for (int i = 0; i < 149; i++) {
                        bureaucrat.decrementGrade();
                    }
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
                std::cout << BOLD_ITALIC_ORANGE << "After decrements: " << bureaucrat;
            }

            {
                std::string message =
                    "Creating a Bureaucrat with an initial grade of 150 and performing 149 increments.";
                announcementMessage(message);

                Bureaucrat bureaucrat("Last", 150);

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
    }
    {
        std::string message = "❌ Exceptions expected. ❌";
        announcementTitle(message);
        {
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
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
            {
                std::string message = "Creating a Bureaucrat with an initial grade of 151.";
                announcementMessage(message);

                try {
                    Bureaucrat bureaucrat("Too too roo!", 151);
                } catch (std::exception &ex) {
                    std::cerr << NEON_RED << ex.what() << RESET << std::endl;
                }
            }
        }
    }
}
