#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "iostream"
#include <cstddef>
#include <string>

std::string validAddField() {
    std::string input;
    std::getline(std::cin, input);

    while (input.empty()) {
        std::cout << RED << "Error: Field cannot be empty. Please fill in the field." RESET
                  << std::endl;
        std::getline(std::cin, input);
    }
    return (input);
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    std::size_t index = 0;
    while (true) {
        std::getline(std::cin, command);
        if (command == "ADD") {
            Contact contact;
            std::cout << BCYAN "🖊️ Enter first name 🖊️ : " RESET;
            contact.setFirstName(validAddField());

            std::cout << BCYAN "🖊️ Enter last name 🖊️ : " RESET;
            contact.setLastName(validAddField());

            std::cout << BCYAN "🆔 Enter nickname 🆔 : " RESET;
            contact.setNickname(validAddField());

            std::cout << BCYAN "📞 Enter phone number 📞 : " RESET;
            contact.setPhoneNumber(validAddField());

            std::cout << BCYAN "🤫 Enter darkest secret 🤫 : " RESET;
            contact.setDarkestSecret(validAddField());

            contact.setIndex(index);
            index += 1;
            if (index > 7) {
                index = 0;
            }
            phoneBook.addContact(contact);
            std::cout << GREEN "Contact " BGREEN << contact.getNickname()
                      << GREEN " added succesfully ✅ " RESET << std::endl;
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
        } else if (command == "EXIT") {
			std::cout << BCYAN "👋 Bye bye 👋 " << std::endl;
            return 0;
        } else {
            std::cout << RED << "Error: The program accepts only these commands: "
                      << BRED "ADD, SEARCH, EXIT." RESET << RESET << std::endl;
        }
    }
    return 0;
}