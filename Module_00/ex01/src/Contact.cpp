#include "../includes/Contact.hpp"

Contact::Contact()
    : index(0), firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {
    std::cout << BLUE << "👷 Contact Constructor called 👷" << RESET << std::endl;
}

Contact::~Contact() {
    std::cout << YELLOW << "🧨 Contact Destructor called 🧨" << RESET << std::endl;
}

void Contact::setIndex(const std::size_t index) {
    this->index = index;
}

void Contact::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::size_t Contact::getIndex() const {
    return index;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
