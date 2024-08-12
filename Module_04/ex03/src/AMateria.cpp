#include "../includes/AMateria.hpp"
#include "../includes/colors.hpp"

AMateria::AMateria() {
    std::cout << YELLOW << "🛠️ Default AMateria Constructor called 🛠️" << RESET
              << std::endl;
}

AMateria::AMateria(std::string const &type) {
    std::cout << YELLOW << "🛠️ Parameterized AMateria Constructor called 🛠️" << RESET
              << std::endl;
}
AMateria::~AMateria() {
    std::cout << RED << "🧨 AMateria Destructor called 🧨" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other) {
    std::cout << YELLOW << "🖨️ AMateria Copy Constructor called 🖨️" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 AMateria Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}