#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"

Dog::Dog() : Animal() {
    setType("Dog");
    std::cout << YELLOW << "🛠️ Default Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name) {
    setType("Dog");
    std::cout << YELLOW << "🛠️ Parameterized Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << RED << "🧨 Dog Destructor called 🧨" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    setName(other.getName());
    setType(other.getType());
    std::cout << YELLOW << "🖨️ Dog Copy Constructor called 🖨️" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    // Check for self-assignment
    if (this != &other) {
        Animal::operator=(other);
        setName(other.getName());
        setType(other.getType());
    }
    std::cout << YELLOW << "📞 Dog Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐕 " << CYAN << "WOOF! I'm a Dog, hear me bark!" << RESET << std::endl;
}