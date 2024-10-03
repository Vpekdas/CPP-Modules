#include "../includes/Contact.hpp"
#include "../includes/colors.hpp"

Contact::Contact() : _index(0), _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {
    std::cout << BLUE << "👷 Contact Constructor called 👷" << RESET << std::endl;
}

Contact::~Contact() {
    std::cout << YELLOW << "🧨 Contact Destructor called 🧨" << RESET << std::endl;
}

void Contact::setIndex(const std::size_t index) {
    this->_index = index;
}

void Contact::setFirstName(const std::string &firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

std::size_t Contact::getIndex() const {
    return _index;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}
