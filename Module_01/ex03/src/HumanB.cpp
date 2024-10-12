#include "../include/HumanB.hpp"
#include "../include/colors.hpp"

HumanB::HumanB(const std::string &name) {
    _name = name;
    std::cout << NEON_YELLOW << "🛠️🙎 HumanB Constructor called 🛠️🙎" << RESET << std::endl;
}

HumanB::~HumanB() {
    std::cout << NEON_RED << "🧨 🙎 HumanB Deconstructor called 🧨 🙎" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void HumanB::attack() {
    std::cout << NEON_PURPLE << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
}

const std::string HumanB::getName() const {
    return _name;
}