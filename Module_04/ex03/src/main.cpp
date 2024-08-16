#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/colors.hpp"

int main() {

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🌟 Creating a Materia Source to learn Ice and Cure Materia 🌟" << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN
              << "🚨 Attempting to learn 3 more Cure Materia, but the Materia Source has only 4 "
                 "slots available. 🚨"
              << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🦸 Creating characters: Gangplank and Ekko. 🦸" << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    ICharacter *gangplank = new Character("Gangplank");
    ICharacter *ekko = new Character("Ekko");

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🎒 Creating and equipping all learned Materia. 🎒" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;

    AMateria *tmp;
    tmp = src->createMateria("ice");
    gangplank->equip(tmp);
    tmp = src->createMateria("cure");
    gangplank->equip(tmp);

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "✨ Using the first and second Materia. ✨" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    gangplank->use(0, *ekko);
    gangplank->use(1, *ekko);

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🚨 Trying to use an empty slot and going out of bounds. 🚨" << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    gangplank->use(2, *ekko);
    gangplank->use(-3, *ekko);
    gangplank->use(42, *ekko);

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Testing deep copy." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    ICharacter *gangplankCopy = new Character(*dynamic_cast<Character *>(gangplank));
    gangplankCopy->use(0, *ekko);
    gangplankCopy->use(1, *ekko);
    gangplankCopy->unequip(0);
    gangplankCopy->unequip(1);
    gangplankCopy->use(0, *ekko);

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🔄 Unequipping the first Materia and trying to use it. 🔄" << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    gangplank->unequip(0);
    gangplank->use(0, *ekko);

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🚨 Unequipping wrong index. 🚨" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    gangplank->unequip(-42);
    gangplank->unequip(42);
    gangplank->unequip(4);

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "🗑️ Releasing all memory. 🗑️" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    delete ekko;
    delete gangplank;
    delete gangplankCopy;
    delete src;
    return 0;
}