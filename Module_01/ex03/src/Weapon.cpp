#include "../include/Weapon.hpp"
#include "../include/colors.hpp"

Weapon::Weapon(const std::string &type) {
  _type = type;
  std::cout << NEON_YELLOW << "🛠️🔫 Weapon Constructor called 🛠️🔫" << RESET
            << std::endl;
}

Weapon::~Weapon() {
  std::cout << NEON_RED << "🧨🔫 Weapon Destructor called 🧨🔫" << RESET
            << std::endl;
}

const std::string &Weapon::getType() { return _type; }

void Weapon::setType(std::string type) { _type = type; }