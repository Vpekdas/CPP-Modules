#include "../includes/Zombie.hpp"

// Instantiate a Zombie, assign it a name, and announce a message.
void randomChump(std::string name) {
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}