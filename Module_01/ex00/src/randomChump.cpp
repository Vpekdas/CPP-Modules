#include "../includes/randomChump.hpp"
#include "../includes/Zombie.hpp"

void randomChump(std::string name) {
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}