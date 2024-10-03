#ifndef FIRE_HPP
#define FIRE_HPP

#include "../includes/AMateria.hpp"
#include <iostream>

class Fire : public AMateria {
    public:
    Fire();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Fire(const Fire &other);
    Fire &operator=(const Fire &other);
    ~Fire();

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif // FIRE_HPP