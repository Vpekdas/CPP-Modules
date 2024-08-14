#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

class Cure {
  public:
    Cure();

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
    ~Cure();
};

#endif // CURE_HPP