#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"
#include "../includes/colors.hpp"

const std::string ADD_COMMAND = "ADD";
const std::string SEARCH_COMMAND = "SEARCH";
const std::string EXIT_COMMAND = "EXIT";

PhoneBook::PhoneBook() : _totalContacts(0), _nextIndex(0) {
    std::cout << BLUE << "👷 PhoneBook constructor called 👷" << RESET << std::endl;
}

PhoneBook::~PhoneBook() {
    std::cout << YELLOW << "🧨 PhoneBook Destructor called 🧨" << RESET << std::endl;
}

std::string formatColumn(const std::string &str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return std::string(10 - str.length(), ' ') + str;
    }
}

bool onlyDigit(std::string input) {
    for (std::size_t i = 0; i < input.length(); i++)
        if (!std::isdigit(input[i])) {
            return false;
        }
    return true;
}

// Ensure that the field is always correct by repeatedly prompting the user until valid input is
// provided. This function handles both empty input and non-digit input (if digitsOnly is true) to
// maintain data integrity.
std::string validAddField(bool digitsOnly = false) {
    std::string input;
    std::getline(std::cin, input);
    while (input.empty() || (digitsOnly && !onlyDigit(input))) {
        if (std::cin.eof()) {
            exit(0);
        }
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

void PhoneBook::addContact(const Contact &contact) {
    this->_contacts[_nextIndex] = contact;
    this->_nextIndex = (_nextIndex + 1) % 8;
    this->_totalContacts += 1;
    if (this->_totalContacts > 8)
        this->_totalContacts = 8;
}

void PhoneBook::displaySpecificContact(std::size_t index) {
    if (index > this->_totalContacts) {
        std::cout << RED << "Error: Specified index is out of range." << NRED
                  << " Exiting SEARCH mode." << RESET << std::endl;
        return;
    } else if (this->_contacts[index].getFirstName().empty()) {
        std::cout << RED << "Error: No contact found at the specified index." << NRED
                  << " Exiting SEARCH mode." << RESET << std::endl;
        return;
    }
    std::cout << PURPLE << "All information for " << NPURPLE << this->_contacts[index].getNickname()
              << ":" << RESET << std::endl;
    std::cout << NCYAN << "First Name: " << RESET << _contacts[index].getFirstName() << std::endl;
    std::cout << NCYAN << "Last Name: " << RESET << _contacts[index].getLastName() << std::endl;
    std::cout << NCYAN << "Nickname: " << RESET << _contacts[index].getNickname() << std::endl;
    std::cout << NCYAN << "Phone Number: " << RESET << _contacts[index].getPhoneNumber()
              << std::endl;
    std::cout << NCYAN << "Darkest Secret: " << RESET << _contacts[index].getDarkestSecret()
              << std::endl;
}

void PhoneBook::displayContacts() {
    std::string input;
    std::size_t index;
    std::cout << NCYAN << "|" << "     INDEX" << "|" << "FIRST NAME" << "|" << " LAST NAME" << "|"
              << "  NICKNAME" << "|" << RESET << std::endl;
    for (std::size_t i = 0; i < _totalContacts; i++) {
        std::cout << "|" << "         " << this->_contacts[i].getIndex() << "|"
                  << formatColumn(this->_contacts[i].getFirstName()) << "|"
                  << formatColumn(this->_contacts[i].getLastName()) << "|"
                  << formatColumn(this->_contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << NCYAN << "Enter the contact index to see details." << RESET << std::endl;

    input = validAddField(true);
    index = strtoul(input.c_str(), NULL, 10);

    displaySpecificContact(index);
}

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