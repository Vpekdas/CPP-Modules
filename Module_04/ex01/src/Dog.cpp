#include "../include/Dog.hpp"
#include "../include/colors.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
    _type = "Dog";
    _name = "";
    std::cout << YELLOW << "🛠️ Default Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::Dog(const std::string &name) : Animal(name), _brain(new Brain("🦴 Dream about chasing the biggest bone 🦴")) {
    _type = "Dog";
    _name = name;
    std::cout << YELLOW << "🛠️ Parameterized Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::~Dog() {
    delete _brain;
    std::cout << RED << "🧨 Dog Destructor called 🧨" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
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
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << YELLOW << "📞 Dog Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "🐕 " << CYAN << "WOOF! I'm a Dog, hear me bark!" << RESET << std::endl;
}

std::string &Dog::getIdea(int index) const {
    return _brain->getIdea(index);
}

void Dog::setIdea(const std::string &newIdea) {
    _brain->setIdea(newIdea);
}