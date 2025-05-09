#include "../include/display.hpp"
#include "../include/easyfind.hpp"
#include "../include/test.hpp"

static const TestFunction testFunctions[] = {{"vector", testVector}, {"list", testList}, {"all", testAll}};

// We don't need to handle associative containers like set, map, multiset or multimap.
int main() {
    try {
        bool skip = false;
        std::string input;
        std::srand(time(NULL));

        std::cout << BOLD_ITALIC_PINK << "Hi! Please choose a test to run from the following options:" << RESET
                  << std::endl;
        std::cout << NEON_CYAN << "- vector\n- list\n- All" << RESET << std::endl;

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
            if (testFunctions[i].type == input) {
                testFunctions[i].test(skip);
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