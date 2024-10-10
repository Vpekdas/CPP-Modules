#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    public:
    Zombie();
    ~Zombie();

    void announce(void);
    std::string getName() const;
    void setName(std::string name);

    private:
    std::string _name;
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif