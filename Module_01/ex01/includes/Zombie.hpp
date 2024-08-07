#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Zombie {
  public:
    Zombie();
    ~Zombie();

    std::string getName() const;
    void setName(std::string name);

    void announce(void);

  private:
    std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif