#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"

ScavTrap::ScavTrap() {
    std::cout << YELLOW << "🛠️ Default ScavTrap Constructor called 🛠️" << RESET
              << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) {
    setName(name);
    setHitPoints(C_MAX_HEALTH);
    setEnergyPoints(S_ENERGY_POINT);
    std::cout << YELLOW << "🛠️ ScavTrap Constructor called 🛠️" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "🧨 ScavTrap Destructor called 🧨" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    setAttackDamage(other.getAttackDamage());
    setEnergyPoints(getEnergyPoints());
    setHitPoints(getHitPoints());
    setName(getName());
    std::cout << YELLOW << "🖨️ ScavTrap Copy Constructor called 🖨️" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 ScavTrap Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << CYAN << getName() << " is protecting himself." << RESET << std::endl;
}
