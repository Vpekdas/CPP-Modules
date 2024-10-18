#include "../include/Array.hpp"
#include <cstddef>

static const Test tests[NUMBER_OF_TESTS] = {
    {"int", testInt}, {"char", testChar}, {"string", testString}, {"float", testFloat}, {"all", testAll}};

void announcementTitle(const std::string &title) {
    std::cout << "\n" << NEON_BLUE << std::setfill('-') << std::setw(title.length() + 3) << RESET << std::endl;
    std::cout << NEON_YELLOW << title << RESET << std::endl;
    std::cout << NEON_BLUE << std::setfill('-') << std::setw(title.length()) << "\n" << RESET << std::endl;
}

void announcementMessage(const std::string &message) {
    std::cout << "\n" << NEON_PURPLE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_GREEN << message << RESET << std::endl;
    std::cout << NEON_PURPLE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

void testAll() {
    testInt();
    testChar();
    testString();
    testFloat();
}

// Converts a character to uppercase, ensuring correct behavior for characters with negative values
// by first casting to unsigned char before using std::toupper.
static char tolower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

void stringToLower(std::string &input) {
    for (std::size_t i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
}

int main() {

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
        if (tests[i].type == input) {
            tests[i].testFunction();
            return 0;
        }
    }
    std::cerr << NEON_RED << "❌ Error: Your input did not match any available tests. ❌" << RESET << std::endl;
    return 1;
}