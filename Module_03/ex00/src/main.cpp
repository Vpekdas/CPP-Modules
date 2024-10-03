#include "../includes/ClapTrap.hpp"
#include "../includes/colors.hpp"

int main() {
    std::string gangplank = "Gangplank";
    std::string illaoi = "Illaoi";
    std::string ekko = "Ekko";

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Creating instances of each class." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    ClapTrap Gangplank(gangplank);
    ClapTrap Illaoi(illaoi);
    ClapTrap Ekko(ekko);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Gangplank reduced Ekko's hit points to 0." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Gangplank.attack(ekko);
    Ekko.takeDamage(10); // Used 10 attack points because ClapTrap has 0 attack damage.

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Ekko will try to heal himself but has 0 hit points." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Ekko.beRepaired(10);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Illaoi will attack 11 times but she has only 10 energy points." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    for (int i = 0; i < 11; i++) {
        Illaoi.attack(gangplank);
        Gangplank.takeDamage(CLAP_TRAP_ATTACK_DAMAGE);
    }

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "Gangplank heals herself." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    Gangplank.takeDamage(5);
    Gangplank.beRepaired(5);
}