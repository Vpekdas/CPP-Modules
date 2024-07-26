#include "../includes/PhoneBook.hpp"
#include "iostream"
#include <cstddef>

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {}

PhoneBook::~PhoneBook() { std::cout << "Destructor called" << std::endl; }

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
  for (std::size_t i = 0; i < totalContacts; i++) {
    std::cout << "|" << formatColumn(this->contacts[i].getFirstName()) << "|"
              << formatColumn(this->contacts[i].getLastName()) << "|"
              << formatColumn(this->contacts[i].getNickname()) << "|"
              << formatColumn(this->contacts[i].getPhoneNumber()) << "|"
              << formatColumn(this->contacts[i].getDarkestSecret()) << "|"
              << std::endl;
  }
}

