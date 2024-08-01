#include "../includes/Zombie.hpp"

// Allocate a Zombie object, set its name, and return a pointer to it.
Zombie *newZombie(std::string name) {
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}