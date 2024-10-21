#include "../include/Array.hpp"
#include "../include/colors.hpp"
#include "../include/display.hpp"

// Use an array of tests to avoid a large number of if-else statements.
static const Test tests[] = {
    {"int", testInt}, {"char", testChar}, {"string", testString}, {"float", testFloat}, {"all", testAll}};

// The 'skip' parameter is not used here, but it is included for consistency
// with other function pointers in the structure.
void testAll(bool skip) {
    (void)skip;
    testInt(true);
    testChar(true);
    testString(true);
    testFloat(true);
}

int main() {
    try {
        bool skip = false;
        std::srand(time(NULL));

        std::string input;

        std::cout << BOLD_ITALIC_PINK << "Hi! Please choose a test to run from the following options:" << RESET
                  << std::endl;
        std::cout << NEON_CYAN << "- Int\n- Char\n- String\n- Float\n- All" << RESET << std::endl;

        std::getline(std::cin, input);

        if (std::cin.eof() || input.empty()) {
            std::cout << NEON_YELLOW << "👋 Bye Bye ! 👋" << RESET << std::endl;
            return 0;
        }

        for (int i = 0; i < NUMBER_OF_TESTS; i++) {
            stringToLower(input);
            if (input == "all") {
                skip = true;
            }
            if (tests[i].type == input) {
                tests[i].testFunction(skip);
                return 0;
            }
        }
        std::cerr << NEON_RED << "❌ Error: Your input did not match any available tests. ❌" << RESET << std::endl;
        std::cout << NEON_YELLOW << "👋 Bye Bye ! 👋" << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }
    return 0;
}