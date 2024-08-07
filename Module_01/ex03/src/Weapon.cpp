#include "../includes/Weapon.hpp"
#include "../includes/colors.hpp"

Weapon::Weapon(const std::string &type) {
    _type = type;
    std::cout << NYELLOW << "🛠️🔫 Weapon Constructor called 🛠️🔫" << RESET << std::endl;
}

Weapon::~Weapon() {
    std::cout << NRED << "🧨🔫 Weapon Destructor called 🧨🔫" << RESET << std::endl;
}

const std::string &Weapon::getType() {
    return _type;
}

void Weapon::setType(std::string type) {
    _type = type;
}