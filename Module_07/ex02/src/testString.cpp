#include "../include/Array.hpp"
#include "../include/colors.hpp"

static std::string generateRandomString() {

    std::string str;

    const std::size_t length = std::rand() % 10 + 1;
    const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    const std::size_t max_index = alphabet.length() - 1;

    for (std::size_t i = 0; i < length; ++i) {
        str += alphabet[std::rand() % max_index];
    }

    return str;
}

void testString(bool skip) {
    std::string title = "Running tests on string array.";
    announcementTitle(title);

    std::string message = "Creating an Array of 42 strings using the template and a mirror array using new.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<std::string> strings(MAX_VAL);
    std::string *mirror = new std::string[MAX_VAL];

    message = "Filling the template array and mirror array with 42 random strings.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < MAX_VAL; i++) {
        std::string randomString = generateRandomString();

        strings[i] = randomString;
        mirror[i] = randomString;
    }
    std::cout << std::endl;

    std::cout << NEON_GREEN << "[strings]: " << RESET;
    for (std::size_t i = 0; i < strings.size(); i++) {
        std::cout << NEON_GREEN << strings[i] << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << NEON_BLUE << "[mirror]: " << RESET;
    for (std::size_t i = 0; i < strings.size(); i++) {
        std::cout << NEON_BLUE << mirror[i] << " " << RESET;
    }
    std::cout << std::endl;

    message = "Comparing the template array and mirror array for equality.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < strings.size(); i++) {
        if (strings[i] != mirror[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << strings[i] << ") and ("
                      << mirror[i] << ")" << RESET << std::endl;
        } else {
            std::cout << NEON_CYAN << "✅" << RESET;
        }
    }
    std::cout << std::endl;

    message = "Testing deep copy using the assignment operator.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<std::string> assignmentArray;
    assignmentArray = strings;

    std::cout << NEON_ORANGE << "[assignmentArray]: " << RESET;
    for (std::size_t i = 0; i < assignmentArray.size(); i++) {
        std::cout << NEON_ORANGE << assignmentArray[i] << " ";
        if (assignmentArray[i] != strings[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << assignmentArray[i]
                      << ") and (" << strings[i] << ")" << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    message = "Replacing values in the original array with 42 and checking if the assignmentArray remains unchanged.";
    announcementMessage(message);
    displayPressButton(skip);

    std::cout << NEON_GREEN << "[strings]: " << RESET;
    for (std::size_t i = 0; i < strings.size(); i++) {
        strings[i] = "Plouf 🤿 !";
        std::cout << NEON_GREEN << strings[i] << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << NEON_ORANGE << "[assignmentArray]: " << RESET;
    for (std::size_t i = 0; i < assignmentArray.size(); i++) {
        std::cout << NEON_ORANGE << assignmentArray[i] << " " << RESET;
    }
    std::cout << std::endl;

    message = "Testing deep copy using the copy constructor.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<std::string> copyArray(strings);
    std::cout << NEON_CYAN << "[copyArray]: " << RESET << std::endl;

    for (std::size_t i = 0; i < copyArray.size(); i++) {
        std::cout << NEON_CYAN << copyArray[i] << " ";
        if (copyArray[i] != strings[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << copyArray[i] << ") and ("
                      << strings[i] << ")" << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    message = "Replacing values in the original array with random strings and checking if the copyArray remains "
              "unchanged.";
    displayPressButton(skip);
    announcementMessage(message);

    for (std::size_t i = 0; i < strings.size(); i++) {
        std::string randomString = generateRandomString();

        strings[i] = randomString;
    }

    std::cout << NEON_GREEN << "[strings]: " << RESET;
    for (std::size_t i = 0; i < strings.size(); i++) {
        std::cout << NEON_GREEN << strings[i] << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << NEON_CYAN << "[copyArray]: " << RESET;
    for (std::size_t i = 0; i < copyArray.size(); i++) {
        std::cout << NEON_CYAN << copyArray[i] << " " << RESET;
    }
    std::cout << std::endl;

    message = "❌ Testing exception handling for out-of-bounds array access. ❌";
    announcementMessage(message);
    displayPressButton(skip);

    try {
        std::cout << NEON_CYAN << "Attempting to access index [-42]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << strings[-42] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        std::cout << NEON_CYAN << "Attempting to access index [420]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << strings[420] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        std::cout << NEON_CYAN << "Attempting to access index [42]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << strings[42] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    delete[] mirror;

    title = "End of tests on string array.";
    announcementTitle(title);
}