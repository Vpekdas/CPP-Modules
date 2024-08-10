#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/Animal.hpp"
#include <iostream>

class Dog : public Animal {
  public:
    Dog();
    Dog(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void makeSound() const;
};

#endif // DOG_HPP