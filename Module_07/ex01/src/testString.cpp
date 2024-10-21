#include "../include/test.hpp"

void testString(bool skip) {
    const std::string title = "Running tests on string array.";
    announcementTitle(title);

    std::string strArray[3] = {"H3llO", "wOr lD", "t3st"};

    std::cout << NEON_CYAN << "Initial Array:" << RESET << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << NEON_CYAN << strArray[i] << " " << RESET;
    }
    std::cout << std::endl;

    {
        const std::string message = "calling function uppercase.";
        announcementMessage(message);
        displayPressButton(skip);

        ::iter(strArray, 3, uppercase);
        for (int i = 0; i < 3; ++i) {
            std::cout << NEON_PINK << strArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }

    {
        const std::string message = "calling function lowercase.";
        announcementMessage(message);
        displayPressButton(skip);

        ::iter(strArray, 3, lowercase);
        for (int i = 0; i < 3; ++i) {
            std::cout << NEON_RED << strArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }
}