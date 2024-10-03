#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "../includes/ClapTrap.hpp"
#include <iostream>

#define FRAG_TRAP_HIT_POINT 100
#define FRAG_TRAP_ENERGY_POINT 100
#define FRAG_TRAP_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap {
    public:
    FragTrap();
    FragTrap(const std::string &name);
    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys(void);

    private:
};

#endif // FRAG_TRAP_HPP