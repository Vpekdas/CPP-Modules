#include "../includes/Animal.hpp"
#include "../includes/colors.hpp"

Animal::Animal() : _type("Animal"), _name("") {
    std::cout << YELLOW << "🛠️ Default Animal Constructor called 🛠️" << RESET
              << std::endl;
}

Animal::Animal(const std::string &name) : _type("Animal"), _name(name) {
    std::cout << YELLOW << "🛠️ Parameterized Animal Constructor called 🛠️" << RESET
              << std::endl;
}

Animal::~Animal() {
    std::cout << RED << "🧨 Animal Destructor called 🧨" << RESET << std::endl;
}

Animal::Animal(const Animal &other) : _type("Animal"), _name(other._name) {
    std::cout << YELLOW << "🖨️ Animal Copy Constructor called 🖨️" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    // Check for self-assignment
    if (this != &other) {
        _type = other._type;
        _name = other._name;
    }
    std::cout << YELLOW << "📞 Animal Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Animal::setName(const std::string &name) {
    _name = name;
}

const std::string &Animal::getName() const {
    return _name;
}

void Animal::setType(const std::string &type) {
    _type = type;
}

const std::string &Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << CYAN << "🤔 *Mysterious Animal Roar* 🤔" << RESET << std::endl;
}
