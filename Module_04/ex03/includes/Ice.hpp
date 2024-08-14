#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

class Ice {
  public:
    Ice();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    ~Ice();
};

#endif // ICE_HPP