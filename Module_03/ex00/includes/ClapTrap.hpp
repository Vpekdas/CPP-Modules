#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // LIBRARIES //      +   +   +   +   +   +  //
// -----------------------------------------------------------------------------//

#include <iostream>

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // CLASS //     +   +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

#define MAX_HEALTH 10
#define ENERGY_POINTS 10
#define ATTACK_DAMAGE 1

class ClapTrap {
  public:
    ClapTrap();
    ClapTrap(std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    bool isClapTrapDead();
    bool isClapTrapHasEnergy();

    const std::string &getName() const;
    const unsigned int &getHitPoints() const;
    const unsigned int &getEnergyPoints() const;

    void setName(const std::string &name);
    void setHitPoints(unsigned int hitPoints);
    void setEnergyPoints(unsigned int energyPoints);

    void displayStatus();

  private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif // CLAP_TRAP_HPP