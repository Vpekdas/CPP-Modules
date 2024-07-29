#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// HEADERS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

#include "../includes/Contact.hpp"
#include <cstdlib>

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// COLORS //	+	+	+	+ 	+	+	+	//
// -----------------------------------------------------------------------------//

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

// -----------------------------------------------------------------------------//
//	+	+	+	+	+	+	+		// CLASS //	+	+	+	+ 	+	+	+		//
// -----------------------------------------------------------------------------//

class PhoneBook {
  public:
    PhoneBook();
    ~PhoneBook();
    // Adds a new contact to the PhoneBook.
    void addContact(const Contact &contact);
    // Displays all contacts with general information.
    void displayContacts();
    // Allows the user to choose an index to display all information.
    void displaySpecificContact(std::size_t index);

  private:
    //   Only 8 contacts can be stored.

    Contact contacts[8];
    std::size_t totalContacts;
    // Allows incrementing and wrapping around to the oldest contact.
    std::size_t nextIndex;
};

#endif