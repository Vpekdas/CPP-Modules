#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP

#include <iostream>

class AMateria;

class ICharacter {
  public:
    ICharacter();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    ICharacter(const ICharacter &other);
    ICharacter &operator=(const ICharacter &other);
    virtual ~ICharacter() {
    }
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;

  private:
    AMateria *inventory[4];
};

#endif // I_CHARACTER_HPP