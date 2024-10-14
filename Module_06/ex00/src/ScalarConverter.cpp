#include "../include/ScalarConverter.hpp"
#include "../include/colors.hpp"

void print(Convertible *convertible);

ScalarConverter::ScalarConverter() {
    std::cout << YELLOW << "🛠️ Default ScalarConverter Constructor called 🛠️" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << RED << "🧨 ScalarConverter Destructor called 🧨" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
    std::cout << YELLOW << "🖨️ ScalarConverter Copy Constructor called 🖨️" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 ScalarConverter Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void ScalarConverter::convert(const std::string &input) {
    Convertible charValue;
    Convertible intValue;
    Convertible floatValue;

    convertToChar(&charValue, input);
    convertToInt(&intValue, input);
    convertToFloat(&floatValue, input);

    print(&charValue);
    print(&intValue);
    print(&floatValue);
}
