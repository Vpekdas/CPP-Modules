#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
    std::cout << YELLOW << "🛠️ Default ClapTrap Constructor called 🛠️" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string &name)
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
        std::cout << NRED << _name << " has no more 🫀 hitPoints🫀. cannot do action." << RESET
                  << std::endl;
        return true;
    }
    return false;
}

bool ClapTrap::isClapTrapHasEnergy() {
    if (getEnergyPoints() <= 0) {
        std::cout << NRED << _name << " has no more 🔋 energy 🔋. cannot do action." << RESET
                  << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    std::string attack;
    _energyPoints -= 1;
    std::cout << BLUE << _name << " has attacked " << target << RESET << std::endl;
    displayStatus();
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (amount > _hitPoints) {
        _hitPoints = 0;
        std::cout << BLUE << _name << " has taken " << _hitPoints << " damage " << RESET
                  << std::endl;

    } else {
        _hitPoints -= amount;
        std::cout << BLUE << _name << " has taken " << amount << " damage " << RESET << std::endl;
    }
    displayStatus();
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (isClapTrapDead() || !isClapTrapHasEnergy()) {
        return;
    }
    if (_hitPoints >= CLAP_TRAP_HIT_POINT) {
        std::cout << BLUE << _name << " is already full life." << RESET << std::endl;
    } else {
        _hitPoints += amount;
        std::cout << BLUE << _name << " has been repaired for " << amount << RESET << std::endl;
    }
    _energyPoints -= 1;
    displayStatus();
}

void ClapTrap::displayStatus() {
    std::string color = NYELLOW;

    if (getName() == "Ekko") {
        color = NCYAN;
    } else if (getName() == "Gangplank") {
        color = NGREEN;
    }

    std::cout << color << _name << " has " << _hitPoints << " hitPoints." << RESET << std::endl;
    std::cout << color << _name << " has " << _energyPoints << " energyPoints." << RESET
              << std::endl;
    std::cout << YELLOW << "--------------------------" << RESET << std::endl;
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