#include "../include/colors.hpp"
#include "../include/whatever.hpp"

void swapTest() {
    std::string message = "SWAP";
    announcementTitle(message);
    {
        std::string message = "INT";
        announcementMessage(message);

        int a = +42;
        int b = -24;
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;

        std::cout << BOLD_ITALIC_PINK << "Swapping..." << RESET << std::endl;
        ::swap(a, b);
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
    }
    {
        std::string message = "CHAR";
        announcementMessage(message);

        char a = 'S';
        char b = 'G';
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;

        std::cout << BOLD_ITALIC_PINK << "Swapping..." << RESET << std::endl;
        ::swap(a, b);
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
    }
    {
        std::string message = "STRING";
        announcementMessage(message);

        std::string a = "Steins";
        std::string b = "Gate";
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;

        std::cout << BOLD_ITALIC_PINK << "Swapping..." << RESET << std::endl;
        ::swap(a, b);
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
    }
    {
        std::string message = "FLOAT";
        announcementMessage(message);

        float a = -42.42f;
        float b = +24.24f;
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;

        std::cout << BOLD_ITALIC_PINK << "Swapping..." << RESET << std::endl;
        ::swap(a, b);
        std::cout << CYAN << "a = " << a << " | b = " << b << RESET << std::endl;
    }
}