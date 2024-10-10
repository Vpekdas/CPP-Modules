#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria;

class IMateriaSource {
    public:
    virtual ~IMateriaSource() {
    }
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // I_MATERIA_SOURCE_HPP