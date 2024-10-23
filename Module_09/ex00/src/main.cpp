#include "../include/BitcoinExchange.hpp"
#include "../include/colors.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        return 1;
    }
    try {
        BitcoinExchange btc;

        btc.parseDatabase("data.csv");
        btc.parseInput(av[1]);
        
    } catch (std::exception &ex) {
        std::cerr << BOLD_ITALIC_RED << ex.what() << RESET << std::endl;
    }
}