#include "../includes/Zombie.hpp"

void Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
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