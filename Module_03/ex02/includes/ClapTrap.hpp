#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

#define CLAP_TRAP_HIT_POINT 100
#define CLAP_TRAP_ENERGY_POINT 10
#define CLAP_TRAP_ATTACK_DAMAGE 0

class ClapTrap {
  public:
    ClapTrap();
    ClapTrap(const std::string &name);

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
    const unsigned int &getAttackDamage() const;

    void setName(const std::string &name);
    void setHitPoints(unsigned int hitPoints);
    void setEnergyPoints(unsigned int energyPoints);
    void setAttackDamage(unsigned int attackDamage);

  protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif // CLAP_TRAP_HPP