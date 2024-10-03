#include <iostream>
#include <string>

#define NYELLOW "\033[1;93m"
#define NGREEN "\033[1;92m"
#define NPURPLE "\033[1;95m"
#define NCYAN "\033[1;96m"
#define RESET "\033[0m"

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << NCYAN << "Memory adress of string variable : " NGREEN << &string << RESET << std::endl;
    std::cout << NCYAN << "Memory address held by stringPTR : " NPURPLE << stringPTR << RESET << std::endl;
    std::cout << NCYAN << "Memory address held by stringREF : " NYELLOW << &stringREF << RESET << std::endl;

    std::cout << NYELLOW << "------------------------------------------------------------" << RESET << std::endl;

    std::cout << NCYAN << "Value of string variable : " NGREEN << string << RESET << std::endl;
    std::cout << NCYAN << "Value pointed to stringPTR : " NPURPLE << *stringPTR << RESET << std::endl;
    std::cout << NCYAN << "Value pointed to stringREF : " NYELLOW << stringREF << RESET << std::endl;
}