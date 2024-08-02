#include "../includes/Harl.hpp"
#include "../includes/colors.hpp"


// Constructor: Initializes the Harl object and sets up the complaint handlers.
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

// Destructor: Cleans up any resources used by the Harl object.
Harl::~Harl() {
    std::cout << RED << "🧨 Harl Deconstructor called 🧨" << RESET << std::endl;
}

// Given a complaint level, use the find method to determine which one should be called.
void Harl::complain(std::string level) {
    for (int i = 0; i < 4; ++i) {
        if (this->complaints[i].level == level) {
            (this->*complaints[i].complain)();
            return;
        }
    }
}

// Print the message when Gangplank buys a Triforce.
void Harl::debug(void) {
    std::cout << NYELLOW << "🔺 Got every angle covered. 🔺" << RESET << std::endl;
}

// Print a joke message by Gangplank.
void Harl::info(void) {
    std::cout << NORANGE << "🍊 They're not just oranges. They're blood oranges. 🍊" << RESET
              << std::endl;
}

// Print a message when Gangplank is moving.
void Harl::warning(void) {
    std::cout << NWHITE << "🕒 Do I look like a patient man? 🕒" << RESET << std::endl;
}

// Print a joke message by Gangplank.
void Harl::error(void) {
    std::cout
        << NRED
        << "😮‍💨 Yar ha har argh! — (coughs) — Had something in my throat. 😮‍💨"
        << RESET << std::endl;
}