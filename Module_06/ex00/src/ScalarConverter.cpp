#include "../include/ScalarConverter.hpp"
#include "../include/colors.hpp"

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

void printDisplayableChar(Convertible *convertible);
void printDisplayableInt(Convertible *convertible);
void printDisplayableFloat(Convertible *convertible);
void printDisplayableDouble(Convertible *convertible);
void printDisplayable(Convertible *convertible);

void printNonDisplayable(Convertible *convertible);
void printImpossible(Convertible *convertible);

static const PrintStatus printStatus[] = {
    {CONVERTIBLE_DISPLAYABLE, printDisplayable},
    {CONVERTIBLE_NON_DISPLAYABLE, printNonDisplayable},
    {CONVERTIBLE_IMPOSSIBLE, printImpossible},
};

static const PrintType printTypes[] = {
    {"char", printDisplayableChar},
    {"int", printDisplayableInt},
    {"float", printDisplayableFloat},
    {"double", printDisplayableDouble},
};

void printDisplayableChar(Convertible *convertible) {
    char *result = static_cast<char *>(convertible->value);
    std::cout << CYAN << "char: " << *result << RESET << std::endl;
}

void printDisplayableInt(Convertible *convertible) {
    int *result = static_cast<int *>(convertible->value);
    std::cout << CYAN << "int: " << *result << RESET << std::endl;
};
void printDisplayableFloat(Convertible *convertible) {};
void printDisplayableDouble(Convertible *convertible) {};

void printDisplayable(Convertible *convertible) {
    for (int i = 0; i < CONVERTIBLE_COUNT; i++) {
        if (printTypes[i].type == convertible->type) {
            printTypes[i].printDisplayable(convertible);
            return;
        }
    }
};

void printNonDisplayable(Convertible *convertible) {
    std::cout << RED << convertible->type << ": Non Displayable." << RESET << std::endl;
}

void printImpossible(Convertible *convertible) {
    std::cout << RED << convertible->type << ": Impossible." << RESET << std::endl;
};

void print(Convertible *convertible) {
    for (int i = 0; i < CONVERTIBLE_STATUS_COUNT; i++) {
        if (printStatus[i].status == convertible->status) {
            printStatus[i].printFunctions(convertible);
            return;
        }
    }
}

void ScalarConverter::convert(const std::string &input) {
    Convertible charValue;
    Convertible intValue;

    charValue.type = "char";
    intValue.type = "int";

    convertToChar(&charValue, input);
    convertToInt(&intValue, input);

    print(&charValue);
    print(&intValue);
}
