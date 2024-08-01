#include "../includes/colors.hpp"
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
    // Open the input file specified by the first command-line argument for reading.
    std::ifstream inputFile(av[1]);
    std::string line;

    // Store the search string provided as the second command-line argument.
    std::string occurence = av[2];

    // Store the replacement string provided as the third command-line argument.
    std::string replaceBy = av[3];
    std::string replace = ".replace";

    // Concatenate the original file name with '.replace' to create a new file name.
    std::string newName = av[1] + replace;

    // Open a new file for writing, using the modified file name.
    std::ofstream outputFile(newName.c_str());

    std::size_t occurenceLength = occurence.length();
    int indexOccurence = 0;

    // Check if both the input and output files are successfully opened.
    if (inputFile.is_open() && outputFile.is_open()) {

        // Read each line from the input file until EOF is reached.
        while (std::getline(inputFile, line)) {
            std::size_t initialLength = line.length();

            // Return the index of the first occurrence of the search string in the line.
            indexOccurence = line.find(occurence);

            // Skip replacement if the search string and replacement string are identical.
            if (replaceBy == occurence || occurence.empty()) {
                indexOccurence = -1;
            }

            // Continue replacing occurrences of the search string in the line as long as they are
            // found.
            while (indexOccurence != -1) {

                // Store the substring following the occurrence to be replaced.
                std::string nextLine =
                    line.substr(indexOccurence + occurenceLength, initialLength - indexOccurence);

                // Store the part before the target word and concatenate it with the replacement
                // word.
                std::string prevLine = line.substr(0, indexOccurence) + replaceBy;

                // Concatenate the part before the occurrence with the replacement word and the
                // remaining substring.
                line = prevLine + nextLine;

                // Check again for another occurrence of the word to replace in the updated line.
                indexOccurence = line.find(occurence);
            }

            // Write the processed line to the output file.
            outputFile << line;

            // Add a newline if not at the end of the file or if the line contains only a newline
            // character.
            if (!inputFile.eof()) {
                outputFile << std::endl;
            }
        }
        std::cout << NGREEN << "File copied successfully." << RESET << std::endl;
    } else {
        std::cout << NRED << "Failed to open the files." << RESET << std::endl;
    }

    // Close all opened files.
    inputFile.close();
    outputFile.close();

    return 0;
}