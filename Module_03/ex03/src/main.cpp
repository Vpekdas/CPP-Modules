#include "../includes/ClapTrap.hpp"
#include "../includes/DiamondTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/colors.hpp"

int main() {
    std::string gangplank = "Gangplank";
    std::string illaoi = "Illaoi";
    std::string ekko = "Ekko";
    std::string nautilus = "Nautilus";

    ClapTrap Gangplank(gangplank);
    ScavTrap Illaoi(illaoi);
    FragTrap Ekko(ekko);
    DiamondTrap Nautilus(nautilus);
    Nautilus.whoAmI();
    Nautilus.attack(ekko);
    Nautilus.guardGate();
    Nautilus.highFivesGuys();
}