#include "../includes/Cat.hpp"
#include "../includes/colors.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    _name = "";
    std::cout << YELLOW << "🛠️ Default Cat Constructor called 🛠️" << RESET << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name) {
    _type = "Cat";
    _name = name;
    std::cout << YELLOW << "🛠️ Parameterized Cat Constructor called 🛠️" << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << RED << "🧨 Cat Destructor called 🧨" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    _type = other._type;
    _name = other._name;
    std::cout << YELLOW << "🖨️ Cat Copy Constructor called 🖨️" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    // Check for self-assignment
    if (this != &other) {
        Animal::operator=(other);
        _type = other._type;
        _name = other._name;
    }
    std::cout << YELLOW << "📞 Cat Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "🐈 " << CYAN << "MEOW! I'm a Cat, hear me roar!" << RESET << std::endl;
}