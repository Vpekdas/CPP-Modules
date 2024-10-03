#include "../includes/WrongCat.hpp"
#include "../includes/colors.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    _name = "";
    std::cout << YELLOW << "🛠️ Default WrongCat Constructor called 🛠️" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal(name) {
    _type = "WrongCat";
    _name = name;
    std::cout << YELLOW << "🛠️ Parameterized WrongCat Constructor called 🛠️" << RESET << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << RED << "🧨 WrongCat Destructor called 🧨" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    _type = other._type;
    _name = other._name;
    std::cout << YELLOW << "🖨️ WrongCat Copy Constructor called 🖨️" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    // Check for self-assignment
    if (this != &other) {
        WrongAnimal::operator=(other);
        _type = other._type;
        _name = other._name;
    }
    std::cout << YELLOW << "📞 WrongCat Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "🐈 " << CYAN << "MEOW! I'm a Cat, hear me roar!" << RESET << std::endl;
}