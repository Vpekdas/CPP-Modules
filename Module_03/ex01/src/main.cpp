#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/colors.hpp"

int main() {
  std::string gangplank = "Gangplank";
  std::string illaoi = "Illaoi";
  std::string ekko = "Ekko";

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "Creating instances of each class." << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  ScavTrap Gangplank(gangplank);
  ClapTrap Illaoi(illaoi);
  ClapTrap Ekko(ekko);

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "Gangplank reduced Ekko's hit points to 0."
            << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 6; i++) {
    Gangplank.attack(ekko);
    Ekko.takeDamage(SCAV_TRAP_ATTACK_DAMAGE);
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN
            << "Ekko will try to heal himself but has 0 hit points." << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Ekko.beRepaired(SCAV_TRAP_ATTACK_DAMAGE);

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN
            << "Illaoi will attack 11 times but she has only 10 energy points."
            << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 11; i++) {
    Illaoi.attack(gangplank);
    Gangplank.takeDamage(CLAP_TRAP_ATTACK_DAMAGE);
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "Gangplank heals herself." << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Gangplank.takeDamage(5);
  Gangplank.beRepaired(5);

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "Gangplank uses guardGate." << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Gangplank.guardGate();
}