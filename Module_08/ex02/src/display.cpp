#include "../include/display.hpp"
#include "../include/colors.hpp"

// Display a formatted message with decorative borders.
void announcementTitle(const std::string &title) {
    std::cout << "\n" << NEON_BLUE << std::setfill('-') << std::setw(title.length() + 3) << RESET << std::endl;
    std::cout << NEON_YELLOW << title << RESET << std::endl;
    std::cout << NEON_BLUE << std::setfill('-') << std::setw(title.length()) << "\n" << RESET << std::endl;
}

void announcementMessage(const std::string &message) {
    std::cout << "\n" << NEON_PURPLE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_GREEN << message << RESET << std::endl;
    std::cout << NEON_PURPLE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

void stringToLower(std::string &input) {
    for (std::size_t i = 0; i < input.length(); i++) {
        input[i] = std::tolower(input[i]);
    }
}

void displayPressButton(bool skip) {
    if (!skip) {
        std::string input;

        std::cout << BLINK_BOLD_ITALIC_YELLOW << "Press Enter to proceed to the next step of the test." << RESET
                  << std::endl;

        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << NEON_YELLOW << "👋 Bye Bye ! 👋" << RESET << std::endl;
            return;
        }
    }
}