#include "../includes/colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

// Locate the occurrence of the target string to identify where the replacement should happen.
// Split the string into two parts: before the occurrence and after the occurrence.
// This ensures that we can replace the target string accurately without affecting other parts of
// the string. Concatenate the part before the occurrence, the replacement string, and the part
// after the occurrence. This approach allows us to perform the replacement as needed, maintaining
// the integrity of the original string structure.
int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << RED << "Error: Exactly 4 arguments are expected: the filename, and two strings, s1 and s2."
                  << RESET << std::endl;
        return 0;
    }
    std::ifstream inputFile(av[1]);
    std::string line;
    std::string occurence = av[2];
    std::string replaceBy = av[3];
    std::string suffix = ".replace";
    std::string newFileName = av[1] + suffix;
    std::ofstream outputFile(newFileName.c_str());
    std::size_t occurenceLength = occurence.length();
    int indexOccurence = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::size_t initialLength = line.length();
            indexOccurence = line.find(occurence);

            if (replaceBy == occurence || occurence.empty()) {
                indexOccurence = -1;
            }
            while (indexOccurence != -1) {
                std::string nextLine = line.substr(indexOccurence + occurenceLength, initialLength - indexOccurence);
                std::string previousLine = line.substr(0, indexOccurence) + replaceBy;
                line = previousLine + nextLine;
                indexOccurence = line.find(occurence, indexOccurence + replaceBy.length());
            }
            outputFile << line;
            if (!inputFile.eof()) {
                outputFile << std::endl;
            }
        }
        std::cout << NGREEN << "File copied successfully." << RESET << std::endl;
    } else {
        std::cout << NRED << "Failed to open the files." << RESET << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}