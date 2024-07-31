#include <iostream>
#include <string>

#define NYELLOW "\033[1;93m"
#define NGREEN "\033[1;92m"
#define NPURPLE "\033[1;95m"
#define NCYAN "\033[1;96m"
#define RESET "\033[0m"

int main() {
    std::string string = "HI THIS IS BRAIN";
    // pointer to string.
    std::string *stringPTR = &string;
    // reference to string.
    std::string &stringREF = string;

    std::cout << NCYAN << "Memory adress of string variable : " NGREEN << &string << RESET
              << std::endl;
    std::cout << NCYAN << "Memory address held by stringPTR : " NPURPLE << &stringPTR << RESET
              << std::endl;
    std::cout << NCYAN << "Memory address held by stringREF : " NYELLOW << &stringREF << RESET
              << std::endl;

    std::cout << NCYAN << "------------------------------------------------------------" << RESET << std::endl;

    std::cout << NCYAN << "Value of string variable : " NGREEN << string << RESET << std::endl;
    std::cout << NCYAN << "Value pointed to by stringPTR : " NPURPLE << *stringPTR << RESET
              << std::endl;
    std::cout << NCYAN << "Value pointed to byby stringREF : " NYELLOW << stringREF << RESET
              << std::endl;
}