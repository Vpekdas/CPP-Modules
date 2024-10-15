#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include "../include/colors.hpp"
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

bool isValidFormat(const std::string &input);
int skipZeroAndSign(const std::string &input);
int countPrecision(const std::string &input);
bool isContainingDigit(const std::string &input);

#define CONVERTIBLE_COUNT 4

enum ConvertibleStatus {
    CONVERTIBLE_DISPLAYABLE,
    CONVERTIBLE_NON_DISPLAYABLE,
    CONVERTIBLE_IMPOSSIBLE,
    CONVERTIBLE_STATUS_COUNT
};

struct Convertible {
    ConvertibleStatus status;
    void *value;
    std::string type;
    int precision;
};

typedef void (*PrintFunction)(Convertible *convertible);

struct PrintType {
    std::string type;
    PrintFunction printDisplayable;
};

struct PrintStatus {
    ConvertibleStatus status;
    PrintFunction printFunctions;
};

void convertToChar(Convertible *convertible, const std::string &input);
void convertToInt(Convertible *convertible, const std::string &input);
void convertToFloat(Convertible *convertible, const std::string &input);
void convertToDouble(Convertible *convertible, const std::string &input);

class ScalarConverter {
    public:
    static void convert(const std::string &input);

    private:
    // Default constructor
    ScalarConverter();

    // Copy Constructor
    ScalarConverter(const ScalarConverter &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    ScalarConverter &operator=(const ScalarConverter &other);

    // Default Destructor
    ~ScalarConverter();
};

#endif // SCALAR_CONVERTER_HPP