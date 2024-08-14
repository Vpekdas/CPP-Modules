#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria;

class IMateriaSource {
  public:
    IMateriaSource();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    IMateriaSource(const IMateriaSource &other);
    IMateriaSource &operator=(const IMateriaSource &other);

    virtual ~IMateriaSource() {
    }
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // I_MATERIA_SOURCE_HPP