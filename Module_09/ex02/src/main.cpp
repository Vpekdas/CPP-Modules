#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"

int main(int ac, char **av) {

    if (ac == 1) {
        return (1);
    }

    try {
        PMergeMe pMergeMe;

        pMergeMe.mergeInsertSort(ac, av);

        double durationMsVector = pMergeMe._durationMsVector;
        double durationMsDeque = pMergeMe._durationMsDeque;

        pMergeMe.printInitialVector();
        pMergeMe.printSortedVector();

        pMergeMe.printInitialDeque();
        pMergeMe.printSortedDeque();

        // When we are trying to sort 10,000 or more numbers, std::deque becomes faster than std::vector.
        // This is probably because it is faster to insert elements in a deque since there is no reallocation,
        // unlike std::vector.
        std::cout << BOLD_ITALIC_CYAN << std::fixed << std::setprecision(5) << "Time to process a range of " << ac - 1
                  << " elements with std::[vector] : " << durationMsVector << " ms ";
        if (durationMsVector < durationMsDeque) {
            std::cout << BOLD_ITALIC_CYAN << "🥇" << RESET << std::endl;
        } else {
            std::cout << BOLD_ITALIC_CYAN << "🥈" << RESET << std::endl;
        }

        std::cout << BOLD_ITALIC_CYAN << std::fixed << std::setprecision(5) << "Time to process a range of " << ac - 1
                  << " elements with std::[deque] : " << durationMsDeque << " ms";
        if (durationMsVector > durationMsDeque) {
            std::cout << BOLD_ITALIC_CYAN << "🥇" << RESET << std::endl;
        } else {
            std::cout << BOLD_ITALIC_CYAN << "🥈" << RESET << std::endl;
        }

    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    return 0;
}
