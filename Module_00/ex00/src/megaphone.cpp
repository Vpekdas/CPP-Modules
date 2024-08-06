#include <cstring>
#include <iostream>
#include <ostream>

// Converts a character to uppercase, ensuring correct behavior for characters with negative values
// by first casting to unsigned char before using std::toupper.
char my_toupper(char ch) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        std::string str(av[i]);
        for (size_t j = 0; j < std::strlen(av[i]); j++) {
            str[j] = my_toupper(av[i][j]);
        }
        std::cout << str;
    }
    std::cout << std::endl;
}