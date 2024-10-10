#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "../include/IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
    public:
    MateriaSource();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);

    ~MateriaSource();
    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);

    private:
    AMateria *_materias[4];
    int _nextIndex;
};

#endif // MATERIA_SOURCE_HPP