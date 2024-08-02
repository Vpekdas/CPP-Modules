#include "../includes/Zombie.hpp"
#include "../includes/colors.hpp"


int main() {
    std::string name = "Zombie 1";
    std::cout << NRED << "Zombie allocated in stack witch newZombie." << RESET << std::endl;
    Zombie *zombie = newZombie(name);
    zombie->announce();
    delete zombie;

    std::cout << PURPLE << "---------------------------------------------------" << RESET
              << std::endl;

    std::cout << NGREEN << "Zombie allocated in heap with randomChump." << RESET << std::endl;
    randomChump(name);
}