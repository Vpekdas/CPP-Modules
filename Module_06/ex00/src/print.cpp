#include "../include/print.hpp"

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

void printDisplayableFloat(Convertible *convertible) {
    std::stringstream out;
    float *result = static_cast<float *>(convertible->value);

    out << std::fixed << std::setprecision(convertible->precision) << *result << 'f';

    std::cout << CYAN << "float: " << out.str() << RESET << std::endl;
};

void printDisplayableDouble(Convertible *convertible) {
    std::stringstream out;

    double *result = static_cast<double *>(convertible->value);
    out << std::fixed << std::setprecision(convertible->precision) << *result;

    std::cout << CYAN << "double: " << out.str() << RESET << std::endl;
};

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