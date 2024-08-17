#include "../includes/Lightning.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/colors.hpp"

Lightning::Lightning() : AMateria("lightning") {
    std::cout << YELLOW << "🛠️ Default Lightning Constructor called 🛠️" << RESET
              << std::endl;
}

Lightning::~Lightning() {
    std::cout << RED << "🧨 Lightning Destructor called 🧨" << RESET << std::endl;
}

Lightning::Lightning(const Lightning &other) : AMateria(other) {
    std::cout << YELLOW << "🖨️ Lightning Copy Constructor called 🖨️" << RESET
              << std::endl;
}

Lightning &Lightning::operator=(const Lightning &other) {
    // Check for self-assignment
    if (this != &other) {
        AMateria::operator=(other);
    }
    std::cout << YELLOW << "📞 Lightning Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

AMateria *Lightning::clone() const {
    return new Lightning(*this);
}

void Lightning::use(ICharacter &target) {
    std::cout << CYAN << " casts ⛈️  " << BICYAN << _type << CYAN << " on " << NCYAN
              << target.getName() << RESET << std::endl;
}