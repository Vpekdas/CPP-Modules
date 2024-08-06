#ifndef UTILS_HPP
#define UTILS_HPP

#include "../includes/PhoneBook.hpp"
#include <string>

bool onlyDigit(std::string input);

// Ensures that the input is valid and not empty when adding a contact, optionally checking for
// digits only. This helps maintain data integrity by preventing empty or invalid entries.
std::string validAddField(bool digitsOnly = false);

// Adds a new contact to the phone book, updating the index accordingly.
// This function encapsulates the logic for adding contacts, ensuring consistency.
void addCommand(PhoneBook &phoneBook, std::size_t &index);

// Handles all commands related to the phone book, providing a single entry point for command
// processing. This centralizes command handling, making the code easier to maintain and extend.
void handleCommand(const std::string &command, PhoneBook &phoneBook, std::size_t &index);

#endif