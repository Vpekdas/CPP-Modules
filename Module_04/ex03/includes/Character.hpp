#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../includes/ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
  public:
    Character();
    Character(const std::string &name);
    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Character(const Character &other);
    Character &operator=(const Character &other);

    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    void equipFromFloor(int idx);

  private:
    AMateria *_inventory[4];
    AMateria *_floor[4];
    int _nextIndex;
};

#endif // CHARACTER_HPP