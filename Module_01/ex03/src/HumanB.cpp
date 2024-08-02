#include "../includes/HumanB.hpp"
#include "../includes/colors.hpp"

// HumanB Constructor by giving him a name.
HumanB::HumanB(const std::string &name) {
    this->name = name;
    std::cout << NYELLOW << "🛠️🙎 HumanB Constructor called 🛠️🙎" << RESET << std::endl;
}

// HumanB Deconstructor.
HumanB::~HumanB() {
    std::cout << NRED << "🧨 🙎 HumanB Deconstructor called 🧨 🙎" << RESET << std::endl;
}

// Setter for the human's weapon.
void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

// HumanABattack that displays the name of the human and the name of the weapon.
void HumanB::attack() {
    std::cout << NPURPLE << this->getName() << " attacks with their " << this->weapon->getType()
              << std::endl;
}

// Getter for the human's name.
const std::string HumanB::getName() const {
    return this->name;
}