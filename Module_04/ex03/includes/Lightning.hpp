#ifndef LIGHTNING_HPP
#define LIGHTNING_HPP

#include "../includes/AMateria.hpp"
#include <iostream>

class Lightning : public AMateria {
  public:
    Lightning();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Lightning(const Lightning &other);
    Lightning &operator=(const Lightning &other);
    ~Lightning();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif // LIGHTNING_HPP