#include "../includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
    if (N < 0) {
        std::cout << NRED << "Error: The number of zombies in a horde must be at least 0." << RESET
                  << std::endl;
        return 0;
    }
    Zombie *zombieHorde = new Zombie[N]();
    for (int i = 0; i < N; i++) {
        zombieHorde[i].setName(name);
        zombieHorde[i].announce();
    }
    return zombieHorde;
}