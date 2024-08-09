#ifndef DIAMOND_TRAP__HPP
#define DIAMOND_TRAP__HPP

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
    DiamondTrap();
    DiamondTrap(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void whoAmI();
    void attack(const std::string &target);

  private:
    std::string _name;
};

#endif // DIAMOND_TRAP__HPP