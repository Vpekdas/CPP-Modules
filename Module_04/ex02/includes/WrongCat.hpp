#ifndef WRONG_WrongCAT_HPP
#define WRONG_WrongCAT_HPP

#include "../includes/WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat();
};

#endif // WRONG_CAT_HPP