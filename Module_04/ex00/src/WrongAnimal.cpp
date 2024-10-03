#include "../includes/WrongAnimal.hpp"
#include "../includes/colors.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"), _name("") {
    std::cout << YELLOW << "🛠️ Default WrongAnimal Constructor called 🛠️" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) : _type("WrongAnimal"), _name(name) {
    std::cout << YELLOW << "🛠️ Parameterized WrongAnimal Constructor called 🛠️" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << RED << "🧨 WrongAnimal Destructor called 🧨" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type), _name(other._name) {
    std::cout << YELLOW << "🖨️ WrongAnimal Copy Constructor called 🖨️" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    // Check for self-assignment
    if (this != &other) {
        _type = other._type;
        _name = other._name;
    }
    std::cout << YELLOW << "📞 WrongAnimal Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void WrongAnimal::setName(const std::string &name) {
    _name = name;
}

const std::string &WrongAnimal::getName() const {
    return _name;
}

void WrongAnimal::setType(const std::string &type) {
    _type = type;
}

const std::string &WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << CYAN << "🤔 *Mysterious Wrong Roar* 🤔" << RESET << std::endl;
}
