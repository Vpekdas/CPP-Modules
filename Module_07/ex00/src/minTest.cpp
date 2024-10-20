#include "../include/colors.hpp"
#include "../include/display.hpp"
#include "../include/whatever.hpp"

void minTest(bool skip) {
    std::string title = "Running tests on the min template function.";
    announcementTitle(title);
    {
        std::string message = "Testing max function with INT values.";
        announcementMessage(message);
        displayPressButton(skip);

        int a = +42;
        int b = -24;
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
        std::cout << BOLD_ITALIC_PINK << "Returning the minimum value..." << RESET << std::endl;
        std::cout << CYAN << "Minimum value is: " << ::min(a, b) << RESET << std::endl;
    }
    {
        std::string message = "Testing max function with CHAR values.";
        announcementMessage(message);
        displayPressButton(skip);

        char a = 'S';
        char b = 'G';
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
        std::cout << BOLD_ITALIC_PINK << "Returning the minimum value..." << RESET << std::endl;
        std::cout << CYAN << "Minimum value is: " << ::min(a, b) << RESET << std::endl;
    }
    {
        std::string message = "Testing max function with STRING values.";
        announcementMessage(message);
        displayPressButton(skip);

        std::string a = "Steins";
        std::string b = "Gate";
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
        std::cout << BOLD_ITALIC_PINK << "Returning the minimum value..." << RESET << std::endl;
        std::cout << CYAN << "Minimum value is: " << ::min(a, b) << RESET << std::endl;
    }
    {
        std::string message = "Testing max function with FLOAT values.";
        announcementMessage(message);
        displayPressButton(skip);

        float a = -42.42f;
        float b = +24.24f;

        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
        std::cout << BOLD_ITALIC_PINK << "Returning the minimum value..." << RESET << std::endl;
        std::cout << CYAN << "Minimum value is: " << ::min(a, b) << RESET << std::endl;
    }
}