#include "../includes/Harl.hpp"
#include "../includes/colors.hpp"

Harl::Harl() {
    complaints[0].level = "DEBUG";
    complaints[0].complain = &Harl::_debug;
    complaints[1].level = "INFO";
    complaints[1].complain = &Harl::_info;
    complaints[2].level = "WARNING";
    complaints[2].complain = &Harl::_warning;
    complaints[3].level = "ERROR";
    complaints[3].complain = &Harl::_error;
    std::cout << YELLOW << "🛠️ Harl Constructor called 🛠️" << RESET << std::endl;
}

Harl::~Harl() {
    std::cout << RED << "🧨 Harl Deconstructor called 🧨" << RESET << std::endl;
}

void Harl::complain(std::string level) {
    for (int i = 0; i < 4; ++i) {
        if (complaints[i].level == level) {
            (this->*complaints[i].complain)();
            return;
        }
    }
}

void Harl::_debug(void) {
    std::cout << NYELLOW << "🔺 Got every angle covered. 🔺" << RESET << std::endl;
}

void Harl::_info(void) {
    std::cout << NORANGE << "🍊 They're not just oranges. They're blood oranges. 🍊" << RESET
              << std::endl;
}

void Harl::_warning(void) {
    std::cout << NWHITE << "🕒 Do I look like a patient man? 🕒" << RESET << std::endl;
}

void Harl::_error(void) {
    std::cout
        << NRED
        << "😮‍💨 Yar ha har argh! — (coughs) — Had something in my throat. 😮‍💨"
        << RESET << std::endl;
}