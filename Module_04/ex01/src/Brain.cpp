#include "../includes/Brain.hpp"
#include "../includes/colors.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "idea";
    }
    std::cout << YELLOW << "🛠️ Default Brain Constructor called 🛠️" << RESET << std::endl;
}

Brain::Brain(const std::string &idea) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = idea;
    }
    std::cout << YELLOW << "🛠️ Parameterized Brain Constructor called 🛠️" << RESET
              << std::endl;
}

Brain::~Brain() {
    std::cout << RED << "🧨 Brain Destructor called 🧨" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << YELLOW << "🖨️ Brain Copy Constructor called 🖨️" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    // Check for self-assignment
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    std::cout << YELLOW << "📞 Brain Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

std::string &Brain::getIdea(int &index) {
    return _ideas[index];
}

void Brain::setIdea(const std::string &newIdea) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = newIdea;
    }
}