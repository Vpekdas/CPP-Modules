#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Fire.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Lightning.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/colors.hpp"

int main() {

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🌟 Creating a Materia Source to learn 5 abilities. 🌟" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    IMateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Lightning());
    source->learnMateria(new Fire());
    source->learnMateria(new Fire());

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🌟 Creating a Materia Source to learn 4 abilities. 🌟" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    IMateriaSource *secondarySource = new MateriaSource();
    secondarySource->learnMateria(new Ice());
    secondarySource->learnMateria(new Cure());
    secondarySource->learnMateria(new Fire());
    secondarySource->learnMateria(new Lightning());

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🦸 Creating characters: Cloud and Tifa. 🦸" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    ICharacter *cloud = new Character("Cloud");
    ICharacter *tifa = new Character("Tifa");

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🎒 Creating and equipping all learned Materia. 🎒" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "📚 Learning and using all materias. 📚" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    AMateria *tmp;
    tmp = secondarySource->createMateria("ice");
    cloud->equip(tmp);
    tmp = secondarySource->createMateria("fire");
    cloud->equip(tmp);
    tmp = secondarySource->createMateria("cure");
    cloud->equip(tmp);
    tmp = secondarySource->createMateria("lightning");
    cloud->equip(tmp);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "✨ Using all materias. ✨" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        cloud->use(i, *tifa);
    }

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🚨 Attempting to equip the same Materia twice. This should trigger an error. 🚨" << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    cloud->equip(tmp);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🚨 Attempting to use an invalid index and out-of-bounds slot. 🚨" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    cloud->use(-42, *tifa);
    cloud->use(42, *tifa);
    cloud->use(4, *tifa);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🤿 Testing deep copy. 🤿" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🦸 Creating a copy of cloud. 🦸" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    ICharacter *cloudCopy = new Character(*dynamic_cast<Character *>(cloud));

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "✨ Trying to use the Materia with a copy and unequipping first materias. ✨" << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    cloudCopy->use(0, *tifa);
    cloudCopy->use(1, *tifa);
    cloudCopy->unequip(0);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🔄 Unequipping the first Materia and trying to use it. 🔄" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    cloud->unequip(0);
    cloud->use(0, *tifa);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🚨 Attempting to unequip an invalid index and out-of-bounds slot. 🚨" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    cloud->unequip(0);
    cloud->unequip(-42);
    cloud->unequip(42);
    cloud->unequip(4);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🧱 Taking a Materia from the floor (Not requested in subject). 🧱" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    cloud->equipFromFloor(0);
    cloud->use(0, *tifa);

    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NGREEN << "🗑️ Releasing all memory. 🗑️" << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    delete tifa;
    delete cloud;
    delete cloudCopy;
    delete source;
    delete secondarySource;

    return 0;
}