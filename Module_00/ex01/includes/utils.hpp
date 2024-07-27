#ifndef UTILS_HPP
#define UTILS_HPP

#include "../includes/PhoneBook.hpp"
#include <string>

bool onlyDigit(std::string input);
std::string validAddField(bool digitsOnly = false);
void addCommand(PhoneBook &phoneBook, std::size_t &index);
void handleCommand(const std::string &command, PhoneBook &phoneBook, std::size_t &index);
#endif