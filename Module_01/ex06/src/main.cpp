#include "../include/Harl.hpp"
#include "../include/colors.hpp"

std::size_t returnChoiceIndex(std::string choice) {
  if (choice == "DEBUG") {
    return DEBUG;
  } else if (choice == "INFO") {
    return INFO;
  } else if (choice == "WARNING") {
    return WARNING;
  } else if (choice == "ERROR") {
    return ERROR;
  }
  return 0;
}

int main(int ac, char **av) {

  if (ac != 2) {
    std::cerr << RED << "Error: The program requires exactly 2 arguments.\n"
              << CYAN << "Usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR>"
              << RESET << std::endl;
    return 0;
  }
  std::size_t choice = returnChoiceIndex(av[1]);

  Harl harl;
  switch (choice) {
  case DEBUG:
    std::cout << NEON_CYAN << "[ DEBUG ]" << RESET << std::endl;
    harl.complain("DEBUG");
    // Fall through to print above level complaints
  case INFO:
    std::cout << NEON_CYAN << "[ INFO ]" << RESET << std::endl;
    harl.complain("INFO");
    // Fall through to print above level complaints
  case WARNING:
    std::cout << NEON_CYAN << "[ WARNING ]" << RESET << std::endl;
    harl.complain("WARNING");
    // Fall through to print above level complaints
  case ERROR:
    std::cout << NEON_CYAN << "[ ERROR ]" << RESET << std::endl;
    harl.complain("ERROR");
    break;
  default:
    std::cerr << RED << "❓ Unknown complaint ❓" << RESET << std::endl;
    break;
  }
  return 0;
}