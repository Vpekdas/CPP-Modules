#include "../includes/FragTrap.hpp"
#include "../includes/colors.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << YELLOW << "🛠️ Default FragTrap Constructor called 🛠️" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    setAttackDamage(FRAG_TRAP_ATTACK_DAMAGE);
    setEnergyPoints(FRAG_TRAP_ENERGY_POINT);
    setHitPoints(FRAG_TRAP_HIT_POINT);
    std::cout << YELLOW << "🛠️ FragTrap Constructor called 🛠️" << RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << RED << "🧨 FragTrap Destructor called 🧨" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    setAttackDamage(other.getAttackDamage());
    setEnergyPoints(other.getEnergyPoints());
    setHitPoints(other.getHitPoints());
    setName(other.getName());
    std::cout << YELLOW << "🖨️ FragTrap Copy Constructor called 🖨️" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    // Check for self-assignment
    if (this != &other) {
        ClapTrap::operator=(other);
        setAttackDamage(other.getAttackDamage());
        setEnergyPoints(other.getEnergyPoints());
        setHitPoints(other.getHitPoints());
        setName(other.getName());
    }
    std::cout << YELLOW << "📞 FragTrap Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    setEnergyPoints(getEnergyPoints() - 1);
    std::cout << CYAN << getName() << " has requested a 🤜 fist bump. 🤛" << RESET << std::endl;
}