#include "../includes/Character.hpp"
#include "../includes/colors.hpp"

Character::Character() : _nextIndex(0) {
    _name = "";
    for (int i = 0; i < 4; i++) {
        _inventory[i] = 0;
        _floor[i] = 0;
    }
    std::cout << YELLOW << "🛠️ Default Character Constructor called 🛠️" << RESET
              << std::endl;
}

Character::Character(const std::string &name) : _nextIndex(0) {
    _name = name;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = 0;
        _floor[i] = 0;
    }
    std::cout << YELLOW << "🛠️ Parameterized Character Constructor called 🛠️" << RESET
              << std::endl;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
            _inventory[i] = 0;
        }
        if (_floor[i]) {
            delete _floor[i];
            _floor[i] = 0;
        }
    }
    std::cout << RED << "🧨 Character Destructor called 🧨" << RESET << std::endl;
}

Character::Character(const Character &other) {
    _name = other._name;
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = 0;
        }
        if (other._floor[i]) {
            _floor[i] = other._floor[i]->clone();
        } else {
            _floor[i] = 0;
        }
    }
    std::cout << YELLOW << "🖨️ Character Copy Constructor called 🖨️" << RESET
              << std::endl;
}

Character &Character::operator=(const Character &other) {
    // Check for self-assignment
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            _inventory[i] = other._inventory[i]->clone();
            _floor[i] = other._floor[i]->clone();
        }
        _name = other._name;
    }
    std::cout << YELLOW << "📞 Character Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        std::cout << NRED << "❌ Error: Index " << idx
                  << " is out of bounds. Valid range is 0 to 3. ❌" << RESET << std::endl;
        return;
    } else if (!_inventory[idx]) {
        std::cout << NRED << "❌ Warning: Inventory slot " << idx
                  << " is empty. Cannot perform the action. ❌" << RESET << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}

void Character::equip(AMateria *m) {
    if (_nextIndex > 3) {
        _nextIndex = 3;
    }
    _inventory[_nextIndex] = m;
    _nextIndex += 1;
}

std::string const &Character::getName() const {
    return _name;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << NRED << "❌ Error: Index " << idx
                  << " is out of bounds. Valid range is 0 to 3. ❌" << RESET << std::endl;
        return;
    }
    if (_inventory[idx] == 0) {
        std::cout << NRED << "❌ Error: Inventory slot " << idx << " is already empty. ❌" << RESET
                  << std::endl;
        return;
    }
    _floor[idx] = _inventory[idx];
    _inventory[idx] = 0;
}
