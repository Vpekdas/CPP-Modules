#ifndef CURE_HPP
#define CURE_HPP

#include "../include/AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
    public:
    Cure();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
    ~Cure();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif // CURE_HPP