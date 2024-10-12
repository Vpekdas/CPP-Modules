#include "../include/MateriaSource.hpp"
#include "../include/AMateria.hpp"
#include "../include/colors.hpp"

MateriaSource::MateriaSource() : _nextIndex(0) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = 0;
    }
    std::cout << YELLOW << "🛠️ Default MateriaSource Constructor called 🛠️" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _nextIndex(other._nextIndex) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = other._materias[i];
    }
    std::cout << YELLOW << "🖨️ MateriaSource Copy Constructor called 🖨️" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_materias[i]) {
            delete _materias[i];
            _materias[i] = 0;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    // Check for self-assignment
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            _materias[i] = other._materias[i];
        }
        _nextIndex = other._nextIndex;
    }
    std::cout << YELLOW << "📞 MateriaSource Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (_nextIndex < 4) {
        _materias[_nextIndex] = m;
        _nextIndex += 1;
    } else {
        delete m;
        std::cout << NEON_RED
                  << "❌ Error: MateriaSource storage is full. Cannot learn more "
                     "Materia. ❌"
                  << RESET << std::endl;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] != 0 && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    std::cout << NEON_RED << "❌ Materia of type '" << type << "' not found in MateriaSource. ❌" << RESET << std::endl;
    return NULL;
}