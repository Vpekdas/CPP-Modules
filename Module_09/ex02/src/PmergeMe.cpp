#include "../include/PmergeMe.hpp"
#include "../include/colors.hpp"

PMergeMe::PMergeMe() {
    std::cout << YELLOW << "🛠️ Default PMergeMe Constructor called 🛠️" << RESET << std::endl;
}

PMergeMe::~PMergeMe() {
    std::cout << RED << "🧨 PMergeMe Destructor called 🧨" << RESET << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe &other) {
    (void)other;
    std::cout << YELLOW << "🖨️ PMergeMe Copy Constructor called 🖨️" << RESET << std::endl;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 PMergeMe Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

// Insertion Sort.
// The 'left' and 'right' parameters allow us to sort a subarray within the vector, rather than the entire vector.
// This approach is more efficient for small subarrays, as insertion sort performs well on small and nearly sorted
// datasets.
void PMergeMe::insertionSortVector(std::vector<int> &vector, std::size_t left, std::size_t right) {
    for (std::size_t i = left + 1; i <= right; i++) {
        int key = vector[i];
        std::size_t j = i;
        while (j > left && vector[j - 1] > key) {
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = key;
    }
}

// Recursively divides the array into smaller subarrays until the size is small enough
// to be sorted using insertion sort. If the subarray size is below the threshold,
// insertion sort is used. Otherwise, merge sort continues to divide and conquer.
void PMergeMe::mergeSortVector(std::vector<int> &vector, std::size_t left, std::size_t right) {

    if (right - left + 1 <= INSERTION_SORT_THRESHOLD) {
        insertionSortVector(vector, left, right);
        return;
    }

    std::size_t middle = left + (right - left) / 2;

    mergeSortVector(vector, left, middle);
    mergeSortVector(vector, middle + 1, right);

    mergeVector(vector, left, middle, right);
}

// Merges two sorted subarrays back into the main array to maintain the overall sorted order.
void PMergeMe::mergeVector(std::vector<int> &vector, std::size_t left, std::size_t middle, std::size_t right) {
    // Create left and right vector.
    std::vector<int> leftVector(vector.begin() + left, vector.begin() + middle + 1);
    std::vector<int> rightVector(vector.begin() + middle + 1, vector.begin() + right + 1);

    // i is the index for the left subarray, r is the index for the right subarray, and l is the index for the main
    // array.
    std::size_t i = 0, r = 0, l = left;

    while (i < leftVector.size() && r < rightVector.size()) {
        if (leftVector[i] <= rightVector[r]) {
            vector[l] = leftVector[i];
            l++;
            i++;
        } else {
            vector[l] = rightVector[r];
            l++;
            r++;
        }
    }

    // Copy remaining numbers from the left vector.
    while (i < leftVector.size()) {
        vector[l] = leftVector[i];
        l++;
        i++;
    }

    // Copy remaining numbers from the right vector.
    while (r < rightVector.size()) {
        vector[l] = rightVector[r];
        l++;
        r++;
    }
}
