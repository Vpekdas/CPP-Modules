#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
    std::cout << YELLOW << "🛠️ Default ClapTrap Constructor called 🛠️" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << YELLOW << "🛠️ClapTrap Constructor called 🛠️" << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << RED << "🧨 ClapTrap Destructor called 🧨" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
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
        std::cout << CYAN << getName() << " has no more ❤️ hitPoints ❤️. He can do nothing." << RESET
                  << std::endl;
        return true;
    }
    return false;
}

bool ClapTrap::isClapTrapHasEnergy() {
    if (getEnergyPoints() <= 0) {
        std::cout << CYAN << getName() << " has no more ⚡ energy ⚡. He can do nothing." << RESET
                  << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target) {
}

void ClapTrap::takeDamage(unsigned int amount) {
}

void ClapTrap::beRepaired(unsigned int amount) {
}

const std::string &ClapTrap::getName() const {
    return _name;
}
const int &ClapTrap::getHitPoints() const {
    return _hitPoints;
}
const int &ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

void ClapTrap::setName(const std::string &name) {
    _name = name;
}
void ClapTrap::setHitPoints(int hitPoints) {
    _hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(int energyPoints) {
    _energyPoints = energyPoints;
}