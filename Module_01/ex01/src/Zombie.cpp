#include "../includes/Zombie.hpp"
#include "../includes/colors.hpp"

void Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {
    std::cout << YELLOW << "🧟🛠️ Zombie Constructor called 🧟🛠️" << RESET << std::endl;
}

Zombie::~Zombie() {
    std::cout << RED << "🧟🔫 Zombie Destructor called 🧟🔫" << RESET << std::endl;
}

std::string Zombie::getName() const {
    return _name;
}

void Zombie::setName(std::string name) {
    _name = name;
}