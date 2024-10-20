#include "../include/test.hpp"

// Functions for testing with int arrays.
void incrementByHundred(int &value) {
    value += 100;
}

void randomize(int &value) {
    value = std::rand();
}

// Functions for testing with string arrays.
void uppercase(std::string &str) {
    for (std::size_t i = 0; i < str.length(); i++) {
        if (std::islower(str[i]))
            str[i] -= 32;
    }
}

void lowercase(std::string &str) {
    for (std::size_t i = 0; i < str.length(); i++) {
        if (std::isupper(str[i]))
            str[i] += 32;
    }
}

// Functions for testing with double arrays.
void doubleValue(double &value) {
    value *= 2;
}
