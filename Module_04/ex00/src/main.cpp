#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/colors.hpp"

int main() {
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN
              << "🐾🐶🐱 Creating 3 animals: the first one is a generic animal, "
                 "the second is a dog, and "
                 "the last is a cat. 🐾🐶🐱"
              << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    const Animal *myAnimal = new Animal("Animal");
    const Animal *myDog = new Dog("Nasus");
    const Animal *myCat = new Cat("Yuumi");

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "📋 Displaying the names of each Animal instance. 📋" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << CYAN << "🐾 Animal name is " << NEON_CYAN << myAnimal->getName() << RESET << std::endl;
    std::cout << CYAN << "🐶 myDog name is " << NEON_CYAN << myDog->getName() << RESET << std::endl;
    std::cout << CYAN << "🐱 myCat name is " << NEON_CYAN << myCat->getName() << RESET << std::endl;

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "🔊 Displaying the sounds made by each animal. 🔊" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    myAnimal->makeSound();
    myDog->makeSound();
    myCat->makeSound();

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "🔍 Displaying the type of each animal. 🔍" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << CYAN << "🐾 Animal type is " << NEON_CYAN << myAnimal->getType() << RESET << std::endl;
    std::cout << CYAN << "🐶 myDog type is " << NEON_CYAN << myDog->getType() << RESET << std::endl;
    std::cout << CYAN << "🐱 myCat type is " << NEON_CYAN << myCat->getType() << RESET << std::endl;

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "⛔🐾🐱 Creating a WrongAnimal and a WrongCat. ⛔🐾🐱" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    const WrongAnimal *myWrongAnimal = new WrongAnimal("Wrong Animal");
    const WrongAnimal *myWrongCat = new WrongCat("Wrong Yuumi");

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "📋⛔ Displaying the names of each WrongAnimal instance. 📋⛔" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << CYAN << "⛔🐾 WrongAnimal name is " << NEON_CYAN << myWrongAnimal->getName() << RESET << std::endl;
    std::cout << CYAN << "⛔🐱 myWrongCat name is " << NEON_CYAN << myWrongCat->getName() << RESET << std::endl;

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "⛔🔊 Displaying the sounds made by each WrongAnimal instance. ⛔🔊" << RESET
              << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    myWrongAnimal->makeSound();
    myWrongCat->makeSound();

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "⛔🔍 Displaying the type of each WrongAnimal instance. ⛔🔍" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << CYAN << "⛔🐾 WrongAnimal type is " << NEON_CYAN << myWrongAnimal->getType() << RESET << std::endl;
    std::cout << CYAN << "⛔🐱 myWrongCat type is " << NEON_CYAN << myWrongCat->getType() << RESET << std::endl;

    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    std::cout << NEON_GREEN << "🗑️ Releasing memory for all dynamically allocated objects. 🗑️" << RESET << std::endl;
    std::cout << NEON_PURPLE << "--------------------------------------------------------------" << RESET << std::endl;
    delete myAnimal;
    delete myDog;
    delete myCat;
    delete myWrongAnimal;
    delete myWrongCat;
}