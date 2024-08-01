#include "../includes/Zombie.hpp"

// Display the zombie's name followed by a specific message.
void Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Constructor that displays a message.
Zombie::Zombie() {
    std::cout << YELLOW << "🧟🛠️ Zombie Constructor called 🧟🛠️" << RESET
              << std::endl;
}

// Destructor that displays a message.
Zombie::~Zombie() {
    std::cout << RED << "🧟🔫 Zombie Destructor called 🧟🔫" << RESET << std::endl;
}

// Returns the name of the Zombie instance.
std::string Zombie::getName() const {
    return name;
}

// Sets the name of the current Zombie instance.
void Zombie::setName(std::string name) {
    this->name = name;
}