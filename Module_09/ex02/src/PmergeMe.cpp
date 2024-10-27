#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"

static void validateFormat(const std::string &input);

PMergeMe::PMergeMe() : _inputStringVector(), _vectorMergeInsert(), _dequeMergeInsert() {
    std::cout << YELLOW << "🛠️ Default PMergeMe Constructor called 🛠️" << RESET << std::endl;
}

PMergeMe::~PMergeMe() {
    std::cout << RED << "🧨 PMergeMe Destructor called 🧨" << RESET << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe &other) {
    (void)other;
    std::cout << YELLOW << "🖨️ PMergeMe Copy Constructor called 🖨️" << RESET << std::endl;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 PMergeMe Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

// Skip leading zeros as they are ignored by std::atof and std::atoi.
// This ensures consistency when comparing the original string with the converted value, helping to detect anomalies.
static std::size_t findStartIndex(const std::string &value) {

    for (std::size_t i = 0; i < value.length(); i++) {
        if (std::isdigit(value[i]) && value[i] != '0') {
            return i;
        }
    }
    return 0;
}

void PMergeMe::mergeInsertSort(int ac, char **av) {
    parseInput(ac, av);

    _vectorMergeInsert.MergeInsertSort(_inputStringVector);
    _dequeMergeInsert.MergeInsertSort(_inputStringVector);

    _durationMsVector = _vectorMergeInsert._durationMs;
    _durationMsDeque = _dequeMergeInsert._durationMs;
}

void PMergeMe::parseInput(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        _inputStringVector.push_back(av[i]);
    }

    validateOverflow();
    validateDuplicate();
}

void PMergeMe::validateOverflow() {

    for (std::size_t i = 0; i < _inputStringVector.size(); i++) {

        std::stringstream ss, ssWithoutZero;

        const std::string value = _inputStringVector[i];
        validateFormat(value);

        std::size_t indexNumber = findStartIndex(value);

        int result = std::atoi(value.c_str());

        // Since itoa does not exist in standard C++, we use a stringstream to convert the number to a string.
        // Later, we will use the str() method to compare the converted number with the original string.
        ss << result;

        // Skip leading zeros to accurately compare the with the original string.
        // This allows us to check if the input was altered due to reasons like overflow or other anomalies.
        std::string valueWithoutZero = value.substr(indexNumber);

        if (value.find("-") != std::string::npos) {
            ssWithoutZero << "-" << valueWithoutZero.c_str();
        } else {
            ssWithoutZero << valueWithoutZero.c_str();
        }

        if (ss.str() != ssWithoutZero.str()) {
            throw std::overflow_error("❌ Error: Overflow/underflow detected for value: " + value);
        }
    }
}

static void validateFormat(const std::string &input) {
    if (input.empty()) {
        throw std::runtime_error("❌ Error: Input cannot be empty.");
    }

    std::size_t start = 0;
    if (input[0] == '+') {
        if (input.length() == 1) {
            throw std::runtime_error("❌ Error: Input cannot be just a sign.");
        }
        start = 1;
    } else if (input[0] == '-') {
        throw std::runtime_error("❌ Error: Arguments cannot be negative.");
    }

    for (std::size_t i = start; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            throw std::runtime_error("❌ Error: Arguments can only be digits.");
        }
    }
}

void PMergeMe::validateDuplicate() {
    std::set<int> seen;
    int number = 0;
    std::stringstream ss;

    for (std::size_t i = 0; i < _inputStringVector.size(); i++) {
        number = std::atoi(_inputStringVector[i].c_str());

        if (!seen.insert(number).second) {
            ss << "❌ Error: Duplicate argument found at position " << i + 1 << ". Duplicated number: " << number;
            throw std::runtime_error(ss.str());
        }
    }
}

void PMergeMe::printInitialVector() const {
    _vectorMergeInsert.printInitialVector();
}

void PMergeMe::printSortedVector() const {
    _vectorMergeInsert.printSortedVector();
}

void PMergeMe::printInitialDeque() const {
    _dequeMergeInsert.printInitialDeque();
}

void PMergeMe::printSortedDeque() const {
    _dequeMergeInsert.printSortedDeque();
}