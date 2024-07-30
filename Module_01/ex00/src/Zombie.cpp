#include "../includes/Zombie.hpp"
#include "../includes/colors.hpp"

void Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name) {
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}

Zombie::~Zombie() {
    std::cout << RED << "🧟🔫 Zombie Destructor called 🧟🔫" << RESET << std::endl;
}

std::string Zombie::getName() const {
    return name;
}

void Zombie::setName(std::string name) {
    this->name = name;
}