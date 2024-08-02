#include "../includes/Weapon.hpp"
#include "../includes/colors.hpp"

// Weapon Constructor that create a weapon with the given type.
Weapon::Weapon(const std::string &type) {
    this->type = type;
    std::cout << NYELLOW << "🛠️🔫 Weapon Constructor called 🛠️🔫" << RESET << std::endl;
}

// Weapon Deconstructor
Weapon::~Weapon() {
    std::cout << NRED << "🧨🔫 Weapon Destructor called 🧨🔫" << RESET << std::endl;
}

// Return the type of a weapon.
const std::string &Weapon::getType() {
    return this->type;
}

// Set the type of a weapon.
void Weapon::setType(std::string type) {
    this->type = type;
}