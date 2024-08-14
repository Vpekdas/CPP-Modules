#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/colors.hpp"

int main() {
    Animal *animals[100];

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Fill the first 50 index with dog." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    for (int i = 0; i < 50; i++) {
        animals[i] = new Dog("Nasus");
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Fill the next 50 index with cat." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    for (int i = 50; i < 100; i++) {
        animals[i] = new Cat("Yuumi");
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Display ideas of animals[0]." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    Dog *dog = static_cast<Dog *>(animals[0]);
    dog->makeSound();
    for (int i = 0; i < 20; i++) {
        std::cout << CYAN << dog->getIdea(i) << RESET << std::endl;
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Display ideas of animals[50]." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    Cat *cat = static_cast<Cat *>(animals[50]);
    cat->makeSound();
    for (int i = 0; i < 20; i++) {
        std::cout << CYAN << cat->getIdea(i) << RESET << std::endl;
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Testing deep copy." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Creating a dogcopy and setting new idea." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    Dog *dogCopy = new Dog("CopyDog");
    dogCopy->setIdea("New idea for original dog");

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Display ideas of copied dog." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    dogCopy->makeSound();
    for (int i = 0; i < 20; i++) {
        std::cout << CYAN << dogCopy->getIdea(i) << RESET << std::endl;
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Display ideas of animals[0]." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    dogCopy->makeSound();
    for (int i = 0; i < 20; i++) {
        std::cout << CYAN << dog->getIdea(i) << RESET << std::endl;
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Creating a catcopy and setting new idea." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    Cat *catCopy = new Cat(*cat);
    catCopy->setIdea("New idea for original cat");

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Display ideas of copied cat." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    catCopy->makeSound();
    for (int i = 0; i < 20; i++) {
        std::cout << CYAN << catCopy->getIdea(i) << RESET << std::endl;
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Display ideas of animals[50]." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    catCopy->makeSound();
    for (int i = 0; i < 20; i++) {
        std::cout << CYAN << cat->getIdea(i) << RESET << std::endl;
    }

    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    std::cout << NGREEN << "Releasing all allocated memory." << RESET << std::endl;
    std::cout << NPURPLE << "--------------------------------------------------------------"
              << RESET << std::endl;
    for (int i = 0; i < 100; i++) {
        delete animals[i];
    }

    delete dogCopy;
    delete catCopy;
}