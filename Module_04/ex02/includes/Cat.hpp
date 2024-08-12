#ifndef CAT_HPP
#define CAT_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
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

    std::string &getIdea(int index) const;
	void setIdea(const std::string &newIdea);
    void makeSound() const;

  private:
    Brain *_brain;
};

#endif // CAT_HPP