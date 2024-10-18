#include "../include/Array.hpp"
#include "../include/colors.hpp"

// Function to generate a random float within a specified range [min, max]
// This function ensures a uniform distribution of random floats within the given range
static float generateRandomFloat(float min = 0.0f, float max = 100.0f) {
    float random = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    return min + random * (max - min);
}

void testFloat() {
    try {
        std::string title = "Running tests on float array.";
        announcementTitle(title);

        std::string message = "Creating an Array of 42 floats using the template and a mirror array using new.";
        announcementMessage(message);

        Array<float> numbers(MAX_VAL);
        float *mirror = new float[MAX_VAL];

        message = "Filling the template array and mirror array with 42 random floats.";
        announcementMessage(message);

        for (std::size_t i = 0; i < MAX_VAL; i++) {
            float randomNumber = generateRandomFloat();
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

        for (std::size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] != mirror[i]) {
                std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << numbers[i]
                          << ") and (" << mirror[i] << ")" << RESET << std::endl;
            } else {
                std::cout << NEON_CYAN << "✅" << RESET;
            }
        }
        std::cout << std::endl;

        message = "Testing deep copy using the assignment operator.";
        announcementMessage(message);

        Array<float> assignmentArray;
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

        message =
            "Replacing values in the original array with 42 and checking if the assignmentArray remains unchanged.";
        announcementMessage(message);

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

        Array<float> copyArray(numbers);
        std::cout << NEON_CYAN << "[copyArray]: " << RESET << std::endl;

        for (std::size_t i = 0; i < copyArray.size(); i++) {
            std::cout << NEON_CYAN << copyArray[i] << " ";
            if (copyArray[i] != numbers[i]) {
                std::cerr << NEON_RED << "Error: number at index " << i << " is not the same (" << copyArray[i]
                          << ") and (" << numbers[i] << ")" << RESET << std::endl;
            }
        }
        std::cout << std::endl;

        message = "Replacing values in the original array with random floats and checking if the copyArray remains "
                  "unchanged.";
        announcementMessage(message);

        for (std::size_t i = 0; i < numbers.size(); i++) {
            numbers[i] = generateRandomFloat();
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

        try {
            std::cout << NEON_CYAN << "Attempting to access index [-42]." << RESET << std::endl;
            std::cout << NEON_CYAN << numbers[-42] << RESET << std::endl;
        } catch (std::exception &ex) {
            std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
        }

        try {
            std::cout << NEON_CYAN << "Attempting to access index [420]." << RESET << std::endl;
            std::cout << NEON_CYAN << numbers[420] << RESET << std::endl;
        } catch (std::exception &ex) {
            std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
        }

        try {
            std::cout << NEON_CYAN << "Attempting to access index [42]." << RESET << std::endl;
            std::cout << NEON_CYAN << numbers[42] << RESET << std::endl;
        } catch (std::exception &ex) {
            std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
        }

        std::cout << std::endl;

        delete[] mirror;
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }
}