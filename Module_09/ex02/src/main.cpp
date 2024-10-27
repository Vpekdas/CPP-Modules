#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"

int main(int ac, char **av) {

    if (ac == 1) {
        return (1);
    }

    try {
        PMergeMe pMergeMe;

        pMergeMe.mergeInsertSort(ac, av);

    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }

    return 0;
}
