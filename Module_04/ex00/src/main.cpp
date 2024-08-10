#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/colors.hpp"

int main() {
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN
              << "Creating 3 animals: the first one is a generic animal, the second is a dog, and "
                 "the last is a cat."
              << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    const Animal *myAnimal = new Animal("Animal");
    const Animal *myDog = new Dog("Nasus");
    const Animal *myCat = new Cat("Yuumi");

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Displaying the names of each Animal instance." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << CYAN << "Animal name is " << NCYAN << myAnimal->getName() << RESET << std::endl;
    std::cout << CYAN << "myDog name is " << NCYAN << myDog->getName() << RESET << std::endl;
    std::cout << CYAN << "myCat name is " << NCYAN << myCat->getName() << RESET << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Displaying the sounds made by each animal." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    myAnimal->makeSound();
    myDog->makeSound();
    myCat->makeSound();

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Displaying the type of each animal." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << CYAN << "Animal type is " << NCYAN << myAnimal->getType() << RESET << std::endl;
    std::cout << CYAN << "myDog type is " << NCYAN << myDog->getType() << RESET << std::endl;
    std::cout << CYAN << "myCat type is " << NCYAN << myCat->getType() << RESET << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Creating a WrongAnimal and a WrongCat." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    const WrongAnimal *myWrongAnimal = new WrongAnimal("Wrong Animal");
    const WrongAnimal *myWrongCat = new WrongCat("Wrong Yuumi");

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Displaying the names of each WrongAnimal instance." << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << CYAN << "WrongAnimal name is " << NCYAN << myWrongAnimal->getName() << RESET
              << std::endl;
    std::cout << CYAN << "myWrongCat name is " << NCYAN << myWrongCat->getName() << RESET
              << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Displaying the sounds made by each WrongAnimal instance." << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    myWrongAnimal->makeSound();
    myWrongCat->makeSound();

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Displaying the type of each WrongAnimal instance." << RESET
              << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << CYAN << "WrongAnimal type is " << NCYAN << myWrongAnimal->getType() << RESET
              << std::endl;
    std::cout << CYAN << "myWrongCat type is " << NCYAN << myWrongCat->getType() << RESET
              << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Deleting all classes." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    delete myAnimal;
    delete myDog;
    delete myCat;
    delete myWrongAnimal;
    delete myWrongCat;
}