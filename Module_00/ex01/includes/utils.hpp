#ifndef UTILS_HPP
#define UTILS_HPP

#include "../includes/PhoneBook.hpp"
#include <string>

// Checks if the input string contains only digits.
bool onlyDigit(std::string input);

// Checks if the input is not empty when adding a contact.
std::string validAddField(bool digitsOnly = false);

// Handles the ADD command.
void addCommand(PhoneBook &phoneBook, std::size_t &index);

// Wraps all command handling.
void handleCommand(const std::string &command, PhoneBook &phoneBook, std::size_t &index);

#endif