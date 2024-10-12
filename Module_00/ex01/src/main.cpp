#include "../include/PhoneBook.hpp"
#include "../include/colors.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;
    std::size_t index = 0;

    std::cout << NEON_CYAN << "Available commands: ADD, SEARCH, EXIT" << RESET << std::endl;
    while (true) {
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            return 0;
        }
        handleCommand(command, phoneBook, index);
    }
    return 0;
}