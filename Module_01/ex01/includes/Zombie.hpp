#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Zombie {
  private:
    std::string name;

  public:
    ~Zombie();

    void announce(void);

    std::string getName() const;
    void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif