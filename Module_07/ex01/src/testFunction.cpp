#include "../include/colors.hpp"
#include "../include/iter.hpp"

// Functions for displaying formatted messages.
void announcementTitle(const std::string &message) {
    std::cout << "\n" << NEON_BLUE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_YELLOW << message << RESET << std::endl;
    std::cout << NEON_BLUE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

void announcementMessage(const std::string &message) {
    std::cout << "\n" << NEON_PURPLE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_GREEN << message << RESET << std::endl;
    std::cout << NEON_PURPLE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

// Functions for testing with int arrays.
static void incrementByHundred(int &value) {
    value += 100;
}

static void randomize(int &value) {
    value = std::rand();
}

// Functions for testing with string arrays.
static void uppercase(std::string &str) {
    for (std::size_t i = 0; i < str.length(); i++) {
        if (std::islower(str[i]))
            str[i] -= 32;
    }
}

static void lowercase(std::string &str) {
    for (std::size_t i = 0; i < str.length(); i++) {
        if (std::isupper(str[i]))
            str[i] += 32;
    }
}

// Functions for testing with double arrays.
static void doubleValue(double &value) {
    value *= 2;
}

void testInt() {
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
        ::iter(intArray, 5, incrementByHundred);
        for (int i = 0; i < 5; ++i) {
            std::cout << NEON_PURPLE << intArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }

    {
        const std::string message = "calling function randomize.";
        announcementMessage(message);
        ::iter(intArray, 5, randomize);
        for (int i = 0; i < 5; ++i) {
            std::cout << NEON_BLUE << intArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }
}

void testDouble() {
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
        ::iter(doubleArray, 5, doubleValue);
        for (int i = 0; i < 5; ++i) {
            std::cout << NEON_ORANGE << doubleArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }
}

void testString() {
    const std::string title = "Running tests on string array.";
    announcementTitle(title);

    std::string strArray[3] = {"H3llO", "wOr lD", "t3st"};

    std::cout << NEON_CYAN << "Initial Array:" << RESET << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << NEON_CYAN << strArray[i] << " " << RESET;
    }
    std::cout << std::endl;

    {
        const std::string message = "calling function uppercase.";
        announcementMessage(message);
        ::iter(strArray, 3, uppercase);
        for (int i = 0; i < 3; ++i) {
            std::cout << NEON_PINK << strArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }

    {
        const std::string message = "calling function lowercase.";
        announcementMessage(message);
        ::iter(strArray, 3, lowercase);
        for (int i = 0; i < 3; ++i) {
            std::cout << NEON_RED << strArray[i] << " " << RESET;
        }
        std::cout << std::endl;
    }
}