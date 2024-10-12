#include "../include/colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

// Locate the occurrence of the target string to identify where the replacement
// should happen. Split the string into two parts: before the occurrence and
// after the occurrence. This ensures that we can replace the target string
// accurately without affecting other parts of the string. Concatenate the part
// before the occurrence, the replacement string, and the part after the
// occurrence. This approach allows us to perform the replacement as needed,
// maintaining the integrity of the original string structure.
int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << "\033[0;31m"
                  << "Error: Exactly 4 arguments are expected: the filename, and "
                     "two strings, s1 and s2."
                  << RESET << std::endl;
        return 0;
    }
    std::ifstream inputFile(av[1]);
    std::string line;
    std::string occurrence = av[2];
    std::string replaceBy = av[3];
    std::string suffix = ".replace";
    std::string newFileName = av[1] + suffix;
    std::ofstream outputFile(newFileName.c_str());
    std::size_t occurrenceLength = occurrence.length();
    int indexOccurrence = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::size_t initialLength = line.length();
            indexOccurrence = line.find(occurrence);

            if (replaceBy == occurrence || occurrence.empty()) {
                indexOccurrence = -1;
            }
            while (indexOccurrence != -1) {
                std::string nextLine = line.substr(indexOccurrence + occurrenceLength, initialLength - indexOccurrence);
                std::string previousLine = line.substr(0, indexOccurrence) + replaceBy;
                line = previousLine + nextLine;
                indexOccurrence = line.find(occurrence, indexOccurrence + replaceBy.length());
            }
            outputFile << line;
            if (!inputFile.eof()) {
                outputFile << std::endl;
            }
        }
        std::cout << NEON_GREEN << "File copied successfully." << RESET << std::endl;
    } else {
        std::cout << NEON_RED << "Failed to open the files." << RESET << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}