#include "../include/Cat.hpp"
#include "../include/colors.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
    _type = "Cat";
    _name = "";
    std::cout << YELLOW << "🛠️ Default Cat Constructor called 🛠️" << RESET << std::endl;
}

Cat::Cat(const std::string &name) : Animal(name), _brain(new Brain("🐠 Dream about catching the biggest fish 🐠")) {
    _type = "Cat";
    _name = name;
    std::cout << YELLOW << "🛠️ Parameterized Cat Constructor called 🛠️" << RESET << std::endl;
}

Cat::~Cat() {
    delete _brain;
    std::cout << RED << "🧨 Cat Destructor called 🧨" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) {
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
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << YELLOW << "📞 Cat Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "🐈 " << CYAN << "MEOW! I'm a Cat, hear me roar!" << RESET << std::endl;
}

std::string &Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}

void Cat::setIdea(const std::string &newIdea) {
    _brain->setIdea(newIdea);
}