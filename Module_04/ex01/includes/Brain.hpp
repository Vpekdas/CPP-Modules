#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
  public:
    Brain();
    Brain(const std::string &idea);
    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    std::string &getIdea(int &index);

  private:
    std::string _ideas[100];
};

#endif // BRAIN_HPP