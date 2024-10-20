#include "../include/test.hpp"

void testDouble(bool skip) {
    const std::string title = "Running tests on double array.";
    announcementTitle(title);

    double doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << NEON_CYAN << "Initial Array:" << RESET << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << NEON_CYAN << doubleArray[i] << " " << RESET;
    }
    std::cout << std::endl;

    {
        const std::string message = "calling function doubleValue.";
        announcementMessage(message);
        displayPressButton(skip);

        ::iter(doubleArray, 5, doubleValue);
        for (int i = 0; i < 5; ++i) {
            std::cout << NEON_ORANGE << doubleArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }
}