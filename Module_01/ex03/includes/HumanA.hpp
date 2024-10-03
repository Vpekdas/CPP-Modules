#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "../includes/Weapon.hpp"

class HumanA {
    public:
    // Constructor that initializes HumanA with a name and a reference to a Weapon.
    // Using a reference ensures that HumanA always has a valid weapon and reflects any changes to
    // the weapon.
    HumanA(const std::string &name, Weapon &weapon);
    ~HumanA();

    const std::string getName() const;

    void attack();

    private:
    Weapon &_weapon;
    std::string _name;
};

#endif