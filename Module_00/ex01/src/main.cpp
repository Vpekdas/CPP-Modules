#include "../includes/PhoneBook.hpp"
#include "../includes/colors.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;
    std::size_t index = 0;

    std::cout << NCYAN << "Available commands: ADD, SEARCH, EXIT" << RESET << std::endl;
    while (true) {
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            return 0;
        }
        handleCommand(command, phoneBook, index);
    }
    return 0;
}