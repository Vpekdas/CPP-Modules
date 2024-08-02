#include "../includes/HumanA.hpp"
#include "../includes/colors.hpp"

// Must initialize weapon because it's a reference.

// HumanA Constructor by giving him a name and a weapon.
HumanA::HumanA(const std::string &name, Weapon &weapon) : weapon(weapon) {
    this->name = name;
    std::cout << NYELLOW << "🛠️ 🙎HumanA Constructor called 🛠️ 🙎" << RESET << std::endl;
}

// HumanA Deconstructor.
HumanA::~HumanA() {
    std::cout << NRED << "🧨 🙎HumanA Deconstructor called 🧨 🙎" << RESET << std::endl;
}

// HumanA attack that displays the name of the human and the name of the weapon.
void HumanA::attack() {
    std::cout << NPURPLE << this->getName() << " attacks with their " << this->weapon.getType()
              << std::endl;
}

// Getter for the human's name.
const std::string HumanA::getName() const {
    return this->name;
}