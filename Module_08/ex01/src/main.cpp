#include "../include/Span.hpp"
#include "../include/colors.hpp"
#include "../include/display.hpp"

int main() {

    try {
        std::srand(time(NULL));

        std::vector<int> tempVector;

        std::string message = "Creating a tempVector with 10 random numbers.";
        announcementMessage(message);

        std::cout << NEON_PURPLE << "[tempVector]: " << RESET;
        for (int i = 0; i < 10; i++) {
            tempVector.push_back(std::rand() % 1000);
            std::cout << NEON_PURPLE << tempVector[i] << " " << RESET;
        }
        std::cout << std::endl;

        std::vector<int>::iterator first = tempVector.begin();
        std::vector<int>::iterator last = tempVector.end();

        message = "Creating a Span class that can contain 10 numbers and filling it with a range of numbers using a "
                  "special method.";
        announcementMessage(message);

        Span span(10);

        span.addMultipleNumber(first, last);

        span.displayNumber();

        message = "Calculating the shortest and longest spans.";
        announcementMessage(message);

        span.shortestSpan();
        span.longestSpan();

        message = "Displaying the sorted span:";
        announcementMessage(message);

        span.displayNumber();

        message = "Testing the addNumber method functionality.";
        announcementMessage(message);

        span.displayNumber();

        message = "Creating a Span that can contain 2 numbers and attempting to add 2 numbers.";
        announcementMessage(message);

        Span littleSpan(2);

        littleSpan.addNumber(24);
        littleSpan.addNumber(42);

        littleSpan.displayNumber();

        message = "Attempting to add one more number to a full Span.";
        announcementMessage(message);

        littleSpan.addNumber(42);

        littleSpan.displayNumber();

    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    return 0;
}