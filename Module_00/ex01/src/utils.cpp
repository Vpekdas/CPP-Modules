#include "../includes/PhoneBook.hpp"
#include "../includes/colors.hpp"

// Command constants.
const std::string ADD_COMMAND = "ADD";
const std::string SEARCH_COMMAND = "SEARCH";
const std::string EXIT_COMMAND = "EXIT";

// Checks if the input string contains only digits.
bool onlyDigit(std::string input) {
    for (std::size_t i = 0; i < input.length(); i++)
        if (!std::isdigit(input[i])) {
            return false;
        }
    return true;
}

// Checks if the input is not empty when adding a contact.
std::string validAddField(bool digitsOnly = false) {
    std::string input;
    std::getline(std::cin, input);

    while (input.empty() || (digitsOnly && !onlyDigit(input))) {
        if (input.empty()) {
            std::cout << RED << "Error: Field cannot be empty. Please fill in the field." << RESET
                      << std::endl;
        } else if (digitsOnly && !onlyDigit(input)) {
            std::cout << RED << "Error: Please enter only digits." << RESET << std::endl;
        }
        std::getline(std::cin, input);
    }
    return input;
}

// Handles the ADD command.
void addCommand(PhoneBook &phoneBook, std::size_t &index) {
    Contact contact;
    std::cout << NCYAN << "🖊️ Enter first name 🖊️ : " << RESET;
    contact.setFirstName(validAddField());

    std::cout << NCYAN << "🖊️ Enter last name 🖊️ : " << RESET;
    contact.setLastName(validAddField());

    std::cout << NCYAN << "🆔 Enter nickname 🆔 : " << RESET;
    contact.setNickname(validAddField());

    std::cout << NCYAN << "📞 Enter phone number 📞 : " << RESET;
    contact.setPhoneNumber(validAddField(true));

    std::cout << NCYAN << "🤫 Enter darkest secret 🤫 : " << RESET;
    contact.setDarkestSecret(validAddField());

    contact.setIndex(index);
    index += 1;
    if (index > 7) {
        index = 0;
    }
    phoneBook.addContact(contact);
    std::cout << GREEN << "Contact " NGREEN << contact.getNickname() << GREEN
              << " added succesfully ✅ " << RESET << std::endl;
}

// Function that wrap all commands.
void handleCommand(const std::string &command, PhoneBook &phoneBook, std::size_t &index) {
    if (command == ADD_COMMAND) {
        addCommand(phoneBook, index);
    } else if (command == SEARCH_COMMAND) {
        phoneBook.displayContacts();
    } else if (command == EXIT_COMMAND) {
        std::cout << NCYAN << "👋 Bye bye 👋 " << RESET << std::endl;
        exit(0);
    } else {
        std::cout << RED << "Error: The program accepts only these commands: " << NRED
                  << "ADD, SEARCH, EXIT." << RESET << std::endl;
    }
}