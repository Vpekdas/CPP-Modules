#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iomanip>
#include <iostream>

void announcementTitle(const std::string &title);
void announcementMessage(const std::string &message);
void displayPressButton(bool skip);
void stringToLower(std::string &input);

#endif // DISPLAY_HPP