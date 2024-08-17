#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
  public:
    AMateria();
    AMateria(std::string const &type);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

  protected:
    const std::string _type;
};

#endif // A_MATERIA_HPP