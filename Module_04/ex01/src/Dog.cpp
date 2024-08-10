#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
    setType("Dog");
    std::cout << YELLOW << "🛠️ Default Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::Dog(const std::string &name)
    : Animal(name), _brain(new Brain("🦴 Dream about chasing the biggest bone 🦴")) {
    setType("Dog");
    std::cout << YELLOW << "🛠️ Parameterized Dog Constructor called 🛠️" << RESET << std::endl;
}

Dog::~Dog() {
    delete _brain;
    std::cout << RED << "🧨 Dog Destructor called 🧨" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
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
    for (int i = 0; i < 100; i++) {
        _brain[i] = newIdea;
    }
}