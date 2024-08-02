#include "../includes/Zombie.hpp"
#include "../includes/colors.hpp"

// Print the zombie's announcement message to standard output.
void Zombie::announce() {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Default constructor for the Zombie class, prints a construction message.
Zombie::Zombie() {
    std::cout << YELLOW << "🧟🛠️ Zombie Constructor called 🧟🛠️" << RESET << std::endl;
}

// Destructor for the Zombie class, prints a destruction message.
Zombie::~Zombie() {
    std::cout << RED << "🧟🔫 Zombie Destructor called 🧟🔫" << RESET << std::endl;
}

// Getter for the Zombie's name attribute.
std::string Zombie::getName() const {
    return name;
}

// Setter for the Zombie's name attribute.
void Zombie::setName(std::string name) {
    this->name = name;
}