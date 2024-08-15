#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP

#include "../includes/AMateria.hpp"
#include <iostream>

class ICharacter {
  public:
    virtual ~ICharacter() {
    }
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;

  protected:
    std::string _name;
};

#endif // I_CHARACTER_HPP