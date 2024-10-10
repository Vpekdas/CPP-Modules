#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/colors.hpp"
#include <string>

int main() {
  Animal *animals[100];

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "🐶 Fill the first 50 index with dog. 🐶" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 50; i++) {
    animals[i] = new Dog("Nasus");
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "🐱 Fill the next 50 index with cat. 🐱" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 50; i < 100; i++) {
    animals[i] = new Cat("Yuumi");
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "💭🐶 Display ideas of animals[0]. 💭🐶" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Dog *dog = static_cast<Dog *>(animals[0]);
  for (int i = 0; i < 20; i++) {
    std::cout << CYAN << dog->getIdea(i) << RESET << std::endl;
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "💭🐱 Display ideas of animals[50]. 💭🐱" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Cat *cat = static_cast<Cat *>(animals[50]);
  for (int i = 0; i < 20; i++) {
    std::cout << CYAN << cat->getIdea(i) << RESET << std::endl;
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "🤿 Testing deep copy. 🤿" << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN
            << "🐶🖨️ Creating a dogcopy and setting new idea. 🐶🖨️" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Dog *dogCopy = new Dog("CopyDog");
  dogCopy->setIdea("🆕 New idea for copy dog 🆕");

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "💭🐶🖨️ Display ideas of copied dog. 💭🐶🖨️"
            << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 20; i++) {
    std::cout << CYAN << dogCopy->getIdea(i) << RESET << std::endl;
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "💭🐶 Display ideas of animals[0].  💭🐶" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 20; i++) {
    std::cout << CYAN << dog->getIdea(i) << RESET << std::endl;
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN
            << "🖨️🐱 Creating a catcopy and setting new idea. 🖨️🐱" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  Cat *catCopy = new Cat(*cat);
  catCopy->setIdea("🆕 New idea for copy cat 🆕");

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "💭🐱🖨️ Display ideas of copied cat. 💭🐱🖨️"
            << RESET << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 20; i++) {
    std::cout << CYAN << catCopy->getIdea(i) << RESET << std::endl;
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "💭🐱 Display ideas of animals[50]. 💭🐱" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 20; i++) {
    std::cout << CYAN << cat->getIdea(i) << RESET << std::endl;
  }

  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  std::cout << NEON_GREEN << "🗑️ Releasing all allocated memory. 🗑️" << RESET
            << std::endl;
  std::cout << NEON_PURPLE
            << "--------------------------------------------------------------"
            << RESET << std::endl;
  for (int i = 0; i < 100; i++) {
    delete animals[i];
  }
  delete dogCopy;
  delete catCopy;
}