#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "../include/ClapTrap.hpp"
#include <iostream>

#define SCAV_TRAP_HIT_POINT 100
#define SCAV_TRAP_ENERGY_POINT 50
#define SCAV_TRAP_ATTACK_DAMAGE 20

class ScavTrap : virtual public ClapTrap {
    public:
    ScavTrap();
    ScavTrap(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif // SCAVTRAP_HPP