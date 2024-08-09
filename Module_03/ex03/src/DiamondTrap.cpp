#include "../includes/DiamondTrap.hpp"
#include "../includes/colors.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << YELLOW << "🛠️ Default DiamondTrap Constructor called 🛠️" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"),
      _name(name) {
    ClapTrap::setName(name + "_clap_name");
    setHitPoints(FRAG_TRAP_HIT_POINT);
    setEnergyPoints(SCAV_TRAP_ENERGY_POINT);
    setAttackDamage(FRAG_TRAP_ATTACK_DAMAGE);
    std::cout << YELLOW << "🛠️ DiamondTrap Constructor called 🛠️" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << RED << "🧨 DiamondTrap Destructor called 🧨" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    ClapTrap::setName(other._name + "_clap_name");
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
    std::cout << YELLOW << "🖨️ DiamondTrap Copy Constructor called 🖨️" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    // Check for self-assignment
    if (this != &other) {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        ClapTrap::setName(other._name + "_clap_name");
    }
    std::cout << YELLOW << "📞 DiamondTrap Copy Assignment Operator called 📞" << RESET
              << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::getName()
              << std::endl;
}