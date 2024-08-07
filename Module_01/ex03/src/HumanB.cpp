#include "../includes/HumanB.hpp"
#include "../includes/colors.hpp"

HumanB::HumanB(const std::string &name) {
    _name = name;
    std::cout << NYELLOW << "🛠️🙎 HumanB Constructor called 🛠️🙎" << RESET << std::endl;
}

HumanB::~HumanB() {
    std::cout << NRED << "🧨 🙎 HumanB Deconstructor called 🧨 🙎" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void HumanB::attack() {
    std::cout << NPURPLE << this->getName() << " attacks with their " << this->_weapon->getType()
              << std::endl;
}

const std::string HumanB::getName() const {
    return _name;
}