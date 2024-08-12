#include "../includes/ICharacter.hpp"
#include "../includes/colors.hpp"

ICharacter::ICharacter() {
    std::cout << YELLOW << "🛠️ Default ICharacter Constructor called 🛠️" << RESET
              << std::endl;
}

ICharacter::ICharacter(const ICharacter &other) {
    std::cout << YELLOW << "🖨️ ICharacter Copy Constructor called 🖨️" << RESET
              << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 ICharacter Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}