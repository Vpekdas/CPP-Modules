#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"

PMergeMe::PMergeMe() : _vectorMergeInsert() {
    std::cout << YELLOW << "🛠️ Default PMergeMe Constructor called 🛠️" << RESET << std::endl;
}

PMergeMe::~PMergeMe() {
    std::cout << RED << "🧨 PMergeMe Destructor called 🧨" << RESET << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe &other) : _vectorMergeInsert(other._vectorMergeInsert) {
    std::cout << YELLOW << "🖨️ PMergeMe Copy Constructor called 🖨️" << RESET << std::endl;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
    // Check for self-assignment
    if (this != &other) {
        _vectorMergeInsert = other._vectorMergeInsert;
    }
    std::cout << YELLOW << "📞 PMergeMe Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void PMergeMe::parseInput(int ac, const char **av) {

    // TODO: Check if all digits, not negative and overflow/underflow.

    for (int i = 1; i < ac; i++) {
        _inputVector.push_back(av[i]);
    }

    _vectorMergeInsert.pushIntToVector(_inputVector);
}