#include "../include/Span.hpp"
#include "../include/colors.hpp"

int main() {

    std::srand(time(NULL));

    std::vector<int> tempVector;

    for (int i = 0; i < 10; i++) {
        tempVector.push_back(std::rand() % 1000);
        std::cout << NEON_CYAN << tempVector[i] << " " << RESET;
    }
    std::cout << std::endl;

    std::vector<int>::iterator first = tempVector.begin();
    std::vector<int>::iterator last = tempVector.end();

    Span span(10);
    span.addMultipleNumber(first, last);

    span.shortestSpan();
    span.longestSpan();

    return 0;
}