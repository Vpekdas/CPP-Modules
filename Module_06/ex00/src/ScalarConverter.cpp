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

// This function checks if the input string is a valid format for an integer.
// It ensures that the string contains at most one 'f', one operator ('+' or '-'), and one dot ('.').
// It also ensures that the string does not end with a dot.
bool isValidFormat(const std::string &input) {
    const char *str = input.c_str();
    int fNumber = 0;
    int operatorNumber = 0;
    int dotNumber = 0;

    for (std::size_t i = 0; i < input.length(); i++) {
        if (std::isalpha(str[i]) && str[i] != 'f' && input.length() > 1) {
            return false;
        } else if (str[i] == 'f') {
            if (i != input.length() - 1) {
                return false;
            }
            fNumber++;
        } else if (str[i] == '-' || str[i] == '+') {
            if (i != 0) {
                return false;
            }
            operatorNumber++;
        } else if (str[i] == '.') {
            dotNumber++;
        } else if (std::isdigit(str[i])) {
        }
    }
    if (fNumber > 1 || operatorNumber > 1 || dotNumber > 1) {
        return false;
    } else if (str[input.length() - 1] == '.') {
        return false;
    }
    return true;
}

void ScalarConverter::convert(const std::string &input) {
    Convertible charValue;
    Convertible intValue;
    Convertible floatValue;
    Convertible doubleValue;

    convertToChar(&charValue, input);
    convertToInt(&intValue, input);
    convertToFloat(&floatValue, input);
    convertToDouble(&doubleValue, input);

    print(&charValue);
    print(&intValue);
    print(&floatValue);
    print(&doubleValue);

    if (charValue.status == CONVERTIBLE_DISPLAYABLE) {
        delete static_cast<char *>(charValue.value);
    }
    if (intValue.status == CONVERTIBLE_DISPLAYABLE) {
        delete static_cast<int *>(intValue.value);
    }
    if (floatValue.status == CONVERTIBLE_DISPLAYABLE) {
        delete static_cast<float *>(floatValue.value);
    }
    if (doubleValue.status == CONVERTIBLE_DISPLAYABLE) {
        delete static_cast<double *>(doubleValue.value);
    }
}
