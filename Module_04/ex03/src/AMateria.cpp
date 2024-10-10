#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include "../include/colors.hpp"

AMateria::AMateria() : _type("") {
    std::cout << YELLOW << "🛠️ Default AMateria Constructor called 🛠️" << RESET << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
    std::cout << YELLOW << "🛠️ Parameterized AMateria Constructor called 🛠️" << RESET << std::endl;
}
AMateria::~AMateria() {
    std::cout << RED << "🧨 AMateria Destructor called 🧨" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
    std::cout << YELLOW << "🖨️ AMateria Copy Constructor called 🖨️" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 AMateria Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}