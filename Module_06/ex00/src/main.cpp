// The following rule applies to the entire module and is not optional.
// For each exercise, the type conversion must be solved using one specific type of casting.
// Your choice will be checked during defense.

// dynamic_cast: Used only with pointers and references to objects. Ensures the result is a valid complete object of the
// requested class.

// static_cast: Converts between pointers to related classes. No runtime safety checks; the programmer must ensure the
// conversion is safe.

// reinterpret_cast: Converts any pointer type to any other pointer type, even of unrelated classes. Performs a binary
// copy of the value.

// const_cast: Manipulates the constness of an object, either adding or removing const.

#include "../include/ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        return 0;
    }

    std::string input = av[1];

    ScalarConverter::convert(input);
}