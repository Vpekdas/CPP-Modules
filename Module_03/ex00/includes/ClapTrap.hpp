#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // LIBRARIES //      +   +   +   +   +   +  //
// -----------------------------------------------------------------------------//

#include <iostream>

// -----------------------------------------------------------------------------//
//  +   +   +   +   +   +   +   +   // CLASS //     +   +   +   +   +   +   +   //
// -----------------------------------------------------------------------------//

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
    const int &getHitPoints() const;
    const int &getEnergyPoints() const;

    void setName(const std::string &name);
    void setHitPoints(int hitPoints);
    void setEnergyPoints(int energyPoints);

  private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};

#endif // CLAP_TRAP_HPP