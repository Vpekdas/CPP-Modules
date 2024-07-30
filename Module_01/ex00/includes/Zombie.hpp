#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
  private:
    std::string name;

  public:
    void announce(void);

    std::string getName() const;
    void setName(std::string name);
    ~Zombie();
};

Zombie *newZombie(std::string name);

#endif