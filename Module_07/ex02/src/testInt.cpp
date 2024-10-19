#include "../include/Array.hpp"
#include "../include/colors.hpp"

void testInt(bool skip) {
    std::string title = "Running tests on integer array.";
    announcementTitle(title);

    std::string message = "Creating an Array of 42 integers using the template and a mirror array using new.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    message = "Filling the template array and mirror array with 42 random integers.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < MAX_VAL; i++) {
        int randomNumber = std::rand();
        numbers[i] = randomNumber;
        mirror[i] = randomNumber;
    }
    std::cout << std::endl;

    std::cout << NEON_GREEN << "[numbers]: " << RESET;
    for (std::size_t i = 0; i < numbers.size(); i++) {
        std::cout << NEON_GREEN << numbers[i] << " " << RESET;
    }
    std::cout << std::endl;

    std::cout << NEON_BLUE << "[mirror]: " << RESET;
    for (std::size_t i = 0; i < numbers.size(); i++) {
        std::cout << NEON_BLUE << mirror[i] << " " << RESET;
    }
    std::cout << std::endl;

    message = "Comparing the template array and mirror array for equality.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] != mirror[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << numbers[i] << ") and ("
                      << mirror[i] << ")" << RESET << std::endl;
        } else {
            std::cout << NEON_CYAN << "✅" << RESET;
        }
    }
    std::cout << std::endl;

    message = "Testing deep copy using the assignment operator.";
    announcementMessage(message);
    displayPressButton(skip);

    Array<int> assignmentArray;
    assignmentArray = numbers;

    std::cout << NEON_ORANGE << "[assignmentArray]: " << RESET;
    for (std::size_t i = 0; i < assignmentArray.size(); i++) {
        std::cout << NEON_ORANGE << assignmentArray[i] << " ";
        if (assignmentArray[i] != numbers[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << assignmentArray[i]
                      << ") and (" << numbers[i] << ")" << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    message = "Replacing values in the original array with 42 and checking if the assignmentArray remains unchanged.";
    announcementMessage(message);
    displayPressButton(skip);

    std::cout << NEON_GREEN << "[numbers]: " << RESET;
    for (std::size_t i = 0; i < numbers.size(); i++) {
        numbers[i] = 42;
        std::cout << NEON_GREEN << numbers[i] << " " << RESET;
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

    Array<int> copyArray(numbers);
    std::cout << NEON_CYAN << "[copyArray]: " << RESET << std::endl;

    for (std::size_t i = 0; i < copyArray.size(); i++) {
        std::cout << NEON_CYAN << copyArray[i] << " ";
        if (copyArray[i] != numbers[i]) {
            std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << copyArray[i] << ") and ("
                      << numbers[i] << ")" << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    message = "Replacing values in the original array with random integers and checking if the copyArray remains "
              "unchanged.";
    displayPressButton(skip);

    announcementMessage(message);

    for (std::size_t i = 0; i < numbers.size(); i++) {
        numbers[i] = std::rand();
    }

    std::cout << NEON_GREEN << "[numbers]: " << RESET;
    for (std::size_t i = 0; i < numbers.size(); i++) {
        std::cout << NEON_GREEN << numbers[i] << " " << RESET;
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
        std::cout << NEON_CYAN << numbers[-42] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        std::cout << NEON_CYAN << "Attempting to access index [420]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << numbers[420] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    try {
        std::cout << NEON_CYAN << "Attempting to access index [42]." << RESET << std::endl;
        displayPressButton(skip);
        std::cout << NEON_CYAN << numbers[42] << RESET << std::endl;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    delete[] mirror;

    title = "End of tests on integer array.";
    announcementTitle(title);
}