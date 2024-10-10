#include "../include/Zombie.hpp"
#include "../include/colors.hpp"

int main() {

  std::string name;
  int zombieNb;
  Zombie *horde;

  name = NEON_GREEN "🧟 Z0mb13 🧟" RESET;
  zombieNb = 42;
  std::cout << NEON_CYAN << "Name is : " << name << RESET << std::endl;
  std::cout << NEON_CYAN << "Number is : " << zombieNb << RESET << std::endl;
  horde = zombieHorde(zombieNb, name);

  delete[] horde;
  std::cout << NEON_PURPLE << "---------------------------------" << RESET
            << std::endl;

  name = "";
  zombieNb = 1;
  std::cout << NEON_CYAN << "Name is : " << name << RESET << std::endl;
  std::cout << NEON_CYAN << "Number is : " << zombieNb << RESET << std::endl;
  horde = zombieHorde(zombieNb, name);
  delete[] horde;
  std::cout << NEON_PURPLE << "---------------------------------" << RESET
            << std::endl;

  name = "zero zombie";
  zombieNb = 0;
  std::cout << NEON_CYAN << "Name is : " << name << RESET << std::endl;
  std::cout << NEON_CYAN << "Number is : " << zombieNb << RESET << std::endl;
  horde = zombieHorde(zombieNb, name);
  delete[] horde;
  std::cout << NEON_PURPLE << "---------------------------------" << RESET
            << std::endl;

  name = "negative zombie";
  zombieNb = -42;
  std::cout << NEON_CYAN << "Name is : " << name << RESET << std::endl;
  std::cout << NEON_CYAN << "Number is : " << zombieNb << RESET << std::endl;
  horde = zombieHorde(zombieNb, name);
  delete[] horde;
  std::cout << NEON_PURPLE << "---------------------------------" << RESET
            << std::endl;
}