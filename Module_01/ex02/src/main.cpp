#include <iostream>
#include <string>

#define NEON_YELLOW "\033[1;93m"
#define NEON_GREEN "\033[1;92m"
#define NEON_PURPLE "\033[1;95m"
#define NEON_CYAN "\033[1;96m"
#define RESET "\033[0m"

int main() {
  std::string string = "HI THIS IS BRAIN";
  std::string *stringPTR = &string;
  std::string &stringREF = string;

  std::cout << NEON_CYAN << "Memory adress of string variable : " NEON_GREEN
            << &string << RESET << std::endl;
  std::cout << NEON_CYAN << "Memory address held by stringPTR : " NEON_PURPLE
            << stringPTR << RESET << std::endl;
  std::cout << NEON_CYAN << "Memory address held by stringREF : " NEON_YELLOW
            << &stringREF << RESET << std::endl;

  std::cout << NEON_YELLOW
            << "------------------------------------------------------------"
            << RESET << std::endl;

  std::cout << NEON_CYAN << "Value of string variable : " NEON_GREEN << string
            << RESET << std::endl;
  std::cout << NEON_CYAN << "Value pointed to stringPTR : " NEON_PURPLE
            << *stringPTR << RESET << std::endl;
  std::cout << NEON_CYAN << "Value pointed to stringREF : " NEON_YELLOW
            << stringREF << RESET << std::endl;
}