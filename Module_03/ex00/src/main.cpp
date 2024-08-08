#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"

int main() {
    std::string name = "GANGPLANK";
    std::string name2 = "ILLAOI";
    std::string name3 = "EKKO";

    ClapTrap Gangplank(name);
    ClapTrap Illaoi(name2);
    ClapTrap Ekko(name3);

    std::cout << NCYAN << "Gangplank will attack MAX_HEALTH - 1 times" << RESET << std::endl;
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;

    for (int i = 0; i < MAX_HEALTH - 1; i++) {
        Gangplank.attack("EKKO");
        Ekko.takeDamage(ATTACK_DAMAGE);
    }

    Illaoi.attack("Ekko");
    Ekko.takeDamage(ATTACK_DAMAGE);
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;
    std::cout << NCYAN << "Ekko will try to repair himself but he is dead" << RESET << std::endl;
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;
    Ekko.beRepaired(ATTACK_DAMAGE);

    Illaoi.attack("GANPLANK");
    Gangplank.takeDamage(ATTACK_DAMAGE);
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;
    std::cout << NCYAN << "Gangplank will repair himself" << RESET << std::endl;
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;
    Gangplank.beRepaired(ATTACK_DAMAGE);

    Illaoi.attack("GANGPLANK");
    Gangplank.takeDamage(ATTACK_DAMAGE);
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;
    std::cout << NCYAN << "Gangplank will try to repair himself but has no energy" << RESET
              << std::endl;
    std::cout << NYELLOW << "------------------------------------" << RESET << std::endl;
    Gangplank.beRepaired(ATTACK_DAMAGE);
}