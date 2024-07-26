#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include "iostream"
#include <string>

int main() {
  PhoneBook phoneBook;
  std::string command;
  while (true) {
    std::getline(std::cin, command);
    if (command == "ADD") {
      Contact contact;
      std::string input;
      std::cout << "🖊️ Enter first name 🖊️ : ";
      std::getline(std::cin, input);
      contact.setFirstName(input);

      std::cout << "🖊️ Enter last name 🖊️ : ";
      std::getline(std::cin, input);
      contact.setLastName(input);

      std::cout << "🆔 Enter nickname 🆔 : ";
      std::getline(std::cin, input);
      contact.setNickname(input);

      std::cout << "📞 Enter phone number 📞 : ";
      std::getline(std::cin, input);
      contact.setPhoneNumber(input);

      std::cout << "🤫 Enter darkest secret 🤫 : ";
      std::getline(std::cin, input);
      contact.setDarkestSecret(input);

      phoneBook.addContact(contact);
      std::cout << GREEN "Contact " << contact.getNickname()
                << " added succesfully ✅" RESET;
    }
    if (command == "SEARCH") {
      phoneBook.displayContacts();
    }
  }
  return 0;
}