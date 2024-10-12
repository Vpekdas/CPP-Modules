#include "../include/ClapTrap.hpp"
#include "../include/colors.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
    std::cout << YELLOW << "🛠️ Default ClapTrap Constructor called 🛠️" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(CLAP_TRAP_HIT_POINT), _energyPoints(CLAP_TRAP_ENERGY_POINT),
      _attackDamage(CLAP_TRAP_ATTACK_DAMAGE) {
    std::cout << YELLOW << "🛠️ ClapTrap Constructor called 🛠️" << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << RED << "🧨 ClapTrap Destructor called 🧨" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << YELLOW << "🖨️ ClapTrap Copy Constructor called 🖨️" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    // Check for self-assignment
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << YELLOW << "📞 ClapTrap Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

bool ClapTrap::isClapTrapDead() {
    if (getHitPoints() <= 0) {
        std::cout << NEON_RED << _name << RED << " has no more 🫀 hit points🫀 and cannot perform any actions." << RESET
                  << std::endl;
        return true;
    }
    return false;
}

bool ClapTrap::isClapTrapHasEnergy() {
    if (getEnergyPoints() <= 0) {
        std::cout << NEON_RED << _name << RED << " has no more 🔋 energy 🔋 and cannot perform any actions." << RESET
                  << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    _energyPoints -= 1;
    std::cout << "🗡️ " << NEON_BLUE << "[ClapTrap " << _name << "]" << BLUE << " has attacked " << NEON_BLUE << target
              << BLUE << " with " << _attackDamage << " attack damage. " << _name << " has " << _energyPoints
              << " energy points left." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (amount > _hitPoints) {
        _hitPoints = 0;
        std::cout << "💥 " << NEON_BLUE << _name << BLUE << " has taken " << _hitPoints << " damage and now has "
                  << _hitPoints << " hit points." << RESET << std::endl;

    } else {
        _hitPoints -= amount;
        std::cout << "💥 " << NEON_BLUE << _name << BLUE << " has taken " << amount << " damage and now has "
                  << _hitPoints << " hit points." << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    if (_hitPoints >= CLAP_TRAP_HIT_POINT) {
        std::cout << "⛑️ " << NEON_BLUE << _name << BLUE << " is already at full health. " << _name << " has "
                  << _energyPoints << " energy points left." << RESET << std::endl;
    } else {
        _hitPoints += amount;
        std::cout << "💊 " << NEON_BLUE << _name << BLUE << " healed themselves for " << amount
                  << " health points and now has " << _hitPoints << " hit points. " << _name << " has " << _energyPoints
                  << " energy points left." << RESET << std::endl;
    }
    _energyPoints -= 1;
}

const std::string &ClapTrap::getName() const {
    return _name;
}
const unsigned int &ClapTrap::getHitPoints() const {
    return _hitPoints;
}
const unsigned int &ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

const unsigned int &ClapTrap::getAttackDamage() const {
    return _attackDamage;
}

void ClapTrap::setName(const std::string &name) {
    _name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    _attackDamage = attackDamage;
}