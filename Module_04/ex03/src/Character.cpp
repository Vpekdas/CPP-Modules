#include "../includes/Character.hpp"
#include "../includes/colors.hpp"

Character::Character() : _nextIndex(0) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = 0;
        _floor[i] = 0;
    }
    _name = "";
    std::cout << YELLOW << "🛠️ Default Character Constructor called 🛠️" << RESET
              << std::endl;
}

Character::Character(const std::string &name) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = 0;
        _floor[i] = 0;
    }
    _name = name;
    std::cout << YELLOW << "🛠️ Parameterized Character Constructor called 🛠️" << RESET
              << std::endl;
}

Character::~Character() {
    std::cout << RED << "🧨 Character Destructor called 🧨" << RESET << std::endl;
}

Character::Character(const Character &other) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = other._inventory[i];
        _floor[i] = other._floor[i];
        _name = other._name;
    }
    std::cout << YELLOW << "🖨️ Character Copy Constructor called 🖨️" << RESET
              << std::endl;
}

Character &Character::operator=(const Character &other) {
    // Check for self-assignment
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            _inventory[i] = other._inventory[i];
            _floor[i] = other._floor[i];
        }
        _name = other._name;
    }
    std::cout << YELLOW << "📞 Character Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Character::use(int idx, ICharacter &target) {
    _inventory[idx]->use(target);
}

void Character::equip(AMateria *m) {
    _inventory[_nextIndex] = m;
    _nextIndex += 1;
    if (_nextIndex > 3) {
        _nextIndex = 3;
    }
}

std::string const &Character::getName() const {
    return _name;
}

void Character::unequip(int idx) {
    _floor[idx] = _inventory[idx];
    _inventory[idx] = 0;
}