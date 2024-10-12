#include "../include/HumanA.hpp"
#include "../include/colors.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weapon(weapon) {
    _name = name;
    std::cout << NEON_YELLOW << "🛠️ 🙎HumanA Constructor called 🛠️ 🙎" << RESET << std::endl;
}

HumanA::~HumanA() {
    std::cout << NEON_RED << "🧨 🙎HumanA Deconstructor called 🧨 🙎" << RESET << std::endl;
}

void HumanA::attack() {
    std::cout << NEON_PURPLE << this->getName() << " attacks with their " << this->_weapon.getType() << std::endl;
}

const std::string HumanA::getName() const {
    return _name;
}