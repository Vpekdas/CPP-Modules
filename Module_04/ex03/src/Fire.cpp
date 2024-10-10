#include "../include/Fire.hpp"
#include "../include/ICharacter.hpp"
#include "../include/colors.hpp"

Fire::Fire() : AMateria("fire") {
  std::cout << YELLOW << "🛠️ Default Fire Constructor called 🛠️" << RESET
            << std::endl;
}

Fire::~Fire() {
  std::cout << RED << "🧨 Fire Destructor called 🧨" << RESET << std::endl;
}

Fire::Fire(const Fire &other) : AMateria(other) {
  std::cout << YELLOW << "🖨️ Fire Copy Constructor called 🖨️" << RESET
            << std::endl;
}

Fire &Fire::operator=(const Fire &other) {
  // Check for self-assignment
  if (this != &other) {
    AMateria::operator=(other);
  }
  std::cout << YELLOW << "📞 Fire Copy Assignment Operator called 📞" << RESET
            << std::endl;
  return *this;
}

AMateria *Fire::clone() const { return new Fire(*this); }

void Fire::use(ICharacter &target) {
  std::cout << CYAN << " casts 🔥 " << BICYAN << _type << CYAN << " on "
            << NEON_CYAN << target.getName() << RESET << std::endl;
}