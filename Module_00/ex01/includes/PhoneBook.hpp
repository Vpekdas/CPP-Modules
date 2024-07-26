#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "../includes/Contact.hpp"

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define BLACK "\033[0;30"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#define BYELLOW "\033[1;33m"
#define BGREEN "\033[1;32m"
#define BBLUE "\033[1;34m"
#define BRED "\033[1;31m"
#define BPURPLE "\033[1;35m"
#define BCYAN "\033[1;36m"
#define BBLACK "\033[1;30m"
#define BWHITE "\033[1;37m"

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  void addContact(const Contact &contact);
  void displayContacts();
  std::string formatColumn(const std::string &str);

private:
  Contact contacts[8];
  std::size_t totalContacts;
  std::size_t nextIndex;
};

#endif