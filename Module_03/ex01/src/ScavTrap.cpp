#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << YELLOW << "🛠️ Default ScavTrap Constructor called 🛠️" << RESET
              << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    setName(name);
    setHitPoints(CLAP_TRAP_HIT_POINT);
    setEnergyPoints(SCAV_TRAP_ENERGY_POINT);
    setAttackDamage(SCAV_TRAP_ATTACK_DAMAGE);
    std::cout << YELLOW << "🛠️ ScavTrap Constructor called 🛠️" << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "🧨 ScavTrap Destructor called 🧨" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    setAttackDamage(other.getAttackDamage());
    setEnergyPoints(other.getEnergyPoints());
    setHitPoints(other.getHitPoints());
    setName(other.getName());
    std::cout << YELLOW << "🖨️ ScavTrap Copy Constructor called 🖨️" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    // Check for self-assignment
    if (this != &other) {
        ClapTrap::operator=(other);
        setAttackDamage(other.getAttackDamage());
        setEnergyPoints(other.getEnergyPoints());
        setHitPoints(other.getHitPoints());
        setName(other.getName());
    }
    std::cout << YELLOW << "📞 ScavTrap Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    setEnergyPoints(getEnergyPoints() - 1);
    std::cout << "🗡️ " << NBLUE << "[ScavTrap " << getName() << "]" << BLUE << " has attacked "
              << NBLUE << target << BLUE << " with " << getAttackDamage() << " attack damage. "
              << getName() << " has " << getEnergyPoints() << " energy points left." << RESET
              << std::endl;
}

void ScavTrap::guardGate() {
    setEnergyPoints(getEnergyPoints() - 1);
    std::cout << "🛡️ " << NBLUE << getName() << BLUE << " is protecting themselves. "
              << getName() << " has " << getEnergyPoints() << " energy points left." << RESET
              << std::endl;
}
