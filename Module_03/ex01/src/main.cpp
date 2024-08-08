#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"

int main() {
    std::string gangplank = "Gangplank";
    std::string illaoi = "Illaoi";
    std::string ekko = "Ekko";

    ClapTrap Gangplank(gangplank);
    ClapTrap Illaoi(illaoi);
    ScavTrap Ekko(ekko);

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Ekko will attack Gangplank 6 times" << RESET << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    for (int i = 0; i < 6; i++) {
        Ekko.attack(gangplank);
        Gangplank.takeDamage(S_ATTACK_DAMAGE);
    }

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Gangplank try to attack but he is dead" << RESET << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    Gangplank.attack(ekko);

    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Ekko will use his guard skills " << RESET << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    Ekko.guardGate();

    Ekko.attack(illaoi);
    Illaoi.takeDamage(S_ATTACK_DAMAGE);
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    std::cout << PURPLE << "Illaoi will use all of her energy and heal with the last one " << RESET
              << std::endl;
    std::cout << PURPLE << "-------------------------" << RESET << std::endl;
    for (int i = 0; i < C_ENERGY_POINTS / 1 - 1; i++) {
        Illaoi.attack(ekko);
        Ekko.takeDamage(C_ATTACK_DAMAGE);
    }
    Illaoi.beRepaired(S_ATTACK_DAMAGE);
    Illaoi.attack(ekko);
    Ekko.takeDamage(C_ATTACK_DAMAGE);
}