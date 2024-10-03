#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/colors.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << YELLOW << "🛠️ Default Ice Constructor called 🛠️" << RESET << std::endl;
}

Ice::~Ice() {
    std::cout << RED << "🧨 Ice Destructor called 🧨" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
    std::cout << YELLOW << "🖨️ Ice Copy Constructor called 🖨️" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    // Check for self-assignment
    if (this != &other) {
        AMateria::operator=(other);
    }
    std::cout << YELLOW << "📞 Ice Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << CYAN << " casts 🧊 " << BICYAN << _type << CYAN << " on " << NCYAN << target.getName() << RESET
              << std::endl;
}