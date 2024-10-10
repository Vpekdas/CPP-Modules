#ifndef CAT_HPP
#define CAT_HPP

#include "../include/Animal.hpp"
#include <iostream>

class Cat : public Animal {
    public:
    Cat();
    Cat(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void makeSound() const;
};

#endif // CAT_HPP