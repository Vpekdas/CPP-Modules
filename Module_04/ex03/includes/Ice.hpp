#ifndef ICE_HPP
#define ICE_HPP

#include "../includes/AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
  public:
    Ice();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    ~Ice();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif // ICE_HPP