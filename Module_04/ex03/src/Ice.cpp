#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/colors.hpp"

Ice::Ice() {
    _type = "ice";
    std::cout << YELLOW << "🛠️ Default Ice Constructor called 🛠️" << RESET << std::endl;
}

Ice::~Ice() {
    std::cout << RED << "🧨 Ice Destructor called 🧨" << RESET << std::endl;
}

Ice::Ice(const Ice &other) {
    _type = other._type;
    std::cout << YELLOW << "🖨️ Ice Copy Constructor called 🖨️" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    // Check for self-assignment
    if (this != &other) {
        _type = other._type;
    }
    std::cout << YELLOW << "📞 Ice Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "🧊 " << CYAN << "* shoots an ice bolt at " << target.getName() << RESET
              << std::endl;
}