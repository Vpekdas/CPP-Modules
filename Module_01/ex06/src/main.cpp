#include "../includes/Harl.hpp"
#include "../includes/colors.hpp"

// Return the case number for switch based on an enum.
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
                  << CYAN << "Usage: ./harlFilter <DEBUG|INFO|WARNING|ERROR>" << RESET << std::endl;
        return 0;
    }
    std::size_t choice = returnChoiceIndex(av[1]);

    Harl harl;
    switch (choice) {
    case DEBUG:
        std::cout << NCYAN << "[ DEBUG ]" << RESET << std::endl;
        harl.complain("DEBUG");
        // Fall through to print above level complaints
    case INFO:
        std::cout << NCYAN << "[ INFO ]" << RESET << std::endl;
        harl.complain("INFO");
        // Fall through to print above level complaints
    case WARNING:
        std::cout << NCYAN << "[ WARNING ]" << RESET << std::endl;
        harl.complain("WARNING");
        // Fall through to print above level complaints
    case ERROR:
        std::cout << NCYAN << "[ ERROR ]" << RESET << std::endl;
        harl.complain("ERROR");
        break;
    default:
        std::cerr << RED << "❓ Unknown complaint ❓" << RESET << std::endl;
        break;
    }
    return 0;
}