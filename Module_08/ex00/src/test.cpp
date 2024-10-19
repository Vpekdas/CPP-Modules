#include "../include/test.hpp"
#include "../include/display.hpp"
#include "../include/easyfind.hpp"

void testVector(bool skip) {
    std::string title = "Running tests on vector container.";
    announcementTitle(title);

    std::vector<int> vectorContainer;

    vectorContainer.push_back(1);
    vectorContainer.push_back(2);
    vectorContainer.push_back(3);
    vectorContainer.push_back(4);
    vectorContainer.push_back(5);
    vectorContainer.push_back(6);
    vectorContainer.push_back(7);
    vectorContainer.push_back(8);
    vectorContainer.push_back(9);
    vectorContainer.push_back(10);

    std::string message = "Filling vector with value.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::size_t i = 0; i < vectorContainer.size(); i++) {
        std::cout << NEON_GREEN << vectorContainer[i] << " " << RESET;
    }
    std::cout << std::endl;

    message = "Attempting to find a random number in the list.";
    announcementMessage(message);
    displayPressButton(skip);

    std::size_t randomNumber;
    for (std::size_t i = 0; i < vectorContainer.size(); i++) {
        randomNumber = std::rand() % vectorContainer.size() * 2 + 1;

        std::vector<int>::iterator it = ::easyfind(vectorContainer, randomNumber);

        if (it == vectorContainer.end()) {
            std::cerr << NEON_RED << "❌ Error: " << randomNumber << " cannot be found in container." << RESET
                      << std::endl;
        } else {
            std::cout << BOLD_ITALIC_GREEN << "✅ Success: " << randomNumber << " has been found in the container."
                      << RESET << std::endl;
        }
    }
}

void testList(bool skip) {
    std::string title = "Running tests on list container.";
    announcementTitle(title);

    std::list<int> listContainer;

    listContainer.push_back(1);
    listContainer.push_back(2);
    listContainer.push_back(3);
    listContainer.push_back(4);
    listContainer.push_back(5);
    listContainer.push_back(6);
    listContainer.push_back(7);
    listContainer.push_back(8);
    listContainer.push_back(9);
    listContainer.push_back(10);

    std::string message = "Filling list with value.";
    announcementMessage(message);
    displayPressButton(skip);

    for (std::list<int>::iterator it = listContainer.begin(); it != listContainer.end(); it++) {
        std::cout << NEON_GREEN << *it << " " << RESET;
    }
    std::cout << std::endl;

    message = "Attempting to find a random number in the list.";
    announcementMessage(message);
    displayPressButton(skip);

    std::size_t randomNumber;
    for (std::size_t i = 0; i < listContainer.size(); i++) {
        randomNumber = std::rand() % listContainer.size() * 2 + 1;

        std::list<int>::iterator it = ::easyfind(listContainer, randomNumber);

        if (it == listContainer.end()) {
            std::cerr << NEON_RED << "❌ Error: " << randomNumber << " cannot be found in container." << RESET
                      << std::endl;
        } else {
            std::cout << BOLD_ITALIC_GREEN << "✅ Success: " << randomNumber << " has been found in the container."
                      << RESET << std::endl;
        }
    }
}

void testAll(bool skip) {
    (void)skip;
    testVector(true);
    testList(true);
}