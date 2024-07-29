#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"
#include "../includes/utils.hpp"

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {
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

void PhoneBook::addContact(const Contact &contact) {
    this->contacts[nextIndex] = contact;
    this->nextIndex = (nextIndex + 1) % 8;
    this->totalContacts += 1;
    if (this->totalContacts > 8)
        this->totalContacts = 8;
}

void PhoneBook::displaySpecificContact(std::size_t index) {
    if (index > this->totalContacts) {
        std::cout << RED << "Error: Specified index is out of range." << BRED
                  << " Exiting SEARCH mode." << RESET << std::endl;
        return;
    } else if (this->contacts[index].getFirstName().empty()) {
        std::cout << RED << "Error: No contact found at the specified index." << BRED
                  << " Exiting SEARCH mode." << RESET << std::endl;
        return;
    }
    std::cout << PURPLE << "All information for " << BPURPLE << this->contacts[index].getNickname()
              << ":" << RESET << std::endl;
    std::cout << BCYAN << "First Name: " << RESET << contacts[index].getFirstName() << std::endl;
    std::cout << BCYAN << "Last Name: " << RESET << contacts[index].getLastName() << std::endl;
    std::cout << BCYAN << "Nickname: " << RESET << contacts[index].getNickname() << std::endl;
    std::cout << BCYAN << "Phone Number: " << RESET << contacts[index].getPhoneNumber()
              << std::endl;
    std::cout << BCYAN << "Darkest Secret: " << RESET << contacts[index].getDarkestSecret()
              << std::endl;
}

void PhoneBook::displayContacts() {
    std::string input;
    std::size_t index;
    std::cout << BCYAN << "|"
              << "     INDEX"
              << "|"
              << "FIRST NAME"
              << "|"
              << " LAST NAME"
              << "|"
              << "  NICKNAME"
              << "|" << RESET << std::endl;
    for (std::size_t i = 0; i < totalContacts; i++) {
        std::cout << "|"
                  << "         " << this->contacts[i].getIndex() << "|"
                  << formatColumn(this->contacts[i].getFirstName()) << "|"
                  << formatColumn(this->contacts[i].getLastName()) << "|"
                  << formatColumn(this->contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << BCYAN << "Enter the contact index to see details." << RESET << std::endl;

    input = validAddField(true);
    index = strtoul(input.c_str(), NULL, 10);

    displaySpecificContact(index);
}
