#include "../include/ClapTrap.hpp"
#include "../include/DiamondTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/colors.hpp"

int main() {
    std::string gangplank = "Gangplank";
    std::string illaoi = "Illaoi";
    std::string ekko = "Ekko";
    std::string nautilus = "Nautilus";

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Creating instances of each class." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    ScavTrap Gangplank(gangplank);
    ClapTrap Illaoi(illaoi);
    FragTrap Ekko(ekko);
    DiamondTrap Nautilus(nautilus);

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Gangplank attacks Ekko." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Gangplank.attack(ekko);
    Ekko.takeDamage(SCAV_TRAP_ATTACK_DAMAGE);

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Ekko heals themselves." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Ekko.beRepaired(SCAV_TRAP_ATTACK_DAMAGE);

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Illaoi will attack 11 times but she has only 10 energy points." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    for (int i = 0; i < 11; i++) {
        Illaoi.attack(gangplank);
        Gangplank.takeDamage(CLAP_TRAP_ATTACK_DAMAGE);
    }

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Gangplank heals herself." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Gangplank.takeDamage(5);
    Gangplank.beRepaired(5);

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Gangplank uses guardGate." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Gangplank.guardGate();

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Ekko uses high fives, guys." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Ekko.highFivesGuys();

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Nautilus attacks with Gangplank's attack." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Nautilus.attack(gangplank);
    Gangplank.takeDamage(FRAG_TRAP_ATTACK_DAMAGE);

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Nautilus uses high fives, guys." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Nautilus.highFivesGuys();

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Nautilus uses whoAmI." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Nautilus.whoAmI();

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "Nautilus uses guardGate." << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Nautilus.guardGate();
}