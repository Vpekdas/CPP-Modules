#include "../include/test.hpp"

void testInt(bool skip) {
    const std::string title = "Running tests on integer array.";
    announcementTitle(title);

    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << NEON_CYAN << "Initial Array:" << RESET << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << NEON_CYAN << intArray[i] << " " << RESET;
    }
    std::cout << std::endl;

    {
        const std::string message = "calling function incrementByHundred.";
        announcementMessage(message);
        displayPressButton(skip);

        ::iter(intArray, 5, incrementByHundred);
        for (int i = 0; i < 5; ++i) {
            std::cout << NEON_PURPLE << intArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }

    {
        const std::string message = "calling function randomize.";
        announcementMessage(message);
        displayPressButton(skip);

        ::iter(intArray, 5, randomize);
        for (int i = 0; i < 5; ++i) {
            std::cout << NEON_BLUE << intArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }
}