#include "../includes/Zombie.hpp"
#include "../includes/colors.hpp"

void Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Constructor to initialize a Zombie object and log its creation.
Zombie::Zombie() {
    std::cout << YELLOW << "🧟🛠️ Zombie Constructor called 🧟🛠️" << RESET
              << std::endl;
}

// Constructor to initialize a Zombie object and log its creation.
Zombie::~Zombie() {
    std::cout << RED << "🧟🔫 Zombie Destructor called 🧟🔫" << RESET << std::endl;
}

std::string Zombie::getName() const {
    return name;
}

void Zombie::setName(std::string name) {
    this->name = name;
}