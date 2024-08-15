#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/colors.hpp"

Cure::Cure() {
    _type = "cure";
    std::cout << YELLOW << "🛠️ Default Cure Constructor called 🛠️" << RESET << std::endl;
}

Cure::~Cure() {
    std::cout << RED << "🧨 Cure Destructor called 🧨" << RESET << std::endl;
}

Cure::Cure(const Cure &other) {
    _type = other._type;
    std::cout << YELLOW << "🖨️ Cure Copy Constructor called 🖨️" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
    // Check for self-assignment
    if (this != &other) {
        _type = other._type;
    }
    std::cout << YELLOW << "📞 Cure Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

AMateria *Cure::clone() const {
    Cure *cure = new (Cure);
    return cure;
}

void Cure::use(ICharacter &target) {
    std::cout << "💊 " << CYAN << "Heals " << target.getName() << " wounds." << RESET << std::endl;
}