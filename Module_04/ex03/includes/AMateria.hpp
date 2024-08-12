#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include "../includes/ICharacter.hpp"
#include <iostream>

class AMateria {
  protected:
  public:
    AMateria();
    AMateria(std::string const &type);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    ~AMateria();

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif // A_MATERIA_HPP