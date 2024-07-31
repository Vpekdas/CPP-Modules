#include "../includes/Zombie.hpp"

int main() {
    std::string name = "Zombie 1";
    std::cout << NRED << "Zombie allocated in stack witch newZombie -> " << RESET;
    Zombie *zombie = newZombie(name);
    zombie->announce();
    delete zombie;

    std::cout << NGREEN << "Zombie allocated in heap with randomChump -> " << RESET;
    randomChump(name);
}