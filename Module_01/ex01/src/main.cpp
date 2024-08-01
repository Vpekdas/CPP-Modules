#include "../includes/Zombie.hpp"

int main() {

    std::string name;
    int zombieNb;
    Zombie *horde;

    name = NGREEN "🧟 Z0mb13 🧟" RESET;
    zombieNb = 42;
    std::cout << NCYAN << "Name is : " << name << RESET << std::endl;
    std::cout << NCYAN << "Number is : " << zombieNb << RESET << std::endl;
    horde = zombieHorde(zombieNb, name);

    delete[] horde;
    std::cout << NPURPLE << "---------------------------------" << RESET << std::endl;

    name = "";
    zombieNb = 1;
    std::cout << NCYAN << "Name is : " << name << RESET << std::endl;
    std::cout << NCYAN << "Number is : " << zombieNb << RESET << std::endl;
    horde = zombieHorde(zombieNb, name);
    delete[] horde;
    std::cout << NPURPLE << "---------------------------------" << RESET << std::endl;

    name = "zero zombie";
    zombieNb = 0;
    std::cout << NCYAN << "Name is : " << name << RESET << std::endl;
    std::cout << NCYAN << "Number is : " << zombieNb << RESET << std::endl;
    horde = zombieHorde(zombieNb, name);
    delete[] horde;
    std::cout << NPURPLE << "---------------------------------" << RESET << std::endl;

    name = "negative zombie";
    zombieNb = -42;
    std::cout << NCYAN << "Name is : " << name << RESET << std::endl;
    std::cout << NCYAN << "Number is : " << zombieNb << RESET << std::endl;
    horde = zombieHorde(zombieNb, name);
    delete[] horde;
    std::cout << NPURPLE << "---------------------------------" << RESET << std::endl;
}