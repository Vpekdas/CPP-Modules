#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // LIBRARIES //      +   +   +   +   +   +  //
// -----------------------------------------------------------------------------//

#include "../includes/ClapTrap.hpp"
#include <iostream>

#define S_MAX_HEALTH 100
#define S_ENERGY_POINT 50
#define S_ATTACK_DAMAGE 20

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // CLASS //     +   +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void guardGate();
};

#endif // SCAVTRAP_HPP