#include "../includes/HumanA.hpp"
#include "../includes/colors.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weapon(weapon) {
    _name = name;
    std::cout << NYELLOW << "🛠️ 🙎HumanA Constructor called 🛠️ 🙎" << RESET << std::endl;
}

HumanA::~HumanA() {
    std::cout << NRED << "🧨 🙎HumanA Deconstructor called 🧨 🙎" << RESET << std::endl;
}

void HumanA::attack() {
    std::cout << NPURPLE << this->getName() << " attacks with their " << this->_weapon.getType()
              << std::endl;
}

const std::string HumanA::getName() const {
    return _name;
}