#include "../include/Dog.hpp"
#include "../include/colors.hpp"

Dog::Dog() : Animal() {
    _type = "Dog";
    _name = "";
    std::cout << YELLOW << "🛠️ Default Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name) {
    _type = "Dog";
    _name = name;
    std::cout << YELLOW << "🛠️ Parameterized Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << RED << "🧨 Dog Destructor called 🧨" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    _type = other._type;
    _name = other._name;
    std::cout << YELLOW << "🖨️ Dog Copy Constructor called 🖨️" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    // Check for self-assignment
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
        _name = other._name;
    }
    std::cout << YELLOW << "📞 Dog Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐕 " << CYAN << "WOOF! I'm a Dog, hear me bark!" << RESET << std::endl;
}