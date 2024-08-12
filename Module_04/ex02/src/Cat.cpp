#include "../includes/Cat.hpp"
#include "../includes/colors.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
    setType("Cat");
    std::cout << YELLOW << "🛠️ Default Cat Constructor called 🛠️" << RESET << std::endl;
}

Cat::Cat(const std::string &name)
    : Animal(name), _brain(new Brain("🐠 Dream about catching the biggest fish 🐠")) {
    setType("Cat");
    std::cout << YELLOW << "🛠️ Parameterized Cat Constructor called 🛠️" << RESET
              << std::endl;
}

Cat::~Cat() {
    delete _brain;
    std::cout << RED << "🧨 Cat Destructor called 🧨" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) {
    setName(other.getName());
    setType(other.getType());
    std::cout << YELLOW << "🖨️ Cat Copy Constructor called 🖨️" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    // Check for self-assignment
    if (this != &other) {
        Animal::operator=(other);
        setName(other.getName());
        setType(other.getType());
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