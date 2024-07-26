#include "../includes/PhoneBook.hpp"
#include "iostream"
#include <cstddef>

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {
    std::cout << BLUE "👷 PhoneBook constructor called 👷" RESET << std::endl;
}

PhoneBook::~PhoneBook() {
    std::cout << YELLOW "🧨 PhoneBook Destructor called 🧨" RESET << std::endl;
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

void PhoneBook::displayContacts() {
    std::cout << BCYAN "|"
              << "     INDEX"
              << "|"
              << "FIRST NAME"
              << "|"
              << " LAST NAME"
              << "|"
              << "  NICKNAME"
              << "|" RESET << std::endl;
    for (std::size_t i = 0; i < totalContacts; i++) {
        std::cout << "|"
                  << "         " << this->contacts[i].getIndex() << "|"
                  << formatColumn(this->contacts[i].getFirstName()) << "|"
                  << formatColumn(this->contacts[i].getLastName()) << "|"
                  << formatColumn(this->contacts[i].getNickname()) << "|" << std::endl;
    }
}
