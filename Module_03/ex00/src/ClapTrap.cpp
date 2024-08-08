#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
    std::cout << YELLOW << "🛠️ Default ClapTrap Constructor called 🛠️" << RESET
              << std::endl;
}

ClapTrap::ClapTrap(std::string &name)
    : _name(name), _hitPoints(MAX_HEALTH), _energyPoints(ENERGY_POINTS),
      _attackDamage(ATTACK_DAMAGE) {
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
        std::cout << NRED << _name << " has no more 🫀 hitPoints🫀. He can do nothing." << RESET
                  << std::endl;
        return true;
    }
    return false;
}

bool ClapTrap::isClapTrapHasEnergy() {
    if (getEnergyPoints() <= 0) {
        std::cout << NRED << _name << " has no more 🔋 energy 🔋. He can do nothing." << RESET
                  << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    setEnergyPoints(1);
    std::cout << CYAN << _name << " has attacked " << target << " and dealt " << ATTACK_DAMAGE
              << " damage " << RESET << std::endl;
    displayStatus();
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (isClapTrapDead()) {
        return;
    }
    if (amount > _hitPoints) {
        _hitPoints = 0;
        std::cout << CYAN << _name << " has taken " << _hitPoints << " damage " << RESET
                  << std::endl;

    } else {
        _hitPoints -= amount;
        std::cout << CYAN << _name << " has taken " << amount << " damage " << RESET << std::endl;
    }
    displayStatus();
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    setEnergyPoints(1);
    if (_hitPoints >= MAX_HEALTH) {
        std::cout << CYAN << _name << " is already full life." << RESET << std::endl;
    } else {
        _hitPoints += amount;
        std::cout << CYAN << _name << " has been repaired for " << amount << RESET << std::endl;
    }
    displayStatus();
}

void ClapTrap::displayStatus() {
    std::cout << NPURPLE << _name << " has " << _hitPoints << " hitPoints." << RESET << std::endl;
    std::cout << NPURPLE << _name << " has " << _energyPoints << " energyPoints." << RESET
              << std::endl;
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

void ClapTrap::setName(const std::string &name) {
    _name = name;
}
void ClapTrap::setHitPoints(unsigned int hitPoints) {
    _hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = _energyPoints - energyPoints;
}