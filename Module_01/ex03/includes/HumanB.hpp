#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "../includes/Weapon.hpp"

class HumanB {
    public:
    // Constructor that initializes HumanB with a name.
    // HumanB does not require a weapon at initialization, allowing for more flexibility.
    HumanB(const std::string &name);
    ~HumanB();

    void setWeapon(Weapon &weapon);
    const std::string getName() const;

    void attack();

    private:
    Weapon *_weapon;
    std::string _name;
};

#endif