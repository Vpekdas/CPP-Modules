#include "../includes/colors.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout
            << RED
            << "Error: Exactly 4 arguments are expected: the filename, and two strings, s1 and s2."
            << RESET << std::endl;
        return 0;
    }

    std::ifstream inputFile(av[1]);
    std::string occurence = av[2];
    std::string replaceBy = av[3];
    std::size_t occurenceLength = occurence.length();

    std::string replace = ".replace";
    std::string newName = av[1] + replace;

    std::ofstream outputFile(newName.c_str());

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;

        while (std::getline(inputFile, line)) {
        }

        std::size_t initialLength = line.length();
        int indexOccurence = line.find(occurence);

        while (indexOccurence != -1) {
            std::string nextLine =
                line.substr(indexOccurence + occurenceLength, initialLength - indexOccurence);
            std::string prevLine = line.substr(0, indexOccurence) + replaceBy;

            line = prevLine + nextLine;
            indexOccurence = line.find(occurence);
        }

        outputFile << line << "\n";

        inputFile.close();
        outputFile.close();

        std::cout << NGREEN << "File copied successfully." << RESET << std::endl;
    } else {
        std::cout << NRED << "Failed to open the files." << RESET << std::endl;
    }

    return 0;
}