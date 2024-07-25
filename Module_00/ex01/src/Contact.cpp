#include "../includes/Contact.hpp"
#include "iostream"

Contact::Contact() {
    std::cout << "Constructor called" << std::endl;
}

Contact::~Contact() {
    std::cout << "Destructor called" << std::endl;
}