#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "../includes/IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);

    ~MateriaSource() {
    }
    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);

  private:
};

#endif // MATERIA_SOURCE_HPP