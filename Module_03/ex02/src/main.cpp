#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"

int main() {
    std::string gangplank = "Gangplank";
    std::string illaoi = "Illaoi";
    std::string ekko = "Ekko";

    ClapTrap Gangplank(gangplank);
    ScavTrap Illaoi(illaoi);
    FragTrap Ekko(ekko);

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Ekko will attack 4 times Illaoi put her hitPoint to 0." << RESET
              << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        Ekko.attack(illaoi);
        Illaoi.takeDamage(FRAG_TRAP_ATTACK_DAMAGE);
    }

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Illaoi will try to repair but she has not hitPoint." << RESET
              << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    Illaoi.beRepaired(10);

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Gangplank try to heal but he full hitPoint." << RESET << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    Gangplank.beRepaired(10);

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Ekko fist bump." << RESET << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    Ekko.highFivesGuys();
}