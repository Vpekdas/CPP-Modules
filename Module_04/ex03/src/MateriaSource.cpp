#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/colors.hpp"
#include <cstddef>
#include <new>

MateriaSource::MateriaSource() : _nextIndex(0) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = 0;
    }
    std::cout << YELLOW << "🛠️ Default MateriaSource Constructor called 🛠️" << RESET
              << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _nextIndex(other._nextIndex) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = other._materias[i];
    }
    std::cout << YELLOW << "🖨️ MateriaSource Copy Constructor called 🖨️" << RESET
              << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    // Check for self-assignment
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            _materias[i] = other._materias[i];
        }
        _nextIndex = other._nextIndex;
    }
    std::cout << YELLOW << "📞 MateriaSource Copy Assignment Operator called 📞" << RESET
              << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    _materias[_nextIndex] = m->clone();
    _nextIndex += 1;
    if (_nextIndex > 3) {
        _nextIndex = 3;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i]->getType() == type && type == "ice") {
            Cure *cure = new (Cure);
            return cure;
        } else if (_materias[i]->getType() == type && type == "cure") {
            Ice *ice = new (Ice);
            return ice;
        }
    }
    return NULL;
}