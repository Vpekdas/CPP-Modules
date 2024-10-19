#include "../include/Array.hpp"
#include "../include/colors.hpp"

void testChar(bool skip) {
    std::string title = "Running tests on character array.";
    announcementTitle(title);

    std::string message = "Creating an Array of 42 characters using the template and a mirror array using new.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<char> characters(MAX_VAL);
    char *mirror = new char[MAX_VAL];

    message = "Filling the template array and mirror array with 42 random characters.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < MAX_VAL; i++) {
        char randomCharacter;
        if (i % 2 == 0) {
            randomCharacter = static_cast<char>('a' + std::rand() % 26);
        } else {
            randomCharacter = static_cast<char>('A' + std::rand() % 26);
        }
        characters[i] = randomCharacter;
        mirror[i] = randomCharacter;
    }
    std::cout << std::endl;

    std::cout << NEON_GREEN << "[characters]: " << RESET;
    for (std::size_t i = 0; i < characters.size(); i++) {
        std::cout << NEON_GREEN << characters[i] << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << NEON_BLUE << "[mirror]: " << RESET;
    for (std::size_t i = 0; i < characters.size(); i++) {
        std::cout << NEON_BLUE << mirror[i] << " " << RESET;
    }
    std::cout << std::endl;

    message = "Comparing the template array and mirror array for equality.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < characters.size(); i++) {
        if (characters[i] != mirror[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << characters[i]
                      << ") and (" << mirror[i] << ")" << RESET << std::endl;
        } else {
            std::cout << NEON_CYAN << "✅" << RESET;
        }
    }
    std::cout << std::endl;

    message = "Testing deep copy using the assignment operator.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<char> assignmentArray;
    assignmentArray = characters;

    std::cout << NEON_ORANGE << "[assignmentArray]: " << RESET;
    for (std::size_t i = 0; i < assignmentArray.size(); i++) {
        std::cout << NEON_ORANGE << assignmentArray[i] << " ";
        if (assignmentArray[i] != characters[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << assignmentArray[i]
                      << ") and (" << characters[i] << ")" << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    message = "Replacing values in the original array with 42 and checking if the assignmentArray remains unchanged.";
    announcementMessage(message);
    displayPressButton(skip);

    std::cout << NEON_GREEN << "[characters]: " << RESET;
    for (std::size_t i = 0; i < characters.size(); i++) {
        characters[i] = 42;
        std::cout << NEON_GREEN << characters[i] << " " << RESET;
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

    Array<char> copyArray(characters);
    std::cout << NEON_CYAN << "[copyArray]: " << RESET << std::endl;

    for (std::size_t i = 0; i < copyArray.size(); i++) {
        std::cout << NEON_CYAN << copyArray[i] << " ";
        if (copyArray[i] != characters[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << copyArray[i] << ") and ("
                      << characters[i] << ")" << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    message = "Replacing values in the original array with random characters and checking if the copyArray remains "
              "unchanged.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < characters.size(); i++) {
        char randomCharacter;
        if (i % 2 == 0) {
            randomCharacter = static_cast<char>('a' + std::rand() % 26);
        } else {
            randomCharacter = static_cast<char>('A' + std::rand() % 26);
        }
        characters[i] = randomCharacter;
    }

    std::cout << NEON_GREEN << "[characters]: " << RESET;
    for (std::size_t i = 0; i < characters.size(); i++) {
        std::cout << NEON_GREEN << characters[i] << " " << RESET;
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
        std::cout << NEON_CYAN << characters[-42] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        std::cout << NEON_CYAN << "Attempting to access index [420]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << characters[420] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        std::cout << NEON_CYAN << "Attempting to access index [42]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << characters[42] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    delete[] mirror;

    title = "End of tests on character array.";
    announcementTitle(title);
}