#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"
#include "../include/display.hpp"

int main(int ac, const char **av) {
    if (ac == 1) {
        return 1;
    }

    PMergeMe pMergeMe;

    pMergeMe.parseInput(ac, av);
}