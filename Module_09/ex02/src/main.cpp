#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"
#include "../include/display.hpp"

// https://www.youtube.com/watch?v=3j0SWDX4AtU
// Merge sort.

// https://www.geeksforgeeks.org/insertion-sort-algorithm/
// Insert sort.

int main(int ac, char **av) {
    if (ac < 2) {
        return 1;
    }

    std::vector<int> inputVector;

    std::string title = "Initializing vector and deque with command-line input.";
    announcementTitle(title);

    std::cout << NEON_BLUE << "[std::vector] Before: ";
    for (int i = 1; i < ac; i++) {
        inputVector.push_back(std::atoi(av[i]));
        std::cout << inputVector[i - 1] << " ";
    }
    std::cout << std::endl;

    std::string message = "Calling mergeSort on Vector.";
    announcementMessage(message);

    PMergeMe pMergeMe;
    pMergeMe.mergeSortVector(inputVector, 0, inputVector.size() - 1);

    message = "displaying the result of mergeSort in Vector and Deque.";
    announcementMessage(message);

    std::cout << NEON_BLUE << "[std::vector] After: ";
    for (int i = 1; i < ac; i++) {
        std::cout << inputVector[i - 1] << " ";
    }
    std::cout << std::endl;

    message = "Checking if Vector is sorted.";
    announcementMessage(message);

    for (std::size_t i = 0; i < inputVector.size() - 1; i++) {
        if (inputVector[i] > inputVector[i + 1]) {
            std::cerr << NEON_RED << "❌ Error: Vector is not sorted at index " << i << ". Element " << inputVector[i]
                      << " is greater than " << inputVector[i + 1] << "." << RESET << std::endl;
            return 1;
        }
    }
    std::cout << BOLD_ITALIC_GREEN << "✅ Vector is sorted !" << RESET << std::endl;
}