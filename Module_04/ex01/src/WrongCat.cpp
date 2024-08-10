#include "../includes/WrongCat.hpp"
#include "../includes/colors.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    setType("WrongCat");
    std::cout << YELLOW << "🛠️ Default WrongCat Constructor called 🛠️" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal(name) {
    setType("WrongCat");
    std::cout << YELLOW << "🛠️ Parameterized WrongCat Constructor called 🛠️" << RESET << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << RED << "🧨 WrongCat Destructor called 🧨" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    setName(other.getName());
    setType(other.getType());
    std::cout << YELLOW << "🖨️ WrongCat Copy Constructor called 🖨️" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    // Check for self-assignment
    if (this != &other) {
        WrongAnimal::operator=(other);
        setName(other.getName());
        setType(other.getType());
    }
    std::cout << YELLOW << "📞 WrongCat Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}
