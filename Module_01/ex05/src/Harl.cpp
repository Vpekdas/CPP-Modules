#include "../includes/Harl.hpp"
#include "../includes/colors.hpp"

Harl::Harl() {
    complaints[0].level = "DEBUG";
    complaints[0].complain = &Harl::debug;
    complaints[1].level = "INFO";
    complaints[1].complain = &Harl::info;
    complaints[2].level = "WARNING";
    complaints[2].complain = &Harl::warning;
    complaints[3].level = "ERROR";
    complaints[3].complain = &Harl::error;
    std::cout << YELLOW << "🛠️ Harl Constructor called 🛠️" << RESET << std::endl;
}

Harl::~Harl() {
    std::cout << RED << "🧨 Harl Deconstructor called 🧨" << RESET << std::endl;
}

void Harl::complain(std::string level) {
    for (int i = 0; i < 4; ++i) {
        if (this->complaints[i].level == level) {
            (this->*complaints[i].complain)();
            return;
        }
    }
}

// These methods provide specific responses for each complaint level.
// The messages are designed to reflect the severity or nature of the complaint.

void Harl::debug(void) {
    std::cout << NYELLOW << "🔺 Got every angle covered. 🔺" << RESET << std::endl;
}

void Harl::info(void) {
    std::cout << NORANGE << "🍊 They're not just oranges. They're blood oranges. 🍊" << RESET
              << std::endl;
}

void Harl::warning(void) {
    std::cout << NWHITE << "🕒 Do I look like a patient man? 🕒" << RESET << std::endl;
}

void Harl::error(void) {
    std::cout
        << NRED
        << "😮‍💨 Yar ha har argh! — (coughs) — Had something in my throat. 😮‍💨"
        << RESET << std::endl;
}